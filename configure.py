from argparse import ArgumentParser
from io import StringIO
import os
from sys import executable as PYTHON
from typing import List

from ninja_syntax import Writer


parser = ArgumentParser()
parser.add_argument("--decomp", type=str, help="Decomp path")
args = parser.parse_args()

outbuf = StringIO()
n = Writer(outbuf)

#############
# Variables #
#############

n.variable("builddir", "build")
n.variable("incdir", "include")
n.variable("mod_incdir", "mod")
n.variable("decomp_incdir", "decomp")

n.variable("incgen", f"{PYTHON} tools/incgen.py")

n.variable("devkitppc", os.environ.get("DEVKITPPC"))
n.variable("cpp", os.path.join("$devkitppc", "bin", "powerpc-eabi-cpp"))

MOD_INCLUDES = ["$incdir", "$mod_incdir"]
n.variable("mod_cc", os.path.join("$devkitppc", "bin", "powerpc-eabi-g++"))
n.variable("mod_source", os.path.join("$builddir", "mod.cpp"))
n.variable("mod_incdir", "mod")
n.variable(
    "mod_machdep",
    ' '.join([
        "-mno-sdata", # Disable SDA sections since not main binary
        "-DGEKKO", # CPU preprocessor define
        "-mcpu=750", # Set CPU to 750cl
        "-meabi", # Set ppc abi to eabi
        "-mhard-float", # Enable hardware floats
        "-nostdlib", # Don't link std lib
        "-mregnames", # Enable r prefix for registers in asm
        "-ffreestanding", # Tell compiler environment isn't hosted
    ])
)
n.variable(
    "mod_cflags",
    ' '.join([
        "$mod_machdep",
        "$mod_includes",

        "-ffunction-sections", # Allow function deadstripping
        "-fdata-sections", # Allow data deadstripping
        "-g", # Emit debug info
        "-O3", # High optimisation for speed
        "-Wall", # Enable all warnings
        "-Wextra", # Enable even more warnings
        "-Wpedantic", # Enable even more warnings than that
        "-Wshadow", # Enable variable shadowing warning
        "-Werror", # Error on warnings
        "-fmax-errors=1", # Stop after 1 error
    ])
)
n.variable(
    "mod_cxxflags",
    ' '.join([
        "$mod_cflags",

        "-fno-exceptions", # Disable C++ exceptions
        "-fno-rtti", # Disable runtime type info
        "-std=gnu++17", # Use C++17 with GNU extensions
    ])
)

DECOMP_INCLUDES = [
    "$incdir",
    "$decomp_incdir",
    os.path.join("$decomp", "tools", "ppcdis", "include"),
]
n.variable("decomp", args.decomp)
n.variable("decomp_cc", os.path.join("$decomp", "tools", "4199_60831", "mwcceppc.exe"))
n.variable("decomp_source", os.path.join("$builddir", "decomp.c"))
n.variable(
    "decomp_cxxflags",
    ' '.join([
        "-lang c++",
        "-W all",
        "-fp fmadd",
        "-Cpp_exceptions off",
        "-O4",
        "-use_lmw_stmw on",
        "-str pool",
        "-rostr",
        "-sym dwarf-2",
        "-ipa file",
    ])
)

REGIONS = [
    "eu0",
    "eu1",
    "jp0",
    "jp1",
    "us0",
    "us1",
    "us2",
    "kr0",
]

########
# Rules#
########

ALLOW_CHAIN = "cmd /c " if os.name == "nt" else ""

n.rule(
    "incgen",
    ALLOW_CHAIN + "$incgen $dirs > $out"
)

n.rule(
    "mod_cc",
    command = "$mod_cc -MMD -MT $out -MF $out.d $mod_cxxflags $flags -c $in -o $out",
    depfile = "$out.d",
    deps = "gcc",
    description = "Mod CC $out",
)

if args.decomp:
    n.rule(
        "decomp_cc",
        command = ALLOW_CHAIN + "$cpp -M $in -MF $out.d $cppflags && " \
                                "$decomp_cc $decomp_cflags $flags -c $in -o $out",
        description = "Decomp CC $in",
        deps = "gcc",
        depfile = "$out.d"
    )

##########
# Builds #
##########

def incgen(source: str, dirs: List[str]):
    n.build(
        source,
        rule="incgen",
        inputs=[],
        variables={
            "dirs" : ' '.join(dirs),
        }
    )

def compile(dest: str, source: str, includes: List[str], defines: List[str], decomp: bool = False):
    define_flags = ' '.join(f"-D{d}" for d in defines)
    gcc_include_flags = ' '.join(f"-I {d}" for d in includes)
    if decomp:
        mwcc_include_flags = "-I- " + ' '.join(f"-i {d}" for d in includes)
        n.build(
            dest,
            "decomp_cc",
            [source],
            variables={
                "cppflags" : f"{gcc_include_flags} {define_flags}",
                "flags" : f"{mwcc_include_flags} {define_flags}",
            }
        )
    else:
        n.build(
            dest,
            "mod_cc",
            [source],
            variables={
                "flags" : f"{gcc_include_flags} {define_flags}",
            }
        )

def compile_regions(dest: str, source: str, includes: List[str], defines: List[str],
                    decomp: bool = False):
    for region in REGIONS:
        compile(dest.format(region=region), source, includes, defines + [f"SPM_{region.upper()}"],
                decomp)


incgen("$mod_source", MOD_INCLUDES)
compile_regions(os.path.join("$builddir", "mod_{region}.o"), "$mod_source", MOD_INCLUDES, ["USE_STL"])
compile_regions(os.path.join("$builddir", "old_mod_{region}.o"), "$mod_source", MOD_INCLUDES, [])

if args.decomp:
    incgen("$decomp_source", DECOMP_INCLUDES)
    compile_regions(os.path.join("$builddir", "decomp_{region}.o"), "$decomp_source",
                    DECOMP_INCLUDES, ["DECOMP"], True)

with open("build.ninja", 'w') as f:
    f.write(outbuf.getvalue())
n.close()

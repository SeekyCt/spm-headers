#pragma once

#include <common.h>
#include <spm/evtmgr.h>
#include <evt_cmd.h>

CPP_WRAPPER(spm::an2_08)

typedef struct RpgNPC {
/* 0x00 */ s32 flags;
/* 0x04 */ s32 unk4;
/* 0x08 */ s32 maxHp;
/* 0x0C */ s32 attackStrength;
/* 0x10 */ s32 unk_10;
/* 0x14 */ s32 killXp;
} RpgUnk;
SIZE_ASSERT(RpgNPC, 0x18);

typedef struct RpgMenu {
/* 0x00 */ s32 flags;
/* 0x04 */ s32 unk_04;
/* 0x08 */ void* unk_08;
/* 0x0C */ RpgNPC rpgNpcInfo[3];
/* 0x54 */ s32 unk_54;
/* 0x58 */ s32 unk_58[15];
/* 0x94 */ char unk_94[4];
} RpgMenu; //sizeof 0x98
SIZE_ASSERT(RpgMenu, 0x98);

typedef struct PhysicalMenu {
/* 0x00 */ char * option_1;
/* 0x04 */ char * unk_4;
/* 0x08 */ char * option_2;
/* 0x0c */ char * unk_c;
/* 0x10 */ char * option_3;
/* 0x14 */ char * unk_14;
/* 0x18 */ char * option_4;
/* 0x1c */ char * unk_1c;
/* 0x20 */ char * option_5;
/* 0x24 */ char * unk_24;
/* 0x28 */ char * option_6;
/* 0x2c */ char * unk_2c;
/* 0x30 */ char * unk_30;
} PhysicalMenu;
SIZE_ASSERT(PhysicalMenu, 0x34);

EVT_DECLARE(theParentOfBeginRPG);
EVT_DECLARE(finalRpgChild);
EVT_DECLARE(underchompAttack1);
EVT_DECLARE(underchompAttack2);
EVT_DECLARE(underchompAttack3);
EVT_DECLARE(checkWinOrContinue);
EVT_DECLARE(attacking);
EVT_DECLARE(usePixls);
EVT_DECLARE(useItems);
EVT_DECLARE(runningAway);
EVT_DECLARE(techChild1);
EVT_DECLARE(techChild2);

UNKNOWN_FUNCTION(func_80c6c908);
u8 rpg_handle_menu(int param_1, PhysicalMenu menu);
UNKNOWN_FUNCTION(func_80c6cccc);
UNKNOWN_FUNCTION(func_80c6ce24);
void rpg_screen_draw();

EVT_DECLARE_USER_FUNC(evt_rpg_npctribe_handle, 0);
EVT_DECLARE_USER_FUNC(evt_rpg_change_menu_flag, 0);
EVT_DECLARE_USER_FUNC(evt_rpg_choice_handler, 5);
EVT_DECLARE_USER_FUNC(evt_rpg_char_get, 1);
EVT_DECLARE_USER_FUNC(evt_rpg_underchomp_name_grab, 2);
EVT_DECLARE_USER_FUNC(evt_rpg_calc_damage_to_enemy, 3);
EVT_DECLARE_USER_FUNC(evt_rpg_enemy_take_damage, 4);
EVT_DECLARE_USER_FUNC(evt_rpg_calc_mario_damage, 2);
EVT_DECLARE_USER_FUNC(evt_rpg_mario_take_damage, 3);
EVT_DECLARE_USER_FUNC(evt_rpg_point_calculation, 2);
EVT_DECLARE_USER_FUNC(evt_rpg_enemy_death_check, 2);
EVT_DECLARE_USER_FUNC(evt_rpg_effect_check, 1);
EVT_DECLARE_USER_FUNC(evt_rpg_status_remove, 3);
EVT_DECLARE_USER_FUNC(evt_rpg_menu_effects_handler, 2);
EVT_DECLARE_USER_FUNC(evt_rpg_wakeup_check, 2);
EVT_DECLARE_USER_FUNC(evt_rpg_effects_handle, 2);
EVT_DECLARE_USER_FUNC(evt_rpg_calc_item_stats, 4);
EVT_DECLARE_USER_FUNC(evt_rpg_add_xp, 1);
EVT_DECLARE_USER_FUNC(evt_rpg_point_handling, 1);
EVT_DECLARE_USER_FUNC(evt_rpg_get_item_msg, 2);
EVT_DECLARE_USER_FUNC(evt_an2_08_draw_face, 2);
UNKNOWN_FUNCTION(func_80c72d5c);
UNKNOWN_FUNCTION(func_80c72e10);

CPP_WRAPPER_END()

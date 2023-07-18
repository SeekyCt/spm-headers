#pragma once

#include <common.h>
#include <spm/evtmgr.h>
#include <evt_cmd.h>

CPP_WRAPPER(spm::evt_rpg)

EVT_DECLARE_USER_FUNC(evt_rpg_effect_check, 1)
EVT_DECLARE_USER_FUNC(evt_rpg_choice_handler, 5)
EVT_DECLARE_USER_FUNC(changeRandomDAT1, 0)
EVT_DECLARE_USER_FUNC(evt_rpg_wakeup_check, 2)
EVT_DECLARE_USER_FUNC(evt_rpg_effects_handle, 2)
EVT_DECLARE_USER_FUNC(evt_rpg_menu_effects_handler, 2)
EVT_DECLARE_USER_FUNC(evt_rpg_mario_take_damage, 3)
EVT_DECLARE_USER_FUNC(evt_rpg_enemy_take_damage, 4)
EVT_DECLARE_USER_FUNC(evt_rpg_point_calculation, 2)
EVT_DECLARE_USER_FUNC(evt_rpg_point_handling, 1)
EVT_DECLARE_USER_FUNC(evt_rpg_underchomp_name_grab, 2)
EVT_DECLARE_USER_FUNC(evt_rpg_calc_mario_damage, 2)
EVT_DECLARE_USER_FUNC(evt_rpg_get_item_msg, 2)
EVT_DECLARE_USER_FUNC(evt_rpg_calc_item_stats, 4)
EVT_DECLARE_USER_FUNC(evt_rpg_add_xp, 1)
EVT_DECLARE_USER_FUNC(evt_rpg_calc_damage_to_enemy, 3)
EVT_DECLARE_USER_FUNC(evt_rpg_enemy_death_check, 2)
EVT_DECLARE_USER_FUNC(evt_rpg_status_remove, 3)
EVT_DECLARE_USER_FUNC(evt_rpg_char_get, 1)
EVT_DECLARE_USER_FUNC(evt_unknown_pointer_change, 1)
EVT_DECLARE_USER_FUNC(evt_rpg_npctribe_handle, 0)


CPP_WRAPPER_END()

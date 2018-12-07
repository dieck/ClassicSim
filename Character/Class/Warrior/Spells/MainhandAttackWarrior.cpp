
#include "MainhandAttackWarrior.h"
#include "Warrior.h"
#include "DeepWounds.h"
#include "OverpowerBuff.h"
#include "RecklessnessBuff.h"
#include "CharacterStats.h"

MainhandAttackWarrior::MainhandAttackWarrior(Character* pchar) :
    MainhandAttack(pchar),
    warr(dynamic_cast<Warrior*>(pchar))
{}

void MainhandAttackWarrior::extra_attack() {
    calculate_damage(false);
}

void MainhandAttackWarrior::spell_effect() {
    complete_swing();
    calculate_damage(true);
}

void MainhandAttackWarrior::calculate_damage(const bool run_procs) {
    const int mh_wpn_skill = warr->get_mh_wpn_skill();
    int result = roll->get_melee_hit_result(mh_wpn_skill, pchar->get_stats()->get_mh_crit_chance());

    if (result == PhysicalAttackResult::MISS) {
        increment_miss();
        return;
    }

    pchar->add_player_reaction_event();

    if (result == PhysicalAttackResult::DODGE) {
        increment_dodge();
        warr->get_overpower_buff()->apply_buff();
        warr->gain_rage(warr->rage_gained_from_dd(warr->get_avg_mh_damage()));
        return;
    }
    if (result == PhysicalAttackResult::PARRY) {
        increment_parry();
        warr->gain_rage(warr->rage_gained_from_dd(warr->get_avg_mh_damage()));
        return;
    }
    if (result == PhysicalAttackResult::BLOCK || result == PhysicalAttackResult::BLOCK_CRITICAL) {
        increment_full_block();
        warr->gain_rage(warr->rage_gained_from_dd(warr->get_avg_mh_damage()));
        return;
    }

    if (warr->get_recklessness_buff()->is_active())
        result = PhysicalAttackResult::CRITICAL;

    double damage_dealt = damage_after_modifiers(warr->get_random_non_normalized_mh_dmg());

    if (result == PhysicalAttackResult::CRITICAL) {
        damage_dealt = round(damage_dealt * 2);
        add_crit_dmg(static_cast<int>(damage_dealt), resource_cost, 0);
        const unsigned rage_gained = warr->rage_gained_from_dd(static_cast<unsigned>(damage_dealt));
        // TODO: Save statistics for resource gains
        warr->gain_rage(rage_gained);

        warr->melee_mh_white_critical_effect(run_procs);
        return;
    }

    warr->melee_mh_white_hit_effect(run_procs);

    if (result == PhysicalAttackResult::GLANCING) {
        damage_dealt = round(damage_dealt * roll->get_glancing_blow_dmg_penalty(mh_wpn_skill));
        add_glancing_dmg(static_cast<int>(damage_dealt), resource_cost, 0);
        const unsigned rage_gained = warr->rage_gained_from_dd(static_cast<unsigned>(damage_dealt));
        // TODO: Save statistics for resource gains
        warr->gain_rage(rage_gained);
        return;
    }

    damage_dealt = round(damage_dealt);
    const unsigned rage_gained = warr->rage_gained_from_dd(static_cast<unsigned>(damage_dealt));
    add_hit_dmg(static_cast<int>(damage_dealt), resource_cost, 0);
    // TODO: Save statistics for resource gains
    warr->gain_rage(rage_gained);
}

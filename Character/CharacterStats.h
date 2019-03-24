#ifndef CHARACTERSTATS_H
#define CHARACTERSTATS_H

#include <QVector>
#include <QHash>

#include "ItemStatsEnum.h"
#include "Target.h"

class Character;
class Race;
class Equipment;
class EquipmentDb;
class Stats;
class Weapon;

class CharacterStats {
public:
    CharacterStats(Character*, EquipmentDb* equipment_db);
    ~CharacterStats();

    Equipment* get_equipment() const;
    Stats* get_stats() const;

    double get_melee_hit_chance() const;
    double get_mh_crit_chance() const;
    double get_oh_crit_chance() const;
    double get_ranged_hit_chance() const;
    double get_ranged_crit_chance() const;
    double get_spell_hit_chance() const;
    double get_spell_crit_chance() const;

    double get_total_phys_dmg_mod() const;
    double get_physical_damage_taken_mod() const;
    double get_spell_damage_taken_mod() const;

    int get_mh_wpn_skill() const;
    int get_oh_wpn_skill() const;
    int get_ranged_wpn_skill() const;

    void increase_wpn_skill(const int, const int);
    void decrease_wpn_skill(const int, const int);

    void increase_stat(const ItemStats, const unsigned);
    void decrease_stat(const ItemStats, const unsigned);

    double get_melee_attack_speed_mod() const;
    void increase_melee_attack_speed(const unsigned);
    void decrease_melee_attack_speed(const unsigned);

    double get_ranged_attack_speed_mod() const;
    void increase_ranged_attack_speed(const unsigned);
    void decrease_ranged_attack_speed(const unsigned);

    unsigned get_strength() const;
    void increase_strength(const unsigned);
    void decrease_strength(const unsigned);

    unsigned get_agility() const;
    void increase_agility(const unsigned);
    void decrease_agility(const unsigned);

    unsigned get_stamina() const;
    void increase_stamina(const unsigned);
    void decrease_stamina(const unsigned);

    unsigned get_intellect() const;
    void increase_intellect(const unsigned);
    void decrease_intellect(const unsigned);

    unsigned get_spirit() const;
    void increase_spirit(const unsigned);
    void decrease_spirit(const unsigned);

    unsigned get_melee_ap() const;
    void increase_melee_ap(const unsigned);
    void decrease_melee_ap(const unsigned);

    unsigned get_ranged_ap() const;
    void increase_ranged_ap(const unsigned);
    void decrease_ranged_ap(const unsigned);

    void increase_ap_vs_type(const Target::CreatureType, const unsigned);
    void decrease_ap_vs_type(const Target::CreatureType, const unsigned);

    void increase_dmg_vs_type(const Target::CreatureType, const double);
    void decrease_dmg_vs_type(const Target::CreatureType, const double);

    void increase_melee_hit(const unsigned);
    void decrease_melee_hit(const unsigned);

    void increase_crit(double);
    void decrease_crit(double);

    void increase_ranged_hit(const unsigned);
    void decrease_ranged_hit(const unsigned);

    void increase_crit_for_weapon_type(const int, const double);
    void decrease_crit_for_weapon_type(const int, const double);

    void increase_total_phys_dmg_for_weapon_type(const int, const int);
    void decrease_total_phys_dmg_for_weapon_type(const int, const int);

    void increase_spell_hit(double);
    void decrease_spell_hit(double);

    void increase_spell_crit(double);
    void decrease_spell_crit(double);

    void increase_total_phys_dmg_mod(const int);
    void decrease_total_phys_dmg_mod(const int);

    void add_phys_damage_taken_mod(const int);
    void remove_phys_damage_taken_mod(const int);

    void add_spell_damage_taken_mod(const int);
    void remove_spell_damage_taken_mod(const int);

    void add_total_stat_mod(const int);
    void remove_total_stat_mod(const int);

    void add_ap_multiplier(const int);
    void remove_ap_multiplier(const int);

    double get_mh_wpn_speed();
    double get_oh_wpn_speed();
    double get_ranged_wpn_speed();

    void increase_dodge(const double);
    void decrease_dodge(const double);

    unsigned get_mp5() const;

private:
    Character* pchar;
    Equipment* equipment;
    Stats* base_stats;
    QVector<int> attack_speed_buffs;
    QVector<int> phys_dmg_buffs;
    QVector<int> phys_damage_taken_changes;
    QVector<int> spell_damage_taken_changes;
    QVector<int> total_stat_mod_changes;
    QVector<int> ap_total_multipliers;
    QHash<int, double> crit_bonuses_per_weapon_type;
    QHash<int, int> damage_bonuses_per_weapon_type;
    QHash<int, double> damage_bonuses_per_monster_type;

    int axe_skill_bonus;
    int dagger_skill_bonus;
    int mace_skill_bonus;
    int sword_skill_bonus;

    double melee_ability_crit_mod{};
    double melee_attack_speed_mod;
    double ranged_attack_speed_mod;
    double total_phys_dmg_mod;
    double physical_damage_taken_mod;
    double spell_damage_taken_mod;
    double total_stat_mod;
    double total_ap_mod;

    void add_multiplicative_effect(QVector<int>& effects, int add_value, double& modifier);
    void remove_multiplicative_effect(QVector<int>& effects, int remove_value, double& modifier);
    void recalculate_multiplicative_effects(QVector<int>& effects, double& modifier);
    Target::CreatureType get_type_for_stat(const ItemStats);

    int get_wpn_skill(Weapon*) const;
};

#endif // CHARACTERSTATS_H

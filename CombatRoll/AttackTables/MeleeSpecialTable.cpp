
#include "MeleeSpecialTable.h"
#include <iostream>

void MeleeSpecialTable::set_attack_table(void) {
    assert(miss >= 0);
    assert(dodge >= 0);
    assert(parry >= 0);
    assert(block >= 0);
    assert(critical >= 0);

    this->miss_range = int(round(miss * 10000));
    this->dodge_range = int(round(dodge * 10000)) + miss_range;
    this->parry_range = int(round(parry * 10000)) + dodge_range;
    this->block_range = int(round(block * 10000)) + parry_range;

    // Separate roll.
    this->critical_range = int(round(critical * 10000));
}

int MeleeSpecialTable::get_outcome(const int roll) {
    assert(roll >= 0 && roll < 10000);

    if (roll < this->miss_range)
        return Outcome::MISS;
    if (roll < this->dodge_range)
        return Outcome::DODGE;
    if (roll < this->parry_range)
        return Outcome::PARRY;
    if (roll < this->block_range) {
        if (random->get_roll() < this->critical_range)
            return Outcome::BLOCK_CRITICAL;
        return Outcome::BLOCK;
    }
    if (random->get_roll() < this->critical_range)
        return Outcome::CRITICAL;
    return Outcome::HIT;
}

void MeleeSpecialTable::dump_table(void) {
    std::cout << "------------\n";
    std::cout << "MISS RANGE " << miss_range << " (" << miss * 100 << "%)" <<"\n";
    std::cout << "DODGE RANGE " << dodge_range << " (" << dodge * 100 << "%)" <<"\n";
    std::cout << "PARRY RANGE " << parry_range << " (" << parry * 100 << "%)" <<"\n";
    std::cout << "BLOCK RANGE " << block_range << " (" << block * 100 << "%)" <<"\n";
    std::cout << "CRITICAL RANGE " << critical_range << " (" << critical* 100 << "%)" <<"\n";
}

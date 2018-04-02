
#include "Paladin.h"

QString Paladin::get_name(void) const {
    return "Paladin";
}

QString Paladin::get_class_color() const {
    return "#F58CBA";
}

int Paladin::get_strength_modifier(void) const {
    return 2;
}

int Paladin::get_agility_modifier(void) const {
    return 0;
}

int Paladin::get_stamina_modifier(void) const {
    return 2;
}

int Paladin::get_intellect_modifier(void) const {
    return 0;
}

int Paladin::get_spirit_modifier(void) const {
    return 1;
}

int Paladin::get_ap_per_strength() const {
    return 1;
}

int Paladin::get_ap_per_agi() const {
    return 1;
}

void Paladin::rotation() {
    return;
}

void Paladin::mh_auto_attack(const int) {
    return;
}

void Paladin::oh_auto_attack(const int) {
    return;
}

float Paladin::global_cooldown() const {
    return 1.5;
}

void Paladin::initialize_talents() {

}

void Paladin::reset_spells() const {

}

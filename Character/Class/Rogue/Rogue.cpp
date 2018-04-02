
#include "Rogue.h"

QString Rogue::get_name(void) const {
    return "Rogue";
}

QString Rogue::get_class_color() const {
    return "#FFF569";
}

int Rogue::get_strength_modifier(void) const {
    return 1;
}

int Rogue::get_agility_modifier(void) const {
    return 3;
}

int Rogue::get_stamina_modifier(void) const {
    return 1;
}

int Rogue::get_intellect_modifier(void) const {
    return 0;
}

int Rogue::get_spirit_modifier(void) const {
    return 0;
}

int Rogue::get_ap_per_strength() const {
    return 1;
}

int Rogue::get_ap_per_agi() const {
    return 1;
}

void Rogue::rotation() {
    return;
}

void Rogue::mh_auto_attack(const int) {
    return;
}

void Rogue::oh_auto_attack(const int) {
    return;
}

float Rogue::global_cooldown() const {
    return 1.0;
}

void Rogue::initialize_talents() {

}

void Rogue::reset_spells() const {

}

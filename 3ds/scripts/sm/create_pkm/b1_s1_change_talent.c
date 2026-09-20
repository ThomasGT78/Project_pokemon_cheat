#include "pksm.h"

void main()
{
    char data[0x104];
    int ability;
    int currentAbility;

    currentAbility = pkx_get_value(data, GEN_SEVEN, ABILITY);

    // Récupère le Pokémon boîte 1 slot 1
    sav_get_pkx(data, 0, 0);


    // Demande le talent
    gui_numpad(&ability, "ID du talent :", 3);


    // Change le talent
    pkx_set_value(data, GEN_SEVEN, ABILITY, ability);


    // Réinjecte le Pokémon
    sav_inject_pkx(data, GEN_SEVEN, 0, 0, 1);

    gui_splash("Talent actuel : %d", currentAbility);
    gui_splash("Talent modifie !");
}
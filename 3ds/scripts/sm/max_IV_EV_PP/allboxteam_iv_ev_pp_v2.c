#include <pksm.h>
#include <stdio.h>

enum Generation generation = GEN_SEVEN;

// IV et EV max sur chaque Stats
void stats_pokemon(char* data, generation)
{
    pkx_set_value(data, generation, IV_HP, 31);
    pkx_set_value(data, generation, IV_ATK, 31);
    pkx_set_value(data, generation, IV_DEF, 31);
    pkx_set_value(data, generation, IV_SPATK, 31);
    pkx_set_value(data, generation, IV_SPDEF, 31);
    pkx_set_value(data, generation, IV_SPEED, 31);

    pkx_set_value(data, generation, EV_HP, 255);
    pkx_set_value(data, generation, EV_ATK, 255);
    pkx_set_value(data, generation, EV_DEF, 255);
    pkx_set_value(data, generation, EV_SPATK, 255);
    pkx_set_value(data, generation, EV_SPDEF, 255);
    pkx_set_value(data, generation, EV_SPEED, 255);
}

// PPmax sur chaque attaque
void max_pp_pokemon(char* data, generation)
{
    int move;
    int slot;

    for (slot = 0; slot < 4; slot++)
    {
        move = pkx_get_value(data, generation, MOVE, slot);

        // Si une attaque existe
        if (move != 0)
        {
            // 3 PP Plus
            pkx_set_value(data, generation, PP_UPS, slot, 3);

            // PP max avec 3 PP Plus
            pkx_set_value(data, generation, PP, slot, max_pp(generation, move, 3));
        }
    }
}


// Fonction qui lance tous les upgrades du pkm
void upgrade_pokemon(data, generation) {
    stats_pokemon(data, generation);
    max_pp_pokemon(data, generation);
}

int main(int argc, char** argv, generation)
{
    // Modif PKM in all boxes
    char data[pkx_box_size(generation)];
    int count = 0;

    for (int box = 0; box < 32; box++)
    {
        for (int slot = 0; slot < 30; slot++)
        {
            sav_get_pkx(data, box, slot);

            if (!pkx_is_valid(data, generation))
                continue;
            
            upgrade_pokemon(data);
            sav_inject_pkx(data, generation, box, slot, 0);

            count++;
        }
    }

    // Modif PKM in Team
    char party[pkx_party_size(generation)];

    for (int slot = 0; slot < 6; slot++)
    {
        party_get_pkx(party, slot);

        if (!pkx_is_valid(party, generation))
            continue;

        upgrade_pokemon(party);
        party_inject_pkx(party, generation, slot);

        count++;
    }

    char message[64];
    sprintf(message, "%d Pokemon modified", count);
    gui_warn(message);

    return 0;
}
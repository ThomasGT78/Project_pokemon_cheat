#include <pksm.h>

void max_pokemon(char* data, enum Generation gen)
{
    pkx_set_value(data, gen, IV_HP, 31);
    pkx_set_value(data, gen, IV_ATK, 31);
    pkx_set_value(data, gen, IV_DEF, 31);
    pkx_set_value(data, gen, IV_SPATK, 31);
    pkx_set_value(data, gen, IV_SPDEF, 31);
    pkx_set_value(data, gen, IV_SPEED, 31);

    pkx_set_value(data, gen, EV_HP, 0);
    pkx_set_value(data, gen, EV_ATK, 0);
    pkx_set_value(data, gen, EV_DEF, 0);
    pkx_set_value(data, gen, EV_SPATK, 0);
    pkx_set_value(data, gen, EV_SPDEF, 252);
    pkx_set_value(data, gen, EV_SPEED, 252);
}

int main(int argc, char** argv)
{
    unsigned char version = *argv[2];

    enum Generation gen;

    if (version == 30 || version == 31)
        gen = GEN_SEVEN;
    else
        return 1;


    char data[pkx_box_size(GEN_SEVEN)];


    // Boites PC
    int boxes = sav_get_max(MAX_BOXES);

    for (int box = 0; box < boxes; box++)
    {
        for (int slot = 0; slot < 30; slot++)
        {
            sav_get_pkx(data, box, slot);

            if (pkx_is_valid(data, GEN_SEVEN))
            {
                max_pokemon(data, GEN_SEVEN);
                sav_inject_pkx(data, GEN_SEVEN, box, slot, 0);
            }
        }
    }


    // Equipe
    char party[pkx_party_size(GEN_SEVEN)];

    int partySize = sav_get_max(MAX_SLOTS);

    for (int i = 0; i < partySize; i++)
    {
        party_get_pkx(party, i);

        if (pkx_is_valid(party, GEN_SEVEN))
        {
            max_pokemon(party, GEN_SEVEN);
            party_inject_pkx(party, GEN_SEVEN, i);
        }
    }

    gui_warn("IV 31 / EV 0-252 applied");

    return 0;
}
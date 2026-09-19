#include <pksm.h>
#include <stdio.h>

int main(int argc, char** argv)
{
    char data[pkx_box_size(GEN_SEVEN)];
    int count = 0;

for (int box = 0; box < 32; box++)
{
    for (int slot = 0; slot < 30; slot++)
    {
        sav_get_pkx(data, box, slot);

        if (!pkx_is_valid(data, GEN_SEVEN))
            continue;

        pkx_set_value(data, GEN_SEVEN, IV_HP, 31);
        pkx_set_value(data, GEN_SEVEN, IV_ATK, 31);
        pkx_set_value(data, GEN_SEVEN, IV_DEF, 31);
        pkx_set_value(data, GEN_SEVEN, IV_SPATK, 31);
        pkx_set_value(data, GEN_SEVEN, IV_SPDEF, 31);
        pkx_set_value(data, GEN_SEVEN, IV_SPEED, 31);

        pkx_set_value(data, GEN_SEVEN, EV_HP, 255);
        pkx_set_value(data, GEN_SEVEN, EV_ATK, 255);
        pkx_set_value(data, GEN_SEVEN, EV_DEF, 255);
        pkx_set_value(data, GEN_SEVEN, EV_SPATK, 255);
        pkx_set_value(data, GEN_SEVEN, EV_SPDEF, 255);
        pkx_set_value(data, GEN_SEVEN, EV_SPEED, 255);

        sav_inject_pkx(data, GEN_SEVEN, box, slot, 0);

        count++;
    }
}

    char party[pkx_party_size(GEN_SEVEN)];

    for (int slot = 0; slot < 6; slot++)
    {
        party_get_pkx(party, slot);

        if (!pkx_is_valid(party, GEN_SEVEN))
            continue;

        pkx_set_value(party, GEN_SEVEN, IV_HP, 31);
        pkx_set_value(party, GEN_SEVEN, IV_ATK, 31);
        pkx_set_value(party, GEN_SEVEN, IV_DEF, 31);
        pkx_set_value(party, GEN_SEVEN, IV_SPATK, 31);
        pkx_set_value(party, GEN_SEVEN, IV_SPDEF, 31);
        pkx_set_value(party, GEN_SEVEN, IV_SPEED, 31);

        pkx_set_value(party, GEN_SEVEN, EV_HP, 255);
        pkx_set_value(party, GEN_SEVEN, EV_ATK, 255);
        pkx_set_value(party, GEN_SEVEN, EV_DEF, 255);
        pkx_set_value(party, GEN_SEVEN, EV_SPATK, 255);
        pkx_set_value(party, GEN_SEVEN, EV_SPDEF, 255);
        pkx_set_value(party, GEN_SEVEN, EV_SPEED, 255);

        party_inject_pkx(party, GEN_SEVEN, slot);

        count++;
    }

    char message[64];
    sprintf(message, "%d Pokemon modifies", count);
    gui_warn(message);

    return 0;
}
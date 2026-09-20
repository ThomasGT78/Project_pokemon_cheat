#include <pksm.h>

int main(int argc, char** argv)
{
    char data[pkx_box_size(GEN_SEVEN)];

    sav_get_pkx(data, 0, 0);

    if (!pkx_is_valid(data, GEN_SEVEN))
    {
        gui_warn("ERREUR", "Pokemon invalide");
        return 1;
    }

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

    sav_inject_pkx(data, GEN_SEVEN, 0, 0, 0);

    gui_warn("Modification terminee");

    return 0;
}
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

    struct PersonalInfo
    {
        u8 hp;
        u8 atk;
        u8 def;
        u8 spe;
        u8 spa;
        u8 spd;
    };

    PersonalInfo *p = &personal[species];

    if (new_hp)
        p->hp = new_hp;

    if (new_atk)
        p->atk = new_atk;

    if (new_def)
        p->def = new_def;

    if (new_spa)
        p->spa = new_spa;

    if (new_spd)
        p->spd = new_spd;

    if (new_spe)
        p->spe = new_spe;
    
    
    BaseStatsEdit absol =
    {
        .hp  = 0,
        .atk = 0,
        .def = 0,
        .spa = 110,
        .spd = 0,
        .spe = 100,
    };

    if (edit.hp != 0)
        p->hp = edit.hp;

    if (edit.atk != 0)
        p->atk = edit.atk;

    if (edit.def != 0)
        p->def = edit.def;

    if (edit.spa != 0)
        p->spa = edit.spa;

    if (edit.spd != 0)
        p->spd = edit.spd;

    if (edit.spe != 0)
        p->spe = edit.spe;
        
    sav_inject_pkx(data, GEN_SEVEN, 0, 0, 0);

    gui_warn("Modification terminee");

    return 0;
}
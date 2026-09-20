#include <pksm.h>

int main(int argc, char** argv)
{
    unsigned int species;

    gui_numpad(&species, "National Dex", 3);

    if (species == 0)
    {
        gui_warn("Aucun numero");
        return 1;
    }

    #define OT_NAME "Nyx"

    #define OT_TID 37869
    #define OT_SID 37869
    
    // ID Dresseur : 500371
    // ID Secret : 2615

    char data[pkx_box_size(GEN_SEVEN)];

    pkx_generate(data, species);

    pkx_set_value(data, GEN_SEVEN, LEVEL, 1);
    pkx_set_value(data, GEN_SEVEN, EGG, 1);
    pkx_set_value(data, GEN_SEVEN, OT_NAME, OT_NAME);
    pkx_set_value(data, GEN_SEVEN, TID, OT_TID);
    pkx_set_value(data, GEN_SEVEN, SID, OT_SID);

    sav_inject_pkx(data, GEN_SEVEN, 0, 0, 0);

    gui_warn("Oeuf cree");

    return 0;
}

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

    char data[pkx_box_size(GEN_SEVEN)];

    pkx_generate(data, species);

    pkx_set_value(data, GEN_SEVEN, LEVEL, 1);

    pkx_set_value(data, GEN_SEVEN, EGG, 1);


    sav_inject_pkx(data, GEN_SEVEN, 0, 0, 0);

    gui_warn("Oeuf cree");

    return 0;
}

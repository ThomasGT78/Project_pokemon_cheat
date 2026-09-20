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

    gui_warn("OK");

    return 0;

}


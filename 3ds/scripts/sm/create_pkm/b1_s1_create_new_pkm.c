c #include "script.h" int main(int argc, char argv) { u32 species; u8 data[pkx_box_size(GEN_SEVEN)]; 
    // Interface : choix du Pokémon 
    gui_numpad(&species, "National Dex", 3); if (species == 0) { gui_warn("Aucun numero"); return 1; } 
    // Génération du Pokémon 
    pkx_generate(data, species); 
    // Niveau 1 
    pkx_set_value(data, GEN_SEVEN, LEVEL, 1); 
    // Talent rare (Ability 2 = talent caché/rare selon l'espèce) 
    pkx_set_value(data, GEN_SEVEN, ABILITY, 2); 
    // Prêt à éclore en 1 pas 
    pkx_set_value(data, GEN_SEVEN, EGG, 1); 
    pkx_set_value(data, GEN_SEVEN, HATCH_COUNTER, 1); 
    // Injection : boîte 0, slot 0 (1ère boîte, slot 1) 
    sav_inject_pkx(data, GEN_SEVEN, 0, 0, 0); 
    gui_warn("Oeuf cree !"); return 0; }
    
   
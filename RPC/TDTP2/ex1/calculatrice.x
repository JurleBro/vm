struct params { long param1; long param2; };
program CALC_PROG {
    version CALC_VERSION_1 {
        long AJOUTER(params) = 1; 
        long SOUSTRAIRE(params) = 2; 
        long MULTIPLIER(params) = 3;
        void MEMORISER_DERNIER_RESULTAT(int) = 4;
        long EXTRAIRE_MEMOIRE(int) = 5;
        void ALLUMER() = 6;
    } = 1;
} = 0x20000001;

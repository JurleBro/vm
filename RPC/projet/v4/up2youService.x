typedef int boolean;

struct date {
	int jour;
	int mois;
	int annee;
};

struct adresse {
	int numero;
	char voie[100];
	int cp;
	char ville[45];
};

struct donnee_bc {
	int numero;
	date date_exp;
	int crypto;
};

struct client { 
	int id;
	char nom[45]; 
	char prenom[45]; 
	struct donnee_bc donnee_bc; 
	boolean rib; 
	boolean pi; 
	boolean fact_tel;
	adresse list_adresse[3];
};

program UP2US_PROG {
	version UP2US_V_1 {
		void INIT() = 1;
		client GET_CLIENT(int) = 2;
	} = 1;
} = 0x23456789;

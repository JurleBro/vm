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

struct liste_clients{
	client liste[10];
	int nbClients;
};

program UP2US_PROG {
	version UP2US_V_1 {
		void INIT() = 1;
		liste_clients GET_CLIENTS() = 2;
		client GET_CLIENT(int) = 3;
	} = 1;
} = 0x23456789;

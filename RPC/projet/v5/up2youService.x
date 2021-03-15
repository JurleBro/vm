typedef int boolean;

struct date {
	int jour;
	int mois;
	int annee;
};

struct adresse {
	int numero;
	int cp;
};

struct donnee_bc {
	int numero;
	date date_exp;
	int crypto;
};

struct client { 
	int id;
	string nom<10>;
	struct donnee_bc donnee_bc; 
	boolean rib; 
	boolean pi; 
	boolean fact_tel;
	adresse adresse_client;
};

program UP2US_PROG {
	version UP2US_V_1 {
		void INIT() = 1;
		client GET_CLIENT() = 2;
	} = 1;
} = 0x23456789;

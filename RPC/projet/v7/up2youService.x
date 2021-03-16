typedef int boolean;

struct date {
	int jour;
	int mois;
	int annee;
};

struct adresse {
	int numero;
	char voie[10];
	int cp;
	char ville[10];
};

struct donnee_bc {
	int numero;
	date date_exp;
	int crypto;
};

struct client { 
	int id;
	char nom[10]; 
	char prenom[10]; 
	donnee_bc donnee_bc_client; 
	boolean rib; 
	boolean pi; 
	boolean fact_tel;
	adresse list_adresse[3];
};

struct mobile {
	int id;
	char nom[10];
	float prix_location;
	float prix_achat;
};

enum e_type {ACHAT, LOCATION};
typedef enum e_type type;
enum e_couleur { ROUGE, VERT, BLEU};
typedef enum e_couleur couleur;
enum e_connect { G4, G5};
typedef enum e_connect connectivite;
enum e_memoire { GO128, GO256, GO512 };
typedef enum e_memoire memoire;

struct params_mobile {
	int id_mobile;
	type type;
	couleur couleur;
	connectivite connectivite;
	memoire memoire;
};

struct commande {
	int id;
	int id_client;
	struct params_mobile mobile;
	int id_assurance;
	int id_adresse_client;
	boolean valide;
};

struct params_set_mobile {
	int id_commande;
	params_mobile param_mobile;
};

struct liste_mobiles{
	mobile liste[10];
	int nb_mobiles;
};

struct liste_clients{
	client liste[10];
	int nb_clients;
};

program UP2US_PROG {
	version UP2US_V_1 {
		void INIT() = 1;
		liste_clients GET_CLIENTS() = 2;
		client GET_CLIENT(int) = 3;
		int CREER_COMMANDE(int) = 4;
		liste_mobiles GET_MOBILES() = 5;
		mobile GET_MOBILE(int) = 6;
		boolean SET_MOBILE(params_set_mobile) = 7;
	} = 1;
} = 0x23456789;

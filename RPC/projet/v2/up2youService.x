const sizeNom = 45;
const sizeVoieAdresse = 100; 
const sizeVilleAdresse = 45;
const nbAdresseClient = 5;
const sizeDescriptionAssurance = 250;
const nbMaxClients = 10;
const nbMaxMobiles = 10;
const nbMaxAssurances = 3;
const nbMaxCommandes = 10;

typedef int boolean;

struct date {
	int jour;
	int mois;
	int annee;
};

struct adresse {
	int numero;
	char voie[sizeVoieAdresse];
	int cp;
	char ville[sizeVilleAdresse];
};

struct donnee_bc {
	int numero;
	struct date date_exp;
	int crypto;
};

struct client { 
	int id;
	char nom[sizeNom]; 
	char prenom[sizeNom]; 
	struct donnee_bc donnee_bc; 
	boolean rib; 
	boolean pi; 
	boolean fact_tel;
	struct adresse list_adresse[nbAdresseClient];
};

struct mobile {
	int id;
	char nom[sizeNom];
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

struct assurance {
	int id;
	float prix;
	char description[sizeDescriptionAssurance];
};

struct commande {
	int id;
	int id_client;
	struct params_mobile mobile;
	int id_assurance;
	int id_adresse_client;
	boolean valide;
};

struct livraison {
	int id;
	int id_commande;
	struct date date;
};

struct params_set_mobile {
	int id_commande;
	struct params_mobile param_mobile;
};

struct params_set_assurance {
	int id_commande;
	int id_assurance;
};

struct params_set_adresse {
	int id_commande;
	int id_adresse_client;
};

struct params_set_dl {
	int id_commande;
	struct date date;
};

struct liste_clients{
	struct client liste[nbMaxClients];
};
struct liste_mobile{
	struct mobile liste[nbMaxMobiles];
};
struct liste_assurances{
	struct assurance liste[nbMaxAssurances];
};
struct liste_commandes{
	struct commandes liste[nbMaxCommandes];
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
		liste_assurances GET_ASSURANCES() = 8;
		assurance GET_ASSURANCE(int) = 9;
		boolean SET_ASSURANCE(params_set_assurance) = 10;
		boolean SET_ADRESSE_LIVRAISON(params_set_adresse) = 11;
		liste_commandes GET_COMMANDES() = 12;
		commande GET_COMMANDE(int) = 13;
		boolean VALIDE_COMMANDE(int) = 14;
		boolean SET_DATE_LIVRAISON(params_set_dl) = 15;
	} = 1;
} = 0x23456789;

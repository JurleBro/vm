typdef int boolean;
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
	struct date date_exp;
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
	struct adresse list_adresse[5];
};
struct mobile {
	int id;
	char nom[45];
	float prix_location;
	float prix_achat;
};
struct params_mobile {
	int id_mobile;
	enum type {ACHAT, LOCATION};
	enum couleur { ROUGE, VERT, BLEU};
	enum connectivite { 4G, 5G };
	enum memoire { 128GO, 256GO, 512GO };
};
struct assurance {
	int id;
	float prix;
	char description[250];
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
struct params_saisie_mobile {
	int id_commande;
	struct params_mobile;
}
struct params_saisie_assurance {
	int id_commande;
	int id_assurance;
}
struct params_set_adresse {
	int id_commande;
	int id_adresse_client;
}
struct params_set_dl {
	int id_commande;
	struct date date;
}
program UP2US_PROG {
	version UP2US_V_1 {
		void INIT() = 1;
		client[10] GET_CLIENTS() = 2;
		client GET_CLIENT(int) = 3;
		int CREER_COMMANDE(int) = 4;
		mobile[10] GET_MOBILES() = 5;
		mobile GET_MOBILE(int) = 6
		boolean SET_MOBILE(params_set_mobile) = 7;
		assurance[10] GET_ASSURANCES() = 8;
		assurance GET_ASSURANCE(int) = 9
		boolean SET_ASSURANCE(params_set_assurance) = 10;
		boolean SET_ADRESSE_LIVRAISON(params_set_adresse) = 11;
		commande[10] GET_COMMANDES() = 12;
		commande GET_COMMANDE(int) = 13;
		boolean VALIDE_COMMANDE(int) = 14;
		boolean SET_DATE_LIVRAISON(params_set_dl) = 15;
	} = 1;
} = 0x23456789;

typdef int boolean;
struct date {
	int jour;
	int mois;
	int annee;
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
struct params_assurance 
struct commande {
	int id_client;
	structur params_mobile mobile;
	int id_assurance;
	boolean valide;
};

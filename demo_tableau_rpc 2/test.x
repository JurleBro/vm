
struct date{
	int jour;
	int mois;
	int annee;
};

struct commande{
	long idLivre;
	int  quantite;
	date date;
};

struct historiqueCommande{
	commande listCommande[50];
	int nbCommandes;
};

program TEST {
	version LIBRAIRIE_V1 {
		void INIT() = 1;
		historiqueCommande HISTORIQUE_COMMANDE(date) = 2;
	} = 1;

} = 0x23456789;

/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _UP2YOUSERVICE_H_RPCGEN
#define _UP2YOUSERVICE_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif

#define sizeNom 45
#define sizeVoieAdresse 100
#define sizeVilleAdresse 45
#define nbAdresseClient 5
#define sizeDescriptionAssurance 250
#define nbMaxClients 10
#define nbMaxMobiles 10
#define nbMaxAssurances 3
#define nbMaxCommandes 10

typedef int boolean;

struct date {
	int jour;
	int mois;
	int annee;
};
typedef struct date date;

struct adresse {
	int numero;
	char voie[sizeVoieAdresse];
	int cp;
	char ville[sizeVilleAdresse];
};
typedef struct adresse adresse;

struct donnee_bc {
	int numero;
	struct date date_exp;
	int crypto;
};
typedef struct donnee_bc donnee_bc;

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
typedef struct client client;

struct mobile {
	int id;
	char nom[sizeNom];
	float prix_location;
	float prix_achat;
};
typedef struct mobile mobile;

enum type {
	ACHAT = 0,
	LOCATION = 1,
};
typedef enum type type;


enum couleur {
	ROUGE = 0,
	VERT = 1,
	BLEU = 2,
};
typedef enum couleur couleur;


enum connect {
	G4 = 0,
	G5 = 1,
};
typedef enum connect connect;

typedef connect connectivite;

enum memoire {
	GO128 = 0,
	GO256 = 1,
	GO512 = 2,
};
typedef enum memoire memoire;


struct params_mobile {
	int id_mobile;
	type type;
	couleur couleur;
	connectivite connectivite;
	memoire memoire;
};
typedef struct params_mobile params_mobile;

struct assurance {
	int id;
	float prix;
	char description[sizeDescriptionAssurance];
};
typedef struct assurance assurance;

struct commande {
	int id;
	int id_client;
	struct params_mobile mobile;
	int id_assurance;
	int id_adresse_client;
	boolean valide;
};
typedef struct commande commande;

struct livraison {
	int id;
	int id_commande;
	struct date date;
};
typedef struct livraison livraison;

struct params_set_mobile {
	int id_commande;
	struct params_mobile param_mobile;
};
typedef struct params_set_mobile params_set_mobile;

struct params_set_assurance {
	int id_commande;
	int id_assurance;
};
typedef struct params_set_assurance params_set_assurance;

struct params_set_adresse {
	int id_commande;
	int id_adresse_client;
};
typedef struct params_set_adresse params_set_adresse;

struct params_set_dl {
	int id_commande;
	struct date date;
};
typedef struct params_set_dl params_set_dl;

typedef client liste_clients[nbMaxClients];

typedef mobile liste_mobiles[nbMaxMobiles];

typedef assurance liste_assurances[nbMaxAssurances];

typedef commande liste_commandes[nbMaxCommandes];

#define UP2US_PROG 0x23456789
#define UP2US_V_1 1

#if defined(__STDC__) || defined(__cplusplus)
#define INIT 1
extern  void * init_1(void *, CLIENT *);
extern  void * init_1_svc(void *, struct svc_req *);
#define GET_CLIENTS 2
extern  client * get_clients_1(void *, CLIENT *);
extern  client * get_clients_1_svc(void *, struct svc_req *);
#define GET_CLIENT 3
extern  client * get_client_1(int *, CLIENT *);
extern  client * get_client_1_svc(int *, struct svc_req *);
#define CREER_COMMANDE 4
extern  int * creer_commande_1(int *, CLIENT *);
extern  int * creer_commande_1_svc(int *, struct svc_req *);
#define GET_MOBILES 5
extern  mobile * get_mobiles_1(void *, CLIENT *);
extern  mobile * get_mobiles_1_svc(void *, struct svc_req *);
#define GET_MOBILE 6
extern  mobile * get_mobile_1(int *, CLIENT *);
extern  mobile * get_mobile_1_svc(int *, struct svc_req *);
#define SET_MOBILE 7
extern  boolean * set_mobile_1(params_set_mobile *, CLIENT *);
extern  boolean * set_mobile_1_svc(params_set_mobile *, struct svc_req *);
#define GET_ASSURANCES 8
extern  assurance * get_assurances_1(void *, CLIENT *);
extern  assurance * get_assurances_1_svc(void *, struct svc_req *);
#define GET_ASSURANCE 9
extern  assurance * get_assurance_1(int *, CLIENT *);
extern  assurance * get_assurance_1_svc(int *, struct svc_req *);
#define SET_ASSURANCE 10
extern  boolean * set_assurance_1(params_set_assurance *, CLIENT *);
extern  boolean * set_assurance_1_svc(params_set_assurance *, struct svc_req *);
#define SET_ADRESSE_LIVRAISON 11
extern  boolean * set_adresse_livraison_1(params_set_adresse *, CLIENT *);
extern  boolean * set_adresse_livraison_1_svc(params_set_adresse *, struct svc_req *);
#define GET_COMMANDES 12
extern  commande * get_commandes_1(void *, CLIENT *);
extern  commande * get_commandes_1_svc(void *, struct svc_req *);
#define GET_COMMANDE 13
extern  commande * get_commande_1(int *, CLIENT *);
extern  commande * get_commande_1_svc(int *, struct svc_req *);
#define VALIDE_COMMANDE 14
extern  boolean * valide_commande_1(int *, CLIENT *);
extern  boolean * valide_commande_1_svc(int *, struct svc_req *);
#define SET_DATE_LIVRAISON 15
extern  boolean * set_date_livraison_1(params_set_dl *, CLIENT *);
extern  boolean * set_date_livraison_1_svc(params_set_dl *, struct svc_req *);
extern int up2us_prog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define INIT 1
extern  void * init_1();
extern  void * init_1_svc();
#define GET_CLIENTS 2
extern  client * get_clients_1();
extern  client * get_clients_1_svc();
#define GET_CLIENT 3
extern  client * get_client_1();
extern  client * get_client_1_svc();
#define CREER_COMMANDE 4
extern  int * creer_commande_1();
extern  int * creer_commande_1_svc();
#define GET_MOBILES 5
extern  mobile * get_mobiles_1();
extern  mobile * get_mobiles_1_svc();
#define GET_MOBILE 6
extern  mobile * get_mobile_1();
extern  mobile * get_mobile_1_svc();
#define SET_MOBILE 7
extern  boolean * set_mobile_1();
extern  boolean * set_mobile_1_svc();
#define GET_ASSURANCES 8
extern  assurance * get_assurances_1();
extern  assurance * get_assurances_1_svc();
#define GET_ASSURANCE 9
extern  assurance * get_assurance_1();
extern  assurance * get_assurance_1_svc();
#define SET_ASSURANCE 10
extern  boolean * set_assurance_1();
extern  boolean * set_assurance_1_svc();
#define SET_ADRESSE_LIVRAISON 11
extern  boolean * set_adresse_livraison_1();
extern  boolean * set_adresse_livraison_1_svc();
#define GET_COMMANDES 12
extern  commande * get_commandes_1();
extern  commande * get_commandes_1_svc();
#define GET_COMMANDE 13
extern  commande * get_commande_1();
extern  commande * get_commande_1_svc();
#define VALIDE_COMMANDE 14
extern  boolean * valide_commande_1();
extern  boolean * valide_commande_1_svc();
#define SET_DATE_LIVRAISON 15
extern  boolean * set_date_livraison_1();
extern  boolean * set_date_livraison_1_svc();
extern int up2us_prog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_boolean (XDR *, boolean*);
extern  bool_t xdr_date (XDR *, date*);
extern  bool_t xdr_adresse (XDR *, adresse*);
extern  bool_t xdr_donnee_bc (XDR *, donnee_bc*);
extern  bool_t xdr_client (XDR *, client*);
extern  bool_t xdr_mobile (XDR *, mobile*);
extern  bool_t xdr_type (XDR *, type*);
extern  bool_t xdr_type (XDR *, type*);
extern  bool_t xdr_couleur (XDR *, couleur*);
extern  bool_t xdr_couleur (XDR *, couleur*);
extern  bool_t xdr_connect (XDR *, connect*);
extern  bool_t xdr_connectivite (XDR *, connectivite*);
extern  bool_t xdr_memoire (XDR *, memoire*);
extern  bool_t xdr_memoire (XDR *, memoire*);
extern  bool_t xdr_params_mobile (XDR *, params_mobile*);
extern  bool_t xdr_assurance (XDR *, assurance*);
extern  bool_t xdr_commande (XDR *, commande*);
extern  bool_t xdr_livraison (XDR *, livraison*);
extern  bool_t xdr_params_set_mobile (XDR *, params_set_mobile*);
extern  bool_t xdr_params_set_assurance (XDR *, params_set_assurance*);
extern  bool_t xdr_params_set_adresse (XDR *, params_set_adresse*);
extern  bool_t xdr_params_set_dl (XDR *, params_set_dl*);
extern  bool_t xdr_liste_clients (XDR *, liste_clients);
extern  bool_t xdr_liste_mobiles (XDR *, liste_mobiles);
extern  bool_t xdr_liste_assurances (XDR *, liste_assurances);
extern  bool_t xdr_liste_commandes (XDR *, liste_commandes);

#else /* K&R C */
extern bool_t xdr_boolean ();
extern bool_t xdr_date ();
extern bool_t xdr_adresse ();
extern bool_t xdr_donnee_bc ();
extern bool_t xdr_client ();
extern bool_t xdr_mobile ();
extern bool_t xdr_type ();
extern bool_t xdr_type ();
extern bool_t xdr_couleur ();
extern bool_t xdr_couleur ();
extern bool_t xdr_connect ();
extern bool_t xdr_connectivite ();
extern bool_t xdr_memoire ();
extern bool_t xdr_memoire ();
extern bool_t xdr_params_mobile ();
extern bool_t xdr_assurance ();
extern bool_t xdr_commande ();
extern bool_t xdr_livraison ();
extern bool_t xdr_params_set_mobile ();
extern bool_t xdr_params_set_assurance ();
extern bool_t xdr_params_set_adresse ();
extern bool_t xdr_params_set_dl ();
extern bool_t xdr_liste_clients ();
extern bool_t xdr_liste_mobiles ();
extern bool_t xdr_liste_assurances ();
extern bool_t xdr_liste_commandes ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_UP2YOUSERVICE_H_RPCGEN */

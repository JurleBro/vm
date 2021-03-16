/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "up2youService.h"
#define NB_MAX_COMMANDES 10

client g_liste_clients[10];
int g_nb_clients;

commande g_liste_commandes[NB_MAX_COMMANDES];
int g_nb_commandes;

mobile g_liste_mobiles[10];
int g_nb_mobiles;

void *
init_1_svc(void *argp, struct svc_req *rqstp)
{
	static char * result;

	g_liste_clients[0].id = 0;
	strcpy(g_liste_clients[0].prenom, "Nadira");
	strcpy(g_liste_clients[0].nom, "DERA");
	g_liste_clients[0].donnee_bc_client.numero = 121575219;
	g_liste_clients[0].donnee_bc_client.crypto = 100;
	g_liste_clients[0].donnee_bc_client.date_exp.jour = 1;
	g_liste_clients[0].donnee_bc_client.date_exp.mois = 1;
	g_liste_clients[0].donnee_bc_client.date_exp.annee = 2022;
	g_liste_clients[0].rib = 1;
	g_liste_clients[0].pi = 1;
	g_liste_clients[0].fact_tel = 1;
	g_liste_clients[0].list_adresse[0].numero = 1;
	strcpy(g_liste_clients[0].list_adresse[0].voie, "Rue");
	g_liste_clients[0].list_adresse[0].cp = 29200;
	strcpy(g_liste_clients[0].list_adresse[0].ville, "Brest");
	
	g_liste_clients[1].id = 1;
	strcpy(g_liste_clients[1].prenom, "Jules");
	strcpy(g_liste_clients[1].nom, "FRÉRE");
	g_liste_clients[1].donnee_bc_client.numero = 121575219;
	g_liste_clients[1].donnee_bc_client.crypto = 100;
	g_liste_clients[1].donnee_bc_client.date_exp.jour = 1;
	g_liste_clients[1].donnee_bc_client.date_exp.mois = 1;
	g_liste_clients[1].donnee_bc_client.date_exp.annee = 2022;
	g_liste_clients[1].rib = 1;
	g_liste_clients[1].pi = 1;
	g_liste_clients[1].fact_tel = 1;
	g_liste_clients[1].list_adresse[0].numero = 1;
	strcpy(g_liste_clients[1].list_adresse[0].voie, "Rue");
	g_liste_clients[1].list_adresse[0].cp = 29200;
	strcpy(g_liste_clients[1].list_adresse[0].ville, "Brest");
	g_nb_clients=2;
	
	g_liste_mobiles[0].id=0;
	strcpy(g_liste_mobiles[0].nom, "Sumsong");
	g_liste_mobiles[0].prix_location = 49.99;
	g_liste_mobiles[0].prix_achat = 799.99;
	
	g_liste_mobiles[1].id=1;
	strcpy(g_liste_mobiles[1].nom, "Ifon");
	g_liste_mobiles[1].prix_location = 69.99;
	g_liste_mobiles[1].prix_achat = 1299.99;
	
	g_liste_mobiles[2].id=2;
	strcpy(g_liste_mobiles[2].nom, "Noucia");
	g_liste_mobiles[2].prix_location = 19.99;
	g_liste_mobiles[2].prix_achat = 120.0;
	
	g_nb_mobiles = 3;

	return (void *) &result;
}

liste_clients *
get_clients_1_svc(void *argp, struct svc_req *rqstp)
{
	static liste_clients result;
	int i = 0;
	for(i = 0; i < g_nb_clients; i++){
		result.liste[i] = g_liste_clients[i];
	}
	result.nb_clients = i;
	return &result;
}

client *
get_client_1_svc(int *argp, struct svc_req *rqstp)
{
	if(*argp==NULL){
		return NULL;
	}

	static client  result;
	for(int i = 0; i<g_nb_clients; i++){
		if(g_liste_clients[i].id == *argp){
			result = g_liste_clients[i];
			break;
		}
	}

	return &result;
}

int *
creer_commande_1_svc(int *argp, struct svc_req *rqstp)
{
	if(*argp==NULL){
		return NULL;
	}

	static int  result;

	if(g_nb_commandes>=NB_MAX_COMMANDES){
		result = -1;
	}else{
		g_liste_commandes[g_nb_commandes].id = g_nb_commandes;
		g_liste_commandes[g_nb_commandes].id_client = *argp;
		g_liste_commandes[g_nb_commandes].valide = 0;
		result = g_nb_commandes;
		g_nb_commandes++;
	}

	return &result;
}

liste_mobiles *
get_mobiles_1_svc(void *argp, struct svc_req *rqstp)
{
	static liste_mobiles  result;
	int i = 0;
	for(i = 0; i < g_nb_mobiles; i++){
		result.liste[i] = g_liste_mobiles[i];
	}
	result.nb_mobiles = i;
	
	return &result;
}

mobile *
get_mobile_1_svc(int *argp, struct svc_req *rqstp)
{
	if(*argp==NULL){
		return NULL;
	}

	static mobile  result;

	for(int i = 0; i < g_nb_mobiles; i++){
		if(g_liste_mobiles[i].id==*argp){
			result = g_liste_mobiles[i];
			break;
		}
	}

	return &result;
}

boolean mobile_exist(int id){
	for(int i = 0; i<g_nb_mobiles; i++){
		if(g_liste_mobiles[i].id==id){
			return 1;
		}
	}
	return 0;
}

boolean *
set_mobile_1_svc(params_set_mobile *argp, struct svc_req *rqstp)
{
	static boolean  result = 0;

	if(argp->id_commande==NULL
		|| argp->param_mobile.connectivite==NULL
		|| argp->param_mobile.couleur==NULL
		|| argp->param_mobile.id_mobile==NULL
		|| !mobile_exist(argp->param_mobile.id_mobile)
		|| argp->param_mobile.memoire==NULL
		|| argp->param_mobile.type==NULL){
			return &result;
	}

	for(int i = 0; i < g_nb_commandes; i++){
		if(g_liste_commandes[i].id==argp->id_commande){
			g_liste_commandes[i].mobile = argp->param_mobile;
			result = 1;
			break;
		}
	}

	return &result;
}

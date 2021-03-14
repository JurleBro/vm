/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "up2youService.h"


void
up2us_prog_1(char *host)
{
	CLIENT *clnt;
	void  *result_1;
	char *init_1_arg;
	liste_clients  *result_2;
	char *get_clients_1_arg;
	client  *result_3;
	int  get_client_1_arg;
	int  *result_4;
	int  creer_commande_1_arg;
	liste_mobiles  *result_5;
	char *get_mobiles_1_arg;
	mobile  *result_6;
	int  get_mobile_1_arg;
	boolean  *result_7;
	params_set_mobile  set_mobile_1_arg;
	liste_assurances  *result_8;
	char *get_assurances_1_arg;
	assurance  *result_9;
	int  get_assurance_1_arg;
	boolean  *result_10;
	params_set_assurance  set_assurance_1_arg;
	boolean  *result_11;
	params_set_adresse  set_adresse_livraison_1_arg;
	liste_commandes  *result_12;
	char *get_commandes_1_arg;
	commande  *result_13;
	int  get_commande_1_arg;
	boolean  *result_14;
	int  valide_commande_1_arg;
	boolean  *result_15;
	params_set_dl  set_date_livraison_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, UP2US_PROG, UP2US_V_1, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	result_1 = init_1((void*)&init_1_arg, clnt);
	if (result_1 == (void *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_2 = get_clients_1((void*)&get_clients_1_arg, clnt);
	if (result_2 == (liste_clients *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_3 = get_client_1(&get_client_1_arg, clnt);
	if (result_3 == (client *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_4 = creer_commande_1(&creer_commande_1_arg, clnt);
	if (result_4 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_5 = get_mobiles_1((void*)&get_mobiles_1_arg, clnt);
	if (result_5 == (liste_mobiles *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_6 = get_mobile_1(&get_mobile_1_arg, clnt);
	if (result_6 == (mobile *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_7 = set_mobile_1(&set_mobile_1_arg, clnt);
	if (result_7 == (boolean *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_8 = get_assurances_1((void*)&get_assurances_1_arg, clnt);
	if (result_8 == (liste_assurances *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_9 = get_assurance_1(&get_assurance_1_arg, clnt);
	if (result_9 == (assurance *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_10 = set_assurance_1(&set_assurance_1_arg, clnt);
	if (result_10 == (boolean *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_11 = set_adresse_livraison_1(&set_adresse_livraison_1_arg, clnt);
	if (result_11 == (boolean *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_12 = get_commandes_1((void*)&get_commandes_1_arg, clnt);
	if (result_12 == (liste_commandes *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_13 = get_commande_1(&get_commande_1_arg, clnt);
	if (result_13 == (commande *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_14 = valide_commande_1(&valide_commande_1_arg, clnt);
	if (result_14 == (boolean *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_15 = set_date_livraison_1(&set_date_livraison_1_arg, clnt);
	if (result_15 == (boolean *) NULL) {
		clnt_perror (clnt, "call failed");
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	up2us_prog_1 (host);
exit (0);
}

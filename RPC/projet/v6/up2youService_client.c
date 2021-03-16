/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "up2youService.h"

void afficher_client(const client * c){
	printf("Client %d : \n", c->id);
	printf("\tId : %d\n", c->id);
    printf("\tNom : %s\n", c->nom);
    printf("\tPrenom : %s\n", c->prenom);
    
printf("\tDonnees bancaires :\n");
    printf("\t\tNumero : %d\n", c->donnee_bc_client.numero);
    printf("\t\tDate : %d/%d/%d\n", c->donnee_bc_client.date_exp.jour, c->donnee_bc_client.date_exp.mois, c->donnee_bc_client.date_exp.annee);
    printf("\t\tCrypto : %d\n", c->donnee_bc_client.crypto);
    
    printf("\tRib : %s\n", c->rib ? "Valide" : "Non valide");
    printf("\tPi : %s\n", c->pi ? "Valide" : "Non valide");
    printf("\tFact_tel : %s\n", c->fact_tel ? "Valide" : "Non valide");
    
    printf("\tListe adresses :\n");
    for (int i = 0; i<1; i ++) {
        printf("\t\tAdresse %d : \n", i);
        printf("\t\t\t%d %s \n\t\t\t%d %s\n", c->list_adresse[i].numero, c->list_adresse[i].voie, c->list_adresse[i].cp, c->list_adresse[i].ville);
    }
	return;
}

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
	get_client_1_arg = 0;
	result_3 = get_client_1(&get_client_1_arg, clnt);
	if (result_3 == (client *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	afficher_client(result_3);
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

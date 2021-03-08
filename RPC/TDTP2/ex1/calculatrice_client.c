/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "calculatrice.h"


void
calc_prog_1(char *host)
{
	CLIENT *clnt;
	long  *result_1;
	params  ajouter_1_arg;
	long  *result_2;
	params  soustraire_1_arg;
	long  *result_3;
	params  multiplier_1_arg;
	void  *result_4;
	int  memoriser_dernier_resultat_1_arg;
	long  *result_5;
	int  extraire_memoire_1_arg;
	void  *result_6;
	char *allumer_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, CALC_PROG, CALC_VERSION_1, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */
	
	result_6 = allumer_1((void*)&allumer_1_arg, clnt);
	if (result_6 == (void *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	
	printf("Calculatrice allumé\n");
	
	extraire_memoire_1_arg = 0;
	
	result_5 = extraire_memoire_1(&extraire_memoire_1_arg, clnt);
	if (result_5 == (long *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	
	printf("Registre 1 : %ld\n", *result_5);
	
	ajouter_1_arg.param1 = *result_5;
	ajouter_1_arg.param2 = 10.0;
	
	result_1 = ajouter_1(&ajouter_1_arg, clnt);
	if (result_1 == (long *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	
	printf("%ld + %ld = %ld\n", ajouter_1_arg.param1, ajouter_1_arg.param2, *result_1);
	
	/*result_2 = soustraire_1(&soustraire_1_arg, clnt);
	if (result_2 == (long *) NULL) {
		clnt_perror (clnt, "call failed");
	}*/
	
	multiplier_1_arg.param1 = *result_1;
	multiplier_1_arg.param2 = 4.0;
	result_3 = multiplier_1(&multiplier_1_arg, clnt);
	if (result_3 == (long *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	
	printf("%ld * %ld = %ld\n", multiplier_1_arg.param1, multiplier_1_arg.param2, *result_3);
	
	memoriser_dernier_resultat_1_arg = 2;
	
	result_4 = memoriser_dernier_resultat_1(&memoriser_dernier_resultat_1_arg, clnt);
	if (result_4 == (void *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	
	printf("Enregistrement registre 3\n");
	
	int extraire_memoire_2_arg = 2;
	
	result_2 = extraire_memoire_1(&extraire_memoire_2_arg, clnt);
	if (result_2 == (long *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	
	printf("Registre 3 : %ld\n", *result_2);
	
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
	calc_prog_1 (host);
exit (0);
}
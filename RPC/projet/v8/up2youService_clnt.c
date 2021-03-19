/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include <memory.h> /* for memset */
#include "up2youService.h"

/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = { 25, 0 };

void *
init_1(void *argp, CLIENT *clnt)
{
	static char clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, INIT,
		(xdrproc_t) xdr_void, (caddr_t) argp,
		(xdrproc_t) xdr_void, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return ((void *)&clnt_res);
}

liste_clients *
get_clients_1(void *argp, CLIENT *clnt)
{
	static liste_clients clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, GET_CLIENTS,
		(xdrproc_t) xdr_void, (caddr_t) argp,
		(xdrproc_t) xdr_liste_clients, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

client *
get_client_1(int *argp, CLIENT *clnt)
{
	static client clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, GET_CLIENT,
		(xdrproc_t) xdr_int, (caddr_t) argp,
		(xdrproc_t) xdr_client, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

int *
creer_commande_1(int *argp, CLIENT *clnt)
{
	static int clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, CREER_COMMANDE,
		(xdrproc_t) xdr_int, (caddr_t) argp,
		(xdrproc_t) xdr_int, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

liste_mobiles *
get_mobiles_1(void *argp, CLIENT *clnt)
{
	static liste_mobiles clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, GET_MOBILES,
		(xdrproc_t) xdr_void, (caddr_t) argp,
		(xdrproc_t) xdr_liste_mobiles, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

mobile *
get_mobile_1(int *argp, CLIENT *clnt)
{
	static mobile clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, GET_MOBILE,
		(xdrproc_t) xdr_int, (caddr_t) argp,
		(xdrproc_t) xdr_mobile, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

boolean *
set_mobile_1(params_set_mobile *argp, CLIENT *clnt)
{
	static boolean clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, SET_MOBILE,
		(xdrproc_t) xdr_params_set_mobile, (caddr_t) argp,
		(xdrproc_t) xdr_boolean, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

liste_assurances *
get_assurances_1(void *argp, CLIENT *clnt)
{
	static liste_assurances clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, GET_ASSURANCES,
		(xdrproc_t) xdr_void, (caddr_t) argp,
		(xdrproc_t) xdr_liste_assurances, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

assurance *
get_assurance_1(int *argp, CLIENT *clnt)
{
	static assurance clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, GET_ASSURANCE,
		(xdrproc_t) xdr_int, (caddr_t) argp,
		(xdrproc_t) xdr_assurance, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

boolean *
set_assurance_1(params_set_assurance *argp, CLIENT *clnt)
{
	static boolean clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, SET_ASSURANCE,
		(xdrproc_t) xdr_params_set_assurance, (caddr_t) argp,
		(xdrproc_t) xdr_boolean, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

boolean *
set_adresse_livraison_1(params_set_adresse *argp, CLIENT *clnt)
{
	static boolean clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, SET_ADRESSE_LIVRAISON,
		(xdrproc_t) xdr_params_set_adresse, (caddr_t) argp,
		(xdrproc_t) xdr_boolean, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

boolean *
valide_commande_1(int *argp, CLIENT *clnt)
{
	static boolean clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, VALIDE_COMMANDE,
		(xdrproc_t) xdr_int, (caddr_t) argp,
		(xdrproc_t) xdr_boolean, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

boolean *
set_date_livraison_1(params_set_dl *argp, CLIENT *clnt)
{
	static boolean clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, SET_DATE_LIVRAISON,
		(xdrproc_t) xdr_params_set_dl, (caddr_t) argp,
		(xdrproc_t) xdr_boolean, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

commande *
get_commande_1(int *argp, CLIENT *clnt)
{
	static commande clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, GET_COMMANDE,
		(xdrproc_t) xdr_int, (caddr_t) argp,
		(xdrproc_t) xdr_commande, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

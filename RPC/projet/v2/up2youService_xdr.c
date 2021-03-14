/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "up2youService.h"

bool_t
xdr_boolean(xdrs, objp)
	XDR *xdrs;
	boolean *objp;
{

	if (!xdr_int(xdrs, objp))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_date(xdrs, objp)
	XDR *xdrs;
	date *objp;
{

	if (!xdr_int(xdrs, &objp->jour))
		return (FALSE);
	if (!xdr_int(xdrs, &objp->mois))
		return (FALSE);
	if (!xdr_int(xdrs, &objp->annee))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_adresse(xdrs, objp)
	XDR *xdrs;
	adresse *objp;
{

	if (!xdr_int(xdrs, &objp->numero))
		return (FALSE);
	if (!xdr_vector(xdrs, (char *)objp->voie, sizeVoieAdresse, sizeof(char), (xdrproc_t)xdr_char))
		return (FALSE);
	if (!xdr_int(xdrs, &objp->cp))
		return (FALSE);
	if (!xdr_vector(xdrs, (char *)objp->ville, sizeVilleAdresse, sizeof(char), (xdrproc_t)xdr_char))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_donnee_bc(xdrs, objp)
	XDR *xdrs;
	donnee_bc *objp;
{

	if (!xdr_int(xdrs, &objp->numero))
		return (FALSE);
	if (!xdr_date(xdrs, &objp->date_exp))
		return (FALSE);
	if (!xdr_int(xdrs, &objp->crypto))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_client(xdrs, objp)
	XDR *xdrs;
	client *objp;
{

	if (!xdr_int(xdrs, &objp->id))
		return (FALSE);
	if (!xdr_vector(xdrs, (char *)objp->nom, sizeNom, sizeof(char), (xdrproc_t)xdr_char))
		return (FALSE);
	if (!xdr_vector(xdrs, (char *)objp->prenom, sizeNom, sizeof(char), (xdrproc_t)xdr_char))
		return (FALSE);
	if (!xdr_donnee_bc(xdrs, &objp->donnee_bc))
		return (FALSE);
	if (!xdr_boolean(xdrs, &objp->rib))
		return (FALSE);
	if (!xdr_boolean(xdrs, &objp->pi))
		return (FALSE);
	if (!xdr_boolean(xdrs, &objp->fact_tel))
		return (FALSE);
	if (!xdr_vector(xdrs, (char *)objp->list_adresse, nbAdresseClient, sizeof(adresse), (xdrproc_t)xdr_adresse))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_mobile(xdrs, objp)
	XDR *xdrs;
	mobile *objp;
{

	if (!xdr_int(xdrs, &objp->id))
		return (FALSE);
	if (!xdr_vector(xdrs, (char *)objp->nom, sizeNom, sizeof(char), (xdrproc_t)xdr_char))
		return (FALSE);
	if (!xdr_float(xdrs, &objp->prix_location))
		return (FALSE);
	if (!xdr_float(xdrs, &objp->prix_achat))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_e_type(xdrs, objp)
	XDR *xdrs;
	e_type *objp;
{

	if (!xdr_enum(xdrs, (enum_t *)objp))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_type(xdrs, objp)
	XDR *xdrs;
	type *objp;
{

	if (!xdr_e_type(xdrs, objp))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_e_couleur(xdrs, objp)
	XDR *xdrs;
	e_couleur *objp;
{

	if (!xdr_enum(xdrs, (enum_t *)objp))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_couleur(xdrs, objp)
	XDR *xdrs;
	couleur *objp;
{

	if (!xdr_e_couleur(xdrs, objp))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_e_connect(xdrs, objp)
	XDR *xdrs;
	e_connect *objp;
{

	if (!xdr_enum(xdrs, (enum_t *)objp))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_connectivite(xdrs, objp)
	XDR *xdrs;
	connectivite *objp;
{

	if (!xdr_e_connect(xdrs, objp))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_e_memoire(xdrs, objp)
	XDR *xdrs;
	e_memoire *objp;
{

	if (!xdr_enum(xdrs, (enum_t *)objp))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_memoire(xdrs, objp)
	XDR *xdrs;
	memoire *objp;
{

	if (!xdr_e_memoire(xdrs, objp))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_params_mobile(xdrs, objp)
	XDR *xdrs;
	params_mobile *objp;
{

	if (!xdr_int(xdrs, &objp->id_mobile))
		return (FALSE);
	if (!xdr_type(xdrs, &objp->type))
		return (FALSE);
	if (!xdr_couleur(xdrs, &objp->couleur))
		return (FALSE);
	if (!xdr_connectivite(xdrs, &objp->connectivite))
		return (FALSE);
	if (!xdr_memoire(xdrs, &objp->memoire))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_assurance(xdrs, objp)
	XDR *xdrs;
	assurance *objp;
{

	if (!xdr_int(xdrs, &objp->id))
		return (FALSE);
	if (!xdr_float(xdrs, &objp->prix))
		return (FALSE);
	if (!xdr_vector(xdrs, (char *)objp->description, sizeDescriptionAssurance, sizeof(char), (xdrproc_t)xdr_char))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_commande(xdrs, objp)
	XDR *xdrs;
	commande *objp;
{

	if (!xdr_int(xdrs, &objp->id))
		return (FALSE);
	if (!xdr_int(xdrs, &objp->id_client))
		return (FALSE);
	if (!xdr_params_mobile(xdrs, &objp->mobile))
		return (FALSE);
	if (!xdr_int(xdrs, &objp->id_assurance))
		return (FALSE);
	if (!xdr_int(xdrs, &objp->id_adresse_client))
		return (FALSE);
	if (!xdr_boolean(xdrs, &objp->valide))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_livraison(xdrs, objp)
	XDR *xdrs;
	livraison *objp;
{

	if (!xdr_int(xdrs, &objp->id))
		return (FALSE);
	if (!xdr_int(xdrs, &objp->id_commande))
		return (FALSE);
	if (!xdr_date(xdrs, &objp->date))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_params_set_mobile(xdrs, objp)
	XDR *xdrs;
	params_set_mobile *objp;
{

	if (!xdr_int(xdrs, &objp->id_commande))
		return (FALSE);
	if (!xdr_params_mobile(xdrs, &objp->param_mobile))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_params_set_assurance(xdrs, objp)
	XDR *xdrs;
	params_set_assurance *objp;
{

	if (!xdr_int(xdrs, &objp->id_commande))
		return (FALSE);
	if (!xdr_int(xdrs, &objp->id_assurance))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_params_set_adresse(xdrs, objp)
	XDR *xdrs;
	params_set_adresse *objp;
{

	if (!xdr_int(xdrs, &objp->id_commande))
		return (FALSE);
	if (!xdr_int(xdrs, &objp->id_adresse_client))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_params_set_dl(xdrs, objp)
	XDR *xdrs;
	params_set_dl *objp;
{

	if (!xdr_int(xdrs, &objp->id_commande))
		return (FALSE);
	if (!xdr_date(xdrs, &objp->date))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_liste_clients(xdrs, objp)
	XDR *xdrs;
	liste_clients *objp;
{

	if (!xdr_vector(xdrs, (char *)objp->liste, nbMaxClients, sizeof(client), (xdrproc_t)xdr_client))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_liste_mobiles(xdrs, objp)
	XDR *xdrs;
	liste_mobiles *objp;
{

	if (!xdr_vector(xdrs, (char *)objp->liste, nbMaxMobiles, sizeof(mobile), (xdrproc_t)xdr_mobile))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_liste_assurances(xdrs, objp)
	XDR *xdrs;
	liste_assurances *objp;
{

	if (!xdr_vector(xdrs, (char *)objp->liste, nbMaxAssurances, sizeof(assurance), (xdrproc_t)xdr_assurance))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_liste_commandes(xdrs, objp)
	XDR *xdrs;
	liste_commandes *objp;
{

	if (!xdr_vector(xdrs, (char *)objp->liste, nbMaxCommandes, sizeof(struct commandes), (xdrproc_t)xdr_commandes))
		return (FALSE);
	return (TRUE);
}

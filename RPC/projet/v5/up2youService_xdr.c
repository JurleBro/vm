/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "up2youService.h"

bool_t
xdr_boolean (XDR *xdrs, boolean *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_date (XDR *xdrs, date *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->jour))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->mois))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->annee))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_adresse (XDR *xdrs, adresse *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->numero))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->cp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_donnee_bc (XDR *xdrs, donnee_bc *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->numero))
		 return FALSE;
	 if (!xdr_date (xdrs, &objp->date_exp))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->crypto))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_client (XDR *xdrs, client *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->id))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->nom, 10))
		 return FALSE;
	 if (!xdr_donnee_bc (xdrs, &objp->donnee_bc))
		 return FALSE;
	 if (!xdr_boolean (xdrs, &objp->rib))
		 return FALSE;
	 if (!xdr_boolean (xdrs, &objp->pi))
		 return FALSE;
	 if (!xdr_boolean (xdrs, &objp->fact_tel))
		 return FALSE;
	 if (!xdr_adresse (xdrs, &objp->adresse_client))
		 return FALSE;
	return TRUE;
}

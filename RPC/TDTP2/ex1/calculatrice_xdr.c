/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "calculatrice.h"

bool_t
xdr_params (XDR *xdrs, params *objp)
{
	register int32_t *buf;

	 if (!xdr_long (xdrs, &objp->param1))
		 return FALSE;
	 if (!xdr_long (xdrs, &objp->param2))
		 return FALSE;
	return TRUE;
}

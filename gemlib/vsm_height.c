
#include "gem.h"


int
vsm_height (int handle, int height)
{
	vdi_ptsin[0] = 0;
	vdi_ptsin[1] = height;
	vdi_control[0] = 19;
	vdi_control[1] = 1;
	vdi_control[3] = 0;
	vdi_control[6] = handle;
	vdi (&vdi_params);
	return (int) vdi_intout[0];
}

/*
 * * marker attribute
 */
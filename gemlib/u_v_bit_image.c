

#include "gem_vdiP.h"

/** This escape is required only for printers.
 *  It allows the application to request processing of a bit image file
 *
 *  @param handle Device handle
 *  @param filename 
 *  @param aspect Aspect ratio flag :
 *         - 0 = ignore aspect ratio
 *         - 1 = honor pixel aspect ratio
 *  @param x_scale Scaling for x-axis :
 *         - 0 = fractional scaling
 *         - 1 = integer scaling
 *  @param y_scale  Scaling for y-axis :
 *         - 0 = fractional scaling
 *         - 1 = integer scaling
 *  @param h_align horizontal alignment :
 *         - 0 = left
 *         - 1 = center
 *         - 2 = right
 *  @param v_align vertical alignment :
 *         - 0 = top
 *         - 1 = middle
 *         - 2 = bottom
 *  @param pxy output rectangle
 *
 *  @since all VDI versions
 *
 *
 */

void
udef_v_bit_image (short handle, const char *filename, short aspect, short x_scale,
             short y_scale, short h_align, short v_align, short *pxy)
{

	short n = 5 + vdi_str2array_n (filename, _VDIParBlk.vdi_intin + 5, VDI_INTINMAX-5);

	VDI_PARAMS(_VDIParBlk.vdi_control, _VDIParBlk.vdi_intin, pxy, vdi_dummy, vdi_dummy);

	_VDIParBlk.vdi_intin[0] = aspect;
	_VDIParBlk.vdi_intin[1] = x_scale;
	_VDIParBlk.vdi_intin[2] = y_scale;
	_VDIParBlk.vdi_intin[3] = h_align;
	_VDIParBlk.vdi_intin[4] = v_align;
	
	VDI_TRAP_ESC (vdi_params, handle, 5,23, 2,n);
}

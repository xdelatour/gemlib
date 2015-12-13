

#include "gem_vdiP.h"

/** 
 *
 *  @param handle Device handle
 *  @param filename
 *
 *  @return 
 *
 *  @since 
 *
 *  @sa
 *
 *
 *
 */

short
udef_v_savecache (short handle, const char *filename)
{
	short n = vdi_str2array_n (filename, _VDIParBlk.vdi_intin, VDI_INTINMAX);

	VDI_PARAMS(_VDIParBlk.vdi_control, _VDIParBlk.vdi_intin, 0L, _VDIParBlk.vdi_intout, vdi_dummy );
	
	VDI_TRAP (vdi_params, handle, 249, 0,n);
	
	return _VDIParBlk.vdi_intout[0];
}

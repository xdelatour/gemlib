
#include "gem.h"


int
evnt_multi (int Type, int Clicks, int WhichButton, int WhichState,
	    int EnterExit1, int In1X, int In1Y, int In1W, int In1H,
	    int EnterExit2, int In2X, int In2Y, int In2W, int In2H,
	    int MesagBuf[], unsigned long Interval,
	    int *OutX, int *OutY, int *ButtonState, int *KeyState, int *Key,
	    int *ReturnCount)
{
	unsigned short *i = (unsigned short *) &Interval;

#ifndef __MSHORT__
	register int j;
	short dummy[8];
#endif

	aes_intin[0] = Type;
	aes_intin[1] = Clicks;
	aes_intin[2] = WhichButton;
	aes_intin[3] = WhichState;
	aes_intin[4] = EnterExit1;
	aes_intin[5] = In1X;
	aes_intin[6] = In1Y;
	aes_intin[7] = In1W;
	aes_intin[8] = In1H;
	aes_intin[9] = EnterExit2;
	aes_intin[10] = In2X;
	aes_intin[11] = In2Y;
	aes_intin[12] = In2W;
	aes_intin[13] = In2H;
	aes_intin[14] = i[1];
	aes_intin[15] = i[0];

#ifdef __MSHORT__
	aes_addrin[0] = (long) MesagBuf;
#else
	aes_addrin[0] = (long) &dummy[0];
#endif

	aes_control[0] = 25;
	aes_control[1] = 16;
	aes_control[2] = 7;
	aes_control[3] = 1;
	aes_control[4] = 0;
	aes (&aes_params);

	*OutX = aes_intout[1];
	*OutY = aes_intout[2];
	*ButtonState = aes_intout[3];
	*KeyState = aes_intout[4];
	*Key = aes_intout[5];
	*ReturnCount = aes_intout[6];

#ifndef __MSHORT__
	if (MesagBuf != (int *) 0)
		for (j = 0; j < 8; j++)
			MesagBuf[j] = dummy[j];
#endif

	return aes_intout[0];
}

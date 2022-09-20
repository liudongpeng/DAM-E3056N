/**************************************************************************/
/* LabWindows/CVI User Interface Resource (UIR) Include File              */
/*                                                                        */
/* WARNING: Do not add to, delete from, or otherwise modify the contents  */
/*          of this include file.                                         */
/**************************************************************************/

#include <userint.h>

#ifdef __cplusplus
    extern "C" {
#endif

     /* Panels and Controls: */

#define  PANEL                            1       /* callback function: panelCB */
#define  PANEL_STRING_9                   2       /* control type: string, callback function: (none) */
#define  PANEL_STRING_3                   3       /* control type: string, callback function: (none) */
#define  PANEL_STRING_5                   4       /* control type: string, callback function: (none) */
#define  PANEL_STRING_4                   5       /* control type: string, callback function: (none) */
#define  PANEL_STRING_8                   6       /* control type: string, callback function: (none) */
#define  PANEL_STRING_7                   7       /* control type: string, callback function: (none) */
#define  PANEL_STRING_C_IN_ACI            8       /* control type: string, callback function: (none) */
#define  PANEL_STRING_OUT_DCI             9       /* control type: string, callback function: (none) */
#define  PANEL_STRING_B_IN_ACI            10      /* control type: string, callback function: (none) */
#define  PANEL_STRING_A_IN_ACI            11      /* control type: string, callback function: (none) */
#define  PANEL_STRING_OUT_DCV             12      /* control type: string, callback function: (none) */
#define  PANEL_STRING_C_IN_ACV            13      /* control type: string, callback function: (none) */
#define  PANEL_STRING_B_IN_ACV            14      /* control type: string, callback function: (none) */
#define  PANEL_STRING_WORK_STATE          15      /* control type: string, callback function: (none) */
#define  PANEL_STRING_11                  16      /* control type: string, callback function: (none) */
#define  PANEL_STRING_10                  17      /* control type: string, callback function: (none) */
#define  PANEL_STRING_A_IN_ACV            18      /* control type: string, callback function: (none) */
#define  PANEL_STRING_6                   19      /* control type: string, callback function: (none) */
#define  PANEL_STRING                     20      /* control type: string, callback function: (none) */
#define  PANEL_STRING_2                   21      /* control type: string, callback function: (none) */
#define  PANEL_CANVAS                     22      /* control type: canvas, callback function: (none) */
#define  PANEL_LED_CONNECT_STATE          23      /* control type: LED, callback function: (none) */

#define  PANEL_INIT                       2
#define  PANEL_INIT_PICTURE_STARTPAGE     2       /* control type: picture, callback function: (none) */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK panelCB(int panel, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
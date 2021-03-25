#include "headfile.h"
void image_center(short v_run,short bias_cen)
{
    target_Vx=-0.5*Diff_center(bias_cen);

    target_Vy=-v_run;
    target_Wz=-50*Diff_center(0);
}

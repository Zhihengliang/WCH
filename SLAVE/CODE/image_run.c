#include "headfile.h"
void image_center(short v_run,short bias_cen)
{

    target_Vx=Diff_center(bias_cen);
    target_Vy=v_run;
    target_Wz=Slope_center();
}

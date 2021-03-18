#include "headfile.h"
void image_center(short v_run)
{
    ctrl_main();
    target_Vx=Diff_center();
    target_Vy=-v_run;
    target_Wz=Slope_center();
}

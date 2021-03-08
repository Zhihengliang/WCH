#include "Uart_TAR.h"
//-------------------------------------------------------------------------------------------------------------------
//  @brief      串口传回int16数组示波
//  @param      void
//  @return     void
//  @autor      SWG
//  Sample usage:           Uart_sent_wave(actual_velocity,3);
//  @note
//-------------------------------------------------------------------------------------------------------------------
void Uart_sent_wave(int16 *_deta,int16 _num)
{

    unsigned char _s=0;
    uart_putchar(UART_1, 0x03);
    uart_putchar(UART_1, 0xFC);
    for(int i=0;i<_num;i++)
    {
        _s = (unsigned char)((_deta[i]) & 0x00FF);
        uart_putchar(UART_1, _s);
        _s = (_deta[i])>>8;
        uart_putchar(UART_1, _s);
    }
    uart_putchar(UART_1, 0xFC);
    uart_putchar(UART_1, 0x03);
}
//-------------------------------------------------------------------------------------------------------------------
//  @brief      结算实际Vx,Vy,Wz
//  @param      void
//  @return     void
//  @autor      SWG
//  Sample usage:           Resolve_VAW();
//  @note                   actual_velocity[]为全局变量
//-------------------------------------------------------------------------------------------------------------------
void Resolve_VAW(void)
{
    actual_velocity[0]=(Left_front_speed-Right_front_speed-Left_rear_speed+Right_rear_speed)/4;
    actual_velocity[1]=(Left_front_speed+Right_front_speed+Left_rear_speed+Right_rear_speed)/4;
    actual_velocity[2]=(-Left_front_speed+Right_front_speed-Left_rear_speed+Right_rear_speed)*11/8;
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      遥控控制Vx,Vy,Wz
//  @param      void
//  @return     void
//  @autor      Zhiheng Liang
//  Sample usage:           Remote_control();
//  @note                   target_Vx横向target_Vy前后target_Wz逆时针
//-------------------------------------------------------------------------------------------------------------------
void Remote_control(void)
{
    uint8 dat;
    while(uart_query(UART_1,&dat));

    switch((unsigned char)(dat)){
        case 0:
            target_Vx=0;
            target_Vy=0;
            target_Wz=0;
            break;
        case 1:
            target_Vx=40;
            target_Vy=0;
            target_Wz=0;
            break;
        case 2:
            target_Vx=-40;
            target_Vy=0;
            target_Wz=0;
            break;
        case 3:
            target_Vx=0;
            target_Vy=40;
            target_Wz=0;
            break;
        case 4:
            target_Vx=0;
            target_Vy=-40;
            target_Wz=0;
            break;
        case 5:
            target_Vx=0;
            target_Vy=0;
            target_Wz=222;
            break;
        case 6:
            target_Vx=0;
            target_Vy=0;
            target_Wz=-222;
            break;
        case 7:
//            send_pic();
            break;
        default:
            target_Vx=0;
            target_Vy=0;
            target_Wz=0;
            break;

    }
}
//-------------------------------------------------------------------------------------------------------------------
//  @brief      遥控调参
//  @param      void
//  @return     void
//  @autor      Zhiheng Liang
//  Sample usage:           Remote_get_parameters();
//  @note                   调参
//-------------------------------------------------------------------------------------------------------------------
void Remote_get_parameters(void)
{
    uint8 dat;
    uart_query(UART_1,&dat);
    flag_uart[flag_j]=dat;
    flag_j++;
    if(flag_j>4)
      flag_j=4;
    if(flag_j==4)
    {
      if(flag_uart[0]==0xFF&&flag_uart[3]==0xFD)
      {
        switch((unsigned char)(flag_uart[1])){
            case 30:
                P_V=(unsigned char)(flag_uart[2]);
                break;
            case 31:
                I_V=(unsigned char)(flag_uart[2]);
                break;
            case 32:
                D_V=(unsigned char)(flag_uart[2]);
                break;
            case 34:
                P_W=(unsigned char)(flag_uart[2]);
                break;
            case 35:
                I_W=(unsigned char)(flag_uart[2]);
                break;
            case 36:
                D_W=(unsigned char)(flag_uart[2]);
                break;
            default:
                break;
        }
        flag_j=0;
      }
      else
      {
      flag_uart[0]=flag_uart[1];
      flag_uart[1]=flag_uart[2];
      flag_uart[2]=flag_uart[3];
      flag_j=4;
      }
   }
}

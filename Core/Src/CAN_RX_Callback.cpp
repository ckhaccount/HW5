#include "main.h"
#include "tim.h"
#include "usart.h"
#include "can.h"
extern CAN_RxHeaderTypeDef RxHeader;
extern uint8_t RxData[8];
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef* hcan)
{
    if(hcan->Instance == CAN1)
    {
        HAL_CAN_GetRxMessage(&hcan1, CAN_RX_FIFO0, &RxHeader, RxData);
        if(RxData[0]==0x01)
            HAL_GPIO_TogglePin(LED_R_GPIO_Port, LED_R_Pin);
        // if(RxData[0]==0x01)
        // {
        //     __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2,RxData[1]<<8|RxData[2]);
        //     HAL_TIM_PWM_Start_IT(&htim1, TIM_CHANNEL_2);
        //
        // }
        // else if(RxData[0]==0x00)
        // {
        //     HAL_TIM_PWM_Stop_IT(&htim1, TIM_CHANNEL_2);
        // }
        // if(RxData[3]==0x01)
        // {
        //     htim8.Instance->ARR=RxData[4]<<8|RxData[5];
        //     HAL_TIM_Base_Start_IT(&htim8);
        // }
        // else if(RxData[3]==0x00)
        // {
        //     HAL_TIM_Base_Stop_IT(&htim8);
        // }
    }
}
#include "main.h"
#include "stm32f4xx_hal_gpio.h"
extern uint32_t TxMailbox;
extern DMA_HandleTypeDef hdma_usart6_rx;
extern CAN_TxHeaderTypeDef TxHeader;
extern uint8_t TxData[8];
extern CAN_HandleTypeDef hcan1;
extern UART_HandleTypeDef huart6;
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if(GPIO_Pin==KEY_Pin)
    {
        //HAL_Delay(50);
        HAL_CAN_AddTxMessage(&hcan1,&TxHeader,TxData,&TxMailbox)==HAL_OK;
            //HAL_UART_Transmit(&huart6,RxData,9,100);

    }
}



// void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
// {
//     if(huart->Instance == USART6)
//     {
//         HAL_UART_Transmit(&huart6,TxData,8,100);
//         HAL_UARTEx_ReceiveToIdle_DMA(&huart6,TxData,Size);
//         __HAL_DMA_DISABLE_IT(&hdma_usart6_rx,DMA_IT_HT);
//     }
// }

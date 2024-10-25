#include "main.h"
#include "tim.h"
#include "usart.h"
#include "can.h"
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM8)
    {
        HAL_GPIO_TogglePin(LED_G_GPIO_Port, LED_G_Pin);
    }
}
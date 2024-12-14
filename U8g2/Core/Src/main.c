/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "i2c.h"
#include "tim.h"
#include "gpio.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stm32_u8g2.h"
#include "test.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
// 定义用于表示"为"字的点阵数据（第一个“为”字，假设你之前有不同样式的“为”字，这里需根据实际字模情况确定，示例中先写一种）
static const unsigned char wei[] ={
0x80,0x00,0x84,0x00,0x88,0x00,0x88,0x00,0x80,0x00,0xFE,0x1F,0x40,0x10,0x40,0x10,
0x40,0x11,0x20,0x12,0x20,0x12,0x10,0x10,0x08,0x10,0x04,0x10,0x02,0x0A,0x01,0x04
};
// 定义用于表示"所"字的点阵数据
static const unsigned char suo[] ={
0x40,0x10,0xE0,0x38,0x1C,0x07,0x04,0x01,0x04,0x01,0x7C,0x01,0x44,0x7F,0x44,0x11,
0x44,0x11,0x7C,0x11,0x04,0x11,0x04,0x11,0x82,0x10,0x82,0x10,0x41,0x10,0x20,0x10
};
// 定义用于表示"欲"字的点阵数据
static const unsigned char yu[] ={
0x28,0x04,0x48,0x04,0x84,0x04,0x92,0x7E,0x10,0x42,0x28,0x21,0x44,0x08,0x82,0x08,
0x7D,0x08,0x44,0x08,0x44,0x14,0x44,0x14,0x44,0x12,0x7C,0x22,0x44,0x21,0x80,0x40
};
// 定义用于表示"为"字的点阵数据（第二个“为”字，若有不同字模样式）
static const unsigned char wei1[] ={
0x80,0x00,0x84,0x00,0x88,0x00,0x88,0x00,0x80,0x00,0xFE,0x1F,0x40,0x10,0x40,0x10,
0x40,0x11,0x20,0x12,0x20,0x12,0x10,0x10,0x08,0x10,0x04,0x10,0x02,0x0A,0x01,0x04
};
// 定义用于表示"法"字的点阵数据
static const unsigned char fa[] ={
0x00,0x02,0x04,0x02,0x08,0x02,0x08,0x02,0xE1,0x3F,0x02,0x02,0x02,0x02,0x08,0x02,
0xF8,0x7F,0x04,0x02,0x07,0x01,0x84,0x00,0x44,0x08,0x24,0x10,0xF4,0x3F,0x20,0x20
};
// 定义用于表示"强"字的点阵数据
static const unsigned char qiang[] ={
0x00,0x00,0x9F,0x3F,0x90,0x20,0x90,0x20,0x90,0x3F,0x1E,0x04,0x02,0x04,0xC2,0x7F,
0x42,0x44,0x5E,0x44,0xD0,0x7F,0x10,0x04,0x10,0x24,0x10,0x44,0xEA,0x7F,0x04,0x40
};
// 定义用于表示"德"字的点阵数据
static const unsigned char de[] ={
0x08,0x02,0x08,0x02,0xF4,0x7F,0x02,0x02,0xE9,0x3F,0x28,0x25,0x24,0x25,0xE6,0x3F,
0x05,0x00,0xF4,0x7F,0x04,0x02,0x04,0x24,0xA4,0x44,0xA4,0x50,0x94,0x10,0x04,0x1F
};

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
    /* USER CODE BEGIN 1 */

    /* USER CODE END 1 */

    /* MCU Configuration--------------------------------------------------------*/
    HAL_Init();

    /* Configure the system clock */
    SystemClock_Config();

    /* Initialize all configured peripherals */
    MX_GPIO_Init();
    MX_I2C2_Init();
    MX_TIM1_Init();

    /* USER CODE BEGIN 2 */
    u8g2_t u8g2;
    u8g2Init(&u8g2);
    u8g2_SetFont(&u8g2, u8g2_font_ncenB12_tf);
    /* USER CODE END 2 */

    /* Infinite loop */
    /* USER CODE BEGIN WHILE */
		unsigned int x=0;
    while (1)
    {
       if (x <= 128)
    {
        x++;  // 向右滑动，可以提高每次x的增加量来控制滑动速度，每次增加1像素向右移动，可适当增大此值加快速度
    }
    else if (x > 128)
    {
        x = 0;  // 当超出屏幕范围（这里假设128是合适的边界值，可根据屏幕宽度等实际情况调整），置零重新从右侧开始滚动
    }
                // 绘制“为”字（第一个）
                u8g2_DrawXBMP(&u8g2, x+16, 0, 16, 16, wei);
                // 绘制“所”字
                u8g2_DrawXBMP(&u8g2, x+32, 0, 16, 16, suo);
                // 绘制“欲”字
                u8g2_DrawXBMP(&u8g2, x+48, 0, 16, 16, yu);
                // 绘制“为”字（第二个）
                u8g2_DrawXBMP(&u8g2, x+64, 0, 16, 16, wei1);
                // 绘制“法”字
                u8g2_DrawXBMP(&u8g2, x+80, 0, 16, 16, fa);
                // 绘制“强”字
                u8g2_DrawXBMP(&u8g2, x+96, 0, 16, 16, qiang);
                // 绘制“德”字
                u8g2_DrawXBMP(&u8g2, x+112, 0, 16, 16, de);

                // 设置字体格式为合适的字体用于显示数字（这里假设u8g2_font_ncenB10_tf合适，可根据实际调整）
                u8g2_SetFont(&u8g2, u8g2_font_ncenB10_tf);
                // 绘制数字字符串，调整坐标，使其显示在合适位置（示例坐标，可根据实际OLED屏幕布局调整）
                u8g2_DrawStr(&u8g2, 16, 50, "632207030313");

       
        u8g2_SendBuffer(&u8g2);
        HAL_Delay(100);
    }
    /* USER CODE END WHILE */
    /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    /** Initializes the RCC Oscillators according to the specified parameters
    * in the RCC_OscInitTypeDef structure.
    */
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    RCC_OscInitStruct.HSEState = RCC_HSE_ON;
    RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
    RCC_OscInitStruct.HSIState = RCC_HSI_ON;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct)!= HAL_OK)
    {
        Error_Handler();
    }
    /** Initializes the CPU, AHB and APB buses clocks
    */
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
                                  | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2)!= HAL_OK)
    {
        Error_Handler();
    }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
    /* USER CODE BEGIN Error_Handler_Debug */
    /* User can add his own implementation to report the HAL error return state */
    __disable_irq();
    while (1)
    {
    }
    /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
    /* USER CODE BEGIN 6 */
    /* User can add his own implementation to report the file name and line number,
       ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
    /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
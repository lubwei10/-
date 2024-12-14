/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "i2c.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "u8g2.h"
#include "AHT20-21_DEMO_V1_3.h"
//温
static const unsigned char  wen[] =
{0x00,0x00,0xC4,0x1F,0x48,0x10,0x48,0x10,0xC1,0x1F,0x42,0x10,0x42,0x10,0xC8,0x1F,0x08,0x00,0xE4,0x3F,0x27,0x25,0x24,0x25,0x24,0x25,0x24,0x25,0xF4,0x7F,0x00,0x00};

//湿
static const unsigned char  shi[] ={0x00,0x00,0xE4,0x1F,0x28,0x10,0x28,0x10,0xE1,0x1F,0x22,0x10,0x22,0x10,0xE8,0x1F,0x88,0x04,0x84,0x04,0x97,0x24,0xA4,0x14,0xC4,0x0C,0x84,0x04,0xF4,0x7F,0x00,0x00};

//度	
static const unsigned char  du[] ={0x80,0x00,0x00,0x01,0xFC,0x7F,0x44,0x04,0x44,0x04,0xFC,0x3F,0x44,0x04,0x44,0x04,0xC4,0x07,0x04,0x00,0xF4,0x0F,0x24,0x08,0x42,0x04,0x82,0x03,0x61,0x0C,0x1C,0x70};

//待	
static const unsigned char  dai[]={0x10,0x02,0x10,0x02,0x08,0x02,0xC4,0x3F,0x12,0x02,0x10,0x02,0xE8,0x7F,0x0C,0x08,0x0A,0x08,0xE9,0x7F,0x08,0x08,0x48,0x08,0x88,0x08,0x88,0x08,0x08,0x0A,0x08,0x04};

//检	
static const unsigned char  jian[]={0x08,0x02,0x08,0x02,0x08,0x05,0x08,0x05,0xBF,0x08,0x48,0x10,0xAC,0x6F,0x1C,0x00,0x2A,0x11,0x0A,0x12,0x49,0x12,0x88,0x0A,0x88,0x08,0x08,0x04,0xE8,0x7F,0x08,0x00};

//测	
static const unsigned char  che[]={0x00,0x20,0xE4,0x23,0x28,0x22,0x28,0x2A,0xA1,0x2A,0xA2,0x2A,0xA2,0x2A,0xA8,0x2A,0xA8,0x2A,0xA4,0x2A,0xA7,0x2A,0x84,0x20,0x44,0x21,0x44,0x22,0x24,0x28,0x10,0x10};

	
	/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
	
//write by luobitaihuangzhang
	
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
	
 void oled_write(int temperature,int humidity){

	char t[5]; // 创建一个足够大的字符数组来存储转换后的数字
	char h[5];
 double t1=( double)temperature;
	double h1=(double)humidity;
  sprintf(t, "%.2f",t1/10 ); // 使用sprintf将int变量转换为字符串
	sprintf(h, "%.2f",h1/10);
	
	 u8g2_t u8g2;
  u8g2Init(&u8g2);	
	u8g2_ClearBuffer(&u8g2); 
	u8g2_SetFont(&u8g2,u8g2_font_ncenB12_tf);//设置字体格式
	u8g2_DrawXBMP(&u8g2,16,0,16,16,wen);//（参数顺序依次是，结构体、x、y、字宽、字高、储存要显示的字点阵的数组）
	u8g2_DrawXBMP(&u8g2,32,0,16,16,du);
	u8g2_DrawStr(&u8g2,48,16,":");
	u8g2_DrawXBMP(&u8g2,16,32,16,16,shi);
	u8g2_DrawXBMP(&u8g2,32,32,16,16,du);
	u8g2_DrawStr(&u8g2,48,48,":");
	u8g2_DrawUTF8(&u8g2,55,16,t);
	u8g2_DrawUTF8(&u8g2,55,48,h);
	
	u8g2_SendBuffer(&u8g2);
 }
 void oled_write_init(){
	u8g2_t u8g2;
  u8g2Init(&u8g2);	
	u8g2_ClearBuffer(&u8g2); 
	u8g2_SetFont(&u8g2,u8g2_font_ncenB12_tf);//设置字体格式
	u8g2_DrawXBMP(&u8g2,16,0,16,16,wen);//（参数顺序依次是，结构体、x、y、字宽、字高、储存要显示的字点阵的数组）
	u8g2_DrawXBMP(&u8g2,32,0,16,16,du);
	u8g2_DrawStr(&u8g2,48,16,":");
	u8g2_DrawXBMP(&u8g2,16,32,16,16,shi);
	u8g2_DrawXBMP(&u8g2,32,32,16,16,du);
	u8g2_DrawStr(&u8g2,48,48,":");
	u8g2_DrawXBMP(&u8g2,58,0,16,16,dai);
	u8g2_DrawXBMP(&u8g2,74,0,16,16,jian);
	u8g2_DrawXBMP(&u8g2,90,0,16,16,che);
	u8g2_DrawXBMP(&u8g2,58,32,16,16,dai);
	u8g2_DrawXBMP(&u8g2,74,32,16,16,jian);
	u8g2_DrawXBMP(&u8g2,90,32,16,16,che);
	u8g2_SendBuffer(&u8g2);
 }
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	uint32_t CT_data[2]={0,0};
	volatile int  c1,t1;
	Delay_1ms(500);
	
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C2_Init();
  MX_USART1_UART_Init();
  MX_I2C1_Init();
  MX_TIM1_Init();
	
	//初始化AHT20
	AHT20_Init();
	Delay_1ms(500);
	u8g2_t u8g2;
  u8g2Init(&u8g2);
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	oled_write_init();
  while (1)
  {
    /* USER CODE END WHILE */
/* USER CODE END WHILE */
		AHT20_Read_CTdata(CT_data);       //不经过CRC校验，直接读取AHT20的温度和湿度数据    推荐每隔大于1S读一次
		//AHT20_Read_CTdata_crc(CT_data);  //crc校验后，读取AHT20的温度和湿度数据 

		c1 = CT_data[0]*1000/1024/1024;  //计算得到湿度值c1（放大了10倍）
		t1 = CT_data[1]*2000/1024/1024-500;//计算得到温度值t1（放大了10倍）
		HAL_Delay(1000);
		oled_write(t1,c1);
  /* USER CODE END 3 */
  }
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
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
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


/**
*****************************************************************************
**
**  File        : main.c
**
**  Abstract    : main function.
**
**  Functions   : main
**
**  Environment : Atollic TrueSTUDIO(R)
**                STMicroelectronics STM32F4xx Standard Peripherals Library
**
**  Distribution: The file is distributed �as is,� without any warranty
**                of any kind.
**
**  (c)Copyright Atollic AB.
**  You may use this file as-is or modify it according to the needs of your
**  project. Distribution of this file (unmodified or modified) is not
**  permitted. Atollic AB permit registered Atollic TrueSTUDIO(R) users the
**  rights to distribute the assembled, compiled & linked contents of this
**  file as part of an application binary file, provided that it is built
**  using the Atollic TrueSTUDIO(R) toolchain.
**
**
*****************************************************************************
*/

/* Includes */
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

/* Private macro */
#define BLUELED LED6
/* Private variables */
float A[6][6] = {{0}};
float B[6][6] = {{1}};
float C[6][6] = {{0}};
/* Private function prototypes */
/* Private functions */
void delay_ms(uint32_t milli);
void matFillMatrix(float *A, uint32_t rA, uint32_t cA, float x);
void matConstMultiplyMatrix(float *A, uint32_t rA, uint32_t cA, float x);
void matMultiplyMatrix(const float *A, const float *B, float *out, uint32_t rA, uint32_t cArB, uint32_t cB);
/**
**===========================================================================
**
**  Abstract: main program
**
**===========================================================================
*/
int main(void)
{
  /* Initialize LEDs */
  STM_EVAL_LEDInit(BLUELED);
  /* Turn on LEDs */
  STM_EVAL_LEDOn(BLUELED);

  /* Initialize Matrix A */
  matFillMatrix((float*) A, (uint32_t) 6, (uint32_t) 6, 3.0);

  /* Infinite loop */
  while (1)
  {

	  /*
	   * ADD YOUR CODE HERE
	   */
	  matConstMultiplyMatrix((float*) A, 6, 6, 1/3.0);	/* This line can be removed */
	  matMultiplyMatrix((float*) A,(float*) B, (float*) C,6,6,6);

	  /* Leave this here for 100ms */
	  delay_ms(100);
  }
}


/*
 * Callback used by stm32f4_discovery_audio_codec.c.
 * Refer to stm32f4_discovery_audio_codec.h for more info.
 */
void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}

/*
 * Callback used by stm324xg_eval_audio_codec.c.
 * Refer to stm324xg_eval_audio_codec.h for more info.
 */
uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}


/**
  * @brief  Delay in ms
  * @param  integer amount of milliseconds
  * @retval None
  */
void delay_ms(uint32_t milli)
{
	uint32_t delay = milli * 17612;              // approximate loops per ms at 168 MHz, Debug config
	for(; delay != 0; delay--);
}


/**
 * Fills a matrix with rows rA and columns cA with the value x. This function returns void.
 * @param A A pointer to the destination matrix
 * @param rA Rows of matrix A
 * @param cA Columns of matrix A
 * @param x Value to be loaded into matrix
 */
void matFillMatrix(float *A, uint32_t rA, uint32_t cA, float x)
{
  uint32_t i, j;

  for (i = 0; i < rA; i++)
  {
    for (j = 0; j < cA; j++)
    {
      *(A + (i * cA) + j) = x;
    }
  }
}

/**
 * Multiplies the value x into the matrix A with rows and columns specified by rA and cA
 * respectively. This function returns void.
 * @param A A pointer to the destination matrix
 * @param rA Rows of matrix A
 * @param cA Columns of matrix A
 * @param x Value to be multiplied with
 */
void matConstMultiplyMatrix(float *A, uint32_t rA, uint32_t cA, float x)
{
  uint32_t i, j;

  for (i = 0; i < rA; i++)
  {
    for (j = 0; j < cA; j++)
    {
      *(A + (i * cA) + j) *= x;
    }
  }
}


/**
 * Mulitply matrices A and B and place the answer in out. This function returns void.
 * @param A A pointer to the source matrix
 * @param B A pointer to the source matrix
 * @param out A pointer to the output matrix
 * @param rA Rows of matrix A
 * @param cArB Columns of matrix A and Rows of Matrix B
 * @param cB Columns of of matrix B
 */
void matMultiplyMatrix(const float *A, const float *B, float *out, uint32_t rA, uint32_t cArB, uint32_t cB)
{
	  /*
    TODO: Exception Handling
    */

    //local variable initialization
    uint32_t i, j;
    float ARowElement;
    float BColElement;
    //float rwColSum;
    int k = 0;

    //create resultant matrix; Initialized to zero
    float res[rA][cB];

	  for (i = 0; i < rA; i++)
	  {/**
    *****************************************************************************
    **
    **  File        : main.c
    **
    **  Abstract    : main function.
    **
    **  Functions   : main
    **
    **  Environment : Atollic TrueSTUDIO(R)
    **                STMicroelectronics STM32F4xx Standard Peripherals Library
    **
    **  Distribution: The file is distributed “as is,” without any warranty
    **                of any kind.
    **
    **  (c)Copyright Atollic AB.
    **  You may use this file as-is or modify it according to the needs of your
    **  project. Distribution of this file (unmodified or modified) is not
    **  permitted. Atollic AB permit registered Atollic TrueSTUDIO(R) users the
    **  rights to distribute the assembled, compiled & linked contents of this
    **  file as part of an application binary file, provided that it is built
    **  using the Atollic TrueSTUDIO(R) toolchain.
    **
    **
    *****************************************************************************
    */

    /* Includes */
    #include "stm32f4xx.h"
    #include "stm32f4_discovery.h"

    /* Private macro */
    #define BLUELED LED6
    /* Private variables */
    float A[6][6] = {{0}};
    float B[6][6] = {{35,1,6,26,19,24},{3,32,7,21,23,25},{31,9,2,22,27,20},{8,28,33,17,10,15},{30,5,34,12,14,16},{4,36,29,13,18,11}};
    float out[6][6] = {{0}};
    /* Private function prototypes */
    /* Private functions */
    void delay_ms(uint32_t milli);
    void matFillMatrix(float *A, uint32_t rA, uint32_t cA, float x);
    void matFillMatrix2(float *A, uint32_t rA, uint32_t cA);
    void matConstMultiplyMatrix(float *A, uint32_t rA, uint32_t cA, float x);
    void matMultiplyMatrix(const float *A, const float *B, float *out, uint32_t rA, uint32_t cArB, uint32_t cB);
    /**
    **===========================================================================
    **
    **  Abstract: main program
    **
    **===========================================================================
    */
    int main(void)
    {
      /* Initialize LEDs */
      STM_EVAL_LEDInit(BLUELED);

      /* Turn on LEDs */
      STM_EVAL_LEDOff(BLUELED);

      /* Initialize Matrix A */
      matFillMatrix((float*) A, (uint32_t) 6, (uint32_t) 6, 3.0);
      //matFillMatrix2((float*) B, (uint32_t) 6, (uint32_t) 6);
      /* Infinite loop */
      while (1)
      {

    	  /*
    	   * ADD YOUR CODE HERE
    	   */

    	  //matConstMultiplyMatrix((float*) A, 6, 6, 1/3.0);	/* This line can be removed */
    	  matMultiplyMatrix((float*) A, (float*) B, (float*) out, (uint32_t) 6, (uint32_t) 6, (uint32_t) 6);
    	  /* Leave this here for 100ms */
    	  delay_ms(100);
      }
    }


    /*
     * Callback used by stm32f4_discovery_audio_codec.c.
     * Refer to stm32f4_discovery_audio_codec.h for more info.
     */
    void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
      /* TODO, implement your code here */
      return;
    }

    /*
     * Callback used by stm324xg_eval_audio_codec.c.
     * Refer to stm324xg_eval_audio_codec.h for more info.
     */
    uint16_t EVAL_AUDIO_GetSampleCallBack(void){
      /* TODO, implement your code here */
      return -1;
    }


    /**
      * @brief  Delay in ms
      * @param  integer amount of milliseconds
      * @retval None
      */
    void delay_ms(uint32_t milli)
    {
    	uint32_t delay = milli * 17612;              // approximate loops per ms at 168 MHz, Debug config
    	for(; delay != 0; delay--);
    }


    /**
     * Fills a matrix with rows rA and columns cA with the value x. This function returns void.
     * @param A A pointer to the destination matrix
     * @param rA Rows of matrix A
     * @param cA Columns of matrix A
     * @param x Value to be loaded into matrix
     */
    void matFillMatrix(float *A, uint32_t rA, uint32_t cA, float x)
    {
      uint32_t i, j;

      for (i = 0; i < rA; i++)
      {
        for (j = 0; j < cA; j++)
        {
          *(A + (i * cA) + j) = x;
        }
      }
    }
    void matFillMatrix2(float *A, uint32_t rA, uint32_t cA)
    {
      uint32_t i, j;

      for (i = 0; i < rA; i++)
      {
        for (j = 0; j < cA; j++)
        {
          *(A + (i * cA) + j) = i;
        }
      }
    }
    /**
     * Multiplies the value x into the matrix A with rows and columns specified by rA and cA
     * respectively. This function returns void.
     * @param A A pointer to the destination matrix
     * @param rA Rows of matrix A
     * @param cA Columns of matrix A
     * @param x Value to be multiplied with
     */
    void matConstMultiplyMatrix(float *A, uint32_t rA, uint32_t cA, float x)
    {
      uint32_t i, j;

      for (i = 0; i < rA; i++)
      {
        for (j = 0; j < cA; j++)
        {
          *(A + (i * cA) + j) *= x;
        }
      }
    }


    /**
     * Mulitply matrices A and B and place the answer in out. This function returns void.
     * @param A A pointer to the source matrix
     * @param B A pointer to the source matrix
     * @param out A pointer to the output matrix
     * @param rA Rows of matrix A
     * @param cArB Columns of matrix A and Rows of Matrix B
     * @param cB Columns of of matrix B
     */
    void matMultiplyMatrix(const float *A, const float *B, float *out, uint32_t rA, uint32_t cArB, uint32_t cB)
    {
    	/* YOUR CODE GOES HERE */
    	int i=0;
    	int j=0;
    	int k=0;
    	int temp=0;

    	for(i=0;i<rA;i++)
    	{
    		for(j=0;j<cB;j++)
    		{
    			temp=0;
    			for(k=0;k<cArB;k++)
    			{
    				temp=temp+*(A+cArB*i+k)*(*(B+cB*k+j));
    			}
    			*(out+cB*i+j)=temp;
    		}
    	}


    }

      float rwColProductSumElement;
	    for (j = 0; j < cArB; j++)
	    {
	      // *(A + (i * cA) + j) *= x;
        ARowElement = *(A + (i * cArB) + j);
        BColElement = *(B + (j * cArB) + i);
	      rwColProductSumElement += ARowElement * BColElement;
	    }
      if(k < cB){
      **(res + (i * cB) + k) = rwColProductSumElement;
      k++;
      }
      else{
        k = 0;
      }
	  }
//	  *out = res;
  }

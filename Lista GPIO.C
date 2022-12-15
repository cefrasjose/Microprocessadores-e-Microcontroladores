/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/
#include "stm32f4xx.h"
#include "Utility.h"

#define K0 !(GPIOE->IDR & (1 << 4))
#define K1 !(GPIOE->IDR & (1 << 3))
#define K_UP (GPIOA->IDR & (1 << 0))
#define LED_OFF GPIOA->ODR |= (1 << 6)
#define LED_ON GPIOA->ODR &= ~(1 << 6)
#define LED_OFF1 GPIOA->ODR |= (1 << 7)
#define LED_ON1 GPIOA->ODR &= ~(1 << 7)

#define PIN1_OFF GPIOE->ODR |= (1 << 7)
#define PIN1_ON GPIOE->ODR &= ~(1 << 7)
#define PIN2_OFF GPIOE->ODR |= (1 << 8)
#define PIN2_ON GPIOE->ODR &= ~(1 << 8)

const uint8_t mask[16] = { 0b00111111, //0
                           0b00000110, //1
                           0b01011011, //2
                           0b01001111, //3
                           0b01100110, //4
                           0b01101101, //5
                           0b01111101, //6
                           0b00000111, //7
                           0b01111111, //8
                           0b01101111, //9
                           0b01110111, //A
                           0b01111100, //B
                           0b00111001, //C
                           0b01011110, //D
                           0b01111001, //E
                           0b01110001}; //F

void count_binary(){
    for(int i = 0; i < 10; i++)
    {
        GPIOA->ODR= mask[i];
        Delay_ms(500);
    }
    for(int i = 10; i > 0; i--)
    {
        GPIOA->ODR= mask[i];
        Delay_ms(500);
    }
}

void count_hexa(){
    for(int i = 0; i < 16; i++)
    {
        GPIOA->ODR= mask[i];
        Delay_ms(500);
    }
    for(int i = 16; i > 0; i--)
    {
        GPIOA->ODR= mask[i];
        Delay_ms(500);
    }
}

int cont = 1000;
int cont1 = 1200;
int cont2 = 0;
int cont3 = 0;


int main(void)
{
        Configure_Clock();
        Delay_Start(); // inicia as funções de Delay
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; // habilita o clock do GPIOA
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN; // habilita o clock do GPIOE

        //GPIOA->MODER |= (0b01 << 12);
        GPIOE->MODER |= (0b01 << 16) | (0b01 << 14);
        GPIOA->MODER |= (0b01 << 14) | (0b01 << 12) | (0b01 << 10) | (0b01 << 8) | (0b01 << 6) | (0b01 << 4) | (0b01 << 2) | (0b01 << 0); // configura o pino PA7, PA6, PA5, PA4, PA3, PA2, PA1, PA0 como saída
        GPIOE->MODER &= ~(0b11 << 6); // configurando o pino PE3 como entrada
        GPIOE->PUPDR |= (0b01 << 6); // liga o resistor do pull-up no pino PE3 (para garantir o nível alto quando a chave estiver solta)
        GPIOE->MODER &= ~(0b11 << 8); // configurando o pino PE4 como entrada
        GPIOE->PUPDR |= (0b01 << 8); // liga o resistor de pull-up no pino PE4 (para garantir o nível alto quando a chave estiver solta)

        GPIOA->MODER &= ~(0b00 << 0); //configura PA0 como entrada
        GPIOA->PUPDR |= (0b10 << 0); // liga o resistor de pull down em PA0

    /*Q1 while(1)
    {
        LED_ON;
        Delay_ms(250);
        LED_OFF;
        Delay_ms(250);
    }*/

    /*Q2 while(1)
    {
        LED_ON;
        Delay_ms(100);
        LED_OFF;
        Delay_ms(1900);
    }*/

    /*Q3 while(1)
    {
        for(int i = 0; i < 1; i++)
        {
            LED_ON;
            Delay_ms(50);
            LED_OFF;
            Delay_ms(950);
        }
        Delay_ms(1000);

        for(int i = 0; i < 1; i++)
        {
            LED_ON;
            Delay_ms(50);
            LED_OFF;
            Delay_ms(100);
            LED_ON;
            Delay_ms(50);
            LED_OFF;
            Delay_ms(900);
        }
        Delay_ms(1000);
    }*/

    /*Q4 while(1)
    {
        LED_ON;
        Delay_ms(50);
        LED_OFF;
        Delay_ms(cont);
        if(cont > 0)
        {
        cont-= 100;
        }else{
        cont = 1000;
        }
    }*/

    /*Q5 while(1)
    {
        for(int i= 0; i < 4;i++)
        {
            LED_OFF;
            Delay_ms(50);
            LED_ON;
            Delay_ms(50);
        }
        Delay_ms(1000);
        }
        while(1)
        {
          if (K_UP)
          LED_ON;
          else
          LED_OFF;
    }*/

    /*Q6 while(1)
    {
        LED_ON;
        Delay_us(8000);
        LED_OFF;
        Delay_us(2000);
    }*/

    /*Q7 while(1)
    {
        LED_ON;
        Delay_us(cont1);
        LED_OFF;
        Delay_us(10000-cont1);
        if (cont2 < 9000)
        {
            cont1+= 100;
            cont2+= 100;
        }
        if(cont2 == 9000 && cont1 > 100)
        {
            cont1-= 100;
        }
        if(cont1 == 100)
        {
            cont2= 100;
        }
    }*/

    /*Q8 while(1)
    {
        LED_ON;
        Delay_ms(250);
        LED_OFF;
        LED_ON1;
        Delay_ms(250);
        LED_OFF1;
    }*/

    /*Q9 while(1)
    {
        LED_OFF;
        Delay_ms(1000);
        LED_OFF1;
        Delay_ms(1000);
        for(int i=1; i<4; i++)
        {
          if(i%2==0)
          {
            LED_OFF1;
            LED_ON;
            Delay_ms(1000);
          }if(i%2!=0)
          {
              LED_ON1;
              Delay_ms(1000);
              LED_OFF1;
          }
        }
    }*/

    /*Q10 while(1)
    {
        LED_ON1;
        Delay_us(10000-cont2);
        LED_OFF1;
        Delay_us(cont2);
        LED_ON;
        Delay_us(cont2);
        LED_OFF;
        Delay_us(10000-cont2);
        if (cont3 < 10000)
        {
            cont2+= 100;
            cont3+= 100;
        }
        if(cont3 == 10000)
        {
            cont2-= 100;
        }
        if(cont2 == 0)
        {
            cont3= 0;
        }
    }*/

    /*Q11 while(1)
    {
        GPIOA->ODR += 0b01;
        Delay_ms(100);
    }*/

    /*Q12 while(1)
    {
       for(int i= 7 ; i>= 0; i--)
       {
           GPIOA->ODR = (1 << i);
           Delay_ms(50);
       }
       for(int i= 0 ; i<= 7;i++)
       {
           GPIOA->ODR = (1 << i);
           Delay_ms(50);
       }
    }*/

    /*Q13 while(1)
    {
        int semi2 = 7;
        int semi1 = 2;

        GPIOA->ODR = (1 << semi1)| (1 << semi2);
        Delay_ms(1000);
        semi2= 6;
        GPIOA->ODR = (1 << semi1)| (1 << semi2);
        Delay_ms(1000);
        semi1= 4;
        semi2= 5;
        GPIOA->ODR = (1 << semi1)| (1 << semi2);
        Delay_ms(1000);
        semi1 = 3;
        GPIOA->ODR = (1 << semi1)| (1 << semi2);
        Delay_ms(1000);
    }*/

    /*Q14 while(1)
    {
        for(int i = 0; i < 10; i++)
        {
            GPIOA->ODR= mask[i];
            Delay_ms(500);
        }
        for(int i = 10; i > 0; i--)
        {
            GPIOA->ODR= mask[i];
            Delay_ms(500);
        }

        for(int i = 0; i < 16; i++)
        {
            GPIOA->ODR= mask[i];
            Delay_ms(500);
        }
        for(int i = 16; i > 0; i--)
        {
            GPIOA->ODR= mask[i];
            Delay_ms(500);
        }
    }*/

    /*Q15 int count = 0;
         int count2 = 15;
        while(1)
        {
           if(count < 16)
           {
               for(int i = 0; i < 16; i++)
               {
                   int temp = 0;
                   while(temp < 100000)
                   {
                       GPIOE->ODR |= (1 << 8);
                       GPIOE->ODR &= ~(1 << 7);

                       GPIOA->ODR= mask[i];
                       Delay_us(500);

                       GPIOE->ODR |= (1 << 7);
                       GPIOE->ODR &= ~(1 << 8);

                       GPIOA->ODR= mask[count];

                       Delay_us(500);

                       temp += 1000;
                  }

               }
               count += 1;

            }
             if (count == 16)
             {
               for(int i = 16; i < 0; i--)
               {
                   int temp = 0;
                   while(temp < 100000)
                   {
                       GPIOE->ODR |= (1 << 8);
                       GPIOE->ODR &= ~(1 << 7);

                       GPIOA->ODR= mask[i];
                       Delay_us(500);

                       GPIOE->ODR |= (1 << 7);
                       GPIOE->ODR &= ~(1 << 8);

                       GPIOA->ODR= mask[count2];

                      Delay_us(500);

                       temp += 1000;
                   }

                }
                count2 -= 1;
            }
            if(count2 ==0)
            {
                count = 0;
                count2 = 15;
             }
         }

    /*Q17 while(1)
    {
        GPIOA->ODR |= (1 << 0);
        Delay_us(cont1);
        GPIOA->ODR &= ~(1 << 0);
        Delay_us(50000);
        if (cont2 < 2400)
        {
            cont1+= 100;
            cont2+= 100;
        }
        if(cont2 == 2400 && cont1 > 100)
        {
            cont1-= 100;
        }
        if(cont1 == 100)
        {
            cont2= 100;
        }
    }*/

    /*Q19 while(1)
    {
        GPIOA->ODR |= (1 << 0);
        Delay_ms(200);
        GPIOA->ODR &= ~(1 << 0);
        Delay_ms(200);
    }*/

    /*Q21 while(1)
    {
        LED_OFF1;

        if(K0)
        {
            LED_ON;
        }else{
            LED_OFF;
        }
    }*/

    /*Q22 while(1)
    {
        if(K0)
        {
            LED_ON;
        }else{
            LED_OFF;
        }

        if(K1)
        {
            LED_ON1;
        }else{
            LED_OFF1;
        }
    }*/

    /*Q23 while(1)
    {
        LED_OFF1;

        if(K0 != 0)
        {
            GPIOA->ODR ^= (1 << 6);
            Delay_ms(400);
         }
    }*/

    /*Q24 while(1)
    {
        LED_OFF;
        LED_OFF1;

        if(K0 && !K1)
        {
            while(K0)
            {
                if(K1)
                {
                    LED_ON;
                 }
                 else
                 {
                    LED_OFF;
                 }
            }
        }
    }*/

    /*Q25 while(1)
    {
          LED_OFF;
          LED_OFF1;

          if(K0 && !K1)
          {
              uint32_t c= 0;
              while(K0)
              {
                    Delay_ms(100);
                    if(K1)
                    {
                        if(c <= 1000)
                        {
                            LED_ON;
                         }
                    }
                    else
                    {
                        LED_OFF;
                    }
                    c+= 100;
              }
          }
    }*/

    /*Q26 while(1)
    {
      if(K0)
      {
          GPIOA->ODR |= (1 << 0);
          Delay_us(cont1);
          GPIOA->ODR &= ~(1 << 0);
          Delay_us(50000);
          if (cont2 < 1200)
          {
              cont1+= 100;
              cont2+= 100;
          }
          if(cont2 == 1200 && cont1 > 100)
          {
              cont1+= 100;
          }
          if(cont1 == 100)
          {
              cont2= 100;
          }
      }
      if(K1)
      {
          GPIOA->ODR |= (1 << 0);
          Delay_us(cont1);
          GPIOA->ODR &= ~(1 << 0);
          Delay_us(50000);
          if (cont2 < 1200)
          { 
              cont1+= 100;
              cont2+= 100;
           }
           if(cont2 == 1200 && cont1 > 100)
           {
              cont1-= 100;
            }
       }
    }*/
}

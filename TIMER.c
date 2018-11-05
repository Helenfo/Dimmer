#include "io430.h"
int ANGULO[]={5555, 8333, 16666, 25000 };  // vetor dos valores do angulo de disparo 
//30, 45, 90 e 135 graus respectivamente
int duracao[]={27777, 25000, 16666,8333};

int APONTADOR;

     

 
 extern void Delay(unsigned int x);


//*----------------------------------------------------------------
// Função: CONF_TIMER
// Descrição: Configura timer
// Entrada: -
// Saída: -
//*---------------------------------------------------------------- 
void CONF_TIMER (void)
{
  
   // CONFIGURA CLOCK
  
  BCSCTL1&=0x7F;       //liga oscilador -XT2OFF ligado
  
  while(IFG1==0x02)        //enquanto flag estiver ativado
    {
      IFG1=0;             // desliga flag
      Delay(1);            // tempo de estabilização=1ms
     }
  
  BCSCTL2|=0x08;              // Seleciona XT2 BIT SELS 
  
  // CONFIGURA BLOCOS

  
P1SEL|=0x08;                //Define P1.3 como função especial
P1SEL|=0x04;                //Define P1.2 como função especial
P1DIR&=0xFB;                //Define P1.
P1DIR|=0X08;


TACTL=0x0220;   
TACCTL1=0x4910;    
TACCTL2=0x0060; 

}

//DEFINE A FUNÇÃO DE TRATAMENTO DE INTERRUPÇÃO DA PORTA P2.0
#pragma vector=TIMERA1_VECTOR  // DEFINE O ENDEREÇÃO DA RTI DA PORTA 2
__interrupt void TIMERA1 (void)
{
   
    TACTL|=0x04;
    
    
    CCR2= CCR1 + ANGULO[APONTADOR];  // valor adicionado a CCR2 ( define angulo de disparo no timer)=CCRO + ANGULO DE DISPARO
    CCR0= duracao[APONTADOR];   // valor adicionado a CCR0= CCR1 + DURACAO DO PULSO 

    
    
   
}

         
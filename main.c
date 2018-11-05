
#include "io430.h"

//EXTERNAS EM C (TECLADO)

   // funções

extern void TECLADO (void);
extern void CONF_TECLADO(void);
 
   // variáveis
extern char TECLA;

//EXTERNAS EM C (TIMER)

   // funções

extern void CONF_TIMER();


int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  
CONF_TIMER();
CONF_TECLADO();
  

asm("EINT");
while(1)
{
}

}

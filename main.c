
#include "io430.h"

//EXTERNAS EM C (TECLADO)

   // fun��es

extern void TECLADO (void);
extern void CONF_TECLADO(void);
 
   // vari�veis
extern char TECLA;

//EXTERNAS EM C (TIMER)

   // fun��es

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

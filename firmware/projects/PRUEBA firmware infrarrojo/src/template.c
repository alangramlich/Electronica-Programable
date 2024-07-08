/*! @mainpage Blinking
 *
 * \section genDesc General Description
 *
 * This application makes the led blink
 *
 * \section hardConn Hardware Connection
 *
 * | Dispositivo1	|   EDU-CIAA	|
 * |:--------------:|:--------------|
 * | 	PIN1	 	| 	GPIO3		|
 *
 *
 * @section changelog Changelog
 *
 * |   Date	    | Description                                    |
 * |:----------:|:-----------------------------------------------|
 * | 01/01/2020 | Document creation		                         |
 * |			|							                     |
 *
 * @author Albano Peñalva
 *
 */

/*==================[inclusions]=============================================*/
#include "template.h"       /* <= own header */
#include "systemclock.h"
#include "Tcrt5000.h"
/*==================[macros and definitions]=================================*/

#define COUNT_DELAY 3000000
/*==================[internal data definition]===============================*/


/*==================[internal functions declaration]=========================*/
void Delay(void)
{
	uint32_t i;
		for(i=COUNT_DELAY; i!=0; i--)
		{
			   asm  ("nop");
		}
}

/*==================[external data definition]===============================*/


/*==================[external functions definition]==========================*/

int main(void){
	bool hay_objeto_cerca;
	gpio_t lectura_del_IR;
	SystemClockInit();
	Tcrt5000Init(lectura_del_IR);
    while(1){
    	hay_objeto_cerca=Tcrt5000State();
    	if (hay_objeto_cerca){
    		printf ("Hay objeto cerca \n");
    	}
    	else {
    		printf ("No hay objeto cerca \n");
    	}
    	Delay();
	}
    
	return 0;
}

/*==================[end of file]============================================*/


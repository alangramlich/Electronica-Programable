/*
 * balanza.h
 *
 *  Created on: 11/11. 2021
 *      Author: alang
 */
#include "gpio.h"
/*==================[inclusions]=============================================*/
#include "Tcrt5000.h"
#include "bool.h"
#include "gpio.h"

/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/


/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/

void BalanzaInit(void){
	analog_input_config my_analog={CH1, 0, NULL};
	AnalogInputInit(&my_analog);
}

float BalanzaRead(void){
	float lectura=0;
	float voltaje=0;
	AnalogInputReadPolling(CH1,&valor);
	voltaje=lectura*(3.3/1024);
	return (voltaje);
}
/*==================[end of file]============================================*/

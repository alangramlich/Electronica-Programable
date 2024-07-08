/*
 * Tcrt5000.h
 *
 *  Created on: 3 sep. 2021
 *      Author: alang
 */
#include "gpio.h"
gpio_t puerto_de_entrada;
/*==================[inclusions]=============================================*/
#include "Tcrt5000.h"
#include "bool.h"
#include "gpio.h"

/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

gpio_t global_dout; /*<variable GLOBAL que guarda el puerto recibido en la inicializacion>*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/
bool Tcrt5000Init(gpio_t dout)
{
	global_dout = dout;
	GPIOInit(global_dout, GPIO_INPUT);
	return true;
}

bool Tcrt5000State(void)
{
	return (bool) GPIORead(global_dout);
}

bool Tcrt5000Deinit(gpio_t dout)
{
	global_dout = dout;
	GPIODeinit();
	return true;
}
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

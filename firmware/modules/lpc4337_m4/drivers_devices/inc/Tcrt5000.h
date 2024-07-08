/*
 * Tcrt5000.h
 *
 *  Created on: 3 sep. 2021
 *      Author: alang
 */

#ifndef MODULES_LPC4337_M4_DRIVERS_DEVICES_INC_TCRT5000_H_
#define MODULES_LPC4337_M4_DRIVERS_DEVICES_INC_TCRT5000_H_

#include "gpio.h"

/*==================[external functions declaration]=========================*/
/** @brief Inicializacion de la funcion que controla el dispositivo de infrarrojos.
 * @return true if no error
 */
bool Tcrt5000Init(gpio_t dout);
/** @brief Esta funcion devuelve el estado que capta el infrarrojo.
 * @return true si encuentra un obstaculo.
 */
bool Tcrt5000State(void);
/** @brief Funcion de deinicializacion.
 * @return true if no error
 */
bool Tcrt5000Deinit(gpio_t dout);




#endif /* MODULES_LPC4337_M4_DRIVERS_DEVICES_INC_TCRT5000_H_ */

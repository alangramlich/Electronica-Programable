/* Copyright 2016, 
 * Leandro D. Medus
 * lmedus@bioingenieria.edu.ar
 * Eduardo Filomena
 * efilomena@bioingenieria.edu.ar
 * Juan Manuel Reta
 * jmrera@bioingenieria.edu.ar
 * Sebastian Mateos
 * smateos@ingenieria.uner.edu.ar
 * Facultad de Ingeniería
 * Universidad Nacional de Entre Ríos
 * Argentina
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */
#ifndef DISPLAYITS_E0803_H_
#define DISPLAYITS_E0803_H_


/** \addtogroup Drivers_Programable Drivers Programable
 ** @{ */
/** \addtogroup Drivers_Devices Drivers devices
 ** @{ */
/** \addtogroup LED Led
 ** @{ */

/** @brief Bare Metal header for leds on EDU-CIAA NXP
 **
 ** This is a driver for six leds mounted on the board
 **
 **/

/*
 * Initials     Name
 * ---------------------------
 *	LM			Leandro Medus
 *  EF			Eduardo Filomena
 *  JMR			Juan Manuel Reta
 *  SM			Sebastian Mateos
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * 20160422 v0.1 initials initial version leo
 * 20190820 v1.1 new version made by Sebastian Mateos
 */


/*==================[inclusions]=============================================*/
#include "bool.h"
#include <stdint.h>
#include "gpio.h"


/*==================[macros]=================================================*/
#define lpc4337            1
#define mk60fx512vlq15     2

/*==================[typedef]================================================*/

/*==================[external data declaration]==============================*/
/** @brief Definition of constants to reference the EDU-CIAA leds.
 */



/** \brief Definition of constants to control the EDU-CIAA leds.
 **
 **/


/*==================[external functions declaration]=========================*/

/** @fn bool ITSE0803Init(gpio_t * pins)
 * @brief Inicializa el funcionamiento de la EDU-CIA
 * Mapping ports (PinMux function), determina la direccion e inicializa el estado del DISPLAY
 * @param[in] pins
 * @return TRUE if no error
 */
bool ITSE0803Init(gpio_t * pins);

/** @fn bool ITSE0803DisplayValue(uint16_t valor)
 * @brief indica que numero se debe indicar en el DISPLAY
 * @param[in] uint16_t valor
 * @return TRUE si no hay error
 */
bool ITSE0803DisplayValue(uint16_t valor);



/** @fn uint16_t ITSE0803ReadValue(void)
 * @brief Lee el valor que se esta mostrando
  * @param[in]
 * @return uint16_t con el valor
 */
uint16_t ITSE0803ReadValue(void);


/** @fn  bool ITSE0803Deinit(gpio_t * pins);
 * @brief Finaliza el funcionamiento de la EDU-CIA. Libera los puertos
 * Conexion (PinMux function), determina la direccion y libera los puerts
 * @param[in] uint16_t valor
 * @return TRUE si no hay error
 */
 bool ITSE0803Deinit(gpio_t * pins);

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/
#endif /* DISPLAYITS_E0803_H_ */







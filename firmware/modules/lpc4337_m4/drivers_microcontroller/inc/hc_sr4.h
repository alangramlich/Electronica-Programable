
#ifndef HC_SR4_H
#define HC_SR4_H


/*
 * Initials     Name
 * ---------------------------
 *	LM			Leandro Medus
 *  EF			Eduardo Filomena
 *  JMR			Juan Manuel Reta
 *  SM			Sebastian Mateos
 *   *  Created on: 17 Septiembre. 2021
 *      Author: Joaquin Palandri
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
enum LED_COLOR {LED_3=(1<<0), LED_2=(1<<1), LED_1=(1<<2), LED_RGB_B=(1<<3), LED_RGB_G=(1<<4), LED_RGB_R=(1<<5)};


/** \brief Definition of constants to control the EDU-CIAA leds.
 **
 **/


/*==================[external functions declaration]=========================*/

/** @fn bool HcSr04Init(gpio_t echo, gpio_t trigger)
 * @brief Initialization function of sensor hc-sr04
 * @param[in] echo, trigger
 * @return TRUE if no error
 */
bool HcSr04Init(gpio_t echo, gpio_t trigger);


/** @fn int16_t HcSr04ReadDistanceCentimeters(void)
 * @brief Function to read the distance in centimeters
 * @param[in] void
 * @return value of the distance in centimeters
 */
int16_t HcSr04ReadDistanceCentimeters(void);


/** @fn int16_t HcSr04ReadDistanceInches(void)
 * @brief Function to read the distance in inches
 * @param[in] void
 * @return value of the distance in inches
 */
int16_t HcSr04ReadDistanceInches(void);


/** @fn bool HcSr04Deinit(gpio_t echo, gpio_t trigger)
 * @brief Function to release a gate port
 * @param[in] echo, trigger
 * @return TRUE if no error
 */
bool HcSr04Deinit(gpio_t echo, gpio_t trigger);



/*==================[end of file]============================================*/
#endif /* #ifndef HC_SR4_H */


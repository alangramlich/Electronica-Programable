

/** \brief Bare Metal driver for leds in the EDU-CIAA board.
 **
 **/

/*
 * Initials     Name
 * ---------------------------
 *	LM			Leandro Medus
 * EF		Eduardo Filomena
 * JMR		Juan Manuel Reta
 * SM		Sebastian Mateos
 *   Created on: 17 Septiembre. 2021
 *      Author: Joaquin Palandri
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * 20160422 v0.1 initials initial version Leando Medus
 * 20160807 v0.2 modifications and improvements made by Eduardo Filomena
 * 20160808 v0.3 modifications and improvements made by Juan Manuel Reta
 * 20180210 v0.4 modifications and improvements made by Sebastian Mateos
 * 20190820 v1.1 new version made by Sebastian Mateos
 */

/*==================[inclusions]=============================================*/
#include "led.h"
#include "gpio.h"


/*==================[internal data declaration]==============================*/

gpio_t pin_del_trigger;
gpio_t pin_del_echo;

#define CONSTANTE_EN_CM 58
#define CONSTANTE_EN_PLG 148



bool HcSr04Init(gpio_t echo, gpio_t trigger){  //inicializo los pines

	pin_del_trigger = trigger;
	pin_del_echo = echo;

	GPIOInit(pin_del_echo, GPIO_INPUT);
	GPIOInit(pin_del_trigger, GPIO_OUTPUT);

	GPIOOff(pin_del_trigger);

	return true;
}


int16_t HcSr04ReadDistanceCentimeters(void){

	int16_t contador_para_cm=0;

	int16_t distancia_en_cm;

	GPIOOn(pin_del_trigger);
	DelayUs(10);
	GPIOOff(pin_del_trigger);

	while(GPIORead(pin_del_echo)==false){

	}

	while(GPIORead(pin_del_echo)==true){
		DelayUs (1);
		contador_para_cm ++;
	}

	distancia_en_cm=contador_para_cm/CONSTANTE_EN_CM;

	return distancia_en_cm;

}


int16_t HcSr04ReadDistanceInches(void){

	int16_t contador_para_plg=0;

	int16_t distancia_en_plg;

	while(GPIORead(pin_del_echo)==false){

	}

	while(GPIORead(pin_del_echo)==true){
		DelayUs (1);
		contador_para_plg ++;
	}

	distancia_en_plg=contador_para_plg/CONSTANTE_EN_PLG;

	return distancia_en_plg;

}


bool HcSr04Deinit(gpio_t echo, gpio_t trigger){

	GPIODeinit();
	return true;

}




/*==================[end of file]============================================*/

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
#include "hc_sr4.h"
#include "gpio.h"
#include "uart.h"
#include "systemclock.h"
#include "timer.h"
/*==================[macros and definitions]=================================*/
uint16_t distancia_de_aire;
uint16_t volumen;
void do_timer(){
	distancia_de_aire=HcSr04ReadDistanceCentimeters();
	volumen=(15-distancia_de_aire)*3.14*4*4;
	UartSendString(SERIAL_PORT_PC, UartItoa(volumen, 10));
	UartSendString(SERIAL_PORT_PC, " cm3 \r\n");

}

/*==================[internal data definition]===============================*/


/*==================[internal functions declaration]=========================*/


/*==================[external data definition]===============================*/
timer_config my_timer = {TIMER_A,160,&do_timer};

/*==================[external functions definition]==========================*/

int main(void){
	HcSr04Init(CH1, CH2);
	SystemClockInit();
	TimerInit(&my_timer);
	TimerStart(TIMER_A);
	serial_config mi_serial_config;
	mi_serial_config.port=SERIAL_PORT_PC;
	mi_serial_config.baud_rate = 115200;
	mi_serial_config.pSerial = NULL;
	UartInit(&mi_serial_config.port);
    while(1){

	}
    
	return 0;
}

/*==================[end of file]============================================*/


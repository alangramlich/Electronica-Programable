/*! @mainpage parcial
 *
 * \section genDesc General Description
 *
 * Esta aplicacion maneja un explorador robotico. Solo sabe girar la cabeza y medir distancias.
 *
 * \section hardConn Hardware Connection
 *
 * | hc_sr4	|   EDU-CIAA	|
 * |:--------------:|:------------------|
 * | 	Trigger	 	| 	GPIO_T_FIL2		|
 * | 	Echo	 	| 	GPIO_T_FIL3		|
 *
 *
 * @section changelog Changelog
 *
 * |   Date	    | Description                                    |
 * |:----------:|:-----------------------------------------------|
 * | 1/11/2021  | Document creation		                         |
 * |			|							                     |
 *
 * @author Alan Gramlich Klein
 *
 */

/*==================[inclusions]=============================================*/
#include "../inc/parcial.h"       /* <= own header */
#include "systemclock.h"
#include "timer.h"
#include "switch.h"
#include "hc_sr4.h"
#include "led.h"
#include "goniometro.h"
#include "gpio.h"
#include "uart.h"
#include "DisplayITS_E0803.h"
#include "timer.h"
/*==================[macros and definitions]=================================*/


/*==================[internal data definition]===============================*/
uint8_t movimiento=1; //1=derecha 2=izquierda
uint8_t vector_distancias[6];
uint8_t pausa=2;
uint8_t dato;
/*==================[internal functions declaration]=========================*/
void pausar (void){
	UartReadByte(SERIAL_PORT_PC, &dato);
	if(dato=='p'){
		if (pausa==1)
			pausa=2;
		else
			pausa=1;
	}
}
void comunicar_obstaculo(void){
	//REVISO CUAL ES LA POSICION
	uint8_t posicion_obstaculo=0;
	uint8_t distancia=vector_distancias[0];
	uint8_t contador=1;
	for (contador=1; i<6; i++)
		if (vector_distancias[i]<distancia){
			distancia=vector_distancias[i];
			posicion_obstaculo=i;
		}
	//LA COMUNICO
	UartSendString(SERIAL_PORT_PC, "Obstaculo en: ");
	UartSendString(SERIAL_PORT_PC, UartItoa(15*posicion_obstaculo, 10)); //MULTIPLICO POR 15 PARA OBTENER LOS GRADOS
	UartSendString(SERIAL_PORT_PC, "º. \r\n");
}

void mover_y_comunicar(){
	if(pausa==0){ //PAUSA ACCIONADA POR LETRA 'P' PARA CUMPLIR CON EL ENUNCIADO DE INTERRUPCION
		LedOff(LED_RGB_B);
		LedOff(LED_RGB_R);
		if (movimiento = 1){
			LedOn(LED_RGB_R); //SIMULO QUE ME MUEVO A LA DERECHA.
		}
		if (movimiento = 2){
			LedOn(LED_RGB_B); //SIMULO QUE ME MUEVO A LA IZQUIERDA.
		}
		//AHORA VOY A COMUNICAR
		UartSendString(SERIAL_PORT_PC, UartItoa(GonRead(), 10));
		UartSendString(SERIAL_PORT_PC, "º objeto a ");
		UartSendString(SERIAL_PORT_PC, UartItoa(HcSr04ReadDistanceCentimeters(), 10));
		UartSendString(SERIAL_PORT_PC, "cm. \r\n");
		//AHORA GUARDO EN EL VECTOR DE DISTANCIAS
		switch(GonRead()){
		case (0):
					vector_distancias[0]=HcSr04ReadDistanceCentimeters();
				break;
		case (15):
					vector_distancias[1]=HcSr04ReadDistanceCentimeters();
				break;
		case (30):
					vector_distancias[2]=HcSr04ReadDistanceCentimeters();
				break;
		case (45):
					vector_distancias[3]=HcSr04ReadDistanceCentimeters();
				break;
		case (60):
					vector_distancias[4]=HcSr04ReadDistanceCentimeters();
				break;
		case (75):
					vector_distancias[5]=HcSr04ReadDistanceCentimeters();
				break;
		}
		//AHORA CHEQUEO SI ESTA EN UNA POSICION TERMINAL.
		if (GonRead()==0){
			movimiento=1; //SE ESTABA MOVIENDO HACIA LA IZQUIERDA Y LO CAMBIO.
			comunicar_obstaculo(); //COMUNICO EN QUE ANGULO TENGO EL OBJETO MAS CERCANO.
		}
		if (GonRead()==75){
			movimiento=2; //SE ESTABA MOVIENDO HACIA LA DERECHA Y LO CAMBIO.
			comunicar_obstaculo(); //COMUNICO EN QUE ANGULO TENGO EL OBJETO MAS CERCANO.
		}
	}
}
/*==================[external data definition]===============================*/
analog_input_config my_analog = {CH1,AINPUTS_SINGLE_READ,NULL};
timer_config my_timer = {TIMER_A,50,&mover_y_comunicar}; //CADA 50 MILISEGUNDOS SE MUEVE Y COMUNICA
/*==================[external functions definition]==========================*/

int main(void){
	SystemClockInit();
	LedsInit();
	GonInit();
	HcSr04Init(GPIO_T_FIL3, GPIO_T_FIL2);

	serial_config mi_serial_config;
	mi_serial_config.port=SERIAL_PORT_PC;
	mi_serial_config.baud_rate = 115200;
	mi_serial_config.pSerial = pausar;
	UartInit(&mi_serial_config.port);


	TimerInit(&my_timer);
	TimerStart(TIMER_A);
    while(1){

	}
    
	return 0;
}

/*==================[end of file]============================================*/


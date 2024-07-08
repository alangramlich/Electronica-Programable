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
#include "../inc/prueba_graficador_con_potenciometro.h"       /* <= own header */
#include "analog_io.h"
#include "uart.h"
#include "iir.h"
#include "lowpass.h"
#include "highpass.h"
#include "timer.h"
#include "systemclock.h"
/*==================[macros and definitions]=================================*/
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define abs(a) (((a) < (0)) ? (-a) : (a))
#define wL_HP 5
#define wL_LP 5

double w_HP[wL_HP];   	// vector de estados internos del filtro pasa altos
double w_LP[wL_LP];   	// vector de estados internos del filtro pasa bajos

double dato_filtrado;
uint8_t vector_de_datos[1000]; //NO ES ENCESARIO
uint8_t contador=0;
uint16_t dato_leido;

//---------------------------------------------------------------------------------
//FILTRO DE LUCIA
#define FC 3
#define dt 0.002
#define PI 3.14
#define VC 475

bool bandera_para_ADC = false;

uint16_t entrada_valor_analogico=0;//donde se guarda valor analógico de la señal que se esta leyendo

int16_t entrada_rectificada=0;

uint16_t entrada_rectificada_al_cuadrado=0;

uint16_t salida_filtrada=0;

uint16_t salida_filtrada_anterior=0;

float alfa=0;

float RC=0;

/*==================[internal data definition]===============================*/




/*==================[internal functions declaration]=========================*/


void Rectificacion(){

	entrada_rectificada = entrada_valor_analogico - VC;
	entrada_rectificada_al_cuadrado = entrada_rectificada * entrada_rectificada;
}

void CalculoParametroAlfa(){

	RC = 1/(2*PI*FC);
	alfa = dt / (RC + dt);
}

void FiltroPasaBajos(){

salida_filtrada = salida_filtrada_anterior + alfa * (entrada_rectificada_al_cuadrado - salida_filtrada_anterior);
salida_filtrada_anterior = salida_filtrada;

}



void respuesta_del_timer(){
	AnalogStartConvertion();
}


void leer_dato(void){
	AnalogInputRead(CH1, &dato_leido);
	UartSendString(SERIAL_PORT_PC, UartItoa(dato_leido, 10));
	UartSendString(SERIAL_PORT_PC, ",");
	//AHORA PARA BT
	/*UartSendString(SERIAL_PORT_P2_CONNECTOR, "*H");
	UartSendString(SERIAL_PORT_P2_CONNECTOR, UartItoa(dato_leido, 10));
	UartSendString(SERIAL_PORT_P2_CONNECTOR, "*");*/

	UartSendString(SERIAL_PORT_PC, UartItoa(dato_filtrado, 10));
	UartSendString(SERIAL_PORT_PC, "\r\n");

}

/*==================[external data definition]===============================*/
analog_input_config my_analog = {CH1,AINPUTS_SINGLE_READ,&leer_dato};
//PRIMERO LE PASO EL CANAL QUE LEE, DESPUES EL MODO, Y LA FUNCION QUE LLAMA CUANDO SE GATILLA LA INTERRUPCION

timer_config my_timer = {TIMER_A,5,&respuesta_del_timer};

/*==================[external functions definition]==========================*/

int main(void){

	AnalogInputInit(&my_analog);
	serial_config mi_serial_config;
	mi_serial_config.port=SERIAL_PORT_PC;
	mi_serial_config.baud_rate = 115200;
	mi_serial_config.pSerial = NULL;
	UartInit(&mi_serial_config.port);

	serial_config mi_serial_config_bt;
	mi_serial_config_bt.port=SERIAL_PORT_P2_CONNECTOR;
	mi_serial_config_bt.baud_rate = 115200;
	mi_serial_config_bt.pSerial = NULL;
	UartInit(&mi_serial_config_bt.port);

	CalculoParametroAlfa();

	TimerInit(&my_timer);
	TimerStart(TIMER_A);

    while(1){

	}
    
	return 0;
}

/*==================[end of file]============================================*/


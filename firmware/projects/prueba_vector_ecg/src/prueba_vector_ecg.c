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
#include "../inc/prueba_vector_ecg.h"
#include "systemclock.h"
#include "bool.h"
#include "timer.h"
#include "uart.h"
#include "analog_io.h"
#include "switch.h"



/*==================[macros and definitions]=================================*/
#define FC 10
#define dt 0.002
#define PI 3.14
#define VC 475

bool bandera_para_ADC = false;

uint16_t entrada_valor_analogico=0;//donde se guarda valor analógico de la señal que se esta leyendo

int16_t entrada_rectificada=0;

uint16_t entrada_rectificada_al_cuadrado=0;

uint16_t salida_filtrada=0;

uint16_t salida_filtrada_anterior=0;

int16_t derivada=100;

uint16_t tiempo_refractario=0;

uint16_t umbral=1200;

uint16_t deteccion_umbral_actual=0;

uint16_t deteccion_umbral_anterior=0;

uint16_t frecuencia_cardiaca=0;

uint32_t contador=0;




float alfa=0;

float RC=0;

/*==================[internal data definition]===============================*/


/*==================[internal functions declaration]=========================*/


/*==================[external data definition]===============================*/


/*==================[external functions definition]==========================*/

//Dispara la conversión analog - digital con timer
void FuncionComienzoADC() {

	AnalogStartConvertion();
}

//lee la entrada analógica
void FuncionAnalog() {

	AnalogInputRead(CH1, &entrada_valor_analogico);
	bandera_para_ADC = true;
}

//Filtro pasa bajos

void FrecuenciaCardiaca(){
	frecuencia_cardiaca=deteccion_umbral_actual-deteccion_umbral_anterior;
	frecuencia_cardiaca=(frecuencia_cardiaca*dt);
	frecuencia_cardiaca=(1/frecuencia_cardiaca);
}

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
derivada=fabs(salida_filtrada - salida_filtrada_anterior);
salida_filtrada_anterior = salida_filtrada;

}


int main(void){

	SystemClockInit();

    //elijo timer A porque tiene el tiempo en 1 ms, y un 2 para que sea 2ms, entonces 1/2ms me da 500Hz=fm

	timer_config my_timer = {TIMER_A, 2, FuncionComienzoADC};
	TimerInit(&my_timer);
	TimerStart(TIMER_A);

	analog_input_config my_analog = {CH1, AINPUTS_SINGLE_READ, FuncionAnalog};
	AnalogInputInit(&my_analog);
	AnalogOutputInit();

	//inicializo la uart e indico puerto
    serial_config my_uart = {SERIAL_PORT_PC,115200,NULL};
    UartInit(&my_uart);

    //Calculo parametros para el filtro
    CalculoParametroAlfa();

    //entr al bucle y si paso por funcionanalog entra lo del puerto
	while(1){

	if(bandera_para_ADC == true){

	Rectificacion();
	FiltroPasaBajos();

	UartSendString(SERIAL_PORT_PC, UartItoa(derivada/1,10));
	UartSendString(SERIAL_PORT_PC, ",");

	UartSendString(SERIAL_PORT_PC, UartItoa(umbral,10));
	/*UartSendString(SERIAL_PORT_PC, ",");

	UartSendString(SERIAL_PORT_PC, UartItoa(salida_filtrada/50,10));*/



    contador++;

    if(tiempo_refractario>=100){
    if(derivada > umbral){
    	deteccion_umbral_anterior=deteccion_umbral_actual;
    	deteccion_umbral_actual=contador;
    	tiempo_refractario=0;
    	FrecuenciaCardiaca();
    	UartSendString(SERIAL_PORT_PC, ",");
    	UartSendString(SERIAL_PORT_PC, UartItoa(frecuencia_cardiaca,10));


    }
    tiempo_refractario++;


    bandera_para_ADC=false; }
    UartSendString(SERIAL_PORT_PC, "\r\n");
	}

	}

	return 0;
}

/*==================[end of file]============================================*/

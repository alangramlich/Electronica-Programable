/*! @mainpage proyecto_ecg
 *
 * \section genDesc General Description
 *
 * Esta aplicacion provee un calculo de frecuencia cardiaca comunicado por UART.
 *
 * \section hardConn Hardware Connection
 *
 * | Placa biopotenciales	|   EDU-CIAA	|
 * |:--------------:|:--------------|
 * | 	PIN1	 	| 	GND		|
 * | 	PIN2	 	| 	5V		|
 * | 	PIN3	 	| 	OUT		|
 *
 *
 *
 * @author Alan Gramlich
 *
 */

/*==================[inclusions]=============================================*/
#include "../inc/proyecto_ecg.h"
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

int32_t derivada=100;

uint16_t tiempo_refractario=0;

uint64_t umbral=800000;

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
/** @fn  void FuncionComienzoADC()
 * @brief Dispara la conversion analogico-digital.
 * @param[in] Sin parámetros.
 * @return .
 */
void FuncionComienzoADC() {

	AnalogStartConvertion();
}

/** @fn  void FuncionAnalog()
 * @brief Lee la entrada digital.
 * @param[in] Sin parámetros.
 * @return .
 */
void FuncionAnalog() {

	AnalogInputRead(CH1, &entrada_valor_analogico);
	bandera_para_ADC = true;
}

//Filtro pasa bajos
/** @fn  void FrecuenciaCardiaca()
 * @brief Realiza el calculo de frecuencia cardiaca.
 * @param[in] Sin parámetros.
 * @return .
 */

void FrecuenciaCardiaca(){
	frecuencia_cardiaca=60000/(contador*2);
}

/** @fn  void Rectificacion()
 * @brief Realiza la rectificacion de la senial.
 * @param[in] Sin parámetros.
 * @return .
 */
void Rectificacion(){

	entrada_rectificada = entrada_valor_analogico - VC;
	entrada_rectificada_al_cuadrado = entrada_rectificada * entrada_rectificada;
}

/** @fn  void CalculoParametroAlfa()
 * @brief Calcula el parametro alfa, se utiliza para filtro.
 * @param[in] Sin parámetros.
 * @return .
 */

void CalculoParametroAlfa(){

	RC = 1/(2*PI*FC);
	alfa = dt / (RC + dt);
}

/** @fn  void FiltroPasaBajos()
 * @brief Aplica el filtro pasabajos a la senial entrante, tambien calcula la derivada.
 * @param[in] Sin parámetros.
 * @return .
 */
void FiltroPasaBajos(){

salida_filtrada = salida_filtrada_anterior + alfa * (entrada_rectificada_al_cuadrado - salida_filtrada_anterior);
derivada=fabs(salida_filtrada - salida_filtrada_anterior)/dt;
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

	UartSendString(SERIAL_PORT_PC, UartItoa(derivada,10));
	UartSendString(SERIAL_PORT_PC, ",");


	UartSendString(SERIAL_PORT_PC, UartItoa(frecuencia_cardiaca,10));
	UartSendString(SERIAL_PORT_PC, ",");


	UartSendString(SERIAL_PORT_PC, UartItoa(umbral,10));
	UartSendString(SERIAL_PORT_PC, "\r\n");


    contador++;
    tiempo_refractario++;

    if(tiempo_refractario>=100){
    if(derivada > umbral){
    	deteccion_umbral_actual=contador;
    	tiempo_refractario=0;
    	FrecuenciaCardiaca();
    	contador=0;



    }}



    bandera_para_ADC=false;

	}

	}

	return 0;
}

/*==================[end of file]============================================*/

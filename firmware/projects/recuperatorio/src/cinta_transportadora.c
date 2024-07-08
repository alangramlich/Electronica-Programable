/*! @mainpage cinta_transportadora
 *
 * \section genDesc General Description
 *
 * Esta aplicacion simula una cinta transportadora que llena cajas hasta un peso determinado.
 *
 * \section hardConn Hardware Connection
 *
 * |  Balanza	|   EDU-CIAA	|
 * |:--------------:|:--------------|
 * | 	PIN1	 	| 	GND		|
 * | 	PIN2	 	| 	3.3V		|
 * | 	OUT	 	| 	CH1		|
 * |:--------------:|:--------------|
 * | 	TCRT5000	 	| 	EDU-CIAA		|
 * | 	OUT	 	| 	GPIO_T_COL0		|
 *
 *
 * @section changelog Changelog
 *
 * |   Date	    | Description                                    |
 * |:----------:|:-----------------------------------------------|
 * | 01/01/2020 | Document creation		                         |
 * |			|							                     |
 *
 * @author Alan Gramlich
 *
 */

/*==================[inclusions]=============================================*/
#include "../inc/cinta_transportadora.h"       /* <= own header */
#include "systemclock.h"
#include "timer.h"
#include "balanza.h"
#include "switch.h"
#include "Tcrt5000.h"
#include "led.h"
#include "gpio.h"
#include "uart.h"
/*==================[macros and definitions]=================================*/


/*==================[internal data definition]===============================*/
uint8_t deteccion_de_caja=0;
uint8_t ya_cargue_esta_caja=0;
uint8_t contador_de_cajas=0;
uint8_t tiempo_de_llenado[8];
uint8_t milisegundos=0;
uint8_t tiempo_de_llenado_maximo=0;
uint8_t tiempo_de_llenado_minimo=0;
uint8_t contador_while=0;
uint8_t iniciar=0;
uint8_t detener=0;
/*==================[internal functions declaration]=========================*/
void f_tecla_1 (void){
	iniciar=1;
}
void f_tecla_2 (void){
	detener=1;
}
void ResumenDeLote(){
	contador_while=0;
	tiempo_de_llenado_maximo=tiempo_de_llenado[0];
	tiempo_de_llenado_maximo=tiempo_de_llenado[0];
	while(contador_while<8){
		if (tiempo_de_llenado[contador_while]>tiempo_de_llenado_maximo)
			tiempo_de_llenado_maximo=tiempo_de_llenado[contador_while];
		if (tiempo_de_llenado[contador_while]<tiempo_de_llenado_minimo)
			tiempo_de_llenado_minimo=tiempo_de_llenado[contador_while];
		contador_while++;
	}
	UartSendString(SERIAL_PORT_PC, "Tiempo de llenado maximo: ");
	UartSendString(SERIAL_PORT_PC, UartItoa(tiempo_de_llenado_maximo, 10));
	UartSendString(SERIAL_PORT_PC, "seg. \r\n");
	UartSendString(SERIAL_PORT_PC, "Tiempo de llenado minimo: ");
	UartSendString(SERIAL_PORT_PC, UartItoa(tiempo_de_llenado_minimo, 10));
	UartSendString(SERIAL_PORT_PC, "seg. \r\n");
}
void respuesta_del_timer(){
	milisegundos++;
}
int LeerBalanza(void){
	uint8_t retorno;
	float lectura=BalanzaRead(); //0 si pesa 0kg, 3.3 si pesa 150kg. 20kg=0,44 V
	if (lectura<0.44)
		retorno = 1;
	if (lectura>=0.44)
		retorno = 0;
	return retorno;

}
void CargarCaja(void){ //apago led 1 prendo led 2
	LedOff(LED_1);
	LedOn(LED_2);
	TimerStart(TIMER_A); //inicio el timer para que cuente milisegundos
	while(LeerBalanza()){ //no hago nada hasta que se llene la caja. Con la caja llena, salgo del ciclo.

	}
	TimerStop(TIMER_A); //detengo el timer para que deje de contar
	tiempo_de_llenado[contador_de_cajas]=milisegundos/1000; //Esto me devuelve el numero ENTERO de segundos. Pierdo los decimales.
	milisegundos=0;
	UartSendString(SERIAL_PORT_PC, "Tiempo de llenado de caja ");             //Se debe tener en cuenta que pierde mucha presicion.
	UartSendString(SERIAL_PORT_PC, UartItoa(contador_de_cajas+1, 10));
	UartSendString(SERIAL_PORT_PC, "  ");
	UartSendString(SERIAL_PORT_PC, UartItoa(tiempo_de_llenado[contador_de_cajas], 10));
	UartSendString(SERIAL_PORT_PC, "seg. \r\n");
	contador_de_cajas++;
	LedOff(LED_2);
	LedOn(LED_1); //se termina de llenar la caja, vuelve a avanzar la cinta
}
/*==================[external data definition]===============================*/

timer_config my_timer = {TIMER_A,1,&respuesta_del_timer};
/*==================[external functions definition]==========================*/

int main(void){
	TimerInit(&my_timer);
	BalanzaInit();
	Tcrt5000Init(GPIO_T_COL0);
	SystemClockInit();
	LedsInit();
	SwitchesInit();
	SwitchActivInt(SWITCH_1, f_tecla_1);
	SwitchActivInt(SWITCH_2, f_tecla_2);
	serial_config mi_serial_config;
	mi_serial_config.port=SERIAL_PORT_PC;
	mi_serial_config.baud_rate = 115200;
	mi_serial_config.pSerial = NULL;
	UartInit(&mi_serial_config.port);
	while (iniciar==0){ //Este while mantiene todo parado hasta que se inicia.
		                //IMPORTANTE: No es una pausa.
	}
	LedOn(LED_1); //Arranco la cinta. Se supone que empieza sin caja en la posicion de llenado.
    while(detener=0){  //Importante. Comentado mas abajo.
    	deteccion_de_caja=Tcrt5000State(); //en cada ciclo leo el estado del infrarrojo.
    	if(deteccion_de_caja==1){
    		if (ya_cargue_esta_caja==0){
    			CargarCaja();               //cargo la caja
    			ya_cargue_esta_caja=1;      //la marco como cargada porque el infrarrojo me sigue devolviendo 1.
    		}
    	}
    	if (ya_cargue_esta_caja!=deteccion_de_caja){ //Si la caja que cargue ya paso,
    	ya_cargue_esta_caja=0;	                     //reinicio las banderas para, al detectar la siguiente caja, poder cargarla.
    	}                                            //Este if se activa cuando el TCRT comienza a devolver 0, y previamente se cargo una caja..
    if (contador_de_cajas==15){ //Si se completo un lote, comunico los tiempos de llenado
    	ResumenDeLote();        //de cada caja y reinicio para el lote siguiente.
    }
	}     //DETENER: Cuando se presione la tecla 2, se saldra del ciclo while y la cinta se detendra.
          //IMPORTANTE: No es una pausa, sino que se apaga el sistema llegando a la linea de retorno.
    
	return 0;
}

/*==================[end of file]============================================*/


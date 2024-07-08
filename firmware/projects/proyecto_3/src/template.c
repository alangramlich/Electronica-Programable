
 /** @brief Bare Metal header for leds on EDU-CIAA NXP
 **
 ** This is a driver for six leds mounted on the board
 **
 **/


/*==================[inclusions]=============================================*/
#include "template.h"       /* <= own header */
#include "systemclock.h"
#include "timer.h"
#include "switch.h"
#include "Tcrt5000.h"
#include "led.h"
#include "gpio.h"
#include "uart.h"
#include "DisplayITS_E0803.h"
#include "timer.h"
/*==================[macros and definitions]=================================*/


/*==================[internal data definition]===============================*/
	uint8_t activar_detener_conteo = 0;
	uint8_t contador=0;
	uint8_t mantener_contador = 0;
	uint8_t dato;
/*==================[internal functions declaration]=========================*/
void do_uart(void){
	UartReadByte(SERIAL_PORT_PC, &dato);
	switch (dato){
	case ('o'):
			f_activar_detener_conteo();
			break;
	case ('h'):
			f_mantener_contador();
			break;
	case ('0'):
			f_resetear_contador();
			break;
	}
}
/** @fn  void f_activar_detener_conteo()
 * @brief Interrupción para cuando se presione switch.
 * @param[in] Sin parámetros.
 * @return .
 */
void f_activar_detener_conteo(void)
{
	activar_detener_conteo = !activar_detener_conteo;
}
/** @fn  void f_mantener_contador()
 * @brief Interrupción para cuando se presione switch.
 * @param[in] Sin parámetros.
 * @return .
 */
void f_mantener_contador(void)
{
	mantener_contador = !mantener_contador;
}
/** @fn  void f_resetear_contador()
 * @brief Interrupción para cuando se presione switch.
 * @param[in] Sin parámetros.
 * @return .
 */
void f_resetear_contador(void)
{
	contador = 0;
}
/** @fn  void f_actualizar_contador()
 * @brief Funicon que actualiza el contador segun el numeor de lineas contadas.
 * @param[in] Sin parámetros.
 * @return .
 */
void f_actualizar_contador(void)
{
	if (mantener_contador == 0){
	    	switch (contador){
	    	case (0):
					LedOff(LED_RGB_B);
	    			LedOff(LED_1);
					LedOff(LED_2);
					LedOff(LED_3);
					ITSE0803DisplayValue(contador);
					UartSendString(SERIAL_PORT_PC, UartItoa(contador, 10));
					UartSendString(SERIAL_PORT_PC, " - lineas \r\n");
	    			break;
	    	case (1):
					LedOff(LED_RGB_B);
	    			LedOff(LED_1);
	    			LedOff(LED_2);
	    			LedOff(LED_3);
	    			LedOn(LED_3);
	    		    ITSE0803DisplayValue(contador);
	    		    UartSendString(SERIAL_PORT_PC, UartItoa(contador, 10));
	    		    UartSendString(SERIAL_PORT_PC, " - lineas \r\n");
	    			break;
	    	case (2):
					LedOff(LED_RGB_B);
	    			LedOff(LED_1);
					LedOff(LED_2);
					LedOff(LED_3);
					LedOn(LED_2);
				    ITSE0803DisplayValue(contador);
				    UartSendString(SERIAL_PORT_PC, UartItoa(contador, 10));
				    UartSendString(SERIAL_PORT_PC, " - lineas \r\n");
	    			break;
	    	case (3):
					LedOff(LED_RGB_B);
	    			LedOff(LED_1);
					LedOff(LED_2);
					LedOff(LED_3);
					LedOn(LED_3);
					LedOn(LED_2);
					ITSE0803DisplayValue(contador);
					UartSendString(SERIAL_PORT_PC, UartItoa(contador, 10));
					UartSendString(SERIAL_PORT_PC, " - lineas \r\n");
	    			break;
	    	case (4):
					LedOff(LED_RGB_B);
	    			LedOff(LED_1);
					LedOff(LED_2);
					LedOff(LED_3);
					LedOn(LED_1);
					ITSE0803DisplayValue(contador);
					UartSendString(SERIAL_PORT_PC, UartItoa(contador, 10));
					UartSendString(SERIAL_PORT_PC, " - lineas \r\n");
	    			break;
	    	case (5):
					LedOff(LED_RGB_B);
	    			LedOff(LED_1);
					LedOff(LED_2);
					LedOff(LED_3);
					LedOn(LED_1);
					LedOn(LED_3);
					ITSE0803DisplayValue(contador);
					UartSendString(SERIAL_PORT_PC, UartItoa(contador, 10));
					UartSendString(SERIAL_PORT_PC, " - lineas \r\n");
	    			break;
	    	case (6):
					LedOff(LED_RGB_B);
	    			LedOff(LED_1);
					LedOff(LED_2);
					LedOff(LED_3);
					LedOn(LED_2);
					LedOn(LED_1);
					ITSE0803DisplayValue(contador);
					UartSendString(SERIAL_PORT_PC, UartItoa(contador, 10));
					UartSendString(SERIAL_PORT_PC, " - lineas \r\n");
	    			break;
	    	case (7):
					LedOff(LED_RGB_B);
	    			LedOff(LED_1);
					LedOff(LED_2);
					LedOff(LED_3);
					LedOn(LED_1);
					LedOn(LED_2);
					LedOn(LED_3);
					ITSE0803DisplayValue(contador);
					UartSendString(SERIAL_PORT_PC, UartItoa(contador, 10));
					UartSendString(SERIAL_PORT_PC, " - lineas \r\n");
	    			break;
	    	case (8):
					LedOff(LED_RGB_B);
	    			LedOff(LED_1);
					LedOff(LED_2);
					LedOff(LED_3);
					LedOn(LED_RGB_B);
					ITSE0803DisplayValue(contador);
					UartSendString(SERIAL_PORT_PC, UartItoa(contador, 10));
					UartSendString(SERIAL_PORT_PC, " - lineas \r\n");
	    			break;
	    	case (9):
					LedOff(LED_RGB_B);
	    			LedOff(LED_1);
					LedOff(LED_2);
					LedOff(LED_3);
					LedOn(LED_RGB_B);
					LedOn(LED_3);
					ITSE0803DisplayValue(contador);
					UartSendString(SERIAL_PORT_PC, UartItoa(contador, 10));
					UartSendString(SERIAL_PORT_PC, " - lineas \r\n");
	    			break;
	    	case (10):
					LedOff(LED_RGB_B);
	    			LedOff(LED_1);
					LedOff(LED_2);
					LedOff(LED_3);
					LedOn(LED_RGB_B);
					LedOn(LED_2);
					ITSE0803DisplayValue(contador);
					UartSendString(SERIAL_PORT_PC, UartItoa(contador, 10));
					UartSendString(SERIAL_PORT_PC, " - lineas \r\n");
	    			break;
	    	case (11):
					LedOff(LED_RGB_B);
	    			LedOff(LED_1);
					LedOff(LED_2);
					LedOff(LED_3);
					LedOn(LED_RGB_B);
					LedOn(LED_3);
					LedOn(LED_2);
					ITSE0803DisplayValue(contador);
					UartSendString(SERIAL_PORT_PC, UartItoa(contador, 10));
					UartSendString(SERIAL_PORT_PC, " - lineas \r\n");
	    			break;
	    	case (12):
					LedOff(LED_RGB_B);
	    			LedOff(LED_1);
					LedOff(LED_2);
					LedOff(LED_3);
					LedOn(LED_RGB_B);
					LedOn(LED_1);
					ITSE0803DisplayValue(contador);
					UartSendString(SERIAL_PORT_PC, UartItoa(contador, 10));
					UartSendString(SERIAL_PORT_PC, " - lineas \r\n");
	    			break;
	    	case (13):
					LedOff(LED_RGB_B);
	    			LedOff(LED_1);
					LedOff(LED_2);
					LedOff(LED_3);
					LedOn(LED_RGB_B);
					LedOn(LED_1);
					LedOn(LED_3);
					ITSE0803DisplayValue(contador);
					UartSendString(SERIAL_PORT_PC, UartItoa(contador, 10));
					UartSendString(SERIAL_PORT_PC, " - lineas \r\n");
	    			break;
	    	case (14):
					LedOff(LED_RGB_B);
	    			LedOff(LED_1);
					LedOff(LED_2);
					LedOff(LED_3);
					LedOn(LED_RGB_B);
					LedOn(LED_1);
					LedOn(LED_2);
					ITSE0803DisplayValue(contador);
					UartSendString(SERIAL_PORT_PC, UartItoa(contador, 10));
					UartSendString(SERIAL_PORT_PC, " - lineas \r\n");
	    			break;
	    	case (15):
					LedOff(LED_RGB_B);
	    			LedOff(LED_1);
					LedOff(LED_2);
					LedOff(LED_3);
					LedOn(LED_RGB_B);
					LedOn(LED_1);
					LedOn(LED_2);
					LedOn(LED_3);
					ITSE0803DisplayValue(contador);
					UartSendString(SERIAL_PORT_PC, UartItoa(contador, 10));
					UartSendString(SERIAL_PORT_PC, " - lineas \r\n");
	    			break;
	    	}}
}
/*==================[external data definition]===============================*/

timer_config my_timer = {TIMER_A,1000,&f_actualizar_contador};

/*==================[external functions definition]==========================*/

int main(void){
	gpio_t dout;
	uint8_t teclas, tecla_1, tecla_2, tecla_3;
	uint8_t estado_anterior, estado_actual;
	uint8_t primer_flanco = 0;
	uint8_t ya_lei_en_este_ciclo = 0;
	gpio_t pines[7]={GPIO_LCD_1, GPIO_LCD_2, GPIO_LCD_3, GPIO_LCD_4, GPIO_1, GPIO_3, GPIO_5};
	SwitchesInit();
	SystemClockInit();
	LedsInit();
	Tcrt5000Init(GPIO_T_COL0);
	ITSE0803Init(pines);
	estado_anterior = Tcrt5000State();
	SwitchActivInt(SWITCH_1, f_activar_detener_conteo);
	SwitchActivInt(SWITCH_2, f_mantener_contador);
	SwitchActivInt(SWITCH_3, f_resetear_contador);
	TimerInit(&my_timer);
	TimerStart(TIMER_A);
	serial_config mi_serial_config;
	mi_serial_config.port=SERIAL_PORT_PC;
	mi_serial_config.baud_rate = 115200;
	mi_serial_config.pSerial = do_uart;
	UartInit(&mi_serial_config.port);

    while(1){

    	if(activar_detener_conteo){
    		estado_actual = Tcrt5000State();
    		if (primer_flanco == 1){
    			if (estado_actual != estado_anterior){
    				estado_anterior = estado_actual;
    				primer_flanco = 0;
    				contador++;
    			}
    		}
    		else {
    			if(estado_actual != estado_anterior){
    				estado_anterior = estado_actual;
    				primer_flanco=1;
    			}
    		}
    	}
	}
    
	return 0;
}

/*==================[end of file]============================================*/


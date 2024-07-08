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
#include "systemclock.h"
#include "timer.h"
#include "Tcrt5000.h"
#include "led.h"
#include "gpio.h"
#include "DisplayITS_E0803.h"
/*==================[macros and definitions]=================================*/


/*==================[internal data definition]===============================*/


/*==================[internal functions declaration]=========================*/
void Delay()
{
	uint32_t i;
		for(i=3000000; i!=0; i--)
		{
			   asm  ("nop");
		}
	}
/*==================[external data definition]===============================*/


/*==================[external functions definition]==========================*/

int main(void){
	gpio_t dout;
	uint8_t contador=0;
	uint8_t mantener_contador = 0;
	uint8_t teclas, tecla_1, tecla_2, tecla_3;
	uint8_t estado_anterior, estado_actual;
	uint8_t primer_flanco = 0;
	uint8_t activar_detener_conteo = 0;
	uint8_t ya_lei_en_este_ciclo = 0;
	gpio_t pines[7]={GPIO_LCD_1, GPIO_LCD_2, GPIO_LCD_3, GPIO_LCD_4, GPIO_1, GPIO_3, GPIO_5};
	SwitchesInit();
	SystemClockInit();
	LedsInit();
	Tcrt5000Init(GPIO_T_COL0);
	ITSE0803Init(pines);
	estado_anterior = Tcrt5000State();
    while(1){
    	//LEVANTO BANDERAS
    	teclas  = SwitchesRead();
    	teclas&=0x0F;
    	tecla_1 = SwitchesRead();
    	tecla_1&=0x01;
    	switch (teclas){
    	case (1):
    	    	if (tecla_1 == 1){ //SI TECLA 1 ESTA ACTIVA
    	    		activar_detener_conteo = !activar_detener_conteo;
    	    		ya_lei_en_este_ciclo = 1;
    	    		while(ya_lei_en_este_ciclo){ //PARA ESPERAR QUE SUELTE LA TECLA
    	    			tecla_1 = SwitchesRead();
    	    			tecla_1 &= 0x01;
    	    			if(tecla_1 == 0)
    	    				ya_lei_en_este_ciclo = 0;
    	    		}
    	    	}
    	break;

    	case (2):
    			mantener_contador = !mantener_contador;
    			ya_lei_en_este_ciclo = 1;
    	    	    	while(ya_lei_en_este_ciclo){ //PARA ESPERAR QUE SUELTE LA TECLA
    	    	    	tecla_2 = SwitchesRead();
    	    	   		tecla_2 &= 0x02;
    	     			if(tecla_2 == 0)
    	     				ya_lei_en_este_ciclo = 0;
    	    	 }
    	    	break;
    	case (4):
    			contador=0;
    			ya_lei_en_este_ciclo = 1;
    			while(ya_lei_en_este_ciclo){ //PARA ESPERAR QUE SUELTE LA TECLA
        	    	tecla_3 = SwitchesRead();
   	    	   		tecla_3 &= 0x04;
         			if(tecla_3 == 0)
    	   				ya_lei_en_este_ciclo = 0;
    	    	   	 }
       	    	break;


    	}

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
    	if (mantener_contador == 0){
    	switch (contador){
    	case (0):
				LedOff(LED_RGB_B);
    			LedOff(LED_1);
				LedOff(LED_2);
				LedOff(LED_3);
				ITSE0803DisplayValue(contador);
    			break;
    	case (1):
				LedOff(LED_RGB_B);
    			LedOff(LED_1);
    			LedOff(LED_2);
    			LedOff(LED_3);
    			LedOn(LED_3);
    		    ITSE0803DisplayValue(contador);
    			break;
    	case (2):
				LedOff(LED_RGB_B);
    			LedOff(LED_1);
				LedOff(LED_2);
				LedOff(LED_3);
				LedOn(LED_2);
			    ITSE0803DisplayValue(contador);
    			break;
    	case (3):
				LedOff(LED_RGB_B);
    			LedOff(LED_1);
				LedOff(LED_2);
				LedOff(LED_3);
				LedOn(LED_3);
				LedOn(LED_2);
				ITSE0803DisplayValue(contador);
    			break;
    	case (4):
				LedOff(LED_RGB_B);
    			LedOff(LED_1);
				LedOff(LED_2);
				LedOff(LED_3);
				LedOn(LED_1);
				ITSE0803DisplayValue(contador);
    			break;
    	case (5):
				LedOff(LED_RGB_B);
    			LedOff(LED_1);
				LedOff(LED_2);
				LedOff(LED_3);
				LedOn(LED_1);
				LedOn(LED_3);
				ITSE0803DisplayValue(contador);
    			break;
    	case (6):
				LedOff(LED_RGB_B);
    			LedOff(LED_1);
				LedOff(LED_2);
				LedOff(LED_3);
				LedOn(LED_2);
				LedOn(LED_1);
				ITSE0803DisplayValue(contador);
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
    			break;
    	case (8):
				LedOff(LED_RGB_B);
    			LedOff(LED_1);
				LedOff(LED_2);
				LedOff(LED_3);
				LedOn(LED_RGB_B);
				ITSE0803DisplayValue(contador);
    			break;
    	case (9):
				LedOff(LED_RGB_B);
    			LedOff(LED_1);
				LedOff(LED_2);
				LedOff(LED_3);
				LedOn(LED_RGB_B);
				LedOn(LED_3);
				ITSE0803DisplayValue(contador);
    			break;
    	case (10):
				LedOff(LED_RGB_B);
    			LedOff(LED_1);
				LedOff(LED_2);
				LedOff(LED_3);
				LedOn(LED_RGB_B);
				LedOn(LED_2);
				ITSE0803DisplayValue(contador);
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
    			break;
    	case (12):
				LedOff(LED_RGB_B);
    			LedOff(LED_1);
				LedOff(LED_2);
				LedOff(LED_3);
				LedOn(LED_RGB_B);
				LedOn(LED_1);
				ITSE0803DisplayValue(contador);
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
    			break;
    	}}
	}
    
	return 0;
}

/*==================[end of file]============================================*/


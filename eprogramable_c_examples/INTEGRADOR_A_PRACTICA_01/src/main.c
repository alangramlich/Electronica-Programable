/*
 * Cátedra: Electrónica Programable
 * FIUNER - 2021
 * Autor/es: Alan Gramlich Klein
 * 
 *
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/*==================[inclusions]=============================================*/
#include "main.h"
#include "stdio.h"
#include <stdint.h>
#include <unistd.h>
/*==================[macros and definitions]=================================*/
struct leds
{
	uint8_t n_led;        //indica el número de led a controlar
	uint8_t n_ciclos;     //indica la cantidad de ciclos de encendido/apagado
	uint64_t periodo;      //indica el tiempo de cada ciclo
	uint8_t mode;         //ON, OFF, TOGGLE
} my_leds;
uint8_t ON=1, TOGGLE=2, OFF=3;

/*==================[internal functions declaration]=========================*/
	void controlador_leds(struct leds *led_controlado){
		printf("Primer prueba \n");
		uint8_t i, j;
		if (led_controlado->mode==ON){
				printf("Se enciende el led %d \n", led_controlado->n_led);
	}
		if (led_controlado->mode==OFF){
				printf("Se apaga el led %d \n", led_controlado->n_led);
		}
		if (led_controlado->mode==TOGGLE){
			//HAGO UN FOR PARA LOS CICLOS
			for(i=0; i<led_controlado->n_ciclos; i++){
				printf("Toggle led %d \n", led_controlado->n_led);
				//sleep(led_controlado->periodo); ESTO NO SE USA!!!
				uint64_t esperando;
				for (esperando=0; esperando<led_controlado->periodo; esperando++){
					esperando++;
					esperando--;
				}
				printf("*estoy esperando*\n");
			}
		}
		printf("Ya termine, no esperes mas. \n");
	}
int main(void)
{
	my_leds.mode=TOGGLE;
	my_leds.n_led=3;
	my_leds.n_ciclos=3;
	my_leds.periodo=99999999;
	controlador_leds(&my_leds);
	return 0;
}

/*==================[end of file]============================================*/


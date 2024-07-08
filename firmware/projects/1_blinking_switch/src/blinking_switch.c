/*
 * Cátedra: Electrónica Programable
 * FIUNER - 2018
 * Autor/es:
 * JMReta - jmreta@ingenieria.uner.edu.ar
 *
 *
 *
 * Revisión:
 * 07-02-18: Versión inicial
 * 01-04-19: V1.1 SM
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
#include "blinking_switch.h"       /* <= own header */

#include "systemclock.h"
#include "led.h"
#include "switch.h"

/*==================[macros and definitions]=================================*/
#define COUNT_DELAY 3000000
/*==================[internal data definition]===============================*/

void Delay()
{
	uint32_t i;
	for(i=COUNT_DELAY; i!=0; i--)
	{
		   asm  ("nop");
	}
	}


/*==================[internal functions declaration]=========================*/

/*==================[external data definition]===============================*/

/*==================[external functions definition]==========================*/

int main(void)
{
	uint8_t teclas, retardo;
	SystemClockInit();
	LedsInit();
	SwitchesInit();
//LedOn(LED_3);
while(1)
{
teclas  = SwitchesRead();
teclas&=0x0E;
retardo = SwitchesRead();
retardo&=0x01;
switch(teclas)
{
case (14):
		LedOn(LED_1);
		LedOn(LED_2);
		LedOn(LED_3);
		Delay(retardo);
		LedOff(LED_1);
		LedOff(LED_2);
		LedOff(LED_3);
		Delay(retardo);
		break;
case (6):
		LedOn(LED_1);
		LedOn(LED_2);
		Delay(retardo);
		LedOff(LED_1);
		LedOff(LED_2);
		Delay(retardo);
		break;
case (8):
		LedOn(LED_3);
		Delay(retardo);
		LedOff(LED_3);
		Delay(retardo);
		break;
case (10):
		LedOn(LED_1);
		LedOn(LED_3);
		Delay(retardo);
		LedOff(LED_1);
		LedOff(LED_3);
		Delay(retardo);
		break;
case (12):
		LedOn(LED_2);
		LedOn(LED_3);
		Delay(retardo);
		LedOff(LED_2);
		LedOff(LED_3);
		Delay(retardo);
		break;
case SWITCH_2:
		LedOn(LED_1);
		Delay(retardo);
		LedOff(LED_1);
		Delay(retardo);
		break;
case SWITCH_3:
		LedOn(LED_2);
		Delay(retardo);
		LedOff(LED_2);
		Delay(retardo);
		break;
    	}
	}

    
}

/*==================[end of file]============================================*/


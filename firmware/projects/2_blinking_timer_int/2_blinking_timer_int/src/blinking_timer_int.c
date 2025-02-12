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
#include "blinking_timer_int.h"       /* <= own header */

#include "systemclock.h"
#include "led.h"
#include "timer.h"
/*==================[macros and definitions]=================================*/
#define ON 1
#define OFF 0
/*==================[internal data definition]===============================*/

/*==================[internal functions declaration]=========================*/
void do_blink(void);
/*==================[external data definition]===============================*/
uint8_t blinking = ON;
timer_config my_timer = {TIMER_A,1000,&do_blink};

/*==================[external functions definition]==========================*/

void do_blink(void)
{
	if(blinking == ON)
	{
		LedToggle(LED_1);
		LedToggle(LED_3);
	}
}

void SisInit(void)
{
	SystemClockInit();
	LedsInit();
	SwitchesInit();
	TimerInit(&my_timer);
	TimerStart(TIMER_A);
}

int main(void)
{
	SisInit();
    while(1)
    {
    	/*Nada*/
    }
}

/*==================[end of file]============================================*/


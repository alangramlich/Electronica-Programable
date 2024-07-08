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
/*==================[macros and definitions]=================================*/

typedef struct
{
	uint8_t port;				//!< GPIO port number
	uint8_t pin;				//!< GPIO pin number
	uint8_t dir;				//!< GPIO direction ‘0’ IN;  ‘1’ OUT
} gpioConf_t;


/*==================[internal functions declaration]=========================*/

void BCD_75 (uint8_t numero, gpioConf_t vector[4])
{
	int i;
	uint8_t variable;
	for (i=0; i<4; i++)
	{
		variable=numero & (0x01);
		printf("Puerto %d", vector[i].port);
		printf(".%d", vector[i].pin);
		printf(": %d \r \n", variable);
		numero=numero>>1;		//voy viendo de a 1 bit para pasarlo al sumador
	}
}
int main(void)
{
	gpioConf_t vector_de_bits[4];
	vector_de_bits[0].port=1;
	vector_de_bits[1].port=1;
	vector_de_bits[2].port=1;
	vector_de_bits[3].port=2;

	vector_de_bits[0].pin=4;
	vector_de_bits[1].pin=5;
	vector_de_bits[2].pin=6;
	vector_de_bits[3].pin=14;

	vector_de_bits[0].dir=1;
	vector_de_bits[1].dir=1;
	vector_de_bits[2].dir=1;
	vector_de_bits[3].dir=1;

	uint8_t numero_para_mapear;
	numero_para_mapear=5;
	BCD_75 (numero_para_mapear, vector_de_bits);
	return 0;
}

/*==================[end of file]============================================*/


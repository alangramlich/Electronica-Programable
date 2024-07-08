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

union variable_union{
	uint32_t variable_entera;
	uint8_t variable_chiquita[4];
} unionb;
/*==================[internal functions declaration]=========================*/

int main(void)
{
	//PARTE A
	printf("Esta es la parte A \n");
	uint32_t variable_completa=0x01020304;
	uint8_t variable01, variable02, variable03, variable04;

	printf("La variable completa es: %d \n", variable_completa);

	variable01=variable_completa;
	variable_completa=variable_completa>>8;
	printf("La variable01 es: %d \n", variable01);

	variable02=variable_completa;
	variable_completa=variable_completa>>8;
	printf("La variable02 es: %d \n", variable02);

	variable03=variable_completa;
	variable_completa=variable_completa>>8;
	printf("La variable03 es: %d \n", variable03);

	variable04=variable_completa;
	printf("La variable04 es: %d \n", variable04);

	unionb;
	unionb.variable_entera=0x01020304;
	printf("Variable del punto B: %d \n", unionb.variable_entera);
	printf("Variable01: %d \n", unionb.variable_chiquita[0]);
	printf("Variable02: %d \n", unionb.variable_chiquita[1]);
	printf("Variable01: %d \n", unionb.variable_chiquita[2]);
	printf("Variable02: %d \n", unionb.variable_chiquita[3]);
	return 0;
}

/*==================[end of file]============================================*/


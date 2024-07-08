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
#include <math.h>
/*==================[macros and definitions]=================================*/

int8_t  BinaryToBcd (uint32_t data, uint8_t digits, uint8_t * bcd_number )
{
	uint8_t i;
	for (i=0; i<digits; i++){
		bcd_number[i]=data%((uint32_t)10);
		data=data/10;

	}
	return 0;
}


/*==================[internal functions declaration]=========================*/

int main(void)
{
	uint32_t dato_de_32_bits=1004;
	uint8_t i, numero_de_digitos;
	numero_de_digitos=4;
	uint8_t arreglo_de_digitos[numero_de_digitos];
	BinaryToBcd (dato_de_32_bits, numero_de_digitos, arreglo_de_digitos);
	for (i=0; i<numero_de_digitos; i++)
		printf("%d ", arreglo_de_digitos[numero_de_digitos-1-i]);


	return 0;
}

/*==================[end of file]============================================*/


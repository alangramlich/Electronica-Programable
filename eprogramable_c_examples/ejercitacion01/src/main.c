/*
 * Cátedra: Electrónica Programable
 * FIUNER - 2018
 * Autor/es:
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

const uint32_t ejercicio_uno=(1<<6);
const uint32_t ejercicio_dos=(3<<3);
const uint16_t ejercicio_dos_V2=(1<<3)|(1<<4);
const uint16_t ejercicio_tres=0xffff&~(1<<14);
const uint16_t ejercicio_tres_V2=~(1<<14);
/*==================[internal functions declaration]=========================*/

int main(void)
{
	printf("prueba \n");
	printf("el numero es : %d \n", ejercicio_uno);
	printf("el numero es : %d \n", ejercicio_dos);
	printf("el numero es : %d \n", ejercicio_dos_V2);
	printf("el numero es : %d \n", ejercicio_tres);
	printf("el numero es : %d \n", ejercicio_tres_V2);

	return 0;
}

/*==================[end of file]============================================*/


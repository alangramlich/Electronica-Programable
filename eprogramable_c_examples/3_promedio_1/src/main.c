/*
 * Cátedra: Electrónica Programable
 * FIUNER - 2018
 * Autor/es:
  * JMReta - jmreta@ingenieria.uner.edu.ar
 * Eduardo Filomena
 * Gonzalo Cuenca
 * Juan Ignacio Cerrudo
 * Albano Peñalva
 * Sebastián Mateos
 *
 *
 *
 * Revisión:
 * 26-02-18: Versión inicial
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


/*==================[macros and definitions]=================================*/

#define CANTIDAD 16
/* #define CON_DESPLAZAMIENTO */

/*==================[internal functions declaration]=========================*/
#include <stdio.h>
#include <stdint.h>


const uint8_t conjunto_numeros[]={234, 123, 111, 101, 32, 116, 211, 24, 214, 100, 124, 222, 1, 129, 9,116};

int main(void)
{
	uint16_t suma_acumulada=0;
	uint8_t indice,promedio=0;
	/*sumo todos los números y los acumulo en una variable*/
	for(indice=0; indice<CANTIDAD; indice++)
	{
		suma_acumulada+=conjunto_numeros[indice];
		printf("N°%d : %d\n",indice+1,conjunto_numeros[indice]);
	}
#ifndef CON_DESPLAZAMIENTO

	/*Divido la suma acumulada por la cantidad de números sumados*/
	promedio=(uint8_t)(suma_acumulada/CANTIDAD);
#else
	/*Divido la suma corriendo 4 lugares a la derecha*/
	promedio=(uint8_t)(suma_acumulada>>4);
#endif
	printf(" Promedio : %d",promedio);
}





/*==================[end of file]============================================*/


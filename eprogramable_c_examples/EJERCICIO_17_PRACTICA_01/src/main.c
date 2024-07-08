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


/*==================[internal functions declaration]=========================*/

int main(void)
{
	uint8_t datos[3][5];

	datos[0][0]=234;
	datos[0][1]=123;
	datos[0][2]=111;
	datos[0][3]=101;
	datos[0][4]=32;

	datos[1][0]=116;
	datos[1][1]=211;
	datos[1][2]=24;
	datos[1][3]=214;
	datos[1][4]=100;

	datos[2][0]=124;
	datos[2][1]=222;
	datos[2][2]=1;
	datos[2][3]=129;
	datos[2][4]=9;


	printf("%d, %d, %d, %d, %d \n", datos[0][0], datos[0][1],
					datos[0][2], datos[0][3], datos[0][4]);
	printf("%d, %d, %d, %d, %d \n", datos[1][0], datos[1][1],
					datos[1][2], datos[1][3], datos[1][4]);
	printf("%d, %d, %d, %d, %d \n", datos[2][0], datos[2][1],
					datos[2][2], datos[2][3], datos[2][4]);

	uint16_t sumatoria=0;
	uint8_t fila=0, columna=0;


	//DE LAS DOS FORMAS (FOR Y WHILE) FUNCIONA


	for( fila=0; fila<3; fila++)
		for ( columna=0; columna<5; columna++)
			sumatoria+=datos[fila][columna];

	/*while(fila<3){
		sumatoria+=datos[fila][columna];
		columna++;
		if(columna==5){
			columna=0;
			fila++;
		}
	}*/



	printf("La sumatoria es: %d \n", sumatoria);
	uint8_t promedio=sumatoria/15;
	printf("El promedio es: %d \n", promedio);
	return 0;
}

/*==================[end of file]============================================*/


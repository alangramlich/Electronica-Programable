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
#include <string.h>
/*==================[macros and definitions]=================================*/
struct alumno {
	char nombre[20];
	char apellido [20];
	uint32_t edad;
} usted, *su_compannero, memoria_para_mi_compannero;

/*==================[internal functions declaration]=========================*/

int main(void)
{
	printf("Ingrese su nombre: ");
	strcpy(usted.nombre, "Alan");
	strcpy(usted.apellido, "Gramlich Klein");
	usted.edad=23;
	//scanf(%c, &usted.nombre);
	printf("\n Su nombre es: %s \n", usted.nombre);
	printf("\n Su apellido es: %s \n", usted.apellido);
	printf("\n Su edad es: %d \n", usted.edad);

	su_compannero=&memoria_para_mi_compannero;
	strcpy(su_compannero->nombre, "Lucia Valentina");
	strcpy(su_compannero->apellido, "Eletti");
	su_compannero->edad=23;
	printf("\n El nombre de su compannero es: %s \n", su_compannero->nombre);
	printf("\n El apellido de su compannero es: %s \n", su_compannero->apellido);
	printf("\n La edad de su compannero es: %d \n", su_compannero->edad);

	return 0;
}

/*==================[end of file]============================================*/


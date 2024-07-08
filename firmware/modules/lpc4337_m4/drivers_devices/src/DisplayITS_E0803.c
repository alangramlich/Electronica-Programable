/* Copyright 2016,
 * Leandro D. Medus
 * lmedus@bioingenieria.edu.ar
 * Eduardo Filomena
 * efilomena@bioingenieria.edu.ar
 * Juan Manuel Reta
 * jmrera@bioingenieria.edu.ar
 * Sebastian Mateos
 * smateos@ingenieria.uner.edu.ar
 * Facultad de Ingeniería
 * Universidad Nacional de Entre Ríos
 * Argentina
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

/** \brief Bare Metal driver for leds in the EDU-CIAA board.
 **
 **/

/*
 * Initials     Name
 * ---------------------------
 *	LM			Leandro Medus
 * EF		Eduardo Filomena
 * JMR		Juan Manuel Reta
 * SM		Sebastian Mateos
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * 20160422 v0.1 initials initial version Leando Medus
 * 20160807 v0.2 modifications and improvements made by Eduardo Filomena
 * 20160808 v0.3 modifications and improvements made by Juan Manuel Reta
 * 20180210 v0.4 modifications and improvements made by Sebastian Mateos
 * 20190820 v1.1 new version made by Sebastian Mateos
 */

/*==================[inclusions]=============================================*/

#include "DisplayITS_E0803.h"
#include "gpio.h"
#include "delay.h"
#include "chip.h"


/*==================[macros and definitions]=================================*/
#define CANTIDAD_GPIO 7
#define CANTIDAD_BYTE 4
#define CANTIDAD_DIGITOS 3
/*==================[internal data declaration]==============================*/
//NADA
/*==================[internal functions declaration]=========================*/
//funciones internas que no quiero que nadie vea

int8_t  BinaryToBcd (uint32_t data, uint8_t digits, uint8_t * bcd_number);
void Digito_A_Bit(uint8_t bcd);
/*==================[internal data definition]===============================*/
gpio_t pines[7];
//Variable en la que se guarda el valor ingresado
uint16_t valor_numerico=0;
/*==================[external data definition]===============================*/
//funciones que se van a mostrar junto al driver


/*==================[internal functions definition]==========================*/
int8_t  BinaryToBcd (uint32_t data, uint8_t digits, uint8_t * bcd_number){
	uint8_t i;

		for (i=0; i<digits; i++){
			bcd_number[i] = data%10;
			data = data/10;
		}
		//for (i=digits; i>0; i--){
			//printf("Numero en BCD= %d\n",bcd_number[i]);
		}

void Digito_A_Bit(uint8_t bcd){
	uint8_t i,aux; //se va  a guardar en pines[0..4], la configuracion si esta en alto o en bajo
	for(i=0;i<CANTIDAD_BYTE;i++){
			aux=bcd&1;
			if(aux==0){
				GPIOOff(pines[i]);
			}
			else{
				GPIOOn(pines[i]);}
			bcd=(bcd>>1);
	}
}
/*==================[external functions definition]==========================*/
bool ITSE0803Init(gpio_t * pins){
		uint8_t i;
			for(i=0; i<CANTIDAD_GPIO;i++){
				pines[i]=pins[i];
				GPIOInit(pins[i],GPIO_OUTPUT);
	}
	return true;
}

bool ITSE0803DisplayValue(uint16_t valor){
	valor_numerico=valor; //guardo valor para usarlo en readvalue
		uint8_t datos[3];
		BinaryToBcd(valor,CANTIDAD_DIGITOS,datos); //de Binario a BCD me devuelve un vector
		//si el numero es 123, me devuelve [3,2,1]
		uint8_t i;
		for(i=0; i<CANTIDAD_DIGITOS;i++){
			Digito_A_Bit(datos[i]); //Toma el BCD y separa en cada uno de sus bits, me guarda configuracion de D1 a D4
			GPIOOn(pines[6-i]); // si i es 0 esta en SEL3, si i es 1 SEL2, si i es 2 SEL1
			GPIOOff(pines[6-i]);
		}
		return true;
}

uint16_t ITSE0803ReadValue(void){
	return valor_numerico;
}

bool ITSE0803Deinit(gpio_t * pins){
	void GPIODeinit();
	return true;
}


/*==================[end of file]============================================*/

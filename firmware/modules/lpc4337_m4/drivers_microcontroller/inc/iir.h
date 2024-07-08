/*
 * can.h
 *
 *  Created on: Dec 9, 2017
 *      Author: quack
 */

#ifndef CAN_H_
#define CAN_H_
/*
	Ejmplo de uso:
	
	// Macros
	#define max(a, b) (((a) > (b)) ? (a) : (b))
	#define abs(a) (((a) < (0)) ? (-a) : (a))
	#define wL_HP max(NL_HP, DL_HP)
	#define wL_LP max(NL_LP, DL_LP)
	
	// Variables internas
	double w_HP[wL_HP];   	// vector de estados internos del filtro pasa altos
	double w_LP[wL_LP];   	// vector de estados internos del filtro pasa bajos
	
	// Filtro Pasa-Alto
	output = iir(DL_HP - 1, DEN_HP, NL_HP - 1, NUM_HP, w_HP, input);

	// Filtro Pasa-Bajo
	output = iir(DL_LP - 1, DEN_LP, NL_LP - 1, NUM_LP, w_LP, input);
*/

double iir(int M,const double *a,int L,const double *b,double *w,double x);


#endif /* CAN_H_ */

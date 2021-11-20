#ifndef TABLERO_H
#define TABLERO_H
#include "Casillabuscaminas.h"

class tablero {
	public:
		tablero(int );
		bool destaparCasilla(int,int);
		int calcularBombas(int,int);
		void marcarCasilla(int,int);
		void imprimirBombas();
		void imprimirTablero();


		~tablero();
	private:
		int size;
		Casillabuscaminas*** table;
};

#endif
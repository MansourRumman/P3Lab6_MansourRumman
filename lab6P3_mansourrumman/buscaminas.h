#ifndef BUSCAMINAS_H
#define BUSCAMINAS_H
#include "tablero.h"

class buscaminas
{
	public:
		buscaminas(int);
		void jugar();
		~buscaminas();
	private:
		tablero* tableroBombas;
};

#endif
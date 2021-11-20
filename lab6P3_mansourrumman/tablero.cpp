#include "tablero.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <cstddef>
#include <iostream>
using namespace std;
tablero::tablero(int dificultad) {
	srand (time(NULL));
	switch(dificultad) {
		case 1: {
			this->size=8;
			this->table=new Casillabuscaminas**[8];
			for(int x=0; x<8; x++) {
				table[x]=new Casillabuscaminas*[8];
			}
			for(int i = 0; i<8 ; i++) {
				for(int j=0; j<8; j++) {
					table[i][j]=new Casillabuscaminas();
				}
				int	bomba=0;
				while(bomba<=12) {
					int fila= rand()%8;
					int columna= rand()%8;
					if(!table[fila][columna]->getBomba()) {
						table[fila][columna]->setBomba(true);
						bomba+=1;
					}
				}
			}
			break;
		}
		case 2: {
			this->size=10;
			this->table=new Casillabuscaminas**[10];
			for(int x=0; x<10; x++) {
				table[x]=new Casillabuscaminas*[10];
			}
			for(int i = 0; i<10 ; i++) {
				for(int j=0; j<10; j++) {
					table[i][j]=new Casillabuscaminas();
				}

			}
			int	bomba=0;
			while(bomba<=25) {
				int fila= rand()%10;
				int columna= rand()%10;
				if(!table[fila][columna]->getBomba()) {
					table[fila][columna]->setBomba(true);
					bomba+=1;
				}
			}

			break;
		}
		case 3: {
			this->size=12;
			this->table=new Casillabuscaminas**[12];
			for(int x=0; x<12; x++) {
				table[x]=new Casillabuscaminas*[12];
			}
			for(int i = 0; i<12 ; i++) {
				for(int j=0; j<12; j++) {
					table[i][j]=new Casillabuscaminas();
				}

			}
			int	bomba=0;
			while(bomba<=43) {
				int fila= rand()%12;
				int columna= rand()%12;
				if(!table[fila][columna]->getBomba()) {
					table[fila][columna]->setBomba(true);
					bomba+=1;
				}
			}

			break;
		}
	}
}
bool tablero::destaparCasilla(int fila, int columna) {
	if(this->table[fila][columna]->getBomba()) {
		return true;
	} else {
		this->table[fila][columna]->setDescubierta(true);
		for(int i=-1; i<=1; i++) {
			for(int j=-1; j<=1; j++) {
				if(i!=j) {
					if(!table[fila+i][columna+j]->getDescubierta()&&!table[fila+i][columna+j]->getMarcada()) {
						if(calcularBombas(fila+i,columna+j)==0) {
							char m=' ';
							destaparCasilla(fila+i,columna+j);
						} else {
							table[fila+i][columna+j]->setDisplay(calcularBombas(fila+i,columna+j)+48);
						}
					}
				}
			}
		}
	}
}
void tablero::marcarCasilla(int fila, int columna) {
	if(this->table[fila][columna]->getMarcada()) {
		this->table[fila][columna]->setMarcada(true);
		this->table[fila][columna]->setDisplay('X');
	}
}

int tablero::calcularBombas(int fila, int columna) {
	int numero=0;
	for(int i=-1; i<1; i++) {
		for(int j=-1; j<1; j++) {
			if(j!=0&&i!=0) {
				if(table[fila+i][columna+j]->getBomba()) {
					numero+=1;
				}
			}
		}
	}
	return numero;
}
void tablero::imprimirBombas() {
	for(int i=0; i<this->size; i++) {
		for(int j=0; j<this->size; j++) {
			if(this->table[i][j] ->getBomba()) {
				cout<<"# ";
			} else {
				cout<<"- ";
			}
		}
		cout<<endl;
	}

}
void tablero::imprimirTablero() {
	for(int i=0; i<this->size; i++) {
		for(int j=0; j<this->size; j++) {
			if(this->table[i][j]->getBomba()) {
				cout<<this->table[i][j]->getDisplay()<<" ";
			}
			cout<<endl;
		}
	}
}


tablero::~tablero() {
	for(int i = 0; i<this->size ; i++) {
		delete[] table[i];
	}
	delete[] table;
	table=NULL;
}
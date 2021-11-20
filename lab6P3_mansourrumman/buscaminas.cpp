#include "buscaminas.h"
#include "tablero.h"
#include <iostream>
using namespace std;

buscaminas::buscaminas(int dificultad) {
	this->tableroBombas=new tablero(dificultad);

}
void buscaminas::jugar() {
	int ufila=0,ucolumna=0;
	bool muerto=false;
	char marc=' ';
	char dest=' ';
	while(muerto) {
		tableroBombas->imprimirTablero();
		tableroBombas->imprimirBombas();
		cout<<"quiere marcar un cuadro si =s /no =n: ";
		cin>>marc;
		if(marc=='s') {
			cout<<"ingrese # fila: "<<endl;
			cin>>ufila;
			cout<<"ingrese # columna: "<<endl;
			cin>>ucolumna;
			tableroBombas->marcarCasilla(ufila,ucolumna);
		}
		cout<<"quiere destapar un cuadro si =s /no =n: ";
		cin>>dest;
		if(dest=='s') {
			cout<<"ingrese # fila: "<<endl;
			cin>>ufila;
			cout<<"ingrese # columna: "<<endl;
			cin>>ucolumna;
			tableroBombas->destaparCasilla(ufila,ucolumna);
			muerto=tableroBombas->destaparCasilla(ufila, ucolumna);
		}
	}


}

buscaminas::~buscaminas() {


}
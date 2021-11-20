#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>  
#include "buscaminas.h" 
using namespace std;
int menu();
int main(int argc, char** argv) {
	srand (time(NULL));
	int opcionMenu=0;
	while(opcionMenu!=4) {
		opcionMenu=menu();
		if(opcionMenu!=4) {
			buscaminas* juego=new buscaminas(opcionMenu);
		}
	}
	return 0;
}
int menu() {
	int opcion=0;
	cout<<"Menu"<<endl
	    <<"1)Facil"<<endl
	    <<"2)Normal"<<endl
	    <<"3)Dificil"<<endl
	    <<"4)salir"<<endl
	    <<"ingrese su dificultad:";

	cin>>opcion;

	return opcion;
}
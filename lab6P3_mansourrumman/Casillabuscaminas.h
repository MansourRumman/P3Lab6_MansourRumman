#ifndef CASILLABUSCAMINAS_H
#define CASILLABUSCAMINAS_H

class Casillabuscaminas {
	public:
		Casillabuscaminas();
		 void setBomba(bool);
		 bool getBomba();
		 void setDescubierta(bool);
		 bool getDescubierta();
		 bool getDisplay();
		 void setDisplay(char);
		 bool getMarcada();
		 void setMarcada(bool);
		 

	private:
		bool esBomba;
		bool descubierta;
		char display;
		bool marcada;

};

#endif
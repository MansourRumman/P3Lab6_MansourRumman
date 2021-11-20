#include "Casillabuscaminas.h"

Casillabuscaminas::Casillabuscaminas() {
		this-> esBomba=false;
		this-> descubierta=false;
		this-> display='-';
		this-> marcada=false;
	
}
bool Casillabuscaminas::getBomba(){
	return this->esBomba;
}
void Casillabuscaminas::setBomba(bool bomba){
	this->esBomba=bomba;
}
void Casillabuscaminas::setDescubierta(bool des){
	this->descubierta=des;
}
bool Casillabuscaminas::getDescubierta(){
	return descubierta;
}
bool Casillabuscaminas::getDisplay(){
	
}
void Casillabuscaminas::setDisplay(char m){
	this->display=m;
}
bool Casillabuscaminas::getMarcada(){
	return marcada;
}
void Casillabuscaminas::setMarcada(bool ma){
	this->marcada==ma;
}
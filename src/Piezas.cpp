#include "Piezas.h"


Vector Piezas::getPos() {
	return posicion; //vector objeto que representa la posicion de la pieza
}


Piezas::Tipo Piezas::getTipo() {
	if (nullptr) // evalua como falsa y no entra al if luego directamente retorna tip
		return NT;
	else return tip;
}

Piezas ::Color Piezas :: getColor(){
	if (nullptr)// no entra al if devuelve col
		return NC;
	else return col;
}

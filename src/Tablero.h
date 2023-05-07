#pragma once
#include <ETSIDI.h>
using ETSIDI::Sprite;
#include <Casilla.h>
#include <Piezas.h> 
#include <ColorCasilla.h>
#include <Peon.h>
#include <Vector.h>
#include <NoPieza.h>

class Tablero
{
	const int NCasillas = 8; // Creamos una constante del numero de casillas 
	Casilla** casilla; // Puntero doble de tipo casilla para recorrer las casillas
	Casilla c;
	Piezas* lista[64]; // Puntero de tipo Piezas para poder imprimirlas
	int NPiezas;
public: 
	Tablero(); // Constructor por defecto de tablero
	void DibujaTablero(ColorCasilla color1,ColorCasilla color2);
	void DibujaPiezas();
	void mueve(); 
	void inicializa();
	bool agregar(Piezas* p);
	void MueveCursor(unsigned char key);
	void Juega(Piezas::COLOR col);
	void Selecciona(Piezas::COLOR col);
};

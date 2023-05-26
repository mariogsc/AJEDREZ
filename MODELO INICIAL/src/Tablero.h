#pragma once
#include <ETSIDI.h>
using ETSIDI::Sprite;
#include <Casilla.h>
#include <Piezas.h> 
#include <ColorCasilla.h>
#include <NoPieza.h>
#include <Vector.h>
//cada pieza
#include <Peon.h>
#include <Alfil.h>
#include <Torre.h>
#include <Caballo.h>
#include <Rey.h>



class Tablero
{

	const int NCasillas = 8; // Creamos una constante del numero de casillas 
	Casilla** casilla; // Puntero doble de tipo casilla para recorrer las casillas
	Casilla c;
	int NPiezas;
	Piezas* lista[64]; // Puntero de tipo Piezas para poder imprimirlas
	int turno;
	int n;
	int aux;
	bool comer=false;
	Vector PosibleJaque[8];
	bool Jaque;
	bool comienzo;
public:
	Tablero(); // Constructor por defecto de tablero
	void DibujaTablero(ColorCasilla color1, ColorCasilla color2);
	void DibujaPiezas();
	void inicializa();
	bool agregar(Piezas* p);
	void MueveCursor(unsigned char key);
	void Mueve(int n);
	int Selecciona();
	void ColocaSelector();
	bool HayPieza(int i);
	bool HayRey(int i);
	int BuscaPieza(Vector posicion);
	int BuscaPieza(Piezas::TIPO t);
	int Comprobaciones(Vector p);
	bool ComprobacionAlfil();
	bool ComprobacionTorre();
	bool ComprobacionReina();
	bool HayRey(Piezas::COLOR);

};

#pragma once
#include <ETSIDI.h>
using ETSIDI::Sprite;
#include <Casilla.h> 
#include <ColorRGB.h>
#include <Vector.h>
#include <Pieza.h>
#include <Torre.h>
#include <Alfil.h>
#include <Caballo.h>
#include <Reina.h>
#include <Peon.h>
#include <Rey.h>
#include<PiezaEspecial.h>


#define MAX_CASILLAS 8
#define MAX_PIEZAS 24

using ETSIDI::Sprite;


class Tablero
{
	Casilla casilla[8][8]; // Puntero doble de tipo casilla para recorrer las casillas
	Pieza* tablero[8][8];
	int NPiezas;

	Casilla* lista[MAX];
	int NLista;
	Sprite* TurnoB = new Sprite("imagenes/TurnoB.png", 4.0, 4.0, 4.0, 4.0);
	Sprite* TurnoN = new Sprite("imagenes/TurnoN.png", 4.0, 4.0, 4.0, 4.0);
public:
	int turno;

	Tablero(); // Constructor por defecto de tablero
	Tablero(const Tablero& otro); //Constructor de copia para realizar movimientos virtuales
	~Tablero();
	void inicializa();

	// FUNCIÓN PARA DIBUJAR EL TABLERO UTILIZANDO UNA MATRIZ DE CASILLAS Y ELEGIR EL COLOR SEGÚN EL EQUIPO SELECCIONADO
	void DibujaTablero(ColorRGB color1, ColorRGB color2);
	void dibujaTurno();

	// FUNCIONES PARA EL MANEJO DEL VECTOR DE PIEZAS (ARQUITECTURA DE POO)
	void EliminarContenido();
	bool agregar(Pieza*, int i, int j);
	void eliminar(int i, int j);
	void eliminar(Pieza* p);

	// FUNCIONES PARA EL MOVIMIENTO Y DIBUJADO DE LAS PIEZAS
	bool mover(Vector origen, Vector destino);
	void DibujaPiezas();

	// FUNCIONES DE INTERFAZ
	int getTurno() { return turno; }
	Pieza* getPieza(int i, int j) {
		if (i < 0 || i >= 8 || j < 0 || j >= 8) { return nullptr; }
		else {
			if (tablero[i][j] != nullptr)
				return tablero[i][j];
			else return nullptr;
		}
	}
	Pieza* getPieza(Vector v) {
		return getPieza(v.x, v.y);

	}

	void CompruebaPosible(Vector origen);
	bool agregar(Casilla* casilla);
	void eliminarContenido();
	void DibujaPosibles();
	void coronacionPeon();//funcion par convertir peon en superpieza

	// MÉTODOS PARA EL JAQUE Y JAQUE MATE
	Vector buscarRey(Pieza::COLOR color);
	bool HayJaqueBlancas();
	bool HayJaqueNegras();
	bool HayJaqueMateBlancas();
	bool HayJaqueMateNegras();


	void operator=(const Tablero& t);

	// CLASES AMIGAS
	friend class Pieza;
	friend class Caballo;
	friend class Peon;
	friend class Rey;
	friend class Reina;
	friend class Torre;
	friend class Alfil;
	friend class SuperPieza;
};
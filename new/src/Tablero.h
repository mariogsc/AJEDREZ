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
#include <Rey.h>
#include <Reina.h>
#include <Peon.h>
#iclude <PiezaEspecial>

#define MAX_CASILLAS 8
#define MAX_PIEZAS 24

using ETSIDI::Sprite; //PRUEBA


class Tablero
{
	Casilla** casilla; // Puntero doble de tipo casilla para recorrer las casillas
	Pieza* tablero[8][8];
	int numero;
	int turno; // SE HACE AQUI O EN MUNDO?
	
	Sprite* TurnoB = new Sprite("imagenes/TurnoB.png", 4.0, 4.0, 4.0, 4.0);
	Sprite* TurnoN = new Sprite("imagenes/TurnoN.png", 4.0, 4.0, 4.0, 4.0);
	
	
public:
	
	Tablero(); // Constructor por defecto de tablero
	~Tablero();
	void inicializa();

	// FUNCIÓN PARA DIBUJAR EL TABLERO UTILIZANDO UNA MATRIZ DE CASILLAS Y ELEGIR EL COLOR SEGÚN EL EQUIPO SELECCIONADO
	void DibujaTablero(ColorRGB color1, ColorRGB color2);
	
	//FUNCION PARA DIBUJAR INTERFAZ TURNOS
	void dibujaTurno();
	
	// FUNCIONES PARA EL MANEJO DEL VECTOR DE PIEZAS (ARQUITECTURA DE POO)
	void EliminarContenido();
	bool agregar(Pieza* ,int i,int j);
	void eliminar(int i,int j);
	void eliminar(Pieza* p);
	void mover(Vector& origen, Vector& destino, Pieza* t[8][8]);
	void DibujaPiezas();
	void MoverPiezas();
	bool Jaque();
	booljaqueMate();
	void Raton(int button, int state, int x, int y);
	
	// FUNCIONES DE INTERFAZ
	int getTurno() { return turno; }

	Pieza* getPieza(int i, int j) {
		if (i < 0 || i >= 8 || j < 0 || j >= 8){return nullptr;} // PORQUE DA ERROR ESTE RETURN 
		else{
			if (tablero[i][j] != nullptr)return tablero[i][j];
		}
	}
};

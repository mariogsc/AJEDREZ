#pragma once
#include <Tablero.h>
#include"freeglut.h"
#include"ETSIDI.h"
#include <cmath>



Tablero::Tablero() :turno(1),numero(0) {
	// Primero reservamos espacio dinamico para una matriz de 8x8 casillas (tablero) 
	
	casilla = new Casilla * [MAX_CASILLAS ];

	for (int i = 0; i < MAX_CASILLAS ; i++) {
		casilla[i] = new Casilla[MAX_CASILLAS];
	}

	// Inicializamos el vector de piezas 
	inicializa();
}

Tablero::~Tablero() {
	for (int i = 0; i < MAX_CASILLAS; i++)
		for (int j = 0; j < MAX_CASILLAS; j++)
			delete tablero[i][j];

}

void Tablero::inicializa() {  // inicializacion de todas las fichas e inclusión en el tablero
	 // Inicializar todas las casillas con un puntero nulo
	for (int i = 0; i < MAX_CASILLAS; i++) {
		for (int j = 0; j < MAX_CASILLAS; j++) {
			tablero[i][j] = nullptr;
		}
	}

	
	// BLANCAS
	tablero[5][0] = new Torre(Pieza::Blanco); // COMO PUEDO HACER PARA AL DEFINIR ESTO EL SPRITE SE ME PONGA EN EL 5,0
	tablero[7][0] = new Torre(Pieza::Blanco);
	
	/*
	// NEGRAS
	tablero[7][0] = new Torre(Color::Negro);
	tablero[7][1] = new Caballo(Color::Negro);
	*/

	//numero = MAX_PIEZAS;
}


// FUNCIÓN PARA DIBUJAR EL TABLERO UTILIZANDO UNA MATRIZ DE CASILLAS Y ELEGIR EL COLOR SEGÚN EL EQUIPO SELECCIONADO

void Tablero::DibujaTablero(ColorRGB color1, ColorRGB color2) {
	float tam = 1.0; //Definimos variables auxiliares para ir desplazando la casilla
	Vector aux; // incializado por defecto a 0,0
	for (int columna = 0; columna < MAX_CASILLAS; columna++) {
		aux.setx(0.0);
		aux.sety(tam * columna);

		for (int fila = 0; fila < MAX_CASILLAS; fila++) {

			if (columna % 2 == 0) {
				if (fila % 2 == 0) casilla[columna][fila].SetColor(color1);
				else casilla[columna][fila].SetColor(color2);
			}
			else {
				if (fila % 2 == 0)casilla[columna][fila].SetColor(color2);
				else casilla[columna][fila].SetColor(color1);
			}


			casilla[columna][fila].SetPos(aux);

			casilla[columna][fila].DibujaCasilla(casilla[columna][fila].GetPos(), {});


			aux.setx(aux.getx() + tam);
		}
	}
	
}

// FUNCIONES PARA EL MANEJO DEL VECTOR DE PIEZAS (ARQUIETECTURA POO)

void Tablero::EliminarContenido() {
	for (int i = 0; i < MAX_CASILLAS; i++)
		for (int j = 0; j < MAX_CASILLAS; j++)
		{
			if (tablero[i][j] != nullptr) {
				delete tablero[i][j];
				tablero[i][j] = nullptr;
			}
		}
}

bool Tablero::agregar(Pieza* p,int _i,int _j)
{
	if (_i < 0 || _i >= MAX_CASILLAS)return false;
	if (_j < 0 || _j >= MAX_CASILLAS)return false;

	if (numero < MAX_PIEZAS){
		tablero[_i][_j] = p;
		numero++;
		return true;
	}
	
}

void Tablero::eliminar(int i,int j) {
	if (i < 0 || i >= MAX_CASILLAS)return;
	if (j < 0 || j >= MAX_CASILLAS)return;

	delete tablero[i][j];
	tablero[i][j] = nullptr; // IMPORTANTE PONER EL PUNTERO A nullptr DESPUES DE ELIMINARLO
	numero--;
}

void Tablero::eliminar(Pieza* p) {
	for (int i = 0; i < MAX_CASILLAS; i++) {
		for(int j=0;j<MAX_CASILLAS;j++){
			if (tablero[i][j] == p) {
				eliminar(i, j);
				return;
			}
		}
	}
}


// FUNCIONES PARA EL CONTROL DEL MOVIMIENTO Y DIBUJADO

void Tablero::mover(Vector& origen, Vector& destino, Pieza* t[8][8]) {
	if (origen.getx() < 0 || origen.gety() < 0 || origen.gety() >= 8 || origen.getx() >= 8) return;
	if (destino.getx() < 0 || destino.gety() < 0 || destino.gety() >= 8 || destino.getx() >= 8) return;

	if (t[destino.getx()][destino.gety()] != nullptr && t[origen.getx()][origen.gety()]->getColor() != t[destino.getx()][destino.gety()]->getColor()) {
		eliminar(t[destino.getx()][destino.gety()]);
		t[origen.getx()][origen.gety()] = nullptr;
	}

	Pieza* temp = t[destino.getx()][destino.gety()];
	t[destino.getx()][destino.gety()] = t[origen.getx()][origen.gety()];
	t[origen.getx()][origen.gety()] = temp;

	

}

void Tablero::DibujaPiezas()
{
	for (int i = 0; i < MAX_CASILLAS; i++)
		for (int j = 0; j < MAX_CASILLAS; j++) {
			if (tablero[i][j] != nullptr) {
				tablero[i][j]->Dibuja();
			}
		}
}


void Tablero::Raton(int button, int state, int x, int y) {
	int fila, columna;
	Vector origen;
	Vector destino;


	if (((x > 22) && (x < 572)) && ((y > 24) && (y < 574))) {
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

			x = x - 22;
			y = y - 24;

			int fila = static_cast<int>(x / 68.75);
			int columna = static_cast<int>(y / 68.75);

				if (turno % 2 != 0) { // Si el turno es impar -> turno blancas
					if (tablero[columna][fila] != nullptr && tablero[columna][fila]->getColor() == Pieza::Blanco) {

						origen.setx(columna);
						origen.sety(fila);
					}
				}
				else if (turno % 2 == 0) { // Si el turno es par -> turno negras
					if (tablero[columna][fila] != nullptr && tablero[columna][fila]->getColor() == Pieza::Negro) {
						origen.setx(columna);
						origen.sety(fila);
					}
				}
		}
		else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {

			// Verificar que la posición de origen sea válida y haya una pieza en esa posición
			if (origen.getx() >= 0 && origen.getx() < MAX_CASILLAS && origen.gety() >= 0 && origen.gety() < MAX_CASILLAS &&
				tablero[origen.getx()][origen.gety()] != nullptr) {
				// Verificar si el movimiento es válido
				destino.setx(columna);
				destino.sety(fila);

				if (tablero[origen.getx()][origen.gety()]->validarMovimiento(origen, destino)) {
					// Realizar el movimiento
					mover(origen, destino, tablero); // COMO PONE X,Y EN VEZ DE DESTINO
					turno++;
				}
			}
		}
	}
}

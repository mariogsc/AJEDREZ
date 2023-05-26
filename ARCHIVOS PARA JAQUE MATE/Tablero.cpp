#pragma once
#include <Tablero.h>
#include"freeglut.h"
#include"ETSIDI.h"
#include <cmath>



Tablero::Tablero() :NPiezas(0),NLista(0), turno(1) {
	inicializa();
	for (int i = 0; i < MAX; i++)lista[i] = nullptr;
	//TurnoB->setSize(1.05, 1.05);
	//TurnoB->setPos(10.3, 9.2);

	//TurnoN->setSize(0.85, 0.85);
	//TurnoN->setPos(11.6, 9.25);

}
void Tablero::dibujaTurno() {
	//if (turno % 2 != 0)TurnoB->draw();
	//else if (turno % 2 == 0) TurnoN->draw();

}
Tablero::Tablero(const Tablero& otro) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (otro.tablero[i][j] != nullptr) 
				tablero[i][j] = otro.tablero[i][j]->clonar();
			else tablero[i][j] = nullptr;
		}
	}
}

void Tablero::operator=(const Tablero& t) {
	
	EliminarContenido();
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (t.tablero[i][j] != nullptr)
				tablero[i][j] = t.tablero[i][j]->clonar();
			else tablero[i][j] = nullptr;
		}
	}
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
	tablero[0][0] = new Torre(Pieza::Blanco);
	tablero[2][0] = new Alfil(Pieza::Blanco);
	tablero[7][0] = new Torre(Pieza::Blanco);
	tablero[5][0] = new Alfil(Pieza::Blanco);
	tablero[1][0] = new Caballo(Pieza::Blanco);
	tablero[6][0] = new Caballo(Pieza::Blanco);
	tablero[3][0] = new Reina(Pieza::Blanco);
	tablero[4][0] = new Rey(Pieza::Blanco);
	tablero[0][1] = new Peon(Pieza::Blanco);
	tablero[1][1] = new Peon(Pieza::Blanco);
	tablero[2][1] = new Peon(Pieza::Blanco);
	tablero[3][1] = new Peon(Pieza::Blanco);
	tablero[4][1] = new Peon(Pieza::Blanco);
	tablero[5][1] = new Peon(Pieza::Blanco);
	tablero[6][1] = new Peon(Pieza::Blanco);
	tablero[7][1] = new Peon(Pieza::Blanco);


	// NEGRAS
	tablero[7][7] = new Torre(Pieza::Negro);
	tablero[2][7] = new Alfil(Pieza::Negro);
	tablero[0][7] = new Torre(Pieza::Negro);
	tablero[1][7] = new Caballo(Pieza::Negro);
	tablero[6][7] = new Caballo(Pieza::Negro);
	tablero[3][7] = new Reina(Pieza::Negro);
	tablero[4][7] = new Rey(Pieza::Negro);
	tablero[0][6] = new Peon(Pieza::Negro);
	tablero[1][6] = new Peon(Pieza::Negro);
	tablero[2][6] = new Peon(Pieza::Negro);
	tablero[3][6] = new Peon(Pieza::Negro);
	tablero[4][6] = new Peon(Pieza::Negro);
	tablero[5][6] = new Peon(Pieza::Negro);
	tablero[6][6] = new Peon(Pieza::Negro);
	tablero[7][6] = new Peon(Pieza::Negro);
	tablero[5][7] = new Alfil(Pieza::Negro);
	
	

	//numero = MAX_PIEZAS;
}


// FUNCIÓN PARA DIBUJAR EL TABLERO UTILIZANDO UNA MATRIZ DE CASILLAS Y ELEGIR EL COLOR SEGÚN EL EQUIPO SELECCIONADO

void Tablero::DibujaTablero(ColorRGB color1, ColorRGB color2) {
	float tam = 1.0; //Definimos variables auxiliares para ir desplazando la casilla
	Vector aux; // incializado por defecto a 0,0
	for (int columna = 0; columna < MAX_CASILLAS; columna++) {
		aux.x=(0.0);
		aux.y=(tam * columna);

		for (int fila = 0; fila < MAX_CASILLAS; fila++) {

			if (columna % 2 == 0) {
				if (fila % 2 == 0) casilla[columna][fila].SetColor(color2);
				else casilla[columna][fila].SetColor(color1);
			}
			else {
				if (fila % 2 == 0)casilla[columna][fila].SetColor(color1);
				else casilla[columna][fila].SetColor(color2);
			}


			casilla[columna][fila].SetPos(aux);

			casilla[columna][fila].DibujaCasilla(casilla[columna][fila].GetPos(), {});


			aux.x=(aux.x + tam);
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

	if (NPiezas < MAX_PIEZAS){
		tablero[_i][_j] = p;
		NPiezas++;
		return true;
	}
	
}

void Tablero::eliminar(int i,int j) {
	if (i < 0 || i >= MAX_CASILLAS)return;
	if (j < 0 || j >= MAX_CASILLAS)return;

	delete tablero[i][j];
	tablero[i][j] = nullptr; // IMPORTANTE PONER EL PUNTERO A nullptr DESPUES DE ELIMINARLO
	NPiezas--;
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

void Tablero::DibujaPiezas()
{
	for (int i = 0; i < MAX_CASILLAS; i++)
		for (int j = 0; j < MAX_CASILLAS; j++) {
			if (tablero[i][j] != nullptr) {
				glPushMatrix();
				glTranslatef(i, j, 0.01);
				tablero[i][j]->Dibuja();
				glPopMatrix();
			}
		}

}

bool Tablero::mover(Vector origen, Vector destino) {
	if (origen.x < 0 || origen.y < 0 || origen.y >= 8 || origen.x >= 8) return false;
	if (destino.x < 0 || destino.y < 0 || destino.y >= 8 || destino.x >= 8) return false;

	if (tablero[origen.x][origen.y] == nullptr) return false;

	Pieza* piezaMovida = tablero[origen.x][origen.y];
	Pieza* piezaCapturada = tablero[destino.x][destino.y];

	Pieza* quieroComer = nullptr; 
	
	tablero[destino.x][destino.y] = tablero[origen.x][origen.y];
	tablero[origen.x][origen.y] = nullptr;  // IMPORTANTE -> poner el puntero a nullptr después de eliminar

	// Verificar si se pone en jaque al propio rey
	if (turno % 2 == 1) {
		if (HayJaqueBlancas()) {
			// Movimiento inválido, pone en jaque al rey blanco
			tablero[origen.x][origen.y] = tablero[destino.x][destino.y];
			tablero[destino.x][destino.y] = piezaCapturada;
			ETSIDI::play("sonidos/error.wav");
			return false;
		}
		else {
			if(quieroComer){
			ETSIDI::play("sonidos/PiezaComida.wav");
			delete quieroComer;
			NPiezas--;
			
			// Actualizar el turno
			turno++;
			return true;
			}
			
		}
	}
	else {
		if (HayJaqueNegras()) {
			// Movimiento inválido, pone en jaque al rey blanco
			tablero[origen.x][origen.y] = tablero[destino.x][destino.y];
			tablero[destino.x][destino.y] = piezaCapturada;
			ETSIDI::play("sonidos/error.wav");
			return false;
		}
		else {
			if (quieroComer) {
				ETSIDI::play("sonidos/PiezaComida.wav");
				delete quieroComer;
				NPiezas--;
				// Actualizar el turno
				turno++;
				return true;
			}
			
		}
	}

	// Actualizar el turno
	turno++;
	return true;
	
}


void Tablero::CompruebaPosible(Vector origen) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (tablero[origen.x][origen.y]->validarMovimiento(origen, { i,j }, *this) == true) {
				agregar(new Casilla({ i,j }, { 0, 255, 0 }));
			}
		}
	}
}

bool Tablero::HayJaqueBlancas() {
	 
	// turno impar->mueven blancas, jaque a negras
	// turno par->mueven negras,jaque a blancas
	Vector posicionRey = buscarRey(Pieza::Blanco);

	// Verificar si alguna pieza del oponente amenaza al rey actual
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			if (tablero[x][y] == nullptr);
			else if (tablero[x][y]->getColor() == Pieza::Negro)
			{

				if (tablero[x][y]->validarMovimiento({ x,y }, posicionRey, *this) == true) {
					return true;  // Hay una pieza del oponente que amenaza al rey
				}
			}
		}
	}

	return false;  // No hay jaque en el tablero actual
}

bool Tablero::HayJaqueNegras() {

	// turno impar->mueven blancas, jaque a negras
	// turno par->mueven negras,jaque a blancas
	Vector posicionRey = buscarRey(Pieza::Negro);

	// Verificar si alguna pieza del oponente amenaza al rey actual
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			if (tablero[x][y] == nullptr);
			else if (tablero[x][y]->getColor() == Pieza::Blanco)
			{

				if (tablero[x][y]->validarMovimiento({ x,y }, posicionRey, *this) == true) {
					return true;  // Hay una pieza del oponente que amenaza al rey
				}
			}
		}
	}

	return false;  // No hay jaque en el tablero actual
}

Vector Tablero::buscarRey(Pieza::COLOR color) {
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			Pieza* pieza = getPieza(x, y);
			if (pieza != nullptr && pieza->getTipo() == Pieza::REY && pieza->getColor() == color) {
				return Vector(x, y);
			}
		}
	}
	// Si no se encuentra el rey, devuelve una posición inválida (-1, -1)
	return Vector(-1, -1);
}


bool Tablero::agregar(Casilla* casilla) {
	if (NLista < MAX) {
		lista[NLista++] = casilla;
		return true;
	}
	else return false;
}

void Tablero::eliminarContenido() {
	for (int i = 0; i < NLista; i++) {
		delete lista[i];
		lista[i] = nullptr;
	}
	NLista=0;
}

void Tablero::DibujaPosibles() {
	for (int i = 0; i < NLista; i++)
	{
		lista[i]->DibujaCasilla(0.0005);
	}
}


// Se intenta implementar el jaque mate pero salta un error siempre
bool Tablero::HayJaqueMateBlancas() {

	Tablero tablero2(*this);

	if (HayJaqueBlancas() == true) {
		for (int i = 0; i < MAX_CASILLAS; i++) {
			for (int j = 0; j < MAX_CASILLAS; j++) {

				// Selecciono una pieza válida
				if (tablero2.tablero[i][j] != nullptr && tablero2.tablero[i][j]->getColor() == Pieza::Negro) {
					
						Vector origenvir = { i,j };
						Pieza* piezaSeleccionada = tablero2.tablero[origenvir.x][origenvir.y];
						for (int m = 0; m < MAX_CASILLAS; m++) {
							for (int n = 0; n < MAX_CASILLAS; n++) {
								if (tablero2.tablero[i][j]->validarMovimiento(origenvir, { m,n }, tablero2) == true) {
									
									Pieza* piezaCapturada = tablero2.tablero[m][n];
									if(tablero2.mover(origenvir, { m,n })){
										if(tablero2.HayJaqueBlancas()==false)return false;
										tablero2=*this;
										piezaSeleccionada = tablero2.tablero[origenvir.x][origenvir.y];
									}
									

								}
							}
						}
					
				}

			}
		}
	}
	else return false;

	// Ninguno de los movimientos posibles evita el Jaque -> Jaque Mate
	return true;
}

bool Tablero::HayJaqueMateNegras() {

		Tablero tablero2(*this);

		if (HayJaqueBlancas() == true) {
			for (int i = 0; i < MAX_CASILLAS; i++) {
				for (int j = 0; j < MAX_CASILLAS; j++) {

					// Selecciono una pieza válida
					if (tablero2.tablero[i][j] != nullptr && tablero2.tablero[i][j]->getColor() == Pieza::Blanco) {

						Vector origenvir = { i,j };
						Pieza* piezaSeleccionada = tablero2.tablero[origenvir.x][origenvir.y];
						for (int m = 0; m < MAX_CASILLAS; m++) {
							for (int n = 0; n < MAX_CASILLAS; n++) {
								if (tablero2.tablero[i][j]->validarMovimiento(origenvir, { m,n }, tablero2) == true) {

									Pieza* piezaCapturada = tablero2.tablero[m][n];
									if (tablero2.mover(origenvir, { m,n })) {
										if (tablero2.HayJaqueBlancas() == false)return false;
										tablero2 = *this;
										piezaSeleccionada = tablero2.tablero[origenvir.x][origenvir.y];
									}

								}
							}
						}

					}

				}
			}
		}
		else return false;

		// Ninguno de los movimientos posibles evita el Jaque -> Jaque Mate
		return true;
	}
	
	
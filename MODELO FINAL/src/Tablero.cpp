#pragma once
#include <Tablero.h>
#include"freeglut.h"
#include"ETSIDI.h"
#include <cmath>



Tablero::Tablero() :NPiezas(0), NLista(0), turno(1) {
	inicializa();
	for (int i = 0; i < MAX; i++)lista[i] = nullptr;
	TurnoB->setSize(1.05, 1.05);
	TurnoB->setPos(10.3, 9.2);

	TurnoN->setSize(0.85, 0.85);
	TurnoN->setPos(11.6, 9.25);

}

//funcion para imprimir de que color es el turno
void Tablero::dibujaTurno() {
	if (turno % 2 != 0)TurnoB->draw();
	else if (turno % 2 == 0) TurnoN->draw();

}

//funcion para clonar un tablero, que más tarde usaremos para hacer el jaque mate
Tablero::Tablero(const Tablero& otro) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (otro.tablero[i][j] != nullptr)
				tablero[i][j] = otro.tablero[i][j]->clonar();
			else tablero[i][j] = nullptr;
		}
	}
}

//sobrecarga para la funcion mover, iguala la pieza quiero comer a la antigua pieza en esa posicion
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

//destructor de tablero
Tablero::~Tablero() {
	for (int i = 0; i < MAX_CASILLAS; i++)
		for (int j = 0; j < MAX_CASILLAS; j++)
			delete tablero[i][j];

}

//funcion para inicializacion de todas las fichas e inclusión en el tablero
void Tablero::inicializa() {  
	// Inicializar todas las casillas con un puntero nulo
	for (int i = 0; i < MAX_CASILLAS; i++) {
		for (int j = 0; j < MAX_CASILLAS; j++) {
			tablero[i][j] = nullptr;
		}
	}


	// BLANCAS
	tablero[0][0] = new Torre(Pieza::Blanco);
	//tablero[2][0] = new Alfil(Pieza::Blanco);
	tablero[7][0] = new Torre(Pieza::Blanco);
	//tablero[5][0] = new Alfil(Pieza::Blanco);
	tablero[1][0] = new Caballo(Pieza::Blanco);
	tablero[6][0] = new Caballo(Pieza::Blanco);
	tablero[3][0] = new Reina(Pieza::Blanco);
	tablero[4][0] = new Rey(Pieza::Blanco);
	for (int i = 0; i < 8; i++) 
	{
		tablero[i][1] = new Peon(Pieza::Blanco);
	}


	// NEGRAS
	tablero[7][7] = new Torre(Pieza::Negro);
	//tablero[2][7] = new Alfil(Pieza::Negro);
	//tablero[5][7] = new Alfil(Pieza::Negro);
	tablero[0][7] = new Torre(Pieza::Negro);
	tablero[1][7] = new Caballo(Pieza::Negro);
	tablero[6][7] = new Caballo(Pieza::Negro);
	tablero[3][7] = new Reina(Pieza::Negro);
	tablero[4][7] = new Rey(Pieza::Negro);
	for (int i = 0; i < 8; i++) 
	{
		tablero[i][6] = new Peon(Pieza::Negro);
	}

}


// FUNCIÓN PARA DIBUJAR EL TABLERO UTILIZANDO UNA MATRIZ DE CASILLAS Y ELEGIR EL COLOR SEGÚN EL EQUIPO SELECCIONADO

void Tablero::DibujaTablero(ColorRGB color1, ColorRGB color2) {
	float tam = 1.0; //Definimos variables auxiliares para ir desplazando la casilla
	Vector aux; // incializado por defecto a 0,0
	for (int columna = 0; columna < MAX_CASILLAS; columna++) {
		aux.x = (0.0);
		aux.y = (tam * columna);

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


			aux.x = (aux.x + tam);
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

bool Tablero::agregar(Pieza* p, int _i, int _j)
{
	if (_i < 0 || _i >= MAX_CASILLAS)return false;
	if (_j < 0 || _j >= MAX_CASILLAS)return false;

	if (NPiezas < MAX_PIEZAS) {
		tablero[_i][_j] = p;
		NPiezas++;
		return true;
	}

}

//estas funciones eliminan las piezas despues de ser comidas en la funcion mover
void Tablero::eliminar(int i, int j) {
	if (i < 0 || i >= MAX_CASILLAS)return;
	if (j < 0 || j >= MAX_CASILLAS)return;

	delete tablero[i][j];
	tablero[i][j] = nullptr; // IMPORTANTE PONER EL PUNTERO A nullptr DESPUES DE ELIMINARLO
	NPiezas--;
}

void Tablero::eliminar(Pieza* p) {
	for (int i = 0; i < MAX_CASILLAS; i++) {
		for (int j = 0; j < MAX_CASILLAS; j++) {
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

//en esta funcion controlamos el movimiento de las piezas, asi como si se produce jaque en algun momento, limitando el movimiento hasta que se deshaga el jaque
bool Tablero::mover(Vector origen, Vector destino) {
	if (origen.x < 0 || origen.y < 0 || origen.y >= 8 || origen.x >= 8) return false;
	if (destino.x < 0 || destino.y < 0 || destino.y >= 8 || destino.x >= 8) return false;

	if (tablero[origen.x][origen.y] == nullptr) return false;

	Pieza* piezaMovida = tablero[origen.x][origen.y];
	Pieza* quieroComer = nullptr;
	quieroComer = tablero[destino.x][destino.y];

	tablero[destino.x][destino.y] = tablero[origen.x][origen.y];
	tablero[origen.x][origen.y] = nullptr;  // IMPORTANTE -> poner el puntero a nullptr después de eliminar

	// Verificar si se pone en jaque al propio rey
	if (turno % 2 == 1) {
		if (HayJaqueBlancas()) {
			// Movimiento inválido, pone en jaque al rey blanco
			tablero[origen.x][origen.y] = tablero[destino.x][destino.y];
			tablero[destino.x][destino.y] = quieroComer;
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
	else {
		if (HayJaqueNegras()) {
			// Movimiento inválido, pone en jaque al rey blanco
			tablero[origen.x][origen.y] = tablero[destino.x][destino.y];
			tablero[destino.x][destino.y] = quieroComer;
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

	if(quieroComer !=nullptr){
		ETSIDI::play("sonidos/PiezaComida.wav");
		delete quieroComer;
		NPiezas--;
	}
	// Actualizar el turno
	coronacionPeon();
	turno++;
	
	return true;

}

//comprueba los posibles movimientos de cada una de las piezas llamando a la funcion validarMovimiento
//cada una de las piezas tiene su propia funcion validarMovimiento, que limita los posibles movimientos de cada tipo de pieza
//se agrega una casilla de color verde en cada una de las casillas a las que se puede mover la pieza seleccionada
void Tablero::CompruebaPosible(Vector origen) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (tablero[origen.x][origen.y]->validarMovimiento(origen, { i,j }, *this) == true) {
				agregar(new Casilla({ i,j }, { 0, 255, 0 }));
			}
		}
	}
}

//se agrega la casilla a una lista de casillas
bool Tablero::agregar(Casilla* casilla) {
	if (NLista < MAX) {
		lista[NLista++] = casilla;
		return true;
	}
	else return false;
}

//funcion que dibuja estas posibles casillas
void Tablero::DibujaPosibles() {
	for (int i = 0; i < NLista; i++)
	{
		lista[i]->DibujaCasilla(0.0005);
	}
}

//funcion para eliminar estas casillas una vez soltada la pieza (se llama en ajedrez)
void Tablero::eliminarContenido() {
	for (int i = 0; i < NLista; i++) {
		delete lista[i];
		lista[i] = nullptr;
	}
	NLista = 0;
}

//se comprueba si el rey de blancas está en jaque 
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

//se comprueba si el rey de negras está en jaque
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

//busca en que posicion se situa el rey del color recibido
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

//funcion para convertir el peon en superpieza al llegar al final
void Tablero::coronacionPeon() {
	for (int i = 0; i < MAX_CASILLAS; i++) {
		if ((tablero[i][7] != nullptr) && (tablero[i][7]->getTipo() == Pieza::PEON) && (tablero[i][7]->getColor() == Pieza::Blanco)) {
			eliminar(tablero[i][7]);
			tablero[i][7] = new PiezaEspecial(Pieza::Blanco);
		}
		if ((tablero[i][0] != nullptr) && (tablero[i][0]->getTipo() == Pieza::PEON) && (tablero[i][0]->getColor() == Pieza::Negro)) {
			eliminar(tablero[i][0]);
			tablero[i][0] = new PiezaEspecial(Pieza::Negro);
		}
	}
}

//EN ESTAS FUNCIONES HACEMOS EL JAQUE MATE
//en estas funciones, lo que hacemos es clonar un nuevo tablero, en el que hacemos y deshacemos todos los posibles movimientos, en el momento que
//encuentra un posible movimiento, automáticamente devuelve false. Pero si no encuentra ningún movimiento posible que deshaga el jaque, se devolverá
//un true, significando así que hay jaque mate

//esta función hemos conseguido que funcione, pero necesita mucha memoria y tarda mucho tiempo en cargar


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

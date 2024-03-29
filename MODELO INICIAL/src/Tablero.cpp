#pragma once
#include <Tablero.h>
#include"freeglut.h"
#include"ETSIDI.h"
#include <cmath>


Tablero::Tablero() {
	// Primero reservamos espacio dinamico para una matriz de 8x8 casillas (tablero) 
	NPiezas = 0;
	turno = 1;
	n = -1;
	casilla = new Casilla * [NCasillas];
	comienzo = false;

	for (int i = 0; i < NCasillas; i++) {
		casilla[i] = new Casilla[NCasillas];
	}

	// Inicializamos el vector de piezas 
	inicializa();
}

// FUNCI�N PARA DIBUJAR EL TABLERO UTILIZANDO UNA MATRIZ DE CASILLAS Y ELEGIR EL COLOR SEG�N EL EQUIPO SELECCIONADO
void Tablero::DibujaTablero(ColorCasilla color1, ColorCasilla color2) {
	float tam = 1.0; //Definimos variables auxiliares para ir desplazando la casilla
	Vector aux{ 0.0,0.0 };

	for (int columna = 0; columna < NCasillas; columna++) {
		aux.x = 0.0;
		aux.y = tam * columna;

		for (int fila = 0; fila < NCasillas; fila++) {

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


			aux.x += tam;
		}
	}
	c.SetColor(138, 149, 151);
	c.CheckPosition();
	c.DibujaCasilla(c.GetPos(), 0.005);

}


// FUNCIONES PARA EL MANEJO DEL VECTOR DE PIEZAS
void Tablero::DibujaPiezas()
{
	for (int i = 0; i < NCasillas * NCasillas; i++)
	{
		lista[i]->Dibuja();
	}
}

bool Tablero::agregar(Piezas* p)
{
	if (NPiezas < NCasillas * NCasillas)
		lista[NPiezas++] = p;
	else
		return false; // capacidad m�xima alcanzada
	return true;
}

void Tablero::inicializa() {  // inicializacion de todas las fichas e inclusi�n en el vector de piezas
	Piezas* aux;
	for (float j = 0.0; j < NCasillas; j++)
	{
		for (float i = 0.0; i < NCasillas; i++) {
			if (j == 1.0) {
				aux = new Peon(Vector{ i,j }, Piezas::COLOR::BLANCO);
			}
			else if (j == 6.0) {
				aux = new Peon(Vector{ i, j }, Piezas::COLOR::NEGRO);
			}
			else if (j == 0.0 && (i == 2.0 || i == 5.0))
			{
				aux = new Alfil(Vector{ i, j }, Piezas::COLOR::BLANCO);
			}
			else if (j == 7.0 && (i == 2.0 || i == 5.0))
			{
				aux = new Alfil(Vector{ i, j }, Piezas::COLOR::NEGRO);
			}
			else if (j == 0.0 && i == 4.0)
			{
				aux = new Rey(Vector{ i, j }, Piezas::COLOR::BLANCO);
			}
			else if (j == 7.0 && i == 4.0)
			{
				aux = new Rey(Vector{ i, j }, Piezas::COLOR::NEGRO);
			}
			else if (j == 0.0 && (i == 1.0 || i == 6.0))
			{
				aux = new Caballo(Vector{ i, j }, Piezas::COLOR::BLANCO);
			}
			else if (j == 7.0 && (i == 1.0 || i == 6.0))
			{
				aux = new Caballo(Vector{ i, j }, Piezas::COLOR::NEGRO);
			}
			else if (j == 0.0 && (i == 0.0 || i == 7.0))
			{
				aux = new Torre(Vector{ i, j }, Piezas::COLOR::BLANCO);
			}
			else if (j == 7.0 && (i == 0.0 || i == 7.0))
			{
				aux = new Torre(Vector{ i, j }, Piezas::COLOR::NEGRO);
			}
			else {
				aux = new NoPieza(Vector{ i,j });
			}
			agregar(aux);
		}
	}
	comienzo = true;
}

void Tablero::MueveCursor(unsigned char key) {
	switch (key)
	{
	case GLUT_KEY_UP:
		c.pos.y += 1;
		break;
	case GLUT_KEY_DOWN:
		c.pos.y -= 1;
		break;
	case GLUT_KEY_RIGHT:
		c.pos.x += 1;
		break;
	case GLUT_KEY_LEFT:
		c.pos.x -= 1;
		break;
	case ' ':
		n = Selecciona();
		break;
	case 13:
		if (n != -1 )Mueve(n);
		else if(n==-1 && turno>1) ETSIDI::play("sonidos/error.wav");
		if(comienzo==true && (HayRey(Piezas::BLANCO) == false || HayRey(Piezas::NEGRO)))exit(0);

		n = -1;
		break;
	}
}

void Tablero::Mueve(int n) {
	Vector PosAntes;
	
	if (lista[n]->CheckMov(c.pos, Comprobaciones(c.pos)) == true)
	{
		PosAntes = lista[n]->posicion;
		lista[n]->SetPos(Vector{ c.pos.x,c.pos.y });

		if (comer) {
			ETSIDI::play("sonidos/PiezaComida.wav");
		}
		turno++;
		ColocaSelector();

		// Se crea pieza vacia donde estaba antes
		delete lista[aux];
		lista[aux] = new NoPieza(PosAntes);

	}
	else ETSIDI::play("sonidos/error.wav");
	lista[n]->seleccionado = false;

}

int Tablero::Selecciona() {
	int retorno = -1;
	for (int i = 0; i < NCasillas * NCasillas; i++)
	{
		if (HayPieza(i)) // Se comprueba que hay una pieza en la posicion seleccionada
		{
			if (c.pos == lista[i]->posicion)  // Se utiliza el operador == sobrecargado para buscar la pieza
			{
				if (turno % 2 != 0 && lista[i]->color == Piezas::COLOR::BLANCO) { // turno de blancas y pieza seleccionada negra
					lista[i]->seleccionado = true;
					retorno = i;
				}
				else if (turno % 2 == 0 && lista[i]->color == Piezas::COLOR::NEGRO) { // turno de negras y pieza seleccionada blanca
					lista[i]->seleccionado = true;
					retorno = i;
				}
				else ETSIDI::play("sonidos/error.wav");
			}
		}
		else if (lista[i]->tipo == Piezas::TIPO::NT && c.pos == lista[i]->posicion)ETSIDI::play("sonidos/error.wav");
	}

	return retorno;
}

void Tablero::ColocaSelector() {
	if (turno % 2 != 0)c.pos = { 0.0,0.0 };
	else if (turno % 2 == 0)c.pos = { 0.0,7.0 };
}

bool Tablero::HayPieza(int i) {
	if (lista[i]->tipo != Piezas::TIPO::NT)return true;
	else return false;
}

int Tablero::Comprobaciones(Vector p) {
	int check = 0;
	comer = 0;
	// Se comprueba si donde se quiere mover hay una pieza del otro color o del mismo color

	for (int i = 0; i < NCasillas * NCasillas; i++) {
		if (p == lista[i]->posicion)
			if (HayPieza(i)) { // comprobaci�n de que hay una pieza

				if (lista[i]->color != lista[n]->color) { // comprobaci�n de que es de distinto color
					check = 1;
					comer = 1;
					aux = i; // Valor de la posicion en la lista donde estaba la casilla antes de moverse
				}
				else if (lista[i]->color == lista[n]->color) { // comprobaci�n de que es del mismo color 
					check = 2;
				}
			}
			else aux = i;

	}

	if (ComprobacionAlfil() == false)check = 2;
	if (ComprobacionTorre() == false)check = 2;

	return check;
}


bool Tablero::ComprobacionAlfil() {
	bool retorno = true;

	if (lista[n]->tipo == Piezas::TIPO::ALFIL) {  // El alfil no puede "saltar" piezas
		if ((c.pos.x - lista[n]->posicion.x) > 0 && (c.pos.y - lista[n]->posicion.y) > 0) { // Selecciona la diagonal en la que se quiere mover el peon
			for (float x = lista[n]->posicion.x; x < c.pos.x; x++) { // Comprueba las posiciones de la diagonal desde la posicion de partida hasta la que se quiere mover
				for (float y = lista[n]->posicion.y; y < c.pos.y; y++) {

					if ((x - lista[n]->posicion.x) == (y - lista[n]->posicion.y)) {
						for (int i = 0; i < NCasillas * NCasillas; i++) { // Busca si hay una pieza en estas posicones que no sea la seleccionada
							if (HayPieza(i) && lista[n]->posicion != lista[i]->posicion) {
								if (lista[i]->posicion.x == x && lista[i]->posicion.y == y) {  // Si hay una pieza entre medias 
									retorno = false; // NO SE PUEDE MOVER AHI
								}
							}
						}
					}
				}
			}
		}

		if ((c.pos.x - lista[n]->posicion.x) > 0 && (c.pos.y - lista[n]->posicion.y) < 0) {
			for (float x = lista[n]->posicion.x; x < c.pos.x; x++) {
				for (float y = lista[n]->posicion.y; y > c.pos.y; y--) {

					if (abs(x - lista[n]->posicion.x) == abs(y - lista[n]->posicion.y)) {
						for (int i = 0; i < NCasillas * NCasillas; i++) { // Busca si hay una pieza en estas posicones que no sea la seleccionada
							if (HayPieza(i) && lista[n]->posicion != lista[i]->posicion) {
								if (lista[i]->posicion.x == x && lista[i]->posicion.y == y) {  // Si hay una pieza entre medias 
									retorno = false; // NO SE PUEDE MOVER AHI
								}
							}
						}
					}
				}
			}
		}


		if ((c.pos.x - lista[n]->posicion.x) < 0 && (c.pos.y - lista[n]->posicion.y) < 0) {
			for (float x = lista[n]->posicion.x; x > c.pos.x; x--) {
				for (float y = lista[n]->posicion.y; y > c.pos.y; y--) {


					if (abs(x - lista[n]->posicion.x) == abs(y - lista[n]->posicion.y)) {
						for (int i = 0; i < NCasillas * NCasillas; i++) { // Busca si hay una pieza en estas posicones que no sea la seleccionada
							if (HayPieza(i) && lista[n]->posicion != lista[i]->posicion) {
								if (lista[i]->posicion.x == x && lista[i]->posicion.y == y) {  // Si hay una pieza entre medias 
									retorno = false; // NO SE PUEDE MOVER AHI
								}
							}
						}
					}
				}
			}
		}


		if ((c.pos.x - lista[n]->posicion.x) < 0 && (c.pos.y - lista[n]->posicion.y) > 0) {
			for (float x = lista[n]->posicion.x - 1; x > c.pos.x; x--) {
				for (float y = lista[n]->posicion.y + 1; y < c.pos.y; y++) {
					if (abs(x - lista[n]->posicion.x) == abs(y - lista[n]->posicion.y)) {

						for (int i = 0; i < NCasillas * NCasillas; i++) { // Busca si hay una pieza en estas posicones que no sea la seleccionada
							if (HayPieza(i)) {
								if (lista[i]->posicion.x == x && lista[i]->posicion.y == y) {  // Si hay una pieza entre medias 

									retorno = false; // NO SE PUEDE MOVER AHI
								}
							}
						}
					}
				}
			}
		}
	}
	return retorno;

}

bool Tablero::ComprobacionTorre() {
	bool retorno = true;
	if (lista[n]->tipo == Piezas::TIPO::TORRE) {
		//COMPROBACION EJE X POSITIVO
		if ((c.pos.x - lista[n]->posicion.x) > 0) {

			for (float x = lista[n]->posicion.x; x < c.pos.x; x++)
			{
				for (int i = 0; i < NCasillas * NCasillas; i++)
				{
					if (HayPieza(i) && lista[n]->posicion != lista[i]->posicion) {
						if (lista[i]->posicion.x == x && lista[i]->posicion.y == lista[n]->posicion.y) {  // Si hay una pieza entre medias  
							retorno = false;
						}
					}

				}
			}


		}

		//COMPROBACCION EJE Y POSITIVO
		if ((c.pos.y - lista[n]->posicion.y) > 0) {
			for (float y = lista[n]->posicion.y; y < c.pos.y; y++)
			{
				for (int i = 0; i < NCasillas * NCasillas; i++)
				{
					if (HayPieza(i) && n != i) {
						if (lista[i]->posicion.x == lista[n]->posicion.x && lista[i]->posicion.y == y) {  // Si hay una pieza entre medias  
							retorno = false;
						}
					}

				}
			}

		}

		//COMPROBACION EJE X NEGATIVO
		if ((c.pos.x - lista[n]->posicion.x) < 0) {

			for (float x = lista[n]->posicion.x; x > c.pos.x; x--)
			{
				for (int i = 0; i < NCasillas * NCasillas; i++)
				{
					if (HayPieza(i) && lista[n]->posicion != lista[i]->posicion) {
						if (lista[i]->posicion.x == x && lista[i]->posicion.y == lista[n]->posicion.y) {  // Si hay una pieza entre medias  
							retorno = false;
						}
					}

				}
			}


		}

		//COMPROBACION EJE Y NEGATIVO
		if ((c.pos.y - lista[n]->posicion.y) < 0) {
			for (float y = lista[n]->posicion.y; y > c.pos.y; y--)
			{
				for (int i = 0; i < NCasillas * NCasillas; i++)
				{
					if (HayPieza(i) && n != i) {
						if (lista[i]->posicion.x == lista[n]->posicion.x && lista[i]->posicion.y == y) {  // Si hay una pieza entre medias  
							retorno = false;
						}
					}

				}
			}

		}


	}

	return retorno;
}


bool Tablero::ComprobacionReina() {
	bool retorno = true;
	if (lista[n]->tipo == Piezas::TIPO::REINA) {
		retorno = ComprobacionAlfil();
		retorno = ComprobacionTorre();
	}
	return retorno;
}

bool Tablero::HayRey(Piezas::COLOR c) {
	for (int i = 0; i < NCasillas; i++) {
		if (HayPieza(i)) {
			if (lista[i]->tipo == Piezas::TIPO::REY && lista[i]->color == c)return true;
		}
	}

	return false;
}
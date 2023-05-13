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
	
	for (int i = 0; i < NCasillas; i++) {  
		casilla[i] = new Casilla[NCasillas];
	}

	// Inicializamos el vector de piezas 
	inicializa();
}

// FUNCIÓN PARA DIBUJAR EL TABLERO UTILIZANDO UNA MATRIZ DE CASILLAS Y ELEGIR EL COLOR SEGÚN EL EQUIPO SELECCIONADO
void Tablero::DibujaTablero(ColorCasilla color1, ColorCasilla color2) {
	float tam= 1.0; //Definimos variables auxiliares para ir desplazando la casilla
	Vector aux{0.0,0.0};

	for (int columna=0; columna < NCasillas; columna++) {
		aux.x = 0.0;
		aux.y = tam * columna;
		
		for (int fila=0; fila < NCasillas; fila++) {
			
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
	c.SetColor(138,149,151);
	c.CheckPosition();
	c.DibujaCasilla(c.GetPos(),0.005);

}


// FUNCIONES PARA EL MANEJO DEL VECTOR DE PIEZAS
void Tablero::DibujaPiezas()
{
	for (int i = 0; i <NCasillas*NCasillas; i++)
	{
		lista[i]->Dibuja();
	}
}

bool Tablero::agregar(Piezas* p)
{
	if (NPiezas < NCasillas * NCasillas)
		lista[NPiezas++] = p; 
	else
		return false; // capacidad máxima alcanzada
	return true;
}

void Tablero::inicializa() {  // inicializacion de todas las fichas e inclusión en el vector de piezas
	Piezas* aux;
		for (float j = 0.0; j < NCasillas; j++)
		{
			for (float i = 0.0; i < NCasillas; i++) {
				if (j == 1.0 ) {
					aux = new Peon(Vector{ i,j }, Piezas::COLOR::BLANCO);
				}
				else if (j == 6.0 ) {
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
				else if (j == 0.0 && i == 3.0)
				{
				aux = new Reina(Vector{ i, j }, Piezas::COLOR::BLANCO);
				}
				else if (j == 7.0 && i == 3.0)
				{
				aux = new Reina(Vector{ i, j }, Piezas::COLOR::NEGRO);
				}
				else if (j == 0.0 && (i == 1.0||i==6.0))
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
				else if(j == 7.0 && (i == 0.0 || i == 7.0)) 
				{
					aux = new Torre(Vector{ i, j }, Piezas::COLOR::NEGRO);
				}
				else {
				aux = new NoPieza(Vector{ i,j });
				}
				agregar(aux);
			}	
		}
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
		n=Selecciona();
		break;
	case 13:
		if (n != -1)Mueve(n);
		break;
	}
}

void Tablero::Mueve(int n) {
	int aux;
	bool comer = false;
	Vector PosAntes;


		if (lista[n]->CheckMov(c.pos,Comprobaciones(aux,comer)) == true)
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
	int retorno=-1;
		for ( int i = 0; i < NCasillas * NCasillas; i++)
		{
			if(HayPieza(i)) // Se comprueba que hay una pieza en la posicion seleccionada
			{
				if (c.pos == lista[i]->posicion)  // Se utiliza el operador == sobrecargado para buscar la pieza
				{
					if (turno % 2 != 0 && lista[i]->color == Piezas::COLOR::BLANCO){ // turno de blancas y pieza seleccionada negra
							lista[i]->seleccionado = true;
						retorno = i;
					}
					else if (turno % 2 == 0 && lista[i]->color == Piezas::COLOR::NEGRO){ // turno de negras y pieza seleccionada blanca
						lista[i]->seleccionado = true;
						retorno = i;
					}
					else ETSIDI::play("sonidos/error.wav");
				}
			}
			else if(lista[i]->tipo==Piezas::TIPO::NT && c.pos==lista[i]->posicion)ETSIDI::play("sonidos/error.wav");
		}
		
		return retorno;
}

void Tablero::ColocaSelector() {
	if (turno % 2 != 0)c.pos = {0.0,0.0};
	else if (turno %2==0)c.pos = {0.0,7.0};
}

bool Tablero::HayPieza(int i) {
	if (lista[i]->tipo != Piezas::TIPO::NT)return true;
	else return false;
}

int Tablero::Comprobaciones(int& aux,bool &comer) {
	int check = 0;
	// Se comprueba si donde se quiere mover hay una pieza del otro color o del mismo color

	for (int i = 0; i < NCasillas * NCasillas; i++) {
		if (c.pos == lista[i]->posicion)
			if (HayPieza(i) && i != n) { // comprobación de que hay una pieza

				if (lista[i]->color != lista[n]->color) { // comprobación de que es de distinto color
					check = 1;
					comer = 1;
					aux = i; // Valor de la posicion en la lista donde estaba la casilla antes de moverse
				}
				else if (lista[i]->color == lista[n]->color) { // comprobación de que es del mismo color 
					check = 2;
				}
			}
			else aux = i;
	
	}

	if (ComprobacionAlfil() == false)check = 2;
	if (ComprobacionTorre() == false)check = 2;
	if (ComprobacionReinaA() == false)check = 3;
	if (ComprobacionReinaB() == false)check = 2;
	if (Jaque() == false)check == 2;
	


	
		return check;
}


bool Tablero::ComprobacionAlfil() {
	bool retorno=true;

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
		if ((c.pos.x - lista[n]->posicion.x ) > 0) {

			for (float x = lista[n]->posicion.x; x < c.pos.x; x++)
			{
				for (int i = 0; i < NCasillas*NCasillas; i++)
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
		if ((c.pos.y - lista[n]->posicion.y)>0) {
			for (float y = lista[n]->posicion.y; y < c.pos.y; y++)
			{
				for (int i = 0; i < NCasillas*NCasillas; i++)
				{
					if (HayPieza(i) && n!=i ) {
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


bool Tablero::ComprobacionReinaA() {
		bool retorno = true;
		if (lista[n]->tipo == Piezas::TIPO::REINA) {
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

bool Tablero::ComprobacionReinaB() {
	bool retorno = true;

	if (lista[n]->tipo == Piezas::TIPO::REINA) {  // El alfil no puede "saltar" piezas
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


bool Tablero::Jaque() {
	bool rey = true;


	if (lista[n]->tipo == Piezas::TIPO::ALFIL|| lista[n]->tipo == Piezas::TIPO::PEON)//cualquier movimiento en diagonal de peon y alfil no puede comer al rey
	{  // El alfil no puede "saltar" piezas

		if ((c.pos.x - lista[n]->posicion.x) > 0 && (c.pos.y - lista[n]->posicion.y) > 0) {
			for (float x = lista[n]->posicion.x; x <= c.pos.x; x++) {
				for (float y = lista[n]->posicion.y; y <= c.pos.y; y++) {

					if (abs(x - lista[n]->posicion.x) == abs(y - lista[n]->posicion.y)) {
						for (int i = 0; i < NCasillas * NCasillas; i++) { // Busca si hay una pieza en estas posicones que no sea la seleccionada
							if (lista[i]->tipo == Piezas::TIPO::REY ) {
								if (lista[i]->posicion.x == x  && lista[i]->posicion.y == y ) {// Si hay una pieza entre medias 
									rey = false; // NO SE PUEDE MOVER AHI
								}
							}
						}
					}
				}
			}
		}




		else if ((c.pos.x - lista[n]->posicion.x) > 0 && (c.pos.y - lista[n]->posicion.y) < 0) {
			for (float x = lista[n]->posicion.x; x <= c.pos.x; x++) {
				for (float y = lista[n]->posicion.y; y >= c.pos.y; y--) {


					if (abs(x - lista[n]->posicion.x) == abs(y - lista[n]->posicion.y)) {
						for (int i = 0; i < NCasillas * NCasillas; i++) { // Busca si hay una pieza en estas posicones que no sea la seleccionada
							if (lista[i]->tipo == Piezas::TIPO::REY ) {
								if (lista[i]->posicion.x == x  && lista[i]->posicion.y == y ) {// Si hay una pieza entre medias 
									rey = false; // NO SE PUEDE MOVER AHI
								}
							}
						}
					}
				}
			}
		}



		else if ((c.pos.x - lista[n]->posicion.x) <= 0 && (c.pos.y - lista[n]->posicion.y) <= 0) {
			for (float x = lista[n]->posicion.x; x >= c.pos.x; x--) {
				for (float y = lista[n]->posicion.y; y >= c.pos.y; y--) {


					if (abs(x - lista[n]->posicion.x) == abs(y - lista[n]->posicion.y)) {
						for (int i = 0; i < NCasillas * NCasillas; i++) { // Busca si hay una pieza en estas posicones que no sea la seleccionada
							if (lista[i]->tipo == Piezas::TIPO::REY ) {
								if (lista[i]->posicion.x == x  && lista[i]->posicion.y == y ) {// Si hay una pieza entre medias 
									rey = false; // NO SE PUEDE MOVER AHI
								}
							}
						}
					}
				}
			}
		}



		else if ((c.pos.x - lista[n]->posicion.x) <= 0 && (c.pos.y - lista[n]->posicion.y) >= 0) {
			for (float x = lista[n]->posicion.x; x >= c.pos.x; x--) {
				for (float y = lista[n]->posicion.y; y <= c.pos.y; y++) {


					if (abs(x - lista[n]->posicion.x) == abs(y - lista[n]->posicion.y)) {
						for (int i = 0; i < NCasillas * NCasillas; i++) { // Busca si hay una pieza en estas posicones que no sea la seleccionada
							if (lista[i]->tipo == Piezas::TIPO::REY ) {
								if (lista[i]->posicion.x == x  && lista[i]->posicion.y == y ) {// Si hay una pieza entre medias 
									rey = false; // NO SE PUEDE MOVER AHI
								}
							}
						}
					}
				}
			}
		}

	if (lista[n]->tipo == Piezas::TIPO::TORRE)
	{
			//COMPROBACION EJE X POSITIVO
			if ((c.pos.x - lista[n]->posicion.x) >= 0) {

				for (float x = lista[n]->posicion.x; x <= c.pos.x; x++)
				{
					for (int i = 0; i < NCasillas * NCasillas; i++)
					{
						if (lista[i]->tipo == Piezas::TIPO::REY) {
							if (lista[i]->posicion.x == x && lista[i]->posicion.y == lista[n]->posicion.y) {  // Si hay una pieza entre medias  
								rey = false;
							}
						}

					}
				}


			}

			//COMPROBACCION EJE Y POSITIVO
			if ((c.pos.y - lista[n]->posicion.y) >= 0) {
				for (float y = lista[n]->posicion.y; y <= c.pos.y; y++)
				{
					for (int i = 0; i < NCasillas * NCasillas; i++)
					{
						if (lista[i]->tipo == Piezas::TIPO::REY) {
							if (lista[i]->posicion.x == lista[n]->posicion.x && lista[i]->posicion.y == y) {  // Si hay una pieza entre medias  
								rey = false;
							}
						}

					}
				}

			}

			//COMPROBACION EJE X NEGATIVO
			if ((c.pos.x - lista[n]->posicion.x) <= 0) {

				for (float x = lista[n]->posicion.x; x >= c.pos.x; x--)
				{
					for (int i = 0; i < NCasillas * NCasillas; i++)
					{
						if (lista[i]->tipo == Piezas::TIPO::REY) {
							if (lista[i]->posicion.x == x && lista[i]->posicion.y == lista[n]->posicion.y) {  // Si hay una pieza entre medias  
								rey = false;
							}
						}

					}
				}


			}

			//COMPROBACION EJE Y NEGATIVO
			if ((c.pos.y - lista[n]->posicion.y) <= 0) {
				for (float y = lista[n]->posicion.y; y >= c.pos.y; y--)
				{
					for (int i = 0; i < NCasillas * NCasillas; i++)
					{
						if (lista[i]->tipo == Piezas::TIPO::REY) {
							if (lista[i]->posicion.x == lista[n]->posicion.x && lista[i]->posicion.y == y) {  // Si hay una pieza entre medias  
								rey = false;
							}
						}

					}
				}

			}
	}
		return rey;
}
	return rey;
}

// INTENTO DE HACER EL JAQUE NO FUNCIONA BIEN
/*
bool Tablero::Jaque() {
	bool retorno = false;	int aux;
	aux = BuscaPieza(Piezas::TIPO::REY);
	for (int i = 0; i < NCasillas * NCasillas; i++) {
		if (HayPieza(i) && i!=aux) {
			for (float x = 0.0; x < 7.0; x++) {
			       for (float y = 0.0; y < 7.0; y++) {
					if (lista[i]->CheckMov({ x,y }, ComprobacionesJaque()) == true) retorno = true;
				}
			}
		}
	}
	return retorno;
}

int Tablero::ComprobacionesJaque() {
	int check = 0;
	int aux = BuscaPieza(Piezas::TIPO::REY);

	for (int i = 0; i < NCasillas * NCasillas; i++) {
		if (c.pos == lista[i]->posicion)
			if (HayPieza(i) && i != aux) { // comprobación de que hay una pieza
				if (lista[i]->color != lista[aux]->color) { // comprobación de que es de distinto color
					check = 1;
				}
				else if (lista[i]->color == lista[aux]->color) { // comprobación de que es del mismo color 
					check = 2;
				}
			}
	}
	if (ComprobacionAlfil() == false)check = 2;
	return check;
}

int Tablero::BuscaPieza(Vector posicion) {
	int aux;

	for (int i = 0; i < NCasillas * NCasillas; i++)
	{
		if (HayPieza(i) && lista[i]->posicion == posicion)aux = i;
	}
	return aux;
};

int Tablero::BuscaPieza(Piezas::TIPO t) {
	int aux;
	for (int i = 0; i < NCasillas * NCasillas; i++)
	{
		if (HayPieza(i) && lista[i]->tipo == t)aux = i;
	}
	return aux;
};




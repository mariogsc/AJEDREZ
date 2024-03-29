#include "Ajedrez.h"
#include "freeglut.h"
#include <math.h>
#include "cstdlib"

MenuInicial menuinicial;

void Ajedrez::inicializa() {
	x_ojo=5.5;
	y_ojo=4.0;
	z_ojo=12.0;
}


void Ajedrez::dibujaMenu()
{ 
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
		5.5, 4.0, 0.0,      // hacia que punto mira  
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)  

	//llamamos a la funcion dibuja de cada uno de los objetos que hemos definido en el .h
	
	menu.dibuja();

	if (menu.GetComienzo() == true) {

		ETSIDI::stopMusica();


		ColorRGB color1(0,0,0), color2(0, 0, 0);

		if (menu.GetEquipo() == 0) {
			color1.SetColor(255, 255, 255);
			color2.SetColor(0, 0, 255);	
		}
		else if (menu.GetEquipo() == 1) {
			color1.SetColor(255, 255, 255);
			color2.SetColor(255, 0, 0);
		}
		else if (menu.GetEquipo() == 2) {
			color1.SetColor(250, 189, 0); // COLOR GUALDA
			color2.SetColor(255, 0, 0);
		}

		tablero.DibujaPiezas();
		tablero.DibujaTablero(color1, color2);
		tablero.DibujaPosibles();
		//tablero.dibujaTurno();
	}
	
	
}
void Ajedrez::dibujaPartida() {
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
		5.5, 4.0, 0.0,      // hacia que punto mira  
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)  

	ETSIDI::stopMusica();


	ColorRGB color1(0, 0, 0), color2(0, 0, 0);

	if (menu.GetEquipo() == 0) {
		color1.SetColor(255, 255, 255);
		color2.SetColor(0, 0, 255);
	}
	else if (menu.GetEquipo() == 1) {
		color1.SetColor(255, 255, 255);
		color2.SetColor(255, 0, 0);
	}
	else if (menu.GetEquipo() == 2) {
		color1.SetColor(250, 189, 0); // COLOR GUALDA
		color2.SetColor(255, 0, 0);
	}

	tablero.DibujaPiezas();
	tablero.DibujaTablero(color1, color2);
	tablero.DibujaPosibles();
	tablero.dibujaTurno();
}

void Ajedrez::teclaEspecial(unsigned char key)
{
	menu.teclaEspecial(key);
}

void Ajedrez::tecla(unsigned char key)
{
	menu.tecla(key);
}

void Ajedrez::Raton(int button, int state, int x, int y) {
	

	// CONVERSIÓN DE PIXELES DE LA VENTANA A CASILLAS DEL TABLERO
	x = (x-22)/(550/8);
	y = 7-((y - 24)/(550/8));

	int columna = static_cast<int>(x );
	int fila = static_cast<int>(y );

	if (((fila >= 0) && (fila < 8)) && ((columna >= 0) && (columna < 8))) {
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
			if (tablero.turno % 2 != 0) { // Si el turno es impar -> turno blancas
				if (tablero.getPieza(columna, fila) != nullptr && tablero.getPieza(columna, fila)->getColor() == Pieza::Blanco) {

					origen.x = columna;
					origen.y = fila;
					tablero.CompruebaPosible(origen);
				}
				else ETSIDI::play("sonidos/error.wav");
			}
			else if (tablero.turno % 2 == 0) { // Si el turno es par -> turno negras
				if (tablero.getPieza(columna, fila) != nullptr && tablero.getPieza(columna, fila)->getColor() == Pieza::Negro) {
					origen.x = columna;
					origen.y = fila;
					tablero.CompruebaPosible(origen);
				}
				else ETSIDI::play("sonidos/error.wav");
			}
		}
		else if (button == GLUT_LEFT_BUTTON && state==GLUT_UP) {
			tablero.eliminarContenido();

			// Verificar que la posición de origen sea válida y haya una pieza en esa posición
			if (origen >= 0 && origen < MAX_CASILLAS && tablero.getPieza(origen) != nullptr && origen != destino) {

				// Verificar si el movimiento es válido
				destino.x = columna;
				destino.y = fila;

				if (tablero.getPieza(origen)->validarMovimiento(origen, destino, tablero)) {
					// Realizar el movimiento
					tablero.mover(origen, destino); 
					
					// Comprobación del jaque mate al equipo contrario
					//if (tablero.HayJaqueMateNegras()||tablero.HayJaqueMateBlancas())exit(0);	
				}
				else ETSIDI::play("sonidos/error.wav");
			}
			else ETSIDI::play("sonidos/error.wav");
		}
	}
}


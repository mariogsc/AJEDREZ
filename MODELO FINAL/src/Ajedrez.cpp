#include "Ajedrez.h"
#include "freeglut.h"
#include <math.h>
#include "cstdlib"
#include "ETSIDI.h"

MenuInicial menuinicial;


Ajedrez::Ajedrez() {
	Blancas->setSize(8, 8);
	Blancas->setPos(4.0, 2.0);

	Negras->setSize(8.0, 8.0);
	Negras->setPos(2.0, 2.0);

	Tablas->setSize(8.0, 8.0);
	Tablas->setPos(2.0, 2.0);

	Inicio->setSize(8.0, 8.0);
	Inicio->setPos(2.0, 2.0);

}


void Ajedrez::dibujaPausa() {


	gluLookAt(5.5, 4.0, 12.0,  // posicion del ojo
		5.5, 4.0, 0.0,      // hacia que punto mira  
		0.0, 1.0, 0.0);     // definimos hacia arriba (eje Y)



	ETSIDI::setTextColor(1, 1, 0);
	ETSIDI::setFont("fuentes/AmidoneGrotesk.ttf", 25);
	ETSIDI::printxy("PAUSA", 17, 9);
	ETSIDI::setFont("fuentes/AmidoneGrotesk.ttf", 10);
	ETSIDI::printxy("PULSE-C-(CONTINUAR)", 17, 8);
	ETSIDI::printxy("PULSE-T-(TABLAS)", 17, 7);
	ETSIDI::printxy("PULSE-S-(SALIR DEL JUEGO)", 17, 6);
	ETSIDI::printxy("PULSE-N-(MATE A NEGRAS)", 17, 5);
	ETSIDI::printxy("PULSE-B-(MATE A BLANCAS)", 17, 4);

}
void Ajedrez::dibujaTablas() {

	Tablas->draw();
}

void Ajedrez::dibujaB() {

	Blancas->draw();
}

void Ajedrez::dibujaN() {
	Negras->draw();

}
void Ajedrez::dibujaInicio() {
	Inicio->draw();

}




void Ajedrez::dibujaMenu()
{
	menu.dibuja();
}


void Ajedrez::dibujaPartida() {


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
	x = (x - 22) / (550 / 8);
	y = 7 - ((y - 24) / (550 / 8));

	int columna = static_cast<int>(x);
	int fila = static_cast<int>(y);

	if (((fila >= 0) && (fila < 8)) && ((columna >= 0) && (columna < 8))) {
		//primero se comprueban los turnos y se realizan las mismas acciones pero dependiendo del turno
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
			if (tablero.turno % 2 != 0) { // Si el turno es impar -> turno blancas
				if (tablero.getPieza(columna, fila) != nullptr && tablero.getPieza(columna, fila)->getColor() == Pieza::Blanco) {

					origen.x = columna;
					origen.y = fila;
					tablero.CompruebaPosible(origen);//comprueba los posibles movimientos de la ficha seleccionada (origen)
				}
				else ETSIDI::play("sonidos/error.wav");
			}
			else if (tablero.turno % 2 == 0) { // Si el turno es par -> turno negras
				if (tablero.getPieza(columna, fila) != nullptr && tablero.getPieza(columna, fila)->getColor() == Pieza::Negro) {
					origen.x = columna;
					origen.y = fila;
					tablero.CompruebaPosible(origen);
				}
				else ETSIDI::play("sonidos/error.wav");//si el turno seleccionado no es correcto, suena error
			}
		}
		else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
			tablero.eliminarContenido();//una vez movida la pieza se eliminan las casillas verdes

			// Verificar que la posición de origen sea válida y haya una pieza en esa posición
			if (origen >= 0 && origen < MAX_CASILLAS && tablero.getPieza(origen) != nullptr && origen != destino) {

				// Verificar si el movimiento es válido
				destino.x = columna;
				destino.y = fila;

				if (tablero.getPieza(origen)->validarMovimiento(origen, destino, tablero)) {//si el movmiento es correcto, se mueve la pieza
					// Realizar el movimiento
					tablero.mover(origen, destino);


					//en estas funciones llamamos al jaque mate, pero están comentadas ya que tardan mucho en ejecutarse
					//if (tablero.turno % 2 == 0 && tablero.HayJaqueMateNegras() == true)exit(0);
					//else if(tablero.turno%2!=0 && tablero.HayJaqueMateBlancas() == true)exit(0);

				}
				else ETSIDI::play("sonidos/error.wav");//si el movimiento no es correcto, suena error
			}
			else ETSIDI::play("sonidos/error.wav");
		}
	}
}




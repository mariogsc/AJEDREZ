
#include <Tablero.h>
#include <Piezas.h>
#include <Casilla.h>
#include"freeglut.h"



Tablero::Tablero():NPiezas(0) {
	// Primero reservamos espacio dinamico para una matriz de 8x8 casillas (tablero) 
	bool color = false;

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
	CheckPosition();
	c.DibujaCasilla(c.GetPos(),0.005);

}


// FUNCIONES PARA EL MANEJO DEL VECTOR DE PIEZAS
void Tablero::DibujaPiezas()
{
	//for (int i = 0; i < MAX_PIEZAS; i++)  // no se puede añadir hasta que se definan todas las piezas o hasta que se cree un tipo de piezas pieza vacía y se inicialice el vector
		lista[0]->Dibuja();
}

void Tablero::mueve() {
	
	//for (int i = 0; i < N_PIEZAS; i++)
		// lista[i]->mueve(v); TODAVIA NO ESTA HECHO EL POLIMORFISMO DE MOVER
	//lista[0]->mueve({ 2.0,2.0 });
	
}

bool Tablero::agregar(Piezas* p)
{
	if (NPiezas < MAX_PIEZAS)
		lista[NPiezas++] = p; 
	else
		return false; // capacidad máxima alcanzada
	return true;
}

void Tablero::inicializa() {  // inicializacion de todas las fichas e inclusión en el vector de piezas
	Peon* p1 = new Peon(Vector{ 0.5,0.5 }, Piezas::COLOR::BLANCO);
	agregar(p1);
}


void Tablero::MueveCursor(unsigned char key) {
	switch (key)
	{
	case GLUT_KEY_UP:
		c.pos.y+=1;
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
	case GLUT_KEY_F1:
		if (c.pos.x+0.5 == lista[0]->posicion.x && c.pos.y+0.5 == lista[0]->posicion.y)
		{
			lista[0]->seleccionado = true;
			lista[0]->PosibleMov();
			lista[0]->mueve();
		}
		break;
	}
}

void Tablero::CheckPosition() {
	if (c.pos.x >= 7) c.pos.x = 7;
	if (c.pos.x <= 0) c.pos.x = 0;
	if (c.pos.y >= 7) c.pos.y = 7;
	if (c.pos.y <= 0) c.pos.y = 0;
}

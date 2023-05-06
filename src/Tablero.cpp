
#include <Tablero.h>
#include <Piezas.h>
#include <Casilla.h>
#include"freeglut.h"
#include"ETSIDI.h"



Tablero::Tablero() {
	// Primero reservamos espacio dinamico para una matriz de 8x8 casillas (tablero) 
	bool color = false;
	NPiezas = 0;
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
				if (j == 1.0) {
					aux = new Peon(Vector{ i,j }, Piezas::COLOR::NEGRO);
				}
				else if (j == 6.0) {
					aux = new Peon(Vector{ i, j }, Piezas::COLOR::BLANCO);
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
	case ' ':
		for (int i = 0; i < NCasillas * NCasillas; i++)
		{
			if (c.pos.x  == lista[i]->posicion.x && c.pos.y == lista[i]->posicion.y && lista[i]->tipo !=Piezas::TIPO::NT)
			{
				lista[i]->seleccionado = true;
			}
		}
		break;
	case 13:
		for(int i=0;i< NCasillas * NCasillas;i++)
			{
				if (lista[i]->CheckMov(c.pos) == true && lista[i]->seleccionado==true) 
				{
					lista[i]->SetPos(Vector{ c.pos.x,c.pos.y });
					lista[i]->seleccionado = false;
				}
				//else (ETSIDI::play("sonidos/error.wav"));
				if(lista[i]->CheckMov(c.pos) == true) ETSIDI::play("sonidos/error.wav");
			}
		break;
	}
}


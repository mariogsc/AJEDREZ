
#include <Tablero.h>
#include <Piezas.h>
#include <Casilla.h>
#include"freeglut.h"
#include"ETSIDI.h"



Tablero::Tablero() {
	// Primero reservamos espacio dinamico para una matriz de 8x8 casillas (tablero) 
	bool color = false;
	NPiezas = 0;
	turno=1;
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
	aux =new Torre(Vector{0.0,0.0}, Piezas::COLOR::NEGRO);
	agregar(aux);
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
		if (float j = NCasillas) {
			if (float i = NCasillas) {
				aux = new Peon(Vector{ i,j }, Piezas::COLOR::NEGRO);
			}
			agregar(aux);
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
		n=Selecciona();
		break;
	case 13:
		Mueve(n);
		break;
	}
}

void Tablero::Mueve(int n) {
	bool check=false;
	int aux=0;
	Vector PosAntes = { 0.0,0.0 };
	if (n != -1) {

		// Se comprueba si donde se ha seleccionado hay una pieza del otro color
		for (int i = 0; i < NCasillas * NCasillas; i++) {
			if(lista[i]->tipo!=Piezas::TIPO::NT){ // comprobación de que hay una pieza
				// comprobación de que el color es distinto y de que la posición de la pieza coincide con la posicion en la que se quiere mover 
				if (lista[i]->posicion.x == c.pos.x && lista[i]->posicion.y == c.pos.y && lista[i]->color != lista[n]->color) {
					check = true;
					aux = i;
					PosAntes = lista[n]->posicion;
				}
			}
		}

		if (lista[n]->CheckMov(c.pos,check) == true && lista[n]->seleccionado==true) 
		{

			lista[n]->SetPos(Vector{ c.pos.x,c.pos.y });
			// Si se ha comido una pieza se elimina
			if (check) {
				ETSIDI::play("sonidos/PiezaComida.wav");
				delete lista[aux];
				lista[aux] = new NoPieza(PosAntes); // Se crea una Pieza Vacia donde estaba antes la pieza que ha comido
				// Ahora mismo se está eliminando por lo que no podría ponerse en el menú de la derecha pero si se intenta transladar va dar errores otras cosas porque en esa casilla no habra una NoPieza
			}
			turno++;
			ColocaSelector();				
		}
		else ETSIDI::play("sonidos/error.wav");
		lista[n]->seleccionado = false;
	}
		
}
	
int Tablero::Selecciona() {
	int retorno=-1;
		for ( int i = 0; i < NCasillas * NCasillas; i++)
		{
			if(lista[i]->tipo != Piezas::TIPO::NT)
			{
				if (c.pos.x == lista[i]->posicion.x && c.pos.y == lista[i]->posicion.y)
				{
					if (turno % 2 != 0 && lista[i]->color == Piezas::COLOR::NEGRO){
						
							lista[i]->seleccionado = true;
							retorno = i;
					}
					else if (turno % 2 == 0 && lista[i]->color == Piezas::COLOR::BLANCO){
						
							lista[i]->seleccionado = true;
							retorno = i;
				
					}
					else ETSIDI::play("sonidos/error.wav");
				
				}
			}
		}
		return retorno;
}

void Tablero::ColocaSelector() {
	if (turno % 2 != 0)c.pos = {0.0,0.0};
	else if (turno %2==0)c.pos = {0.0,7.0};
}

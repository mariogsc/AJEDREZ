
#include <Tablero.h>
#include"freeglut.h"
#include"ETSIDI.h"




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
				if (j == 1.0) {
					aux = new Peon(Vector{ i,j }, Piezas::COLOR::NEGRO);
				}
				else if (j == 6.0) {
					aux = new Peon(Vector{ i, j }, Piezas::COLOR::BLANCO);
				}
				else if (j == 0.0 && (i == 2.0 ||i==5.0))
				{
					aux = new Alfil(Vector{ i, j }, Piezas::COLOR::NEGRO);
				}
				else if (j == 7.0 && (i == 2.0 || i == 5.0))
				{
					aux = new Alfil(Vector{ i, j }, Piezas::COLOR::BLANCO);
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
	int aux=0;
	Vector PosAntes = { 0.0,0.0 };


		if (lista[n]->CheckMov(c.pos,ComprobacionColor(aux,PosAntes)) == true && lista[n]->seleccionado==true)
		{

			lista[n]->SetPos(Vector{ c.pos.x,c.pos.y });

			if (ComprobacionColor(aux, PosAntes)==1) {
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
				if (c.pos == lista[i]->posicion)  // Se utiliza el operador == sobrecargado
				{
					if (turno % 2 != 0 && lista[i]->color == Piezas::COLOR::NEGRO){
							lista[i]->seleccionado = true;
					}
					else if (turno % 2 == 0 && lista[i]->color == Piezas::COLOR::BLANCO){
						lista[i]->seleccionado = true;
					}
					else ETSIDI::play("sonidos/error.wav");

					retorno = i;
				}
			}
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

int Tablero::ComprobacionColor(int &aux,Vector &v) {
	int check = 0;
	// Se comprueba si donde se quiere mover hay una pieza del otro color o del mismo color

		for (int i = 0; i < NCasillas * NCasillas; i++) {

			if (HayPieza(i) && c.pos == lista[i]->posicion) { // comprobación de que hay una pieza

				if (lista[i]->color != lista[n]->color) { // comprobación de que es de distinto color
					check = 1;
					aux = i;
					v = lista[n]->posicion;
				}
				else if (lista[i]->color == lista[n]->color) { // comprobación de que es del mismo color 
					check = 2;
				}

			}
		}
		return check;
}


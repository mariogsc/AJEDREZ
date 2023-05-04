
#include <Tablero.h>
#include <Piezas.h>
#include <Casilla.h>


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
			
			casilla[columna][fila].DibujaCasilla(casilla[columna][fila].GetPos());

			
			aux.x += tam;
		}
	}

}


// FUNCIONES PARA EL MANEJO DEL VECTOR DE PIEZAS
void Tablero::DibujaPiezas()
{
	//for (int i = 0; i < MAX_PIEZAS; i++)  // no se puede añadir hasta que se definan todas las piezas o hasta que se cree un tipo de piezas pieza vacía y se inicialice el vector
		lista[0]->Dibuja();
}

void Tablero::mueve(Vector v) {
	
	//for (int i = 0; i < N_PIEZAS; i++)
		// lista[i]->mueve(v); TODAVIA NO ESTA HECHO EL POLIMORFISMO DE MOVER
	
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
	Piezas* p1 = new Peon(Vector{ 0,0 }, Piezas::COLOR::BLANCO);
	agregar(p1);
}

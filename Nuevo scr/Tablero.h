#include <ETSIDI.h>
using ETSIDI::Sprite;
#include <Casilla.h>
#include <Piezas.h>

class Tablero
{
	const int NCasillas = 8; // Creamos una constante del numero de casillas 
	Casilla** casilla; // Puntero doble de tipo casilla para recorrer las casillas
	Piezas* pieza; // Puntero de tipo Piezas para poder imprimirlas
	
public: 
	Tablero(); // Constructor por defecto de tablero

	void DibujaTablero();
	

};

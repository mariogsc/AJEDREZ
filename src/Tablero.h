#include <ETSIDI.h>
using ETSIDI::Sprite;
#include <Casilla.h>
#include <Piezas.h>
#include <ColorCasilla.h>

#define MAX_PIEZAS 32

class Tablero
{
	const int NCasillas = 8; // Creamos una constante del numero de casillas 
	Casilla** casilla; // Puntero doble de tipo casilla para recorrer las casillas
	Piezas* lista[MAX_PIEZAS]; // Puntero de tipo Piezas para poder imprimirlas
	int NPiezas;
public: 
	Tablero(); // Constructor por defecto de tablero
	void DibujaTablero(ColorCasilla color1,ColorCasilla color2);
	void DibujaPiezas();
	void mueve(Vector v); 
	void inicializa();
	bool agregar(Piezas* p);
};

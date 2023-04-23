#include <ETSIDI.h>
using ETSIDI::Sprite;

class Tablero
{
	// Variables para interacción con teclado
	
	
public: 
	Tablero();
	float x = 2.5;
	float y = 2.5;
	Sprite* GrisOscuro = new Sprite("imagenes/GrisOscuro.png", x, y, 5.2, 5.0);
	Sprite* tab = new Sprite("imagenes/Tablero.png", 0.0, 0.0, 40.0, 40.0);
	void CheckPosition(float x,float y);
};

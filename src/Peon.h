
#include <ETSIDI.h>
using ETSIDI::SpriteSequence;
#include <Piezas.h>
#include <Vector.h>

class Peon:public Piezas { //ESTO ES HERENCIA PERO TODAVIA NO LO HEMOS VISTO
protected:
	SpriteSequence ImagenPeonN{ "imagenes/PeonNegro.png", 1 };
	SpriteSequence ImagenPeonB{ "imagenes/PeonBlanco.png", 1 };
public:
	//Peon(Vector p) { posicion = p; }
	//Peon(COLOR c, Vector p) { color=c, posicion=p; } // Constructor para inicializar las variables
	Peon(Vector p, COLOR c) { posicion = p; tipo = PEON; color = c; }
	Peon(Vector p) { posicion = p; }
	void dibuja(); 
};

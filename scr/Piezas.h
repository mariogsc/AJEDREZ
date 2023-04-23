#include <ETSIDI.h>
#include <freeglut.h>
using namespace ETSIDI;
using ETSIDI::getTexture;

using ETSIDI::Sprite;

class Piezas
{
	// float Pos = -17.5; ¿porque no va? Poniendolo publico tmpc
	Sprite* ReyNegro = new Sprite("imagenes/ReyNegro.png", 2.5, 17.5, 5.0, 5.0);
	Sprite* ReyBlanco = new Sprite("imagenes/ReyBlanco.png", 2.5, -17.5, 5.0, 5.0);
	Sprite* ReinaNegro = new Sprite("imagenes/ReinaNegro.png", -2.5, 17.5, 5.0, 5.0);
	Sprite* ReinaBlanco = new Sprite("imagenes/ReinaBlanco.png", -2.5, -17.5, 5.0, 5.0);

	Sprite** TorreBlanco=new Sprite*[1];
	Sprite** TorreNegro = new Sprite * [1];
	Sprite** AlfilBlanco = new Sprite * [1];
	Sprite** AlfilNegro = new Sprite * [1];
	Sprite** CaballoBlanco = new Sprite * [1];
	Sprite** CaballoNegro = new Sprite * [1];
	Sprite** PeonNegro=new Sprite *[8];
	Sprite** PeonBlanco = new Sprite * [8];
public:
	void ImprimePiezas();
	float limite;
	
};

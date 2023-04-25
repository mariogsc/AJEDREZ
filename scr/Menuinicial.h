#include <ETSIDI.h>
using ETSIDI::Sprite;

class Mundo1
{
public: 
	void dibuja();
	void tecla(unsigned char key);

	float x_ojo=0.0;
	float y_ojo = 0.0;
	float z_ojo = 20.0;
	Sprite* menu = new Sprite("imagenes/menu1.png", 0.0, 0.0, 15.0, 15.0);
	Sprite* menu2 = new Sprite("imagenes/menu2.png", 0.0, 0.0, 15.0, 15.0);
	Sprite* menu3 = new Sprite("imagenes/menu3.png", 0.0, 0.0, 15.0, 15.0);


};


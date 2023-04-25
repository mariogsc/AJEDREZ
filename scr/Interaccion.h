#pragma once
#include <ETSIDI.h>
using ETSIDI::Sprite;

class Interaccion {
	float x = 2.5;
	float y = 2.5;
public:
	// Se puede pasar aqui el OnKeyboardDown ??
	bool Seleccion = false;
	Sprite* GrisClaro = new Sprite("imagenes/GrisClaro.png", 2.5, 2.5, 0, 0);
	Sprite* GrisOscuro = new Sprite("imagenes/GrisOscuro.png", 2.5, 2.5, 5.2, 5.0);

	void SetX(float _x);
	void SetY(float _y);
	float GetX();
	float GetY();
	void CheckPosition(float x, float y);
	void teclado(char k);
};
#pragma once

class ColorRGB
{
	unsigned char rojo;
	unsigned char azul;
	unsigned char verde;
public:
	ColorRGB(unsigned char ,unsigned char, unsigned char);
	void CheckColor(unsigned char c);
	void SetColor(unsigned char r, unsigned char a, unsigned char v);

	// FUNCIONES DE INTERFAZ
	unsigned char GetRojo() { return rojo; }
	unsigned char GetVerde() { return verde; }
	unsigned char GetAzul() { return azul; }
};


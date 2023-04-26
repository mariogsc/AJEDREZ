#pragma once
class ColorCasilla
{
	unsigned char rojo;
	unsigned char azul;
	unsigned char verde;
public:
	ColorCasilla() :rojo(0), verde(0), azul(0) {};
	void CheckColor(unsigned char c);
	void SetColor(unsigned char r, unsigned char a, unsigned char v);
};


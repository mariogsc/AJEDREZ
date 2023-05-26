#pragma once
class ColorCasilla
{
	unsigned char rojo;
	unsigned char azul;
	unsigned char verde;
public:
	ColorCasilla() :rojo(0), verde(0), azul(0) {};
	ColorCasilla(unsigned char r,unsigned char a, unsigned char v):rojo(r),azul(a),verde(v) {};
	void CheckColor(unsigned char c);
	void SetColor(unsigned char r, unsigned char a, unsigned char v);
	unsigned char GetRojo() { return rojo; }
	unsigned char GetVerde() { return verde; }
	unsigned char GetAzul() { return azul; }
};


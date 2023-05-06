#include "freeglut.h"
#include <Tablero.h>
#include <ColorCasilla.h>
#include <MenuInicial.h>
#include <Marcador.h>


#include <ETSIDI.h>
using ETSIDI::Sprite;

Tablero tablero;
ColorCasilla color1,color2;
MenuInicial menu;
Marcador marcador;

//los callback, funciones que seran llamadas automaticamente por la glut cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE

void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	
void flechas(int key, int x, int y);


int main(int argc, char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("AJEDREZ");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);
	glutSpecialFunc(flechas);

	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();

	return 0;
}


void OnDraw(void)
{
	//Borrado de la pantalla	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(5.5, 4.0, 12.0,  // posicion del ojo (se desplaza un poco en ambos ejes para que cuadre con el tamaño de la pantalla)
		5.5, 4.0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el codigo de dibujo
	

	//INTRODUCIR AQUI LAS CONDICIONES DEL MENU
	menu.dibuja();

	if (menu.GetComienzo() == true) {
		if(menu.GetEquipo()==0){
			color1.SetColor(255, 255, 255);
			color2.SetColor(0, 0, 255);
		}
		else if (menu.GetEquipo() == 1) {
			color1.SetColor(255, 255, 255);
			color2.SetColor(255, 0, 0);
		}
		else if (menu.GetEquipo() == 2) {
			color1.SetColor(250, 189, 0); // COLOR GUALDA
			color2.SetColor(255, 0, 0);
		}

		glDisable(GL_LIGHTING);
		tablero.DibujaTablero(color1,color2);
		marcador.CreaMarcador(color1,color2);
		tablero.DibujaPiezas();
		glEnable(GL_LIGHTING);
	}

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//poner aqui el código de teclado

	menu.flecha(key);

	glutPostRedisplay();
}

void flechas(int key, int x_x, int y_y) {

	menu.flecha(key);
	tablero.MueveCursor(key);
	

	glutPostRedisplay();

}

void OnTimer(int value)
{
	//poner aqui el código de animacion

	//no borrar estas lineas
	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}

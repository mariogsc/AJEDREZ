#include <Peon.h>
#include <ETSIDI.h>


	void Peon::Dibuja() {
		if (color == BLANCO) {
			glDisable(GL_LIGHTING);
			ImagenPeonB.setCenter(0, 0);
			ImagenPeonB.setSize(1, 1);
			ImagenPeonB.draw();
			glEnable(GL_LIGHTING);
		}
		else if (color == NEGRO) {
			glDisable(GL_LIGHTING);
			ImagenPeonN.setCenter(0, 0);
			ImagenPeonN.setSize(1, 1);
			ImagenPeonN.draw();
			glEnable(GL_LIGHTING);
		}
	}


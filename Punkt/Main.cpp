#include "Punkt.h"

int main(int argc, char** argv)
{
	Punkt punkt(786, 786, 100, 100);

	punkt.stworzenieOkna(argc, argv);
	punkt.inicjalizacjaGlew();
	punkt.sprawdzenieWersji();
	punkt.stworzenieVAO();
	punkt.stworzenieVBO();
	glutDisplayFunc(punkt.wyswietl);
	glutCloseFunc(punkt.usun);

	glClearColor(0.2f, 0.1f, 0.0f, 0.0f);

	glutMainLoop();

	system("PAUSE");
	return 0;
}
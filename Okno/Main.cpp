#include "Okno.h"
#include "Matrix.h"
#include "Punkt.h"

int main(int argc, char** argv)
{
	Matrix matrix(3);
	matrix.printMatrix();

	showOkno(argc, argv);
	showPunkt(argc, argv);

	system("PAUSE");
	return 0;
}

void showOkno(int argc, char** argv) {
	Okno okno(786, 1024, 100, 100);
	okno.stworzenieOkna(argc, argv);
	glutDisplayFunc(okno.wyswietl);
	okno.~Okno();

	glClearColor(1.0f, 0.8f, 0.9f, 0.0f);

	glutMainLoop();
}

void showPunkt(int argc, char** argv) {
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
}
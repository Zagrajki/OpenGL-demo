#include "common.hpp"
#include "rendering.hpp"
#include "points.hpp"
#include "size.hpp"
#include "init.hpp"
#include "keyboard.hpp"
#include "mouse.hpp"

/*
Main program entry point. The program runs in console mode.
*/
void main(void)
{
	cout << "The program presents a scene in which a three - dimensional object reflects light" << endl;
	cout << "coming from one point source, as well as a scene in which a three - dimensional object" << endl;
	cout << "reflects light coming from two sources, with each source emitting light of a different color," << endl;
	cout << "and these sources can be moved by the user by moving mouse." << endl;
	cout << "Key - function" << endl;
	printf("p - displaying an egg made of points\n");
	printf("w - displaying an egg made of lines\n");
	printf("s - displaying an egg made of triangles\n");
	printf("c - displaying a kettle\n");
	printf("z - displaying a pyramid\n");
	printf("x - displaying a triangle\n");
	printf("1 - object rotation\n");
	printf("2 - changing the camera position\n");
	printf("3 - changing the position of the light sources\n");
	printf("4 - one unmoving light source\n");
	printf("5 - two movable light sources\n");
	printf("0 - displaying coordinates of the camera and the moving light sources\n");

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(300, 300);

	glutCreateWindow("Perspective projection");

	set3Dpoints();

	glutDisplayFunc(RenderScene);
	// Specifying that the RenderScene function will be a callback function.
	// It will be called every time the window needs to be redrawn.

	glutReshapeFunc(ChangeSize);
	// For the current window, it sets the callback function responsible for resizing the window.

	MyInit();
	// MyInit() (defined above) performs any initialization necessary before rendering.

	glEnable(GL_DEPTH_TEST);
	// Enabling the mechanism for removing invisible elements of the scene.

	glutKeyboardFunc(keys);

	glutMouseFunc(Mouse);
	// Sets the callback function responsible for examining the state of the mouse.

	glutMotionFunc(Motion);
	// Sets a callback function responsible for examining mouse movement.

	glutMainLoop();
	// The function runs the skeleton of the GLUT library.

}
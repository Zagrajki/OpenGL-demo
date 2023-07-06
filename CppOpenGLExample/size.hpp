#ifndef SIZE_HPP
#define SIZE_HPP

#include "common.hpp"

/*
The function is designed to maintain constant proportions of drawn elements when the window size is changed.
The vertical and horizontal parameters(heightand width of the window)
are passed to the function each time the window size changes.
*/
void ChangeSize(GLsizei horizontal, GLsizei vertical)
{
	pix2angle = 360.0 / (float)horizontal;  // converting pixels to degrees

	glMatrixMode(GL_PROJECTION);
	// Switching the current matrix to the projection matrix

	glLoadIdentity();
	// Clearing the current matrix

	gluPerspective(70, 1.0, 1.0, 30.0);
	// Parameter setting for perspective projection

	if (horizontal <= vertical)
		glViewport(0, (vertical - horizontal) / 2, horizontal, horizontal);
	else
		glViewport((horizontal - vertical) / 2, 0, vertical, vertical);
	// Setting the size of the viewport window depending on the relationship between the height and width of the window

	glMatrixMode(GL_MODELVIEW);
	// Switches the current matrix to the model view matrix

	glLoadIdentity();
	// Clearing the current matrix

}
#endif
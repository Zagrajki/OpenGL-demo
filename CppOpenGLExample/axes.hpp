#ifndef AXES_HPP
#define AXES_HPP

#include "common.hpp"

/*
A function that draws the axes of the coordinate system.
*/
void Axes()
{

	point3  x_min = { -5.0, 0.0, 0.0 };
	point3  x_max = { 5.0, 0.0, 0.0 };
	// start and end of the x-axis image

	point3  y_min = { 0.0, -5.0, 0.0 };
	point3  y_max = { 0.0,  5.0, 0.0 };
	// start and end of the y-axis image

	point3  z_min = { 0.0, 0.0, -5.0 };
	point3  z_max = { 0.0, 0.0,  5.0 };
	//  start and end of the z-axis image

	glColor3f(1.0f, 0.0f, 0.0f);  // axis drawing color - red
	glBegin(GL_LINES); // drawing the x axis

	glVertex3fv(x_min);
	glVertex3fv(x_max);

	glEnd();

	glColor3f(0.0f, 1.0f, 0.0f);  // axis drawing color - green
	glBegin(GL_LINES);  // drawing the y axis

	glVertex3fv(y_min);
	glVertex3fv(y_max);

	glEnd();

	glColor3f(0.0f, 0.0f, 1.0f);  // axis drawing color - blue
	glBegin(GL_LINES); // drawing the z axis

	glVertex3fv(z_min);
	glVertex3fv(z_max);

	glEnd();

}
#endif
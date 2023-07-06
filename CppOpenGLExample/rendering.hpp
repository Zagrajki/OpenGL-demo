#ifndef RENDERING_HPP
#define RENDERING_HPP

#include "common.hpp"
#include "axes.hpp"
#include "egg.hpp"

/*
The function that determines what to draw (always called when the scene needs to be redrawn)
*/
void RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Cleaning the window with the current cleaning color
	glLoadIdentity();
	// Clearing the current matrix
	//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
	if (movement == 1) {
		if (status == 1)                     // if left mouse button pressed
		{
			theta[1] += delta_x * pix2angle;    // modification of the rotation angle by an angle proportional to
			theta[0] += delta_y * pix2angle;	// the difference in the position of the mouse cursor
		}
		else if (status == 2)
		{
			R += delta_y * pix2angle / 15.0;
			if (R <= 0) {
				viewAt[0] = 10 * R * cos(azymut) * cos(elewacja);
				viewAt[1] = 10 * R * sin(elewacja);
				viewAt[2] = 10 * R * sin(azymut) * cos(elewacja);
			}
			else {
				viewAt[0] = 0;
				viewAt[1] = 0;
				viewAt[2] = 0;
			}
		}
		viewer[0] = R * cos(azymut) * cos(elewacja);
		viewer[1] = R * sin(elewacja);
		viewer[2] = R * sin(azymut) * cos(elewacja);
		gluLookAt(viewer[0], viewer[1], viewer[2], viewAt[0], viewAt[1], viewAt[2], 0.0, temp, 0.0);
		Axes();
		glRotatef(theta[0], 1.0, 0.0, 0.0);  //rotate the object by a new angle
		glRotatef(theta[1], 0.0, 1.0, 0.0);  //rotate the object by a new angle
	}
	else if (movement == 2) {
		gluLookAt(viewer[0], viewer[1], viewer[2], viewAt[0], viewAt[1], viewAt[2], 0.0, temp, 0.0);
		if (status == 1) {
			azymut += delta_x * pix2angle / 30.0;
			elewacja += delta_y * pix2angle / 30.0;
			if (elewacja > 2 * MY_PI)
				elewacja = elewacja - 2 * MY_PI;
			else if (elewacja < 0)
				elewacja = elewacja + 2 * MY_PI;
			if (azymut > 2 * MY_PI)
				azymut = azymut - 2 * MY_PI;
			else if (azymut < 0)
				azymut = azymut + 2 * MY_PI;
			if (elewacja > MY_PI / 2)
				temp = -1.0;
			else
				temp = 1.0;
			if (elewacja > MY_PI + (MY_PI / 2))
				temp = 1.0;
		}
		else if (status == 2)
		{
			R += delta_y * pix2angle / 15.0;
			if (R <= 0) {
				viewAt[0] = 10 * R * cos(azymut) * cos(elewacja);
				viewAt[1] = 10 * R * sin(elewacja);
				viewAt[2] = 10 * R * sin(azymut) * cos(elewacja);
			}
			else {
				viewAt[0] = 0;
				viewAt[1] = 0;
				viewAt[2] = 0;
			}
		}
		viewer[0] = R * cos(azymut) * cos(elewacja);
		viewer[1] = R * sin(elewacja);
		viewer[2] = R * sin(azymut) * cos(elewacja);
		Axes();
		glRotatef(theta[0], 1.0, 0.0, 0.0);  //rotate the object by a new angle
		glRotatef(theta[1], 0.0, 1.0, 0.0);  //rotate the object by a new angle
	}
	else if (movement == 3) {
		gluLookAt(viewer[0], viewer[1], viewer[2], viewAt[0], viewAt[1], viewAt[2], 0.0, temp, 0.0);
		if (status == 1) {
			azymut_red += delta_x * pix2angle / 30.0;
			elewacja_red += delta_y * pix2angle / 30.0;
			if (elewacja_red > 2 * MY_PI)
				elewacja_red = elewacja_red - 2 * MY_PI;
			else if (elewacja_red < 0)
				elewacja_red = elewacja_red + 2 * MY_PI;
			if (azymut_red > 2 * MY_PI)
				azymut_red = azymut_red - 2 * MY_PI;
			else if (azymut_red < 0)
				azymut_red = azymut_red + 2 * MY_PI;
			red_light_position[0] = R_red * cos(azymut_red) * cos(elewacja_red);
			red_light_position[1] = R_red * sin(elewacja_red);
			red_light_position[2] = R_red * sin(azymut_red) * cos(elewacja_red);
			glLightfv(GL_LIGHT1, GL_POSITION, red_light_position);
		}
		else if (status == 2)
		{
			azymut_blue += delta_x * pix2angle / 30.0;
			elewacja_blue += delta_y * pix2angle / 30.0;
			if (elewacja_blue > 2 * MY_PI)
				elewacja_blue = elewacja_blue - 2 * MY_PI;
			else if (elewacja_blue < 0)
				elewacja_blue = elewacja_blue + 2 * MY_PI;
			if (azymut_blue > 2 * MY_PI)
				azymut_blue = azymut_blue - 2 * MY_PI;
			else if (azymut_blue < 0)
				azymut_blue = azymut_blue + 2 * MY_PI;
			blue_light_position[0] = R_blue * cos(azymut_blue) * cos(elewacja_blue);
			blue_light_position[1] = R_blue * sin(elewacja_blue);
			blue_light_position[2] = R_blue * sin(azymut_blue) * cos(elewacja_blue);
			glLightfv(GL_LIGHT2, GL_POSITION, blue_light_position);
		}
		Axes();
	}
	//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
	glColor3f(1.0f, 1.0f, 1.0f);
	// Set the drawing color to white

	egg();
	// Drawing the egg

	glFlush();
	// Passing drawing commands to be executed

	glutSwapBuffers();

}
#endif
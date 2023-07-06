#ifndef MOUSE_HPP
#define MOUSE_HPP

#include "common.hpp"

/*
The function "investigates" the state of the mouse and sets the values of the appropriate global variables.
*/
void Mouse(int btn, int state, int x, int y)
{
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		x_pos_old = x;
		y_pos_old = y;		//x and y, because it is supposed to react to horizontal 
							//and vertical movements when the left key is pressed
		status = 1;          // left mouse button pressed
	}
	else if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		y_pos_old = y; //only y, because the zoom is supposed to react only to vertical movements
		status = 2;
	}
	else
		status = 0;          // no key has been pressed
}

/*
The function "monitors" the position of the mouse cursor and sets the values of the appropriate global variables.
*/
void Motion(GLsizei x, GLsizei y)
{
	delta_x = x - x_pos_old;     // calculation of the difference in the position of the mouse cursor
	delta_y = y - y_pos_old;

	x_pos_old = x;            // substitute the current position as the previous one
	y_pos_old = y;

	glutPostRedisplay();     // redraw the scene
}
#endif
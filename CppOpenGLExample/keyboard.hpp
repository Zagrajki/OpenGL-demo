#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP

#include <iostream>
#include "rendering.hpp"

void keys(unsigned char key, int x, int y)
{
	if (key == 'p') model = 1;
	if (key == 'w') model = 2;
	if (key == 's') model = 3;
	if (key == 'c') model = 4; //kettle
	if (key == 'z') model = 5; //pyramid
	if (key == 'x') model = 6; //triangle
	if (key == '1') movement = 1;
	if (key == '2') movement = 2;
	if (key == '3') movement = 3;
	if (key == '4') { light = 1; glEnable(GL_LIGHT0); glDisable(GL_LIGHT1); glDisable(GL_LIGHT2); }
	if (key == '5') { light = 2; glDisable(GL_LIGHT0); glEnable(GL_LIGHT1); glEnable(GL_LIGHT2); }
	if (key == '0') {
		cout << "Kamera: " << viewer[0] << ", " << viewer[1] << ", " << viewer[2] << endl;
		cout << "Swiatlo czerwone: " << red_light_position[0] << ", " << red_light_position[1] << ", " << red_light_position[2] << endl;
		cout << "Swiatlo niebieskie: " << blue_light_position[0] << ", " << blue_light_position[1] << ", " << blue_light_position[2] << endl;
	}
	RenderScene(); // redraw the scene
}
#endif
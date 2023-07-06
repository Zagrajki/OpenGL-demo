#ifndef INIT_HPP
#define INIT_HPP

#include "common.hpp"
#include "tga.hpp"

void MyInit()
{
	/*************************************************************************************/
	// Variables for the texture image
	GLbyte* pBytes;
	GLint ImWidth, ImHeight, ImComponents;
	GLenum ImFormat;

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	// The cleaning color (window fills) is set to black

	/*************************************************************************************/

// Definition of the material the kettle is made of and the definition of the light source

/*************************************************************************************/


/*************************************************************************************/
// Definition of the material the kettle is made of

	GLfloat mat_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
	// coefficients ka =[kar,kag,kab] of ambient light

	GLfloat mat_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	// coefficients kd = [kdr,kdg,kdb] of scattered light

	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	// coefficients ks =[ksr,ksg,ksb] of reflected light 

	GLfloat mat_shininess = { 20.0 };
	// coefficient n describing the gloss of the surface

/*************************************************************************************/
// Definition of a light source

	//GLfloat light_position[] = { 0.0, 0.0, 10.0, 1.0 };
	// source location


	//GLfloat light_ambient[] = { 0.1, 0.1, 0.1, 1.0 };
	// components of the luminous intensity of the ambient light source
	// Ia = [Iar,Iag,Iab]

	//GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	// components of the luminous intensity of the light source causing diffuse reflection
	// Id = [Idr,Idg,Idb]

	//GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	// components of the luminous intensity of the light source causing directional reflection
	// Is = [Isr,Isg,Isb]

	GLfloat att_constant = { 1.0 };
	// the constant component ds for the model of changes in illumination as a function of the distance from the source

	GLfloat att_linear = { 0.05 };
	// the linear component dl for the model of changes in illumination as a function of the distance from the source

	GLfloat att_quadratic = { 0.001 };
	// the square component dq for the model of changes in illumination as a function of the distance from the source

/*************************************************************************************/
// Setting the parameters of the material and the light source

/*************************************************************************************/
// Setting the material parameters


	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);

	/*************************************************************************************/
	// Setting the source parameters
	glLightfv(GL_LIGHT0, GL_AMBIENT, basic_light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, basic_light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, basic_light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, basic_light_position);

	glLightfv(GL_LIGHT1, GL_AMBIENT, red_light_ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, red_light_diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, red_light_specular);
	glLightfv(GL_LIGHT1, GL_POSITION, red_light_position);

	glLightfv(GL_LIGHT2, GL_AMBIENT, blue_light_ambient);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, blue_light_diffuse);
	glLightfv(GL_LIGHT2, GL_SPECULAR, blue_light_specular);
	glLightfv(GL_LIGHT2, GL_POSITION, blue_light_position);

	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, att_constant);
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, att_linear);
	glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, att_quadratic);

	glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, att_constant);
	glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, att_linear);
	glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, att_quadratic);

	glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, att_constant);
	glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, att_linear);
	glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, att_quadratic);


	/*************************************************************************************/
	// Setting the scene lighting system options

	glShadeModel(GL_SMOOTH); // enabling soft shading
	glEnable(GL_LIGHTING);   // enabling scene lighting system
	if (light == 1) {
		glEnable(GL_LIGHT0);     // enabling source number 0
	}
	else {
		glEnable(GL_LIGHT1);     // enabling source number 1
		glEnable(GL_LIGHT2);     // enabling source number 2
	}
	glEnable(GL_DEPTH_TEST); // enabling the z-buffer mechanism

	/*************************************************************************************/
	// Texturing will only be done on one side of the wall
	glEnable(GL_CULL_FACE);
	/*************************************************************************************/
	//  Reading a texture image from a file named D1_t.tga
	pBytes = LoadTGAImage("D1_t.tga", &ImWidth, &ImHeight, &ImComponents, &ImFormat);
	/*************************************************************************************/
	// Defining a 2D texture
	glTexImage2D(GL_TEXTURE_2D, 0, ImComponents, ImWidth, ImHeight, 0, ImFormat, GL_UNSIGNED_BYTE, pBytes);
	/*************************************************************************************/
	// Memory release
	free(pBytes);
	/*************************************************************************************/
	// Enabling the texturing mechanism
	glEnable(GL_TEXTURE_2D);
	/*************************************************************************************/
	// Setting the texturing mode
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	/*************************************************************************************/
	// Determining how to apply textures
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	/*************************************************************************************/
}
#endif
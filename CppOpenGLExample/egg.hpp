#ifndef EGGS_HPP
#define EGGS_HPP

#include "common.hpp"

void egg() {
	// Points
	if (model == 1) {
		glBegin(GL_POINTS);
		glColor3f(1.0f, 1.0f, 0.0f);
		for (int j = 0; j < N; j++) {
			for (int i = 0; i < N; i++) {
				glVertex3f(points_in_3D[j][i].x, points_in_3D[j][i].y, points_in_3D[j][i].z);
			}
		}
		glEnd();
	}
	// Lines
	else if (model == 2) {
		glColor3f(1.0f, 1.0f, 0.0f);
		glBegin(GL_LINES);
		//horizontal
		for (int j = 0; j < N; j++) {
			int last = N - j;
			for (int i = 0; i < N - 1; i++) {
				glVertex3f(points_in_3D[j][i].x, points_in_3D[j][i].y, points_in_3D[j][i].z);
				glVertex3f(points_in_3D[j][i + 1].x, points_in_3D[j][i + 1].y, points_in_3D[j][i + 1].z);
			}
			if (j != 0) { //between the halves of the egg
				glVertex3f(points_in_3D[j][0].x, points_in_3D[j][0].y, points_in_3D[j][0].z);
				glVertex3f(points_in_3D[last][N - 1].x, points_in_3D[last][N - 1].y, points_in_3D[last][N - 1].z);
			}
		}
		//vertical
		for (int j = 0; j < N; j++) {
			int last = N - j;
			for (int i = 0; i < N; i++) {
				if (j != N - 1) {
					glVertex3f(points_in_3D[j][i].x, points_in_3D[j][i].y, points_in_3D[j][i].z);
					glVertex3f(points_in_3D[j + 1][i].x, points_in_3D[j + 1][i].y, points_in_3D[j + 1][i].z);
				}
				else { //because the point at the bottom is point [0][0]
					glVertex3f(points_in_3D[j][i].x, points_in_3D[j][i].y, points_in_3D[j][i].z);
					glVertex3f(points_in_3D[0][0].x, points_in_3D[0][0].y, points_in_3D[0][0].z);
				}
			}
		}
		//oblique
		for (int j = N / 2; j < N; j++) {
			int last = N - j;
			for (int i = 0; i < N - 1; i++) {
				if (j != N - 1) {
					glVertex3f(points_in_3D[j][i].x, points_in_3D[j][i].y, points_in_3D[j][i].z);
					glVertex3f(points_in_3D[j + 1][i + 1].x, points_in_3D[j + 1][i + 1].y, points_in_3D[j + 1][i + 1].z);
				}
				else {
					glVertex3f(points_in_3D[j][i].x, points_in_3D[j][i].y, points_in_3D[j][i].z);
					glVertex3f(points_in_3D[0][0].x, points_in_3D[0][0].y, points_in_3D[0][0].z);
				}
			}
			//between the halves of the egg
			glVertex3f(points_in_3D[j][0].x, points_in_3D[j][0].y, points_in_3D[j][0].z);
			glVertex3f(points_in_3D[last + 1][N - 1].x, points_in_3D[last + 1][N - 1].y, points_in_3D[last + 1][N - 1].z);
		}
		//last points (because after N-1 there is no next one)
		glVertex3f(points_in_3D[0][0].x, points_in_3D[0][0].y, points_in_3D[0][0].z);
		glVertex3f(points_in_3D[1][N - 1].x, points_in_3D[1][N - 1].y, points_in_3D[1][N - 1].z);

		glVertex3f(points_in_3D[0][0].x, points_in_3D[0][0].y, points_in_3D[0][0].z);
		glVertex3f(points_in_3D[N - 1][N - 1].x, points_in_3D[N - 1][N - 1].y, points_in_3D[N - 1][N - 1].z);

		for (int j = 1; j < N / 2 + 1; j++) {
			int last = N - j;
			for (int i = 0; i < N - 1; i++) {
				glVertex3f(points_in_3D[j][i].x, points_in_3D[j][i].y, points_in_3D[j][i].z);
				glVertex3f(points_in_3D[j - 1][i + 1].x, points_in_3D[j - 1][i + 1].y, points_in_3D[j - 1][i + 1].z);
			}//between the halves of the egg
			glVertex3f(points_in_3D[j][0].x, points_in_3D[j][0].y, points_in_3D[j][0].z);
			glVertex3f(points_in_3D[last - 1][N - 1].x, points_in_3D[last - 1][N - 1].y, points_in_3D[last - 1][N - 1].z);
		}
		glEnd();
	}
	//triangles
	else if (model == 3) {
		glBegin(GL_TRIANGLES);
		for (int j = N / 2; j < N; j++) {
			int last = N - j;
			for (int i = 0; i < N - 1; i++) {
				if (j != N - 1) {//walls
					//glColor3f(1.0f, 0.0f, 0.0f);
					glNormal3f(-points_in_3D[j + 1][i].Nx, -points_in_3D[j + 1][i].Ny, -points_in_3D[j + 1][i].Nz);
					glTexCoord2f(points_in_3D[j + 1][i].t1, points_in_3D[j + 1][i].t2);
					glVertex3f(points_in_3D[j + 1][i].x, points_in_3D[j + 1][i].y, points_in_3D[j + 1][i].z);
					glNormal3f(-points_in_3D[j][i].Nx, -points_in_3D[j][i].Ny, -points_in_3D[j][i].Nz);
					glTexCoord2f(points_in_3D[j][i].t1, points_in_3D[j][i].t2);
					glVertex3f(points_in_3D[j][i].x, points_in_3D[j][i].y, points_in_3D[j][i].z);
					glNormal3f(-points_in_3D[j + 1][i + 1].Nx, -points_in_3D[j + 1][i + 1].Ny, -points_in_3D[j + 1][i + 1].Nz);
					glTexCoord2f(points_in_3D[j + 1][i + 1].t1, points_in_3D[j + 1][i + 1].t2);
					glVertex3f(points_in_3D[j + 1][i + 1].x, points_in_3D[j + 1][i + 1].y, points_in_3D[j + 1][i + 1].z);

					glNormal3f(-points_in_3D[j][i].Nx, -points_in_3D[j][i].Ny, -points_in_3D[j][i].Nz);
					glTexCoord2f(points_in_3D[j][i].t1, points_in_3D[j][i].t2);
					glVertex3f(points_in_3D[j][i].x, points_in_3D[j][i].y, points_in_3D[j][i].z);
					glNormal3f(-points_in_3D[j][i + 1].Nx, -points_in_3D[j][i + 1].Ny, -points_in_3D[j][i + 1].Nz);
					glTexCoord2f(points_in_3D[j][i + 1].t1, points_in_3D[j][i + 1].t2);
					glVertex3f(points_in_3D[j][i + 1].x, points_in_3D[j][i + 1].y, points_in_3D[j][i + 1].z);
					glNormal3f(-points_in_3D[j + 1][i + 1].Nx, -points_in_3D[j + 1][i + 1].Ny, -points_in_3D[j + 1][i + 1].Nz);
					glTexCoord2f(points_in_3D[j + 1][i + 1].t1, points_in_3D[j + 1][i + 1].t2);
					glVertex3f(points_in_3D[j + 1][i + 1].x, points_in_3D[j + 1][i + 1].y, points_in_3D[j + 1][i + 1].z);
				}
				else {//down bottom (one half)
					//glNormal3f(0.0f, 1.0f, 1.0f);
					glNormal3f(-points_in_3D[j][i].Nx, -points_in_3D[j][i].Ny, -points_in_3D[j][i].Nz);
					glTexCoord2f(points_in_3D[j][i].t1, points_in_3D[j][i].t2);
					glVertex3f(points_in_3D[j][i].x, points_in_3D[j][i].y, points_in_3D[j][i].z);
					glNormal3f(-points_in_3D[j][i + 1].Nx, -points_in_3D[j][i + 1].Ny, -points_in_3D[j][i + 1].Nz);
					glTexCoord2f(points_in_3D[j][i + 1].t1, points_in_3D[j][i + 1].t2);
					glVertex3f(points_in_3D[j][i + 1].x, points_in_3D[j][i + 1].y, points_in_3D[j][i + 1].z);
					glNormal3f(-points_in_3D[0][0].Nx, -points_in_3D[0][0].Ny, -points_in_3D[0][0].Nz);
					glTexCoord2f(points_in_3D[0][0].t1, points_in_3D[0][0].t2);
					glVertex3f(points_in_3D[0][0].x, points_in_3D[0][0].y, points_in_3D[0][0].z);
				}
			}//one edge of the egg
			//glNormal3f(0.0f, 0.0f, 1.0f);
			glNormal3f(-points_in_3D[j][0].Nx, -points_in_3D[j][0].Ny, -points_in_3D[j][0].Nz);
			glTexCoord2f(points_in_3D[j][0].t1, points_in_3D[j][0].t2);
			glVertex3f(points_in_3D[j][0].x, points_in_3D[j][0].y, points_in_3D[j][0].z);
			glNormal3f(points_in_3D[last][N - 1].Nx, points_in_3D[last][N - 1].Ny, points_in_3D[last][N - 1].Nz);
			glTexCoord2f(points_in_3D[last][N - 1].t1, points_in_3D[last][N - 1].t2);
			glVertex3f(points_in_3D[last][N - 1].x, points_in_3D[last][N - 1].y, points_in_3D[last][N - 1].z);
			glNormal3f(points_in_3D[last + 1][N - 1].Nx, points_in_3D[last + 1][N - 1].Ny, points_in_3D[last + 1][N - 1].Nz);
			glTexCoord2f(points_in_3D[last + 1][N - 1].t1, points_in_3D[last + 1][N - 1].t2);
			glVertex3f(points_in_3D[last + 1][N - 1].x, points_in_3D[last + 1][N - 1].y, points_in_3D[last + 1][N - 1].z);
			if (j != N / 2) {//upper non-bottom edge of the egg
				glNormal3f(-points_in_3D[j - 1][0].Nx, -points_in_3D[j - 1][0].Ny, -points_in_3D[j - 1][0].Nz);
				glTexCoord2f(points_in_3D[j - 1][0].t1, points_in_3D[j - 1][0].t2);
				glVertex3f(points_in_3D[j - 1][0].x, points_in_3D[j - 1][0].y, points_in_3D[j - 1][0].z);
				glNormal3f(-points_in_3D[j][0].Nx, -points_in_3D[j][0].Ny, -points_in_3D[j][0].Nz);
				glTexCoord2f(points_in_3D[j][0].t1, points_in_3D[j][0].t2);
				glVertex3f(points_in_3D[j][0].x, points_in_3D[j][0].y, points_in_3D[j][0].z);
				glNormal3f(points_in_3D[last + 1][N - 1].Nx, points_in_3D[last + 1][N - 1].Ny, points_in_3D[last + 1][N - 1].Nz);
				glTexCoord2f(points_in_3D[last + 1][N - 1].t1, points_in_3D[last + 1][N - 1].t2);
				glVertex3f(points_in_3D[last + 1][N - 1].x, points_in_3D[last + 1][N - 1].y, points_in_3D[last + 1][N - 1].z);
			}
		}
		//the last edge triangles on the down bottom (because there is no next one after N-1)
		//glNormal3f(1.0f, 0.0f, 1.0f);
		glNormal3f(-points_in_3D[N - 1][0].Nx, -points_in_3D[N - 1][0].Ny, -points_in_3D[N - 1][0].Nz);
		glTexCoord2f(points_in_3D[N - 1][0].t1, points_in_3D[N - 1][0].t2);
		glVertex3f(points_in_3D[N - 1][0].x, points_in_3D[N - 1][0].y, points_in_3D[N - 1][0].z);
		glNormal3f(-points_in_3D[0][0].Nx, -points_in_3D[0][0].Ny, -points_in_3D[0][0].Nz);
		glTexCoord2f(points_in_3D[0][0].t1, points_in_3D[0][0].t2);
		glVertex3f(points_in_3D[0][0].x, points_in_3D[0][0].y, points_in_3D[0][0].z);
		glNormal3f(points_in_3D[1][N - 1].Nx, points_in_3D[1][N - 1].Ny, points_in_3D[1][N - 1].Nz);
		glTexCoord2f(points_in_3D[1][N - 1].t1, points_in_3D[1][N - 1].t2);
		glVertex3f(points_in_3D[1][N - 1].x, points_in_3D[1][N - 1].y, points_in_3D[1][N - 1].z);

		glNormal3f(points_in_3D[1][0].Nx, points_in_3D[1][0].Ny, points_in_3D[1][0].Nz);
		glTexCoord2f(points_in_3D[1][0].t1, points_in_3D[1][0].t2);
		glVertex3f(points_in_3D[1][0].x, points_in_3D[1][0].y, points_in_3D[1][0].z);
		glNormal3f(points_in_3D[0][0].Nx, points_in_3D[0][0].Ny, points_in_3D[0][0].Nz);
		glTexCoord2f(points_in_3D[0][0].t1, points_in_3D[0][0].t2);
		glVertex3f(points_in_3D[0][0].x, points_in_3D[0][0].y, points_in_3D[0][0].z);
		glNormal3f(-points_in_3D[N - 1][N - 1].Nx, -points_in_3D[N - 1][N - 1].Ny, -points_in_3D[N - 1][N - 1].Nz);
		glTexCoord2f(points_in_3D[N - 1][N - 1].t1, points_in_3D[N - 1][N - 1].t2);
		glVertex3f(points_in_3D[N - 1][N - 1].x, points_in_3D[N - 1][N - 1].y, points_in_3D[N - 1][N - 1].z);

		for (int j = 1; j < N / 2 + 1; j++) { //until N/2, because it is id
			int last = N - j;
			for (int i = 0; i < N - 1; i++) {
				if (j == 1) {//down bottom (the second half)
					//glNormal3f(0.0f, 1.0f, 1.0f);
					glNormal3f(points_in_3D[j][i].Nx, points_in_3D[j][i].Ny, points_in_3D[j][i].Nz);
					glTexCoord2f(points_in_3D[j][i].t1, points_in_3D[j][i].t2);
					glVertex3f(points_in_3D[j][i].x, points_in_3D[j][i].y, points_in_3D[j][i].z);
					glNormal3f(points_in_3D[j][i + 1].Nx, points_in_3D[j][i + 1].Ny, points_in_3D[j][i + 1].Nz);
					glTexCoord2f(points_in_3D[j][i + 1].t1, points_in_3D[j][i + 1].t2);
					glVertex3f(points_in_3D[j][i + 1].x, points_in_3D[j][i + 1].y, points_in_3D[j][i + 1].z);
					glNormal3f(points_in_3D[0][0].Nx, points_in_3D[0][0].Ny, points_in_3D[0][0].Nz);
					glTexCoord2f(points_in_3D[0][0].t1, points_in_3D[0][0].t2);
					glVertex3f(points_in_3D[0][0].x, points_in_3D[0][0].y, points_in_3D[0][0].z);
				}
				else {//walls
					//glNormal3f(1.0f, 1.0f, 1.0f);
					glNormal3f(points_in_3D[j - 1][i].Nx, points_in_3D[j - 1][i].Ny, points_in_3D[j - 1][i].Nz);
					glTexCoord2f(points_in_3D[j - 1][i].t1, points_in_3D[j - 1][i].t2);
					glVertex3f(points_in_3D[j - 1][i].x, points_in_3D[j - 1][i].y, points_in_3D[j - 1][i].z);
					glNormal3f(points_in_3D[j][i].Nx, points_in_3D[j][i].Ny, points_in_3D[j][i].Nz);
					glTexCoord2f(points_in_3D[j][i].t1, points_in_3D[j][i].t2);
					glVertex3f(points_in_3D[j][i].x, points_in_3D[j][i].y, points_in_3D[j][i].z);
					glNormal3f(points_in_3D[j - 1][i + 1].Nx, points_in_3D[j - 1][i + 1].Ny, points_in_3D[j - 1][i + 1].Nz);
					glTexCoord2f(points_in_3D[j - 1][i + 1].t1, points_in_3D[j - 1][i + 1].t2);
					glVertex3f(points_in_3D[j - 1][i + 1].x, points_in_3D[j - 1][i + 1].y, points_in_3D[j - 1][i + 1].z);

					glNormal3f(points_in_3D[j][i].Nx, points_in_3D[j][i].Ny, points_in_3D[j][i].Nz);
					glTexCoord2f(points_in_3D[j][i].t1, points_in_3D[j][i].t2);
					glVertex3f(points_in_3D[j][i].x, points_in_3D[j][i].y, points_in_3D[j][i].z);
					glNormal3f(points_in_3D[j][i + 1].Nx, points_in_3D[j][i + 1].Ny, points_in_3D[j][i + 1].Nz);
					glTexCoord2f(points_in_3D[j][i + 1].t1, points_in_3D[j][i + 1].t2);
					glVertex3f(points_in_3D[j][i + 1].x, points_in_3D[j][i + 1].y, points_in_3D[j][i + 1].z);
					glNormal3f(points_in_3D[j - 1][i + 1].Nx, points_in_3D[j - 1][i + 1].Ny, points_in_3D[j - 1][i + 1].Nz);
					glTexCoord2f(points_in_3D[j - 1][i + 1].t1, points_in_3D[j - 1][i + 1].t2);
					glVertex3f(points_in_3D[j - 1][i + 1].x, points_in_3D[j - 1][i + 1].y, points_in_3D[j - 1][i + 1].z);
				}
			}
			//edge (the second side) (for j=0 already before the loop is done)
			//glNormal3f(0.0f, 1.0f, 1.0f);
			glNormal3f(points_in_3D[j][0].Nx, points_in_3D[j][0].Ny, points_in_3D[j][0].Nz);
			glTexCoord2f(points_in_3D[j][0].t1, points_in_3D[j][0].t2);
			glVertex3f(points_in_3D[j][0].x, points_in_3D[j][0].y, points_in_3D[j][0].z);
			glNormal3f(-points_in_3D[last][N - 1].Nx, -points_in_3D[last][N - 1].Ny, -points_in_3D[last][N - 1].Nz);
			glTexCoord2f(points_in_3D[last][N - 1].t1, points_in_3D[last][N - 1].t2);
			glVertex3f(points_in_3D[last][N - 1].x, points_in_3D[last][N - 1].y, points_in_3D[last][N - 1].z);
			glNormal3f(-points_in_3D[last - 1][N - 1].Nx, -points_in_3D[last - 1][N - 1].Ny, -points_in_3D[last - 1][N - 1].Nz);
			glTexCoord2f(points_in_3D[last - 1][N - 1].t1, points_in_3D[last - 1][N - 1].t2);
			glVertex3f(points_in_3D[last - 1][N - 1].x, points_in_3D[last - 1][N - 1].y, points_in_3D[last - 1][N - 1].z);

			glNormal3f(points_in_3D[j + 1][0].Nx, points_in_3D[j + 1][0].Ny, points_in_3D[j + 1][0].Nz);
			glTexCoord2f(points_in_3D[j + 1][0].t1, points_in_3D[j + 1][0].t2);
			glVertex3f(points_in_3D[j + 1][0].x, points_in_3D[j + 1][0].y, points_in_3D[j + 1][0].z);
			glNormal3f(points_in_3D[j][0].Nx, points_in_3D[j][0].Ny, points_in_3D[j][0].Nz);
			glTexCoord2f(points_in_3D[j][0].t1, points_in_3D[j][0].t2);
			glVertex3f(points_in_3D[j][0].x, points_in_3D[j][0].y, points_in_3D[j][0].z);
			glNormal3f(-points_in_3D[last - 1][N - 1].Nx, -points_in_3D[last - 1][N - 1].Ny, -points_in_3D[last - 1][N - 1].Nz);
			glTexCoord2f(points_in_3D[last - 1][N - 1].t1, points_in_3D[last - 1][N - 1].t2);
			glVertex3f(points_in_3D[last - 1][N - 1].x, points_in_3D[last - 1][N - 1].y, points_in_3D[last - 1][N - 1].z);
		}
		glEnd();
	}
	else if (model == 4) {
		glutSolidTeapot(3.0);
	}
	else if (model == 5) {
		glBegin(GL_TRIANGLES);

		glNormal3f(0.0f, 0.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-3.0f, -6.0f, -3.0f);
		glNormal3f(0.0f, 0.0f, -1.0f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(-3.0f, 6.0f, -3.0f);
		glNormal3f(0.0f, 0.0f, -1.0f);
		glTexCoord2f(0.5f, 1.0f);
		glVertex3f(6.0f, 0.0f, -3.0f);

		N_len = N_length(-108, 0, 36);
		glNormal3f(-108.0f / N_len, 0.0f, 36.0f / N_len);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-3.0f, 6.0f, -3.0f);
		glNormal3f(-108.0f / N_len, 0.0f, 36.0f / N_len);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(-3.0f, -6.0f, -3.0f);
		glNormal3f(-108.0f / N_len, 0.0f, 36.0f / N_len);
		glTexCoord2f(0.5f, 1.0f);
		glVertex3f(0.0f, 0.0f, 6.0f);

		N_len = N_length(54, -81, 36);
		glNormal3f(54.0f / N_len, -81.0f / N_len, 36.0f / N_len);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-3.0f, -6.0f, -3.0f);
		glNormal3f(54.0f / N_len, -81.0f / N_len, 36.0f / N_len);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(6.0f, 0.0f, -3.0f);
		glNormal3f(54.0f / N_len, -81.0f / N_len, 36.0f / N_len);
		glTexCoord2f(0.5f, 1.0f);
		glVertex3f(0.0f, 0.0f, 6.0f);

		N_len = N_length(-54, -81, -36);
		glNormal3f(54.0f / N_len, 81.0f / N_len, 36.0f / N_len);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(6.0f, 0.0f, -3.0f);
		glNormal3f(54.0f / N_len, 81.0f / N_len, 36.0f / N_len);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(-3.0f, 6.0f, -3.0f);
		glNormal3f(54.0f / N_len, 81.0f / N_len, 36.0f / N_len);
		glTexCoord2f(0.5f, 1.0f);
		glVertex3f(0.0f, 0.0f, 6.0f);

		glEnd();
	}
	else if (model == 6) {
		glBegin(GL_TRIANGLES);

		glNormal3f(0.0f, 0.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-3.0f, -6.0f, 0.0f);

		glNormal3f(0.0f, 0.0f, -1.0f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(-3.0f, 6.0f, 0.0f);

		glNormal3f(0.0f, 0.0f, -1.0f);
		glTexCoord2f(0.5f, 1.0f);
		glVertex3f(6.0f, 0.0f, 0.0f);

		glEnd();
	}
}
#endif
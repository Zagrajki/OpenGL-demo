#ifndef POINTS_HPP
#define POINTS_HPP

#include "common.hpp"

inline float my_X(float u, float v) {
	return ((-90 * u * u * u * u * u + 225 * u * u * u * u - 270 * u * u * u + 180 * u * u - 45 * u) * cos(MY_PI * v));
}
inline float my_Y(float u, float v) {
	return (160 * u * u * u * u - 320 * u * u * u + 160 * u * u - 5);
}
inline float my_Z(float u, float v) {
	return ((-90 * u * u * u * u * u + 225 * u * u * u * u - 270 * u * u * u + 180 * u * u - 45 * u) * sin(MY_PI * v));
}
inline float my_Xu(float u, float v) {
	return (-450 * u * u * u * u + 900 * u * u * u - 810 * u * u + 360 * u - 45) * cos(MY_PI * v);
}
inline float my_Xv(float u, float v) {
	return MY_PI * (90 * u * u * u * u * u - 225 * u * u * u * u + 270 * u * u * u - 180 * u * u + 45 * u) * sin(MY_PI * v);
}
inline float my_Yu(float u, float v) {
	return (640 * u * u * u - 960 * u * u + 320 * u);
}
inline float my_Yv(float u, float v) {
	return 0;
}
inline float my_Zu(float u, float v) {
	return (-450 * u * u * u * u + 900 * u * u * u - 810 * u * u + 360 * u - 45) * sin(MY_PI * v);
}
inline float my_Zv(float u, float v) {
	return -MY_PI * (90 * u * u * u * u * u - 225 * u * u * u * u + 270 * u * u * u - 180 * u * u + 45 * u) * cos(MY_PI * v);
}

void set3Dpoints() {
	for (int u = 0; u < N; u++) {
		for (int v = 0; v < N; v++) {
			points_in_3D[u][v].x = my_X(u * divider, v * divider);
			points_in_3D[u][v].y = my_Y(u * divider, v * divider);
			points_in_3D[u][v].z = my_Z(u * divider, v * divider);
			points_in_3D[u][v].red = ((float)rand() / (RAND_MAX));
			points_in_3D[u][v].green = ((float)rand() / (RAND_MAX));
			points_in_3D[u][v].blue = ((float)rand() / (RAND_MAX));

			float Xu = my_Xu(u * divider, v * divider);
			float Xv = my_Xv(u * divider, v * divider);
			float Yu = my_Yu(u * divider, v * divider);
			float Yv = my_Yv(u * divider, v * divider);
			float Zu = my_Zu(u * divider, v * divider);
			float Zv = my_Zv(u * divider, v * divider);
			float Nx = (Yu * Zv - Zu * Yv);
			float Ny = (Zu * Xv - Xu * Zv);
			float Nz = (Xu * Yv - Yu * Xv);
			float Nl = N_length(Nx, Ny, Nz);
			points_in_3D[u][v].Nx = Nx / Nl;
			points_in_3D[u][v].Ny = Ny / Nl;
			points_in_3D[u][v].Nz = Nz / Nl;
			points_in_3D[u][v].t1 = u * divider;
			points_in_3D[u][v].t2 = v * divider;
		}
	}
}
#endif
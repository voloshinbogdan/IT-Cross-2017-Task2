#include "BrownianTrajectoryLib.h"

#include <random>
#include <math.h>


double fRand(double fMin, double fMax)
{
    double f = (double)std::rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}


point::point(double x, double y) {
	this->x = x;
	this->y = y;
}


point next_step(const point &from_p, double v, double delta_t, double angle) {
	double s = delta_t * v;
	double dx = s * std::cos(s);
	double dy = s * std::sin(s);
	double new_x = from_p.x + dx;
	double new_y = from_p.y + dy;
	return point(new_x, new_y);
}


std::vector<point> generate_path(double delta_t, int n, double v_max) {
	std::vector<point> path;
	path.push_back(point(0, 0));

	for (int i = 1; i < n + 1; i++) {
		double angle = fRand(0, M_PI);
		double v = fRand(0, v_max);
		path.push_back(next_step(
			path[i - 1],
			v,
			delta_t,
			angle));
	}

	return path;
}


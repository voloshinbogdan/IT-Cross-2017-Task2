#ifndef BROWNIAN_TRAJECTORY_H
#define BROWNIAN_TRAJECTORY_H

#include<vector>

class point
{
public:
	double x;
	double y;

	point(double x, double y);
}

point next_step(const point &from_p, double v, double delta_t, double angle);

std::vector<point> generate_path(double delta_t, int n, double v_max);

#endif //BROWNIAN_TRAJECTORY_H

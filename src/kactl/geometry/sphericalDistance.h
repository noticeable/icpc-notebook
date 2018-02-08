/**
 * Author: Ulf Lundstrom
 * Date: 2009-04-07
 * License: CC0
 * Source: My geometric reasoning
 * Description: Returns the shortest distance on the sphere with radius radius between the points
 *  with azimuthal angles (longitude) {\tt f1} ($\phi_1$) and {\tt f2} ($\phi_2$) from $x$ axis and zenith angles
 *  (latitude) {\tt t1} ($\theta_1$) and {\tt t2} ($\theta_2$) from $z$ axis. All angles measured in radians.
 *  The algorithm starts by converting the spherical coordinates to cartesian coordinates so
 *  if that is what you have you can use only the two last lines. $dx*radius$ is then the difference
 *  between the two points in the $x$ direction and $d*radius$ is the total distance between the points.
 * Status: somewhat tested locally, tested with Kattis problem airlinehub, to be tested with UVa 535
 */
#pragma once

double sphericalDistance(double f1, double t1,
		double f2, double t2, double radius) {
	double dx = sin(t2)*cos(f2) - sin(t1)*cos(f1);
	double dy = sin(t2)*sin(f2) - sin(t1)*sin(f1);
	double dz = cos(t2) - cos(t1);
	double d = sqrt(dx*dx + dy*dy + dz*dz);
	return radius*2*asin(d/2);
}

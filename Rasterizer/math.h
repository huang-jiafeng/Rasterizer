#ifndef MATH_H
#define MATH_H

#include "vec4.h"
#include "mat4.h"

#include <algorithm>

Mat4 transpose(Mat4 m) {
	using std::swap;
	swap(m[0][1], m[1][0]);
	swap(m[0][2], m[2][0]);
	swap(m[0][3], m[3][0]);
	swap(m[1][2], m[2][1]);
	swap(m[1][3], m[3][1]);
	swap(m[2][3], m[3][2]);
	return m;
}

#endif // !MATH_H

#include "vec4.h"
#include "mat4.h"


Vec4 Vec4::operator*(const Mat4 &M) const {
	Vec4 v;

	for (std::size_t i = 0; i < 4; ++i) {
		v.arr[i] = this->arr[0] * M[0][i] + this->arr[i] * M[1][i] + this->arr[2] * M[2][i] + this->arr[3] * M[3][i];
	}

	// May use NRVO.
	// If not£¬call Move Copy constructor of Vec4
	return v;
}







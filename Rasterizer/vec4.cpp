#include "vec4.h"
#include "mat4.h"
#include <initializer_list>
#include <algorithm>



Vec4::Vec4(std::initializer_list<float> lst) : Vec4() {
	float *item = reinterpret_cast<float*>(this);
	std::for_each(lst.begin(), lst.end(), [&item](float f) { *item++ = f; });
}



Vec4 Vec4::operator*(const Mat4 &M) const {
	Vec4 v;
	float *item = reinterpret_cast<float*>(&v);

	for (std::size_t i = 0; i < 4; ++i) {
		*item++ = this->x_ * M[0][i] + this->y_ * M[1][i] + this->z_ * M[2][i] + this->w_ * M[3][i];
	}
	return v;
}





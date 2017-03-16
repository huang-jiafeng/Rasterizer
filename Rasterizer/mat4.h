#ifndef MAT4_H
#define MAT4_H

#include <array>
#include "vec4.h"
using std::array;

class Mat4 {
public:
	Mat4();
	Mat4(array<Vec4, 4> &&vec4s);
	Mat4(const array<Vec4, 4> &vec4s);

	Mat4(const Mat4& M);
	Mat4(Mat4&& M);

	Mat4 &operator=(const Mat4 &M);
	Mat4 &operator=(Mat4 &&M);

	~Mat4() = default;

	Vec4 &operator[](size_t i);
	const Vec4 &operator[](size_t i) const;
	Mat4 operator*(const Mat4 &m) const;

private:
	array<Vec4, 4> m;
};

#endif // !MAT4_H





inline Mat4::Mat4()
	: m{ Vec4(1.0f, 0.0f, 0.0f, 0.0f),
	     Vec4(0.0f, 1.0f, 0.0f, 0.0f),
	     Vec4(0.0f, 0.0f, 1.0f, 0.0f),
	     Vec4(0.0f, 0.0f, 0.0f, 1.0f) } {}

inline Mat4::Mat4(array<Vec4, 4> &&vec4s) : m(vec4s) {}


inline Mat4::Mat4(const array<Vec4, 4> &vec4s) : m(vec4s) {}


inline Mat4::Mat4(const Mat4& M) : m(M.m) {}
inline Mat4::Mat4(Mat4&& M) : m(std::move(M.m)) {}


inline Mat4 &Mat4::operator=(const Mat4 &M) {
	this->m = M.m;
}


inline Mat4 &Mat4::operator=(Mat4 &&M) {
	this->m = std::move(M.m);
}


inline Vec4 &Mat4::operator[](size_t i) {
	if (i < m.size())
		return m[i];
}


inline const Vec4 &Mat4::operator[](size_t i) const {
	if (i < m.size())
		return m[i];
}


inline Mat4 Mat4::operator*(const Mat4 &m) const {
	Mat4 rlt;
	for (size_t i = 0; i < 4; ++i) {
		Vec4 v;
		for (size_t j = 0; j < 4; ++j) {
			v[j] = (*this)[i][0] * m[0][j] + (*this)[i][1] * m[1][j] + (*this)[i][2] * m[2][j] + (*this)[i][3] * m[3][j];
		}
		rlt[i] = v;
	}
	return rlt;
}


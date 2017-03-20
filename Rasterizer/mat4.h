#ifndef MAT4_H
#define MAT4_H

#include <array>
#include <ostream>
#include <initializer_list>
#include "vec4.h"
using std::array;

class Mat4 {
	friend std::ostream &operator<<(std::ostream &out, const Mat4 &m);
public:
	Mat4();
	Mat4(const std::initializer_list<float> &lst);
	Mat4(std::initializer_list<float> &&lst);
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
	Vec4_T operator*(const Vec4_T &v) const;
	Vec4 operator*(const Vec4 &) const = delete;

private:
	array<Vec4, 4> m;
};








inline Mat4::Mat4()
	: Mat4{ 1.0f, 0.0f, 0.0f, 0.0f,
		    0.0f, 1.0f, 0.0f, 0.0f,
		    0.0f, 0.0f, 1.0f, 0.0f,
		    0.0f, 0.0f, 0.0f, 1.0f } {}


inline Mat4::Mat4(const std::initializer_list<float> &lst)
	: m{ Vec4( *lst.begin(), *(lst.begin() + 1), *(lst.begin() + 2), *(lst.begin() + 3) ),
	     Vec4( *(lst.begin() + 4), *(lst.begin() + 5), *(lst.begin() + 6),*(lst.begin() + 7) ),
	     Vec4( *(lst.begin() + 8), *(lst.begin() + 9), *(lst.begin() + 10), *(lst.begin() + 11) ),
	     Vec4( *(lst.begin() + 12), *(lst.begin() + 13), *(lst.begin() + 14), *(lst.begin() + 15) ) } {}


inline Mat4::Mat4(std::initializer_list<float> &&lst)
	: m{ Vec4(*lst.begin(), *(lst.begin() + 1), *(lst.begin() + 2), *(lst.begin() + 3)),
		 Vec4(*(lst.begin() + 4), *(lst.begin() + 5), *(lst.begin() + 6),*(lst.begin() + 7)),
		 Vec4(*(lst.begin() + 8), *(lst.begin() + 9), *(lst.begin() + 10), *(lst.begin() + 11)),
		 Vec4(*(lst.begin() + 12), *(lst.begin() + 13), *(lst.begin() + 14), *(lst.begin() + 15)) } {}



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
	// NRVO or call move copy constructor
	return rlt;
}


inline Vec4_T Mat4::operator*(const Vec4_T &v) const {
	Vec4_T rlt;
	for (size_t i = 0; i < 4; ++i) {
		rlt[i] = (*this)[i][0] * v[0] + (*this)[i][1] * v[1] + (*this)[i][2] * v[2] + (*this)[i][3] * v[3];
	}
	// NRVO or call move copy constructor
	return rlt;
}



inline std::ostream &operator<<(std::ostream &out, const Mat4 &m) {
	for (size_t i = 0; i < 4; ++i) {
		for (size_t j = 0; j < 4; ++j)
			out << m[i][j] << "  ";
		out << "\n";
	}
	return out;
}


#endif // !MAT4_H
#ifndef VEC4_H
#define VEC4_H


#include "point.h"
#include <array>
#include <initializer_list>
using std::array;
using std::size_t;


class Mat4;

class Vec4 final {
public:
	Vec4();
	Vec4(Point3 &p, float w);
	Vec4(std::initializer_list<float> lst);
	Vec4(float x, float y, float z, float w);

	Vec4(const Vec4 &V);
	Vec4(Vec4 &&V);

	Vec4 &operator=(Vec4 V);

	~Vec4() = default;

	Vec4 operator*(const Mat4 &M) const;
	
	float &operator[](std::size_t i);
	const float operator[](std::size_t i) const;

	float x() const noexcept { return this->x_; }
	float y() const noexcept { return this->y_; }
	float z() const noexcept { return this->z_; }
	float w() const noexcept { return this->w_; }


	friend void swap(Vec4 &v1, Vec4 &v2) {
		using std::swap;
		if (&v1 == &v2) { return; }
		swap(v1.x_, v2.x_);
		swap(v1.y_, v2.y_);
		swap(v1.z_, v2.z_);
		swap(v1.w_, v2.w_);
	}
private:
	float x_;
	float y_;
	float z_;
	float w_;

	
};


inline Vec4::Vec4() : x_(0.0f), y_(0.0f), z_(0.0f), w_(0.0f) {}


inline Vec4::Vec4(Point3 &p, float w) : x_(p.p1), y_(p.p2), z_(p.p3), w_(w) {}


inline Vec4::Vec4(float x, float y, float z, float w) : x_(x), y_(y), z_(z), w_(w) {}


inline Vec4::Vec4(const Vec4 &V) : x_(V.x_), y_(V.y_), z_(V.z_), w_(V.w_) {}


inline Vec4::Vec4(Vec4 &&V) : Vec4() { swap(*this, V); }

inline Vec4 &Vec4::operator=(Vec4 V) {
	swap(*this, V);
	return *this;
}


inline float &Vec4::operator[](std::size_t i) {
	if (i < 4) {
		float *item = reinterpret_cast<float*>(this);
		return *(item + i);
	}
}


inline const float Vec4::operator[](std::size_t i) const {
	if (i < 4) {
		float *item = reinterpret_cast<float*>(const_cast<Vec4*>(this));
		return *(item + i);
	}
}





#endif // !VEC4_H

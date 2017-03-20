#ifndef VEC4_H
#define VEC4_H


#include "point.h"
#include <array>
#include <ostream>
#include <initializer_list>
#include <utility>
using std::array;
using std::size_t;


class Mat4;
class Vec4;
class Vec4_T;


class Vec4Base {
	friend Vec4;
	friend std::ostream &operator<<(std::ostream &out, const Vec4Base &v);
	friend void swap(Vec4Base &v1, Vec4Base &v2);
public:
	float x() const noexcept { return this->arr[0]; }
	float y() const noexcept { return this->arr[1]; }
	float z() const noexcept { return this->arr[2]; }
	float w() const noexcept { return this->arr[3]; }

	float &operator[](std::size_t i);
	const float operator[](std::size_t i) const;

protected:
	Vec4Base();
	Vec4Base(Point3 &p, float w);
	Vec4Base(std::initializer_list<float> lst);
	Vec4Base(float x, float y, float z, float w);

	Vec4Base(const Vec4Base &V);
	Vec4Base(Vec4Base &&V);

	Vec4Base &operator=(Vec4Base V);

	// if use pure virtual, argument type ['Vec4Base'] is not allowed. 
	virtual ~Vec4Base() = default;
	
	
private:
	array<float, 4> arr;
};


struct Vec4 final : public Vec4Base {
	// Perfect forwarding don't work with initializer_list
	Vec4(std::initializer_list<float> lst) : Vec4Base(lst) {}

	template<typename ... Args>
	Vec4(Args&& ... args) : Vec4Base(std::forward<Args>(args)...) { }


	Vec4 operator*(const Mat4 &M) const;

	~Vec4() override {};
	
	//float x, y, z, w;
};


struct Vec4_T final : Vec4Base {
	Vec4_T(std::initializer_list<float> lst) : Vec4Base(lst) {}

	template<typename ... Args>
	Vec4_T(Args&& ... args) : Vec4Base(std::forward<Args>(args)...) {}


	~Vec4_T() override {};

	//float x,
	//      y,
	//      z,
	//      w;
};






inline Vec4Base::Vec4Base() : arr{ 0.0f, 0.0f, 0.0f, 0.0f } {}

inline Vec4Base::Vec4Base(Point3 &p, float w) : arr{ p.p1, p.p2, p.p3, w } {}


inline Vec4Base::Vec4Base(std::initializer_list<float> lst) : Vec4Base() {
	std::move(lst.begin(), lst.end(), this->arr.begin());
}


inline Vec4Base::Vec4Base(float x, float y, float z, float w) : arr{ x, y, z, w } {}


inline Vec4Base::Vec4Base(const Vec4Base &V) : arr(V.arr) {}


inline Vec4Base::Vec4Base(Vec4Base &&V) : Vec4Base() { swap(*this, V); }

inline Vec4Base &Vec4Base::operator=(Vec4Base V) {
	swap(*this, V);
	return *this;
}


inline float &Vec4Base::operator[](std::size_t i) {
	return this->arr.at(i);
}


inline const float Vec4Base::operator[](std::size_t i) const {
	return this->arr.at(i);
}


inline std::ostream &operator<<(std::ostream &out, const Vec4Base &v) {
	std::copy(v.arr.begin(), v.arr.end(), std::ostream_iterator<float>(out, dynamic_cast<const Vec4_T*>(&v) ? " \n" : "  "));
	return out;
}


inline void swap(Vec4Base &v1, Vec4Base &v2) {
	using std::swap;
	if (&v1 == &v2) { return; }
	swap(v1.arr[0], v2.arr[0]);
	swap(v1.arr[1], v2.arr[1]);
	swap(v1.arr[2], v2.arr[2]);
	swap(v1.arr[3], v2.arr[3]);
}


#endif // !VEC4_H

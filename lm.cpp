#include "lm.h"
#include <math.h>



float lm::degrees2radians(float angle)
{
    return angle * lm::PIrad;
}

float lm::radians2degrees(float radians)
{
    return radians / lm::PIrad;
}


// Add operator overload for vectors
lm::vec2 lm::operator+(const lm::vec2& v1, const lm::vec2& v2) {
	return lm::vec2(v1.x + v2.x, v1.y + v2.y);
}
lm::vec3 lm::operator+(const lm::vec3& v1, const lm::vec3& v2) {
	return lm::vec3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}
lm::vec4 lm::operator+(const lm::vec4& v1, const lm::vec4& v2) {
	return lm::vec4(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w);
}

// Multiply operator overload for vectors
lm::vec2 lm::operator*(const lm::vec2& v1, const lm::vec2& v2) {
	return lm::vec2(v1.x * v2.x, v1.y * v2.y);
}
lm::vec3 lm::operator*(const lm::vec3& v1, const lm::vec3& v2) {
	return lm::vec3(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
}
lm::vec4 lm::operator*(const lm::vec4& v1, const lm::vec4& v2) {
	return lm::vec4(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z, v1.w * v2.w);
}

// Subtract operator overload for vectors
lm::vec2 lm::operator-(const lm::vec2& v1, const lm::vec2& v2) {
	return lm::vec2(v1.x - v2.x, v1.y - v2.y);
}
lm::vec3 lm::operator-(const lm::vec3& v1, const lm::vec3& v2) {
	return lm::vec3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}
lm::vec4 lm::operator-(const lm::vec4& v1, const lm::vec4& v2) {
	return lm::vec4(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w);
}

// Divide operator overload for vectors
lm::vec2 lm::operator/(const lm::vec2& v1, const lm::vec2& v2) {
	return lm::vec2(v1.x / v2.x, v1.y / v2.y);
}
lm::vec3 lm::operator/(const lm::vec3& v1, const lm::vec3& v2) {
	return lm::vec3(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z);
}
lm::vec4 lm::operator/(const lm::vec4& v1, const lm::vec4& v2) {
	return lm::vec4(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z, v1.w / v2.w);
}

// Vector operations with float
// Add operator overload
lm::vec2 lm::operator+(const float& value, const lm::vec2& vector) {
	return lm::vec2(vector.x + value, vector.y + value);
}
lm::vec3 lm::operator+(const float& value, const lm::vec3& vector) {
	return lm::vec3(vector.x + value, vector.y + value, vector.z + value);
}
lm::vec4 lm::operator+(const float& value, const lm::vec4& vector) {
	return lm::vec4(vector.x + value, vector.y + value, vector.z + value, vector.w + value);
}

// Multiply operator overload
lm::vec2 lm::operator*(const float& value, const lm::vec2& vector) {
	return lm::vec2(vector.x * value, vector.y * value);
}
lm::vec3 lm::operator*(const float& value, const lm::vec3& vector) {
	return lm::vec3(vector.x * value, vector.y * value, vector.z * value);
}
lm::vec4 lm::operator*(const float& value, const lm::vec4& vector) {
	return lm::vec4(vector.x * value, vector.y * value, vector.z * value, vector.w * value);
}

// Subtract operator overload
lm::vec2 lm::operator-(const float& value, const lm::vec2& vector) {
	return lm::vec2(vector.x - value, vector.y - value);
}
lm::vec3 lm::operator-(const float& value, const lm::vec3& vector) {
	return lm::vec3(vector.x - value, vector.y - value, vector.z - value);
}
lm::vec4 lm::operator-(const float& value, const lm::vec4& vector) {
	return lm::vec4(vector.x - value, vector.y - value, vector.z - value, vector.w - value);
}

// Divide operator overload
lm::vec2 lm::operator/(const float& value, const lm::vec2& vector) {
	return lm::vec2(vector.x / value, vector.y / value);
}
lm::vec3 lm::operator/(const float& value, const lm::vec3& vector) {
	return lm::vec3(vector.x / value, vector.y / value, vector.z / value);
}
lm::vec4 lm::operator/(const float& value, const lm::vec4& vector) {
	return lm::vec4(vector.x / value, vector.y / value, vector.z / value, vector.w / value);
}

// Negative operator overload
lm::vec2 lm::operator-(const lm::vec2& vector) {
	return lm::vec2(-vector.x, -vector.y);
}
lm::vec3 lm::operator-(const lm::vec3& vector) {
	return lm::vec3(-vector.x, -vector.y, -vector.z);
}
lm::vec4 lm::operator-(const lm::vec4& vector) {
	return lm::vec4(-vector.x, -vector.y, -vector.z, -vector.w);
}

// Compound assign operators overload
// Add
lm::vec2& lm::operator+=(lm::vec2& vector, const float& value) {
	vector.x += value;
	vector.y += value;
	return vector;
}
lm::vec3& lm::operator+=(lm::vec3& vector, const float& value) {
	vector.x += value;
	vector.y += value;
	vector.z += value;
	return vector;
}
lm::vec4& lm::operator+=(lm::vec4& vector, const float& value) {
	vector.x += value;
	vector.y += value;
	vector.z += value;
	vector.w += value;
	return vector;
}

// Multiply
lm::vec2& lm::operator*=(lm::vec2& vector, const float& value) {
	vector.x *= value;
	vector.y *= value;
	return vector;
}
lm::vec3& lm::operator*=(lm::vec3& vector, const float& value) {
	vector.x *= value;
	vector.y *= value;
	vector.z *= value;
	return vector;
}
lm::vec4& lm::operator*=(lm::vec4& vector, const float& value) {
	vector.x *= value;
	vector.y *= value;
	vector.z *= value;
	vector.w *= value;
	return vector;
}

// Subtract
lm::vec2& lm::operator-=(lm::vec2& vector, const float& value) {
	vector.x -= value;
	vector.y -= value;
	return vector;
}
lm::vec3& lm::operator-=(lm::vec3& vector, const float& value) {
	vector.x -= value;
	vector.y -= value;
	vector.z -= value;
	return vector;
}
lm::vec4& lm::operator-=(lm::vec4& vector, const float& value) {
	vector.x -= value;
	vector.y -= value;
	vector.z -= value;
	vector.w -= value;
	return vector;
}

// Divide
lm::vec2& lm::operator/=(lm::vec2& vector, const float& value) {
	vector.x /= value;
	vector.y /= value;
	return vector;
}
lm::vec3& lm::operator/=(lm::vec3& vector, const float& value) {
	vector.x /= value;
	vector.y /= value;
	vector.z /= value;
	return vector;
}
lm::vec4& lm::operator/=(lm::vec4& vector, const float& value) {
	vector.x /= value;
	vector.y /= value;
	vector.z /= value;
	vector.w /= value;
	return vector;
}

// Compound assignment with vectors
// Add
lm::vec2& lm::operator+=(lm::vec2& v1, const lm::vec2& v2) {
	v1.x += v1.x;
	v1.y += v2.y;
	return v1;
}
lm::vec3& lm::operator+=(lm::vec3& v1, const lm::vec3& v2) {
	v1.x += v1.x;
	v1.y += v2.y;
	v1.z += v2.z;
	return v1;
}
lm::vec4& lm::operator+=(lm::vec4& v1, const lm::vec4& v2) {
	v1.x += v1.x;
	v1.y += v2.y;
	v1.z += v2.z;
	v1.w += v2.w;
	return v1;
}

// Multiply
lm::vec2& lm::operator*=(lm::vec2& v1, const lm::vec2& v2) {
	v1.x *= v1.x;
	v1.y *= v2.y;
	return v1;
}
lm::vec3& lm::operator*=(lm::vec3& v1, const lm::vec3& v2) {
	v1.x *= v1.x;
	v1.y *= v2.y;
	v1.z *= v2.z;
	return v1;
}
lm::vec4& lm::operator*=(lm::vec4& v1, const lm::vec4& v2) {
	v1.x *= v1.x;
	v1.y *= v2.y;
	v1.z *= v2.z;
	v1.w *= v2.w;
	return v1;
}

// Subtract
lm::vec2& lm::operator-=(lm::vec2& v1, const lm::vec2& v2) {
	v1.x -= v1.x;
	v1.y -= v2.y;
	return v1;
}
lm::vec3& lm::operator-=(lm::vec3& v1, const lm::vec3& v2) {
	v1.x -= v1.x;
	v1.y -= v2.y;
	v1.z -= v2.z;
	return v1;
}
lm::vec4& lm::operator-=(lm::vec4& v1, const lm::vec4& v2) {
	v1.x -= v1.x;
	v1.y -= v2.y;
	v1.z -= v2.z;
	v1.w -= v2.w;
	return v1;
}

// Divide
lm::vec2& lm::operator/=(lm::vec2& v1, const lm::vec2& v2) {
	v1.x /= v1.x;
	v1.y /= v2.y;
	return v1;
}
lm::vec3& lm::operator/=(lm::vec3& v1, const lm::vec3& v2) {
	v1.x /= v1.x;
	v1.y /= v2.y;
	v1.z /= v2.z;
	return v1;
}
lm::vec4& lm::operator/=(lm::vec4& v1, const lm::vec4& v2) {
	v1.x /= v1.x;
	v1.y /= v2.y;
	v1.z /= v2.z;
	v1.w /= v2.w;
	return v1;
}

// Modulo operator overload
lm::vec2 lm::operator%(const lm::vec2& vector, const float& value)
{
	return lm::vec2(std::fmod(vector.x, value), std::fmodf(vector.y, value));
}
lm::vec3 lm::operator%(const lm::vec3& vector, const float& value)
{
	return lm::vec3(std::fmod(vector.x, value), std::fmodf(vector.y, value), std::fmod(vector.z, value));
}
lm::vec4 lm::operator%(const lm::vec4& vector, const float& value)
{
	return lm::vec4(std::fmod(vector.x, value), std::fmodf(vector.y, value), std::fmod(vector.z, value), std::fmodf(vector.w, value));
}


// Cout operator overloading for vectors
std::ostream& lm::operator<<(std::ostream& os, const lm::vec2& v) {
	os << "x = " << v.x << ", y = " << v.y;
	return os;
}
std::ostream& lm::operator<<(std::ostream& os, const lm::vec3& v) {
	os << "x = " << v.x << ", y = " << v.y << ", z = " << v.z;
	return os;
}
std::ostream& lm::operator<<(std::ostream& os, const lm::vec4& v) {
	os << "x = " << v.x << ", y = " << v.y << ", z = " << v.z << ", w = " << v.w;
	return os;
}
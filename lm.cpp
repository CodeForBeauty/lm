#include "lm.h"
#include <math.h>

using namespace lm;



float lm::degrees2radians(float angle) {
    return angle * lm::PIrad;
}

float lm::radians2degrees(float radians) {
    return radians / lm::PIrad;
}

// Dot product
float lm::dot(const vec2& v1, const vec2& v2) {
	return v1.x * v2.x + v1.y * v2.y;
}
float lm::dot(const vec3& v1, const vec3& v2) {
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}
float lm::dot(const vec4& v1, const vec4& v2) {
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
}

float lm::cross(const vec2& v1, const vec2& v2) {
	return v1.x * v2.y - v1.y * v2.x;
}

vec3 lm::cross(const vec3& v1, const vec3& v2) {
	return vec3(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x);
}

float lm::magnitude(const vec2& vector) {
	return std::sqrt(lm::dot(vector, vector));
}

float lm::magnitude(const vec3& vector) {
	return std::sqrt(lm::dot(vector, vector));
}

float lm::magnitude(const vec4& vector) {
	return std::sqrt(lm::dot(vector, vector));
}

vec2 lm::normalize(const vec2& vector) {
	return vector / magnitude(vector);
}

vec3 lm::normalize(const vec3& vector) {
	return vector / magnitude(vector);
}

vec4 lm::normalize(const vec4& vector) {
	return vector / magnitude(vector);
}

vec2 lm::vecPow(const vec2& vector, const int pow) {
	vec2 out = vector;
	for (int i = 0; i < pow - 1; i++) {
		out *= vector;
	}
	return out;
}

vec3 lm::vecPow(const vec3& vector, const int pow) {
	vec3 out = vector;
	for (int i = 0; i < pow - 1; i++) {
		out *= vector;
	}
	return out;
}

vec4 lm::vecPow(const vec4& vector, const int pow) {
	vec4 out = vector;
	for (int i = 0; i < pow - 1; i++) {
		out *= vector;
	}
	return out;
}

vec2 lm::vecSqrt(const vec2& vector) {
	return vec2(std::sqrt(vector.x), std::sqrt(vector.y));
}

vec3 lm::vecSqrt(const vec3& vector) {
	return vec3(std::sqrt(vector.x), std::sqrt(vector.y), std::sqrt(vector.z));
}

vec4 lm::vecSqrt(const vec4& vector) {
	return vec4(std::sqrt(vector.x), std::sqrt(vector.y), std::sqrt(vector.z), std::sqrt(vector.w));
}



// Add operator overload for vectors
vec2 lm::operator+(const vec2& v1, const vec2& v2) {
	return vec2(v1.x + v2.x, v1.y + v2.y);
}
vec3 lm::operator+(const vec3& v1, const vec3& v2) {
	return vec3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}
vec4 lm::operator+(const vec4& v1, const vec4& v2) {
	return vec4(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w);
}

// Multiply operator overload for vectors
vec2 lm::operator*(const vec2& v1, const vec2& v2) {
	return vec2(v1.x * v2.x, v1.y * v2.y);
}
vec3 lm::operator*(const vec3& v1, const vec3& v2) {
	return vec3(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
}
vec4 lm::operator*(const vec4& v1, const vec4& v2) {
	return vec4(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z, v1.w * v2.w);
}

// Subtract operator overload for vectors
vec2 lm::operator-(const vec2& v1, const vec2& v2) {
	return vec2(v1.x - v2.x, v1.y - v2.y);
}
vec3 lm::operator-(const vec3& v1, const vec3& v2) {
	return vec3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}
vec4 lm::operator-(const vec4& v1, const vec4& v2) {
	return vec4(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w);
}

// Divide operator overload for vectors
vec2 lm::operator/(const vec2& v1, const vec2& v2) {
	return vec2(v1.x / v2.x, v1.y / v2.y);
}
vec3 lm::operator/(const vec3& v1, const vec3& v2) {
	return vec3(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z);
}
vec4 lm::operator/(const vec4& v1, const vec4& v2) {
	return vec4(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z, v1.w / v2.w);
}

// Vector operations with float
// Add operator overload
vec2 lm::operator+(const float& value, const vec2& vector) {
	return vec2(vector.x + value, vector.y + value);
}
vec3 lm::operator+(const float& value, const vec3& vector) {
	return vec3(vector.x + value, vector.y + value, vector.z + value);
}
vec4 lm::operator+(const float& value, const vec4& vector) {
	return vec4(vector.x + value, vector.y + value, vector.z + value, vector.w + value);
}

// Multiply operator overload
vec2 lm::operator*(const float& value, const vec2& vector) {
	return vec2(vector.x * value, vector.y * value);
}
vec3 lm::operator*(const float& value, const vec3& vector) {
	return vec3(vector.x * value, vector.y * value, vector.z * value);
}
vec4 lm::operator*(const float& value, const vec4& vector) {
	return vec4(vector.x * value, vector.y * value, vector.z * value, vector.w * value);
}

// Subtract operator overload
vec2 lm::operator-(const float& value, const vec2& vector) {
	return vec2(vector.x - value, vector.y - value);
}
vec3 lm::operator-(const float& value, const vec3& vector) {
	return vec3(vector.x - value, vector.y - value, vector.z - value);
}
vec4 lm::operator-(const float& value, const vec4& vector) {
	return vec4(vector.x - value, vector.y - value, vector.z - value, vector.w - value);
}

// Divide operator overload
vec2 lm::operator/(const float& value, const vec2& vector) {
	return vec2(vector.x / value, vector.y / value);
}
vec3 lm::operator/(const float& value, const vec3& vector) {
	return vec3(vector.x / value, vector.y / value, vector.z / value);
}
vec4 lm::operator/(const float& value, const vec4& vector) {
	return vec4(vector.x / value, vector.y / value, vector.z / value, vector.w / value);
}

// Negative operator overload
vec2 lm::operator-(const vec2& vector) {
	return vec2(-vector.x, -vector.y);
}
vec3 lm::operator-(const vec3& vector) {
	return vec3(-vector.x, -vector.y, -vector.z);
}
vec4 lm::operator-(const vec4& vector) {
	return vec4(-vector.x, -vector.y, -vector.z, -vector.w);
}

// Compound assign operators overload
// Add
vec2& lm::operator+=(vec2& vector, const float& value) {
	vector.x += value;
	vector.y += value;
	return vector;
}
vec3& lm::operator+=(vec3& vector, const float& value) {
	vector.x += value;
	vector.y += value;
	vector.z += value;
	return vector;
}
vec4& lm::operator+=(vec4& vector, const float& value) {
	vector.x += value;
	vector.y += value;
	vector.z += value;
	vector.w += value;
	return vector;
}

// Multiply
vec2& lm::operator*=(vec2& vector, const float& value) {
	vector.x *= value;
	vector.y *= value;
	return vector;
}
vec3& lm::operator*=(vec3& vector, const float& value) {
	vector.x *= value;
	vector.y *= value;
	vector.z *= value;
	return vector;
}
vec4& lm::operator*=(vec4& vector, const float& value) {
	vector.x *= value;
	vector.y *= value;
	vector.z *= value;
	vector.w *= value;
	return vector;
}

// Subtract
vec2& lm::operator-=(vec2& vector, const float& value) {
	vector.x -= value;
	vector.y -= value;
	return vector;
}
vec3& lm::operator-=(vec3& vector, const float& value) {
	vector.x -= value;
	vector.y -= value;
	vector.z -= value;
	return vector;
}
vec4& lm::operator-=(vec4& vector, const float& value) {
	vector.x -= value;
	vector.y -= value;
	vector.z -= value;
	vector.w -= value;
	return vector;
}

// Divide
vec2& lm::operator/=(vec2& vector, const float& value) {
	vector.x /= value;
	vector.y /= value;
	return vector;
}
vec3& lm::operator/=(vec3& vector, const float& value) {
	vector.x /= value;
	vector.y /= value;
	vector.z /= value;
	return vector;
}
vec4& lm::operator/=(vec4& vector, const float& value) {
	vector.x /= value;
	vector.y /= value;
	vector.z /= value;
	vector.w /= value;
	return vector;
}

// Compound assignment with vectors
// Add
vec2& lm::operator+=(vec2& v1, const vec2& v2) {
	v1.x += v2.x;
	v1.y += v2.y;
	return v1;
}
vec3& lm::operator+=(vec3& v1, const vec3& v2) {
	v1.x += v2.x;
	v1.y += v2.y;
	v1.z += v2.z;
	return v1;
}
vec4& lm::operator+=(vec4& v1, const vec4& v2) {
	v1.x += v2.x;
	v1.y += v2.y;
	v1.z += v2.z;
	v1.w += v2.w;
	return v1;
}

// Multiply
vec2& lm::operator*=(vec2& v1, const vec2& v2) {
	v1.x *= v2.x;
	v1.y *= v2.y;
	return v1;
}
vec3& lm::operator*=(vec3& v1, const vec3& v2) {
	v1.x *= v2.x;
	v1.y *= v2.y;
	v1.z *= v2.z;
	return v1;
}
vec4& lm::operator*=(vec4& v1, const vec4& v2) {
	v1.x *= v2.x;
	v1.y *= v2.y;
	v1.z *= v2.z;
	v1.w *= v2.w;
	return v1;
}

// Subtract
vec2& lm::operator-=(vec2& v1, const vec2& v2) {
	v1.x -= v2.x;
	v1.y -= v2.y;
	return v1;
}
vec3& lm::operator-=(vec3& v1, const vec3& v2) {
	v1.x -= v2.x;
	v1.y -= v2.y;
	v1.z -= v2.z;
	return v1;
}
vec4& lm::operator-=(vec4& v1, const vec4& v2) {
	v1.x -= v2.x;
	v1.y -= v2.y;
	v1.z -= v2.z;
	v1.w -= v2.w;
	return v1;
}

// Divide
vec2& lm::operator/=(vec2& v1, const vec2& v2) {
	v1.x /= v2.x;
	v1.y /= v2.y;
	return v1;
}
vec3& lm::operator/=(vec3& v1, const vec3& v2) {
	v1.x /= v2.x;
	v1.y /= v2.y;
	v1.z /= v2.z;
	return v1;
}
vec4& lm::operator/=(vec4& v1, const vec4& v2) {
	v1.x /= v2.x;
	v1.y /= v2.y;
	v1.z /= v2.z;
	v1.w /= v2.w;
	return v1;
}

// Modulo operator overload
vec2 lm::operator%(const vec2& vector, const float& value)
{
	return vec2(std::fmod(vector.x, value), std::fmodf(vector.y, value));
}
vec3 lm::operator%(const vec3& vector, const float& value)
{
	return vec3(std::fmod(vector.x, value), std::fmodf(vector.y, value), std::fmod(vector.z, value));
}
vec4 lm::operator%(const vec4& vector, const float& value)
{
	return vec4(std::fmod(vector.x, value), std::fmodf(vector.y, value), std::fmod(vector.z, value), std::fmodf(vector.w, value));
}


// Cout operator overloading for vectors
std::ostream& lm::operator<<(std::ostream& os, const vec2& v) {
	os << "x = " << v.x << ", y = " << v.y;
	return os;
}
std::ostream& lm::operator<<(std::ostream& os, const vec3& v) {
	os << "x = " << v.x << ", y = " << v.y << ", z = " << v.z;
	return os;
}
std::ostream& lm::operator<<(std::ostream& os, const vec4& v) {
	os << "x = " << v.x << ", y = " << v.y << ", z = " << v.z << ", w = " << v.w;
	return os;
}
#pragma once
#include <iostream>


namespace lm {
	const float PI = 3.141592653589793;
	const float E = 2.718281828459045;
	const float PIrad = PI / 180;


	float degrees2radians(float angle);
	float radians2degrees(float radians);

	struct vec2 {
	private:
		float* ptr;
	public:
		float x, y;
		vec2() {
			x = 0; y = 0;
			ptr = &x;
		}
		vec2(float value) {
			x = value; y = value;
			ptr = &x;
		}
		vec2(float xVal, float yVal) {
			x = xVal; y = yVal;
			ptr = &x;
		}

		float& operator[] (int idx) {
			if (idx > 1) {
				std::cerr << "vec2: Index out of range 0-1." << std::endl;
				throw std::out_of_range("Index out of range 0-1.");
			}
			return ptr[idx];
		}

		vec2& operator=(vec2 v) {
			x = v.x;
			y = v.y;
			return *this;
		}
		vec2& operator=(float v) {
			x = v;
			y = v;
			return *this;
		}

		vec2& operator++(int) {
			x++;
			y++;
			return *this;
		}
		vec2& operator--(int) {
			x--;
			y--;
			return *this;
		}
	};
	struct vec3 {
	private:
		float* ptr;
	public:
		float x, y, z;
		vec3() {
			x = 0; y = 0; z = 0;
			ptr = &x;
		}
		vec3(float value) {
			x = value; y = value; z = value;
			ptr = &x;
		}
		vec3(float xVal, float yVal) {
			x = xVal; y = yVal; z = 0;
			ptr = &x;
		}
		vec3(float xVal, float yVal, float zVal) {
			x = xVal; y = yVal; z = zVal;
			ptr = &x;
		}
		vec3(const vec2& v) {
			x = v.x; y = v.y; z = 0;
			ptr = &x;
		}

		float& operator[] (int idx) {
			if (idx > 2) {
				std::cerr << "vec3: Index out of range 0-2." << std::endl;
				throw std::out_of_range("Index out of range 0-2.");
			}
			return ptr[idx];
		}

		vec3& operator=(vec2 v) {
			x = v.x;
			y = v.y;
			return *this;
		}
		vec3& operator=(vec3 v) {
			x = v.x;
			y = v.y;
			z = v.z;
			return *this;
		}
		vec3& operator=(float v) {
			x = v;
			y = v;
			z = v;
			return *this;
		}

		vec3& operator++(int) {
			x++;
			y++;
			z++;
			return *this;
		}
		vec3& operator--(int) {
			x--;
			y--;
			z--;
			return *this;
		}
	};
	struct vec4 {
	private:
		float* ptr;
	public:
		float x, y, z, w;
		vec4() {
			x = 0; y = 0; z = 0; w = 0;
			ptr = &x;
		}
		vec4(float value) {
			x = value; y = value; z = value; w = value;
			ptr = &x;
		}
		vec4(float xVal, float yVal) {
			x = xVal; y = yVal; z = 0; w = 0;
			ptr = &x;
		}
		vec4(float xVal, float yVal, float zVal) {
			x = xVal; y = yVal; z = zVal; w = 0;
			ptr = &x;
		}
		vec4(float xVal, float yVal, float zVal, float wVal) {
			x = xVal; y = yVal; z = zVal; w = wVal;
			ptr = &x;
		}
		vec4(const vec2& v) {
			x = v.x; y = v.y; z = 0; w = 0;
			ptr = &x;
		}
		vec4(const vec3& v) {
			x = v.x; y = v.y; z = v.z; w = 0;
			ptr = &x;
		}

		float& operator[] (int idx) {
			if (idx > 3) {
				std::cerr << "vec4: Index out of range 0-3." << std::endl;
				throw std::out_of_range("Index out of range 0-3.");
			}
			return ptr[idx];
		}

		vec4& operator=(vec2 v) {
			x = v.x;
			y = v.y;
			return *this;
		}
		vec4& operator=(vec3 v) {
			x = v.x;
			y = v.y;
			z = v.z;
			return *this;
		}
		vec4& operator=(vec4 v) {
			x = v.x;
			y = v.y;
			z = v.z;
			w = v.w;
			return *this;
		}
		vec4& operator=(float v) {
			x = v;
			y = v;
			z = v;
			w = v;
			return *this;
		}

		vec4& operator++(int) {
			x++;
			y++;
			z++;
			w++;
			return *this;
		}
		vec4& operator--(int) {
			x--;
			y--;
			z--;
			w--;
			return *this;
		}
	};

	// Vector math functions
	// Dot product
	float dot(const vec2& v1, const vec2& v2);
	float dot(const vec3& v1, const vec3& v2);
	float dot(const vec4& v1, const vec4& v2);
	
	// Cross product
	float cross(const vec2& v1, const vec2& v2);
	vec3 cross(const vec3& v1, const vec3& v2);

	// Magnitude
	float magnitude(const vec2& vector);
	float magnitude(const vec3& vector);
	float magnitude(const vec4& vector);

	// Normalize
	vec2 normalize(const vec2& vector);
	vec3 normalize(const vec3& vector);
	vec4 normalize(const vec4& vector);

	// Power
	vec2 vecPow(const vec2& vector, const int pow);
	vec3 vecPow(const vec3& vector, const int pow);
	vec4 vecPow(const vec4& vector, const int pow);

	// Square root
	vec2 vecSqrt(const vec2& vector);
	vec3 vecSqrt(const vec3& vector);
	vec4 vecSqrt(const vec4& vector);


	// Add operator overload for vectors
	vec2 operator+(const vec2& v1, const vec2& v2);
	vec3 operator+(const vec3& v1, const vec3& v2);
	vec4 operator+(const vec4& v1, const vec4& v2);

	// Multiply operator overload for vectors
	vec2 operator*(const vec2& v1, const vec2& v2);
	vec3 operator*(const vec3& v1, const vec3& v2);
	vec4 operator*(const vec4& v1, const vec4& v2);

	// Subtract operator overload for vectors
	vec2 operator-(const vec2& v1, const vec2& v2);
	vec3 operator-(const vec3& v1, const vec3& v2);
	vec4 operator-(const vec4& v1, const vec4& v2);

	// Divide operator overload for vectors
	vec2 operator/(const vec2& v1, const vec2& v2);
	vec3 operator/(const vec3& v1, const vec3& v2);
	vec4 operator/(const vec4& v1, const vec4& v2);

	// Vector operations with float
	// Add operator overload
	vec2 operator+(const float& value, const vec2& vector);
	vec3 operator+(const float& value, const vec3& vector);
	vec4 operator+(const float& value, const vec4& vector);

	// Multiply operator overload
	vec2 operator*(const float& value, const vec2& vector);
	vec3 operator*(const float& value, const vec3& vector);
	vec4 operator*(const float& value, const vec4& vector);

	// Subtract operator overload
	vec2 operator-(const float& value, const vec2& vector);
	vec3 operator-(const float& value, const vec3& vector);
	vec4 operator-(const float& value, const vec4& vector);

	// Divide operator overload
	vec2 operator/(const float& value, const vec2& vector);
	vec3 operator/(const float& value, const vec3& vector);
	vec4 operator/(const float& value, const vec4& vector);

	// Negative operator overload
	vec2 operator-(const vec2& vector);
	vec3 operator-(const vec3& vector);
	vec4 operator-(const vec4& vector);

	// Compound assign operators overload
	// Add
	vec2& operator+=(vec2& vector, const float& value);
	vec3& operator+=(vec3& vector, const float& value);
	vec4& operator+=(vec4& vector, const float& value);

	// Multiply
	vec2& operator*=(vec2& vector, const float& value);
	vec3& operator*=(vec3& vector, const float& value);
	vec4& operator*=(vec4& vector, const float& value);

	// Subtract
	vec2& operator-=(vec2& vector, const float& value);
	vec3& operator-=(vec3& vector, const float& value);
	vec4& operator-=(vec4& vector, const float& value);

	// Divide
	vec2& operator/=(vec2& vector, const float& value);
	vec3& operator/=(vec3& vector, const float& value);
	vec4& operator/=(vec4& vector, const float& value);

	// Compound assignment with vectors
	// Add
	vec2& operator+=(vec2& v1, const vec2& v2);
	vec3& operator+=(vec3& v1, const vec3& v2);
	vec4& operator+=(vec4& v1, const vec4& v2);

	// Multiply
	vec2& operator*=(vec2& v1, const vec2& v2);
	vec3& operator*=(vec3& v1, const vec3& v2);
	vec4& operator*=(vec4& v1, const vec4& v2);

	// Subtract
	vec2& operator-=(vec2& v1, const vec2& v2);
	vec3& operator-=(vec3& v1, const vec3& v2);
	vec4& operator-=(vec4& v1, const vec4& v2);

	// Divide
	vec2& operator/=(vec2& v1, const vec2& v2);
	vec3& operator/=(vec3& v1, const vec3& v2);
	vec4& operator/=(vec4& v1, const vec4& v2);

	// Modulo operator overload
	vec2 operator%(const vec2& vector, const float& value);
	vec3 operator%(const vec3& vector, const float& value);
	vec4 operator%(const vec4& vector, const float& value);

	// Cout operator overloading for vectors
	std::ostream& operator<<(std::ostream& os, const vec2& v);
	std::ostream& operator<<(std::ostream& os, const vec3& v);
	std::ostream& operator<<(std::ostream& os, const vec4& v);
}
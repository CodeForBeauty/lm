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

	lm::vec2 operator+(const lm::vec2& v1, const lm::vec2& v2);
	lm::vec3 operator+(const lm::vec3& v1, const lm::vec3& v2);
	lm::vec4 operator+(const lm::vec4& v1, const lm::vec4& v2);

	// Multiply operator overload for vectors
	lm::vec2 operator*(const lm::vec2& v1, const lm::vec2& v2);
	lm::vec3 operator*(const lm::vec3& v1, const lm::vec3& v2);
	lm::vec4 operator*(const lm::vec4& v1, const lm::vec4& v2);

	// Subtract operator overload for vectors
	lm::vec2 operator-(const lm::vec2& v1, const lm::vec2& v2);
	lm::vec3 operator-(const lm::vec3& v1, const lm::vec3& v2);
	lm::vec4 operator-(const lm::vec4& v1, const lm::vec4& v2);

	// Divide operator overload for vectors
	lm::vec2 operator/(const lm::vec2& v1, const lm::vec2& v2);
	lm::vec3 operator/(const lm::vec3& v1, const lm::vec3& v2);
	lm::vec4 operator/(const lm::vec4& v1, const lm::vec4& v2);

	// Vector operations with float
	// Add operator overload
	lm::vec2 operator+(const float& value, const lm::vec2& vector);
	lm::vec3 operator+(const float& value, const lm::vec3& vector);
	lm::vec4 operator+(const float& value, const lm::vec4& vector);

	// Multiply operator overload
	lm::vec2 operator*(const float& value, const lm::vec2& vector);
	lm::vec3 operator*(const float& value, const lm::vec3& vector);
	lm::vec4 operator*(const float& value, const lm::vec4& vector);

	// Subtract operator overload
	lm::vec2 operator-(const float& value, const lm::vec2& vector);
	lm::vec3 operator-(const float& value, const lm::vec3& vector);
	lm::vec4 operator-(const float& value, const lm::vec4& vector);

	// Divide operator overload
	lm::vec2 operator/(const float& value, const lm::vec2& vector);
	lm::vec3 operator/(const float& value, const lm::vec3& vector);
	lm::vec4 operator/(const float& value, const lm::vec4& vector);

	// Negative operator overload
	lm::vec2 operator-(const lm::vec2& vector);
	lm::vec3 operator-(const lm::vec3& vector);
	lm::vec4 operator-(const lm::vec4& vector);

	// Compound assign operators overload
	// Add
	lm::vec2& operator+=(lm::vec2& vector, const float& value);
	lm::vec3& operator+=(lm::vec3& vector, const float& value);
	lm::vec4& operator+=(lm::vec4& vector, const float& value);

	// Multiply
	lm::vec2& operator*=(lm::vec2& vector, const float& value);
	lm::vec3& operator*=(lm::vec3& vector, const float& value);
	lm::vec4& operator*=(lm::vec4& vector, const float& value);

	// Subtract
	lm::vec2& operator-=(lm::vec2& vector, const float& value);
	lm::vec3& operator-=(lm::vec3& vector, const float& value);
	lm::vec4& operator-=(lm::vec4& vector, const float& value);

	// Divide
	lm::vec2& operator/=(lm::vec2& vector, const float& value);
	lm::vec3& operator/=(lm::vec3& vector, const float& value);
	lm::vec4& operator/=(lm::vec4& vector, const float& value);

	// Compound assignment with vectors
	// Add
	lm::vec2& operator+=(lm::vec2& v1, const lm::vec2& v2);
	lm::vec3& operator+=(lm::vec3& v1, const lm::vec3& v2);
	lm::vec4& operator+=(lm::vec4& v1, const lm::vec4& v2);

	// Multiply
	lm::vec2& operator*=(lm::vec2& v1, const lm::vec2& v2);
	lm::vec3& operator*=(lm::vec3& v1, const lm::vec3& v2);
	lm::vec4& operator*=(lm::vec4& v1, const lm::vec4& v2);

	// Subtract
	lm::vec2& operator-=(lm::vec2& v1, const lm::vec2& v2);
	lm::vec3& operator-=(lm::vec3& v1, const lm::vec3& v2);
	lm::vec4& operator-=(lm::vec4& v1, const lm::vec4& v2);

	// Divide
	lm::vec2& operator/=(lm::vec2& v1, const lm::vec2& v2);
	lm::vec3& operator/=(lm::vec3& v1, const lm::vec3& v2);
	lm::vec4& operator/=(lm::vec4& v1, const lm::vec4& v2);

	// Modulo operator overload
	vec2 operator%(const vec2& vector, const float& value);
	vec3 operator%(const vec3& vector, const float& value);
	vec4 operator%(const vec4& vector, const float& value);

	// Cout operator overloading for vectors
	std::ostream& operator<<(std::ostream& os, const lm::vec2& v);
	std::ostream& operator<<(std::ostream& os, const lm::vec3& v);
	std::ostream& operator<<(std::ostream& os, const lm::vec4& v);
}
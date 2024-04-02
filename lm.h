#pragma once
#include <iostream>


namespace lm {
	// Constant variables
	const float PI = 3.141592653589793;
	const float E = 2.718281828459045;
	const float PIrad = PI / 180;

	// Converting euler degrees and radians
	float degrees2radians(float angle);
	float radians2degrees(float radians);

	// Vector types
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
				std::cerr << "vec2: Index out of range 0-2." << std::endl;
				throw std::out_of_range("Index out of range 0-2.");
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

		vec2 cutVec2() {
			return { x, y };
		}

		float& operator[] (int idx) {
			if (idx > 2) {
				std::cerr << "vec3: Index out of range 0-3." << std::endl;
				throw std::out_of_range("Index out of range 0-3.");
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

		vec2 cutVec2() {
			return { x, y };
		}
		vec3 cutVec3() {
			return { x, y, z };
		}

		float& operator[] (int idx) {
			if (idx > 3) {
				std::cerr << "vec4: Index out of range 0-4." << std::endl;
				throw std::out_of_range("Index out of range 0-4.");
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


	// Matrix types
	// Square matricies
	struct mat2x2 {
	private:
		vec2* ptr;
	public:
		vec2 x, y;

		mat2x2() {
			x = {}; y = {};
			ptr = &x;
		}
		mat2x2(const vec2& x1, const vec2& y1) {
			x = x1; y = y1;
			ptr = &x;
		}

		vec2 column(int idx) {
			return vec2(x[idx], y[idx]);
		}


		mat2x2& operator=(const mat2x2& value) {
			x = value.x;
			y = value.y;
			return *this;
		}

		vec2& operator[] (int idx) {
			if (idx > 1) {
				std::cerr << "vec4: Index out of range 0-2." << std::endl;
				throw std::out_of_range("Index out of range 0-2.");
			}
			return ptr[idx];
		}
	};
	struct mat3x3 {
	private:
		vec3* ptr;
	public:
		vec3 x, y, z;

		mat3x3() {
			x = {}; y = {}; z = {};
			ptr = &x;
		}
		mat3x3(const mat2x2& value) {
			x = value.x; y = value.y; z = {};
			ptr = &x;
		}
		mat3x3(vec3 x1, vec3 y1, vec3 z1) {
			x = x1; y = y1; z = z1;
			ptr = &x;
		}


		vec3 column(int idx) {
			return vec3(x[idx], y[idx], z[idx]);
		}


		mat3x3& operator=(const mat3x3& value) {
			x = value.x;
			y = value.y;
			z = value.z;
			return *this;
		}
		mat3x3& operator=(const mat2x2& value) {
			x = value.x;
			y = value.y;
			return *this;
		}

		vec3& operator[] (int idx) {
			if (idx > 2) {
				std::cerr << "vec4: Index out of range 0-3." << std::endl;
				throw std::out_of_range("Index out of range 0-3.");
			}
			return ptr[idx];
		}
	};
	struct mat4x4 {
	private:
		vec4* ptr;
	public:
		vec4 x, y, z, w;

		mat4x4() {
			x = {}; y = {}; z = {}; w = {};
			ptr = &x;
		}
		mat4x4(const mat2x2& value) {
			x = value.x; y = value.y; z = {}; w = {};
			ptr = &x;
		}
		mat4x4(const mat3x3& value) {
			x = value.x; y = value.y; z = value.z; w = {};
			ptr = &x;
		}
		mat4x4(vec4 x1, vec4 y1, vec4 z1, vec4 w1) {
			x = x1; y = y1; z = z1; w = w1;
			ptr = &x;
		}


		vec4 column(int idx) {
			return vec4(x[idx], y[idx], z[idx], w[idx]);
		}


		mat4x4& operator=(const mat4x4& value) {
			x = value.x;
			y = value.y;
			z = value.z;
			return *this;
		}
		mat4x4& operator=(const mat2x2& value) {
			x = value.x;
			y = value.y;
			return *this;
		}
		mat4x4& operator=(const mat3x3& value) {
			x = value.x;
			y = value.y;
			z = value.z;
			return *this;
		}

		vec4& operator[] (int idx) {
			if (idx > 4) {
				std::cerr << "vec4: Index out of range 0-4." << std::endl;
				throw std::out_of_range("Index out of range 0-4.");
			}
			return ptr[idx];
		}
	};


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



	// Matrix operator overloads
	// Square matricies
	vec2 operator*(mat2x2& mat, const vec2& vec);
	vec3 operator*(mat3x3& mat, const vec3& vec);
	vec4 operator*(mat4x4& mat, const vec4& vec);

	mat2x2 operator*(const mat2x2& mat1, mat2x2& mat2);
	mat3x3 operator*(const mat3x3& mat1, mat3x3& mat2);
	mat4x4 operator*(const mat4x4& mat1, mat4x4& mat2);


	std::ostream& operator<<(std::ostream& os, const mat2x2& v);
	std::ostream& operator<<(std::ostream& os, const mat3x3& v);
	std::ostream& operator<<(std::ostream& os, const mat4x4& v);
}
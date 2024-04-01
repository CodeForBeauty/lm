#pragma once
#include <iostream>


namespace lm {
	const float PI = 3.141592653589793;
	const float E = 2.718281828459045;


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

		vec2& operator++() {
			x++;
			y++;
			return *this;
		}
		vec2& operator--() {
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

		vec3& operator++() {
			x++;
			y++;
			z++;
			return *this;
		}
		vec3& operator--() {
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

		vec4& operator++() {
			x++;
			y++;
			z++;
			w++;
			return *this;
		}
		vec4& operator--() {
			x--;
			y--;
			z--;
			w--;
			return *this;
		}
	};

	// Add operator overload for vectors
	vec2 operator+(const vec2& v1, const vec2& v2) {
		return vec2(v1.x + v2.x, v1.y + v2.y);
	}
	vec3 operator+(const vec3& v1, const vec3& v2) {
		return vec3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
	}
	vec4 operator+(const vec4& v1, const vec4& v2) {
		return vec4(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w);
	}

	// Multiply operator overload for vectors
	vec2 operator*(const vec2& v1, const vec2& v2) {
		return vec2(v1.x * v2.x, v1.y * v2.y);
	}
	vec3 operator*(const vec3& v1, const vec3& v2) {
		return vec3(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
	}
	vec4 operator*(const vec4& v1, const vec4& v2) {
		return vec4(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z, v1.w * v2.w);
	}

	// Subtract operator overload for vectors
	vec2 operator-(const vec2& v1, const vec2& v2) {
		return vec2(v1.x - v2.x, v1.y - v2.y);
	}
	vec3 operator-(const vec3& v1, const vec3& v2) {
		return vec3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
	}
	vec4 operator-(const vec4& v1, const vec4& v2) {
		return vec4(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w);
	}

	// Divide operator overload for vectors
	vec2 operator/(const vec2& v1, const vec2& v2) {
		return vec2(v1.x / v2.x, v1.y / v2.y);
	}
	vec3 operator/(const vec3& v1, const vec3& v2) {
		return vec3(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z);
	}
	vec4 operator/(const vec4& v1, const vec4& v2) {
		return vec4(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z, v1.w / v2.w);
	}

	// Vector operations with float
	// Add operator overload
	vec2 operator+(const float& value, const vec2& vector) {
		return vec2(vector.x + value, vector.y + value);
	}
	vec3 operator+(const float& value, const vec3& vector) {
		return vec3(vector.x + value, vector.y + value, vector.z + value);
	}
	vec4 operator+(const float& value, const vec4& vector) {
		return vec4(vector.x + value, vector.y + value, vector.z + value, vector.w + value);
	}

	// Multiply operator overload
	vec2 operator*(const float& value, const vec2& vector) {
		return vec2(vector.x * value, vector.y * value);
	}
	vec3 operator*(const float& value, const vec3& vector) {
		return vec3(vector.x * value, vector.y * value, vector.z * value);
	}
	vec4 operator*(const float& value, const vec4& vector) {
		return vec4(vector.x * value, vector.y * value, vector.z * value, vector.w * value);
	}

	// Subtract operator overload
	vec2 operator-(const float& value, const vec2& vector) {
		return vec2(vector.x - value, vector.y - value);
	}
	vec3 operator-(const float& value, const vec3& vector) {
		return vec3(vector.x - value, vector.y - value, vector.z - value);
	}
	vec4 operator-(const float& value, const vec4& vector) {
		return vec4(vector.x - value, vector.y - value, vector.z - value, vector.w - value);
	}

	// Divide operator overload
	vec2 operator/(const float& value, const vec2& vector) {
		return vec2(vector.x / value, vector.y / value);
	}
	vec3 operator/(const float& value, const vec3& vector) {
		return vec3(vector.x / value, vector.y / value, vector.z / value);
	}
	vec4 operator/(const float& value, const vec4& vector) {
		return vec4(vector.x / value, vector.y / value, vector.z / value, vector.w / value);
	}

	// Negative operator overload
	vec2 operator-(const vec2& vector) {
		return vec2(-vector.x, -vector.y);
	}
	vec3 operator-(const vec3& vector) {
		return vec3(-vector.x, -vector.y, -vector.z);
	}
	vec4 operator-(const vec4& vector) {
		return vec4(-vector.x, -vector.y, -vector.z, -vector.w);
	}

	// Compound assign operators overload
	// Add
	vec2& operator+=(vec2& vector, const float& value) {
		vector.x += value;
		vector.y += value;
		return vector;
	}
	vec3& operator+=(vec3& vector, const float& value) {
		vector.x += value;
		vector.y += value;
		vector.z += value;
		return vector;
	}
	vec4& operator+=(vec4& vector, const float& value) {
		vector.x += value;
		vector.y += value;
		vector.z += value;
		vector.w += value;
		return vector;
	}

	// Multiply
	vec2& operator*=(vec2& vector, const float& value) {
		vector.x *= value;
		vector.y *= value;
		return vector;
	}
	vec3& operator*=(vec3& vector, const float& value) {
		vector.x *= value;
		vector.y *= value;
		vector.z *= value;
		return vector;
	}
	vec4& operator*=(vec4& vector, const float& value) {
		vector.x *= value;
		vector.y *= value;
		vector.z *= value;
		vector.w *= value;
		return vector;
	}

	// Subtract
	vec2& operator-=(vec2& vector, const float& value) {
		vector.x -= value;
		vector.y -= value;
		return vector;
	}
	vec3& operator-=(vec3& vector, const float& value) {
		vector.x -= value;
		vector.y -= value;
		vector.z -= value;
		return vector;
	}
	vec4& operator-=(vec4& vector, const float& value) {
		vector.x -= value;
		vector.y -= value;
		vector.z -= value;
		vector.w -= value;
		return vector;
	}

	// Divide
	vec2& operator/=(vec2& vector, const float& value) {
		vector.x /= value;
		vector.y /= value;
		return vector;
	}
	vec3& operator/=(vec3& vector, const float& value) {
		vector.x /= value;
		vector.y /= value;
		vector.z /= value;
		return vector;
	}
	vec4& operator/=(vec4& vector, const float& value) {
		vector.x /= value;
		vector.y /= value;
		vector.z /= value;
		vector.w /= value;
		return vector;
	}

	// Compound assignment with vectors
	// Add
	vec2& operator+=(vec2& v1, const vec2& v2) {
		v1.x += v1.x;
		v1.y += v2.y;
		return v1;
	}
	vec3& operator+=(vec3& v1, const vec3& v2) {
		v1.x += v1.x;
		v1.y += v2.y;
		v1.z += v2.z;
		return v1;
	}
	vec4& operator+=(vec4& v1, const vec4& v2) {
		v1.x += v1.x;
		v1.y += v2.y;
		v1.z += v2.z;
		v1.w += v2.w;
		return v1;
	}

	// Multiply
	vec2& operator*=(vec2& v1, const vec2& v2) {
		v1.x *= v1.x;
		v1.y *= v2.y;
		return v1;
	}
	vec3& operator*=(vec3& v1, const vec3& v2) {
		v1.x *= v1.x;
		v1.y *= v2.y;
		v1.z *= v2.z;
		return v1;
	}
	vec4& operator*=(vec4& v1, const vec4& v2) {
		v1.x *= v1.x;
		v1.y *= v2.y;
		v1.z *= v2.z;
		v1.w *= v2.w;
		return v1;
	}

	// Subtract
	vec2& operator-=(vec2& v1, const vec2& v2) {
		v1.x -= v1.x;
		v1.y -= v2.y;
		return v1;
	}
	vec3& operator-=(vec3& v1, const vec3& v2) {
		v1.x -= v1.x;
		v1.y -= v2.y;
		v1.z -= v2.z;
		return v1;
	}
	vec4& operator-=(vec4& v1, const vec4& v2) {
		v1.x -= v1.x;
		v1.y -= v2.y;
		v1.z -= v2.z;
		v1.w -= v2.w;
		return v1;
	}

	// Divide
	vec2& operator/=(vec2& v1, const vec2& v2) {
		v1.x /= v1.x;
		v1.y /= v2.y;
		return v1;
	}
	vec3& operator/=(vec3& v1, const vec3& v2) {
		v1.x /= v1.x;
		v1.y /= v2.y;
		v1.z /= v2.z;
		return v1;
	}
	vec4& operator/=(vec4& v1, const vec4& v2) {
		v1.x /= v1.x;
		v1.y /= v2.y;
		v1.z /= v2.z;
		v1.w /= v2.w;
		return v1;
	}

	// Cout operator overloading for vectors
	std::ostream& operator<<(std::ostream& os, const vec2& v) {
		os << "x = " << v.x << ", y = " << v.y;
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const vec3& v) {
		os << "x = " << v.x << ", y = " << v.y << ", z = " << v.z;
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const vec4& v) {
		os << "x = " << v.x << ", y = " << v.y << ", z = " << v.z << ", w = " << v.w;
		return os;
	}
}
#pragma once
#include <iostream>


namespace lm {
	const double PI = 3.141592653589793;
	const double E = 2.718281828459045;

	struct vec2 {
		float x, y;
		vec2() {
			x = 0; y = 0;
		}
		vec2(float xVal, float yVal) {
			x = xVal; y = yVal;
		}

	};
	struct vec3 {
		float x, y, z;
		vec3() {
			x = 0; y = 0; z = 0;
		}
		vec3(float xVal, float yVal) {
			x = xVal; y = yVal; z = 0;
		}
		vec3(float xVal, float yVal, float zVal) {
			x = xVal; y = yVal; z = zVal;
		}
		vec3(const vec2& v) {
			x = v.x; y = v.y; z = 0;
		}

	};
	struct vec4 {
		float x, y, z, w;
		vec4() {
			x = 0; y = 0; z = 0; w = 0;
		}
		vec4(float xVal, float yVal) {
			x = xVal; y = yVal; z = 0; w = 0;
		}
		vec4(float xVal, float yVal, float zVal) {
			x = xVal; y = yVal; z = zVal; w = 0;
		}
		vec4(float xVal, float yVal, float zVal, float wVal) {
			x = xVal; y = yVal; z = zVal; w = wVal;
		}
		vec4(const vec2& v) {
			x = v.x; y = v.y; z = 0; w = 0;
		}
		vec4(const vec3& v) {
			x = v.x; y = v.y; z = v.z; w = 0;
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
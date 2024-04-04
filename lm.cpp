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


vec2 lm::operator*(mat2 mat, vec2 vec) {
	return { dot(mat.column(0), vec), dot(mat.column(1), vec) };
}

vec3 lm::operator*(mat3 mat, vec3 vec) {
	return { dot(mat.column(0), vec), dot(mat.column(1), vec), dot(mat.column(2), vec) };
}

vec4 lm::operator*(mat4 mat, vec4 vec) {
	return { dot(mat.column(0), vec), dot(mat.column(1), vec), dot(mat.column(2), vec), dot(mat.column(3), vec) };
}



mat2 lm::operator*(mat2 mat1, mat2 mat2) {
	return {{ dot(mat1.x, mat2.column(0)), dot(mat1.x, mat2.column(1)) },
			{ dot(mat1.y, mat2.column(0)), dot(mat1.y, mat2.column(1)) }};
}

mat3 lm::operator*(mat3 mat1, mat3 mat2) {
	return {{ dot(mat1.x, mat2.column(0)), dot(mat1.x, mat2.column(1)), dot(mat1.z, mat2.column(2)) },
			{ dot(mat1.y, mat2.column(0)), dot(mat1.y, mat2.column(1)), dot(mat1.y, mat2.column(2)) },
			{ dot(mat1.z, mat2.column(0)), dot(mat1.z, mat2.column(1)), dot(mat1.z, mat2.column(2)) }};
}

mat4 lm::operator*(mat4 mat1, mat4 mat2) {
	return {{ dot(mat1.x, mat2.column(0)), dot(mat1.x, mat2.column(1)), dot(mat1.x, mat2.column(2)), dot(mat1.x, mat2.column(3)) },
			{ dot(mat1.y, mat2.column(0)), dot(mat1.y, mat2.column(1)), dot(mat1.y, mat2.column(2)), dot(mat1.y, mat2.column(3)) },
			{ dot(mat1.z, mat2.column(0)), dot(mat1.z, mat2.column(1)), dot(mat1.z, mat2.column(2)), dot(mat1.z, mat2.column(3)) },
			{ dot(mat1.w, mat2.column(0)), dot(mat1.w, mat2.column(1)), dot(mat1.w, mat2.column(2)), dot(mat1.w, mat2.column(3)) }};
}

Matrix lm::operator*(Matrix mat1, Matrix mat2) {
	if (mat1.columnsSize != mat2.rowsSize) {
		std::cerr << "Given Matrices are not multipliable. mat1 must have the same columnsSize as mat2's rowsSize" << std::endl;
		throw std::length_error("Given Matrices are not multipliable.");
	}
	Matrix out = Matrix(mat1.rowsSize, mat2.columnsSize);

	for (int i = 0; i < out.rowsSize; i++) {
		for (int j = 0; i < out.columnsSize; i++) {
			double tmpVal = 0;
			for (int i1 = 0; i1 < mat1.columnsSize; i1++) {
				tmpVal += mat1(i, i1) * mat2(i1, j);
			}
			out(i, j) = tmpVal;
		}
	}

	return out;
}

std::list<double> lm::operator*(Matrix mat1, std::list<double> vec)
{
	if (mat1.rowsSize != vec.size()) {
		std::cerr << "Given Matrix and list are not multipliable." << std::endl;
		throw std::length_error("Given Matrix and list are not multipliable.");
	}

	std::list<double> out = std::list<double>(mat1.columnsSize);
	std::list<double>::iterator ptr = out.begin();


	for (int i = 0; i < mat1.columnsSize; i++) {
		std::list<double>::iterator vecPtr = vec.begin();
		for (int j = 0; j < mat1.rowsSize; j++) {
			*ptr += *vecPtr * mat1(j, i);
			vecPtr++;
		}
		ptr++;
	}

	return out;
}

std::ostream& lm::operator<<(std::ostream& os, const mat2& v) {
	os << " | " << v.x << " |\n";
	os << " | " << v.y << " |\n";
	return os;
}

std::ostream& lm::operator<<(std::ostream& os, const mat3& v) {
	os << " | " << v.x << " |\n";
	os << " | " << v.y << " |\n";
	os << " | " << v.z << " |\n";
	return os;
}

std::ostream& lm::operator<<(std::ostream& os, const mat4& v) {
	os << " | " << v.x << " |\n";
	os << " | " << v.y << " |\n";
	os << " | " << v.z << " |\n";
	os << " | " << v.w << " |\n";
	return os;
}

std::ostream& lm::operator<<(std::ostream& os, Matrix mat1) {
	for (int i = 0; i < mat1.rowsSize; i++) {
		for (int j = 0; j < mat1.columnsSize; j++) {
			std::cout << " | " << mat1(i, j) << ", ";
		}
		std::cout << " | \n";
	}
	return os;
}

mat4 lm::position3d(const vec3& position) {
	return { {1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {position.x, position.y, position.z, 1} };
}

mat3 lm::position2d(const vec2& position) {
	return { {1, 0, 0}, {0, 1, 0}, {position.x, position.y, 1} };
}


mat3 lm::rotation3d(const vec3& rotation) {
	vec3 theta = { degrees2radians(rotation.x), degrees2radians(rotation.y) , degrees2radians(rotation.z) };

	vec3 thetaCos = { std::cosf(theta.x), std::cosf(theta.y), std::cosf(theta.z) };
	vec3 thetaSin = { std::sinf(theta.x), std::sinf(theta.y), std::sinf(theta.z) };

	mat3 rotX = {
		{1, 0, 0},
		{0, thetaCos.x, -thetaSin.x},
		{0, thetaSin.x, thetaCos.x}
	};

	mat3 rotY = {
		{thetaCos.y, 0, -thetaSin.y},
		{0, 1, 0},
		{thetaSin.y, 0, thetaCos.y}
	};

	mat3 rotZ = {
		{thetaCos.z, -thetaSin.z, 0},
		{thetaSin.z, thetaCos.z, 0},
		{0, 0, 1}
	};

	return rotX * rotY * rotZ;
}

mat2 lm::rotation2d(const float& rotation) {
	float theta = degrees2radians(rotation);

	float valX = std::cos(theta);
	float valY = std::sin(theta);

	mat2 rot = {
		{ valX, valY, },
		{ -valY, valX }
	};

	return rot;
}


mat4 lm::viewMatrix(vec3 at, vec3 eye, vec3 up) {
	vec3 zaxis = normalize(at - eye);
	vec3 xaxis = normalize(cross(up, zaxis));
	vec3 yaxis = cross(zaxis, xaxis);

	return {
		xaxis, yaxis, zaxis, {dot(xaxis, -eye), dot(yaxis, -eye), dot(zaxis, -eye), 1}
	};
}

mat4 lm::orthographic(const float& right, const float& left, const float& top, const float& bottom, const float& far, const float& near) {
	return {
		{2 / (right - left), 0, 0, 0},
		{0, 2 / (top - bottom), 0, 0},
		{0, 0, 2 / (far - near), 0},
		{-((right + left) / (right - left)), -((top + bottom) / (top - bottom)), -((far + near) / (far - near)), 1}
	};
}

mat4 lm::orthographic(const float& width, const float& height, const float& far, const float& near) {
	return orthographic(width, -width, height, -height, far, near);
}

mat4 lm::orthographic(const float& width, const float& height, const float& depth) {
	return orthographic(width, -width, height, -height, depth, -depth);
}


mat4 lm::perspective(const float& fov, const float& near, const float& far, const float& ratio) {
	float y = 1 / std::tan(fov / 2);
	return {
		{ y * ratio, 0, 0, 0 },
		{ 0, y, 0, 0 },
		{ 0, 0, far / (far - near), 0},
		{0, 0, 0, 1}
	};
}

mat4 lm::perspective(const float& fov, const float& near, const float& far, const float& width, const float& height) {
	return perspective(fov, near, far, width / height);
}
//
//#include <iomanip>
//#include <cmath>
//#include "SqaureMatrix.h"
//
//using namespace algebra;
//
//sf::Vector2f algebra::to_unit(const sf::Vector2f& a)
//{
//	sf::Vector2f r;
//	r.x = a.x / sqrt(pow(a.x, 2) + pow(a.y, 2));
//	r.y = a.y / sqrt(pow(a.x, 2) + pow(a.y, 2));
//	return r;
//}
//
////SquareMatrix::SquareMatrix()
////{
////	this->matrix = std::vector<float>(4, 0.f);
////}
//
////SquareMatrix::SquareMatrix(float x, float y, float z, float a) : SquareMatrix()
////{
////	this->matrix[0] = x;
////	this->matrix[1] = y;
////	this->matrix[2] = z;
////	this->matrix[3] = a;
////
////}
//
////float SquareMatrix::det() const
////{
////	return this->matrix[0]*this->matrix[3]-this->matrix[1]*this->matrix[2];
////}
//
////const SquareMatrix algebra::SquareMatrix::T() const
////{
////	return SquareMatrix(matrix[0],matrix[2],matrix[1],matrix[3]);
////}
//
//SquareMatrix algebra::SquareMatrix::operator*(const SquareMatrix& a) const
//{
//	float _0 = this->matrix[0] * a.matrix[0] + this->matrix[1] * a.matrix[2];
//	float _1 = this->matrix[0] * a.matrix[1] + this->matrix[1] * a.matrix[3];
//	float _2 = this->matrix[2] * a.matrix[0] + this->matrix[3] * a.matrix[2];
//	float _3 = this->matrix[2] * a.matrix[1] + this->matrix[3] * a.matrix[3];
//	return SquareMatrix(_0,_1,_2,_3);
//}
//
//float algebra::SquareMatrix::operator()(int x, int y) const
//{
//	if (x >= 0 && x < 2 && y >= 0 && y < 2) {
//		return this->matrix[x * 2 + y];
//	}
//	else
//	{
//		return 0.f;//to fix
//	}
//}
//
//SquareMatrix SquareMatrix::operator+( SquareMatrix const& a) const
//{
//	SquareMatrix m;
//	for (int i = 0; i < 4; ++i) {
//		m.matrix[i] = this->matrix[i] + a.matrix[i];
//	}
//	return m;
//}
//
//SquareMatrix SquareMatrix::operator-(const SquareMatrix& a) const
//{
//	SquareMatrix m;
//	for (int i = 0; i < 4; ++i) {
//		m.matrix[i] = this->matrix[i] - a.matrix[i];
//	}
//	return m;
//}
//
//algebra::SquareMatrix::SquareMatrix(const SquareMatrix& a)
//{
//	this->matrix = a.matrix;
//}
//
//algebra::SquareMatrix::SquareMatrix(const sf::Vector2f& a) :SquareMatrix()
//{
//	sf::Vector2f b = to_unit(a);
//	this->matrix[0] = b.x;
//	this->matrix[2] = b.y;
//	this->matrix[1] = -1 * b.y;
//	this->matrix[3] = b.x;
//}
//
//std::ostream& algebra::operator<<(std::ostream& os, const SquareMatrix& a)
//{
//	os << std::setprecision(3);
//	os << "[[ " << std::setw(5) << a.matrix[0] << ", " << std::setw(5) << a.matrix[1] << " ],\n [ " << std::setw(5) << a.matrix[2] << ", " <<std::setw(5) << a.matrix[3] << " ]]\n";
//	return os;
//}

#ifndef SQUARE_MATRIX
#define SQUARE_MATRIX
#include <vector>
#include <iostream>
#include <iomanip>
#include <SFML/Graphics.hpp>
namespace algebra {
	template <class C>
	sf::Vector2<C> to_unit(const sf::Vector2<C> a) {
		{
			if (a.x == 0 && a.y == 0) return sf::Vector2<C>(0, 0);
			sf::Vector2<C> r;
			r.x = a.x / (C) sqrt(pow(a.x, 2) + pow(a.y, 2));
			r.y = a.y / (C) sqrt(pow(a.x, 2) + pow(a.y, 2));
			return r;
		}
	}
	template<class C>
	class Row {
	public:
		sf::Vector2<C> v;
		Row() :v(sf::Vector2<C>(C(), C())) {};
		Row(C a, C b) : v(a, b) {}
		C operator[](int i) {
			if (!(i >= 0 && i < 2)) return C();
			if (i) return v.y;
			else return v.x;
		}
	};
	template<class C>
	class SquareMatrix
	{
	private:
		std::vector<C> matrix;
		
	public:
		
		SquareMatrix()
		{
			this->matrix = std::vector<C>(4);
		};
		SquareMatrix(C a, C b, C c, C d) : SquareMatrix()
		{
			this->matrix[0] = a;
			this->matrix[1] = b;
			this->matrix[2] = c;
			this->matrix[3] = d;
		};
		SquareMatrix(const SquareMatrix& a) {
			this->matrix = a.matrix;
		};
		SquareMatrix(const sf::Vector2<C>& a) : SquareMatrix()
		{
			sf::Vector2f b = to_unit(a);
			this->matrix[0] = b.x;
			this->matrix[2] = b.y;
			this->matrix[1] = -1 * b.y;
			this->matrix[3] = b.x;
		}
		SquareMatrix(const sf::Vector2<C>& a, const sf::Vector2<C>& b) : SquareMatrix(sf::Vector2<C>(a.x - b.x, a.y - b.y)) {};
		C det() const
		{
			return this->matrix[0] * this->matrix[3] - this->matrix[1] * this->matrix[2];
		};
		const SquareMatrix T() const
		{
			return SquareMatrix(matrix[0], matrix[2], matrix[1], matrix[3]);
		};
		SquareMatrix inverse() {
			if (!this->det()) {
				//todo cc
				return SquareMatrix();
			}
			else {
				C inv_det = 1 / this->det();
				C _0 = inv_det * this->matrix[3];
				C _1 = inv_det * this->matrix[1] * (-1);
				C _2 = inv_det * this->matrix[2] * (-1);
				C _3 = inv_det * this->matrix[0];
				return SquareMatrix(_0, _1, _2, _3);

			}
		}
		SquareMatrix operator*(const SquareMatrix& a) const
		{
			C _2 = this->matrix[2] * a.matrix[0] + this->matrix[3] * a.matrix[2];
			C _3 = this->matrix[2] * a.matrix[1] + this->matrix[3] * a.matrix[3];
			C _1 = this->matrix[0] * a.matrix[1] + this->matrix[1] * a.matrix[3];
			C _0 = this->matrix[0] * a.matrix[0] + this->matrix[1] * a.matrix[2];
			return SquareMatrix(_0, _1, _2, _3);
		};
		C operator()(int x, int y) const
		{
			if (x >= 0 && x < 2 && y >= 0 && y < 2) {
				return this->matrix[x * 2 + y];
			}
			else
			{
				return C();//to fix
			}
		}
		SquareMatrix operator+(const SquareMatrix& a) const
		{
			SquareMatrix m;
			for (int i = 0; i < 4; ++i) {
				m.matrix[i] = this->matrix[i] + a.matrix[i];
			}
			return m;
		};
		SquareMatrix operator-(const SquareMatrix& a) const
		{
			SquareMatrix m;
			for (int i = 0; i < 4; ++i) {
				m.matrix[i] = this->matrix[i] - a.matrix[i];
			}
			return m;
		};
		Row<C> operator[] (int i) const 
		{
			if (i <= 2 && i >= 0) return Row<C>(this->matrix[2 * i], this->matrix[2 * i + 1]);
			else return Row<C>(); //todo
		}
		friend std::ostream& operator<<(std::ostream& os, const SquareMatrix& a)
		{
			os << std::setprecision(3);
			os << "[[ " << std::setw(5) << a.matrix[0] << ", " << std::setw(5) << a.matrix[1] << " ],\n [ " << std::setw(5) << a.matrix[2] << ", " << std::setw(5) << a.matrix[3] << " ]]\n";
			return os;
		};
		sf::Vector2<C> operator*(sf::Vector2<C> a) {
			C x = this->matrix[0] * a.x + this->matrix[1] * a.y;
			C y = this->matrix[2] * a.x + this->matrix[3] * a.y;
			return sf::Vector2<C>(x, y);
		}
	};
	typedef SquareMatrix<float> SquareMatrixf;

}
#endif
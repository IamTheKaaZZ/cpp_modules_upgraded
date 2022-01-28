#ifndef MATRIX_HPP
# define MATRIX_HPP

# include <iostream>
# include <list>
#include <stdexcept>
# include <string>
# include <vector>
# include <exception>
# include <tuple>

template<typename T = double> //default is int if T is not specified
class Matrix
{

	public:

		Matrix() = delete;
		Matrix(unsigned int const & rowSize, unsigned const & colSize, T init) {
			this->_rowSize = rowSize;
			this->_colSize = colSize;
			this->_matrix.resize(_rowSize);
			for (unsigned i = 0; i < _matrix.size(); i++) this->_matrix[i].resize(_colSize, init);
		}
		Matrix( Matrix const & src ) { //default works fine
			this->_rowSize = src.getRows();
			this->_colSize = src.getCols();
			this->_matrix = src._matrix;
		}
		~Matrix() = default;

		//Matrix operations
		Matrix &		operator=(Matrix const & rhs) { //default works here
			if (this != &rhs) {
				this->_rowSize = rhs.getRows();
				this->_colSize = rhs.getCols();
				this->_matrix = rhs._matrix;
			}
			return *this;
		};
		Matrix			operator+(Matrix const & rhs) {
			Matrix<T>	sum(this->_rowSize, this->_colSize, static_cast<T>(0));
			unsigned	row, col;
			for (row = 0; row < _rowSize; row++) {
				for (col = 0; col < _colSize; col++) {
					sum(row, col) = this->_matrix[row][col] + rhs(row, col);
				}
			}
			return sum;
		};
		Matrix			operator-(Matrix const & rhs) {
			Matrix<T>	diff(this->_rowSize, this->_colSize, static_cast<T>(0));
			unsigned	row, col;
			for (row = 0; row < _rowSize; row++) {
				for (col = 0; col < _colSize; col++) {
					diff(row, col) = this->_matrix[row][col] - rhs(row, col);
				}
			}
			return diff;
		};
		Matrix			operator*(Matrix const & rhs) {
			Matrix<T>	multi(_rowSize, rhs.getCols(), static_cast<T>(0));
			if (this->_colSize == rhs.getCols()) {
				unsigned	row, col, rhsCol;
				T	temp;
				for (row = 0; row < _rowSize; row++) {
					for (rhsCol = 0; rhsCol < rhs.getCols(); rhsCol++) {
						temp = static_cast<T>(0);
						for (col = 0; col < _colSize; col++) {
							temp += this->_matrix[row][col] * rhs(col, rhsCol);
						}
						multi(row, rhsCol) = temp;
					}
				}
				return multi;
			}
			else {
				throw std::logic_error("Cannot multiply matrices with different amount of columns.");
			}
		};
		Matrix			transpose() {
			Matrix<T>	transposed(_colSize, _rowSize, static_cast<T>(0));
			for (unsigned row = 0; row < _rowSize; row++) {
				for (unsigned col = 0; col < _colSize; col++) {
					transposed(row, col) = this->_matrix[col][row];
				}
			}
			return transposed;
		};
		//Scalar operations
		Matrix			operator+(T scalar) {
			Matrix<T>	result(this->_rowSize, this->_colSize, static_cast<T>(0));
			unsigned	row, col;
			for (row = 0; row < _rowSize; row++) {
				for (col = 0; col < _colSize; col++) {
					result(row, col) = this->_matrix[row][col] + scalar;
				}
			}
			return result;
		};
		Matrix			operator-(T scalar) {
			Matrix<T>	result(this->_rowSize, this->_colSize, static_cast<T>(0));
			unsigned	row, col;
			for (row = 0; row < _rowSize; row++) {
				for (col = 0; col < _colSize; col++) {
					result(row, col) = this->_matrix[row][col] - scalar;
				}
			}
			return result;
		};
		Matrix			operator*(T scalar) {
			Matrix<T>	result(this->_rowSize, this->_colSize, static_cast<T>(0));
			unsigned	row, col;
			for (row = 0; row < _rowSize; row++) {
				for (col = 0; col < _colSize; col++) {
					result(row, col) = this->_matrix[row][col] * scalar;
				}
			}
			return result;
		};
		Matrix			operator/(T scalar) {
			Matrix<T>	result(this->_rowSize, this->_colSize, static_cast<T>(0));
			unsigned	row, col;
			for (row = 0; row < _rowSize; row++) {
				for (col = 0; col < _colSize; col++) {
					result(row, col) = this->_matrix[row][col] / scalar;
				}
			}
			return result;
		};
		//Access operations/methods
		T &				operator()(unsigned const & row, unsigned const & col) {
			return _matrix[row][col];
		};
		T const &		operator()(unsigned const & row, unsigned const & col) const {
			return _matrix[row][col];
		}
		unsigned const &		getRows() const { return _rowSize; }
		unsigned const &		getCols() const { return _colSize; }
		//Only when the matrix contains doubles
		//Returns 3 values: 1 [Eigen Vector], 2 [Eigen value], 3 [Flag]
		std::tuple<Matrix, T, int> powerIter(unsigned rowNum, T tolerance) {
			if (!std::is_same<T, double>::value)
				throw std::logic_error("Can only be performed with doubles.");
			Matrix<T>	X(rowNum, 1, 1.0);
			for (unsigned i = 1; i <= rowNum; i++) {
        		X(i - 1, 0) = i;
    		}
    		int errorCode = 0;
    		double difference = 1.0; // Initiall value greater than tolerance
    		unsigned j = 0;
    		unsigned location;
    		// Defined to find the value between last two eigen values
    		std::vector<double> eigen;
    		double eigenvalue = 0.0;
    		eigen.push_back(0.0);
    		while(std::abs(difference) > tolerance) // breaks out when reached tolerance
    		{
        		j++;
        		// Normalize X vector with infinite norm
        		for (int i = 0; i < rowNum; ++i)
        		{
            		eigenvalue = X(0,0);
            		if (abs(X(i, 0)) >= std::abs(eigenvalue))
            		{
                		// Take the value of the infinite norm as your eigenvalue
                		eigenvalue = X(i, 0);
                		location = i;
            		}
        		}
        		if (j >= 5e5) {
            		std::cout << "Oops, that was a nasty complex number wasn't it?" << std::endl;
            		std::cout << "ERROR! Returning code black, code black!";
            		errorCode = -1;
            		return std::make_tuple(X, 0.0, errorCode);
        		}
        		eigen.push_back(eigenvalue);
        		difference = eigen[j] - eigen[j - 1];
        		// Normalize X vector with its infinite norm
        		X = X / eigenvalue;
        		// Multiply The matrix with X vector
        		X = (*this) * X;
    		}
    		// Take the X vector and what you've found is an eigenvector!
    		X = X / eigenvalue;
    		return std::make_tuple(X, eigenvalue, errorCode);
		};
		Matrix		deflation(Matrix & X, double & eigenVal) {
			if (!std::is_same<T, double>::value)
				throw std::logic_error("Can only be performed with doubles.");
			// Deflation formula exactly applied
    		double denominator = eigenVal / (X.transpose() * X)(0,0);
    		Matrix Xtrans = X.transpose();
    		Matrix RHS = (X * Xtrans);
    		Matrix RHS2 = RHS * denominator;
    		Matrix A2 = *this - RHS2;
			return A2;
		};

	private:

		unsigned						_rowSize;
		unsigned						_colSize;
		std::vector<std::vector<T>>		_matrix;

};

template<typename T>
std::ostream &			operator<<( std::ostream & o, Matrix<T> const & i ) {
	o << "The Matrix has " << i.getRows() << " rows and " << i.getCols() << " colums.\n";
	o << "Contents:\n";
	for (unsigned row = 0; row < i.getRows(); row++) {
		for (unsigned col = 0; col < i.getCols(); col++) {
			o << '[' << i(row,col) << "] ";
		}
		o << std::endl;
	}
	o << std::endl;
	return o;
}; //Print the entire matrix

template<typename T>
std::ostream &			operator<<( std::ostream & o, Matrix<T> & i ) {
	o << "The Matrix has " << i.getRows() << " rows and " << i.getCols() << " colums.\n";
	o << "Contents:\n";
	for (unsigned row = 0; row < i.getRows(); row++) {
		for (unsigned col = 0; col < i.getCols(); col++) {
			o << '[' << i(row,col) << "] ";
		}
		o << std::endl;
	}
	o << std::endl;
	return o;
}; //Print the entire matrix

#endif /* ********************************************************** MATRIX_H */
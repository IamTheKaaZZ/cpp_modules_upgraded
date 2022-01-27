#ifndef MATRIX_HPP
# define MATRIX_HPP

# include <iostream>
# include <string>
# include <vector>

template<typename T>
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
		Matrix( Matrix const & src ) {
			this->_rowSize = src.getRows();
			this->_colSize = src.getCols();
			this->_matrix = src._matrix;
		}
		~Matrix();

		//Matrix operations
		Matrix &		operator=(Matrix const & rhs);
		Matrix			operator+(Matrix const & rhs);
		Matrix			operator-(Matrix const & rhs);
		Matrix			operator*(Matrix const & rhs);
		Matrix			transpose();
		//Scalar operations
		Matrix			operator+(T);
		Matrix			operator-(T);
		Matrix			operator*(T);
		Matrix			operator/(T);
		//Access operations/methods
		T&				operator()(unsigned const & row, unsigned const & col);
		unsigned		getRows() const { return _rowSize; }
		unsigned		getCols() const { return _colSize; }
		std::tuple<Matrix, T, int> powerIter(unsigned, T);

	private:

		unsigned						_rowSize;
		unsigned						_colSize;
		std::vector<std::vector<T>>		_matrix;

};

template<typename T>
std::ostream &			operator<<( std::ostream & o, Matrix<T> const & i ); //Print the entire matrix

#endif /* ********************************************************** MATRIX_H */
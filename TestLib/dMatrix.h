#pragma once
#include <exception>
#include <algorithm>
template<class Type>
class dMatrix {
public:
	dMatrix(int cols, int rows):m_size(cols*rows) {
		m_array = (Type *)malloc(sizeof(Type) * m_size);
		for (Type* ptr = m_array; ptr != m_array + m_size - 1; ptr++) {
			*ptr = 0.0;
		}
	};
	dMatrix() {
		m_array = new Type[9]{};
	};
	Type& get(int row, int col = 0) {
		if (!(row < m_rows and m_cols > col))
			throw std::exception("Index out of range for Vector");
		return m_array[col * m_rows + row];
	};
	dMatrix<Type>& operator=(dMatrix<Type>& src) {
		for (int i = 0; i < m_size; i++) {
			m_array[i] = src.m_array[i];
		}
		return *this;
	};
	dMatrix<Type>& operator=(dMatrix<Type>&& rsrc) {
		if (this != &rsrc) {
			delete[] m_array;
			m_size = rsrc.m_size;
			m_array = new float[m_size];
			std::copy(rsrc.m_array, rsrc.m_array + m_size - 1, m_array);
			rsrc.m_array = nullptr;
			rsrc.m_size = 0;
		}
		return *this;
	};
	dMatrix<Type> operator*(dMatrix<Type>& src) const {
		if (m_cols != src.m_rows) {
			char chbuff[100];
			sprintf(chbuff, "Cant multiply matrices (%d/%d columns/rows by %d/%d columns/rows)",
				m_cols, m_rows, src.m_cols, src.m_rows);
			throw std::exception(chbuff);
		}
		int resulting_size = m_rows * src.m_rows;
		dMatrix<Type> result(m_rows, src.m_rows);
		Type* result = malloc(sizeof(Type) * resulting_size);
		for (int bcol = 0; bcol < m_cols; bcol++) {
			for (int brow = 0; brow < m_rows; brow++) {
				for (int row = 0; row < src.m_rows; row++) {
					for (int col = 0; col < src.m_cols; col++) {
						result.m_array[bcol * src.m_rows + brow] +=
							src.m_array[col * src.m_rows + row] * m_array[bcol * m_rows + brow];
					}
				}
			}
		}
		return result;
	};
	dMatrix<Type> operator*(int mult) const {
		dMatrix<Type> result(m_rows, m_cols);
		for (int i = 0; i < m_size; i++) {
			result.m_array[i] = m_array[i] * mult;
		}
		return result;
	};
	dMatrix<Type>& invert() {
		return *this;
	};
	float det() {
		return 0.0f;
	};
	dMatrix<Type>& transpose() {

		return *this;
	};
	dMatrix<Type> operator*(float mult) const {
		dMatrix<Type> result(m_rows, m_cols);
		for (int i = 0; i < m_size; i++) {
			result.m_array[i] = m_array[i] * mult;
		}
		return result;
	};
	dMatrix<Type> operator+(dMatrix<Type>& src) const {
		if (m_rows != src.m_rows or m_cols != src.m_cols)
			throw std::exception("Incompatible matrices!");
		dMatrix<Type> result(m_rows, m_cols);
		for (int i = 0; i < m_size; i++) {
			result.m_array[i] = m_array[i] + src.m_array[i];
		}
		return result;
	};
	dMatrix<Type> operator-(dMatrix<Type>& src) const {
		if (m_rows != src.m_rows or m_cols != src.m_cols)
			throw std::exception("Incompatible matrices!");
		dMatrix<Type> result(m_rows, m_cols);
		for (int i = 0; i < m_size; i++) {
			result.m_array[i] = m_array[i] - src.m_array[i];
		}
		return result;
	};
	dMatrix<Type> operator/(dMatrix<Type>& src) const {
		if (m_cols != src.m_rows) {
			char chbuff[100];
			sprintf(chbuff, "Cant devide matrices (%d/%d columns/rows by %d/%d columns/rows)",
				m_cols, m_rows, src.m_cols, src.m_rows);
			throw std::exception(chbuff);
		}
		int resulting_size = m_rows * src.m_rows;
		dMatrix<Type> result(m_rows, src.m_rows);
		Type* result = malloc(sizeof(Type) * resulting_size);
		for (int bcol = 0; bcol < m_cols; bcol++) {
			for (int brow = 0; brow < m_rows; brow++) {
				for (int row = 0; row < src.m_rows; row++) {
					for (int col = 0; col < src.m_cols; col++) {
						result.m_array[bcol * src.m_rows + brow] +=
							src.m_array[col * src.m_rows + row] / m_array[bcol * m_rows + brow];
					}
				}
			}
		}
		return result;
	};
	dMatrix<Type> operator/(int div) const {
		dMatrix<Type> result(m_rows, m_cols);
		for (int i = 0; i < m_size; i++) {
			result.m_array[i] = m_array[i] / div;
		}
		return result;
	};
	dMatrix<Type> operator/(float div) const {
		dMatrix<Type> result(m_rows, m_cols);
		for (int i = 0; i < m_size; i++) {
			result.m_array[i] = m_array[i] / div;
		}
		return result;
	};
	Type& operator[](int index) {
		if (!(index < m_size and index > -m_size))
			throw std::exception("Index out of range for Vector");
		return index >= 0 ? &m_array[index] : &m_array[m_size - 1 + index];
	};
	~dMatrix() {
		free(m_array);
	};
private:
	Type* m_array;
	int m_size;
	int m_rows;
	int m_cols;
};


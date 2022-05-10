#pragma once
#include <exception>
#include <algorithm>
#include <memory>
#include <array>
#include <initializer_list>

template<class Type = float, int rows = 3, int cols = 3>
class dMatrix {
	typedef std::array<std::array<Type, rows>, cols> dmatrix;
	typedef std::array<Type, rows> dvect;
public:
	dMatrix() : 
		m_cols(cols), m_rows(rows), m_size(cols * rows) {
		mp_arr = std::shared_ptr<dmatrix>(new dmatrix());
		m_arr = *mp_arr;
		for (int i = 0; i < m_cols; i++) {
			dvect row;
			row.fill(Type());
			m_arr.at(i) = row;
		}
	}
	dMatrix(std::initializer_list<Type> list) : 
		dMatrix<Type, rows, cols>() {
		int msize = static_cast<int>(list.size());
		int count = 0;
		for (auto elem : list) {
			m_arr[count / m_rows][count % m_rows] = static_cast<Type>(elem);
			if (++count == m_size) 
				break;
		}
	}
	dvect& operator[](int index) {
		return m_arr.at(index);
	}
	Type get(int row, int col = 0) const {
		return m_arr.at(col).at(row);
	}
	void set(Type val, int row, int col = 0) {
		m_arr.at(col).at(row) = val;
	}
	Type& at(int row, int col = 0) const {
		return m_arr.at(col).at(row);
	}
	dMatrix<Type>& operator=(const dMatrix<Type>&& rsrc) {
		if (this != &rsrc) {
		mp_arr = rsrc.mp_arr;
		m_arr = *mp_arr;
		m_size = rsrc.m_size;
		m_cols = rsrc.m_cols;
		m_rows = rsrc.m_rows;
		}
		return *this;
	}
	dMatrix(const dMatrix<Type>& src):
		dMatrix<Type,src.m_rows,src.m_cols>()
	{
		for (int col = 0; col < src.m_cols; col++) {
			for (int row = 0; row < src.m_rows; row++) {
				this->at(row, col) = src.get(row, col);
			}
		}
	}
	~dMatrix() {
	}
private:
	std::shared_ptr<dmatrix> mp_arr;
	dmatrix m_arr;
	int m_size;
	int m_rows;
	int m_cols;
};


//template<class Type>
//class dMatrix {
//public:
//	dMatrix(int cols, int rows): m_cols(cols), m_rows(rows), m_size(cols*rows) {
//		
//		}
//	};
//
//	dMatrix() {
//		m_array = new Type[9]{};
//	};
//	Type& get(int row, int col = 0) {
//		if (!(row < m_rows and m_cols > col))
//			throw std::exception("Index out of range for Vector");
//		return m_array[col][row];
//	};
//	dMatrix<Type>& operator=(dMatrInfo src) {
//	m_array = src.m_array;
//	return *this;
//	};
//	dMatrix<Type>& operator=(dMatrix<Type>&& rsrc) {
//		if (this != &rsrc) {
//			delete[] m_array;
//			m_size = rsrc.m_size;
//			m_array = new float[m_size];
//			std::copy(rsrc.m_array, rsrc.m_array + m_size - 1, m_array);
//			rsrc.m_array = nullptr;
//			rsrc.m_size = 0;
//		}
//		return *this;
//	};
//	dMatrix<Type> operator*(dMatrix<Type>& src) const {
//		if (m_cols != src.m_rows) {
//			char chbuff[100];
//			sprintf_s(chbuff, "Cant multiply matrices (%d/%d columns/rows by %d/%d columns/rows)",
//				m_cols, m_rows, src.m_cols, src.m_rows);
//			throw std::exception(chbuff);
//		}
//		int resulting_size = m_rows * src.m_rows;
//		dMatrix<Type> result(m_rows, src.m_rows);
//		for (int bcol = 0; bcol < m_cols; bcol++) {
//			for (int brow = 0; brow < m_rows; brow++) {
//				for (int row = 0; row < src.m_rows; row++) {
//					for (int col = 0; col < src.m_cols; col++) {
//						result.m_array[bcol * src.m_rows + brow] +=
//							src.m_array[col * src.m_rows + row] * m_array[bcol * m_rows + brow];
//					}
//				}
//			}
//		}
//		return result;
//	};
//	dMatrix<Type> operator*(int mult) const {
//		dMatrix<Type> result(m_rows, m_cols);
//		for (int i = 0; i < m_size; i++) {
//			result.m_array[i] = m_array[i] * mult;
//		}
//		return result;
//	};
//	dMatrix<Type>& invert() {
//		return *this;
//	};
//	float det() {
//		return 0.0f;
//	};
//	dMatrix<Type>& transpose() {
//
//		return *this;
//	};
//	dMatrix<Type> operator*(float mult) const {
//		dMatrix<Type> result(m_rows, m_cols);
//		for (int i = 0; i < m_size; i++) {
//			result.m_array[i] = m_array[i] * mult;
//		}
//		return result;
//	};
//	dMatrix<Type> operator+(dMatrix<Type>& src) const {
//		if (m_rows != src.m_rows or m_cols != src.m_cols)
//			throw std::exception("Incompatible matrices!");
//		dMatrix<Type> result(m_rows, m_cols);
//		for (int i = 0; i < m_size; i++) {
//			result.m_array[i] = m_array[i] + src.m_array[i];
//		}
//		return result;
//	};
//	dMatrix<Type> operator-(dMatrix<Type>& src) const {
//		if (m_rows != src.m_rows or m_cols != src.m_cols)
//			throw std::exception("Incompatible matrices!");
//		dMatrix<Type> result(m_rows, m_cols);
//		for (int i = 0; i < m_size; i++) {
//			result.m_array[i] = m_array[i] - src.m_array[i];
//		}
//		return result;
//	};
//	dMatrix<Type> operator/(dMatrix<Type>& src) const {
//		if (m_cols != src.m_rows) {
//			char chbuff[100];
//			sprintf(chbuff, "Cant devide matrices (%d/%d columns/rows by %d/%d columns/rows)",
//				m_cols, m_rows, src.m_cols, src.m_rows);
//			throw std::exception(chbuff);
//		}
//		int resulting_size = m_rows * src.m_rows;
//		dMatrix<Type> result(m_rows, src.m_rows);
//		for (int bcol = 0; bcol < m_cols; bcol++) {
//			for (int brow = 0; brow < m_rows; brow++) {
//				for (int row = 0; row < src.m_rows; row++) {
//					for (int col = 0; col < src.m_cols; col++) {
//						result.m_array[bcol * src.m_rows + brow] +=
//							src.m_array[col * src.m_rows + row] / m_array[bcol * m_rows + brow];
//					}
//				}
//			}
//		}
//		return result;
//	};
//	dMatrix<Type> operator/(int div) const {
//		dMatrix<Type> result(m_rows, m_cols);
//		for (int i = 0; i < m_size; i++) {
//			result.m_array[i] = m_array[i] / div;
//		}
//		return result;
//	};
//	dMatrix<Type> operator/(float div) const {
//		dMatrix<Type> result(m_rows, m_cols);
//		for (int i = 0; i < m_size; i++) {
//			result.m_array[i] = m_array[i] / div;
//		}
//		return result;
//	};
//	Type& operator[](int index) {
//		if (!(index < m_cols and index > -m_cols))
//			throw std::exception("Index out of range for Vector");
//		if (m_cols > 1) 
//
//		else
//			return index >= 0 ? m_array[0][index] : m_array[0][m_rows - 1 + index];
//	};
//	Type** get2dArray() {
//		Type** result = new Type*[m_rows];
//		Type* cresult = new Type[m_cols];
//		for (int brow = 0; brow < m_rows; brow++) {
//			for (int bcol = 0; bcol < m_cols; bcol++) {
//				cresult[bcol] = this->get(brow, bcol);
//			}
//			result[brow] = cresult;
//		}
//		return result;
//	}
//	~dMatrix() {
//		free(m_array);
//	};
//private:
//	std::shared_ptr<Type*> m_array;
//	int m_size;
//	int m_rows;
//	int m_cols;
//};


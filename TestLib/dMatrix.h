#pragma once
#include <exception>
#include <algorithm>
#include <memory>
#include <vector>
#include <array>
#include <initializer_list>

template<class Type = float, int rows = 3, int cols = 3>
class dMatrix {
public:
	dMatrix() : 
		m_cols(cols), m_rows(rows), m_size(cols * rows) {
		mp_arr = std::shared_ptr<std::array<std::array<Type, rows>, cols>>(new std::array<std::array<Type, rows>, cols>());
		m_arr = *mp_arr;
		for (int i = 0; i < m_cols; i++) {
			std::array<Type, rows> col;
			col.fill(Type());
			m_arr.at(i) = col;
		}
	}
	dMatrix(std::initializer_list<Type> list) : 
		dMatrix<Type, rows, cols>() {
		int msize = static_cast<int>(list.size());
		int count = 0;
		for (auto elem : list) {
			m_arr.at(count / m_rows).at(count % m_rows) = static_cast<Type>(elem);
			if (++count == m_size) 
				break;
		}
	}
	std::array<Type, rows>& operator[](int index) {
		return m_arr.at(index);
	}
	Type get(int row, int col = 0) const {
		return m_arr.at(col).at(row);
	}
	void set(Type val, int row, int col = 0) {
		m_arr.at(col).at(row) = val;
	}
	Type& at(int arow, int acol = 0){
		return static_cast<Type&>(m_arr.at(acol).at(arow));
	}
	template <class Type, int src_rows, int src_cols>
	dMatrix<Type, src_rows, src_cols>& operator=(const dMatrix<Type, src_rows, src_cols>&& rsrc) {
		if (this != &rsrc) {
		mp_arr = rsrc.get_arr_ptr();
		m_arr = *mp_arr;
		m_size = rsrc.get_size();
		m_cols = rsrc.get_cols();
		m_rows = rsrc.get_rows();
		}
		return *this;
	}
	template <class Type, int src_rows, int src_cols>
	dMatrix<Type, rows, src_cols> operator*(dMatrix<Type, src_rows, src_cols>&& src) {
		if (get_cols() != src.get_rows()) {
			throw std::exception("Cant multiply matrices! Did you try to multiply vectors?");
		}
		int resulting_size = get_rows() * src.get_rows();
		dMatrix<Type, rows, 1> result;
		for (int bcol = 0; bcol < get_cols(); bcol++) {
			for (int brow = 0; brow < get_rows(); brow++) {
				for (int row = 0; row < src.get_rows(); row++) {
					for (int col = 0; col < src.get_cols(); col++) {
						result[brow][bcol] +=
							m_arr[brow][bcol] * src[row][col];
					}
				}
			}
		}
		return result;
	}
	template <class Type,int src_rows, int src_cols>
	dMatrix(const dMatrix<Type, src_rows, src_cols>& src):
		dMatrix<Type, src_rows, src_cols>()
	{
		for (int col = 0; col < src_cols; col++) {
			for (int row = 0; row < src_rows; row++) {
				this->at(row, col) = src.get(row, col);
			}
		}
	}
	dMatrix<Type, rows, cols>& copy(const dMatrix<Type, rows, cols>& src) {
		for (int col = 0; col < src.get_cols(); col++) {
			for (int row = 0; row < src.get_rows(); row++) {
				this->at(row, col) = src.get(row, col);
			}
		}
		return *this;
	}


	template <class Type, int res_rows = rows, int res_cols = cols>
	dMatrix<Type, res_rows, res_cols> operator*(dMatrix<Type, res_rows, res_cols>& src) const {
		if (m_cols != src.get_rows()) {
			char chbuff[100];
			sprintf_s(chbuff, "Cant multiply matrices (%d/%d columns/rows by %d/%d columns/rows)",
				m_cols, m_rows, src.get_cols(), src.get_rows());
			throw std::exception(chbuff);
		}
		int resulting_size = m_rows * src.get_rows();
		dMatrix<Type, res_rows, res_cols> result;
		for (int bcol = 0; bcol < m_cols; bcol++) {
			for (int brow = 0; brow < m_rows; brow++) {
				for (int row = 0; row < src.get_rows(); row++) {
					for (int col = 0; col < src.get_cols(); col++) {
						result[brow][bcol] +=
							m_arr[brow][bcol] * src[row][col];
					}
				}
			}
		}
		return result;
	};
	~dMatrix() {
	}
	int get_size() const{
		return m_size;
	}
	int get_rows() const {
		return m_rows;
	}
	int get_cols() const {
		return m_cols;
	}
	std::shared_ptr<std::shared_ptr<std::array<std::array<Type, rows>, cols>>> get_arr_ptr() const{
		return mp_arr;
	}
private:
	std::shared_ptr<std::array<std::array<Type, rows>, cols>> mp_arr;
	std::array<std::array<Type, rows>, cols> m_arr;
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
//		if (m_cols != src.get_rows()) {
//			char chbuff[100];
//			sprintf_s(chbuff, "Cant multiply matrices (%d/%d columns/rows by %d/%d columns/rows)",
//				m_cols, m_rows, src.m_cols, src.get_rows());
//			throw std::exception(chbuff);
//		}
//		int resulting_size = m_rows * src.get_rows();
//		dMatrix<Type> result(m_rows, src.get_rows());
//		for (int bcol = 0; bcol < m_cols; bcol++) {
//			for (int brow = 0; brow < m_rows; brow++) {
//				for (int row = 0; row < src.get_rows(); row++) {
//					for (int col = 0; col < src.m_cols; col++) {
//						result.m_array[bcol * src.get_rows() + brow] +=
//							src.m_array[col * src.get_rows() + row] * m_array[bcol * m_rows + brow];
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
//		if (m_rows != src.get_rows() or m_cols != src.m_cols)
//			throw std::exception("Incompatible matrices!");
//		dMatrix<Type> result(m_rows, m_cols);
//		for (int i = 0; i < m_size; i++) {
//			result.m_array[i] = m_array[i] + src.m_array[i];
//		}
//		return result;
//	};
//	dMatrix<Type> operator-(dMatrix<Type>& src) const {
//		if (m_rows != src.get_rows() or m_cols != src.m_cols)
//			throw std::exception("Incompatible matrices!");
//		dMatrix<Type> result(m_rows, m_cols);
//		for (int i = 0; i < m_size; i++) {
//			result.m_array[i] = m_array[i] - src.m_array[i];
//		}
//		return result;
//	};
//	dMatrix<Type> operator/(dMatrix<Type>& src) const {
//		if (m_cols != src.get_rows()) {
//			char chbuff[100];
//			sprintf(chbuff, "Cant devide matrices (%d/%d columns/rows by %d/%d columns/rows)",
//				m_cols, m_rows, src.m_cols, src.get_rows());
//			throw std::exception(chbuff);
//		}
//		int resulting_size = m_rows * src.get_rows();
//		dMatrix<Type> result(m_rows, src.get_rows());
//		for (int bcol = 0; bcol < m_cols; bcol++) {
//			for (int brow = 0; brow < m_rows; brow++) {
//				for (int row = 0; row < src.get_rows(); row++) {
//					for (int col = 0; col < src.m_cols; col++) {
//						result.m_array[bcol * src.get_rows() + brow] +=
//							src.m_array[col * src.get_rows() + row] / m_array[bcol * m_rows + brow];
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


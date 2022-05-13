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
		m_cols(cols), m_rows(rows){
		mp_arr = std::shared_ptr<std::array<std::array<Type, rows>, cols>>(new std::array<std::array<Type, rows>, cols>());
		for (int i = 0; i < m_cols; i++) {
			std::array<Type, rows> col;
			col.fill(Type());
			arr().at(i) = col;
		}
	}
	dMatrix(std::initializer_list<Type> list) : 
		dMatrix<Type, rows, cols>() {
		int msize = static_cast<int>(list.size());
		int count = 0;
		for (auto elem : list) {
			arr().at(count / m_rows).at(count % m_rows) = static_cast<Type>(elem);
			if (++count == (rows * cols)) 
				break;
		}
	}
	Type get(int row, int col = 0) const {
		return arr().at(col).at(row);
	}
	void set(Type val, int row, int col = 0) {
		arr().at(col).at(row) = val;
	}
	Type& at(int arow, int acol = 0)  const {
		return static_cast<Type&>(arr().at(acol).at(arow));
	}
	template <class Type, int src_rows, int src_cols>
	dMatrix<Type, src_rows, src_cols>& operator=(dMatrix<Type, src_rows, src_cols>&& rsrc) {
		if (this != &rsrc) {
		mp_arr = rsrc.get_arr_ptr();
		arr() = *mp_arr;
		m_cols = rsrc.get_cols();
		m_rows = rsrc.get_rows();
		}
		return *this;
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
	dMatrix<Type, rows, cols>& copy(dMatrix<Type, rows, cols>& src) {
		for (int col = 0; col < src.get_cols(); col++) {
			for (int row = 0; row < src.get_rows(); row++) {
				this->at(row, col) = src.get(row, col);
			}
		}
		return *this;
	}

	dMatrix<Type, rows, cols> getCopy() {
		dMatrix<Type, rows, cols> result;
		for (int col = 0; col < m_cols; col++) {
			for (int row = 0; row < m_rows; row++) {
				result.at(row, col) = this->at(row, col);
			}
		}
		return result;
	}

	template <class Type, int src_rows, int src_cols>
	dMatrix<Type, src_rows, cols> operator*(dMatrix<Type, src_rows, src_cols>& src) {
		if (m_rows != src.get_cols())
			throw std::exception("Cant multiply matrices of these sizes! (Or you did Matrix * Vector?)");
		dMatrix<Type, src_rows, cols> result;  // Yesli viletel, to lox yopta UwU
		for (int rescol = 0; rescol < cols; rescol++) {
			for (int resrow = 0; resrow < src_rows; resrow++) {
				for (int src_row = 0 ; src_row < src.get_rows(); src_row++) {
					auto base = this->at(src_row, rescol);
					auto other = src.at(resrow, src_row);
					result.at(resrow, rescol) += (base * other);
				}	
			}
		}
		return result;
	};
	~dMatrix() {
	}
	template <class Type, int res_rows = rows, int res_cols = cols>
	dMatrix<Type,res_rows, res_cols> operator+(dMatrix<Type>& src) const {
		if (m_rows != src.get_rows() or m_cols != src.m_cols)
			throw std::exception("Incompatible matrices!");
		dMatrix<Type, res_rows, res_cols> result;
		for (int bcol = 0; bcol < res_cols; bcol++) {
			for (int brow = 0; brow < res_rows; brow++) {
				result.at(brow, bcol) = arr().at(brow, bcol) + src.at(brow, bcol);
			}
		}
	return result;
	};
	int get_rows() const {
		return m_rows;
	}
	int get_cols() const {
		return m_cols;
	}
	std::shared_ptr<std::shared_ptr<std::array<std::array<Type, rows>, cols>>> get_arr_ptr() const{
		return mp_arr;
	}
	std::array<std::array<Type, rows>, cols>& arr() const{
		return *mp_arr;
	}
	template <class Type, int src_rows, int src_cols>
	std::array<std::array<Type, src_rows>, src_cols>& arr() {
		return *mp_arr;
	}
private:
	std::shared_ptr<std::array<std::array<Type, rows>, cols>> mp_arr;
	int m_rows;
	int m_cols;
};




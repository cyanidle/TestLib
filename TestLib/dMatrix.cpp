#include "dMatrix.h"

template<class Type>
dMatrix<Type>::dMatrix(int cols, int rows):m_size(cols*rows),m_cols(cols),m_rows(rows) {
	m_array = malloc(sizeof(Type)* m_size);
	for (Type* ptr = m_array; ptr != m_array + m_size - 1; ptr++) {
		*ptr = 0.0;
	}
}

template<class Type>
dMatrix<Type>::dMatrix()
{
	m_array = new Type[9]{};
}

template<class Type>
dMatrix<Type>& dMatrix<Type>::operator=(dMatrix& src)
{
	for (int i = 0; i < m_size; i++) {
		m_array[i] = src.m_array[i];
	}
	return *this;
}

template<class Type>
dMatrix<Type>& dMatrix<Type>::operator=(dMatrix&& rsrc)
{
	if (this != &rsrc) {
		delete[] m_array;
		m_order = other.m_order;
		mp_flat_vect = new float[m_order + 1];
		std::copy(rsrc.m_array, rsrc.mp_flat_vect + m_size - 1, m_array);
		rsrc.mp_flat_vect = nullptr;
		rsrc.m_order = 0;
	}
	return *this;
}

template<class Type>
dMatrix<Type> dMatrix<Type>::operator*(dMatrix<Type>& src) const {
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
}

template<class Type>
dMatrix<Type> dMatrix<Type>::operator*(int) const
{
	return dMatrix<Type>();
}

template<class Type>
dMatrix<Type> dMatrix<Type>::operator*(float) const
{
	return dMatrix<Type>();
}

template<class Type>
dMatrix<Type> dMatrix<Type>::operator+(dMatrix&) const
{
	dMatrix<Type> result();
	return result;
}

template<class Type>
dMatrix<Type> dMatrix<Type>::operator-(dMatrix&) const
{
	dMatrix<Type> result();
	return result;
}

template<class Type>
dMatrix<Type> dMatrix<Type>::operator/(dMatrix&) const
{
	dMatrix<Type> result();
	return result;
}

template<class Type>
dMatrix<Type> dMatrix<Type>::operator/(int) const
{
	return dMatrix<Type>();
}

template<class Type>
dMatrix<Type> dMatrix<Type>::operator/(float) const
{
	return dMatrix<Type>();
}

template<class Type>
Type& dMatrix<Type>::operator[](int index)
{
	if (!(index < m_size and index > -m_size))
		throw std::exception("Index out of range for Vector");
	return index >= 0 ? &m_array[index] : &m_array[m_size - 1 + index];
}

template<class Type>
dMatrix<Type>::~dMatrix()
{
	free(m_array);
}

#include "dMatrix.h"

template<class Type>
dMatrix<Type>::dMatrix(int rows, int cols):m_size(cols*rows),m_cols(cols),m_rows(rows) 

template<class Type>
dMatrix<Type>::dMatrix()


template<class Type>
dMatrix<Type>& dMatrix<Type>::operator=(dMatrix& src)


template<class Type>
dMatrix<Type>& dMatrix<Type>::operator=(dMatrix&& rsrc)


template<class Type>
dMatrix<Type> dMatrix<Type>::operator*(dMatrix<Type>& src) const 

template<class Type>
dMatrix<Type> dMatrix<Type>::operator*(int mult) const


template<class Type>
dMatrix<Type>& dMatrix<Type>::invert()


template<class Type>
float dMatrix<Type>::det()


template<class Type>
dMatrix<Type>& dMatrix<Type>::transpose()


template<class Type>
dMatrix<Type> dMatrix<Type>::operator*(float mult) const


template<class Type>
dMatrix<Type> dMatrix<Type>::operator+(dMatrix& src) const


template<class Type>
dMatrix<Type> dMatrix<Type>::operator-(dMatrix& src) const


template<class Type>
dMatrix<Type> dMatrix<Type>::operator/(dMatrix& src) const


template<class Type>
dMatrix<Type> dMatrix<Type>::operator/(int div) const


template<class Type>
dMatrix<Type> dMatrix<Type>::operator/(float div) const


template<class Type>
Type& dMatrix<Type>::operator[](int index)


template<class Type>
Type& dMatrix<Type>::get(int row, int col)


template<class Type>
dMatrix<Type>::~dMatrix()


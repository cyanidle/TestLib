#pragma once
template<class Type>
class dMatrix {
public:
	dMatrix(int cols, int rows);
	dMatrix();
	dMatrix<Type>& operator=(dMatrix&);
	dMatrix<Type>& operator=(dMatrix&&);
	dMatrix<Type> operator*(dMatrix&) const;
	dMatrix<Type> operator*(int) const;
	dMatrix<Type> operator*(float) const;
	dMatrix<Type> operator+(dMatrix&) const;
	dMatrix<Type> operator-(dMatrix&) const;
	dMatrix<Type> operator/(dMatrix&) const;
	dMatrix<Type> operator/(int) const;
	dMatrix<Type> operator/(float) const;
	Type& operator[](int index);
	~dMatrix();
private:
	Type* m_array;
	int m_size;
	int m_rows;
	int m_cols;
};


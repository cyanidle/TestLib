#pragma once
template<class Type>
class dMatrix {
public:
	dMatrix(int cols, int rows);
	dMatrix();
	Type& get(int, int = 0);
	dMatrix<Type>& operator=(dMatrix&);
	dMatrix<Type>& operator=(dMatrix&&);
	dMatrix<Type> operator*(dMatrix&) const;
	dMatrix<Type> operator*(int) const;
	dMatrix<Type>& invert();
	float det();
	dMatrix<Type>& transpose();
	dMatrix<Type> operator*(float) const;
	dMatrix<Type> operator+(dMatrix&) const;
	dMatrix<Type> operator-(dMatrix&) const;
	dMatrix<Type> operator/(dMatrix&) const;
	dMatrix<Type> operator/(int) const;
	dMatrix<Type> operator/(float) const;
	Type& operator[](int);
	~dMatrix();
private:
	Type* m_array;
	int m_size;
	int m_rows;
	int m_cols;
};


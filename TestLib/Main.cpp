#include "dMatrix.h"
#include <iostream>

dMatrix<float, 1, 1> test() {
	dMatrix<float, 1, 1> mat2{ 1 };
	return mat2;
}

int main(int argc, char* argv[]) {
	dMatrix<float> mat0{ 1,2,3,4,5,6,7,8,9 };
	dMatrix<float> mat0b{ 1,4,7,2,5,8,3,6,9 };
	dMatrix<float, 3, 1> mat1{ 1,2,3};
	mat1.at(0);
	auto mat3 = test();
	dMatrix<float, 2> mat4;
	//mat4.copy(mat1);
	auto new_mat = mat0b * mat0;
	auto new_vect = mat1 * mat0b;
	printf("kek");
}
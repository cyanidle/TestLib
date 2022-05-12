#include "dMatrix.h"
#include <iostream>

dMatrix<float, 1, 1> test() {
	dMatrix<float, 1, 1> mat2{ 1 };
	return mat2;
}

int main(int argc, char* argv[]) {
	dMatrix<float> mat0{1,2,3,4,5};
	dMatrix<float, 2> mat1{ 1,2,3,4,5,6,7,8,9 };
	mat1[0];
	auto mat3 = test();
	dMatrix<float, 2> mat4;
	mat4.copy(mat1);
	auto pmat;
	printf("kek");
}
#include "dMatrix.h"
#include <iostream>

dMatrix<float, 1, 1> test() {
	dMatrix<float, 1, 1> mat2{ 1 };
	return mat2;
}

int main(int argc, char* argv[]) {
	dMatrix<float> mat0{1,2,3,4,5};
	dMatrix<float, 2> mat1{ 1,2,3,4,5,6,7,8,9 };
	auto mat3 = test();
	auto mat4(mat3);
	printf("kek");
}
//#include "dLinearAlg.h"
//
//dTransformer2d::dTransformer2d(float rot = 0, float scale = 0, float transform = 0) 
//{
//
//}
//
//
//dPoint2f::dPoint2f(float x, float y, float theta = 0):m_theta(theta)
//{
//
//}
//
//dTransMatrix::~dTransMatrix() {
//	free(mp_flat_array);
//}
//dTransMatrix::dTransMatrix(float rotation, float scale, float move,
//	int order,float move_coeff,
//	const dVect rot_vect,
//	const dVect scale_vect,
//	const dVect move_vect) : m_order(order), m_size((order + 1)* (order + 1)) {
//	// init flat array
//	mp_flat_array = new float[m_size] {0};
//	mp_flat_array[m_size] = 1;
//	// Generating matrix for each axis
//	dTransMatrix** p_storage = new dTransMatrix*[order];
//	for (int curr_basis = 0; curr_basis < order; curr_basis ++){
//		float current_rotation = rotation * rot_vect[curr_basis];
//		p_storage[curr_basis] = new dTransMatrix(current_rotation, order, curr_basis);
//	}
//	// Applying scale ...
//	// Applying move ...
//	// Multiplying matrixes to get final Matrix...
//}
//
//dTransMatrix::dTransMatrix(float rotation, int order, int axis)
//	: m_order(order), m_size((order + 1)* (order + 1))
//{
//	// init flat array
//	mp_flat_array = new float[m_size] {0};
//	mp_flat_array[m_size] = 1;
//	// Generating matrix for current axis
//	for (int curr_part_axis = 0; curr_part_axis < order; curr_part_axis++) {
//		for (int curr_part_row = 0; curr_part_row < order; curr_part_row++) {
//			int diff = curr_part_row - curr_part_axis;
//			int sign = 0;
//			if (diff == 0) {
//				mp_flat_array[curr_part_axis * (order + 1) + curr_part_row] = 1;
//			}
//			else if (curr_part_axis == axis and curr_part_row == axis) {
//				mp_flat_array[curr_part_axis * (order + 1) + curr_part_row] = cos(rotation);
//			}
//			else if (diff > 0) {
//				sign = -1 * (1 - diff % 2); // set sign for sin
//			}
//			else {
//				sign = -1 * (1 - abs(diff + 1) % 2);
//			}
//			if (sign != 0) {
//				mp_flat_array[curr_part_axis * (order + 1) + curr_part_row] = sign * sinf(rotation);
//			}
//		}
//	}
//}
//
//dTransMatrix& dTransMatrix::operator=(dTransMatrix&)
//{
//	// TODO: вставьте здесь оператор return
//}
//
//dTransMatrix dTransMatrix::operator*(dTransMatrix&) const{
//
//}
//
//dTransMatrix dTransMatrix::operator+(dTransMatrix&) const
//{
//	return dTransMatrix();
//}
//
//
//
//dVect::dVect(std::vector<float>, float order, float theta)
//{
//}
//
//dVect::dVect(float x, float y, float z, float theta)
//{
//}
//
//dVect& dVect::operator=(dVect& other) {
//	for (int i = 0; i < m_order; i++) {
//		mp_flat_vect[i] = other.mp_flat_vect[i];
//	}
//	return *this;
//}
//float dVect::operator[](int index) const{
//	if (index > (m_order + 1) or index < (-m_order - 1))
//		throw std::exception("Index out of range for Vector");
//	return index >= 0 ? mp_flat_vect[index] : mp_flat_vect[m_order + 1 + index];
//}
//dVect& dVect::applyTrans(dTransMatrix)
//{
//	// TODO: вставьте здесь оператор return
//}
//dVect dVect::operator*(dTransMatrix&) const
//{
//	return dVect();
//}
//dVect& dVect::applyRotate(float)
//{
//	// TODO: вставьте здесь оператор return
//}
//dVect& dVect::applyScale(float)
//{
//	// TODO: вставьте здесь оператор return
//}
//dVect& dVect::applyMove(float)
//{
//	// TODO: вставьте здесь оператор return
//}
//dVect& dVect::operator=(dVect&& other) { //либо меня студио наебывает, либо я чего то не понимаю
//	if (this != &other){
//		delete[] mp_flat_vect;
//		m_order = other.m_order;
//		mp_flat_vect = new float[m_order + 1];
//		std::copy(other.mp_flat_vect, other.mp_flat_vect + m_order + 1, mp_flat_vect);
//		other.mp_flat_vect = nullptr;
//		other.m_order = 0;
//	}
//	return *this;
//} 
//dVect::dVect(dVect&& rval)
//	:mp_flat_vect(rval.mp_flat_vect),m_order(rval.m_order) 
//{
//	rval.mp_flat_vect = nullptr;
//	rval.m_order = 0;
//}
//dVect dVect::operator*(dVect&) const
//{
//	return dVect();
//}
//dVect dVect::operator+(dVect&) const
//{
//	return dVect();
//}
//dVect dVect::operator-(dVect&) const
//{
//	return dVect();
//}
//dVect dVect::operator/(dVect&) const
//{
//	return dVect();
//}
//dVect::~dVect() {
//	free(mp_flat_vect);
//}
//
//dTransMatrix dTransMatrix::operator-(dTransMatrix&) const
//{
//	return dTransMatrix();
//}
//
//dTransMatrix dTransMatrix::operator/(dTransMatrix&) const
//{
//	return dTransMatrix();
//}
//
//dVect& dTransMatrix::apply(dVect&)
//{
//	// TODO: вставьте здесь оператор return
//}
//
//dTransMatrix& dTransMatrix::changeRot(float)
//{
//	// TODO: вставьте здесь оператор return
//}
//
//dTransMatrix& dTransMatrix::changeScale(float)
//{
//	// TODO: вставьте здесь оператор return
//}
//
//dTransMatrix& dTransMatrix::changeMove(float)
//{
//	// TODO: вставьте здесь оператор return
//}
//

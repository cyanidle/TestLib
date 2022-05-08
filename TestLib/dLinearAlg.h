//#pragma once
//#include <float.h>
//#include <vector>
//#include <array>
//
//
//
//class dTransMatrix {
//public:
//	dTransMatrix(float rotation = 0.0, float scale = 0.0, float move = 0.0,
//		int order = 2, float = 1.0,
//		const dVect = dVect(0.0, 0.0),
//		const dVect = dVect(0.0, 0.0),
//		const dVect = dVect(0.0, 0.0));
//	dTransMatrix(float rotation, int order, int axis);
//	dTransMatrix& operator=(dTransMatrix&);
//	dTransMatrix operator*(dTransMatrix&) const;
//	dTransMatrix operator+(dTransMatrix&) const;
//	dTransMatrix operator-(dTransMatrix&) const;
//	dTransMatrix operator/(dTransMatrix&) const;
//	dVect& apply(dVect&);
//	dTransMatrix& changeRot(float);
//	dTransMatrix& changeScale(float);
//	dTransMatrix& changeMove(float);
//	~dTransMatrix();
//protected:	
//	int m_size;
//	int m_order;
//	float* mp_flat_array;
//};
//class dVect {
//public:
//	dVect(std::vector<float>, float order = 2, float theta = 0);
//	dVect(float x = 0, float y = 0);
//	//
//	dVect& operator=(dVect&);
//	dVect& operator=(dVect&&); // ne jebu
//	dVect(dVect&&);
//	//
//	dVect operator*(dVect&) const;
//	dVect operator+(dVect&) const;
//	dVect operator-(dVect&) const;
//	dVect operator/(dVect&) const;
//	float operator[](int) const;
//	
//	dVect& applyTrans(dTransMatrix);
//	dVect operator*(dTransMatrix&) const;
//	dVect& applyRotate(float);
//	dVect& applyScale(float);
//	dVect& applyMove(float);
//	~dVect();
//protected:
//	int m_order;
//	float* mp_flat_vect;
//};
//class dPoint2f : public dVect
//{
//public:
//	dPoint2f(float x = 0, float y = 0, float theta = 0);
//private:
//	std::array<float, 2> m_point;
//	float m_theta;
//};
//class dTransformer2d : public dTransMatrix
//{
//public:
//	dTransformer2d(float = 0, float = 0, float = 0);
//private:
//	std::array<float, 9> m_mat;
//};

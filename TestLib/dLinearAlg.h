#pragma once
#include <float.h>
#include <vector>
#include <array>
class dMatrix {
public:
	dMatrix(float = 0, float = 0, float = 0); // just rotation
	virtual dMatrix& operator=(dMatrix&) noexcept;
	virtual dMatrix operator*(dMatrix) const;
	virtual dMatrix operator+(dMatrix) const;
	virtual dMatrix operator-(dMatrix) const;
	virtual dMatrix operator/(dMatrix) const;
	virtual dVect& apply(dVect&);
	virtual dMatrix& changeRot(float);
	virtual dMatrix& changeScale(float);
	virtual dMatrix& changeMove(float);
protected:	
	unsigned int m_size;
};
class dVect {
public:
	dVect(std::vector<float>);
	dVect(float = 0, float = 0, float = 0);
	virtual dVect& operator=(dVect&) noexcept;
	virtual dVect operator*(dVect&) const;
	virtual dVect operator+(dVect&) const;
	virtual dVect operator-(dVect&) const;
	virtual dVect operator/(dVect&) const;
	//
	virtual dVect& applyTrans(dMatrix);
	virtual dVect operator*(dMatrix&) const;
	virtual dVect& applyRotate(float);
	virtual dVect& applyScale(float);
	virtual dVect& applyMove(float);
protected:
	unsigned int m_size;
};
class dPoint2f : private dVect
{
public:
	dPoint2f(float = 0, float = 0, float = 0);
	dPoint2f& operator*(dTransformer2d);
	dPoint2f& operator=(dPoint2f&) noexcept;
	dPoint2f& operator*(dPoint2f&);
	dPoint2f& operator+(dPoint2f&);
	dPoint2f& operator-(dPoint2f&);
	dPoint2f& operator/(dPoint2f&);
private:
	std::array<float, 2> m_point;
	float m_theta;
};
class dTransformer2d : private dMatrix
{
public:
	dTransformer2d(float = 0, float = 0, float = 0);
	
private:
	std::array<float, 9> m_mat;
};

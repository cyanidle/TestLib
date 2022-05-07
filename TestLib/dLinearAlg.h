#pragma once
#include <float.h>

class dMatrix {
public:
	virtual dMatrix& operator=(dMatrix&) noexcept;
	virtual dMatrix& operator*(dMatrix&);
	virtual dMatrix& operator+(dMatrix&);
	virtual dMatrix& operator-(dMatrix&);
	virtual dMatrix& operator/(dMatrix&);
protected:	
	unsigned int m_size;
};
class dVect {
public:
	virtual dVect& operator=(dVect&) noexcept;
	virtual dVect& operator*(dVect&);
	virtual dVect& operator+(dVect&);
	virtual dVect& operator-(dVect&);
	virtual dVect& operator/(dVect&);
protected:
	unsigned int m_size;
};
class dPoint2f : private dVect
{
public:
	dPoint2f();
	dPoint2f(float);
	dPoint2f(float, float);
	dPoint2f& applyTrans(dTransformer2d);
	dPoint2f& operator*(dTransformer2d);
	dPoint2f& applyRotate(float);
	dPoint2f& applyScale(float);
	dPoint2f& applyMove(float);
	dPoint2f& operator=(dPoint2f&) noexcept;
	dPoint2f& operator*(dPoint2f&);
	dPoint2f& operator+(dPoint2f&);
	dPoint2f& operator-(dPoint2f&);
	dPoint2f& operator/(dPoint2f&);
private:
	float m_point[];
};
class dTransformer2d : private dMatrix
{
public:
	dTransformer2d(float, float = 0, float = 0);
	dTransformer2d(float);
	dPoint2f apply(dPoint2f);
	dPoint2f& apply(dPoint2f&);
	dTransformer2d& changeRot(float);
	dTransformer2d& changeScale(float);
	dTransformer2d& changeMove(float);
private:
	float m_mat[];
};

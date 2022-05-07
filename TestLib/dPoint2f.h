#pragma once
#include <float.h>

class dPoint2f
{
public:
	dPoint2f();
	dPoint2f(float);
	dPoint2f(float, float);
	dPoint2f& applyTrans(dTransformer2d);
	dPoint2f& applyRotate(float);
	dPoint2f& applyMove(float);
	dPoint2f& applyScale(float);
	dPoint2f& operator=(dPoint2f&);
	dPoint2f& operator*(dPoint2f&);
	dPoint2f& operator+(dPoint2f&);
	dPoint2f& operator-(dPoint2f&);
	dPoint2f& operator/(dPoint2f&);
private:
	float m_point[2];
};
class dTransformer2d {
public:
	dTransformer2d(float, float = 0, float = 0);
	dTransformer2d(float);
	dPoint2f apply(dPoint2f);
	dPoint2f& apply(dPoint2f&);
	dTransformer2d& changeRot(float);
	dTransformer2d& changeScale(float);
	dTransformer2d& changeMove(float);
private:
	float m_mat[9];
};

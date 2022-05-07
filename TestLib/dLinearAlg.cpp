#include "dLinearAlg.h"

dTransformer2d::dTransformer2d(float rot = 0, float scale = 0, float transform = 0) 
{
	m_size = 9;
}


dPoint2f::dPoint2f(float x, float y, float theta = 0):m_theta(theta) {

}

#ifndef __X_MATH_H_
#define __X_MATH_H_
#include "CommonConvert.h"

#define PI			3.1415926f

class CPoint2d
{
public:
	float m_x;
	float m_y;


	CPoint2d(float _x=0.0f,float _y=0.0f )
	{
		m_x = _x;
		m_y = _y;
	}


	 CPoint2d&  operator *=(float v)
	{
		m_x *= v;
		m_y *= v;
		return *this;
	}

	 CPoint2d& operator /=(float v)
	{
		m_x /= v;
		m_y /= v;
		return *this;
	}


	inline  CPoint2d& operator -=(float v)
	{
		m_x -= v;
		m_y -= v;
		return *this;
	}


	inline  CPoint2d& operator +=(float v)
	{
		m_x += v;
		m_y += v;
		return *this;
	}

	inline  CPoint2d& operator +=(const  CPoint2d& v)
	{
		m_x += v.m_x;
		m_y += v.m_y;
		return *this;
	}

	inline  bool operator ==(CPoint2d& pt)
	{
		if(pt.m_x==m_x&&pt.m_y==m_y)
		{
			return true;
		}
		return false;
	}


	float GetDistance(CPoint2d pos)
	{
		return sqrt(float(pow(fabs(pos.m_x-m_x),2)+pow(fabs(pos.m_y-m_y),2)));
	}

	bool From(std::string str)
	{
		m_x = CommonConvert::StringToFloat(str.substr(0, str.find_first_of(',')).c_str());
		m_y = CommonConvert::StringToFloat(str.substr(str.find_last_of(',')).c_str());
		return true;
	}
};


inline CPoint2d operator +(const CPoint2d& pos,float v)
{
	return CPoint2d(pos.m_x+v,pos.m_y+v);
}


inline CPoint2d operator +(const CPoint2d& pos,const CPoint2d& v)
{
	return CPoint2d(pos.m_x+v.m_x,pos.m_y+v.m_y);
}
inline CPoint2d operator -(const CPoint2d& pos,const CPoint2d& v)
{
	return CPoint2d(pos.m_x-v.m_x,pos.m_y-v.m_y);
}

inline CPoint2d operator -(const CPoint2d& pos,float v)
{
	return CPoint2d(pos.m_x-v,pos.m_y-v);
}

inline CPoint2d operator *(const CPoint2d& pos,float v)
{
	return CPoint2d(pos.m_x*v,pos.m_y*v);
}

inline CPoint2d operator / (const CPoint2d& pos,float v)
{
	return CPoint2d(pos.m_x/v,pos.m_y/v);
}



class Rect2d
{
public:
	float m_left,m_top,m_bottom,m_right;
	Rect2d(float _left,float _top,float _right,float _bottom)
	{
		m_left=_left;
		m_top=_top;
		m_bottom=_bottom;
		m_right=_right;
	};
	bool PtInRect(CPoint2d pt)
	{
		if(pt.m_x >= m_left && pt.m_y >= m_top && pt.m_x<=m_right && pt.m_y<=m_bottom)
		{
			return true;
		}
		return false;
	};
};


#endif //_MAP_H_
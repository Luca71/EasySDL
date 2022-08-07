#ifndef _MATHHELPER_H
#define _MATHHELPER_H
#include <math.h>


namespace EasySDL
{
	#define PI 3.14159265
	#define DEG_TO_RAD PI / 180.0f

	struct Vector2
	{
		float x;
		float y;
	
		Vector2(float _x = 0.0f, float _y = 0.0f) : x(_x), y(_y){}
	
		float MagnitudeSqr()
		{
			return x * x + y * y;
		}
	
		float Magnitude()
		{
			return (float)sqrt(x * x + y * y);
		}
	
		Vector2 Normalized()
		{
			float mag = Magnitude();
			return Vector2(x / mag, y / mag);
		}
	
		Vector2& operator +=(const Vector2& rhs)
		{
			x += rhs.x;
			y += rhs.y;
			return *this;
		}
	
		Vector2& operator -=(const Vector2& rhs)
		{
			x -= rhs.x;
			y -= rhs.y;
			return *this;
		}
	};
	
	inline Vector2 operator +(const Vector2& lhs, const Vector2& rhs)
	{
		return Vector2(lhs.x + rhs.x, lhs.y + rhs.y);
	}
	
	inline Vector2 operator -(const Vector2& lhs, const Vector2& rhs)
	{
		return Vector2(lhs.x - rhs.x, lhs.y - rhs.y);
	}
	
	inline Vector2 operator *(const Vector2& lhs, const float& rhs)
	{
		return Vector2(lhs.x * rhs, lhs.y * rhs);
	}
	
	/**
	* Rotate a Vector2
	*
	* @param vec = The vector to rotate
	* @param angle = Angle value in degrees
	* @return The rotated Vector2
	*/
	inline Vector2 RotateVector(Vector2& vec, float angle) {
		//converting the angle to radians to be used in sin and cos functions
		float radAngle = (float)(angle * DEG_TO_RAD);
	
		return Vector2((float)(vec.x * cos(radAngle) - vec.y * sin(radAngle)), (float)(vec.x * sin(radAngle) + vec.y * cos(radAngle)));
	}

	inline Vector2 Lerp(Vector2& start, Vector2& end, float time)
	{
		if (time <= 0.0f) { return start; }
		if (time >= 1.0f) { return end; }

		Vector2 dir = (end - start).Normalized();
		float mag = (end - start).Magnitude();

		return start + dir * mag * time;
	}

	const Vector2 VEC2_ZERO = { 0.0f, 0.0f };
	const Vector2 VEC2_ONE = { 1.0f, 1.0f };
	const Vector2 VEC2_UP = { 0.0f, 1.0f };
	const Vector2 VEC2_RIGHT = { 1.0f, 0.0f };
}


#endif // _MATHHELPER_H

// name: vector.h
// type: c++ header
// desc: class with implementation
// auth: is0urce

// 2-d point with real components

#pragma once

#include "coordinate.h"
#include "point.h"

namespace px
{
	class vector : public coordinate<float>
	{
	public:
		vector() : coordinate() {}
		vector(component x, component y) : coordinate(x, y) {}
		vector(const vector& vec2) : coordinate(vec2) {}
		vector(const point& point) : coordinate((component)point.X, (component)point.Y) {}

		vector& operator+=(const vector& rhs)
		{
			X += rhs.X;
			Y += rhs.Y;
			return *this;
		}
		vector& operator-=(const vector& rhs)
		{
			X -= rhs.X;
			Y -= rhs.Y;
			return *this;
		}
		vector moved(const vector& move) const { vector result = *this; return result += move; };
		vector clamped(const vector& min, const vector& max) const { return vector((std::min)((std::max)(min.X, X), max.X), (std::min)((std::max)(min.Y, Y), max.Y)); }
	};

	inline bool operator==(const vector& a, const vector& b) { return a.X == b.X && a.Y == b.Y; }
	inline bool operator!=(const vector& lhs, const vector& rhs) { return !operator==(lhs,rhs); }
	inline vector operator+(vector lhs, const vector& rhs) { lhs += rhs; return lhs; }
	inline vector operator-(vector lhs, const vector& rhs) { lhs -= rhs; return lhs; }
}

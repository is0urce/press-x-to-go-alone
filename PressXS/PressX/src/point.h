// name: point.h
// type: c++ header
// desc: class with implementation
// auth: is0urce

// 2-d point with integer components

#pragma once

#include "coordinate.h"

#include <algorithm>
#include <functional>

namespace px
{
	class point : public coordinate<int>
	{
	public:
		point() : coordinate() {}
		point(component x, component y) : coordinate(x, y) {}

		point& operator+=(const point& rhs)
		{
			X += rhs.X;
			Y += rhs.Y;
			return *this;
		}
		point& operator-=(const point& rhs)
		{
			X -= rhs.X;
			Y -= rhs.Y;
			return *this;
		}
		point moved(const point& move) const { point result = *this; return result += move; }
		point moved(component x, component y) const { return moved(point(x, y)); }
		point multiplied(const point &c) const { return point(X * c.X, Y * c.Y); }
		point multiplied(component w, component h) const { return multiplied(point(w, h)); }
		point multiplied(component c) const { return multiplied(c, c); }
		point clamped(const point& min, const point& max) const { return point((std::min)((std::max)(min.X, X), max.X), (std::min)((std::max)(min.Y, Y), max.Y)); }

		// enumerators
		void enumerate(const point &start, std::function<void(const point&)> enum_fn) const
		{
			point corner = start.moved(*this);
			for (int j = start.Y; j < corner.Y; ++j)
			{
				for (int i = start.X; i < corner.X; ++i)
				{
					enum_fn(point(i, j));
				}
			}
		}
		void enumerate(std::function<void(const point&)> enum_fn) const
		{
			enumerate(point(0, 0), enum_fn);
		}
	};

	inline bool operator==(const point& a, const point& b) { return a.X == b.X && a.Y == b.Y; }
	inline bool operator!=(const point& lhs, const point& rhs) { return !operator==(lhs, rhs); }
	inline point operator+(point lhs, const point& rhs) { lhs += rhs; return lhs; }
	inline point operator-(point lhs, const point& rhs) { lhs -= rhs; return lhs; }
}

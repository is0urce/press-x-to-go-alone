// name: enhancement.h
// type: c++
// desc: class header
// auth: is0urce

// statistics buffs and debuffs

#pragma once

#include "statistics.h"

namespace px
{
	namespace rl
	{
		class enhancement
		{
		private:
			statistics::attribute_t m_index;
			statistics::component m_modify;

		public:
			enhancement(attribute stat, int mod);
			~enhancement();

		public:
			void enhance(statistics &statistics) const;
			attribute attribute() const;
			int value() const;
		};
	}
}
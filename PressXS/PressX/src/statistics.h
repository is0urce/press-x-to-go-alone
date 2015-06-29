// name: Statistics.h
// type: c++
// desc: class header
// auth: is0urce

#pragma once

#include <vector>

namespace px
{
	namespace rl
	{
		enum class attribute : int;

		class statistics
		{
		public:
			typedef attribute attribute_t;
			typedef int component;
		private:
			std::vector<component> _values;

		public:
			statistics();
			~statistics();

		public:
			void clear();
			void enhance(attribute_t stat, component modify);
			component& operator[] (attribute_t n);
			const component& operator[] (attribute_t n) const;
		};
	}
}

#include "stdafx.h"

#include "statistics.h"
#include "attribute.h"

using namespace px;
using namespace px::rl;

statistics::statistics() : _values((std::vector<int>::size_type)attribute::max_attribute + 1, {})
{
}

statistics::~statistics()
{
}

void statistics::clear()
{
	std::fill(_values.begin(), _values.end(), 0);
}

void statistics::enhance(attribute_t stat, int modify)
{
	(*this)[stat] += modify;
}

const int& statistics::operator[](attribute_t stat) const
{
	return _values.at((int)stat);
}

int& statistics::operator[](attribute_t stat)
{
	return _values.at((int)stat);
}
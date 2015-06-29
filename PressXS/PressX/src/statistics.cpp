#include "stdafx.h"

#include "statistics.h"
#include "attribute.h"

using namespace px;
using namespace px::rl;

statistics::statistics() : m_values((std::vector<component>::size_type)attribute::max_attribute + 1, {})
{
}

statistics::~statistics()
{
}

void statistics::clear()
{
	std::fill(m_values.begin(), m_values.end(), 0);
}

void statistics::enhance(attribute_t stat, int modify)
{
	(*this)[stat] += modify;
}

const int& statistics::operator[](attribute_t stat) const
{
	return m_values.at((int)stat);
}

int& statistics::operator[](attribute_t stat)
{
	return m_values.at((int)stat);
}
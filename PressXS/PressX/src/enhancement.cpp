// name: enhancement.cpp
// type: c++
// desc: class implementation
// auth: is0urce

#include "stdafx.h"

#include "enhancement.h"

#include "statistics.h"

using namespace px;
using namespace px::rl;

enhancement::enhancement(statistics::attribute_t stat, statistics::component mod) : m_index(stat), m_modify(mod)
{
}

enhancement::~enhancement()
{
}

void enhancement::enhance(statistics &statistics) const
{
	statistics.enhance(m_index, m_modify);
}

statistics::attribute_t  enhancement::attribute() const
{
	return m_index;
}

int enhancement::value() const
{
	return m_modify;
}
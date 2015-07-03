// name: renderer.cpp
// type: c++ class implementation
// desc: opengl rendering
// auth: is0urce

#include "stdafx.h"

#include "renderer.h"

using namespace px;
using namespace px::shell;

renderer::renderer(renderer::opengl_handle opengl)
{
	if (!opengl) throw std::runtime_error("renderer::renderer(renderer::opengl_handle opengl) opengl is null");

	m_opengl.swap(opengl);
}

renderer::~renderer()
{
}

void renderer::draw(double span)
{
	m_opengl->update(m_width, m_height);
	m_aspect = m_width;
	m_aspect /= m_height;

	m_opengl->swap();
}
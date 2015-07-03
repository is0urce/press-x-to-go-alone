// name: vao.h
// type: c++ header
// desc: class declaration
// auth: is0urce

// vertex array object for opengl

#pragma once

#include "gl\glew.h"
#include <gl\gl.h>
#include <gl\glu.h>

#include <vector>
#include <memory>

namespace px
{
	namespace shell
	{
		struct vao
		{
		private:
			bool m_init;
			GLuint m_vao;
			unsigned int m_num; // number of attributes
			std::unique_ptr<unsigned int[]> m_depth; // attribute depth
			std::unique_ptr<GLuint[]> m_buffers;

			GLuint m_indices;
			unsigned int m_length; // size of index array

		public:
			vao() : m_init(false), m_num(0), m_length(0) {}

		public:
			// count - number of buffers
			// depth - array of buffer element size
			inline void init(unsigned int count, unsigned int* depths)
			{
				if (count == 0) throw std::runtime_error("vao::init - count == 0");

				if (m_init)
				{
					clear();
				}
				m_init = true;

				m_num = count;
				m_depth.reset(new unsigned int[m_num]);
				for (int i = 0; i < m_num; ++i)
				{
					m_depth[i] = depths[i];
				}
				m_buffers.reset(new GLuint[m_num]);

				glGenBuffers(1, &m_indices);
				glGenBuffers(m_num, m_buffers.get());
				glGenVertexArrays(1, &m_vao);
				glBindVertexArray(m_vao);
				for (int i = 0; i < m_num; ++i)
				{
					glEnableVertexAttribArray(i);
				}
				for (int i = 0; i < m_num; ++i)
				{
					glBindBuffer(GL_ARRAY_BUFFER, m_buffers[i]);
					glVertexAttribPointer(i, depths[i], GL_FLOAT, GL_FALSE, 0, 0);
				}
				glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indices);
			}

			inline void init(std::vector<unsigned int> depths)
			{
				if (depths.empty()) throw std::exception("void VAO::Init(std::vector<unsigned int> depths) depth is empty");
				init(depths.size(), &depths[0]);
			}

			inline unsigned int depth(unsigned int attribute) const
			{
				if (attribute > m_num) throw std::runtime_error("VAO::GetDepth(int attribute) const - attribute out of range");
				return m_depth[attribute];
			}

			inline void clear()
			{
				if (m_init)
				{
					glDeleteVertexArrays(1, &m_vao);
					glDeleteBuffers(1, &m_indices);
					glDeleteBuffers(m_num, m_buffers.get());
				}
				m_init = false;
				m_num = 0;
				m_length = 0;
				m_depth.reset();
				m_buffers.reset();
			}

			// points - number of points in values
			// length - number of indices in index_values
			inline void fill(unsigned int points, unsigned int length, GLfloat** attribute_values, GLuint* index_values)
			{
				m_length = length;
				glBindVertexArray(m_vao);
				glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indices);
				glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(index_values[0]) * length, index_values, GL_STATIC_DRAW);

				for (int i = 0; i < m_num; ++i)
				{
					if (attribute_values[i]) // nullptr
					{
						glBindBuffer(GL_ARRAY_BUFFER, m_buffers[i]);
						glBufferData(GL_ARRAY_BUFFER, sizeof(attribute_values[i][0]) * points * m_depth[i], attribute_values[i], GL_STATIC_DRAW);
					}
				}
			}

			inline void draw() const
			{
				if (!m_init) throw std::runtime_error("vao::draw - not initialized");

				glBindVertexArray(m_vao);
				glDrawElements(GL_TRIANGLES, m_length, GL_UNSIGNED_INT, 0);
			}

			inline void draw(int points, int length, GLfloat** values, GLuint* index_values)
			{
				fill(points, length, values, index_values);
				draw();
			}
		};
	}
}
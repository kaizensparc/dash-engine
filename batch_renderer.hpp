/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <clement@decoodt.eu> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Clement Decoodt
 * ----------------------------------------------------------------------------
 */

#pragma once

#include <vector>
#include <array>
#include <GL/gl.h>
#include <GL/glut.h>
#include "fake_glm.hpp"
#include "sphere_primitive.hpp"

namespace scene_renderer {

	class Batch_renderer {
		public:
			Batch_renderer();

			// Add primitive to pool
			// Currently only spheres are allowed
			void add_to_pool(primitives::Sphere sphere);

			// Start pool rendering
			void render();

		private:
			GLuint vertexBuffer[2];
			std::vector<primitives::Sphere> pool;
			std::vector<std::array<float, 3> > vertexArray;
			std::vector<unsigned int> vertexIndexArray;

	};

}

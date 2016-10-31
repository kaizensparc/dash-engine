/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <clement@decoodt.eu> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Clement Decoodt
 * ----------------------------------------------------------------------------
 */

#include <GL/gl.h>
#include <GL/glu.h>

#include "scene_camera.hpp"

namespace scene {
	Camera::Camera() {
		position.set(1, 0, 0);
		target.set(0, 0, 0);
		updirection.set(0, 0, 1);
	}

	void Camera::rotate(float theta, float phi) {
		float curRad   = position.getR();
		float curTheta = position.getTheta();
		float curPhi   = position.getPhi();

		position.setPolar(curRad, curTheta+theta, curPhi+phi);

		curRad   = updirection.getR();
		curTheta = updirection.getTheta();
		curPhi   = updirection.getPhi();

		updirection.setPolar(curRad, curTheta+theta, curPhi+phi);
	}

	void Camera::zoom(float rad) {
		float curRad   = position.getR();
		float curTheta = position.getTheta();
		float curPhi   = position.getPhi();
		// Just add rad to current polar coordinates
		position.setPolar(curRad-rad, curTheta, curPhi);
	}

	void Camera::initRender() {
		// Go to MV matrix
		glMatrixMode(GL_MODELVIEW);

		// Reset transformations
		glLoadIdentity();

		gluLookAt(
				position.getX()   , position.getY()   , position.getZ()   ,
				target.getX()     , target.getY()     , target.getZ()     ,
				updirection.getX(), updirection.getY(), updirection.getZ()
		);

	}
}

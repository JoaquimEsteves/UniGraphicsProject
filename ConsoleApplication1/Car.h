#ifndef __CAR__
#define __CAR__

#include "DynamicObject.h"
#include "GL\glut.h"

class Car : public DynamicObject {
	Vector3 *carStruct;

public:
	inline Car(){}
	inline virtual ~Car(){}
	inline void draw() {
		drawCarStructure();
	}
	void drawWheelRight();
	void drawWheelLeft();
	void drawAllWheels();
	inline void drawCarStructure() {
		glPushMatrix();
			glBegin(GL_POLYGON);
			glVertex3f(-0.42857142857, -0.77777777777, 0.0);
			glVertex3f(0.42857142857, -0.77777777777, 0.0);
			glVertex3f(0.42857142857, 0.77777777777, 0.0);
			glVertex3f(-0.42857142857, 0.77777777777, 0.0);
			glEnd();
		glPopMatrix();
	}
};
#endif

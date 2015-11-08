#ifndef __CAR__
#define __CAR__

#define PI 3.14159265
#define CARSPEED 0.0015

#include "DynamicObject.h"
#include "GameManager.h"
#include "Vector3.h"
#include "Entity.h"
#include "GameObject.h"
#include "GL\glut.h"
#include <math.h>
#include <stdio.h>
#include <list>
#include <iostream>
#include <vector>
#include <map>

//extern GameManager *gm;
extern Camera * _currentCamera;
extern std::list<DynamicObject *> _interactable_game_objects;
class Car : public DynamicObject {
	double _maxSpeed = 50;
	double _acceleration = 10;
	double _frictionVal = 1;
	double _specialSpeed = 0;
	double _turnAngle = 0;
	//double _rotation = 0;
	Vector3 _direction;
	bool _forceStart = false;

public:

	inline Car() {
		setPosition(0, -6.5, 0);
		_direction.set(1, 0, 0);
		setSize(.5, .375, 0.1875);

	}
	inline virtual ~Car() {}
	double getMaxSpeed() { return _maxSpeed; }
	double getAcceleration() { return _acceleration; }
	double getTurnAngle() { return _turnAngle; }
	void setSpecialSpeed(double d) { _specialSpeed = d; }
	double getSpecialSpeed() { return _specialSpeed; }
	bool getForceStart() { return _forceStart; }
	void setForceStart(bool b) { _forceStart = b; }
	Vector3 getDirection() { return _direction; }
	void setDirection(Vector3 direction) { _direction = direction; }

	void turnLeft() {
		_turnAngle = _turnAngle + 0.030;
		setDirectionSpeed();
	}
	void turnRight() {
		_turnAngle = _turnAngle - 0.030;
		setDirectionSpeed();
	}

	//HELLO
	void  setDirectionSpeed() {
		double x, y;
		if (_direction.getX() < 0) {
			x = _direction.getX()*cos(PI + _turnAngle) /*- direction.getY()*sin(turnAngle)*/;
			y = _direction.getX()*sin(PI + _turnAngle) /*+ direction.getY()*cos(turnAngle)*/;
		}
		else {
			x = _direction.getX()*cos(_turnAngle) /*- direction.getY()*sin(turnAngle)*/;
			y = _direction.getX()*sin(_turnAngle) /*+ direction.getY()*cos(turnAngle)*/;
		}
		double z = 0;
		_direction.set(x / sqrt(x*x + y*y + z*z), y / sqrt(x*x + y*y + z*z), z / sqrt(x*x + y*y + z*z));
	}
	//GOODBYE


	void friction() {
		if (_specialSpeed == 0)
			return;
		if (_specialSpeed > 0)
			_specialSpeed -= _frictionVal;
		if (_specialSpeed < 0)
			_specialSpeed += _frictionVal;
	}

	void drawWheel(double x, double y, double z, double Angle) {
		glPushMatrix();
		glTranslated(x, y, z);

		glRotated(90, 1, 0, 0);

		glutSolidTorus(0.075, 0.15, 6, 6);
		//glutSolidSphere(0.2, 50, 50);
		glPopMatrix();
	}

	void drawStructure(double x, double y, double z) {
		glPushMatrix();
		glTranslated(x, y, z);
		glScaled(2, 1.5, 0.75);
		// glutSolidCube(0.5);
		//Lower case
		glBegin(GL_POLYGON);
		glVertex3f(-.25, .25, 0);
		glVertex3f(.25, .25, 0);
		glVertex3f(.25, -.25, 0);
		glVertex3f(-.25, -.25, 0);
		glEnd();
		//Upper case
		glBegin(GL_POLYGON);
		glVertex3f(-.25, .25, .25);
		glVertex3f(.25, .25, .25);
		glVertex3f(.25, -.25, .25);
		glVertex3f(-.25, -.25, .25);
		glEnd();
		//left side
		glBegin(GL_POLYGON);
		glVertex3f(-.25, -.25, .25);
		glVertex3f(.25, -.25, .25);
		glVertex3f(.25, -.25, 0);
		glVertex3f(-.25, -.25, 0);
		glEnd();
		//right side
		glBegin(GL_POLYGON);
		glVertex3f(.25, .25, .25);
		glVertex3f(-.25, .25, .25);
		glVertex3f(-.25, .25, 0);
		glVertex3f(.25, .25, 0);
		glEnd();
		//back
		glBegin(GL_POLYGON);
		glVertex3f(.25, .25, 0);
		glVertex3f(.25, .25, .25);
		glVertex3f(.25, -.25, .25);
		glVertex3f(.25, -.25, 0);
		glEnd();
		//front
		glBegin(GL_POLYGON);
		glVertex3f(-.25, .25, 0);
		glVertex3f(-.25, .25, .25);
		glVertex3f(-.25, -.25, .25);
		glVertex3f(-.25, -.25, 0);
		glEnd();
		glPopMatrix();
	}

	inline void draw() {
		//glColor3d(0, 0, 0); //wheels could be torus
							//WHEELS ARE NOW TORUS BUT ROTATION IS NOT CORRECT HELP
		defineMaterial(0.00, 0.00, 0.00, 1.00,	//Ambient
			0.01, 0.01, 0.01, 1.00,	//Diffuse
			0.50, 0.50, 0.50, 1.00,	//Specular
			0.00, 0.00, 0.00, 1.00,	//Emission
			32);					//SHININESS
		glColor3f(0.01, 0.01, 0.01);

		glPushMatrix();
		glTranslated(getPosition().getX(), getPosition().getY(), getPosition().getZ());
		glRotated(_turnAngle * 180 / PI, 0, 0, 1);

		drawWheel(0.25, 0.4, 0, 90);
		drawWheel(0.25, -0.4, 0, 90);
		drawWheel(-0.25, 0.35, 0, 90);
		drawWheel(-0.25, -0.35, 0, 90);

		
		//glColor3d(1, 0, 0);//car
		defineMaterial(0.1, 0, 0, 1.00,	//Ambient
			0.1, 0, 0, 1.00,	//Diffuse
			0.1, 0, 0, 1.00,	//Specular
			0.00, 0.00, 0.00, 1.00,	//Emission
			77);					//SHININESS
		glColor3f(1, 0, 0);

		drawStructure(0, 0, .1);
		glPopMatrix();

	}

	/*void update_trivial(double delta_t) {
	//In case of emergency
	setPosition(getPosition() + getSpeed() * delta_t);
	}*/

	void update(double delta_t) {
		//using printf because visual studios does not like cout
		//printf("%d %d %d \n",(_direction * specialSpeed * CARSPEED * delta_t).getX() , (_direction * specialSpeed * CARSPEED * delta_t).getY() , (_direction * specialSpeed * CARSPEED * delta_t).getZ());
		if (getPosition().getX() >= 9.5 || getPosition().getX() <= -10 ||
			getPosition().getY() >= 9.5 || getPosition().getY() <= -9.5) {
			setPosition(0, -6.5, 0);
		}
		friction();
		setPosition(getPosition() + getDirection() * _specialSpeed * CARSPEED);
		//printf("car Y position %d \n", getPosition().getY());
	}
};
#endif

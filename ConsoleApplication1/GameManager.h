#ifndef _GAMEMANAGER_H_
#define _GAMEMANAGER_H_

#include "Camera.h"
#include "Vector3.h"
#include "GameObject.h"
#include "DynamicObject.h"
#include "Butter.h"
#include "Car.h"
#include "Orange.h"
#include "Road.h"
#include "GL\glut.h"
#include <math.h>


class GameManager {

	/*Deviam ser ponteiros? Assumo que sim*/
	//std::vector<Camera *> _cameras; //vectr ou list?
	//std::vector<GameObject *> _game_objects;
	//std::vector<LightSource *> _light_sources;
	bool keys[256]; //a up down left right
	bool draw_wired = false;
	Car  * c;
	int currentTime;
	int lastTime = 0;
	float xmin = -5, xmax = 5, ymin = -5, ymax = 5;
	float xscale = (xmax - xmin) / 600, yscale = (ymax - ymin) / 600;

public:
	inline GameManager() {
		c = new Car();
	}
	inline ~GameManager() {}

	/*std::vector<Camera *> getCameras();
	std::vector<GameObject *> getObjects();
	std::vector<LightSource *> getLightSources();
	void setCameras(std::vector<Camera *> v);
	void setObjects(std::vector<GameObject *> v);
	void setLightSources(std::vector<LightSource *> v);*/

	void keyA(unsigned char key) {
		switch (key) {
			case 'a':
				keys['a'] = true;
				if (draw_wired) {
					draw_wired = false;
					glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
				}
				else {
					draw_wired = true;
					glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
				}
				break;
			case 'A':
				keys['A'] = true;
				if (draw_wired) {
					draw_wired = false;
					glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
				}
				else {
					draw_wired = true;
					glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
				}
				break;
		}

	}
	void keyUp(unsigned char key) {
		switch (key) {
			case GLUT_KEY_UP:
				keys[GLUT_KEY_UP] = false; break;
			case GLUT_KEY_DOWN:
				keys[GLUT_KEY_DOWN] = false; break;
			case GLUT_KEY_LEFT:
				keys[GLUT_KEY_LEFT] = false; break;
			case GLUT_KEY_RIGHT:
				keys[GLUT_KEY_RIGHT] = false; break;
		}
	}
	void keyPressed(unsigned char key) {
		//double rotationX;
		//double rotationY;
		//double ANGLE = 0.1;
		switch (key) {

		case GLUT_KEY_UP:
			keys[GLUT_KEY_UP] = true;
			/*if (c->getSpecialSpeed() <= 0)
				c->setSpecialSpeed(c->getAcceleration()); 
			else if(c->getSpecialSpeed() < c->getMaxSpeed()) {
				c->setSpecialSpeed(c->getSpecialSpeed() + c->getAcceleration());
			}*/
			//c->setSpeed(0, 1 * CARSPEED, 0); 
			/*if (c->getSpeed().getX() == 0 || c->getSpeed().getY() == 0) {
				c->setSpeed(1*cos(ANGLE), 1*sin(ANGLE), 0);
			}
			if (c->getSpeed().getX() == 5 || c->getSpeed().getY() == 5) {
				c->setSpeed(5*cos(ANGLE), 5*sin(ANGLE), 0);
			}
			else {
				c->setSpeed((c->getSpeed().getX()+1)*cos(ANGLE), (c->getSpeed().getY()+1)*sin(ANGLE), 0);
			} */
			break;

		case GLUT_KEY_DOWN:
			keys[GLUT_KEY_DOWN] = true;
			//c->setSpecialSpeed(-1);
			/*if (c->getSpecialSpeed() >= 0)
				c->setSpecialSpeed(-c->getAcceleration());
			else if (c->getSpecialSpeed() > (- c->getMaxSpeed())) {
				c->setSpecialSpeed(c->getSpecialSpeed() - c->getAcceleration());
			}*/

			//c->setSpeed(0, -1 * CARSPEED, 0); 
			/*if (c->getSpeed().getX() == 0 || c->getSpeed().getY() == 0) {
				c->setSpeed(0, 0, 0);
			}
			else {
				c->setSpeed((c->getSpeed().getX() -1)*cos(ANGLE), (c->getSpeed().getY() -1)*sin(ANGLE), 0);
			}*/
			break;

		case GLUT_KEY_LEFT:
			keys[GLUT_KEY_LEFT] = true;
			//c->turnLeft(); 
			/*rotationX = cos(ANGLE) - sin(ANGLE) - (c->getPosition().getX()*cos(ANGLE)) + (c->getPosition().getY()*sin(ANGLE)) + c->getPosition().getX();
			rotationY = sin(ANGLE) + cos(ANGLE) - (c->getPosition().getX()*sin(ANGLE)) - (c->getPosition().getY()*cos(ANGLE)) + c->getPosition().getY();
			c->setPosition(rotationX, rotationY, 0);*/
			break;
		case GLUT_KEY_RIGHT:
			keys[GLUT_KEY_RIGHT] = true;
			//c->turnRight(); 
			/*rotationX = cos(-ANGLE) - sin(-ANGLE) - (c->getPosition().getX()*cos(-ANGLE)) + (c->getPosition().getY()*sin(-ANGLE)) + c->getPosition().getX();
			rotationY = sin(-ANGLE) + cos(-ANGLE) - (c->getPosition().getX()*sin(-ANGLE)) - (c->getPosition().getY()*cos(-ANGLE)) + c->getPosition().getY();
			c->setPosition(rotationX, rotationY, 0); */
			break;
		}
	}
	void display() {
			
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			//background -> table
			for (int i = -10; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					if (i % 2 == 0) {
						if (j % 2 == 0)glColor3d(0.74902, 0.847059, 1.847059); //0.74902 green 0.847059 blue 0.847059
						else glColor3d(1, 1, 1);
						glPushMatrix();
							glTranslated(i, j, 0);
							glutSolidCube(1);
						glPopMatrix();

						glPushMatrix();
							glTranslated(-i - 2, -j, 0);
							glutSolidCube(1);
						glPopMatrix();
					}
					else {
						if (j % 2 == 1)glColor3d(0.74902, 0.847059, 1.847059);
						else glColor3d(1, 1, 1);
						glPushMatrix();
							glTranslated(i, j, 0);
							glutSolidCube(1);
						glPopMatrix();

						glPushMatrix();
							glTranslated(-i, -j, 0);
							glutSolidCube(1);
						glPopMatrix();
					}
				}

			}

			//draw stuff

			Orange *o = new Orange();
			o->draw();
			Butter * b = new Butter();
			b->draw();
			c->draw();
			Road *rs = new Road();
			rs->draw();

			glutSwapBuffers();
	}
	void reshape(int w, int h) {
		glViewport(0, 0, w, h);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		float c = (xmax + xmin);
		xmax = c + xscale * w;
		xmin = c - xscale * w;
		c = (ymax + ymin);
		ymax = c + yscale * h;
		ymin = c - yscale * h;
		gluOrtho2D(xmin, xmax, ymin, ymax);
	}
	void keyPressed();
	void onTimer(){
		currentTime = glutGet(GLUT_ELAPSED_TIME);
		update((currentTime - lastTime));
		lastTime = currentTime;
	}
	void idle();
	inline void update(double delta_t) {
		if (keys[GLUT_KEY_UP]) {
			if (c->getSpecialSpeed() <= 0)
				c->setSpecialSpeed(c->getAcceleration());
			else if (c->getSpecialSpeed() < c->getMaxSpeed()) {
				c->setSpecialSpeed(c->getSpecialSpeed() + c->getAcceleration());
			}
		}
		if (keys[GLUT_KEY_DOWN]) {
			if (c->getSpecialSpeed() >= 0)
				c->setSpecialSpeed(-c->getAcceleration());
			else if (c->getSpecialSpeed() > (-c->getMaxSpeed())) {
				c->setSpecialSpeed(c->getSpecialSpeed() - c->getAcceleration());
			}
		}
		if (keys[GLUT_KEY_LEFT])
			c->turnLeft();
		if (keys[GLUT_KEY_RIGHT])
			c->turnRight();

		c->update(delta_t);
		glutPostRedisplay();
	}
	void init() {
		c = new Car();
	}
};
#endif

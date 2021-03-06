#ifndef __ENTITY__
#define __ENTITY__

#include "Vector3.h"

class Entity {
	Vector3 _position;
public:
	inline Entity() { _position.set(0.0, 0.0, 0.0); }
	inline ~Entity() {}
	Vector3  getPosition() { return _position; }
	void  setPosition(double x, double y, double z) {
		_position.set(x, y, z);
	}
	void setPosition(const Vector3 & p) { _position = p; }

	//Vector3 * setPosition(const Vector3 &);
};

#endif
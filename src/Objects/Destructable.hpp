/*
 * Destructable.hpp
 *
 *  Created on: Jul 27, 2014
 *      Author: Charles Miller
 */

#ifndef DESTRUCTABLE_HPP_
#define DESTRUCTABLE_HPP_

enum DestructionType
{
	collision,
	interaction
};

class Destructable
{

public:

	Destructable();

	~Destructable();

	virtual void onDesruction();

//
	void setCollisionThreshold(float threshold);

	bool isDestroyed(b2Contact* contact);

	bool isDestructable();

private:

	float m_collisionThreshold;
};



#endif /* DESTRUCTABLE_HPP_ */

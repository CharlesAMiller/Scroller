/*
 * ContactListener.hpp
 *
 *  Created on: Jul 17, 2014
 *      Author: Charles Miller
 */

#ifndef CONTACTLISTENER_HPP_
#define CONTACTLISTENER_HPP_

#include <Box2D/Box2D.h>

#include "Object.hpp"
#include "Player.hpp"

class ContactListener : public b2ContactListener
{

public:

	  void BeginContact(b2Contact* contact);

	  void EndContact(b2Contact* contact);

	  void PreSolve(b2Contact* contact, const b2Manifold* oldManifold);

	  void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse);

};



#endif /* CONTACTLISTENER_HPP_ */

/*
 * ContactListener.cpp
 *
 *  Created on: Jul 18, 2014
 *      Author: Charles Miller
 */

#include "ContactListener.hpp"


void ContactListener::BeginContact(b2Contact* contact)
{
	Player* pCompare = static_cast<Player*>(contact->GetFixtureA()->GetBody()->GetUserData());
	Object* oCompare = static_cast<Object*>(contact->GetFixtureA()->GetBody()->GetUserData());
	Object* oCompareB = static_cast<Object*>(contact->GetFixtureB()->GetBody()->GetUserData());

}

void ContactListener::PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
{
	  b2WorldManifold worldManifold;

	  contact->GetWorldManifold(&worldManifold);

	 /* if (worldManifold.normal.y < -0.5f)
	  {
		contact->SetEnabled(false);
	  }*/
}

void ContactListener::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse)
{
}

void ContactListener::EndContact(b2Contact* contact)
{

}

/*====================*/
// @author: Harrison M. (Verrazano)
// @version: 8/7/13 v1.2
// @description: Implements the b2Draw interface,
// used for drawing debug data using a b2World and sf::RenderWindow.
// @usage:
// 		Box2dDebugDrawer debugDrawer(&win);
//		world.SetDebugDraw(&debugDrawer);
//
//		while( . . . )
//		{
//			win.clear();
//			world.DrawDebugData();
//			win.display();
//
//		}
/*====================*/

//TODO:
//	- Implement some kind of image caching system so this runs faster.
// 	- Implement screen culling so we don't draw shapes that are off screen.

#ifndef BOX2DDEBUGDRAWER_H_
#define BOX2DDEBUGDRAWER_H_

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

class Box2DDebugDrawer : public b2Draw
{
public:
	Box2DDebugDrawer();
	// @note: The constructor sets up the default drawing flags to
	// e_shapeBit you can set your own flags using SetFlags.
	Box2DDebugDrawer(sf::RenderWindow* win);

	// You can also use these functions to draw your own shapes that
	// are not included in the b2World if you want!
	void DrawPolygon(const b2Vec2* vertices,
			int32 vertexCount,
			const b2Color& color);

	void DrawSolidPolygon(const b2Vec2* vertices,
			int32 vertexCount,
			const b2Color& color);

	void DrawCircle(const b2Vec2& center,
			float32 radius,
			const b2Color& color);

	void DrawSolidCircle(const b2Vec2& center,
			float32 radius,
			const b2Vec2& axis,
			const b2Color& color);

	void DrawSegment(const b2Vec2& p1,
			const b2Vec2& p2,
			const b2Color& color);

	void DrawTransform(const b2Transform& xf);

	static sf::Color b2ColorToSFColor(b2Color color);
	static b2Color sfColorToB2Color(sf::Color color);

private:
	sf::RenderWindow* win;

};

#endif /* BOX2DDEBUGDRAWER_H_ */

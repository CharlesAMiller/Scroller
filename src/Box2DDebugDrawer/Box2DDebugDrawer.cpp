#include "Box2DDebugDrawer.h"
//#include "../convert/b2tosf.h"

Box2DDebugDrawer::Box2DDebugDrawer()
{
	win = NULL;
	SetFlags(e_shapeBit  + e_pairBit + e_centerOfMassBit);

}

Box2DDebugDrawer::Box2DDebugDrawer(sf::RenderWindow* win)
{
	this->win = win;
	SetFlags(e_shapeBit + e_pairBit + e_centerOfMassBit);

}

void Box2DDebugDrawer::DrawPolygon(const b2Vec2* vertices,
		int32 vertexCount,
		const b2Color& color)
{
	sf::ConvexShape shape(vertexCount);

	sf::Color shapeColor = b2ColorToSFColor(color);
	shape.setOutlineColor(shapeColor);
	shape.setFillColor(sf::Color(0, 0, 0, 0));
	shape.setOutlineThickness(1);
	for(unsigned int i  = 0; i < vertexCount; i++)
		shape.setPoint(i, sf::Vector2f(vertices[i].x*32, -(vertices[i].y*32)));

	win->draw(shape);

}

void Box2DDebugDrawer::DrawSolidPolygon(const b2Vec2* vertices,
		int32 vertexCount,
		const b2Color& color)
{
	sf::ConvexShape shape(vertexCount);

	sf::Color shapeColor = b2ColorToSFColor(color);
	shape.setOutlineColor(shapeColor);
	shape.setOutlineThickness(1);

	shapeColor.a = 180;
	shape.setFillColor(shapeColor);

	for(unsigned int i  = 0; i < vertexCount; i++)
		shape.setPoint(i, sf::Vector2f(vertices[i].x*32, -(vertices[i].y*32)));

	win->draw(shape);

}

void Box2DDebugDrawer::DrawCircle(const b2Vec2& center,
		float32 radius,
		const b2Color& color)
{
	float pixelRadius = radius*32;

	sf::CircleShape shape(pixelRadius);
	shape.setOrigin(pixelRadius, pixelRadius);
	shape.setPosition(sf::Vector2f(center.x*32, -(center.y*32)));

	sf::Color shapeColor = b2ColorToSFColor(color);
	shape.setOutlineColor(shapeColor);
	shape.setFillColor(sf::Color(0, 0, 0, 0));
	shape.setOutlineThickness(1);

	win->draw(shape);

}

void Box2DDebugDrawer::DrawSolidCircle(const b2Vec2& center,
		float32 radius,
		const b2Vec2& axis,
		const b2Color& color)
{
	float pixelRadius = radius*32;

	sf::CircleShape shape(pixelRadius);
	shape.setOrigin(pixelRadius, pixelRadius);
	shape.setPosition(sf::Vector2f(center.x*32, -(center.y*32)));

	sf::Color shapeColor = b2ColorToSFColor(color);
	shape.setOutlineColor(shapeColor);
	shape.setOutlineThickness(1);

	shapeColor.a = 180;
	shape.setFillColor(shapeColor);

	win->draw(shape);

	b2Vec2 outside = center + (radius*axis);
	DrawSegment(center, outside, color);

}

void Box2DDebugDrawer::DrawSegment(const b2Vec2& p1,
		const b2Vec2& p2,
		const b2Color& color)
{
	sf::VertexArray segment(sf::Lines, 2);

	sf::Color segmentColor = b2ColorToSFColor(color);

	segment[0] = sf::Vertex(sf::Vector2f(p1.x*32, -(p1.y*32)), segmentColor);
	segment[1] = sf::Vertex(sf::Vector2f(p2.x*32, -(p2.y*32)), segmentColor);

	win->draw(segment);

}

void Box2DDebugDrawer::DrawTransform(const b2Transform& xf)
{
	float lineProportion = 0.60; // ~19 pixels
	b2Vec2 p1 = xf.p;
	b2Vec2 p2;

	p2 = p1;
	p2 += b2Vec2(lineProportion*xf.q.GetXAxis());
	DrawSegment(p1, p2, b2Color(1, 0, 0));

	p2 = p1;
	p2 -= b2Vec2(lineProportion*xf.q.GetYAxis());
	DrawSegment(p1, p2, b2Color(0, 1, 0));

}

// b2Color uses a range of [0-1] to work well with OpenGL.
// So we need to convert between the color types.
sf::Color Box2DDebugDrawer::b2ColorToSFColor(b2Color color)
{
	return sf::Color(color.r*255, color.g*255, color.b*255);

}

b2Color Box2DDebugDrawer::sfColorToB2Color(sf::Color color)
{
	return b2Color(color.r/255, color.g/255, color.b/255);

}

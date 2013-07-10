// See the file COPYRIGHT.txt for authors and copyright information.
// See the file LICENSE.txt for copying conditions.

#include "entityliving.h"
//#include <cmath>

EntityLiving::EntityLiving()
{
    angle = 0;
    speed = defaultSpeed;
    sprite.setOrigin(32, 32);
    sprite.setPosition(400, 300);
    moving = false;
}

void EntityLiving::move(float deltaTime)
{
    if (moving)
    {
        float rad = (angle * PI) / 180.0;
        sf::Vector2f amount;
        amount.x = deltaTime * speed * cos(rad);
        amount.y = deltaTime * speed * sin(rad);
        sprite.move(amount);
        sprite.setRotation(angle + 90);
        pos = sprite.getPosition();
        handleCollision();
    }
}

void EntityLiving::setAngle(float deg)
{
    angle = deg;
}

void EntityLiving::setSpeed(float theSpeed)
{
    speed = theSpeed;
}

void EntityLiving::setMoving(bool isMoving)
{
    moving = isMoving;
}

void EntityLiving::handleCollision()
{
    // TODO: Improve this later
    if (pos.x < 0)
    {
        pos.x = 0;
        flipAngle();
    }

    if (pos.y < 0)
    {
        pos.y = 0;
        flipAngle();
    }

    if (pos.x >= mapWidth)
    {
        pos.x = mapWidth;
        flipAngle();
    }

    if (pos.y >= mapHeight)
    {
        pos.y = mapHeight;
        flipAngle();
    }

    sprite.setPosition(pos);
}

void EntityLiving::flipAngle()
{
    angle += 90;
    if (angle > 360)
        angle -= 360;
}

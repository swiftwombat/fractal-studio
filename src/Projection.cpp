#include "Projection.h"

// construction

Projection::Projection(sf::Vector2f size)
    : sf::RectangleShape(size)
{
    this->init();
}

Projection::~Projection()
{
    
}

// m_functions

void Projection::init()
{
    
}

// functions

void Projection::update(const sf::Vector2f& mpos)
{
    sf::Vector2f offset;
    offset.x = mpos.x - this->getGlobalBounds().left - this->getOrigin().x ;
    offset.y = mpos.y - this->getGlobalBounds().top - this->getOrigin().y ;
    this->move(offset);
}

void Projection::render(sf::RenderTarget& target)
{
    target.draw(*this);
}

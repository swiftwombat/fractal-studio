#include "Projection.h"

// construction

Projection::Projection(const sf::Vector2f& size)
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
    this->m_screencap.create(1600, 1200);
    this->setOrigin(this->getSize().x / 2.f, this->getSize().y / 2.f);
}

// functions

bool Projection::contains(const sf::Vector2f& point)
{
    const sf::Vector2f tpoint = this->getInverseTransform().transformPoint(point);
    return this->getLocalBounds().contains(tpoint);
}

void Projection::update()
{
    
}

void Projection::render(sf::RenderTarget& target)
{
    target.draw(*this);
}

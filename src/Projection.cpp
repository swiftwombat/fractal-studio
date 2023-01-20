#include "Projection.h"

// construction

Projection::Projection(const sf::Vector2f& size)
    : sf::RectangleShape(size)
{
    this->init();
}

Projection::~Projection()
{
    delete this->m_centerdot;
}

// m_functions

void Projection::init()
{
    this->setFillColor(sf::Color(132, 128, 128));
    this->setOrigin(this->getSize().x / 2.f, this->getSize().y / 2.f);
    this->setRotation(45.f);

    this->m_centerdot = new sf::RectangleShape(sf::Vector2f(1,1));
    this->m_centerdot->setFillColor(sf::Color().Red);
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
    this->m_centerdot->setPosition(this->getPosition());

    target.draw(*this);
    target.draw(*this->m_centerdot);
}

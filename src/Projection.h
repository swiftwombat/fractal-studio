#ifndef PROJECTION_H
#define PROJECTION_H

#include "SFML/Graphics.hpp"
#include <array>

class Projection : 
    public sf::RectangleShape
{
private:
    // m_variables
    sf::Texture m_screencap;

    // m_functions
    void init();
    
public:
    // construction
    Projection(const sf::Vector2f& size);
    virtual ~Projection();

    // functions
    bool contains(const sf::Vector2f& point);

    void update();
    void render(sf::RenderTarget& target);
};

#endif
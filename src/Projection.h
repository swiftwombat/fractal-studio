#ifndef PROJECTION_H
#define PROJECTION_H

#include "SFML/Graphics.hpp"

class Projection : 
    public sf::RectangleShape
{
private:
    // m_variables


    // m_functions
    void init();
    
public:
    // construction
    Projection(sf::Vector2f vector);
    virtual ~Projection();

    // functions
    void update(const sf::Vector2f& mpos);
    void render(sf::RenderTarget& target);
};

#endif
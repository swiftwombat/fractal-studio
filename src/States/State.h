#ifndef STATE_H
#define STATE_H

#include "SFML/Graphics.hpp"

class State
{
public:
    // construction
    State();
    virtual ~State();

    // functions
    virtual void update() = 0;
    virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

#endif
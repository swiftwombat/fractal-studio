#ifndef SPLASHSTATE_H
#define SPLASHSTATE_H

#include "State.h"

class SplashState : 
    public State
{
private:
    // m_variables

    // m_functions

public:
    // construction
    SplashState();
    virtual ~SplashState();

    // functions
    void update();
    void render(sf::RenderTarget* target = nullptr);
};

#endif
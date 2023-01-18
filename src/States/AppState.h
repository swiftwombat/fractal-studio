#ifndef APPSTATE_H
#define APPSTATE_H

#include "State.h"

class AppState : 
    public State
{
private:
    // m_variables

    // m_functions

public:
    // construction
    AppState();
    virtual ~AppState();

    // functions
    void update();
    void render(sf::RenderTarget* target = nullptr);
};

#endif
#ifndef STUDIOSTATE_H
#define STUDIOSTATE_H

#include "State.h"

class StudioState : 
    public State
{
private:
    // m_variables

    // m_functions

public:
    // construction
    StudioState();
    virtual ~StudioState();

    // functions
    void update();
    void render(sf::RenderTarget* target = nullptr);
};

#endif
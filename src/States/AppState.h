#ifndef APPSTATE_H
#define APPSTATE_H

#include "State.h"
#include "../Projection.h"

class AppState : 
    public State
{
private:
    // m_variables
    std::vector<Projection*> m_projections;
    Projection* m_current;

    // m_functions

    
public:
    // construction
    AppState();
    virtual ~AppState();

    // functions
    void update(const sf::Vector2f& mpos);
    void render(sf::RenderTarget& target);
};

#endif
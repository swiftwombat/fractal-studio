#ifndef APPSTATE_H
#define APPSTATE_H

#include "State.h"
#include "../Projection.h"
#include <cmath>

class AppState : 
    public State
{
private:
    // m_variables
    std::vector<Projection*> m_projections;
    Projection* m_current;
    sf::Vector2f offset;

    bool m_dragging;
    bool m_rotating;
    bool m_scaling;

    // m_functions
    void init();
    
public:
    // construction
    AppState();
    virtual ~AppState();

    // functions
    void checkEvents(sf::Event& event, const sf::Vector2f& mpos);
    void update(const sf::Vector2f& mpos);
    void render(sf::RenderTarget& target);
};

#endif
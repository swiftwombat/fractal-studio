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
    Projection* m_curr_proj;
    sf::Vector2f m_prev_mpos;

    // m_functions
    void init();
    Projection* getProjectionAt(const sf::Vector2f& mpos);
    
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
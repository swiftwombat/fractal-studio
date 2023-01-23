#ifndef APPSTATE_H
#define APPSTATE_H

#include "State.h"
#include "../Display.h"
#include "../Projection.h"

class AppState : 
    public State
{
private:
    // m_variables
    const Display& m_display;

    Projection* m_curr_proj;
    std::vector<Projection*> m_projections;
    sf::Vector2f m_prev_mpos;
    sf::Texture* m_screencap;

    // m_functions
    void init();
    Projection* getProjectionAt(const sf::Vector2f& mpos);
    
public:
    // construction
    AppState(const Display& display);
    virtual ~AppState();

    // functions
    void checkEvents(const sf::Event& event, const sf::Vector2f& mpos);
    void update(const sf::Vector2f& mpos);
    void render(sf::RenderTarget& target);
};

#endif
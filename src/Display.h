#ifndef DISPLAY_H
#define DISPLAY_H

#include "States/State.h"

class Display : 
    public sf::RenderWindow
{
private:
    // m_variables
    sf::Event m_event;
    sf::Vector2f m_mpos;

    // m_functions
    void init();

public:
    // construction
    Display(const sf::VideoMode mode, const sf::String& title);
    virtual ~Display();

    // functions
    const sf::Vector2f& mpos() const;

    void checkEvents(const sf::Event& event);
    void update(State* state);
    void render(State* state);
};

#endif
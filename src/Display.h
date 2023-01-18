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
    Display(sf::VideoMode mode, sf::String& title);
    virtual ~Display();

    // functions
    sf::Vector2f& mpos();

    void update();
    void render(State* state);
};

#endif
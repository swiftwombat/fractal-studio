#ifndef DISPLAY_H
#define DISPLAY_H

#include "State.h"

class Display : 
    public sf::RenderWindow
{
private:
    // m_variables
    sf::Event m_event;

    // m_functions
    void init();

public:
    // construction
    Display(sf::VideoMode mode, sf::String& title);
    virtual ~Display();

    // functions
    void update();
    void render(State* state);
};

#endif
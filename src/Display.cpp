#include "Display.h"


Display::Display(sf::VideoMode mode, sf::String &title)
    : sf::RenderWindow(mode, title)
{
    this->init();
}

Display::~Display()
{

}


void Display::init()
{
    
}

void Display::update()
{
    while (this->pollEvent(this->m_event))
    {
        if (this->m_event.type == sf::Event::Closed)
            this->close();

        if ((this->m_event.type == sf::Event::KeyPressed) && (this->m_event.key.code == sf::Keyboard::Escape))
            this->close();
    }
}

void Display::render(State *state)
{
    this->clear();
    state->render(this);
    this->display();
}

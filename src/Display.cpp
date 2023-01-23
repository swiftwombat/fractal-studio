#include "Display.h"

// construction

Display::Display(const sf::VideoMode mode, const sf::String &title)
    : sf::RenderWindow(mode, title)
{
    this->init();
}

Display::~Display()
{

}

// m_functions

void Display::init()
{
    this->setKeyRepeatEnabled(false);
}

// functions

const sf::Vector2f& Display::mpos() const
{
    return this->m_mpos;
}

void Display::checkEvents(const sf::Event& e)
{
    if (e.type == sf::Event::Closed)
        this->close();

    if ((e.type == sf::Event::KeyPressed) && (e.key.code == sf::Keyboard::Escape))
        this->close();
}

void Display::update(State* state)
{
    this->m_mpos = this->mapPixelToCoords(sf::Mouse::getPosition(*this));

    while (this->pollEvent(this->m_event))
    {
        this->checkEvents(this->m_event);
        if (state) { state->checkEvents(this->m_event, this->m_mpos); }
    }
}

void Display::render(State* state)
{
    this->clear(sf::Color(2u, 2u, 2u));
    if(state) { state->render(*this); }
    this->display();
}

#include "Display.h"

// construction

Display::Display(const sf::String &title, const sf::VideoMode mode)
    : sf::RenderWindow(mode, title, sf::Style::Fullscreen)
{
    this->init();
}

Display::~Display()
{

}

// m_functions

void Display::init()
{
    sf::Image icon;
    icon.loadFromFile("./img/icon.png");
    this->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    this->setKeyRepeatEnabled(false);
}

// functions

const sf::Vector2f& Display::mpos() const
{
    return m_mpos;
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
    m_mpos = mapPixelToCoords(sf::Mouse::getPosition(*this));

    while (this->pollEvent(m_event))
    {
        this->checkEvents(m_event);
        if (state) { state->checkEvents(m_event, m_mpos); }
    }
}

void Display::render(State* state)
{
    this->clear(sf::Color(2u, 2u, 2u));
    if(state) { state->render(*this); }
    this->display();
}

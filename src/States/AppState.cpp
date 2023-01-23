#include "AppState.h"

// construction

AppState::AppState(const Display& display)
    : State(), m_display(display)
{
    this->init();
}

AppState::~AppState()
{
    delete this->m_curr_proj;
    delete this->m_screencap;
    for ( auto p : this->m_projections ) { delete p; }
}

// m_functions

void AppState::init()
{
    auto size = sf::Vector2u(this->m_display.getSize());
    this->m_screencap = new sf::Texture();
    this->m_screencap->create(size.x, size.y);
    this->m_curr_proj = nullptr;
}

Projection* AppState::getProjectionAt(const sf::Vector2f& mpos)
{
    Projection* p_proj = nullptr;
    for (auto p : this->m_projections) 
    {
        if (!p->contains(mpos)) { continue; }
        p_proj = p;
        break;
    }
    return p_proj;
}

// functions


void AppState::checkEvents(const sf::Event& e, const sf::Vector2f& mpos)
{
    if (e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Left && !m_curr_proj) // add new projection
    {
        auto p_proj = new Projection(sf::Vector2f(this->m_display.getSize()) / 6.f);
        p_proj->setPosition(mpos);
        this->m_projections.push_back(p_proj);
    }

    if (e.type == sf::Event::MouseButtonPressed && e.mouseButton.button == sf::Mouse::Right) // delete projection
    {
        auto i = this->m_projections.begin();
        while (i != this->m_projections.end()) 
        {
            auto p_proj = *i;
            if (p_proj->contains(mpos)) { this->m_projections.erase(i); break; }
            else                      { ++i; }
        }
    }

    if (e.type == sf::Event::MouseWheelScrolled) // rotate projection
    {
        Projection* p_proj = getProjectionAt(mpos);
        auto ds = e.mouseWheelScroll.delta;
        if (p_proj)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) 
            {  
                if (ds > 0) { p_proj->scale(1.1f, 1.1f); }
                else        { p_proj->scale(0.9f, 0.9f); }
            }
            else { p_proj->rotate(2.5f * ds); }
        }
    }
}

void AppState::update(const sf::Vector2f& mpos)
{ 
    this->m_screencap->update(this->m_display);
    for (auto proj : this->m_projections) { proj->update(this->m_screencap); }


    if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
    { 
        this->m_curr_proj = nullptr; 
        return; 
    }

    if (!this->m_curr_proj)
    {
        for (auto proj : this->m_projections) 
        {
            if (!proj->contains(mpos)) { continue; }
            this->m_prev_mpos = mpos;
            this->m_curr_proj = proj;
            break;
        }
    }
    else
    { 
        this->m_curr_proj->move(mpos - m_prev_mpos);
        this->m_prev_mpos = mpos;
    }
}

void AppState::render(sf::RenderTarget& target)
{
    for (auto proj : this->m_projections) { proj->render(target); }
}

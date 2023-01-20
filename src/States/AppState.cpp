#include "AppState.h"

// construction

AppState::AppState()
    : State()
{
    this->init();
}

AppState::~AppState()
{
    delete this->m_current;
    for ( auto p : this->m_projections ) { delete p; }
}

// m_functions

void AppState::init()
{
    this->m_dragging, this->m_rotating, this->m_scaling = false;
    this->m_current = nullptr;
}

// functions


void AppState::checkEvents(sf::Event& e, const sf::Vector2f& mpos)
{
    if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Space) // add new projection
    {
        auto proj = new Projection(sf::Vector2f(100.f, 100.f));
        proj->setPosition(mpos);
        this->m_projections.push_back(proj);
    }
}

void AppState::update(const sf::Vector2f& mpos)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) // moving projection
    {
        if (!this->m_dragging)
        {
            for (auto proj : this->m_projections) 
            {
                if (!proj->contains(mpos)) { continue; }
                this->offset.x = mpos.x - proj->getGlobalBounds().left - 45 / 2.173f - proj->getOrigin().x;
                this->offset.y = mpos.y - proj->getGlobalBounds().top - 45 / 2.173f - proj->getOrigin().x;
                this->m_current = proj;
                this->m_dragging = true;
            }
        }
    }
    else
    {
        this->m_current = nullptr;
        this->m_dragging = false;
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) // add new projection
    {
        auto i = this->m_projections.begin();
        while (i != this->m_projections.end()) 
        {
            auto proj = *i;
            if (proj->contains(mpos)) { i = this->m_projections.erase(i); }
            else                      { ++i; }
        }
    }

    if(this->m_current && this->m_dragging) { this->m_current->setPosition(mpos.x - offset.x, mpos.y - offset.y); }
}

void AppState::render(sf::RenderTarget& target)
{
    for (auto proj : this->m_projections) { proj->render(target); }
}

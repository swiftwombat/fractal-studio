#include "AppState.h"

// construction

AppState::AppState()
    : State()
{

}

AppState::~AppState()
{
    delete this->m_current;
    for ( auto p : this->m_projections ) { delete p; }
}

// functions

void AppState::update(const sf::Vector2f& mpos)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) // add new projection
    {
        auto proj = new Projection(sf::Vector2f(100.f, 100.f));
        proj->setPosition(mpos);
        this->m_projections.push_back(proj);
    }
    
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) // moving projection
    {
        for (auto proj : this->m_projections) 
        {
            if (!proj->getGlobalBounds().contains(mpos)) { break; }
            this->m_current = proj;
        }
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) // deleteing projection
    {
        
    }

    if(this->m_current != nullptr) { this->m_current->update(mpos); }
}

void AppState::render(sf::RenderTarget& target)
{
    for (auto proj : this->m_projections) { proj->render(target); }
}

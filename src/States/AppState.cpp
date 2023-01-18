#include "AppState.h"

// construction

AppState::AppState()
    : State()
{

}

AppState::~AppState()
{
    
}

// functions

void AppState::update(sf::Vector2f& mpos)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) // add new projection
    {
        auto proj = new Projection(sf::Vector2f(100.f, 100.f));
        proj->setPosition(mpos);
        this->m_projections.push_back(proj);
    }
    
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
    {
        for (auto proj : this->m_projections) 
        {
            if (!proj->getGlobalBounds().contains(mpos)) { break; }
            this->m_selectedProjection = proj;
        }
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
    {
        // deleting logic
    }

    if(this->m_selectedProjection != nullptr)
        this->m_selectedProjection->update(mpos);
}

void AppState::render(sf::RenderTarget& target)
{
    for (auto proj : this->m_projections) 
        proj->render(target);
}

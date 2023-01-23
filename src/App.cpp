#include "App.h"

// construction

App::App()
{
    this->init();
}

App::~App()
{
    delete this->m_display;
    while (!this->m_states.empty())
    {
        delete this->m_states.top();
        this->m_states.pop();
    }
}

// m_functions

void App::init()
{
    this->initDisplay();
    this->initStates();
}

void App::initDisplay()
{
    auto title = sf::String("Fractal Studio");
    this->m_display = new Display(title);
}

void App::initStates()
{
    this->m_states.push(new AppState(*this->m_display));
}

void App::update(State* state)
{
    this->m_display->update(state);
    const sf::Vector2f& mpos = this->m_display->mpos();
    
    if (state) { state->update(mpos); }
}

// functions

void App::run()
{
    while (this->m_display->isOpen())
    {
        State* state = nullptr;
        if (!this->m_states.empty()) { state = this->m_states.top(); }

        this->update(state);
        this->m_display->render(state);
    }
}

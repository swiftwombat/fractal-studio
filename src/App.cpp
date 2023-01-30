#include "App.h"

// construction

App::App()
{
    this->init();
}

App::~App()
{
    delete m_display;
    while (!m_states.empty())
    {
        delete m_states.top();
        m_states.pop();
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
    m_display = new Display(title);
}

void App::initStates()
{
    m_states.push(new AppState(*m_display));
}

void App::update(State* state)
{
    m_display->update(state);
    const sf::Vector2f& mpos = m_display->mpos();
    
    if (state) { state->update(mpos); }
}

// functions

void App::run()
{
    while (m_display->isOpen())
    {
        State* state = nullptr;
        if (!m_states.empty()) { state = m_states.top(); }

        this->update(state);
        m_display->render(state);
    }
}

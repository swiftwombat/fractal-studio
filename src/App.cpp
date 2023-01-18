#include "App.h"

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

void App::init()
{
    sf::String title = "Fractal Studio";
    this->m_display = new Display(sf::VideoMode(800, 600), title);

    this->m_states.push(new StudioState());
}

void App::update()
{
    this->m_display->update();
    if (!this->m_states.empty()) { this->m_states.top()->update(); }
}

void App::run()
{
    this->update();

    State* state;
    if (!this->m_states.empty()) { state = this->m_states.top(); }

    this->m_display->render(state);
}

#ifndef APP_H
#define APP_H

#include "Display.h"
#include "States/AppState.h"
#include "States/SplashState.h"

#include <stack>

class App
{
private:
    // m_variables
    Display* m_display;
    std::stack<State*> m_states;

    // m_functions
    void init();
    void initDisplay();
    void initStates();

public:
    // construction
    App();
    virtual ~App();

    // functions
    void update();
    void run();
};

#endif
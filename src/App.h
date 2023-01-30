#ifndef APP_H
#define APP_H

#include "Display.h"
#include "States/AppState.h"

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
    
    void update(State* state);

public:
    // construction
    App();
    virtual ~App();

    // functions
    void run();
};

#endif
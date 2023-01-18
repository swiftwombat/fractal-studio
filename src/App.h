#ifndef APP_H
#define APP_H

#include "Display.h"
#include "StudioState.h"

#include <stack>

class App
{
private:
    // m_variables
    Display* m_display;
    std::stack<State*> m_states;

    // m_functions
    void init();

public:
    // construction
    App();
    virtual ~App();

    // functions
    void update();
    void run();
};

#endif
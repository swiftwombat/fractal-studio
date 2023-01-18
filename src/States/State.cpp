#include "State.h"

// construction

State::State()
{
    this->m_isEnded = false;
}

State::~State()
{
    
}

const bool& State::isEnded() const
{
    return this->m_isEnded;
}
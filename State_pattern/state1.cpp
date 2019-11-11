#include <iostream>
using namespace std;

class SwitchState
{
public:
    virtual SwitchState *switch_off() = 0;
    virtual SwitchState *switch_on() = 0;
};

class SwitchOffState : public SwitchState
{
public:
    SwitchState *switch_off() override
    {
        cout << "Already Switched off" << endl;
        return nullptr;
    }
    SwitchState *switch_on() override;
};

class SwitchOnState : public SwitchState
{
public:
    SwitchState *switch_on() override
    {
        cout << "Already Switched on" << endl;
        return nullptr;
    }
    SwitchState *switch_off() override
    {
        cout << "Switching off" << endl;
        return new SwitchOffState;
    }
};

SwitchState *SwitchOffState::switch_on()
{
    cout << "Switching on" << endl;
    return new SwitchOnState;
}

class Switch
{
    SwitchState *m_current_state;

public:
    Switch() { m_current_state = new SwitchOffState; }
    void switch_on()
    {
        SwitchState *newstate = m_current_state->switch_on();
        if (newstate && m_current_state != newstate)
        {
            delete m_current_state;
            m_current_state = newstate;
        }
    }
    void switch_off()
    {
        SwitchState *newstate = m_current_state->switch_off();
        if (newstate && m_current_state != newstate)
        {
            delete m_current_state;
            m_current_state = newstate;
        }
    }
};

int main()
{
    Switch myswitch;
    myswitch.switch_off();
    myswitch.switch_on();
    myswitch.switch_on();
    myswitch.switch_off();

    return 0;
}
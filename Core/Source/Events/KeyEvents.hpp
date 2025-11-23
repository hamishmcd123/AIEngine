#pragma once 
#include "Event.hpp"

namespace Core {

    class KeyPressedEvent : public Event {

    public:
    KeyPressedEvent(int KeyCode) : m_KeyCode(KeyCode) {}

    int GetKeyCode() const {return m_KeyCode;}

    EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard)
    EVENT_CLASS_TYPE(KeyPressed)

    private:
        int m_KeyCode;
    };
}

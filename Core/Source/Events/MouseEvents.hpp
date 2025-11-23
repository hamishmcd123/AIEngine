#pragma once

#include "Event.hpp"
#include "imgui.h"
#include <sstream>

namespace Core{

class MouseMovedEvent : public Event {
    public:
    MouseMovedEvent(const float x, const float y) : m_MouseX(x), m_MouseY(y) {}
    float GetMouseX() const {return m_MouseX;}
    float GetMouseY() const {return m_MouseY;}

   std::string ToString() const override {
       std::stringstream ss; 
       ss << '(' << GetMouseX() << ',' << GetMouseY() << ')';
       return ss.str();
   }

    EVENT_CLASS_CATEGORY(EventCategoryMouse)
    EVENT_CLASS_TYPE(MouseMoved)

    private:
    float m_MouseX, m_MouseY;
};

}

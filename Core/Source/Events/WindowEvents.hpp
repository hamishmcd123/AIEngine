#pragma once

#include "Event.hpp"

namespace Core {

    class WindowResizeEvent : public Event {
        public:

        WindowResizeEvent(const int Width, const int Height) : m_WindowWidth(Width), m_WindowHeight(Height) {}

        int GetWindowWidth() const {return m_WindowWidth;}
        int GetWindowHeight() const {return m_WindowHeight;}

        EVENT_CLASS_TYPE(WindowResize)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)

        private:
        int m_WindowWidth;
        int m_WindowHeight;
    };

    class WindowCloseEvent : public Event {
        public:
        WindowCloseEvent() {}

        EVENT_CLASS_TYPE(WindowClose)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };


}

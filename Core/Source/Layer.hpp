#pragma once
#include "Event.hpp"

namespace Core {
    class Layer {
        public:
            virtual ~Layer() = default;
            virtual void OnRender() = 0;
            virtual void OnUpdate(float ts) = 0;
            virtual void ImGuiRender() {}
            virtual void OnEvent(Event& e) = 0;
    };
}

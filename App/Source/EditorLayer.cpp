#include "EditorLayer.hpp"
#include "Application.hpp"
#include "Event.hpp"
#include "Events/MouseEvents.hpp"
#include "Events/WindowEvents.hpp"
#include "Logger.hpp"
#include "ImguiIncludes.hpp"
#include "imgui.h"
#include <iostream>

namespace App {

    void EditorLayer::ImGuiRender() {
        for (const auto& panel : Panels) {
            panel.get()->Render();
        }
    }

    void EditorLayer::OnUpdate(float ts) {
    }

    void EditorLayer::OnRender() {
    }
    
    void EditorLayer::OnEvent(Core::Event& event) {

        Core::EventDispatcher dispatcher(event);

    }
}


#include "MenuBar.hpp"
#include "Application.hpp"
#include "Events/WindowEvents.hpp"
#include "imgui.h"

namespace App {

    void MenuBar::Render() {
        ImGui::BeginMainMenuBar();
        if (ImGui::BeginMenu("File")) {
            if(ImGui::MenuItem("Quit")) {
                Core::WindowCloseEvent e;
                Core::Application::Get()->OnEvent(e);
            }
        ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
        }
    }


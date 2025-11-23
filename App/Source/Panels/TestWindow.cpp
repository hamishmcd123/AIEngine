#include "TestWindow.hpp"
#include "imgui.h"

namespace App {
    void TestWindow::Render() {
        ImGui::Begin("Test");
        ImGui::Text("This is a test window");
        ImGui::End();
    }
}


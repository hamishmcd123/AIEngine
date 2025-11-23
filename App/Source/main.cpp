#include "Application.hpp"
#include "EditorLayer.hpp"
#include "Panels/MenuBar.hpp"
#include "Panels/TestWindow.hpp"
int main() {

    Core::ApplicationSpec AppSpec;

    AppSpec.m_AppName = "AIEngine";
    AppSpec.m_WindowSpec.Width = 1280;
    AppSpec.m_WindowSpec.Height = 720;
    AppSpec.m_WindowSpec.Name = AppSpec.m_AppName;
    AppSpec.m_WindowSpec.bVsyncEnabled = true;

    Core::Application App(AppSpec);
    App.PushNewLayer<App::EditorLayer>(App::MenuBar(), App::TestWindow());
    App.Run();
    return 0;
}

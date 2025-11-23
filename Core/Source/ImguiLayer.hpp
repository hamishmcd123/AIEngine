#pragma once
#include "Layer.hpp"

namespace Core{
// The Imgui layer is special. It will be stored as a separate member variable in the application.
// We do this so that we can explicitly call Begin() (which creates the new imgui frame) and End()
// (which renders that frame) before and after processing the logic for other layer's imgui stuff.

class ImguiLayer{
    public:
    ImguiLayer();
    void Begin();
    void End();

};

}


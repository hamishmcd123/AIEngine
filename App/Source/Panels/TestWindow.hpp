#pragma once

#include "Panel.hpp"

namespace App {
    class TestWindow : public Core::Panel {
        public:
        TestWindow() {}
        void Render() override;
    };
}


#pragma once

#include "Panel.hpp"

namespace App {
    class MenuBar : public Core::Panel {
        public:
        MenuBar() {}
        void Render() override;
    };
}


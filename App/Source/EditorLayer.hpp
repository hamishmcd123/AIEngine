#pragma once 
#include "Panel.hpp"
#include <memory>
#include <type_traits>
#include <vector>
#include <cassert>
#include "Layer.hpp"

namespace App {

class EditorLayer final : public Core::Layer {
    public:

    // 22/11/25 -- EditorLayer takes in an arbitrary number of panels. 
    template<typename... Args>
    EditorLayer(Args&& ...args) {
        // Fold expression over the , operator so that it applies expr to each element of args
        // 22/11/25 std::decay_t "normalises" the types, so that const or & or && don't matter.
        static_assert((std::is_base_of_v<Core::Panel, std::decay_t<Args>> && ...), "All arguments must inherit from Panel!");

        // We are passing rvalue objects into this, so a unique ptr is made from that and the original object is discarded.
        (... , Panels.push_back(std::make_unique<Args>(std::forward<Args>(args))));
    }

    void OnUpdate(float ts) override;
    void OnRender() override;
    void ImGuiRender() override;
    void OnEvent(Core::Event& e) override;
    private:
        std::vector<std::unique_ptr<Core::Panel>> Panels;
};

}

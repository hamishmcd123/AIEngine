#pragma once 

namespace Core {
    class Panel {
        public:
        virtual void Render() = 0;
        virtual ~Panel() = default;
    };
}


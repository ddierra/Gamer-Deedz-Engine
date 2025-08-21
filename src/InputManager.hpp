#include <iostream>

class InputManager{
    public:
        void update();
        bool isKeyPressed(int key);
        bool isMousePressed(int button);
        std::pair<int, int> getMousePosition();
};
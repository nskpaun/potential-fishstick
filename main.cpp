#include <iostream>

#include "model/GameModel.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    auto model = new GameModel();
    model->nextFrame();
    return 0;
}

#include <iostream>

#include "model/GameModel.h"

int main() {
    std::cout << "Hello PF GAME!" << std::endl;
    auto model = new GameModel();
    model->nextFrame();
    return 0;
}

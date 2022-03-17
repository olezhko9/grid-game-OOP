#include "Engine.h"
#include <iostream>
#define FPS 30

int main() {
    setlocale(LC_ALL, "rus");

    Engine engine(FPS);
    return engine.start();
}
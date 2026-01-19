#pragma once
#include "I2CBusManager.h"   // include the real bus class

class Bus {
public:
    static void init();
    static bool isInitialized();
    static I2CBus bus;
};
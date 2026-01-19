#include "I2CDriver.h"

static bool initialized = false;

I2CBus Bus::bus;

void Bus::init() {
    if (!initialized) {
        Bus::bus.begin(8, 9);
        initialized = true;
    }
}

bool Bus::isInitialized() {
    return initialized;
}
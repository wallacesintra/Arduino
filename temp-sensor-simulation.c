#include "RIMS.h"

// Define the temperature threshold
#define THRESHOLD 5

int main() {
    while (1) {
        // Read the temperature sensor value from A0, A1, and A2
        unsigned char temp = (A2 << 2) | (A1 << 1) | A0;

        // Check if the temperature exceeds the threshold
        if (temp > THRESHOLD) {
            B0 = 1;  // Set B0 high to indicate warning
        } else {
            B0 = 0;  // Set B0 low to turn off warning
        }
    }
    return 0;
}

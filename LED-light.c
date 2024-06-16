#include "RIMS.h"
// Variables to store the current state of the LED and the previous state of the button
unsigned char LEDState = 0;
unsigned char previousButtonState = 0;

int main() {
    while (1) {
        // Read the current state of the button
        unsigned char currentButtonState = A0;
        // Check for the rising edge (transition from 0 to 1)
        if (currentButtonState == 1 && previousButtonState == 0) {
            // Toggle the LED state
            LEDState = !LEDState;
            B0 = LEDState;
        }
        // Update the previous state of the button
        previousButtonState = currentButtonState;
    }
    
    return 0;
}
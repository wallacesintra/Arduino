#include "RIMS.h"

// Define the PWM frequency and period
#define PWM_PERIOD 100 // Period of 100ms

// Variables to store the current duty cycle
unsigned char dutyCycle = 0;

void setDutyCycle() {
    // Determine the duty cycle based on A0 and A1
    if (A1 == 0 && A0 == 0) {
        dutyCycle = 25;  // 25% duty cycle
    } else if (A1 == 0 && A0 == 1) {
        dutyCycle = 50;  // 50% duty cycle
    } else if (A1 == 1 && A0 == 0) {
        dutyCycle = 75;  // 75% duty cycle
    } else if (A1 == 1 && A0 == 1) {
        dutyCycle = 100; // 100% duty cycle
    }
}

int main() {
    unsigned char timeCounter = 0;
    
    while (1) {
        // Update the duty cycle based on inputs A0 and A1
        setDutyCycle();
        
        // Increment the time counter
        timeCounter++;
        if (timeCounter >= PWM_PERIOD) {
            timeCounter = 0;
        }

        // Generate PWM signal on B0
        if (timeCounter < (dutyCycle * PWM_PERIOD / 100)) {
            B0 = 1; // Turn on B0 for the duty cycle duration
        } else {
            B0 = 0; // Turn off B0 for the rest of the period
        }

        // Small delay to simulate the time progression (adjust as needed)
        _delay_ms(1);
    }
    return 0;
}

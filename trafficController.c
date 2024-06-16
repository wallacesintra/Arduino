#include "RIMS.h"

unsigned char yellow_B1 = 1;
unsigned char green_B2 = 1;
unsigned char red_B0 = 1;

unsigned int timer = 0;


enum States { Green, Yellow, Red } state;

void Traffic_timer() {
    // Transitions
    switch(state) {
        case Green:
            if (timer >= 5000) { // 5 seconds
                state = Yellow;
                timer = 0;
            }
            break;
        case Yellow:
            if (timer >= 2000) { // 2 seconds
                state = Red;
                timer = 0;
            }
            break;
        case Red:
            if (timer >= 5000) { // 5 seconds
                state = Green;
                timer = 0;
            }
            break;
        default:
            state = Green;
            break;
    }

    // Actions
    switch(state) {
        case Green:
            B2 = 1, B1 = 0, B0 = 0;
            break;
        case Yellow: 
            B2 = 0, B1 = 1, B0 = 0;
            break;
        case Red:
             B2 = 0, B1 = 0, B0 = 1;
            break;
    }
}

int main(void) {
    // Initialize state
    state = Green;

    while (1) {
        Traffic_timer(); // Call state machine function
        _delay_ms(1); // Delay 1 ms
        timer++;
    }

    return 0;
}

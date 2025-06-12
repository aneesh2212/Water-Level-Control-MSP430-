/**
 * Automated Water Level Control System
 * Author: [Your Name]
 * Description: MSP430 code to control pump based on tank levels using hysteresis logic.
 * Sensors: P1.0 (UL1), P1.1 (L1), P1.2 (L2)
 * Actuator: P1.3 (Relay for pump)
 */

#include <msp430.h>

void delay() {
    volatile unsigned int i;
    for(i = 0; i < 50000; i++);  // Rough delay for debouncing
}

void main(void) {
    WDTCTL = WDTPW | WDTHOLD;    // Stop watchdog timer

    // Configure GPIO
    P1DIR &= ~(BIT0 + BIT1 + BIT2);  // P1.0, P1.1, P1.2 as inputs (sensors)
    P1REN |= BIT0 + BIT1 + BIT2;     // Enable pull-up/down resistors
    P1OUT |= BIT0 + BIT1 + BIT2;     // Set as pull-up (sensors active LOW)
    P1DIR |= BIT3;                   // P1.3 as output (relay control)
    P1OUT &= ~BIT3;                  // Initially turn OFF pump

    while(1) {
        unsigned char underground_low = P1IN & BIT0;  // UL1 sensor (0 = water present)
        unsigned char overhead_low = P1IN & BIT1;     // L1 sensor (0 = water below threshold)
        unsigned char overhead_high = P1IN & BIT2;    // L2 sensor (0 = tank full)

        // Pump ON: Underground has water AND overhead tank is low
        if (!underground_low && overhead_low) {
            P1OUT |= BIT3;  // Turn ON pump
        }

        // Pump OFF: Overhead tank full OR underground tank empty
        if (!overhead_high || underground_low) {
            P1OUT &= ~BIT3; // Turn OFF pump
        }

        delay();  // Simple debounce delay
    }
}

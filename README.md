# Water-Level-Control-MSP430-
# Automated Water Level Control System using MSP430

A hysteresis-based control system to manage water levels in overhead/underground tanks, preventing pump dry-run and overflow. Built with MSP430G2553.

## Features
- Monitors tank levels via float sensors (digital inputs).
- Controls pump via relay using hysteresis logic.
- Low-power operation with autonomous switching.

## Hardware Setup
- **Microcontroller:** MSP430G2553 LaunchPad
- **Sensors:** Float switches (L1, L2 for overhead tank; UL1 for underground tank)
- **Actuator:** Relay module (connected to P1.3)
- **Power:** 5V supply for pump circuit (isolated from MCU)

## Wiring
| MSP430 Pin | Component  | Connection       |
|------------|------------|------------------|
| P1.0       | UL1 sensor | Underground tank |
| P1.1       | L1 sensor  | Overhead tank (Low) |
| P1.2       | L2 sensor  | Overhead tank (High) |
| P1.3       | Relay      | Pump control     |

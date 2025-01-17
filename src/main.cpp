#include "beer_song.h"

void setup() {
    Serial.begin(BAUD_RATE, SERIAL_7E1);  // Initialize serial communication
    pinMode(BUTTON_PIN, INPUT_PULLUP);    // Set button pin as input with pull-up resistor
    Serial.println("\n\n\nReady...\r\n");
}

// Main loop
void loop() {
     if (bottles > NO_BOTTLES_ON_THE_WALL) {
        BeerSongVerse();        // Print the current verse
        SerialUserInput();      // Handle serial user input
    } else {
        ResetBottelsOnWall();   // Reset bottles via button if needed
    }
}

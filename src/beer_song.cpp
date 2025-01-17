#include "beer_song.h"

unsigned int bottles = INITIAL_BOTTLES;  // Initial number of bottles

// Print The song's lyrics are as follows, beginning with n=99:
void BeerSongVerse() {
    Serial.printf("%3d bottle%s of beer on the wall.\r\n", bottles, (bottles != 1 ? "s" : ""));
    Serial.printf("%3d bottle%s of beer.\r\n", bottles, (bottles != 1 ? "s" : ""));
    Serial.print("    Take one down and pass it around,\r\n");

    bottles--; // Decrease the number of bottles

    // Print the remaining number of bottles
    if (bottles > NO_BOTTLES_ON_THE_WALL) {
        Serial.printf("%3d bottle%s of beer on the wall.\r\n\r\n", bottles, (bottles != 1 ? "s" : ""));
    } else {
        Serial.print("    No more bottles of beer on the wall.\r\n\r\n");
    }
}

// Handle serial user input
void SerialUserInput() {
    while (true) {
        Serial.println("Take another one down? (yes/y/no/n)\r\n");

        // Wait until valid data is available on serial
        while (!Serial.available()) {
            delay(100);  // Small delay to avoid busy-waiting
        }

        String input = Serial.readStringUntil('\n');  // Read and process user input
        input.trim();  // Remove leading/trailing spaces or newlines

        // Clear any remaining data in the serial buffer
        while (Serial.available()) {
            Serial.read();
        }

        // Handle user inpu
        if (input == "yes" || input == "y" || input == "Y") {
            return;  // Continue to the next bottle
        } else if (input == "no" || input == "n" || input == "N") {
            Serial.println("Stopping the song.");
            while (1) { delay(1000); }  // Stop the program
        } else {
            Serial.println("Invalid input. Please type 'yes/y' or 'no/n'.");  // Invalid input case
        }
    }
}

// Reset bottles via button if needed
void ResetBottelsOnWall() {
    if (bottles == NO_BOTTLES_ON_THE_WALL) { // Print the "no more bottles" verse
        Serial.println("No more bottles of beer on the wall,\r\n"
                       "no more bottles of beer.\r\n"
                       "Go to the store and buy some more,\r\n"
                       "    99 bottles of beer on the wall...\r\n"
                       "Buy some more? Press the button to get some more.\r\n");

    // Wait for the button press
    while (true) {
            if (digitalRead(BUTTON_PIN) == LOW) {  
                delay(200);  // debounce delay
                bottles = INITIAL_BOTTLES;  // Reset the counter

                // Clear the serial buffer once again before re-prompting the user
                while (Serial.available()) {
                    Serial.read();
                }
                break;
            }
            delay(50);  // Polling delay
        }
    }
}


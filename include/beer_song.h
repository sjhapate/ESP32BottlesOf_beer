#ifndef BEER_SONG_H
#define BEER_SONG_H

#include <Arduino.h>

#define INITIAL_BOTTLES 99          // Initial number of bottles on the wall
#define BUTTON_PIN 21               // GPIO pin for Button
#define NO_BOTTLES_ON_THE_WALL 0    // Constant for no bottles remaining
#define BAUD_RATE 19200             // Define the baud rate
extern unsigned int bottles;        // Declare external variable for available number of bottles on the wall

void BeerSongVerse();               // Function to print the current verse of the song
void SerialUserInput();             // Function to handle user input via serial (yes/no)
void ResetBottelsOnWall();          // Function to reset INITIAL_BOTTLES when the button is pressed

#endif  // BEER_SONG_H

# ESP32 Beer Song Program

This program implements the classic "99 Bottles of Beer" song on an ESP32 microcontroller. It uses serial communication for output and user interaction, and a physical button for resetting the song.

## Features
- **Interactive Song**: Prompts the user to continue or stop after each verse.
- **Reset Button**: Reset the song by pressing a button when all bottles are consumed.
- **Serial Monitoring**: Displays the song's progress and user prompts in a terminal.
- **Customizable Bottles**: Start with any initial number of bottles.

## Hardware Requirements

- ESP32 WROOM development board
- Push button connected to GPIO21
- Serial connection to computer (e.g., via USB)

## Software Requirements

- Arduino framework for ESP32
- PlatformIO or Arduino IDE for compiling and uploading

## Setup

1. Connect the push button to the ESP32 as defined in `beer_song.h`
2. Set up your development environment (PlatformIO or Arduino IDE)
3. Upload the code to your ESP32

## Usage

1. Open a serial monitor (e.g., PuTTY) with the following settings:
   - Baud rate: 19200 (or as defined in BAUD_RATE)
   - Data bits: 7
   - Parity: Even
   - Stop bits: 1
2. The program will start and print "Ready..."
3. Each verse of the song will be printed
4. After each verse, you'll be prompted to continue or stop
5. When no bottles are left, press the physical button to restart the song

## Notes

- There might be garbage data at the start due to different baud rate initialization in ESP32 (115200)
- The Arduino framework doesn't support SERIAL_7E1, which is why PuTTY is recommended for monitoring
- The program uses a custom serial configuration (7E1) which all serial monitors may not support

 ## Handling Initialization Garbage Data

To filter out the garbage data produced during ESP32 initialization, you can use a Python script to read and process the serial output. This script can ignore the initial garbage data and only display the relevant program output.

## Flow Chart
![BeerSong_Flowchart](https://github.com/user-attachments/assets/77414ead-09ac-4ea7-9102-fe897af30e22)



/*
 * File:   LCD_HD4470.c
 * Author: tranthamkw
 *
 * Created on June 20, 2026, 6:33 PM
 */


#include "LCD_HD44780.h"
#include <xc.h>
#include <stdio.h>

// Splits the byte and sends the upper then lower nibble to RA0-RA3
void LCD_SendNibble(unsigned char nibble) {
    LATA = (LATA & 0xF0) | (nibble & 0x0F); 
    LCD_E = 1;                  // Clock high
    __delay_us(2);              // Data setup time
    LCD_E = 0;                  // Clock low latch
    __delay_us(50);             // Execution delay
}

void LCD_Command(unsigned char cmd) {
    LCD_RS = 0;                 // Command Register Selected
    LCD_SendNibble(cmd >> 4);   // Send High Nibble
    LCD_SendNibble(cmd);        // Send Low Nibble
    __delay_ms(2);              // Standard command execution window
}
void LCD_Char(char data) {
    LCD_RS = 1;                 // Data Register Selected
    LCD_SendNibble(data >> 4);  // Send High Nibble
    LCD_SendNibble(data);       // Send Low Nibble
    __delay_us(50);             // Data write delay
}
void LCD_Init(void) {
    LCD_RS = 0;
    LCD_E  = 0;
    
    // Official HD44780 Software Reset Sequence for 4-Bit Mode
    __delay_ms(20);
    LCD_SendNibble(0x03);
    __delay_ms(5);
    LCD_SendNibble(0x03);
    __delay_us(150);
    LCD_SendNibble(0x03);
    
    LCD_SendNibble(0x02);       // Establish 4-bit mode interface
    
    // Function Set: 4-bit, 2-line/4-line mode, 5x8 dots font
    LCD_Command(0x28);          
    LCD_Command(0x0C);          // Display ON, Cursor OFF, Blink OFF
    LCD_Command(0x06);          // Entry Mode: Increment automatically
    LCD_Command(0x01);          // Clear display home RAM
       __delay_ms(2);
}

void LCD_Clear(void){
    
    LCD_Command(0x01);          // Clear display home RAM
       __delay_ms(2);
    
    
}

void LCD_String(const char *str) {
    while(*str) {
        LCD_Char(*str++);
    }
}
void LCD_SetCursor(unsigned char row, unsigned char col) {
    unsigned char address;
    switch(row) {
        case 1: address = 0x00 + (col - 1); break; // Row 1 Base DDRAM
        case 2: address = 0x40 + (col - 1); break; // Row 2 Base DDRAM
        case 3: address = 0x14 + (col - 1); break; // Row 3 Base DDRAM
        case 4: address = 0x54 + (col - 1); break; // Row 4 Base DDRAM
        default: return;
    }
    LCD_Command(0x80 | address); // Set DDRAM address command bit mask
}

void LCDWriteHex(unsigned char temp, unsigned char row, unsigned char col) {
    char c_temp[4]; // Buffer size for 2 hex digits + "0x" option or null terminator
    
    // "%02X" formats as uppercase hex, padding with a leading zero if under 0x10
    snprintf(c_temp, sizeof(c_temp), "%02X", temp);
    
    // Set cursor position and print
    LCD_SetCursor(row, col);
    LCD_String(c_temp);
}

void LCDWriteInt(int temp, unsigned char row, unsigned char col) {
    char c_temp[8]; // Buffer big enough for "-32768" + null terminator
    
    // Dynamically converts the integer to a string, automatically handling 
    // negative signs and any number of digits (up to the size of the buffer).
    snprintf(c_temp, sizeof(c_temp), "%d", temp);
    
    // Set cursor position using our previous library function
    LCD_SetCursor(row, col);
    
    // Print the formatted string
    LCD_String(c_temp);
}
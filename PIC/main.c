 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.2
 *
 * @version Package Version: 3.1.2
*/

/*
© [2026] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/
#include "mcc_generated_files/system/system.h"
#include <xc.h>
#include "LCD_HD44780.h"
#include "SB256.h"

#include <stdio.h>
#include <string.h>


#define MAX_ERRORS 12
#define DELAY_TIME 100  //microseconds
#define GADD_SIZE 247


    unsigned char t_list[13] = {24,20,12,16,8,4,44,43,11,9,41,42,10};
    unsigned char s_list[18]= {12,16,52,44,48,40,51,39,11,13,37,38,49,50,42,46,10,14};
    unsigned char e_list[18]= {20,12,16,8,40,52,51,19,11,17,9,49,50,18,10,14,6,38};
    unsigned char l_list[11]= {20,52,51,19,17,49,50,18,10,14,6};
    unsigned char c_list[12]= {40,12,16,52,51,19,17,49,50,10,14,38};
    unsigned char r_list[19]= {20,12,16,52,40,51,39,19,11,15,17,9,49,45,50,46,38,18,6};
    unsigned char n_list[24]={20,52,51,19,17,49,50,18,12,44,47,15,13,45,38,6,4,36,3,1,33,34,2};
    unsigned char o_list[20]= {12,16,52,44,48,40,51,39,19,7,17,5,49,37,50,42,46,38,10,14};
    const unsigned char gadd[GADD_SIZE] = {
    // === BLOCK 1 (+0) ===
    31, 23, 19, 11, 15,  7,  3, 27,
    63, 55, 51, 43, 47, 39, 35, 59,
    62, 54, 50,     46, 38, 34, 58,  // Removed: 42
    30, 22, 18, 10, 14,  6,  2, 26,
    28, 20, 16,  8, 12,  4,  0, 24,
    60, 52, 48, 40, 44, 36, 32, 56,
    61, 53, 49, 41, 45, 37, 33, 57,
    29, 21, 17,  9, 13,  5,  1, 25,
    // === BLOCK 2 (+64) ===
    95, 87, 83, 75, 79, 71, 67, 91,
    127,119,115,    111,103, 99,123,  // Removed: 107
        118,114,106,    102, 98,122,  // Removed: 126, 110
    94, 86, 82, 74, 78, 70, 66, 90,
    92, 84, 80, 72, 76, 68, 64, 88,
    124,116,112,104,108,100, 96,120,
    125,117,113,105,109,101, 97,121,
    93, 85, 81, 73, 77, 69, 65, 89,
    // === BLOCK 3 (+128) ===
    159,151,147,    143,135,131,155,  // Removed: 139
    191,183,179,171,175,167,163,187,
    190,182,178,170,174,166,162,186,
    158,150,146,138,142,134,    154,  // Removed: 130
    156,148,144,136,140,132,128,152,
    188,180,176,168,172,164,160,184,
    189,181,177,169,173,165,161,185,
    157,149,145,137,141,133,129,153,
    // === BLOCK 4 (+192) ===
    223,215,211,203,207,199,195,219,
    255,247,243,235,239,231,227,251,
        246,242,234,238,230,226,250,  // Removed: 254
    222,214,210,202,206,198,194,218,
    220,212,208,200,204,196,192,216,
    252,244,240,232,236,228,224,248,
    253,245,241,233,237,229,225,249,
    221,213,209,            197,193,217   // Removed: 201, 205
};

    const char* msg = "HELLO WORLD!\nMy name is SB256";


void displaySelectron(){
    unsigned char address;
    unsigned char i;
    
    // displays "SELECTRON"
     //Clear
        do{            
            __delay_ms(1);    
            write_bit(address, 0);
        } while (++address != 0);    
        //write 'S E'
        for (i=0;i<18;i++){
            __delay_ms(1);
            write_bit(s_list[i]-1,1);   
        }
        for (i=0;i<18;i++){
            __delay_ms(1);
            write_bit(e_list[i]-1+64,1);   
        }
        __delay_ms(500); 
       
        //Clear
        do{            
            __delay_ms(1);    
            write_bit(address, 0);
        } while (++address != 0); 
        //write 'L E'
        for (i=0;i<11;i++){
            __delay_ms(1);
            write_bit(l_list[i]-1,1);   
        }
        for (i=0;i<18;i++){
            __delay_ms(1);
            write_bit(e_list[i]-1+64,1);   
        }
        __delay_ms(500); 
        
        //Clear
        do{            
            __delay_ms(1);    
            write_bit(address, 0);
        } while (++address != 0); 
        //write 'C T '
        for (i=0;i<12;i++){
            __delay_ms(1);
            write_bit(c_list[i]-1,1);   
        }
        for (i=0;i<13;i++){
            __delay_ms(1);
            write_bit(t_list[i]-1+64,1);   
        }
        __delay_ms(500);
        
        //Clear
        do{            
            __delay_ms(1);    
            write_bit(address, 0);
        } while (++address != 0); 
        //write 'R O '
        for (i=0;i<19;i++){
            __delay_ms(1);
            write_bit(r_list[i]-1,1);   
        }
        for (i=0;i<20;i++){
            __delay_ms(1);
            write_bit(o_list[i]-1+64,1);   
        }
        __delay_ms(500);
        
        //Clear
        do{            
            __delay_ms(1);    
            write_bit(address, 0);
        } while (++address != 0); 
        //write 'N '
        for (i=0;i<24;i++){
            __delay_ms(1);
            write_bit(n_list[i]-1,1);   
        }
        __delay_ms(500);
    
}

void testMemory (unsigned char bit){
    
    unsigned char address;
    unsigned char i,k;
    unsigned char error_log[MAX_ERRORS]; 
    int error_count = 0; 
    LCD_String("SB256 W/R Test",1,1);
    error_count=0;
    LCD_String("WrAdd:",2,1);
    LCD_String("WrData:",2,11);
    __delay_us(DELAY_TIME);
    address=0;
    do{            
       __delay_us(DELAY_TIME);   
            write_bit(address, bit);
            LCDWriteHex(address, 2, 8); 
            LCDWriteHex(bit, 2, 18); 
     } while (++address != 0);// cheat to cover 0 to 256 using an 8-bit variable
    LCD_String("RdAdd:",2,1);
    LCD_String("RdData:",2,11);
    address=0;
    do{            
        __delay_us(DELAY_TIME);   
        i=read_bit(address);
        if (i^bit) {
            if (error_count < MAX_ERRORS){
                error_log[error_count]=address;
                } 
            error_count++;
        }
        LCDWriteHex(address, 2, 8); 
        LCDWriteHex(i, 2, 18); 
    } while (++address != 0);
    //Prepare report
    if ((error_count==0)||(error_count>MAX_ERRORS)){
        LCD_String("                    ",3,1);           
        LCD_String("NumErrors       ",4,1);
        LCDWriteInt(error_count,4,13);
    } else {
        LCD_String("                    ",3,1);
        LCD_String("                    ",4,1);
        for (k=0;k<error_count;k++){
            if ((3*k+1)>20){
                LCDWriteHex(error_log[k], 4, (3*k+1)-21); 
            }else{
            LCDWriteHex(error_log[k], 3, (3*k+1));
            }
        }
    }  
}

//TO DO  change all for (address) loops to DO WHILE loops like this.)
void toggle_display(unsigned char bit){
    unsigned char address;
    address=0; // important
    LCD_String("WrAdd:",2,1);
    LCD_String("WrData:",2,11);
    LCDWriteHex(bit, 2, 18);
    do {            
        __delay_us(DELAY_TIME);   
        write_bit(address, bit);
        LCDWriteHex(address, 2, 8);    
    } while (++address != 0);//cheat to cover all 256, 0x00 to 0xFF using an 8 bit variable.
    //supposed to be more efficient than a for-next loop using an int.
}

void stream_message_to_selectron(const char* message) {
    unsigned int expected_bits;
    unsigned char total_bits_written;
    unsigned char char_index,bit,bit_value,i;
    char current_char;
    
    expected_bits = (strlen(message) + 1) * 8;

    if (expected_bits > GADD_SIZE) {// number of good bits.
        // Optional: Call an error routine, blink an LED, or truncate here
        return; 
    }

    total_bits_written = 0;
    char_index = 0;

    // 3. Write the body characters
    while (message[char_index] != '\0') {
        current_char = message[char_index];

        for (i = 0; i < 8; i++) {
            bit = 7 - i; 
            bit_value = (current_char >> bit) & 1;
            __delay_us(DELAY_TIME);;
            write_bit(gadd[total_bits_written], bit_value);
            total_bits_written++;
        }// bit i
        char_index++;
    }//while

    // 4. Write the 8-bit Null Terminator (\0)
    for (i = 0; i < 8; i++) {
        bit = 7 - i;
        __delay_us(DELAY_TIME);
        write_bit(gadd[total_bits_written], 0);
        total_bits_written++;
    }//bit i
}// stream



void read_message_from_selectron(char* output_buffer, unsigned char max_buffer_size) {
    unsigned char total_bits_read = 0;
    unsigned char char_index = 0;
    char current_char = 0;
    unsigned char running = 1;
    unsigned char physical_bit,i,bit;

    // Safety check: ensure our output buffer has at least room for a null terminator
    if (max_buffer_size == 0) return;

    while (running) {
        current_char = 0; // Clear character buffer
        // Assemble 8 bits into a single character (MSB to LSB)
        for (i = 0; i < 8; i++) {
            bit = 7 - i;
            __delay_us(DELAY_TIME);
            physical_bit = read_bit(gadd[total_bits_read]);
            
            if (physical_bit == 1) {
                current_char |= (1 << bit);
            }

            // stop if we read the final bit of the tube (address 251 of gadd[])
            if (total_bits_read == GADD_SIZE - 1) {
                running = 0; 
            }
            total_bits_read++;
        }

        // Store the assembled character inside your array
        output_buffer[char_index] = current_char;
        char_index++;

        // Stop if we hit the Null Terminator OR run out of array space
        // (Leaving 1 byte free at the very end of the array for a guaranteed null)
        if (current_char == '\0' || char_index >= (max_buffer_size - 1)) {
            break;
        }
    }

    // Force a strict null terminator at the end of the text string 
    // to guarantee safe printing to your LCD screen
    output_buffer[char_index] = '\0';
}


/*
    Main application
*/

int main(void)
{
    
    unsigned char address;
    unsigned char i, bit;
    char my_lcd_buffer[32];

    SYSTEM_Initialize();
    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts 
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts 
    // Use the following macros to: 

    // Enable the Global Interrupts 
    //INTERRUPT_GlobalInterruptEnable(); 

    // Disable the Global Interrupts 
    //INTERRUPT_GlobalInterruptDisable(); 

    // Enable the Peripheral Interrupts 
    //INTERRUPT_PeripheralInterruptEnable(); 

    // Disable the Peripheral Interrupts 
    //INTERRUPT_PeripheralInterruptDisable(); 
    
    init_SB256();          
    bit=0;
    __delay_ms(10);
 
    LCD_Init();                 // Run HD44780 4-bit initialization sequence
    
    //READ=0;   //makes it visual
    READ = 1;//make it not
    while(1) {
        
        LCD_Clear();
        //LCD_String("CLEAR SB256",1,1);
        //toggle_display(0);
        //LCD_Clear();
        LCD_String("WRITING MSG",1,1);
        stream_message_to_selectron(msg);
        __delay_ms(1000);
        LCD_Clear();
        LCD_String("READ DATA in",4,1);
        for (i=5;i>0;i--){
           LCDWriteInt(i,4,18);
        __delay_ms(1000);
        }
        read_message_from_selectron(my_lcd_buffer, 32);       
        LCD_Clear();
        LCD_String(my_lcd_buffer,1,1); 
        
        //__delay_ms(5000);
        LCD_String("READPLATEOFF in",4,1);
        for (i=5;i>0;i--){
           LCDWriteInt(i,4,18);
        __delay_ms(1000);
        }
        
        READ=0;
        LCD_String("READPLATE ON in",4,1);
        for (i=9;i>0;i--){
           LCDWriteInt(i,4,18);
        __delay_ms(1000);
        }
        READ=1;
        LCD_String("RE-READ DATA in ",4,1);
        for (i=4;i>0;i--){
           LCDWriteInt(i,4,18);
        __delay_ms(1000);
        }
        read_message_from_selectron(my_lcd_buffer, 32);       
        LCD_Clear();
        LCD_String(my_lcd_buffer,1,1); 
        
        LCD_String("WRITE DATA in",4,1);
        for (i=5;i>0;i--){
           LCDWriteInt(i,4,18);
        __delay_ms(1000);
        }
        
        //testMemory (bit);//requires READ=1;
        //displaySelectron();//requires READ=0;
        //toggle_display(bit);//requires READ=0;
        bit=!bit;   
        
    
    }   
   
    
}

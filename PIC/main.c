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



    unsigned char t_list[13] = {24,20,12,16,8,4,44,43,11,9,41,42,10};
    unsigned char s_list[18]= {12,16,52,44,48,40,51,39,11,13,37,38,49,50,42,46,10,14};
    unsigned char e_list[18]= {20,12,16,8,40,52,51,19,11,17,9,49,50,18,10,14,6,38};
    unsigned char l_list[11]= {20,52,51,19,17,49,50,18,10,14,6};
    unsigned char c_list[12]= {40,12,16,52,51,19,17,49,50,10,14,38};
    unsigned char r_list[19]= {20,12,16,52,40,51,39,19,11,15,17,9,49,45,50,46,38,18,6};
    unsigned char n_list[24]={20,52,51,19,17,49,50,18,12,44,47,15,13,45,38,6,4,36,3,1,33,34,2};
    unsigned char o_list[20]= {12,16,52,44,48,40,51,39,19,7,17,5,49,37,50,42,46,38,10,14};
    const unsigned char gadd[247] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 
    16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 
    32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 43, 44, 45, 46, 47, 
    48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 
    64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 77, 78, 79, 
    80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 
    96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 
    111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 
    127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 140, 141, 142, 144, 
    145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 
    161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 
    178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 
    194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 
    210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 
    226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 
    242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 255
};

    const char* msg = "HELLO WORLD!\nSB256";


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
        do{            
            __delay_us(DELAY_TIME);   
            write_bit(address, bit);
            LCDWriteHex(address, 2, 8); 
            LCDWriteHex(bit, 2, 18); 
        } while (++address != 0);
        
        
        LCD_String("RdAdd:",2,1);
        
        LCD_String("RdData:",2,11);
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
    address=0;
        
        LCD_String("WrAdd:",2,1);
        
        LCD_String("WrData:",2,11);
        LCDWriteHex(bit, 2, 18); 
        do {            
            __delay_ms(10);   
            write_bit(address, bit);
            LCDWriteHex(address, 2, 8);    
        } while (++address != 0);
}

void stream_message_to_selectron(const char* message) {
    unsigned int expected_bits;
    unsigned char total_bits_written;
    unsigned char char_index,bit,bit_value,i;
    char current_char;
    
    expected_bits = (strlen(message) + 1) * 8;

    if (expected_bits > 247) {// number of good bits.
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
            if (total_bits_read == 246) {
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
        LCD_String("WRITING MSG",1,1);
        LCD_String("READ IN",4,1);
         __delay_ms(1000);
        stream_message_to_selectron(msg);
        for (i=5;i>0;i--){
           LCDWriteInt(i,4,13);
        __delay_ms(1000);
        }
        read_message_from_selectron(my_lcd_buffer, 32);       
        LCD_Clear();
        LCD_String(my_lcd_buffer,1,1); 
        
        //__delay_ms(5000);
        LCD_String("READOFF in",4,1);
        for (i=5;i>0;i--){
           LCDWriteInt(i,4,13);
        __delay_ms(1000);
        }
        
        READ=0;
        LCD_String("READ ON in",4,1);
        for (i=9;i>0;i--){
           LCDWriteInt(i,4,13);
        __delay_ms(1000);
        }
        READ=1;
        LCD_String("RE-READ",4,1);
        for (i=4;i>0;i--){
           LCDWriteInt(i,4,13);
        __delay_ms(1000);
        }
        read_message_from_selectron(my_lcd_buffer, 32);       
        LCD_Clear();
        LCD_String(my_lcd_buffer,1,1); 
        
        LCD_String("WRITE in",4,1);
        for (i=5;i>0;i--){
           LCDWriteInt(i,4,13);
        __delay_ms(1000);
        }
        
        //testMemory (bit);//requires READ=1;
        //displaySelectron();//requires READ=0;
        //toggle_display(bit);//requires READ=0;
        bit=!bit;   
        
    
    }   
   
    
}

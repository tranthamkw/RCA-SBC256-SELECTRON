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


#define SELECT    LATBbits.LATB3  // Controls the selection bars / matrix decoding
#define WRITE     LATBbits.LATB1  // Controls the +360V writing pulse plate
#define QPOINT    LATBbits.LATB2  // Controls quiescent/idle state timing logic
#define READ      LATBbits.LATB0  // Controls the +150V / -100V read plate pulse
#define RESETRS   LATBbits.LATB4  // Controls the read sense wire reset logic

#define READBIT PORTBbits.RB5
#define _XTAL_FREQ 16000000 // Define clock frequency for macros

#define tsr 70
// settling time after deselect bars before write pulse applied 8 -> 70uS
#define tp 105
// time that write pulse is active 12 -> 105uS
#define td 70
// time for write pulse to decay. 8 ->70uS
// used for the case of writing a zero.
#define tz 88
// safety time after write pulse done, deselect done, before re-establish Q-point 10->88uS
#define MAX_ERRORS 12
#define DELAY_TIME 10



    unsigned char t_list[13] = {24,20,12,16,8,4,44,43,11,9,41,42,10};
    unsigned char s_list[18]= {12,16,52,44,48,40,51,39,11,13,37,38,49,50,42,46,10,14};
    unsigned char e_list[18]= {20,12,16,8,40,52,51,19,11,17,9,49,50,18,10,14,6,38};
    unsigned char l_list[11]= {20,52,51,19,17,49,50,18,10,14,6};
    unsigned char c_list[12]= {40,12,16,52,51,19,17,49,50,10,14,38};
    unsigned char r_list[19]= {20,12,16,52,40,51,39,19,11,15,17,9,49,45,50,46,38,18,6};
    unsigned char n_list[24]={20,52,51,19,17,49,50,18,12,44,47,15,13,45,38,6,4,36,3,1,33,34,2};
    unsigned char o_list[20]= {12,16,52,44,48,40,51,39,19,7,17,5,49,37,50,42,46,38,10,14};


void init_SB256(){
    SELECT=0;
    READ=1;
    WRITE=1;
    QPOINT=1;
    
    /*
    WRITE
    1 = Idle Write plate = 0V
    0 = Select active. write plate = 360V.
    
    QPOINT
    1 = Idle Q-point. All outputs 0V.  This allows maintaining current
    0 = Select active. See SELECT status for selector-bar status
     
    SELECT
    1 = Address selected bar = 0V, all others = -250V
    0 = De-select all; when writing 0; ALL outputs -250V
    
    READ 
     0 = +HV. allow electron beam through. Use this for constant visual display
     1 = -100 V. stop electron beam      
     */
     
    READ=0;
    WRITE = 0;//WRITE TO +HV
    __delay_us(tp);
    QPOINT = 0;// ALL BARS -HV               
    __delay_us(tp);
    WRITE = 1;  
    
    RESETRS =0;
}


void write_bit(char add, char mybit){
    PORTD = add;//SELECT AN ADDRESS
    __delay_us(200);
    QPOINT = 0;// ALL BARS -HV, ALLOW SELECTION
    SELECT = 1;//ADDRESS SELECTED BARS = 0V, ALL OTHERS -250V
    __delay_us(tsr);
    WRITE = 0;//WRITE PLATE TO +360
    __delay_us(tp);
  // IF WRITTING 0, SELECT=0 
    if (mybit==0) {
        SELECT=0;  //DESELECT ALL BARS; ALL BARS = -250V
        __delay_us(tp);
    }      
    WRITE = 1;// RETURN WRITE PULSE TO 0V
    __delay_us(td);       
    SELECT = 1;//RETURN SELECT, ADDRESS SELECTED BARS = 0V
    __delay_us(tz);
    QPOINT = 1; //RETURN TO Q-POINT;  ALL BARS  = 0V     
}

char read_bit(char add){
    char j;
        RESETRS =0;
        READ=1;//turn off current to Faraday cage
         //begin read process. it should have been off long before reaching this 
        PORTD = add;//SELECT AN ADDRESS
        __delay_us(100);
        QPOINT = 0;// ALL BARS -HV, ALLOW SELECTION
        SELECT = 1;//ADDRESS SELECTED BARS = 0V, ALL OTHERS -250V
        __delay_us(100);
        RESETRS =1;// reset the RS Latch
        __delay_us(10);//pulse width of RS reset
        RESETRS =0;
        
        READ=0; // now open the read plate
        __delay_us(100); //pulse the read plate
         j=READBIT; //read bit durring pulse of read
        __delay_us(100); //pulse the read plate
        READ=1;
        __delay_us(20);
       
        SELECT = 1;//RETURN SELECT, ADDRESS SELECTED BARS = 0V
        __delay_us(tz);
        QPOINT = 1; //RETURN TO Q-POINT;  ALL BARS  = 0V   
        return j;
}

void displaySelectron(){
    char address;
    char i;
    
    // displays SELECTRON
     //Clear
        for (address = 0;address<0xFF;address++){            
            __delay_ms(1);    
            write_bit(address, 0);
        }       
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
        for (address = 0;address<0xFF;address++){            
            __delay_ms(1);   
            write_bit(address, 0);
        }
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
        for (address = 0;address<0xFF;address++){            
            __delay_ms(1);   
            write_bit(address, 0);
        }
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
        for (address = 0;address<0xFF;address++){            
            __delay_ms(1);   
            write_bit(address, 0);
        }
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
        for (address = 0;address<0xFF;address++){            
            __delay_ms(1);  
            write_bit(address, 0);
        }
        //write 'N '
        for (i=0;i<24;i++){
            __delay_ms(1);
            write_bit(n_list[i]-1,1);   
        }
        __delay_ms(500);
    
}

void testMemory (char bit){
    
    char address;
    char i,k;
    unsigned char error_log[MAX_ERRORS]; 
    unsigned char error_count = 0; 
    
    LCD_SetCursor(1, 1);
    LCD_String("SB256 W/R Test");
    error_count=0;
        LCD_SetCursor(2,1);
        LCD_String("WrAdd:");
        LCD_SetCursor(2,11);
        LCD_String("WrData:");
        __delay_ms(DELAY_TIME);
        for (address = 0;address<0xFF;address++){            
            __delay_ms(DELAY_TIME);   
            write_bit(address, bit);
            LCDWriteHex(address, 2, 8); 
            LCDWriteHex(bit, 2, 18); 
        }
        LCD_SetCursor(2,1);
        LCD_String("RdAdd:");
        LCD_SetCursor(2,11);
        LCD_String("RdData:");
        for (address = 0;address<0xFF;address++){            
            __delay_ms(DELAY_TIME);   
            i=read_bit(address);
            if (i^bit) {
                 
                if (error_count < MAX_ERRORS){
                    error_log[error_count]=address;
                } 
                error_count++;
            }
            LCDWriteHex(address, 2, 8); 
            LCDWriteHex(i, 2, 18); 
        }
        
        //Prepare report
        if ((error_count==0)||(error_count>MAX_ERRORS)){
            LCD_SetCursor(3,1);
            LCD_String("                    ");           
            LCD_SetCursor(4,1);
            LCD_String("NumErrors       ");
            LCDWriteInt(error_count,4,13);
        } else {
            LCD_SetCursor(3,1);
            LCD_String("                    ");
            LCD_SetCursor(4,1);
            LCD_String("                    ");
            for (k=0;k<error_count;k++){
                if ((3*k+1)>20){
                    LCDWriteHex(error_log[k], 4, (3*k+1)-21); 
                }else{
                    LCDWriteHex(error_log[k], 3, (3*k+1));
                }
                
            }
        }  
}
/*
    Main application
*/

int main(void)
{
    
    char address;
    char bit;
    char i;

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

    READ = 0;
    
    
    init_SB256();          
    bit=0;
    __delay_ms(10);
    address=0; 
    
    LCD_Init();                 // Run HD44780 4-bit initialization sequence
    
    
    
    
    
    //READ=0;   //makes it visual
    READ=1;//make it not
    while(1) {
        
        testMemory (bit);
        //displaySelectron();
        bit=!bit;     
    
    }   
   
    
}

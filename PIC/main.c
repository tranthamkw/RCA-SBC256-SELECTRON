 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.0
*/

/*
© [2024] Microchip Technology Inc. and its subsidiaries.

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

#define SELECT PORTBbits.RB3
#define WRITE PORTBbits.RB1
#define QPOINT PORTBbits.RB2
#define READ PORTBbits.RB0
#define TAU 100

void delay(long n){
long k;
for (k = 0; k<n; k++);
}

/*
    Main application
*/

int main(void)
{
    char tsr, tp, td, tz, te;
    char address;
    char bit;
    char inc;
    
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
 
  
 */
 


tsr = 8; // settling time after deselect bars before write pulse applied
tp = 12; // time that write pulse is active
td = 8; // time for write pulse to decay. 
// used for the case of writing a zero.
tz = 8; // safety time after write pulse done, deselect done, before re-establish Q-point
bit=0;
delay(10000);
delay(10000);
 READ=0;
 WRITE = 0;//WRITE TO +HV
delay(tp);
 QPOINT = 0;// ALL BARS -HV               
 delay(tp);
 WRITE = 1;
inc=0;            
           
address=0;
    while(1)
    {            
      delay(10000); 
      delay(10000);     
        for (address = 0;address<0xFF;address++){            
            delay(3000);
            PORTD = address;//SELECT AN ADDRESS
            QPOINT = 0;// ALL BARS -HV, ALLOW SELECTION
            SELECT = 1;//ADDRESS SELECTED BARS = 0V, ALL OTHERS -250V
            //This step should not be required. 
            
            delay(tsr);
            
            WRITE = 0;//WRITE PLATE TO +360V
			delay(tp);
            // IF WRITTING 0, SELECT=0 
            if (bit==0) {
                SELECT=0;  //DESELECT ALL BARS; ALL BARS = -250V
                delay(tp);
            }  
            
            WRITE = 1;// RETURN WRITE PULSE TO 0V
            delay(td);       
            SELECT = 1;//RETURN SELECT, ADDRESS SELECTED BARS = 0V
            delay(tz);
            READ=1;
            delay(2*tz);
            READ=0;
            
            
            
            QPOINT = 1; //RETURN TO Q-POINT;  ALL BARS  = 0V
        }
        bit=!bit;  
       
    }    
}
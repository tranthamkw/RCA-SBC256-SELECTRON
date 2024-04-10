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
    
    SYSTEM_Initialize();

    

       
SELECT=0;
READ=1;
WRITE=0;
QPOINT=1;

	
/*
 
 Select
0 = Select bar based on address
1 = De-select all; writing 0;
 all outputs -100V
 * 
 
 Qpoint
1 = ilde Qpoint. All outputs 0V
0 = Select active.
 */
    
//define times. See patent 2,635,201, Figure 7 and text within
/*
unknown clock speed. dang it. 

 delay x    	t(uS)
10              137
20          	254
40              484
80              944
160             1860
300             3460
500             5760
 
 slope= 11.46734458
 yint=  24.32107313
 
 t = slope x + yint
  
  
 */

tsr = 2; // settling time after deselect bars before write pulse applied
tp = 10; // time that write pulse is active
td = 10; // time for write pulse to decay. This marks the end of deselect
// used for the case of writing a zero.
tz = 2; // safety time after write pulse done, deselect done, before re-establish Q-point
bit=0;
delay(10000);

 WRITE = 1;//WRITE TO +HV
delay(tp);
 QPOINT = 0;// ALL BARS -HV               
 delay(tp);
 WRITE = 0;
            
            
address=0;
    while(1)
    {
        for (address = 0;address<0xFF;address++){
         //SELECT AN ADDRESS
            
            delay(1000);
            //delay(10000);
            
            PORTD = address;
            
			
             
            QPOINT = 0;// ALL BARS -HV
            SELECT = 0;// SELECTED BARS 0V
            delay(tsr);
            
            WRITE = 1;//WRITE TO +HV
			delay(tp);
            // IF WRITTING 0, SELECT=1 
            if (bit==1) {
                SELECT=1;
                delay(tp);
            }
            
            WRITE = 0;
            delay(td);
            
            SELECT = 0;
            delay(tz);
            QPOINT = 1; 
            
        }
			
            
     bit=!bit;      
       
    }    
}

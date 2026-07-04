/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef SB256_H
#define	SB256_H

#include <xc.h> // include processor files - each processor file is guarded.  

// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations
#define _XTAL_FREQ 16000000 // Define clock frequency for macros
#define SELECT    LATBbits.LATB3  // Controls the selection bars / matrix decoding
#define WRITE     LATBbits.LATB1  // Controls the +360V writing pulse plate
#define QPOINT    LATBbits.LATB2  // Controls quiescent/idle state timing logic
#define READ      LATBbits.LATB0  // Controls the +150V / -100V read plate pulse
#define RESETRS   LATBbits.LATB4  // Controls the read sense wire reset logic

#define READBIT PORTBbits.RB5

#define tsr 70
// settling time after deselect bars before write pulse applied 8 -> 70uS
#define tp 105
// time that write pulse is active 12 -> 105uS
#define td 70
// time for write pulse to decay. 8 ->70uS
// used for the case of writing a zero.
#define tz 88
// safety time after write pulse done, deselect done, before re-establish Q-point 10->88uS
// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation



void init_SB256();
void write_bit(unsigned char add, unsigned char mybit);
unsigned char read_bit(unsigned char add);


#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */


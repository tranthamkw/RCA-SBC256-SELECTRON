/*
 * File:   SB256.c
 * Author: tranthamkw
 *
 * Created on July 3, 2026, 6:01 PM
 */


#include "SB256.h"
#include<xc.h>


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


void write_bit(unsigned char add, unsigned char mybit){
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

unsigned char read_bit(unsigned char add){
    unsigned char j;
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
        __delay_us(150); //pulse the read plate
         j=READBIT; //read bit durring pulse of read
        __delay_us(75); //pulse the read plate
        READ=1;
        __delay_us(50);
       
        SELECT = 1;//RETURN SELECT, ADDRESS SELECTED BARS = 0V
        __delay_us(tz);
        QPOINT = 1; //RETURN TO Q-POINT;  ALL BARS  = 0V   
        return j;
}

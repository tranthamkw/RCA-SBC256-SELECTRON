Project goal:
develop a driver to demonstrate  operation a RCA SB 256 selectron tube.

Initial information  and references taken from https://www.rcaselectron.com/index1.html with much appreciation to Charles S. Osborne for collecting this information.

General outline

General theory of operation document

Specific electrical implementation to drive the SB256

4/8/22- initial test with PIC controller and drivers works.  Able to write 1's and 0's.  Sequentially step through all 0x00 to 0xFF address and write 1, then go through and write 0.  The data sheet for the selector bar pins appears to be in error, as it was not stepping through the bits in the order expected. Not sure which pin is H3 and there are two H4 pins.  Also the H group and V group appear to be reversed on the data sheet as the address count increments generally horizonally as we expect a general veritcal increment. Finally, the H' group appears to be out of order as it would increment 32 bits at a time per 64-bit patch, steping through to the next one-of-four 64-bit patch; expected a full complete 64-bit write per patch before moving to the next. 

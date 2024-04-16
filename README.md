Project goals:
1. develop a driver to demonstrate  operation a RCA SB 256 selectron tube.
2. educate:  there are some very poor if not wrong descriptions in the interwebs about how this device works - vis-a-vis physics of operation.  These descriptions need to be corrected.

Initial information  and references taken from https://www.rcaselectron.com/index1.html with much appreciation to Charles S. Osborne for collecting this information.

General outline

General theory of operation document

Specific electrical implementation to drive the SB256

4/8/22- initial test with PIC controller and drivers works.  Able to write 1's and 0's.  Sequentially step through all 0x00 to 0xFF address and write 1, then go through and write 0.  The data sheet for the selector bar pins appears to be in error, as it was not stepping through the bits in the order expected. Not sure which pin is H3 and there are two H4 pins.  Also the H group and V group appear to be reversed on the data sheet as the address count increments generally horizonally as we expect a general veritcal increment. Finally, the H' group appears to be out of order as it would increment 32 bits at a time per 64-bit patch, steping through to the next one-of-four 64-bit patch; expected a full complete 64-bit write per patch before moving to the next. 


4/12/22 - The data sheet appears to be incorrect with regard to selector bar pins.  The groups (H, V, H', and V') appear correct, but any given pin out of order.  An obvious error in the data sheet does not show a pin for H3, and shows two pins for H4.  The H' group appear to be out of order (Or I miss-labeled the wires when arranging the socket). I retract the statement that the V and H group are reversed.  I did shift the H' pins around so that each 64-bit block is written in order. The bit - order of write was determined by writing 1 then 0 fifty times with sufficient pause between so I could label each address. .. before the PIC moved to the next address.  This order is documented in /Bar/Decoder

4/12/22  Reduced delay times in PIC code to see how fast we can reliably write to the memory.  An unused PIC output wrote 0 at the begining of the write process, then 1 at the end of writing all 256 bits.  The time to write 0 to the eyelets is slightly longer than 1, (see the eyelet I-V curve and writing description).  The nominal time to write is about 60mS. Oh gosh! 256 bits in 60mS!
256 bits / (1024^2 bits per MB) / 60mS = 0.004 MB/S.  OR, put another way, it would take 245 seconds = 4 ish minutes to write a MB.  

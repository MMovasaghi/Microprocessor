## XBee Commands

* [Site-Source](https://www.digikey.com/eewiki/display/Wireless/XBee+AT+Mode+-+Transmit+and+Command+Mode+Example)

xbee.attach(&ReceiveXbee);  //attach the xbee interrupt service upon byte receipt
<br/>
xbee.baud(9600);  //xbee baud rate
<br/>
pc.baud(9600);  //pc serial baud rate

> Command Mode <Type-ENTER> // Set the mode to get commands

> ATID <Type-Enter>  // PIN ID Configuration

> ATSH <Type-ENTER>  // The terminal will display the UPPER 32 bits of the module's Serial ID

> ATSL <Type-ENTER>  // The terminal will display the LOWER 32 bits of the module's Serial ID

> ATDH <Type-ENTER>  // The terminal will Destination Address UPPER 32 bits of the module's Serial ID
  
> ATDH <Destination Address UPPER 32 bits of the module's Serial ID><Type-ENTER>  // To Change the terminal will Destination Address UPPER 32 bits of the module's Serial ID

> ATDL <ENTER>  // The terminal will Destination Address LOWER 32 bits of the module's Serial ID
  
> ATDL <Destination Address LOWER 32 bits of the module's Serial ID><Type-ENTER>  // To Change the terminal will Destination Address LOWER 32 bits of the module's Serial ID

> ATAC <Type-ENTER>  // Apply Changes (Save changes)

> Transmit Mode <Type-ENTER> // Set the mode to Transmit mode

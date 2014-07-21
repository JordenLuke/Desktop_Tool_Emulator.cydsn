/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>
#include <stdio.h>

uint8 i2c_write(uint8 subAddr, uint8 *buffer, uint8 buff_size);
uint8 i2c_read(uint8 subAddr, uint8 *buffer, uint8 buff_size);
void configure();


const int ADDRESS = 0x0E;
int main()
{
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
	I2C_1_Start();
	UART_1_Start();
    CyGlobalIntEnable;  /* Uncomment this line to enable global interrupts. */
	configure();
    for(;;)
    {
    
		
    }
}
uint8 i2c_write(uint8 subAddr, uint8 *buffer, uint8 buff_size) {

	int i;
	uint8 status;
	char array[10];
	I2C_1_I2CMasterClearStatus();

	
	//Set subaddr
	status = I2C_1_I2CMasterSendStart(ADDRESS, 0);
	if (status != I2C_1_I2C_MSTR_NO_ERROR) {
		i= sprintf(array, "X: %d \n",status);
		UART_1_UartPutString(array);;
		return status;
	}
   
     
	status = I2C_1_I2CMasterWriteByte(subAddr);
	if (status != I2C_1_I2C_MSTR_NO_ERROR) {
		i= sprintf(array, "X: %d \n",status);
		UART_1_UartPutString(array);
		return status;
	}
               
	for (i=0;i<buff_size;i++) {
		status = I2C_1_I2CMasterWriteByte(buffer[i]);
		if (status != I2C_1_I2C_MSTR_NO_ERROR) {
			return status;
			i= sprintf(array, "X: %d \n",status);
			UART_1_UartPutString(array);
		}
	}
                  
		status = I2C_1_I2CMasterSendStop();
	if (status != I2C_1_I2C_MSTR_NO_ERROR) {
		return status;
		i= sprintf(array, "X: %d \n",status);
		UART_1_UartPutString(array);
	}   
	return status;
}
uint8 i2c_read(uint8 subAddr, uint8 *buffer, uint8 buff_size) {

	uint8 status;
	int i;
	char array[12];
	
	I2C_1_I2CMasterClearStatus();
    //UART_1_PutString("make it here?  \n"); 
	//Set subaddr
	status = I2C_1_I2CMasterSendStart(ADDRESS, 0);
	if (status != I2C_1_I2C_MSTR_NO_ERROR) {
		i= sprintf(array, "X: %d \n",status);
		UART_1_UartPutString(array);
		return status;
	}
        //UART_1_PutString("make it here?  \n");        
	buffer[0] = I2C_1_I2CMasterReadByte(0);
                   
	status = I2C_1_I2CMasterWriteByte(subAddr);
	if (status != I2C_1_I2C_MSTR_NO_ERROR) {
		return status;
	}
               
	status = I2C_1_I2CMasterSendRestart(ADDRESS, 1);
	if (status != I2C_1_I2C_MSTR_NO_ERROR) {
		return status;
	}               
               
	for (i=0;i<buff_size;i++) {
		buffer[i] = I2C_1_I2CMasterReadByte( (i<(buff_size-1) ) );
	}
 
	status = I2C_1_I2CMasterSendStop();
	if (status != I2C_1_I2C_MSTR_NO_ERROR) {
        return status;
 	}  
	return 0;
}
void configure()
{
	uint8 array[2];
	array [0] = 0x80;
	i2c_write(0x11,array,1);
	
	array [0] = 1;
	i2c_write(0x10,array,1);
}
/* [] END OF FILE */

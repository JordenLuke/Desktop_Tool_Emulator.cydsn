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
void spi_read( uint8 reg, uint8 *buffer);
void configure();


const int ADDRESS = 0x0E;
int main()
{
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
	uint8 array[6]={1,2,3,1,2,3};
	uint8 array2[6]={1,2,3,1,2,3};
	int16 x = 6;
	int16 y = 7;
	int16 z = 8;
	int16 ax = 9;
	int16 ay =0;
	int16 az;
	
	char *buffer;
	int n;
	
	//I2C_1_Start();
	UART_1_Start();
	//SPIM_1_Start();
    CyGlobalIntEnable;  /* Uncomment this line to enable global interrupts. */
	//configure();
    for(;;)
    {
    	
		//i2c_read(0x1u,array, 6);
		//spi_read(0x28,array2);
		x = (array[0] << 8)|array[1];
		y = (array[2] << 8)|array[3];
		z = (array[4] << 8)|array[5];
		
		ax = (array2[1] << 8)|array2[0];
		ay = (array2[3] << 8)|array2[2];
		az = (array2[5] << 8)|array2[4];
		CyDelay(1000);
		UART_1_UartPutString("MAG: \n\r");
		//n=sprintf(buffer, "X: %d \nY: %d \nZ: %d \n",(int)x,(int)y,(int)z);
		//UART_1_SpiUartPutArray(buffer, n);
		UART_1_UartPutString("ACC: \n\r");
		n=sprintf(buffer, "X: %d \nY: %d \nZ: %d \n\r ",ax,ay,az);
		UART_1_SpiUartPutArray(buffer, n);
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
		i= sprintf(array, "Error 1.1: %d \n",status);
		UART_1_UartPutString(array);;
		return status;
	}
   
     
	status = I2C_1_I2CMasterWriteByte(subAddr);
	if (status != I2C_1_I2C_MSTR_NO_ERROR) {
		i= sprintf(array, "Error 1.2: %d \n",status);
		UART_1_UartPutString(array);
		return status;
	}
               
	for (i=0;i<buff_size;i++) {
		status = I2C_1_I2CMasterWriteByte(buffer[i]);
		if (status != I2C_1_I2C_MSTR_NO_ERROR) {
			return status;
			i= sprintf(array, "Error 1.3: %d \n",status);
			UART_1_UartPutString(array);
		}
	}
                  
		status = I2C_1_I2CMasterSendStop();
	if (status != I2C_1_I2C_MSTR_NO_ERROR) {
		return status;
		i= sprintf(array, "Error 1.4: %d \n",status);
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
		i= sprintf(array, "Error 2.1: %d \n",status);
		UART_1_UartPutString(array);
		return status;
	}
           
	///buffer[0] = I2C_1_I2CMasterReadByte(0);
                   
	status = I2C_1_I2CMasterWriteByte(subAddr);
	if (status != I2C_1_I2C_MSTR_NO_ERROR) {
		return status;
	}
	UART_1_UartPutString("make it here?  \n\r"); 
	I2C_1_I2CMasterReadBuf(ADDRESS,buffer,buff_size,(I2C_1_I2C_MODE_REPEAT_START | I2C_1_I2C_MODE_COMPLETE_XFER) );
               
//	status = I2C_1_I2CMasterSendRestart(ADDRESS, 1);
//	if (status != I2C_1_I2C_MSTR_NO_ERROR) {
//		return status;
//	}               
//               
//	for (i=0;i<buff_size;i++) {
//		buffer[i] = I2C_1_I2CMasterReadByte( (i<(buff_size-1) ) );
//	}
 
	status = I2C_1_I2CMasterSendStop();
	if (status != I2C_1_I2C_MSTR_NO_ERROR) {
        return status;
 	}  
	return 0;
}
void configure()
{
	uint8 array[2];
	Pin_4_Write(1);
	array [0] = 0x80;
	i2c_write(0x11,array,1);
	
	array [0] = 1;
	i2c_write(0x10,array,1);
	
	Pin_4_Write(0);
	CyDelay(10);
	SPIM_1_WriteTxData(0x20);
	SPIM_1_WriteTxData(0x37);
	Pin_4_Write(1);
	CyDelay(100);
	
	Pin_4_Write(0);
	CyDelay(10);
	SPIM_1_WriteTxData(0x21);
	SPIM_1_WriteTxData(0x00);
	Pin_4_Write(1);
	CyDelay(100);
	
	Pin_4_Write(0);
	CyDelay(10);
	SPIM_1_WriteTxData(0x22);
	SPIM_1_WriteTxData(0x00);
	Pin_4_Write(1);
	CyDelay(100);
	
	Pin_4_Write(0);
	CyDelay(10);
	SPIM_1_WriteTxData(0x23);
	SPIM_1_WriteTxData(0x30);
	Pin_4_Write(1);
	CyDelay(100);

}
void spi_read(uint8 reg, uint8 *buffer)
{
	uint8 array[6];
	reg = 0xC0 | reg;
	Pin_4_Write(0);
	CyDelay(10);
	SPIM_1_WriteTxData(reg);
	SPIM_1_WriteTxData(0x00);
	array[0] = SPIM_1_ReadRxData();
	SPIM_1_WriteTxData(0x00);
	array[1] = SPIM_1_ReadRxData();
	SPIM_1_WriteTxData(0x00);
	array[2] = SPIM_1_ReadRxData();
	SPIM_1_WriteTxData(0x00);
	array[3] = SPIM_1_ReadRxData();
	SPIM_1_WriteTxData(0x00);
	array[4] = SPIM_1_ReadRxData();
	SPIM_1_WriteTxData(0x00);
	array[5] = SPIM_1_ReadRxData();
	Pin_4_Write(1);
	buffer = array;
}
/* [] END OF FILE */

/*******************************************************************************
* File Name: sclk.c  
* Version 2.0
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "sclk.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        sclk_PC =   (sclk_PC & \
                                (uint32)(~(uint32)(sclk_DRIVE_MODE_IND_MASK << (sclk_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (sclk_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: sclk_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void sclk_Write(uint8 value) 
{
    uint8 drVal = (uint8)(sclk_DR & (uint8)(~sclk_MASK));
    drVal = (drVal | ((uint8)(value << sclk_SHIFT) & sclk_MASK));
    sclk_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: sclk_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  sclk_DM_STRONG     Strong Drive 
*  sclk_DM_OD_HI      Open Drain, Drives High 
*  sclk_DM_OD_LO      Open Drain, Drives Low 
*  sclk_DM_RES_UP     Resistive Pull Up 
*  sclk_DM_RES_DWN    Resistive Pull Down 
*  sclk_DM_RES_UPDWN  Resistive Pull Up/Down 
*  sclk_DM_DIG_HIZ    High Impedance Digital 
*  sclk_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void sclk_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(sclk__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: sclk_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro sclk_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 sclk_Read(void) 
{
    return (uint8)((sclk_PS & sclk_MASK) >> sclk_SHIFT);
}


/*******************************************************************************
* Function Name: sclk_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 sclk_ReadDataReg(void) 
{
    return (uint8)((sclk_DR & sclk_MASK) >> sclk_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(sclk_INTSTAT) 

    /*******************************************************************************
    * Function Name: sclk_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 sclk_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(sclk_INTSTAT & sclk_MASK);
		sclk_INTSTAT = maskedStatus;
        return maskedStatus >> sclk_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */

/*******************************************************************************
* File Name: mosi.h  
* Version 2.0
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_mosi_H) /* Pins mosi_H */
#define CY_PINS_mosi_H

#include "cytypes.h"
#include "cyfitter.h"
#include "mosi_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    mosi_Write(uint8 value) ;
void    mosi_SetDriveMode(uint8 mode) ;
uint8   mosi_ReadDataReg(void) ;
uint8   mosi_Read(void) ;
uint8   mosi_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define mosi_DRIVE_MODE_BITS        (3)
#define mosi_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - mosi_DRIVE_MODE_BITS))
#define mosi_DRIVE_MODE_SHIFT       (0x00u)
#define mosi_DRIVE_MODE_MASK        (0x07u << mosi_DRIVE_MODE_SHIFT)

#define mosi_DM_ALG_HIZ         (0x00u << mosi_DRIVE_MODE_SHIFT)
#define mosi_DM_DIG_HIZ         (0x01u << mosi_DRIVE_MODE_SHIFT)
#define mosi_DM_RES_UP          (0x02u << mosi_DRIVE_MODE_SHIFT)
#define mosi_DM_RES_DWN         (0x03u << mosi_DRIVE_MODE_SHIFT)
#define mosi_DM_OD_LO           (0x04u << mosi_DRIVE_MODE_SHIFT)
#define mosi_DM_OD_HI           (0x05u << mosi_DRIVE_MODE_SHIFT)
#define mosi_DM_STRONG          (0x06u << mosi_DRIVE_MODE_SHIFT)
#define mosi_DM_RES_UPDWN       (0x07u << mosi_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define mosi_MASK               mosi__MASK
#define mosi_SHIFT              mosi__SHIFT
#define mosi_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define mosi_PS                     (* (reg32 *) mosi__PS)
/* Port Configuration */
#define mosi_PC                     (* (reg32 *) mosi__PC)
/* Data Register */
#define mosi_DR                     (* (reg32 *) mosi__DR)
/* Input Buffer Disable Override */
#define mosi_INP_DIS                (* (reg32 *) mosi__PC2)


#if defined(mosi__INTSTAT)  /* Interrupt Registers */

    #define mosi_INTSTAT                (* (reg32 *) mosi__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins mosi_H */


/* [] END OF FILE */

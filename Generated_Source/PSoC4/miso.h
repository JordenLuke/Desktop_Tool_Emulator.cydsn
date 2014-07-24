/*******************************************************************************
* File Name: miso.h  
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

#if !defined(CY_PINS_miso_H) /* Pins miso_H */
#define CY_PINS_miso_H

#include "cytypes.h"
#include "cyfitter.h"
#include "miso_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    miso_Write(uint8 value) ;
void    miso_SetDriveMode(uint8 mode) ;
uint8   miso_ReadDataReg(void) ;
uint8   miso_Read(void) ;
uint8   miso_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define miso_DRIVE_MODE_BITS        (3)
#define miso_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - miso_DRIVE_MODE_BITS))
#define miso_DRIVE_MODE_SHIFT       (0x00u)
#define miso_DRIVE_MODE_MASK        (0x07u << miso_DRIVE_MODE_SHIFT)

#define miso_DM_ALG_HIZ         (0x00u << miso_DRIVE_MODE_SHIFT)
#define miso_DM_DIG_HIZ         (0x01u << miso_DRIVE_MODE_SHIFT)
#define miso_DM_RES_UP          (0x02u << miso_DRIVE_MODE_SHIFT)
#define miso_DM_RES_DWN         (0x03u << miso_DRIVE_MODE_SHIFT)
#define miso_DM_OD_LO           (0x04u << miso_DRIVE_MODE_SHIFT)
#define miso_DM_OD_HI           (0x05u << miso_DRIVE_MODE_SHIFT)
#define miso_DM_STRONG          (0x06u << miso_DRIVE_MODE_SHIFT)
#define miso_DM_RES_UPDWN       (0x07u << miso_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define miso_MASK               miso__MASK
#define miso_SHIFT              miso__SHIFT
#define miso_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define miso_PS                     (* (reg32 *) miso__PS)
/* Port Configuration */
#define miso_PC                     (* (reg32 *) miso__PC)
/* Data Register */
#define miso_DR                     (* (reg32 *) miso__DR)
/* Input Buffer Disable Override */
#define miso_INP_DIS                (* (reg32 *) miso__PC2)


#if defined(miso__INTSTAT)  /* Interrupt Registers */

    #define miso_INTSTAT                (* (reg32 *) miso__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins miso_H */


/* [] END OF FILE */

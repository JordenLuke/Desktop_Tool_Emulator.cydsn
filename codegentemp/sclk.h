/*******************************************************************************
* File Name: sclk.h  
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

#if !defined(CY_PINS_sclk_H) /* Pins sclk_H */
#define CY_PINS_sclk_H

#include "cytypes.h"
#include "cyfitter.h"
#include "sclk_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    sclk_Write(uint8 value) ;
void    sclk_SetDriveMode(uint8 mode) ;
uint8   sclk_ReadDataReg(void) ;
uint8   sclk_Read(void) ;
uint8   sclk_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define sclk_DRIVE_MODE_BITS        (3)
#define sclk_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - sclk_DRIVE_MODE_BITS))
#define sclk_DRIVE_MODE_SHIFT       (0x00u)
#define sclk_DRIVE_MODE_MASK        (0x07u << sclk_DRIVE_MODE_SHIFT)

#define sclk_DM_ALG_HIZ         (0x00u << sclk_DRIVE_MODE_SHIFT)
#define sclk_DM_DIG_HIZ         (0x01u << sclk_DRIVE_MODE_SHIFT)
#define sclk_DM_RES_UP          (0x02u << sclk_DRIVE_MODE_SHIFT)
#define sclk_DM_RES_DWN         (0x03u << sclk_DRIVE_MODE_SHIFT)
#define sclk_DM_OD_LO           (0x04u << sclk_DRIVE_MODE_SHIFT)
#define sclk_DM_OD_HI           (0x05u << sclk_DRIVE_MODE_SHIFT)
#define sclk_DM_STRONG          (0x06u << sclk_DRIVE_MODE_SHIFT)
#define sclk_DM_RES_UPDWN       (0x07u << sclk_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define sclk_MASK               sclk__MASK
#define sclk_SHIFT              sclk__SHIFT
#define sclk_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define sclk_PS                     (* (reg32 *) sclk__PS)
/* Port Configuration */
#define sclk_PC                     (* (reg32 *) sclk__PC)
/* Data Register */
#define sclk_DR                     (* (reg32 *) sclk__DR)
/* Input Buffer Disable Override */
#define sclk_INP_DIS                (* (reg32 *) sclk__PC2)


#if defined(sclk__INTSTAT)  /* Interrupt Registers */

    #define sclk_INTSTAT                (* (reg32 *) sclk__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins sclk_H */


/* [] END OF FILE */

/******************************************************************************
* Project Name		: PDM_Microphone
* File Name			: Main.c
* Version 			: 1.0
* Device Used		: CY8C4247LQI-BL483
* Software Used		: PSoC Creator 3.2
* Compiler    		: ARM GCC 4.8.4
* Related Hardware	: CY8CKIT-042-BLE Bluetooth Low Energy Pioneer Kit 
* Owner				: kris@cypress.com
*
********************************************************************************
* Copyright (2015), Cypress Semiconductor Corporation. All Rights Reserved.
********************************************************************************
* This software is owned by Cypress Semiconductor Corporation (Cypress)
* and is protected by and subject to worldwide patent protection (United
* States and foreign), United States copyright laws and international treaty
* provisions. Cypress hereby grants to licensee a personal, non-exclusive,
* non-transferable license to copy, use, modify, create derivative works of,
* and compile the Cypress Source Code and derivative works for the sole
* purpose of creating custom software in support of licensee product to be
* used only in conjunction with a Cypress integrated circuit as specified in
* the applicable agreement. Any reproduction, modification, translation,
* compilation, or representation of this software except as specified above 
* is prohibited without the express written permission of Cypress.
*
* Disclaimer: CYPRESS MAKES NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, WITH 
* REGARD TO THIS MATERIAL, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* Cypress reserves the right to make changes without further notice to the 
* materials described herein. Cypress does not assume any liability arising out 
* of the application or use of any product or circuit described herein. Cypress 
* does not authorize its products for use as critical components in life-support 
* systems where a malfunction or failure may reasonably be expected to result in 
* significant injury to the user. The inclusion of Cypress' product in a life-
* support systems application implies that the manufacturer assumes all risk of 
* such use and in doing so indemnifies Cypress against all charges. 
*
* Use of this Software may be limited by and subject to the applicable Cypress
* software license agreement. 
*******************************************************************************/

/********************************************************************************
*	Description - Main entry point for PDM microphone interface PSoC 4 design
********************************************************************************/
#include <Configuration.h>
#include <I2S_OUT.h>
#include <PDM.h>
#include <project.h>

/*******************************************************************************
* Function Name: Main
********************************************************************************
*
* Summary:
*  Initialises system and runs the firmware main thread
*
* Parameters:
*  None.
*
* Return:
*  int - We never return.
*
*******************************************************************************/
int main()
{
    CyGlobalIntEnable; 
    
#if ENABLE_I2S_OUTPUT
    I2S_Initialise();
#endif

#if ENABLE_16K_SAMPLING
    PDM_Clock_SetDivider(PMD_16K_DIVIDE);
    I2S_Clock_SetDivider(I2S_16K_DIVIDE);
    I2S_MCLK_SetDivider(I2S_MCLK_16K_DIVIDE);
#endif    
    
    PDM_Start();	

    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */

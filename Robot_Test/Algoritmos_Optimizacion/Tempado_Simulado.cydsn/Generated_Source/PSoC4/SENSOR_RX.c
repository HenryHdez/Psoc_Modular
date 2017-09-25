/*******************************************************************************
* File Name: SENSOR_RX.c
* Version 2.50
*
* Description:
*  This file provides all API functionality of the UART component
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "SENSOR_RX.h"
#if (SENSOR_RX_INTERNAL_CLOCK_USED)
    #include "SENSOR_RX_IntClock.h"
#endif /* End SENSOR_RX_INTERNAL_CLOCK_USED */


/***************************************
* Global data allocation
***************************************/

uint8 SENSOR_RX_initVar = 0u;

#if (SENSOR_RX_TX_INTERRUPT_ENABLED && SENSOR_RX_TX_ENABLED)
    volatile uint8 SENSOR_RX_txBuffer[SENSOR_RX_TX_BUFFER_SIZE];
    volatile uint8 SENSOR_RX_txBufferRead = 0u;
    uint8 SENSOR_RX_txBufferWrite = 0u;
#endif /* (SENSOR_RX_TX_INTERRUPT_ENABLED && SENSOR_RX_TX_ENABLED) */

#if (SENSOR_RX_RX_INTERRUPT_ENABLED && (SENSOR_RX_RX_ENABLED || SENSOR_RX_HD_ENABLED))
    uint8 SENSOR_RX_errorStatus = 0u;
    volatile uint8 SENSOR_RX_rxBuffer[SENSOR_RX_RX_BUFFER_SIZE];
    volatile uint8 SENSOR_RX_rxBufferRead  = 0u;
    volatile uint8 SENSOR_RX_rxBufferWrite = 0u;
    volatile uint8 SENSOR_RX_rxBufferLoopDetect = 0u;
    volatile uint8 SENSOR_RX_rxBufferOverflow   = 0u;
    #if (SENSOR_RX_RXHW_ADDRESS_ENABLED)
        volatile uint8 SENSOR_RX_rxAddressMode = SENSOR_RX_RX_ADDRESS_MODE;
        volatile uint8 SENSOR_RX_rxAddressDetected = 0u;
    #endif /* (SENSOR_RX_RXHW_ADDRESS_ENABLED) */
#endif /* (SENSOR_RX_RX_INTERRUPT_ENABLED && (SENSOR_RX_RX_ENABLED || SENSOR_RX_HD_ENABLED)) */


/*******************************************************************************
* Function Name: SENSOR_RX_Start
********************************************************************************
*
* Summary:
*  This is the preferred method to begin component operation.
*  SENSOR_RX_Start() sets the initVar variable, calls the
*  SENSOR_RX_Init() function, and then calls the
*  SENSOR_RX_Enable() function.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  The SENSOR_RX_intiVar variable is used to indicate initial
*  configuration of this component. The variable is initialized to zero (0u)
*  and set to one (1u) the first time SENSOR_RX_Start() is called. This
*  allows for component initialization without re-initialization in all
*  subsequent calls to the SENSOR_RX_Start() routine.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SENSOR_RX_Start(void) 
{
    /* If not initialized then initialize all required hardware and software */
    if(SENSOR_RX_initVar == 0u)
    {
        SENSOR_RX_Init();
        SENSOR_RX_initVar = 1u;
    }

    SENSOR_RX_Enable();
}


/*******************************************************************************
* Function Name: SENSOR_RX_Init
********************************************************************************
*
* Summary:
*  Initializes or restores the component according to the customizer Configure
*  dialog settings. It is not necessary to call SENSOR_RX_Init() because
*  the SENSOR_RX_Start() API calls this function and is the preferred
*  method to begin component operation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void SENSOR_RX_Init(void) 
{
    #if(SENSOR_RX_RX_ENABLED || SENSOR_RX_HD_ENABLED)

        #if (SENSOR_RX_RX_INTERRUPT_ENABLED)
            /* Set RX interrupt vector and priority */
            (void) CyIntSetVector(SENSOR_RX_RX_VECT_NUM, &SENSOR_RX_RXISR);
            CyIntSetPriority(SENSOR_RX_RX_VECT_NUM, SENSOR_RX_RX_PRIOR_NUM);
            SENSOR_RX_errorStatus = 0u;
        #endif /* (SENSOR_RX_RX_INTERRUPT_ENABLED) */

        #if (SENSOR_RX_RXHW_ADDRESS_ENABLED)
            SENSOR_RX_SetRxAddressMode(SENSOR_RX_RX_ADDRESS_MODE);
            SENSOR_RX_SetRxAddress1(SENSOR_RX_RX_HW_ADDRESS1);
            SENSOR_RX_SetRxAddress2(SENSOR_RX_RX_HW_ADDRESS2);
        #endif /* End SENSOR_RX_RXHW_ADDRESS_ENABLED */

        /* Init Count7 period */
        SENSOR_RX_RXBITCTR_PERIOD_REG = SENSOR_RX_RXBITCTR_INIT;
        /* Configure the Initial RX interrupt mask */
        SENSOR_RX_RXSTATUS_MASK_REG  = SENSOR_RX_INIT_RX_INTERRUPTS_MASK;
    #endif /* End SENSOR_RX_RX_ENABLED || SENSOR_RX_HD_ENABLED*/

    #if(SENSOR_RX_TX_ENABLED)
        #if (SENSOR_RX_TX_INTERRUPT_ENABLED)
            /* Set TX interrupt vector and priority */
            (void) CyIntSetVector(SENSOR_RX_TX_VECT_NUM, &SENSOR_RX_TXISR);
            CyIntSetPriority(SENSOR_RX_TX_VECT_NUM, SENSOR_RX_TX_PRIOR_NUM);
        #endif /* (SENSOR_RX_TX_INTERRUPT_ENABLED) */

        /* Write Counter Value for TX Bit Clk Generator*/
        #if (SENSOR_RX_TXCLKGEN_DP)
            SENSOR_RX_TXBITCLKGEN_CTR_REG = SENSOR_RX_BIT_CENTER;
            SENSOR_RX_TXBITCLKTX_COMPLETE_REG = ((SENSOR_RX_NUMBER_OF_DATA_BITS +
                        SENSOR_RX_NUMBER_OF_START_BIT) * SENSOR_RX_OVER_SAMPLE_COUNT) - 1u;
        #else
            SENSOR_RX_TXBITCTR_PERIOD_REG = ((SENSOR_RX_NUMBER_OF_DATA_BITS +
                        SENSOR_RX_NUMBER_OF_START_BIT) * SENSOR_RX_OVER_SAMPLE_8) - 1u;
        #endif /* End SENSOR_RX_TXCLKGEN_DP */

        /* Configure the Initial TX interrupt mask */
        #if (SENSOR_RX_TX_INTERRUPT_ENABLED)
            SENSOR_RX_TXSTATUS_MASK_REG = SENSOR_RX_TX_STS_FIFO_EMPTY;
        #else
            SENSOR_RX_TXSTATUS_MASK_REG = SENSOR_RX_INIT_TX_INTERRUPTS_MASK;
        #endif /*End SENSOR_RX_TX_INTERRUPT_ENABLED*/

    #endif /* End SENSOR_RX_TX_ENABLED */

    #if(SENSOR_RX_PARITY_TYPE_SW)  /* Write Parity to Control Register */
        SENSOR_RX_WriteControlRegister( \
            (SENSOR_RX_ReadControlRegister() & (uint8)~SENSOR_RX_CTRL_PARITY_TYPE_MASK) | \
            (uint8)(SENSOR_RX_PARITY_TYPE << SENSOR_RX_CTRL_PARITY_TYPE0_SHIFT) );
    #endif /* End SENSOR_RX_PARITY_TYPE_SW */
}


/*******************************************************************************
* Function Name: SENSOR_RX_Enable
********************************************************************************
*
* Summary:
*  Activates the hardware and begins component operation. It is not necessary
*  to call SENSOR_RX_Enable() because the SENSOR_RX_Start() API
*  calls this function, which is the preferred method to begin component
*  operation.

* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  SENSOR_RX_rxAddressDetected - set to initial state (0).
*
*******************************************************************************/
void SENSOR_RX_Enable(void) 
{
    uint8 enableInterrupts;
    enableInterrupts = CyEnterCriticalSection();

    #if (SENSOR_RX_RX_ENABLED || SENSOR_RX_HD_ENABLED)
        /* RX Counter (Count7) Enable */
        SENSOR_RX_RXBITCTR_CONTROL_REG |= SENSOR_RX_CNTR_ENABLE;

        /* Enable the RX Interrupt */
        SENSOR_RX_RXSTATUS_ACTL_REG  |= SENSOR_RX_INT_ENABLE;

        #if (SENSOR_RX_RX_INTERRUPT_ENABLED)
            SENSOR_RX_EnableRxInt();

            #if (SENSOR_RX_RXHW_ADDRESS_ENABLED)
                SENSOR_RX_rxAddressDetected = 0u;
            #endif /* (SENSOR_RX_RXHW_ADDRESS_ENABLED) */
        #endif /* (SENSOR_RX_RX_INTERRUPT_ENABLED) */
    #endif /* (SENSOR_RX_RX_ENABLED || SENSOR_RX_HD_ENABLED) */

    #if(SENSOR_RX_TX_ENABLED)
        /* TX Counter (DP/Count7) Enable */
        #if(!SENSOR_RX_TXCLKGEN_DP)
            SENSOR_RX_TXBITCTR_CONTROL_REG |= SENSOR_RX_CNTR_ENABLE;
        #endif /* End SENSOR_RX_TXCLKGEN_DP */

        /* Enable the TX Interrupt */
        SENSOR_RX_TXSTATUS_ACTL_REG |= SENSOR_RX_INT_ENABLE;
        #if (SENSOR_RX_TX_INTERRUPT_ENABLED)
            SENSOR_RX_ClearPendingTxInt(); /* Clear history of TX_NOT_EMPTY */
            SENSOR_RX_EnableTxInt();
        #endif /* (SENSOR_RX_TX_INTERRUPT_ENABLED) */
     #endif /* (SENSOR_RX_TX_INTERRUPT_ENABLED) */

    #if (SENSOR_RX_INTERNAL_CLOCK_USED)
        SENSOR_RX_IntClock_Start();  /* Enable the clock */
    #endif /* (SENSOR_RX_INTERNAL_CLOCK_USED) */

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: SENSOR_RX_Stop
********************************************************************************
*
* Summary:
*  Disables the UART operation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void SENSOR_RX_Stop(void) 
{
    uint8 enableInterrupts;
    enableInterrupts = CyEnterCriticalSection();

    /* Write Bit Counter Disable */
    #if (SENSOR_RX_RX_ENABLED || SENSOR_RX_HD_ENABLED)
        SENSOR_RX_RXBITCTR_CONTROL_REG &= (uint8) ~SENSOR_RX_CNTR_ENABLE;
    #endif /* (SENSOR_RX_RX_ENABLED || SENSOR_RX_HD_ENABLED) */

    #if (SENSOR_RX_TX_ENABLED)
        #if(!SENSOR_RX_TXCLKGEN_DP)
            SENSOR_RX_TXBITCTR_CONTROL_REG &= (uint8) ~SENSOR_RX_CNTR_ENABLE;
        #endif /* (!SENSOR_RX_TXCLKGEN_DP) */
    #endif /* (SENSOR_RX_TX_ENABLED) */

    #if (SENSOR_RX_INTERNAL_CLOCK_USED)
        SENSOR_RX_IntClock_Stop();   /* Disable the clock */
    #endif /* (SENSOR_RX_INTERNAL_CLOCK_USED) */

    /* Disable internal interrupt component */
    #if (SENSOR_RX_RX_ENABLED || SENSOR_RX_HD_ENABLED)
        SENSOR_RX_RXSTATUS_ACTL_REG  &= (uint8) ~SENSOR_RX_INT_ENABLE;

        #if (SENSOR_RX_RX_INTERRUPT_ENABLED)
            SENSOR_RX_DisableRxInt();
        #endif /* (SENSOR_RX_RX_INTERRUPT_ENABLED) */
    #endif /* (SENSOR_RX_RX_ENABLED || SENSOR_RX_HD_ENABLED) */

    #if (SENSOR_RX_TX_ENABLED)
        SENSOR_RX_TXSTATUS_ACTL_REG &= (uint8) ~SENSOR_RX_INT_ENABLE;

        #if (SENSOR_RX_TX_INTERRUPT_ENABLED)
            SENSOR_RX_DisableTxInt();
        #endif /* (SENSOR_RX_TX_INTERRUPT_ENABLED) */
    #endif /* (SENSOR_RX_TX_ENABLED) */

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: SENSOR_RX_ReadControlRegister
********************************************************************************
*
* Summary:
*  Returns the current value of the control register.
*
* Parameters:
*  None.
*
* Return:
*  Contents of the control register.
*
*******************************************************************************/
uint8 SENSOR_RX_ReadControlRegister(void) 
{
    #if (SENSOR_RX_CONTROL_REG_REMOVED)
        return(0u);
    #else
        return(SENSOR_RX_CONTROL_REG);
    #endif /* (SENSOR_RX_CONTROL_REG_REMOVED) */
}


/*******************************************************************************
* Function Name: SENSOR_RX_WriteControlRegister
********************************************************************************
*
* Summary:
*  Writes an 8-bit value into the control register
*
* Parameters:
*  control:  control register value
*
* Return:
*  None.
*
*******************************************************************************/
void  SENSOR_RX_WriteControlRegister(uint8 control) 
{
    #if (SENSOR_RX_CONTROL_REG_REMOVED)
        if(0u != control)
        {
            /* Suppress compiler warning */
        }
    #else
       SENSOR_RX_CONTROL_REG = control;
    #endif /* (SENSOR_RX_CONTROL_REG_REMOVED) */
}


#if(SENSOR_RX_RX_ENABLED || SENSOR_RX_HD_ENABLED)
    /*******************************************************************************
    * Function Name: SENSOR_RX_SetRxInterruptMode
    ********************************************************************************
    *
    * Summary:
    *  Configures the RX interrupt sources enabled.
    *
    * Parameters:
    *  IntSrc:  Bit field containing the RX interrupts to enable. Based on the 
    *  bit-field arrangement of the status register. This value must be a 
    *  combination of status register bit-masks shown below:
    *      SENSOR_RX_RX_STS_FIFO_NOTEMPTY    Interrupt on byte received.
    *      SENSOR_RX_RX_STS_PAR_ERROR        Interrupt on parity error.
    *      SENSOR_RX_RX_STS_STOP_ERROR       Interrupt on stop error.
    *      SENSOR_RX_RX_STS_BREAK            Interrupt on break.
    *      SENSOR_RX_RX_STS_OVERRUN          Interrupt on overrun error.
    *      SENSOR_RX_RX_STS_ADDR_MATCH       Interrupt on address match.
    *      SENSOR_RX_RX_STS_MRKSPC           Interrupt on address detect.
    *
    * Return:
    *  None.
    *
    * Theory:
    *  Enables the output of specific status bits to the interrupt controller
    *
    *******************************************************************************/
    void SENSOR_RX_SetRxInterruptMode(uint8 intSrc) 
    {
        SENSOR_RX_RXSTATUS_MASK_REG  = intSrc;
    }


    /*******************************************************************************
    * Function Name: SENSOR_RX_ReadRxData
    ********************************************************************************
    *
    * Summary:
    *  Returns the next byte of received data. This function returns data without
    *  checking the status. You must check the status separately.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  Received data from RX register
    *
    * Global Variables:
    *  SENSOR_RX_rxBuffer - RAM buffer pointer for save received data.
    *  SENSOR_RX_rxBufferWrite - cyclic index for write to rxBuffer,
    *     checked to identify new data.
    *  SENSOR_RX_rxBufferRead - cyclic index for read from rxBuffer,
    *     incremented after each byte has been read from buffer.
    *  SENSOR_RX_rxBufferLoopDetect - cleared if loop condition was detected
    *     in RX ISR.
    *
    * Reentrant:
    *  No.
    *
    *******************************************************************************/
    uint8 SENSOR_RX_ReadRxData(void) 
    {
        uint8 rxData;

    #if (SENSOR_RX_RX_INTERRUPT_ENABLED)

        uint8 locRxBufferRead;
        uint8 locRxBufferWrite;

        /* Protect variables that could change on interrupt */
        SENSOR_RX_DisableRxInt();

        locRxBufferRead  = SENSOR_RX_rxBufferRead;
        locRxBufferWrite = SENSOR_RX_rxBufferWrite;

        if( (SENSOR_RX_rxBufferLoopDetect != 0u) || (locRxBufferRead != locRxBufferWrite) )
        {
            rxData = SENSOR_RX_rxBuffer[locRxBufferRead];
            locRxBufferRead++;

            if(locRxBufferRead >= SENSOR_RX_RX_BUFFER_SIZE)
            {
                locRxBufferRead = 0u;
            }
            /* Update the real pointer */
            SENSOR_RX_rxBufferRead = locRxBufferRead;

            if(SENSOR_RX_rxBufferLoopDetect != 0u)
            {
                SENSOR_RX_rxBufferLoopDetect = 0u;
                #if ((SENSOR_RX_RX_INTERRUPT_ENABLED) && (SENSOR_RX_FLOW_CONTROL != 0u))
                    /* When Hardware Flow Control selected - return RX mask */
                    #if( SENSOR_RX_HD_ENABLED )
                        if((SENSOR_RX_CONTROL_REG & SENSOR_RX_CTRL_HD_SEND) == 0u)
                        {   /* In Half duplex mode return RX mask only in RX
                            *  configuration set, otherwise
                            *  mask will be returned in LoadRxConfig() API.
                            */
                            SENSOR_RX_RXSTATUS_MASK_REG  |= SENSOR_RX_RX_STS_FIFO_NOTEMPTY;
                        }
                    #else
                        SENSOR_RX_RXSTATUS_MASK_REG  |= SENSOR_RX_RX_STS_FIFO_NOTEMPTY;
                    #endif /* end SENSOR_RX_HD_ENABLED */
                #endif /* ((SENSOR_RX_RX_INTERRUPT_ENABLED) && (SENSOR_RX_FLOW_CONTROL != 0u)) */
            }
        }
        else
        {   /* Needs to check status for RX_STS_FIFO_NOTEMPTY bit */
            rxData = SENSOR_RX_RXDATA_REG;
        }

        SENSOR_RX_EnableRxInt();

    #else

        /* Needs to check status for RX_STS_FIFO_NOTEMPTY bit */
        rxData = SENSOR_RX_RXDATA_REG;

    #endif /* (SENSOR_RX_RX_INTERRUPT_ENABLED) */

        return(rxData);
    }


    /*******************************************************************************
    * Function Name: SENSOR_RX_ReadRxStatus
    ********************************************************************************
    *
    * Summary:
    *  Returns the current state of the receiver status register and the software
    *  buffer overflow status.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  Current state of the status register.
    *
    * Side Effect:
    *  All status register bits are clear-on-read except
    *  SENSOR_RX_RX_STS_FIFO_NOTEMPTY.
    *  SENSOR_RX_RX_STS_FIFO_NOTEMPTY clears immediately after RX data
    *  register read.
    *
    * Global Variables:
    *  SENSOR_RX_rxBufferOverflow - used to indicate overload condition.
    *   It set to one in RX interrupt when there isn't free space in
    *   SENSOR_RX_rxBufferRead to write new data. This condition returned
    *   and cleared to zero by this API as an
    *   SENSOR_RX_RX_STS_SOFT_BUFF_OVER bit along with RX Status register
    *   bits.
    *
    *******************************************************************************/
    uint8 SENSOR_RX_ReadRxStatus(void) 
    {
        uint8 status;

        status = SENSOR_RX_RXSTATUS_REG & SENSOR_RX_RX_HW_MASK;

    #if (SENSOR_RX_RX_INTERRUPT_ENABLED)
        if(SENSOR_RX_rxBufferOverflow != 0u)
        {
            status |= SENSOR_RX_RX_STS_SOFT_BUFF_OVER;
            SENSOR_RX_rxBufferOverflow = 0u;
        }
    #endif /* (SENSOR_RX_RX_INTERRUPT_ENABLED) */

        return(status);
    }


    /*******************************************************************************
    * Function Name: SENSOR_RX_GetChar
    ********************************************************************************
    *
    * Summary:
    *  Returns the last received byte of data. SENSOR_RX_GetChar() is
    *  designed for ASCII characters and returns a uint8 where 1 to 255 are values
    *  for valid characters and 0 indicates an error occurred or no data is present.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  Character read from UART RX buffer. ASCII characters from 1 to 255 are valid.
    *  A returned zero signifies an error condition or no data available.
    *
    * Global Variables:
    *  SENSOR_RX_rxBuffer - RAM buffer pointer for save received data.
    *  SENSOR_RX_rxBufferWrite - cyclic index for write to rxBuffer,
    *     checked to identify new data.
    *  SENSOR_RX_rxBufferRead - cyclic index for read from rxBuffer,
    *     incremented after each byte has been read from buffer.
    *  SENSOR_RX_rxBufferLoopDetect - cleared if loop condition was detected
    *     in RX ISR.
    *
    * Reentrant:
    *  No.
    *
    *******************************************************************************/
    uint8 SENSOR_RX_GetChar(void) 
    {
        uint8 rxData = 0u;
        uint8 rxStatus;

    #if (SENSOR_RX_RX_INTERRUPT_ENABLED)
        uint8 locRxBufferRead;
        uint8 locRxBufferWrite;

        /* Protect variables that could change on interrupt */
        SENSOR_RX_DisableRxInt();

        locRxBufferRead  = SENSOR_RX_rxBufferRead;
        locRxBufferWrite = SENSOR_RX_rxBufferWrite;

        if( (SENSOR_RX_rxBufferLoopDetect != 0u) || (locRxBufferRead != locRxBufferWrite) )
        {
            rxData = SENSOR_RX_rxBuffer[locRxBufferRead];
            locRxBufferRead++;
            if(locRxBufferRead >= SENSOR_RX_RX_BUFFER_SIZE)
            {
                locRxBufferRead = 0u;
            }
            /* Update the real pointer */
            SENSOR_RX_rxBufferRead = locRxBufferRead;

            if(SENSOR_RX_rxBufferLoopDetect != 0u)
            {
                SENSOR_RX_rxBufferLoopDetect = 0u;
                #if( (SENSOR_RX_RX_INTERRUPT_ENABLED) && (SENSOR_RX_FLOW_CONTROL != 0u) )
                    /* When Hardware Flow Control selected - return RX mask */
                    #if( SENSOR_RX_HD_ENABLED )
                        if((SENSOR_RX_CONTROL_REG & SENSOR_RX_CTRL_HD_SEND) == 0u)
                        {   /* In Half duplex mode return RX mask only if
                            *  RX configuration set, otherwise
                            *  mask will be returned in LoadRxConfig() API.
                            */
                            SENSOR_RX_RXSTATUS_MASK_REG |= SENSOR_RX_RX_STS_FIFO_NOTEMPTY;
                        }
                    #else
                        SENSOR_RX_RXSTATUS_MASK_REG |= SENSOR_RX_RX_STS_FIFO_NOTEMPTY;
                    #endif /* end SENSOR_RX_HD_ENABLED */
                #endif /* SENSOR_RX_RX_INTERRUPT_ENABLED and Hardware flow control*/
            }

        }
        else
        {   rxStatus = SENSOR_RX_RXSTATUS_REG;
            if((rxStatus & SENSOR_RX_RX_STS_FIFO_NOTEMPTY) != 0u)
            {   /* Read received data from FIFO */
                rxData = SENSOR_RX_RXDATA_REG;
                /*Check status on error*/
                if((rxStatus & (SENSOR_RX_RX_STS_BREAK | SENSOR_RX_RX_STS_PAR_ERROR |
                                SENSOR_RX_RX_STS_STOP_ERROR | SENSOR_RX_RX_STS_OVERRUN)) != 0u)
                {
                    rxData = 0u;
                }
            }
        }

        SENSOR_RX_EnableRxInt();

    #else

        rxStatus =SENSOR_RX_RXSTATUS_REG;
        if((rxStatus & SENSOR_RX_RX_STS_FIFO_NOTEMPTY) != 0u)
        {
            /* Read received data from FIFO */
            rxData = SENSOR_RX_RXDATA_REG;

            /*Check status on error*/
            if((rxStatus & (SENSOR_RX_RX_STS_BREAK | SENSOR_RX_RX_STS_PAR_ERROR |
                            SENSOR_RX_RX_STS_STOP_ERROR | SENSOR_RX_RX_STS_OVERRUN)) != 0u)
            {
                rxData = 0u;
            }
        }
    #endif /* (SENSOR_RX_RX_INTERRUPT_ENABLED) */

        return(rxData);
    }


    /*******************************************************************************
    * Function Name: SENSOR_RX_GetByte
    ********************************************************************************
    *
    * Summary:
    *  Reads UART RX buffer immediately, returns received character and error
    *  condition.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  MSB contains status and LSB contains UART RX data. If the MSB is nonzero,
    *  an error has occurred.
    *
    * Reentrant:
    *  No.
    *
    *******************************************************************************/
    uint16 SENSOR_RX_GetByte(void) 
    {
        
    #if (SENSOR_RX_RX_INTERRUPT_ENABLED)
        uint16 locErrorStatus;
        /* Protect variables that could change on interrupt */
        SENSOR_RX_DisableRxInt();
        locErrorStatus = (uint16)SENSOR_RX_errorStatus;
        SENSOR_RX_errorStatus = 0u;
        SENSOR_RX_EnableRxInt();
        return ( (uint16)(locErrorStatus << 8u) | SENSOR_RX_ReadRxData() );
    #else
        return ( ((uint16)SENSOR_RX_ReadRxStatus() << 8u) | SENSOR_RX_ReadRxData() );
    #endif /* SENSOR_RX_RX_INTERRUPT_ENABLED */
        
    }


    /*******************************************************************************
    * Function Name: SENSOR_RX_GetRxBufferSize
    ********************************************************************************
    *
    * Summary:
    *  Returns the number of received bytes available in the RX buffer.
    *  * RX software buffer is disabled (RX Buffer Size parameter is equal to 4): 
    *    returns 0 for empty RX FIFO or 1 for not empty RX FIFO.
    *  * RX software buffer is enabled: returns the number of bytes available in 
    *    the RX software buffer. Bytes available in the RX FIFO do not take to 
    *    account.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  uint8: Number of bytes in the RX buffer. 
    *    Return value type depends on RX Buffer Size parameter.
    *
    * Global Variables:
    *  SENSOR_RX_rxBufferWrite - used to calculate left bytes.
    *  SENSOR_RX_rxBufferRead - used to calculate left bytes.
    *  SENSOR_RX_rxBufferLoopDetect - checked to decide left bytes amount.
    *
    * Reentrant:
    *  No.
    *
    * Theory:
    *  Allows the user to find out how full the RX Buffer is.
    *
    *******************************************************************************/
    uint8 SENSOR_RX_GetRxBufferSize(void)
                                                            
    {
        uint8 size;

    #if (SENSOR_RX_RX_INTERRUPT_ENABLED)

        /* Protect variables that could change on interrupt */
        SENSOR_RX_DisableRxInt();

        if(SENSOR_RX_rxBufferRead == SENSOR_RX_rxBufferWrite)
        {
            if(SENSOR_RX_rxBufferLoopDetect != 0u)
            {
                size = SENSOR_RX_RX_BUFFER_SIZE;
            }
            else
            {
                size = 0u;
            }
        }
        else if(SENSOR_RX_rxBufferRead < SENSOR_RX_rxBufferWrite)
        {
            size = (SENSOR_RX_rxBufferWrite - SENSOR_RX_rxBufferRead);
        }
        else
        {
            size = (SENSOR_RX_RX_BUFFER_SIZE - SENSOR_RX_rxBufferRead) + SENSOR_RX_rxBufferWrite;
        }

        SENSOR_RX_EnableRxInt();

    #else

        /* We can only know if there is data in the fifo. */
        size = ((SENSOR_RX_RXSTATUS_REG & SENSOR_RX_RX_STS_FIFO_NOTEMPTY) != 0u) ? 1u : 0u;

    #endif /* (SENSOR_RX_RX_INTERRUPT_ENABLED) */

        return(size);
    }


    /*******************************************************************************
    * Function Name: SENSOR_RX_ClearRxBuffer
    ********************************************************************************
    *
    * Summary:
    *  Clears the receiver memory buffer and hardware RX FIFO of all received data.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    * Global Variables:
    *  SENSOR_RX_rxBufferWrite - cleared to zero.
    *  SENSOR_RX_rxBufferRead - cleared to zero.
    *  SENSOR_RX_rxBufferLoopDetect - cleared to zero.
    *  SENSOR_RX_rxBufferOverflow - cleared to zero.
    *
    * Reentrant:
    *  No.
    *
    * Theory:
    *  Setting the pointers to zero makes the system believe there is no data to
    *  read and writing will resume at address 0 overwriting any data that may
    *  have remained in the RAM.
    *
    * Side Effects:
    *  Any received data not read from the RAM or FIFO buffer will be lost.
    *
    *******************************************************************************/
    void SENSOR_RX_ClearRxBuffer(void) 
    {
        uint8 enableInterrupts;

        /* Clear the HW FIFO */
        enableInterrupts = CyEnterCriticalSection();
        SENSOR_RX_RXDATA_AUX_CTL_REG |= (uint8)  SENSOR_RX_RX_FIFO_CLR;
        SENSOR_RX_RXDATA_AUX_CTL_REG &= (uint8) ~SENSOR_RX_RX_FIFO_CLR;
        CyExitCriticalSection(enableInterrupts);

    #if (SENSOR_RX_RX_INTERRUPT_ENABLED)

        /* Protect variables that could change on interrupt. */
        SENSOR_RX_DisableRxInt();

        SENSOR_RX_rxBufferRead = 0u;
        SENSOR_RX_rxBufferWrite = 0u;
        SENSOR_RX_rxBufferLoopDetect = 0u;
        SENSOR_RX_rxBufferOverflow = 0u;

        SENSOR_RX_EnableRxInt();

    #endif /* (SENSOR_RX_RX_INTERRUPT_ENABLED) */

    }


    /*******************************************************************************
    * Function Name: SENSOR_RX_SetRxAddressMode
    ********************************************************************************
    *
    * Summary:
    *  Sets the software controlled Addressing mode used by the RX portion of the
    *  UART.
    *
    * Parameters:
    *  addressMode: Enumerated value indicating the mode of RX addressing
    *  SENSOR_RX__B_UART__AM_SW_BYTE_BYTE -  Software Byte-by-Byte address
    *                                               detection
    *  SENSOR_RX__B_UART__AM_SW_DETECT_TO_BUFFER - Software Detect to Buffer
    *                                               address detection
    *  SENSOR_RX__B_UART__AM_HW_BYTE_BY_BYTE - Hardware Byte-by-Byte address
    *                                               detection
    *  SENSOR_RX__B_UART__AM_HW_DETECT_TO_BUFFER - Hardware Detect to Buffer
    *                                               address detection
    *  SENSOR_RX__B_UART__AM_NONE - No address detection
    *
    * Return:
    *  None.
    *
    * Global Variables:
    *  SENSOR_RX_rxAddressMode - the parameter stored in this variable for
    *   the farther usage in RX ISR.
    *  SENSOR_RX_rxAddressDetected - set to initial state (0).
    *
    *******************************************************************************/
    void SENSOR_RX_SetRxAddressMode(uint8 addressMode)
                                                        
    {
        #if(SENSOR_RX_RXHW_ADDRESS_ENABLED)
            #if(SENSOR_RX_CONTROL_REG_REMOVED)
                if(0u != addressMode)
                {
                    /* Suppress compiler warning */
                }
            #else /* SENSOR_RX_CONTROL_REG_REMOVED */
                uint8 tmpCtrl;
                tmpCtrl = SENSOR_RX_CONTROL_REG & (uint8)~SENSOR_RX_CTRL_RXADDR_MODE_MASK;
                tmpCtrl |= (uint8)(addressMode << SENSOR_RX_CTRL_RXADDR_MODE0_SHIFT);
                SENSOR_RX_CONTROL_REG = tmpCtrl;

                #if(SENSOR_RX_RX_INTERRUPT_ENABLED && \
                   (SENSOR_RX_RXBUFFERSIZE > SENSOR_RX_FIFO_LENGTH) )
                    SENSOR_RX_rxAddressMode = addressMode;
                    SENSOR_RX_rxAddressDetected = 0u;
                #endif /* End SENSOR_RX_RXBUFFERSIZE > SENSOR_RX_FIFO_LENGTH*/
            #endif /* End SENSOR_RX_CONTROL_REG_REMOVED */
        #else /* SENSOR_RX_RXHW_ADDRESS_ENABLED */
            if(0u != addressMode)
            {
                /* Suppress compiler warning */
            }
        #endif /* End SENSOR_RX_RXHW_ADDRESS_ENABLED */
    }


    /*******************************************************************************
    * Function Name: SENSOR_RX_SetRxAddress1
    ********************************************************************************
    *
    * Summary:
    *  Sets the first of two hardware-detectable receiver addresses.
    *
    * Parameters:
    *  address: Address #1 for hardware address detection.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void SENSOR_RX_SetRxAddress1(uint8 address) 
    {
        SENSOR_RX_RXADDRESS1_REG = address;
    }


    /*******************************************************************************
    * Function Name: SENSOR_RX_SetRxAddress2
    ********************************************************************************
    *
    * Summary:
    *  Sets the second of two hardware-detectable receiver addresses.
    *
    * Parameters:
    *  address: Address #2 for hardware address detection.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void SENSOR_RX_SetRxAddress2(uint8 address) 
    {
        SENSOR_RX_RXADDRESS2_REG = address;
    }

#endif  /* SENSOR_RX_RX_ENABLED || SENSOR_RX_HD_ENABLED*/


#if( (SENSOR_RX_TX_ENABLED) || (SENSOR_RX_HD_ENABLED) )
    /*******************************************************************************
    * Function Name: SENSOR_RX_SetTxInterruptMode
    ********************************************************************************
    *
    * Summary:
    *  Configures the TX interrupt sources to be enabled, but does not enable the
    *  interrupt.
    *
    * Parameters:
    *  intSrc: Bit field containing the TX interrupt sources to enable
    *   SENSOR_RX_TX_STS_COMPLETE        Interrupt on TX byte complete
    *   SENSOR_RX_TX_STS_FIFO_EMPTY      Interrupt when TX FIFO is empty
    *   SENSOR_RX_TX_STS_FIFO_FULL       Interrupt when TX FIFO is full
    *   SENSOR_RX_TX_STS_FIFO_NOT_FULL   Interrupt when TX FIFO is not full
    *
    * Return:
    *  None.
    *
    * Theory:
    *  Enables the output of specific status bits to the interrupt controller
    *
    *******************************************************************************/
    void SENSOR_RX_SetTxInterruptMode(uint8 intSrc) 
    {
        SENSOR_RX_TXSTATUS_MASK_REG = intSrc;
    }


    /*******************************************************************************
    * Function Name: SENSOR_RX_WriteTxData
    ********************************************************************************
    *
    * Summary:
    *  Places a byte of data into the transmit buffer to be sent when the bus is
    *  available without checking the TX status register. You must check status
    *  separately.
    *
    * Parameters:
    *  txDataByte: data byte
    *
    * Return:
    * None.
    *
    * Global Variables:
    *  SENSOR_RX_txBuffer - RAM buffer pointer for save data for transmission
    *  SENSOR_RX_txBufferWrite - cyclic index for write to txBuffer,
    *    incremented after each byte saved to buffer.
    *  SENSOR_RX_txBufferRead - cyclic index for read from txBuffer,
    *    checked to identify the condition to write to FIFO directly or to TX buffer
    *  SENSOR_RX_initVar - checked to identify that the component has been
    *    initialized.
    *
    * Reentrant:
    *  No.
    *
    *******************************************************************************/
    void SENSOR_RX_WriteTxData(uint8 txDataByte) 
    {
        /* If not Initialized then skip this function*/
        if(SENSOR_RX_initVar != 0u)
        {
        #if (SENSOR_RX_TX_INTERRUPT_ENABLED)

            /* Protect variables that could change on interrupt. */
            SENSOR_RX_DisableTxInt();

            if( (SENSOR_RX_txBufferRead == SENSOR_RX_txBufferWrite) &&
                ((SENSOR_RX_TXSTATUS_REG & SENSOR_RX_TX_STS_FIFO_FULL) == 0u) )
            {
                /* Add directly to the FIFO. */
                SENSOR_RX_TXDATA_REG = txDataByte;
            }
            else
            {
                if(SENSOR_RX_txBufferWrite >= SENSOR_RX_TX_BUFFER_SIZE)
                {
                    SENSOR_RX_txBufferWrite = 0u;
                }

                SENSOR_RX_txBuffer[SENSOR_RX_txBufferWrite] = txDataByte;

                /* Add to the software buffer. */
                SENSOR_RX_txBufferWrite++;
            }

            SENSOR_RX_EnableTxInt();

        #else

            /* Add directly to the FIFO. */
            SENSOR_RX_TXDATA_REG = txDataByte;

        #endif /*(SENSOR_RX_TX_INTERRUPT_ENABLED) */
        }
    }


    /*******************************************************************************
    * Function Name: SENSOR_RX_ReadTxStatus
    ********************************************************************************
    *
    * Summary:
    *  Reads the status register for the TX portion of the UART.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  Contents of the status register
    *
    * Theory:
    *  This function reads the TX status register, which is cleared on read.
    *  It is up to the user to handle all bits in this return value accordingly,
    *  even if the bit was not enabled as an interrupt source the event happened
    *  and must be handled accordingly.
    *
    *******************************************************************************/
    uint8 SENSOR_RX_ReadTxStatus(void) 
    {
        return(SENSOR_RX_TXSTATUS_REG);
    }


    /*******************************************************************************
    * Function Name: SENSOR_RX_PutChar
    ********************************************************************************
    *
    * Summary:
    *  Puts a byte of data into the transmit buffer to be sent when the bus is
    *  available. This is a blocking API that waits until the TX buffer has room to
    *  hold the data.
    *
    * Parameters:
    *  txDataByte: Byte containing the data to transmit
    *
    * Return:
    *  None.
    *
    * Global Variables:
    *  SENSOR_RX_txBuffer - RAM buffer pointer for save data for transmission
    *  SENSOR_RX_txBufferWrite - cyclic index for write to txBuffer,
    *     checked to identify free space in txBuffer and incremented after each byte
    *     saved to buffer.
    *  SENSOR_RX_txBufferRead - cyclic index for read from txBuffer,
    *     checked to identify free space in txBuffer.
    *  SENSOR_RX_initVar - checked to identify that the component has been
    *     initialized.
    *
    * Reentrant:
    *  No.
    *
    * Theory:
    *  Allows the user to transmit any byte of data in a single transfer
    *
    *******************************************************************************/
    void SENSOR_RX_PutChar(uint8 txDataByte) 
    {
    #if (SENSOR_RX_TX_INTERRUPT_ENABLED)
        /* The temporary output pointer is used since it takes two instructions
        *  to increment with a wrap, and we can't risk doing that with the real
        *  pointer and getting an interrupt in between instructions.
        */
        uint8 locTxBufferWrite;
        uint8 locTxBufferRead;

        do
        { /* Block if software buffer is full, so we don't overwrite. */

        #if ((SENSOR_RX_TX_BUFFER_SIZE > SENSOR_RX_MAX_BYTE_VALUE) && (CY_PSOC3))
            /* Disable TX interrupt to protect variables from modification */
            SENSOR_RX_DisableTxInt();
        #endif /* (SENSOR_RX_TX_BUFFER_SIZE > SENSOR_RX_MAX_BYTE_VALUE) && (CY_PSOC3) */

            locTxBufferWrite = SENSOR_RX_txBufferWrite;
            locTxBufferRead  = SENSOR_RX_txBufferRead;

        #if ((SENSOR_RX_TX_BUFFER_SIZE > SENSOR_RX_MAX_BYTE_VALUE) && (CY_PSOC3))
            /* Enable interrupt to continue transmission */
            SENSOR_RX_EnableTxInt();
        #endif /* (SENSOR_RX_TX_BUFFER_SIZE > SENSOR_RX_MAX_BYTE_VALUE) && (CY_PSOC3) */
        }
        while( (locTxBufferWrite < locTxBufferRead) ? (locTxBufferWrite == (locTxBufferRead - 1u)) :
                                ((locTxBufferWrite - locTxBufferRead) ==
                                (uint8)(SENSOR_RX_TX_BUFFER_SIZE - 1u)) );

        if( (locTxBufferRead == locTxBufferWrite) &&
            ((SENSOR_RX_TXSTATUS_REG & SENSOR_RX_TX_STS_FIFO_FULL) == 0u) )
        {
            /* Add directly to the FIFO */
            SENSOR_RX_TXDATA_REG = txDataByte;
        }
        else
        {
            if(locTxBufferWrite >= SENSOR_RX_TX_BUFFER_SIZE)
            {
                locTxBufferWrite = 0u;
            }
            /* Add to the software buffer. */
            SENSOR_RX_txBuffer[locTxBufferWrite] = txDataByte;
            locTxBufferWrite++;

            /* Finally, update the real output pointer */
        #if ((SENSOR_RX_TX_BUFFER_SIZE > SENSOR_RX_MAX_BYTE_VALUE) && (CY_PSOC3))
            SENSOR_RX_DisableTxInt();
        #endif /* (SENSOR_RX_TX_BUFFER_SIZE > SENSOR_RX_MAX_BYTE_VALUE) && (CY_PSOC3) */

            SENSOR_RX_txBufferWrite = locTxBufferWrite;

        #if ((SENSOR_RX_TX_BUFFER_SIZE > SENSOR_RX_MAX_BYTE_VALUE) && (CY_PSOC3))
            SENSOR_RX_EnableTxInt();
        #endif /* (SENSOR_RX_TX_BUFFER_SIZE > SENSOR_RX_MAX_BYTE_VALUE) && (CY_PSOC3) */

            if(0u != (SENSOR_RX_TXSTATUS_REG & SENSOR_RX_TX_STS_FIFO_EMPTY))
            {
                /* Trigger TX interrupt to send software buffer */
                SENSOR_RX_SetPendingTxInt();
            }
        }

    #else

        while((SENSOR_RX_TXSTATUS_REG & SENSOR_RX_TX_STS_FIFO_FULL) != 0u)
        {
            /* Wait for room in the FIFO */
        }

        /* Add directly to the FIFO */
        SENSOR_RX_TXDATA_REG = txDataByte;

    #endif /* SENSOR_RX_TX_INTERRUPT_ENABLED */
    }


    /*******************************************************************************
    * Function Name: SENSOR_RX_PutString
    ********************************************************************************
    *
    * Summary:
    *  Sends a NULL terminated string to the TX buffer for transmission.
    *
    * Parameters:
    *  string[]: Pointer to the null terminated string array residing in RAM or ROM
    *
    * Return:
    *  None.
    *
    * Global Variables:
    *  SENSOR_RX_initVar - checked to identify that the component has been
    *     initialized.
    *
    * Reentrant:
    *  No.
    *
    * Theory:
    *  If there is not enough memory in the TX buffer for the entire string, this
    *  function blocks until the last character of the string is loaded into the
    *  TX buffer.
    *
    *******************************************************************************/
    void SENSOR_RX_PutString(const char8 string[]) 
    {
        uint16 bufIndex = 0u;

        /* If not Initialized then skip this function */
        if(SENSOR_RX_initVar != 0u)
        {
            /* This is a blocking function, it will not exit until all data is sent */
            while(string[bufIndex] != (char8) 0)
            {
                SENSOR_RX_PutChar((uint8)string[bufIndex]);
                bufIndex++;
            }
        }
    }


    /*******************************************************************************
    * Function Name: SENSOR_RX_PutArray
    ********************************************************************************
    *
    * Summary:
    *  Places N bytes of data from a memory array into the TX buffer for
    *  transmission.
    *
    * Parameters:
    *  string[]: Address of the memory array residing in RAM or ROM.
    *  byteCount: Number of bytes to be transmitted. The type depends on TX Buffer
    *             Size parameter.
    *
    * Return:
    *  None.
    *
    * Global Variables:
    *  SENSOR_RX_initVar - checked to identify that the component has been
    *     initialized.
    *
    * Reentrant:
    *  No.
    *
    * Theory:
    *  If there is not enough memory in the TX buffer for the entire string, this
    *  function blocks until the last character of the string is loaded into the
    *  TX buffer.
    *
    *******************************************************************************/
    void SENSOR_RX_PutArray(const uint8 string[], uint8 byteCount)
                                                                    
    {
        uint8 bufIndex = 0u;

        /* If not Initialized then skip this function */
        if(SENSOR_RX_initVar != 0u)
        {
            while(bufIndex < byteCount)
            {
                SENSOR_RX_PutChar(string[bufIndex]);
                bufIndex++;
            }
        }
    }


    /*******************************************************************************
    * Function Name: SENSOR_RX_PutCRLF
    ********************************************************************************
    *
    * Summary:
    *  Writes a byte of data followed by a carriage return (0x0D) and line feed
    *  (0x0A) to the transmit buffer.
    *
    * Parameters:
    *  txDataByte: Data byte to transmit before the carriage return and line feed.
    *
    * Return:
    *  None.
    *
    * Global Variables:
    *  SENSOR_RX_initVar - checked to identify that the component has been
    *     initialized.
    *
    * Reentrant:
    *  No.
    *
    *******************************************************************************/
    void SENSOR_RX_PutCRLF(uint8 txDataByte) 
    {
        /* If not Initialized then skip this function */
        if(SENSOR_RX_initVar != 0u)
        {
            SENSOR_RX_PutChar(txDataByte);
            SENSOR_RX_PutChar(0x0Du);
            SENSOR_RX_PutChar(0x0Au);
        }
    }


    /*******************************************************************************
    * Function Name: SENSOR_RX_GetTxBufferSize
    ********************************************************************************
    *
    * Summary:
    *  Returns the number of bytes in the TX buffer which are waiting to be 
    *  transmitted.
    *  * TX software buffer is disabled (TX Buffer Size parameter is equal to 4): 
    *    returns 0 for empty TX FIFO, 1 for not full TX FIFO or 4 for full TX FIFO.
    *  * TX software buffer is enabled: returns the number of bytes in the TX 
    *    software buffer which are waiting to be transmitted. Bytes available in the
    *    TX FIFO do not count.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  Number of bytes used in the TX buffer. Return value type depends on the TX 
    *  Buffer Size parameter.
    *
    * Global Variables:
    *  SENSOR_RX_txBufferWrite - used to calculate left space.
    *  SENSOR_RX_txBufferRead - used to calculate left space.
    *
    * Reentrant:
    *  No.
    *
    * Theory:
    *  Allows the user to find out how full the TX Buffer is.
    *
    *******************************************************************************/
    uint8 SENSOR_RX_GetTxBufferSize(void)
                                                            
    {
        uint8 size;

    #if (SENSOR_RX_TX_INTERRUPT_ENABLED)

        /* Protect variables that could change on interrupt. */
        SENSOR_RX_DisableTxInt();

        if(SENSOR_RX_txBufferRead == SENSOR_RX_txBufferWrite)
        {
            size = 0u;
        }
        else if(SENSOR_RX_txBufferRead < SENSOR_RX_txBufferWrite)
        {
            size = (SENSOR_RX_txBufferWrite - SENSOR_RX_txBufferRead);
        }
        else
        {
            size = (SENSOR_RX_TX_BUFFER_SIZE - SENSOR_RX_txBufferRead) +
                    SENSOR_RX_txBufferWrite;
        }

        SENSOR_RX_EnableTxInt();

    #else

        size = SENSOR_RX_TXSTATUS_REG;

        /* Is the fifo is full. */
        if((size & SENSOR_RX_TX_STS_FIFO_FULL) != 0u)
        {
            size = SENSOR_RX_FIFO_LENGTH;
        }
        else if((size & SENSOR_RX_TX_STS_FIFO_EMPTY) != 0u)
        {
            size = 0u;
        }
        else
        {
            /* We only know there is data in the fifo. */
            size = 1u;
        }

    #endif /* (SENSOR_RX_TX_INTERRUPT_ENABLED) */

    return(size);
    }


    /*******************************************************************************
    * Function Name: SENSOR_RX_ClearTxBuffer
    ********************************************************************************
    *
    * Summary:
    *  Clears all data from the TX buffer and hardware TX FIFO.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    * Global Variables:
    *  SENSOR_RX_txBufferWrite - cleared to zero.
    *  SENSOR_RX_txBufferRead - cleared to zero.
    *
    * Reentrant:
    *  No.
    *
    * Theory:
    *  Setting the pointers to zero makes the system believe there is no data to
    *  read and writing will resume at address 0 overwriting any data that may have
    *  remained in the RAM.
    *
    * Side Effects:
    *  Data waiting in the transmit buffer is not sent; a byte that is currently
    *  transmitting finishes transmitting.
    *
    *******************************************************************************/
    void SENSOR_RX_ClearTxBuffer(void) 
    {
        uint8 enableInterrupts;

        enableInterrupts = CyEnterCriticalSection();
        /* Clear the HW FIFO */
        SENSOR_RX_TXDATA_AUX_CTL_REG |= (uint8)  SENSOR_RX_TX_FIFO_CLR;
        SENSOR_RX_TXDATA_AUX_CTL_REG &= (uint8) ~SENSOR_RX_TX_FIFO_CLR;
        CyExitCriticalSection(enableInterrupts);

    #if (SENSOR_RX_TX_INTERRUPT_ENABLED)

        /* Protect variables that could change on interrupt. */
        SENSOR_RX_DisableTxInt();

        SENSOR_RX_txBufferRead = 0u;
        SENSOR_RX_txBufferWrite = 0u;

        /* Enable Tx interrupt. */
        SENSOR_RX_EnableTxInt();

    #endif /* (SENSOR_RX_TX_INTERRUPT_ENABLED) */
    }


    /*******************************************************************************
    * Function Name: SENSOR_RX_SendBreak
    ********************************************************************************
    *
    * Summary:
    *  Transmits a break signal on the bus.
    *
    * Parameters:
    *  uint8 retMode:  Send Break return mode. See the following table for options.
    *   SENSOR_RX_SEND_BREAK - Initialize registers for break, send the Break
    *       signal and return immediately.
    *   SENSOR_RX_WAIT_FOR_COMPLETE_REINIT - Wait until break transmission is
    *       complete, reinitialize registers to normal transmission mode then return
    *   SENSOR_RX_REINIT - Reinitialize registers to normal transmission mode
    *       then return.
    *   SENSOR_RX_SEND_WAIT_REINIT - Performs both options: 
    *      SENSOR_RX_SEND_BREAK and SENSOR_RX_WAIT_FOR_COMPLETE_REINIT.
    *      This option is recommended for most cases.
    *
    * Return:
    *  None.
    *
    * Global Variables:
    *  SENSOR_RX_initVar - checked to identify that the component has been
    *     initialized.
    *  txPeriod - static variable, used for keeping TX period configuration.
    *
    * Reentrant:
    *  No.
    *
    * Theory:
    *  SendBreak function initializes registers to send 13-bit break signal. It is
    *  important to return the registers configuration to normal for continue 8-bit
    *  operation.
    *  There are 3 variants for this API usage:
    *  1) SendBreak(3) - function will send the Break signal and take care on the
    *     configuration returning. Function will block CPU until transmission
    *     complete.
    *  2) User may want to use blocking time if UART configured to the low speed
    *     operation
    *     Example for this case:
    *     SendBreak(0);     - initialize Break signal transmission
    *         Add your code here to use CPU time
    *     SendBreak(1);     - complete Break operation
    *  3) Same to 2) but user may want to initialize and use the interrupt to
    *     complete break operation.
    *     Example for this case:
    *     Initialize TX interrupt with "TX - On TX Complete" parameter
    *     SendBreak(0);     - initialize Break signal transmission
    *         Add your code here to use CPU time
    *     When interrupt appear with SENSOR_RX_TX_STS_COMPLETE status:
    *     SendBreak(2);     - complete Break operation
    *
    * Side Effects:
    *  The SENSOR_RX_SendBreak() function initializes registers to send a
    *  break signal.
    *  Break signal length depends on the break signal bits configuration.
    *  The register configuration should be reinitialized before normal 8-bit
    *  communication can continue.
    *
    *******************************************************************************/
    void SENSOR_RX_SendBreak(uint8 retMode) 
    {

        /* If not Initialized then skip this function*/
        if(SENSOR_RX_initVar != 0u)
        {
            /* Set the Counter to 13-bits and transmit a 00 byte */
            /* When that is done then reset the counter value back */
            uint8 tmpStat;

        #if(SENSOR_RX_HD_ENABLED) /* Half Duplex mode*/

            if( (retMode == SENSOR_RX_SEND_BREAK) ||
                (retMode == SENSOR_RX_SEND_WAIT_REINIT ) )
            {
                /* CTRL_HD_SEND_BREAK - sends break bits in HD mode */
                SENSOR_RX_WriteControlRegister(SENSOR_RX_ReadControlRegister() |
                                                      SENSOR_RX_CTRL_HD_SEND_BREAK);
                /* Send zeros */
                SENSOR_RX_TXDATA_REG = 0u;

                do /* Wait until transmit starts */
                {
                    tmpStat = SENSOR_RX_TXSTATUS_REG;
                }
                while((tmpStat & SENSOR_RX_TX_STS_FIFO_EMPTY) != 0u);
            }

            if( (retMode == SENSOR_RX_WAIT_FOR_COMPLETE_REINIT) ||
                (retMode == SENSOR_RX_SEND_WAIT_REINIT) )
            {
                do /* Wait until transmit complete */
                {
                    tmpStat = SENSOR_RX_TXSTATUS_REG;
                }
                while(((uint8)~tmpStat & SENSOR_RX_TX_STS_COMPLETE) != 0u);
            }

            if( (retMode == SENSOR_RX_WAIT_FOR_COMPLETE_REINIT) ||
                (retMode == SENSOR_RX_REINIT) ||
                (retMode == SENSOR_RX_SEND_WAIT_REINIT) )
            {
                SENSOR_RX_WriteControlRegister(SENSOR_RX_ReadControlRegister() &
                                              (uint8)~SENSOR_RX_CTRL_HD_SEND_BREAK);
            }

        #else /* SENSOR_RX_HD_ENABLED Full Duplex mode */

            static uint8 txPeriod;

            if( (retMode == SENSOR_RX_SEND_BREAK) ||
                (retMode == SENSOR_RX_SEND_WAIT_REINIT) )
            {
                /* CTRL_HD_SEND_BREAK - skip to send parity bit at Break signal in Full Duplex mode */
                #if( (SENSOR_RX_PARITY_TYPE != SENSOR_RX__B_UART__NONE_REVB) || \
                                    (SENSOR_RX_PARITY_TYPE_SW != 0u) )
                    SENSOR_RX_WriteControlRegister(SENSOR_RX_ReadControlRegister() |
                                                          SENSOR_RX_CTRL_HD_SEND_BREAK);
                #endif /* End SENSOR_RX_PARITY_TYPE != SENSOR_RX__B_UART__NONE_REVB  */

                #if(SENSOR_RX_TXCLKGEN_DP)
                    txPeriod = SENSOR_RX_TXBITCLKTX_COMPLETE_REG;
                    SENSOR_RX_TXBITCLKTX_COMPLETE_REG = SENSOR_RX_TXBITCTR_BREAKBITS;
                #else
                    txPeriod = SENSOR_RX_TXBITCTR_PERIOD_REG;
                    SENSOR_RX_TXBITCTR_PERIOD_REG = SENSOR_RX_TXBITCTR_BREAKBITS8X;
                #endif /* End SENSOR_RX_TXCLKGEN_DP */

                /* Send zeros */
                SENSOR_RX_TXDATA_REG = 0u;

                do /* Wait until transmit starts */
                {
                    tmpStat = SENSOR_RX_TXSTATUS_REG;
                }
                while((tmpStat & SENSOR_RX_TX_STS_FIFO_EMPTY) != 0u);
            }

            if( (retMode == SENSOR_RX_WAIT_FOR_COMPLETE_REINIT) ||
                (retMode == SENSOR_RX_SEND_WAIT_REINIT) )
            {
                do /* Wait until transmit complete */
                {
                    tmpStat = SENSOR_RX_TXSTATUS_REG;
                }
                while(((uint8)~tmpStat & SENSOR_RX_TX_STS_COMPLETE) != 0u);
            }

            if( (retMode == SENSOR_RX_WAIT_FOR_COMPLETE_REINIT) ||
                (retMode == SENSOR_RX_REINIT) ||
                (retMode == SENSOR_RX_SEND_WAIT_REINIT) )
            {

            #if(SENSOR_RX_TXCLKGEN_DP)
                SENSOR_RX_TXBITCLKTX_COMPLETE_REG = txPeriod;
            #else
                SENSOR_RX_TXBITCTR_PERIOD_REG = txPeriod;
            #endif /* End SENSOR_RX_TXCLKGEN_DP */

            #if( (SENSOR_RX_PARITY_TYPE != SENSOR_RX__B_UART__NONE_REVB) || \
                 (SENSOR_RX_PARITY_TYPE_SW != 0u) )
                SENSOR_RX_WriteControlRegister(SENSOR_RX_ReadControlRegister() &
                                                      (uint8) ~SENSOR_RX_CTRL_HD_SEND_BREAK);
            #endif /* End SENSOR_RX_PARITY_TYPE != NONE */
            }
        #endif    /* End SENSOR_RX_HD_ENABLED */
        }
    }


    /*******************************************************************************
    * Function Name: SENSOR_RX_SetTxAddressMode
    ********************************************************************************
    *
    * Summary:
    *  Configures the transmitter to signal the next bytes is address or data.
    *
    * Parameters:
    *  addressMode: 
    *       SENSOR_RX_SET_SPACE - Configure the transmitter to send the next
    *                                    byte as a data.
    *       SENSOR_RX_SET_MARK  - Configure the transmitter to send the next
    *                                    byte as an address.
    *
    * Return:
    *  None.
    *
    * Side Effects:
    *  This function sets and clears SENSOR_RX_CTRL_MARK bit in the Control
    *  register.
    *
    *******************************************************************************/
    void SENSOR_RX_SetTxAddressMode(uint8 addressMode) 
    {
        /* Mark/Space sending enable */
        if(addressMode != 0u)
        {
        #if( SENSOR_RX_CONTROL_REG_REMOVED == 0u )
            SENSOR_RX_WriteControlRegister(SENSOR_RX_ReadControlRegister() |
                                                  SENSOR_RX_CTRL_MARK);
        #endif /* End SENSOR_RX_CONTROL_REG_REMOVED == 0u */
        }
        else
        {
        #if( SENSOR_RX_CONTROL_REG_REMOVED == 0u )
            SENSOR_RX_WriteControlRegister(SENSOR_RX_ReadControlRegister() &
                                                  (uint8) ~SENSOR_RX_CTRL_MARK);
        #endif /* End SENSOR_RX_CONTROL_REG_REMOVED == 0u */
        }
    }

#endif  /* EndSENSOR_RX_TX_ENABLED */

#if(SENSOR_RX_HD_ENABLED)


    /*******************************************************************************
    * Function Name: SENSOR_RX_LoadRxConfig
    ********************************************************************************
    *
    * Summary:
    *  Loads the receiver configuration in half duplex mode. After calling this
    *  function, the UART is ready to receive data.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    * Side Effects:
    *  Valid only in half duplex mode. You must make sure that the previous
    *  transaction is complete and it is safe to unload the transmitter
    *  configuration.
    *
    *******************************************************************************/
    void SENSOR_RX_LoadRxConfig(void) 
    {
        SENSOR_RX_WriteControlRegister(SENSOR_RX_ReadControlRegister() &
                                                (uint8)~SENSOR_RX_CTRL_HD_SEND);
        SENSOR_RX_RXBITCTR_PERIOD_REG = SENSOR_RX_HD_RXBITCTR_INIT;

    #if (SENSOR_RX_RX_INTERRUPT_ENABLED)
        /* Enable RX interrupt after set RX configuration */
        SENSOR_RX_SetRxInterruptMode(SENSOR_RX_INIT_RX_INTERRUPTS_MASK);
    #endif /* (SENSOR_RX_RX_INTERRUPT_ENABLED) */
    }


    /*******************************************************************************
    * Function Name: SENSOR_RX_LoadTxConfig
    ********************************************************************************
    *
    * Summary:
    *  Loads the transmitter configuration in half duplex mode. After calling this
    *  function, the UART is ready to transmit data.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    * Side Effects:
    *  Valid only in half duplex mode. You must make sure that the previous
    *  transaction is complete and it is safe to unload the receiver configuration.
    *
    *******************************************************************************/
    void SENSOR_RX_LoadTxConfig(void) 
    {
    #if (SENSOR_RX_RX_INTERRUPT_ENABLED)
        /* Disable RX interrupts before set TX configuration */
        SENSOR_RX_SetRxInterruptMode(0u);
    #endif /* (SENSOR_RX_RX_INTERRUPT_ENABLED) */

        SENSOR_RX_WriteControlRegister(SENSOR_RX_ReadControlRegister() | SENSOR_RX_CTRL_HD_SEND);
        SENSOR_RX_RXBITCTR_PERIOD_REG = SENSOR_RX_HD_TXBITCTR_INIT;
    }

#endif  /* SENSOR_RX_HD_ENABLED */


/* [] END OF FILE */

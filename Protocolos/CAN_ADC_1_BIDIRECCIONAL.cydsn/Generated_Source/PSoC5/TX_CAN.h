/*******************************************************************************
* File Name: TX_CAN.h
* Version 3.0
*
* Description:
*  Contains the function prototypes, constants and register definition
*  of the CAN Component.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CAN_TX_CAN_H)
#define CY_CAN_TX_CAN_H

#include "cyfitter.h"
#include "cytypes.h"
#include "CyLib.h"
#include "cyapicallbacks.h"

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component CAN_v3_0 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */

extern uint8 TX_CAN_initVar;

#define TX_CAN_INT_ISR_DISABLE                (0u)


/***************************************
*   Conditional Compilation Parameters
***************************************/

#define TX_CAN_ARB_LOST                       (0u)
#define TX_CAN_OVERLOAD                       (0u)
#define TX_CAN_BIT_ERR                        (0u)
#define TX_CAN_STUFF_ERR                      (0u)
#define TX_CAN_ACK_ERR                        (0u)
#define TX_CAN_FORM_ERR                       (0u)
#define TX_CAN_CRC_ERR                        (0u)
#define TX_CAN_BUS_OFF                        (1u)
#define TX_CAN_RX_MSG_LOST                    (0u)
#define TX_CAN_TX_MESSAGE                     (0u)
#define TX_CAN_RX_MESSAGE                     (1u)
#define TX_CAN_ARB_LOST_USE_HELPER            (1u)
#define TX_CAN_OVERLOAD_USE_HELPER            (1u)
#define TX_CAN_BIT_ERR_USE_HELPER             (1u)
#define TX_CAN_STUFF_ERR_USE_HELPER           (1u)
#define TX_CAN_ACK_ERR_USE_HELPER             (1u)
#define TX_CAN_FORM_ERR_USE_HELPER            (1u)
#define TX_CAN_CRC_ERR_USE_HELPER             (1u)
#define TX_CAN_BUS_OFF_USE_HELPER             (1u)
#define TX_CAN_RX_MSG_LOST_USE_HELPER         (1u)
#define TX_CAN_TX_MESSAGE_USE_HELPER          (1u)
#define TX_CAN_RX_MESSAGE_USE_HELPER          (1u)

#if (!(CY_PSOC3 || CY_PSOC5))
    #define TX_CAN_RTR_AUTO_MSG_SENT          (0u)
    #define TX_CAN_STUCK_AT_ZERO              (0u)
    #define TX_CAN_SST_FAILURE                (0u)

    #define TX_CAN_RTR_MESSAGE_USE_HELPER     (1u)
    #define TX_CAN_STUCK_AT_ZERO_USE_HELPER   (1u)
    #define TX_CAN_SST_FAILURE_USE_HELPER     (1u)
#endif /* (!(CY_PSOC3 || CY_PSOC5)) */

#define TX_CAN_ADVANCED_INTERRUPT_CFG         (0u)

/* TX/RX Function Enable */
#define TX_CAN_TX0_FUNC_ENABLE         (1u)
#define TX_CAN_TX1_FUNC_ENABLE         (0u)
#define TX_CAN_TX2_FUNC_ENABLE         (0u)
#define TX_CAN_TX3_FUNC_ENABLE         (0u)
#define TX_CAN_TX4_FUNC_ENABLE         (0u)
#define TX_CAN_TX5_FUNC_ENABLE         (0u)
#define TX_CAN_TX6_FUNC_ENABLE         (0u)
#define TX_CAN_TX7_FUNC_ENABLE         (0u)
#define TX_CAN_RX0_FUNC_ENABLE         (1u)
#define TX_CAN_RX1_FUNC_ENABLE         (0u)
#define TX_CAN_RX2_FUNC_ENABLE         (0u)
#define TX_CAN_RX3_FUNC_ENABLE         (0u)
#define TX_CAN_RX4_FUNC_ENABLE         (0u)
#define TX_CAN_RX5_FUNC_ENABLE         (0u)
#define TX_CAN_RX6_FUNC_ENABLE         (0u)
#define TX_CAN_RX7_FUNC_ENABLE         (0u)
#define TX_CAN_RX8_FUNC_ENABLE         (0u)
#define TX_CAN_RX9_FUNC_ENABLE         (0u)
#define TX_CAN_RX10_FUNC_ENABLE        (0u)
#define TX_CAN_RX11_FUNC_ENABLE        (0u)
#define TX_CAN_RX12_FUNC_ENABLE        (0u)
#define TX_CAN_RX13_FUNC_ENABLE        (0u)
#define TX_CAN_RX14_FUNC_ENABLE        (0u)
#define TX_CAN_RX15_FUNC_ENABLE        (0u)
#define TX_CAN_RX_MAILBOX_TYPE         (0x1u)
#define TX_CAN_TX_MAILBOX_TYPE         (0x1u)


/***************************************
*        Data Struct Definition
***************************************/

/* Struct for DATA of BASIC CAN mailbox */
typedef struct
{
    uint8 byte[8u];
} TX_CAN_DATA_BYTES_MSG;

/* Struct for DATA of CAN RX register */
typedef struct
{
    reg8 byte[8u];
} TX_CAN_DATA_BYTES;

/* Struct for 32-bit CAN register */
typedef struct
{
    reg8 byte[4u];
} TX_CAN_REG_32;

/* Struct for BASIC CAN mailbox to send messages */
typedef struct
{
    uint32 id;
    uint8 rtr;
    uint8 ide;
    uint8 dlc;
    uint8 irq;
    #if (!(CY_PSOC3 || CY_PSOC5))
        uint8 sst;
    #endif /* (!(CY_PSOC3 || CY_PSOC5)) */
    TX_CAN_DATA_BYTES_MSG *msg;
} TX_CAN_TX_MSG;

/* Constant configuration of CAN RX */
typedef struct
{
    uint8 rxmailbox;
    uint32 rxcmd;
    uint32 rxamr;
    uint32 rxacr;
} TX_CAN_RX_CFG;

/* Constant configuration of CAN TX */
typedef struct
{
    uint8 txmailbox;
    uint32 txcmd;
    uint32 txid;
} TX_CAN_TX_CFG;

/* CAN RX registers */
typedef struct
{
    TX_CAN_REG_32 rxcmd;
    TX_CAN_REG_32 rxid;
    TX_CAN_DATA_BYTES rxdata;
    TX_CAN_REG_32 rxamr;
    TX_CAN_REG_32 rxacr;
    TX_CAN_REG_32 rxamrd;
    TX_CAN_REG_32 rxacrd;
} TX_CAN_RX_STRUCT;

/* CAN TX registers */
typedef struct
{
    TX_CAN_REG_32 txcmd;
    TX_CAN_REG_32 txid;
    TX_CAN_DATA_BYTES txdata;
} TX_CAN_TX_STRUCT;

/* Sleep Mode API Support */
typedef struct
{
    uint8  enableState;
    #if (CY_PSOC3 || CY_PSOC5)
        uint32 intSr;
        uint32 intEn;
        uint32 cmd;
        uint32 cfg;
    #endif /* CY_PSOC3 || CY_PSOC5 */
} TX_CAN_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

uint8  TX_CAN_Init(void) ;
uint8  TX_CAN_Start(void) ;
uint8  TX_CAN_Stop(void) ;
uint8  TX_CAN_Enable(void) ;
uint8  TX_CAN_GlobalIntEnable(void) ;
uint8  TX_CAN_GlobalIntDisable(void) ;
uint8  TX_CAN_SetPreScaler(uint16 bitrate) ;
uint8  TX_CAN_SetArbiter(uint8 arbiter) ;
uint8  TX_CAN_SetTsegSample(uint8 cfgTseg1, uint8 cfgTseg2, uint8 sjw, uint8 sm)
                                                ;
uint8  TX_CAN_SetRestartType(uint8 reset) ;
uint8  TX_CAN_SetEdgeMode(uint8 edge) ;
uint8  TX_CAN_SetOpMode(uint8 opMode) ;
uint8  TX_CAN_RXRegisterInit(reg32 *regAddr, uint32 config)
                                            ;
uint8  TX_CAN_SetIrqMask(uint16 mask) ;
uint8  TX_CAN_GetTXErrorFlag(void) ;
uint8  TX_CAN_GetRXErrorFlag(void) ;
uint8  TX_CAN_GetTXErrorCount(void) ;
uint8  TX_CAN_GetRXErrorCount(void) ;
uint8  TX_CAN_GetErrorState(void) ;
void   TX_CAN_Sleep(void) ;
void   TX_CAN_Wakeup(void) ;
void   TX_CAN_SaveConfig(void) ;
void   TX_CAN_RestoreConfig(void) ;

#if (!(CY_PSOC3 || CY_PSOC5))
    uint8  TX_CAN_SetSwapDataEndianness(uint8 swap);
    uint8  TX_CAN_SetErrorCaptureRegisterMode(uint8 ecrMode);
    uint32 TX_CAN_ReadErrorCaptureRegister(void);
    uint8  TX_CAN_ArmErrorCaptureRegister(void);
#endif /* (!(CY_PSOC3 || CY_PSOC5)) */

#if (TX_CAN_ARB_LOST)
    void TX_CAN_ArbLostIsr(void) ;
#endif /* TX_CAN_ARB_LOST */
#if (TX_CAN_OVERLOAD)
    void TX_CAN_OvrLdErrorIsr(void) ;
#endif /* TX_CAN_OVERLOAD */
#if (TX_CAN_BIT_ERR)
    void TX_CAN_BitErrorIsr(void) ;
#endif /* TX_CAN_BIT_ERR */
#if (TX_CAN_STUFF_ERR)
    void TX_CAN_BitStuffErrorIsr(void) ;
#endif /* TX_CAN_STUFF_ERR */
#if (TX_CAN_ACK_ERR)
    void TX_CAN_AckErrorIsr(void) ;
#endif /* TX_CAN_ACK_ERR */
#if (TX_CAN_FORM_ERR)
    void TX_CAN_MsgErrorIsr(void) ;
#endif /* TX_CAN_FORM_ERR */
#if (TX_CAN_CRC_ERR)
    void TX_CAN_CrcErrorIsr(void) ;
#endif /* TX_CAN_CRC_ERR */
#if (TX_CAN_BUS_OFF)
    void TX_CAN_BusOffIsr(void) ;
#endif /* TX_CAN_BUS_OFF */
#if (TX_CAN_RX_MSG_LOST)
    void TX_CAN_MsgLostIsr(void) ;
#endif /* TX_CAN_RX_MSG_LOST */
#if (TX_CAN_TX_MESSAGE)
   void TX_CAN_MsgTXIsr(void) ;
#endif /* TX_CAN_TX_MESSAGE */
#if (TX_CAN_RX_MESSAGE)
    void TX_CAN_MsgRXIsr(void) ;
#endif /* TX_CAN_RX_MESSAGE */

#if (!(CY_PSOC3 || CY_PSOC5))
    #if (TX_CAN_RTR_AUTO_MSG_SENT)
        void TX_CAN_RtrAutoMsgSentIsr(void);
    #endif /* TX_CAN_RTR_MESSAGE */
    #if (TX_CAN_STUCK_AT_ZERO)
        void TX_CAN_StuckAtZeroIsr(void);
    #endif /* TX_CAN_STUCK_AT_ZERO */
    #if (TX_CAN_SST_FAILURE)
        void TX_CAN_SSTErrorIsr(void);
    #endif /* TX_CAN_SST_ERROR */
#endif /* (!(CY_PSOC3 || CY_PSOC5)) */

uint8 TX_CAN_RxBufConfig(const TX_CAN_RX_CFG *rxConfig) \
                                   ;
uint8 TX_CAN_TxBufConfig(const TX_CAN_TX_CFG *txConfig) \
                                   ;
uint8 TX_CAN_RxTxBuffersConfig(void) ;                                
uint8 TX_CAN_SendMsg(const TX_CAN_TX_MSG *message) ;
void  TX_CAN_TxCancel(uint8 bufferId) ;
void  TX_CAN_ReceiveMsg(uint8 rxMailbox) ;

#if (TX_CAN_TX0_FUNC_ENABLE)
    uint8 TX_CAN_SendMsg0(void) ;
#endif /* TX_CAN_TX0_FUNC_ENABLE */
#if (TX_CAN_TX1_FUNC_ENABLE)
    uint8 TX_CAN_SendMsg1(void) ;
#endif /* TX_CAN_TX1_FUNC_ENABLE */
#if (TX_CAN_TX2_FUNC_ENABLE)
    uint8 TX_CAN_SendMsg2(void) ;
#endif /* TX_CAN_TX2_FUNC_ENABLE */
#if (TX_CAN_TX3_FUNC_ENABLE)
    uint8 TX_CAN_SendMsg3(void) ;
#endif /* TX_CAN_TX3_FUNC_ENABLE */
#if (TX_CAN_TX4_FUNC_ENABLE)
    uint8 TX_CAN_SendMsg4(void) ;
#endif /* TX_CAN_TX4_FUNC_ENABLE */
#if (TX_CAN_TX5_FUNC_ENABLE)
    uint8 TX_CAN_SendMsg5(void) ;
#endif /* TX_CAN_TX5_FUNC_ENABLE */
#if (TX_CAN_TX6_FUNC_ENABLE)
    uint8 TX_CAN_SendMsg6(void) ;
#endif /* TX_CAN_TX6_FUNC_ENABLE */
#if (TX_CAN_TX7_FUNC_ENABLE)
    uint8 TX_CAN_SendMsg7(void) ;
#endif /* TX_CAN_TX7_FUNC_ENABLE */
#if (TX_CAN_RX0_FUNC_ENABLE)
    void TX_CAN_ReceiveMsg0(void) ;
#endif /* TX_CAN_RX0_FUNC_ENABLE */
#if (TX_CAN_RX1_FUNC_ENABLE)
    void TX_CAN_ReceiveMsg1(void) ;
#endif /* TX_CAN_RX1_FUNC_ENABLE */
#if (TX_CAN_RX2_FUNC_ENABLE)
    void TX_CAN_ReceiveMsg2(void) ;
#endif /* TX_CAN_RX2_FUNC_ENABLE */
#if (TX_CAN_RX3_FUNC_ENABLE)
    void TX_CAN_ReceiveMsg3(void) ;
#endif /* TX_CAN_RX3_FUNC_ENABLE */
#if (TX_CAN_RX4_FUNC_ENABLE)
    void TX_CAN_ReceiveMsg4(void) ;
#endif /* TX_CAN_RX4_FUNC_ENABLE */
#if (TX_CAN_RX5_FUNC_ENABLE)
    void TX_CAN_ReceiveMsg5(void) ;
#endif /* TX_CAN_RX5_FUNC_ENABLE */
#if (TX_CAN_RX6_FUNC_ENABLE)
    void TX_CAN_ReceiveMsg6(void) ;
#endif /* TX_CAN_RX6_FUNC_ENABLE */
#if (TX_CAN_RX7_FUNC_ENABLE)
    void TX_CAN_ReceiveMsg7(void) ;
#endif /* TX_CAN_RX7_FUNC_ENABLE */
#if (TX_CAN_RX8_FUNC_ENABLE)
    void TX_CAN_ReceiveMsg8(void) ;
#endif /* TX_CAN_RX8_FUNC_ENABLE */
#if (TX_CAN_RX9_FUNC_ENABLE)
    void TX_CAN_ReceiveMsg9(void) ;
#endif /* TX_CAN_RX9_FUNC_ENABLE */
#if (TX_CAN_RX10_FUNC_ENABLE)
    void TX_CAN_ReceiveMsg10(void) ;
#endif /* TX_CAN_RX10_FUNC_ENABLE */
#if (TX_CAN_RX11_FUNC_ENABLE)
    void TX_CAN_ReceiveMsg11(void) ;
#endif /* TX_CAN_RX11_FUNC_ENABLE */
#if (TX_CAN_RX12_FUNC_ENABLE)
    void TX_CAN_ReceiveMsg12(void) ;
#endif /* TX_CAN_RX12_FUNC_ENABLE */
#if (TX_CAN_RX13_FUNC_ENABLE)
    void TX_CAN_ReceiveMsg13(void) ;
#endif /* TX_CAN_RX13_FUNC_ENABLE */
#if (TX_CAN_RX14_FUNC_ENABLE)
    void TX_CAN_ReceiveMsg14(void) ;
#endif /* TX_CAN_RX14_FUNC_ENABLE */
#if (TX_CAN_RX15_FUNC_ENABLE)
    void TX_CAN_ReceiveMsg15(void) ;
#endif /* TX_CAN_RX15_FUNC_ENABLE */

#if(!TX_CAN_INT_ISR_DISABLE)
    /* Interrupt handler */
    CY_ISR_PROTO(TX_CAN_ISR);
#endif /* !TX_CAN_INT_ISR_DISABLE */


/***************************************
*           API Constants
***************************************/

#if (!TX_CAN_INT_ISR_DISABLE)
    /* Number of TX_CAN_isr interrupt */
    #define TX_CAN_ISR_NUMBER            ((uint8) TX_CAN_isr__INTC_NUMBER)
    /* Priority of TX_CAN_isr interrupt */
    #define TX_CAN_ISR_PRIORITY          ((uint8) TX_CAN_isr__INTC_PRIOR_NUM)
#endif /* !TX_CAN_INT_ISR_DISABLE */

/* One bit time in CAN clock cycles */
#define TX_CAN_ONE_BIT_TIME              ((TX_CAN_BITRATE + 1u) * \
        ((TX_CAN_CFG_REG_TSEG1 + 1u) + (TX_CAN_CFG_REG_TSEG2 + 1u) + 1u))

/* Timeout for CAN state machine to switch operation mode to Run */
#define TX_CAN_MODE_STATE_RUN_TIMEOUT    (12u * TX_CAN_ONE_BIT_TIME)
/* Timeout for CAN state machine to switch operation mode to Stop */
#define TX_CAN_MODE_STATE_STOP_TIMEOUT   (160u * TX_CAN_ONE_BIT_TIME)

/* One or more parameters to function were invalid. */
#define TX_CAN_FAIL                      (0x01u)
#define TX_CAN_OUT_OF_RANGE              (0x02u)

#if (CY_PSOC3 || CY_PSOC5)
    /* PM_ACT_CFG (Active Power Mode CFG Register) */
    #define TX_CAN_ACT_PWR_EN            (TX_CAN_CanIP__PM_ACT_MSK)    /* Power enable mask */
    /* PM_STBY_CFG (Alternate Active (Standby) Power Mode CFG Register) */
    #define TX_CAN_STBY_PWR_EN           (TX_CAN_CanIP__PM_STBY_MSK)   /* Power enable mask */
#endif /* CY_PSOC3 || CY_PSOC5 */

/* Number of TX and RX mailboxes */
#define TX_CAN_NUMBER_OF_TX_MAILBOXES    (8u)
#define TX_CAN_NUMBER_OF_RX_MAILBOXES    (16u)

/* Error status of CAN */
#define TX_CAN_ERROR_ACTIVE              (0x00u)
#define TX_CAN_ERROR_PASIVE              (0x01u)
#define TX_CAN_ERROR_BUS_OFF             (0x10u)

/* Operation mode */
#define TX_CAN_INITIAL_MODE              (0x00u)
#define TX_CAN_STOP_MODE                 (0x00u)
#define TX_CAN_ACTIVE_RUN_MODE           (0x01u)
#define TX_CAN_LISTEN_ONLY_MODE          (0x02u)
#if (!(CY_PSOC3 || CY_PSOC5))
    #define TX_CAN_INTERNAL_LOOP_BACK    (0x06u)
    #define TX_CAN_EXTERNAL_LOOP_BACK    (0x04u)
#endif /* (!(CY_PSOC3 || CY_PSOC5)) */

/* TX Defines to link mailbox names with mailbox numbers */
#define TX_CAN_TX_MAILBOX_0            (0u)
#define TX_CAN_TX_MAILBOX_1            (1u)
#define TX_CAN_TX_MAILBOX_2            (2u)
#define TX_CAN_TX_MAILBOX_3            (3u)
#define TX_CAN_TX_MAILBOX_4            (4u)
#define TX_CAN_TX_MAILBOX_5            (5u)
#define TX_CAN_TX_MAILBOX_6            (6u)
#define TX_CAN_TX_MAILBOX_7            (7u)

/* RX Defines to link mailbox names with mailbox numbers */
#define TX_CAN_RX_MAILBOX_0            (0u)
#define TX_CAN_RX_MAILBOX_1            (1u)
#define TX_CAN_RX_MAILBOX_2            (2u)
#define TX_CAN_RX_MAILBOX_3            (3u)
#define TX_CAN_RX_MAILBOX_4            (4u)
#define TX_CAN_RX_MAILBOX_5            (5u)
#define TX_CAN_RX_MAILBOX_6            (6u)
#define TX_CAN_RX_MAILBOX_7            (7u)
#define TX_CAN_RX_MAILBOX_8            (8u)
#define TX_CAN_RX_MAILBOX_9            (9u)
#define TX_CAN_RX_MAILBOX_10           (10u)
#define TX_CAN_RX_MAILBOX_11           (11u)
#define TX_CAN_RX_MAILBOX_12           (12u)
#define TX_CAN_RX_MAILBOX_13           (13u)
#define TX_CAN_RX_MAILBOX_14           (14u)
#define TX_CAN_RX_MAILBOX_15           (15u)


/***************************************
*    Initial Parameter Constants
***************************************/

/* General */
#define TX_CAN_BITRATE                   (0u)
#define TX_CAN_CFG_REG_TSEG1             (13u - 1u)
#define TX_CAN_CFG_REG_TSEG2             (2u - 1u)
#define TX_CAN_CFG_REG_SJW               (1u - 1u)
#define TX_CAN_SAMPLING_MODE             (0u)
#define TX_CAN_ARBITER                   (0u)
#define TX_CAN_RESET_TYPE                (0u)
#define TX_CAN_SYNC_EDGE                 (0u)

#if (!(CY_PSOC3 || CY_PSOC5))
    #define TX_CAN_SWAP_DATA_END         (0u)
#endif /* (!(CY_PSOC3 || CY_PSOC5)) */

/* Interrupts */
#define TX_CAN_INT_ENABLE                (1u)

#if (CY_PSOC3 || CY_PSOC5)
    #define TX_CAN_INIT_INTERRUPT_MASK (((uint16) TX_CAN_INT_ENABLE) | \
                ((uint16) ((uint16) TX_CAN_ARB_LOST    <<  TX_CAN_ARBITRATION_LOST_SHIFT)) | \
                ((uint16) ((uint16) TX_CAN_OVERLOAD    <<  TX_CAN_OVERLOAD_ERROR_SHIFT))   | \
                ((uint16) ((uint16) TX_CAN_BIT_ERR     <<  TX_CAN_BIT_ERROR_SHIFT))        | \
                ((uint16) ((uint16) TX_CAN_STUFF_ERR   <<  TX_CAN_STUFF_ERROR_SHIFT))      | \
                ((uint16) ((uint16) TX_CAN_ACK_ERR     <<  TX_CAN_ACK_ERROR_SHIFT))        | \
                ((uint16) ((uint16) TX_CAN_FORM_ERR    <<  TX_CAN_FORM_ERROR_SHIFT))       | \
                ((uint16) ((uint16) TX_CAN_CRC_ERR     << (TX_CAN_ONE_BYTE_OFFSET          + \
                                                                     TX_CAN_CRC_ERROR_SHIFT)))       | \
                ((uint16) ((uint16) TX_CAN_BUS_OFF     << (TX_CAN_ONE_BYTE_OFFSET          + \
                                                                     TX_CAN_BUS_OFF_SHIFT)))         | \
                ((uint16) ((uint16) TX_CAN_RX_MSG_LOST << (TX_CAN_ONE_BYTE_OFFSET          + \
                                                                     TX_CAN_RX_MSG_LOST_SHIFT)))     | \
                ((uint16) ((uint16) TX_CAN_TX_MESSAGE  << (TX_CAN_ONE_BYTE_OFFSET          + \
                                                                     TX_CAN_TX_MESSAGE_SHIFT)))      | \
                ((uint16) ((uint16) TX_CAN_RX_MESSAGE  << (TX_CAN_ONE_BYTE_OFFSET          + \
                                                                     TX_CAN_RX_MESSAGE_SHIFT))))
#else /* CY_PSOC4 */
    #define TX_CAN_INIT_INTERRUPT_MASK    (((uint16) TX_CAN_INT_ENABLE) | \
                ((uint16) ((uint16) TX_CAN_ARB_LOST    <<  TX_CAN_ARBITRATION_LOST_SHIFT)) | \
                ((uint16) ((uint16) TX_CAN_OVERLOAD    <<  TX_CAN_OVERLOAD_ERROR_SHIFT))   | \
                ((uint16) ((uint16) TX_CAN_BIT_ERR     <<  TX_CAN_BIT_ERROR_SHIFT))        | \
                ((uint16) ((uint16) TX_CAN_STUFF_ERR   <<  TX_CAN_STUFF_ERROR_SHIFT))      | \
                ((uint16) ((uint16) TX_CAN_ACK_ERR     <<  TX_CAN_ACK_ERROR_SHIFT))        | \
                ((uint16) ((uint16) TX_CAN_FORM_ERR    <<  TX_CAN_FORM_ERROR_SHIFT))       | \
                ((uint16) ((uint16) TX_CAN_CRC_ERR     <<  TX_CAN_CRC_ERROR_SHIFT))        | \
                ((uint16) ((uint16) TX_CAN_BUS_OFF     <<  TX_CAN_BUS_OFF_SHIFT))          | \
                ((uint16) ((uint16) TX_CAN_RX_MSG_LOST <<  TX_CAN_RX_MSG_LOST_SHIFT))      | \
                ((uint16) ((uint16) TX_CAN_TX_MESSAGE  <<  TX_CAN_TX_MESSAGE_SHIFT))       | \
                ((uint16) ((uint16) TX_CAN_RX_MESSAGE  <<  TX_CAN_RX_MESSAGE_SHIFT))       | \
                ((uint16) ((uint16) TX_CAN_RTR_AUTO_MSG_SENT  << TX_CAN_RTR_MSG_SHIFT))    | \
                ((uint16) ((uint16) TX_CAN_STUCK_AT_ZERO << TX_CAN_STUCK_AT_ZERO_SHIFT))   | \
                ((uint16) ((uint16) TX_CAN_SST_FAILURE   << TX_CAN_SST_FAILURE_SHIFT)))
#endif /* (CY_PSOC3 || CY_PSOC5) */


/***************************************
*             Registers
***************************************/

#if (CY_PSOC3 || CY_PSOC5)
#define TX_CAN_TX          ( (volatile TX_CAN_TX_STRUCT XDATA *) TX_CAN_CanIP__TX0_CMD)
#define TX_CAN_RX          ( (volatile TX_CAN_RX_STRUCT XDATA *) TX_CAN_CanIP__RX0_CMD)
#define TX_CAN_INT_SR_REG  (*(volatile TX_CAN_REG_32 XDATA *) TX_CAN_CanIP__CSR_INT_SR)
#define TX_CAN_INT_SR_PTR  ( (reg32 *) TX_CAN_CanIP__CSR_INT_SR)
#define TX_CAN_INT_EN_REG  (*(volatile TX_CAN_REG_32 XDATA *) TX_CAN_CanIP__CSR_INT_EN)
#define TX_CAN_INT_EN_PTR  ( (reg32 *) TX_CAN_CanIP__CSR_INT_EN)
#define TX_CAN_BUF_SR_REG  (*(volatile TX_CAN_REG_32 XDATA *) TX_CAN_CanIP__CSR_BUF_SR)
#define TX_CAN_BUF_SR_PTR  ( (reg32 *) TX_CAN_CanIP__CSR_BUF_SR)
#define TX_CAN_ERR_SR_REG  (*(volatile TX_CAN_REG_32 XDATA *) TX_CAN_CanIP__CSR_ERR_SR)
#define TX_CAN_ERR_SR_PTR  ( (reg32 *) TX_CAN_CanIP__CSR_ERR_SR)
#define TX_CAN_CMD_REG     (*(volatile TX_CAN_REG_32 XDATA *) TX_CAN_CanIP__CSR_CMD)
#define TX_CAN_CMD_PTR     ( (reg32 *) TX_CAN_CanIP__CSR_CMD)
#define TX_CAN_CFG_REG     (*(volatile TX_CAN_REG_32 XDATA *) TX_CAN_CanIP__CSR_CFG)
#define TX_CAN_CFG_PTR     ( (reg32 *) TX_CAN_CanIP__CSR_CFG)

/* Power manager */
#define TX_CAN_PM_ACT_CFG_REG           (*(reg8 *) TX_CAN_CanIP__PM_ACT_CFG)
#define TX_CAN_PM_ACT_CFG_PTR           ( (reg8 *) TX_CAN_CanIP__PM_ACT_CFG)
#define TX_CAN_PM_STBY_CFG_REG          (*(reg8 *) TX_CAN_CanIP__PM_STBY_CFG)
#define TX_CAN_PM_STBY_CFG_PTR          ( (reg8 *) TX_CAN_CanIP__PM_STBY_CFG)

#define TX_CAN_RX_FIRST_REGISTER_PTR    ((reg32 *) TX_CAN_CanIP__RX0_CMD)
#define TX_CAN_RX_LAST_REGISTER_PTR     ((reg32 *) TX_CAN_CanIP__RX15_ACRD)

#else /* CY_PSOC4 */
#define TX_CAN_TX    ((volatile TX_CAN_TX_STRUCT XDATA *) TX_CAN_CanIP__CAN_TX0_CONTROL)
#define TX_CAN_RX    ((volatile TX_CAN_RX_STRUCT XDATA *) TX_CAN_CanIP__CAN_RX0_CONTROL)
#define TX_CAN_TX_REG                   (*(reg32 *) TX_CAN_CanIP__CAN_TX0_CONTROL)
#define TX_CAN_TX_PTR                   ( (reg32 *) TX_CAN_CanIP__CAN_TX0_CONTROL)
#define TX_CAN_RX_REG                   (*(reg32 *) TX_CAN_CanIP__CAN_RX0_CONTROL)
#define TX_CAN_RX_PTR                   ( (reg32 *) TX_CAN_CanIP__CAN_RX0_CONTROL)
#define TX_CAN_INT_SR_REG               (*(reg32 *) TX_CAN_CanIP__INT_STATUS)
#define TX_CAN_INT_SR_PTR               ( (reg32 *) TX_CAN_CanIP__INT_STATUS)
#define TX_CAN_INT_EN_REG               (*(reg32 *) TX_CAN_CanIP__INT_EBL)
#define TX_CAN_INT_EN_PTR               ( (reg32 *) TX_CAN_CanIP__INT_EBL)
#define TX_CAN_BUF_SR_REG               (*(reg32 *) TX_CAN_CanIP__BUFFER_STATUS)
#define TX_CAN_BUF_SR_PTR               ( (reg32 *) TX_CAN_CanIP__BUFFER_STATUS)
#define TX_CAN_ERR_SR_REG               (*(reg32 *) TX_CAN_CanIP__ERROR_STATUS)
#define TX_CAN_ERR_SR_PTR               ( (reg32 *) TX_CAN_CanIP__ERROR_STATUS)
#define TX_CAN_CNTL_REG                 (*(reg32 *) TX_CAN_CanIP__CNTL)
#define TX_CAN_CNTL_PTR                 ( (reg32 *) TX_CAN_CanIP__CNTL)
#define TX_CAN_CMD_REG                  (*(reg32 *) TX_CAN_CanIP__COMMAND)
#define TX_CAN_CMD_PTR                  ( (reg32 *) TX_CAN_CanIP__COMMAND)
#define TX_CAN_CFG_REG                  (*(reg32 *) TX_CAN_CanIP__CONFIG)
#define TX_CAN_CFG_PTR                  ( (reg32 *) TX_CAN_CanIP__CONFIG)
#define TX_CAN_ECR_REG                  (*(reg32 *) TX_CAN_CanIP__ECR)
#define TX_CAN_ECR_PTR                  ( (reg32 *) TX_CAN_CanIP__ECR)
#define TX_CAN_RX_FIRST_REGISTER_PTR    ( (reg32 *) TX_CAN_CanIP__CAN_RX0_CONTROL)
#define TX_CAN_RX_LAST_REGISTER_PTR     ( (reg32 *) TX_CAN_CanIP__CAN_RX15_ACR_DATA)

#define TX_CAN_TX_DATA_LO_REG(i)        (*(reg32 *) (&TX_CAN_TX[i].txdata))
#define TX_CAN_TX_DATA_HI_REG(i)        (*(reg32 *) ((uint32) (&TX_CAN_TX[i].txdata) + \
                                                  TX_CAN_DATA_HIGH_ADDR))
#define TX_CAN_RX_DATA_LO_REG(i)        (*(reg32 *) (&TX_CAN_RX[i].rxdata))
#define TX_CAN_RX_DATA_HI_REG(i)        (*(reg32 *) ((uint32) (&TX_CAN_RX[i].rxdata) + \
                                                  TX_CAN_DATA_HIGH_ADDR))
#endif /* (CY_PSOC3 || CY_PSOC5) */

#define TX_CAN_TX_CMD_PTR(i)            ( (reg32 *) (&TX_CAN_TX[i].txcmd))
#define TX_CAN_TX_CMD_REG(i)            (*(reg32 *) (&TX_CAN_TX[i].txcmd))
#define TX_CAN_RX_CMD_PTR(i)            ( (reg32 *) (&TX_CAN_RX[i].rxcmd))
#define TX_CAN_RX_CMD_REG(i)            (*(reg32 *) (&TX_CAN_RX[i].rxcmd))
#define TX_CAN_RX_ID_PTR(i)             ( (reg32 *) (&TX_CAN_RX[i].rxid))
#define TX_CAN_RX_ID_REG(i)             (*(reg32 *) (&TX_CAN_RX[i].rxid))
#define TX_CAN_TX_ID_PTR(i)             ( (reg32 *) (&TX_CAN_TX[i].txid))
#define TX_CAN_TX_ID_REG(i)             (*(reg32 *) (&TX_CAN_TX[i].txid))


/***************************************
*        Register Constants
***************************************/

/* Run/Stop mode */
#define TX_CAN_MODE_STOP                (0x00u)
#define TX_CAN_MODE_START               (0x01u)

/* Transmit buffer arbiter */
#define TX_CAN_ROUND_ROBIN              (0x00u)
#define TX_CAN_FIXED_PRIORITY           (0x01u)

/* Restart type */
#define TX_CAN_MANUAL_RESTART           (0x00u)
#define TX_CAN_AUTO_RESTART             (0x01u)

/* Sampling mode */
#define TX_CAN_ONE_SAMPLE_POINT         (0x00u)
#define TX_CAN_THREE_SAMPLE_POINTS      (0x01u)

/* Edge mode */
#define TX_CAN_EDGE_R_TO_D              (0x00u)
#define TX_CAN_BOTH_EDGES               (0x01u)

/* Extended identifier */
#define TX_CAN_STANDARD_MESSAGE         (0x00u)
#define TX_CAN_EXTENDED_MESSAGE         (0x01u)

/* Write Protect Mask for Basic and Full mailboxes */
#define TX_CAN_TX_WPN_CLEAR           ((uint32) (~TX_CAN_TX_WPN_SET))
#define TX_CAN_RX_WPN_CLEAR           ((uint32) (~TX_CAN_RX_WPN_SET))
#define TX_CAN_TX_RSVD_MASK           ((uint32) 0x00FF00FFu)
#define TX_CAN_TX_READ_BACK_MASK      (TX_CAN_TX_WPN_CLEAR & TX_CAN_TX_RSVD_MASK)
#define TX_CAN_RX_READ_BACK_MASK      (TX_CAN_RX_WPN_CLEAR & TX_CAN_TX_RSVD_MASK)
#define TX_CAN_RX_CMD_REG_WIDTH       (0x20u)

#if (CY_PSOC3 || CY_PSOC5)
    #define TX_CAN_TX_WPN_SET         (((uint32) ((uint32) 0x00000001u << TX_CAN_TX_WPNL_SHIFT)) | \
            ((uint32) ((uint32) 0x00000001u << (TX_CAN_TWO_BYTE_OFFSET + TX_CAN_TX_WPNH_SHIFT))))
    #define TX_CAN_RX_WPN_SET         (((uint32) ((uint32) 0x00000001u << TX_CAN_RX_WPNL_SHIFT)) | \
            ((uint32) ((uint32) 0x00000001u << (TX_CAN_TWO_BYTE_OFFSET + TX_CAN_RX_WPNH_SHIFT))))
#else  /* CY_PSOC4 */
    #define TX_CAN_TX_WPN_SET         (((uint32) ((uint32) 0x00000001u << TX_CAN_TX_WPNL_SHIFT)) | \
            ((uint32) ((uint32) 0x00000001u << TX_CAN_TX_WPNH_SHIFT)))
    #define TX_CAN_RX_WPN_SET         (((uint32) ((uint32) 0x00000001u << TX_CAN_RX_WPNL_SHIFT)) | \
            ((uint32) ((uint32) 0x00000001u << TX_CAN_RX_WPNH_SHIFT)))

    /* CAN IP Block Enable */
    #define TX_CAN_IP_ENABLE_SHIFT    (31u)
    #define TX_CAN_IP_ENABLE          ((uint32) ((uint32) 0x00000001u << TX_CAN_IP_ENABLE_SHIFT))

    /* Error Capture register mode setting */
    #define TX_CAN_ECR_FREE_RUNNING   (0x00u)
    #define TX_CAN_ECR_ERROR_CAPTURE  (0x01u)

    /* Swap Endian */
    #define TX_CAN_SWAP_ENDIANNESS_DISABLE  (0x00u)
    #define TX_CAN_SWAP_ENDIANNESS_ENABLE   (0x01u)
#endif /* (CY_PSOC3 || CY_PSOC5) */

/* TX send message */
#define TX_CAN_TX_REQUEST_PENDING     (0x01u)
#define TX_CAN_RETRY_NUMBER           (0x03u)
#define TX_CAN_SEND_MESSAGE_SHIFT     (0u)
#define TX_CAN_SEND_MESSAGE           ((uint32) ((uint32) 0x00000001u << TX_CAN_SEND_MESSAGE_SHIFT))

/* Offsets to maintain bytes within uint32 */
#define TX_CAN_ONE_BYTE_OFFSET        (8u)
#define TX_CAN_TWO_BYTE_OFFSET        (16u)
#define TX_CAN_THREE_BYTE_OFFSET      (24u)

#if (CY_PSOC3 || CY_PSOC5)
    /* Set/Clear bits macro for TX_CAN_RX mailbox(i) */
    /* Bit 0 within RX_CMD[i] */
    #define TX_CAN_RX_ACK_MSG_SHIFT       (0u)
    #define TX_CAN_RX_ACK_MSG             ((uint8) ((uint8) 0x01u << TX_CAN_RX_ACK_MSG_SHIFT))
    /* Bit 2 within RX_CMD[i] */
    #define TX_CAN_RX_RTR_ABORT_SHIFT     (2u)
    #define TX_CAN_RX_RTR_ABORT_MASK      ((uint8) ((uint8) 0x01u << TX_CAN_RX_RTR_ABORT_SHIFT))
    /* Bit 3 within RX_CMD[i] */
    #define TX_CAN_RX_BUF_ENABLE_SHIFT    (3u)
    #define TX_CAN_RX_BUF_ENABLE_MASK     ((uint8) ((uint8) 0x01u << TX_CAN_RX_BUF_ENABLE_SHIFT))
    /* Bit 4 within RX_CMD[i] */
    #define TX_CAN_RX_RTRREPLY_SHIFT      (4u)
    #define TX_CAN_RX_RTRREPLY_MASK       ((uint8) ((uint8) 0x01u << TX_CAN_RX_RTRREPLY_SHIFT))
    /* Bit 5 within RX_CMD[i] */
    #define TX_CAN_RX_INT_ENABLE_SHIFT    (5u)
    #define TX_CAN_RX_INT_ENABLE_MASK     ((uint8) ((uint8) 0x01u << TX_CAN_RX_INT_ENABLE_SHIFT))
    /* Bit 6 within RX_CMD[i] */
    #define TX_CAN_RX_LINKING_SHIFT       (6u)
    #define TX_CAN_RX_LINKING_MASK        ((uint8) ((uint8) 0x01u << TX_CAN_RX_LINKING_SHIFT))
    /* Bit 7 within RX_CMD[i] */
    #define TX_CAN_RX_WPNL_SHIFT          (7u)
    #define TX_CAN_RX_WPNL_MASK           ((uint8) ((uint8) 0x01u << TX_CAN_RX_WPNL_SHIFT))
    /* Bits 19-16 within RX_CMD[i] */
    #define TX_CAN_RX_DLC_VALUE_SHIFT     (0u)
    #define TX_CAN_RX_DLC_VALUE_MASK      ((uint8) ((uint8) 0x0Fu << TX_CAN_RX_DLC_VALUE_SHIFT))
    /* Bit 20 within RX_CMD[i] */
    #define TX_CAN_RX_IDE_SHIFT           (4u)
    #define TX_CAN_RX_IDE_MASK            ((uint8) ((uint8) 0x01u << TX_CAN_RX_IDE_SHIFT))
    /* Bit 23 within RX_CMD[i] */
    #define TX_CAN_RX_WPNH_SHIFT          (7u)
    #define TX_CAN_RX_WPNH_MASK           ((uint8) ((uint8) 0x01u << TX_CAN_RX_WPNH_SHIFT))

    #define TX_CAN_RX_ACK_MESSAGE(i)    (TX_CAN_RX[i].rxcmd.byte[0u] |= TX_CAN_RX_ACK_MSG)
    #define TX_CAN_RX_RTR_ABORT_MESSAGE(i) \
            (TX_CAN_RX[i].rxcmd.byte[0u] |= TX_CAN_RX_RTR_ABORT_MASK)
    #define TX_CAN_RX_BUF_ENABLE(i)      \
            (TX_CAN_RX[i].rxcmd.byte[0u] |= TX_CAN_RX_BUF_ENABLE_MASK)
    #define TX_CAN_RX_BUF_DISABLE(i)     \
            (TX_CAN_RX[i].rxcmd.byte[0u] &= (uint8) (~TX_CAN_RX_BUF_ENABLE_MASK))
    #define TX_CAN_SET_RX_RTRREPLY(i)    \
            (TX_CAN_RX[i].rxcmd.byte[0u] |= TX_CAN_RX_RTRREPLY_MASK)
    #define TX_CAN_CLEAR_RX_RTRREPLY(i)  \
            (TX_CAN_RX[i].rxcmd.byte[0u] &= (uint8) (~TX_CAN_RX_RTRREPLY_MASK))
    #define TX_CAN_RX_INT_ENABLE(i)      \
            (TX_CAN_RX[i].rxcmd.byte[0u] |= TX_CAN_RX_INT_ENABLE_MASK)
    #define TX_CAN_RX_INT_DISABLE(i)     \
            (TX_CAN_RX[i].rxcmd.byte[0u] &= (uint8) (~TX_CAN_RX_INT_ENABLE_MASK))
    #define TX_CAN_SET_RX_LINKING(i)     \
            (TX_CAN_RX[i].rxcmd.byte[0u] |= TX_CAN_RX_LINKING_MASK)
    #define TX_CAN_CLEAR_RX_LINKING(i)   \
            (TX_CAN_RX[i].rxcmd.byte[0u] &= (uint8) (~TX_CAN_RX_LINKING_MASK))
    #define TX_CAN_SET_RX_WNPL(i)     (TX_CAN_RX[i].rxcmd.byte[0u] |= TX_CAN_RX_WPNL_MASK)
    #define TX_CAN_CLEAR_RX_WNPL(i)      \
            (TX_CAN_RX[i].rxcmd.byte[0u] &= (uint8) (~TX_CAN_RX_WPNL_MASK))
    #define TX_CAN_SET_RX_WNPH(i)     (TX_CAN_RX[i].rxcmd.byte[2u] |= TX_CAN_RX_WPNH_MASK)
    #define TX_CAN_CLEAR_RX_WNPH(i)      \
            (TX_CAN_RX[i].rxcmd.byte[2u] &= (uint8) (~TX_CAN_RX_WPNH_MASK))
    #define TX_CAN_GET_DLC(i)            \
            (TX_CAN_RX[i].rxcmd.byte[2u] & TX_CAN_RX_DLC_VALUE_MASK)
    #define TX_CAN_GET_RX_IDE(i)         ((uint8) \
            (TX_CAN_RX[i].rxcmd.byte[2u] & TX_CAN_RX_IDE_MASK) >> TX_CAN_RX_IDE_SHIFT)
    #define TX_CAN_GET_RX_ID(i)          ((TX_CAN_GET_RX_IDE(i)) ? \
            (CY_GET_REG32(TX_CAN_RX_ID_PTR(i)) >> TX_CAN_SET_TX_ID_EXTENDED_MSG_SHIFT) : \
            (CY_GET_REG32(TX_CAN_RX_ID_PTR(i)) >> TX_CAN_SET_TX_ID_STANDARD_MSG_SHIFT))

    /* Set/Clear bits macro for TX_CAN_TX mailbox(i) */
    /* Bit 0 within TX_CMD[i] */
    #define TX_CAN_TX_TRANSMIT_REQUEST_SHIFT (0u)
    #define TX_CAN_TX_TRANSMIT_REQUEST ((uint8) ((uint8) 0x01u << TX_CAN_TX_TRANSMIT_REQUEST_SHIFT))
    /* Bit 1 within TX_CMD[i] */
    #define TX_CAN_TX_ABORT_SHIFT        (1u)
    #define TX_CAN_TX_ABORT_MASK         ((uint8) ((uint8) 0x01u << TX_CAN_TX_ABORT_SHIFT))
    /* Bit 2 within TX_CMD[i] */
    #define TX_CAN_TRANSMIT_INT_ENABLE   (0x01u)
    #define TX_CAN_TRANSMIT_INT_DISABLE  (0x00u)
    #define TX_CAN_TX_INT_ENABLE_SHIFT   (2u)
    #define TX_CAN_TX_INT_ENABLE_MASK    \
            ((uint32) ((uint32) 0x00000001u << TX_CAN_TX_INT_ENABLE_SHIFT))
    /* Bit 3 within TX_CMD[i] */
    #define TX_CAN_TX_WPNL_SHIFT         (3u)
    #define TX_CAN_TX_WPNL_MASK          ((uint8) ((uint8) 0x01u << TX_CAN_TX_WPNL_SHIFT))
    /* Bits 19-16 within TX_CMD[i] */
    #define TX_CAN_TX_DLC_VALUE_SHIFT    (0u)
    #define TX_CAN_TX_DLC_UPPER_VALUE_SHIFT (19u)
    #define TX_CAN_TX_DLC_UPPER_VALUE    \
            ((uint32) ((uint32) 0x00000001u << TX_CAN_TX_DLC_UPPER_VALUE_SHIFT))
    #define TX_CAN_TX_DLC_VALUE_MASK     ((uint8) ((uint8) 0x0Fu << TX_CAN_TX_DLC_VALUE_SHIFT))
    #define TX_CAN_TX_DLC_MAX_VALUE      (8u)
    /* Bit 20 within TX_CMD[i] */
    #define TX_CAN_TX_IDE_SHIFT          (20u)
    #define TX_CAN_TX_IDE_MASK           ((uint32) ((uint32) 0x00000001u << TX_CAN_TX_IDE_SHIFT))
    /* Bit 21 within TX_CMD[i] */
    #define TX_CAN_TX_RTR_SHIFT          (21u)
    #define TX_CAN_TX_RTR_MASK           ((uint32) ((uint32) 0x00000001u <<  TX_CAN_TX_RTR_SHIFT))
    /* Bit 23 within TX_CMD[i] */
    #define TX_CAN_TX_WPNH_SHIFT         (7u)
    #define TX_CAN_TX_WPNH_MASK          ((uint8) ((uint8) 0x01u << TX_CAN_TX_WPNH_SHIFT))

    #define TX_CAN_TX_TRANSMIT_MESSAGE(i) \
            (TX_CAN_TX[i].txcmd.byte[0u] |= TX_CAN_TX_TRANSMIT_REQUEST)
    #define TX_CAN_TX_ABORT_MESSAGE(i)   \
            (TX_CAN_TX[i].txcmd.byte[0u] = (TX_CAN_TX[i].txcmd.byte[0u] & \
            (uint8) (~TX_CAN_TX_TRANSMIT_REQUEST)) | TX_CAN_TX_ABORT_MASK)
    #define TX_CAN_TX_INT_ENABLE(i)      \
            (TX_CAN_TX[i].txcmd.byte[0u] |= (uint8) TX_CAN_TX_INT_ENABLE_MASK)
    #define TX_CAN_TX_INT_DISABLE(i)     \
            (TX_CAN_TX[i].txcmd.byte[0u] &= (uint8) (~TX_CAN_TX_INT_ENABLE_MASK))
    #define TX_CAN_SET_TX_WNPL(i)        \
            (TX_CAN_TX[i].txcmd.byte[0u] |= TX_CAN_TX_WPNL_MASK)
    #define TX_CAN_CLEAR_TX_WNPL(i)      \
            (TX_CAN_TX[i].txcmd.byte[0u] &= (uint8) (~TX_CAN_TX_WPNL_MASK))
    #define TX_CAN_SET_TX_IDE(i)         (TX_CAN_TX[i].txcmd.byte[2u] |= \
            (uint8) (TX_CAN_TX_IDE_MASK >> TX_CAN_TWO_BYTE_OFFSET))
    #define TX_CAN_CLEAR_TX_IDE(i)       (TX_CAN_TX[i].txcmd.byte[2u] &= \
            (uint8) (((uint32) (~TX_CAN_TX_IDE_MASK)) >> TX_CAN_TWO_BYTE_OFFSET))
    #define TX_CAN_SET_TX_RTR(i)         (TX_CAN_TX[i].txcmd.byte[2u] |= \
            (uint8) (TX_CAN_TX_RTR_MASK >> TX_CAN_TWO_BYTE_OFFSET))
    #define TX_CAN_CLEAR_TX_RTR(i)       (TX_CAN_TX[i].txcmd.byte[2u] &= \
            (uint8) (((uint32) (~TX_CAN_TX_RTR_MASK)) >> TX_CAN_TWO_BYTE_OFFSET))
    #define TX_CAN_SET_TX_WNPH(i)        \
            (TX_CAN_TX[i].txcmd.byte[2u] |= TX_CAN_TX_WPNH_MASK)
    #define TX_CAN_CLEAR_TX_WNPH(i)      \
            (TX_CAN_TX[i].txcmd.byte[2u] &= (uint8) (~TX_CAN_TX_WPNH_MASK))

    #define TX_CAN_RX_DATA_BYTE(mailbox, i) (TX_CAN_RX[mailbox].rxdata.byte[((i) > 3u) ? \
                                                      (7u - ((i) - 4u)) : (3u - (i))])
    #define TX_CAN_TX_DATA_BYTE(mailbox, i) (TX_CAN_TX[mailbox].txdata.byte[((i) > 3u) ? \
                                                      (7u - ((i) - 4u)) : (3u - (i))])
#else  /* CY_PSOC4 */
    /* Set/Clear bits macro for TX_CAN_RX mailbox(i) */
    /* Bit 0 within RX_CMD[i] */
    #define TX_CAN_RX_ACK_MSG_SHIFT       (0u)
    #define TX_CAN_RX_ACK_MSG             ((uint32) ((uint32) 0x01u << TX_CAN_RX_ACK_MSG_SHIFT))
    /* Bit 2 within RX_CMD[i] */
    #define TX_CAN_RX_RTR_ABORT_SHIFT     (2u)
    #define TX_CAN_RX_RTR_ABORT_MASK      ((uint32) ((uint32) 0x01u << TX_CAN_RX_RTR_ABORT_SHIFT))
    /* Bit 3 within RX_CMD[i] */
    #define TX_CAN_RX_BUF_ENABLE_SHIFT    (3u)
    #define TX_CAN_RX_BUF_ENABLE_MASK     ((uint32) ((uint32) 0x01u << TX_CAN_RX_BUF_ENABLE_SHIFT))
    /* Bit 4 within RX_CMD[i] */
    #define TX_CAN_RX_RTRREPLY_SHIFT      (4u)
    #define TX_CAN_RX_RTRREPLY_MASK       ((uint32) ((uint32) 0x01u << TX_CAN_RX_RTRREPLY_SHIFT))
    /* Bit 5 within RX_CMD[i] */
    #define TX_CAN_RX_INT_ENABLE_SHIFT    (5u)
    #define TX_CAN_RX_INT_ENABLE_MASK     ((uint32) ((uint32) 0x01u << TX_CAN_RX_INT_ENABLE_SHIFT))
    /* Bit 6 within RX_CMD[i] */
    #define TX_CAN_RX_LINKING_SHIFT       (6u)
    #define TX_CAN_RX_LINKING_MASK        ((uint32) ((uint32) 0x01u << TX_CAN_RX_LINKING_SHIFT))
    /* Bit 7 within RX_CMD[i] */
    #define TX_CAN_RX_WPNL_SHIFT          (7u)
    #define TX_CAN_RX_WPNL_MASK           ((uint32) ((uint32) 0x01u << TX_CAN_RX_WPNL_SHIFT))
    /* Bits 19-16 within RX_CMD[i] */
    #define TX_CAN_RX_DLC_VALUE_SHIFT     (16u)
    #define TX_CAN_RX_DLC_VALUE_MASK      ((uint32) ((uint32) 0x0Fu << TX_CAN_RX_DLC_VALUE_SHIFT))
    /* Bit 20 within RX_CMD[i] */
    #define TX_CAN_RX_IDE_SHIFT           (20u)
    #define TX_CAN_RX_IDE_MASK            ((uint32) ((uint32) 0x01u << TX_CAN_RX_IDE_SHIFT))
    /* Bit 23 within RX_CMD[i] */
    #define TX_CAN_RX_WPNH_SHIFT          (23u)
    #define TX_CAN_RX_WPNH_MASK           ((uint32) ((uint32) 0x01u << TX_CAN_RX_WPNH_SHIFT))

    #define TX_CAN_RX_ACK_MESSAGE(i)       (TX_CAN_RX_CMD_REG(i) |= TX_CAN_RX_ACK_MSG)
    #define TX_CAN_RX_RTR_ABORT_MESSAGE(i) (TX_CAN_RX_CMD_REG(i) |= \
                                                     TX_CAN_RX_RTR_ABORT_MASK)
    #define TX_CAN_RX_BUF_ENABLE(i)      (TX_CAN_RX_CMD_REG(i) |= \
                                                   TX_CAN_RX_BUF_ENABLE_MASK)
    #define TX_CAN_RX_BUF_DISABLE(i)     (TX_CAN_RX_CMD_REG(i) &= \
                                                   (uint32) (~TX_CAN_RX_BUF_ENABLE_MASK))
    #define TX_CAN_SET_RX_RTRREPLY(i)    (TX_CAN_RX_CMD_REG(i) |= \
                                                   TX_CAN_RX_RTRREPLY_MASK)
    #define TX_CAN_CLEAR_RX_RTRREPLY(i)  (TX_CAN_RX_CMD_REG(i) &= \
                                                   (uint32) (~TX_CAN_RX_RTRREPLY_MASK))
    #define TX_CAN_RX_INT_ENABLE(i)      (TX_CAN_RX_CMD_REG(i) |= \
                                                   TX_CAN_RX_INT_ENABLE_MASK)
    #define TX_CAN_RX_INT_DISABLE(i)     (TX_CAN_RX_CMD_REG(i) &= \
                                                   (uint32) (~TX_CAN_RX_INT_ENABLE_MASK))
    #define TX_CAN_SET_RX_LINKING(i)     (TX_CAN_RX_CMD_REG(i) |= TX_CAN_RX_LINKING_MASK)
    #define TX_CAN_CLEAR_RX_LINKING(i)   (TX_CAN_RX_CMD_REG(i) &= \
                                                   (uint32) (~TX_CAN_RX_LINKING_MASK))
    #define TX_CAN_SET_RX_WNPL(i)        (TX_CAN_RX_CMD_REG(i) |= TX_CAN_RX_WPNL_MASK)
    #define TX_CAN_CLEAR_RX_WNPL(i)      (TX_CAN_RX_CMD_REG(i) &= \
                                                   (uint32) (~TX_CAN_RX_WPNL_MASK))
    #define TX_CAN_SET_RX_WNPH(i)        (TX_CAN_RX_CMD_REG(i) |= TX_CAN_RX_WPNH_MASK)
    #define TX_CAN_CLEAR_RX_WNPH(i)      (TX_CAN_RX_CMD_REG(i) &= \
                                                   (uint32) (~TX_CAN_RX_WPNH_MASK))
    #define TX_CAN_GET_DLC(i)            ((uint32) ((TX_CAN_RX_CMD_REG(i) & \
            TX_CAN_RX_DLC_VALUE_MASK) >> TX_CAN_RX_DLC_VALUE_SHIFT))
    #define TX_CAN_GET_RX_IDE(i)         ((uint32) ((TX_CAN_RX_CMD_REG(i) & \
            TX_CAN_RX_IDE_MASK) >> TX_CAN_RX_IDE_SHIFT))
    #define TX_CAN_GET_RX_ID(i)          ((TX_CAN_GET_RX_IDE(i) == 0u) ? \
            (TX_CAN_RX_ID_REG(i) >> TX_CAN_SET_TX_ID_STANDARD_MSG_SHIFT) : \
            (TX_CAN_RX_ID_REG(i) >> TX_CAN_SET_TX_ID_EXTENDED_MSG_SHIFT))

    /* Set/Clear bits macro for TX_CAN_TX mailbox(i) */
    /* Bit 0 within TX_CMD[i] */
    #define TX_CAN_TX_TRANSMIT_REQUEST_SHIFT (0u)
    #define TX_CAN_TX_TRANSMIT_REQUEST   \
            ((uint32) ((uint32) 0x01u << TX_CAN_TX_TRANSMIT_REQUEST_SHIFT))
    /* Bit 1 within TX_CMD[i] */
    #define TX_CAN_TX_ABORT_SHIFT        (1u)
    #define TX_CAN_TX_ABORT_MASK         ((uint32) ((uint32) 0x01u << TX_CAN_TX_ABORT_SHIFT))
    /* Bit 2 within TX_CMD[i] */
    #define TX_CAN_TRANSMIT_INT_ENABLE   (0x01u)
    #define TX_CAN_TRANSMIT_INT_DISABLE  (0x00u)
    #define TX_CAN_TX_INT_ENABLE_SHIFT   (2u)
    #define TX_CAN_TX_INT_ENABLE_MASK    \
            ((uint32) ((uint32) 0x00000001u << TX_CAN_TX_INT_ENABLE_SHIFT))
    /* Bit 3 within TX_CMD[i] */
    #define TX_CAN_TX_WPNL_SHIFT         (3u)
    #define TX_CAN_TX_WPNL_MASK          ((uint32) ((uint32) 0x01u << TX_CAN_TX_WPNL_SHIFT))
    /* Bits 19-16 within TX_CMD[i] */
    #define TX_CAN_TX_DLC_VALUE_SHIFT    (0u)
    #define TX_CAN_TX_DLC_UPPER_VALUE_SHIFT (19u)
    #define TX_CAN_TX_DLC_UPPER_VALUE    \
            ((uint32) ((uint32) 0x00000001u << TX_CAN_TX_DLC_UPPER_VALUE_SHIFT))
    #define TX_CAN_TX_DLC_VALUE_MASK     ((uint32) ((uint32) 0x0Fu << TX_CAN_TX_DLC_VALUE_SHIFT))
    #define TX_CAN_TX_DLC_MAX_VALUE      (8u)
    /* Bit 20 within TX_CMD[i] */
    #define TX_CAN_TX_IDE_SHIFT          (20u)
    #define TX_CAN_TX_IDE_MASK           ((uint32) ((uint32) 0x00000001u << TX_CAN_TX_IDE_SHIFT))
    /* Bit 21 within TX_CMD[i] */
    #define TX_CAN_TX_RTR_SHIFT          (21u)
    #define TX_CAN_TX_RTR_MASK           ((uint32) ((uint32) 0x00000001u <<  TX_CAN_TX_RTR_SHIFT))
    /* Bit 23 within TX_CMD[i] */
    #define TX_CAN_TX_WPNH_SHIFT         (23u)
    #define TX_CAN_TX_WPNH_MASK          ((uint32) ((uint32) 0x01u << TX_CAN_TX_WPNH_SHIFT))

    #define TX_CAN_TX_TRANSMIT_MESSAGE(i) \
            (TX_CAN_TX_CMD_REG(i) |= TX_CAN_TX_TRANSMIT_REQUEST)
    #define TX_CAN_TX_ABORT_MESSAGE(i) (TX_CAN_TX_CMD_REG(i) = (TX_CAN_TX_CMD_REG(i) & \
            (uint32) (~TX_CAN_TX_TRANSMIT_REQUEST)) | TX_CAN_TX_ABORT_MASK)
    #define TX_CAN_TX_INT_ENABLE(i)    (TX_CAN_TX_CMD_REG(i) |= TX_CAN_TX_INT_ENABLE_MASK)
    #define TX_CAN_TX_INT_DISABLE(i)   (TX_CAN_TX_CMD_REG(i) &= \
                                                 (uint32) (~TX_CAN_TX_INT_ENABLE_MASK))
    #define TX_CAN_SET_TX_WNPL(i)     (TX_CAN_TX_CMD_REG(i) |= TX_CAN_TX_WPNL_MASK)
    #define TX_CAN_CLEAR_TX_WNPL(i)   \
            (TX_CAN_TX_CMD_REG(i) &= (uint32)(~TX_CAN_TX_WPNL_MASK))
    #define TX_CAN_SET_TX_IDE(i)      (TX_CAN_TX_CMD_REG(i) |= TX_CAN_TX_IDE_MASK)
    #define TX_CAN_CLEAR_TX_IDE(i)    \
            (TX_CAN_TX_CMD_REG(i) &= (uint32) (~TX_CAN_TX_IDE_MASK))
    #define TX_CAN_SET_TX_RTR(i)      (TX_CAN_TX_CMD_REG(i) |= TX_CAN_TX_RTR_MASK)
    #define TX_CAN_CLEAR_TX_RTR(i)    \
            (TX_CAN_TX_CMD_REG(i) &= (uint32) (~TX_CAN_TX_RTR_MASK))
    #define TX_CAN_SET_TX_WNPH(i)     (TX_CAN_TX_CMD_REG(i) |= TX_CAN_TX_WPNH_MASK)
    #define TX_CAN_CLEAR_TX_WNPH(i)   \
            (TX_CAN_TX_CMD_REG(i) &= (uint32)(~TX_CAN_TX_WPNH_MASK))

    #define TX_CAN_DATA_HIGH_ADDR     (4u)
    #define TX_CAN_DATA_BYTE_MASK     ((uint32) 0xFFu)

    #define TX_CAN_RX_DATA_BYTE(mailbox, i) (((i) > 3u) ? \
            (uint8) (TX_CAN_RX_DATA_HI_REG(mailbox) >> ((7u - (i)) * TX_CAN_ONE_BYTE_OFFSET)) : \
            (uint8) (TX_CAN_RX_DATA_LO_REG(mailbox) >> ((3u - (i)) * TX_CAN_ONE_BYTE_OFFSET)))

    #define TX_CAN_TX_DATA_BYTE(mailbox, i, byte) (((i) > 3u) ? \
        (TX_CAN_TX_DATA_HI_REG(mailbox) = (TX_CAN_TX_DATA_HI_REG(mailbox) & \
        (uint32) (~((uint32) (TX_CAN_DATA_BYTE_MASK << ((7u - (i)) * TX_CAN_ONE_BYTE_OFFSET))))) | \
        (uint32) ((uint32) (byte) << ((7u - (i)) * TX_CAN_ONE_BYTE_OFFSET))) : \
        (TX_CAN_TX_DATA_LO_REG(mailbox) = (TX_CAN_TX_DATA_LO_REG(mailbox) & \
        (uint32) (~((uint32) (TX_CAN_DATA_BYTE_MASK << ((3u - (i)) * TX_CAN_ONE_BYTE_OFFSET))))) | \
        (uint32) ((uint32) (byte) << ((3u - (i)) * TX_CAN_ONE_BYTE_OFFSET))))
#endif /* CY_PSOC3 || CY_PSOC5 */

#if (CY_PSOC3 || CY_PSOC5)
    #define TX_CAN_DATA_BYTE_1            (3u)
    #define TX_CAN_DATA_BYTE_2            (2u)
    #define TX_CAN_DATA_BYTE_3            (1u)
    #define TX_CAN_DATA_BYTE_4            (0u)
    #define TX_CAN_DATA_BYTE_5            (7u)
    #define TX_CAN_DATA_BYTE_6            (6u)
    #define TX_CAN_DATA_BYTE_7            (5u)
    #define TX_CAN_DATA_BYTE_8            (4u)

    /* Macros for access to RX DATA for mailbox(i) */
    #define TX_CAN_RX_DATA_BYTE1(i)       TX_CAN_RX[i].rxdata.byte[TX_CAN_DATA_BYTE_1]
    #define TX_CAN_RX_DATA_BYTE2(i)       TX_CAN_RX[i].rxdata.byte[TX_CAN_DATA_BYTE_2]
    #define TX_CAN_RX_DATA_BYTE3(i)       TX_CAN_RX[i].rxdata.byte[TX_CAN_DATA_BYTE_3]
    #define TX_CAN_RX_DATA_BYTE4(i)       TX_CAN_RX[i].rxdata.byte[TX_CAN_DATA_BYTE_4]
    #define TX_CAN_RX_DATA_BYTE5(i)       TX_CAN_RX[i].rxdata.byte[TX_CAN_DATA_BYTE_5]
    #define TX_CAN_RX_DATA_BYTE6(i)       TX_CAN_RX[i].rxdata.byte[TX_CAN_DATA_BYTE_6]
    #define TX_CAN_RX_DATA_BYTE7(i)       TX_CAN_RX[i].rxdata.byte[TX_CAN_DATA_BYTE_7]
    #define TX_CAN_RX_DATA_BYTE8(i)       TX_CAN_RX[i].rxdata.byte[TX_CAN_DATA_BYTE_8]

    /* Macros for access to TX DATA for mailbox(i) */
    #define TX_CAN_TX_DATA_BYTE1(i)       TX_CAN_TX[i].txdata.byte[TX_CAN_DATA_BYTE_1]
    #define TX_CAN_TX_DATA_BYTE2(i)       TX_CAN_TX[i].txdata.byte[TX_CAN_DATA_BYTE_2]
    #define TX_CAN_TX_DATA_BYTE3(i)       TX_CAN_TX[i].txdata.byte[TX_CAN_DATA_BYTE_3]
    #define TX_CAN_TX_DATA_BYTE4(i)       TX_CAN_TX[i].txdata.byte[TX_CAN_DATA_BYTE_4]
    #define TX_CAN_TX_DATA_BYTE5(i)       TX_CAN_TX[i].txdata.byte[TX_CAN_DATA_BYTE_5]
    #define TX_CAN_TX_DATA_BYTE6(i)       TX_CAN_TX[i].txdata.byte[TX_CAN_DATA_BYTE_6]
    #define TX_CAN_TX_DATA_BYTE7(i)       TX_CAN_TX[i].txdata.byte[TX_CAN_DATA_BYTE_7]
    #define TX_CAN_TX_DATA_BYTE8(i)       TX_CAN_TX[i].txdata.byte[TX_CAN_DATA_BYTE_8]
#else  /* CY_PSOC4 */
    /* Macros for access to RX DATA for mailbox(i) */
    #define TX_CAN_RX_DATA_BYTE1(i)       \
            ((uint8) (TX_CAN_RX_DATA_LO_REG(i) >> TX_CAN_THREE_BYTE_OFFSET))
    #define TX_CAN_RX_DATA_BYTE2(i)       \
            ((uint8) (TX_CAN_RX_DATA_LO_REG(i) >> TX_CAN_TWO_BYTE_OFFSET))
    #define TX_CAN_RX_DATA_BYTE3(i)       \
            ((uint8) (TX_CAN_RX_DATA_LO_REG(i) >> TX_CAN_ONE_BYTE_OFFSET))
    #define TX_CAN_RX_DATA_BYTE4(i)       ((uint8) TX_CAN_RX_DATA_LO_REG(i))
    #define TX_CAN_RX_DATA_BYTE5(i)       \
            ((uint8) (TX_CAN_RX_DATA_HI_REG(i) >> TX_CAN_THREE_BYTE_OFFSET))
    #define TX_CAN_RX_DATA_BYTE6(i)       \
            ((uint8) (TX_CAN_RX_DATA_HI_REG(i) >> TX_CAN_TWO_BYTE_OFFSET))
    #define TX_CAN_RX_DATA_BYTE7(i)       \
            ((uint8) (TX_CAN_RX_DATA_HI_REG(i) >> TX_CAN_ONE_BYTE_OFFSET))
    #define TX_CAN_RX_DATA_BYTE8(i)       ((uint8) TX_CAN_RX_DATA_HI_REG(i))

    /* Macros for access to TX DATA for mailbox(i) */
    #define TX_CAN_TX_DATA_BYTE1(i, byte) \
            (TX_CAN_TX_DATA_LO_REG(i) = (TX_CAN_TX_DATA_LO_REG(i) & \
            (uint32) (~((uint32) (TX_CAN_DATA_BYTE_MASK << TX_CAN_THREE_BYTE_OFFSET)))) | \
            (uint32) ((uint32) (byte) << TX_CAN_THREE_BYTE_OFFSET))
    #define TX_CAN_TX_DATA_BYTE2(i, byte) \
            (TX_CAN_TX_DATA_LO_REG(i) = (TX_CAN_TX_DATA_LO_REG(i) & \
            (uint32) (~((uint32) (TX_CAN_DATA_BYTE_MASK << TX_CAN_TWO_BYTE_OFFSET)))) | \
            (uint32) ((uint32) (byte) << TX_CAN_TWO_BYTE_OFFSET))
    #define TX_CAN_TX_DATA_BYTE3(i, byte) \
            (TX_CAN_TX_DATA_LO_REG(i) = (TX_CAN_TX_DATA_LO_REG(i) & \
            (uint32) (~((uint32) (TX_CAN_DATA_BYTE_MASK << TX_CAN_ONE_BYTE_OFFSET)))) | \
            (uint32) ((uint32) (byte) << TX_CAN_ONE_BYTE_OFFSET))
    #define TX_CAN_TX_DATA_BYTE4(i, byte) \
            (TX_CAN_TX_DATA_LO_REG(i) = (TX_CAN_TX_DATA_LO_REG(i) & \
            (uint32) (~TX_CAN_DATA_BYTE_MASK)) | (uint32) (byte))
    #define TX_CAN_TX_DATA_BYTE5(i, byte) \
            (TX_CAN_TX_DATA_HI_REG(i) = (TX_CAN_TX_DATA_HI_REG(i) & \
            (uint32) (~((uint32) (TX_CAN_DATA_BYTE_MASK << TX_CAN_THREE_BYTE_OFFSET)))) | \
            (uint32) ((uint32) (byte) << TX_CAN_THREE_BYTE_OFFSET))
    #define TX_CAN_TX_DATA_BYTE6(i, byte) \
            (TX_CAN_TX_DATA_HI_REG(i) = (TX_CAN_TX_DATA_HI_REG(i) & \
            (uint32) (~((uint32) (TX_CAN_DATA_BYTE_MASK << TX_CAN_TWO_BYTE_OFFSET)))) | \
            (uint32) ((uint32) (byte) << TX_CAN_TWO_BYTE_OFFSET))
    #define TX_CAN_TX_DATA_BYTE7(i, byte) \
            (TX_CAN_TX_DATA_HI_REG(i) = (TX_CAN_TX_DATA_HI_REG(i) & \
            (uint32) (~((uint32) (TX_CAN_DATA_BYTE_MASK << TX_CAN_ONE_BYTE_OFFSET)))) | \
            (uint32) ((uint32) (byte) << TX_CAN_ONE_BYTE_OFFSET))
    #define TX_CAN_TX_DATA_BYTE8(i, byte) \
            (TX_CAN_TX_DATA_HI_REG(i) = (TX_CAN_TX_DATA_HI_REG(i) & \
            (uint32) (~TX_CAN_DATA_BYTE_MASK)) | (uint32) (byte))
#endif /* CY_PSOC3 || CY_PSOC5 */

/* Macros for setting Tx Msg Identifier in TX_CAN_TX_ID register */
#define TX_CAN_SET_TX_ID_STANDARD_MSG_SHIFT  (21u)
#define TX_CAN_SET_TX_ID_EXTENDED_MSG_SHIFT  (3u)
#define TX_CAN_SET_TX_ID_STANDARD_MSG(i, id) (CY_SET_REG32(TX_CAN_TX_ID_PTR(i), \
        (uint32) ((uint32) (id) << TX_CAN_SET_TX_ID_STANDARD_MSG_SHIFT)))
#define TX_CAN_SET_TX_ID_EXTENDED_MSG(i, id) (CY_SET_REG32(TX_CAN_TX_ID_PTR(i), \
        (uint32) ((uint32) (id) << TX_CAN_SET_TX_ID_EXTENDED_MSG_SHIFT)))

/* Mask for bits within TX_CAN_CSR_CFG */
#define TX_CAN_EDGE_MODE_SHIFT           (0u)
/* Bit 0 within CSR_CFG */
#define TX_CAN_EDGE_MODE_MASK            ((uint8) ((uint8) 0x01u << TX_CAN_EDGE_MODE_SHIFT))
#define TX_CAN_SAMPLE_MODE_SHIFT         (1u)
/* Bit 1 within CSR_CFG */
#define TX_CAN_SAMPLE_MODE_MASK          ((uint8) ((uint8) 0x01u << TX_CAN_SAMPLE_MODE_SHIFT))
#define TX_CAN_CFG_REG_SJW_SHIFT         (2u)
/* Bits 3-2 within CSR_CFG */
#define TX_CAN_CFG_REG_SJW_MASK          ((uint8) ((uint8) 0x03u << TX_CAN_CFG_REG_SJW_SHIFT))
#define TX_CAN_CFG_REG_SJW_LOWER_LIMIT   (0x03u)  /* the lowest allowed value of cfg_sjw */
#define TX_CAN_RESET_SHIFT               (4u)
/* Bit 4 within CSR_CFG    */
#define TX_CAN_RESET_MASK                ((uint8) ((uint8) 0x01u << TX_CAN_RESET_SHIFT))
#define TX_CAN_CFG_REG_TSEG2_SHIFT       (5u)
/* Bits 7-5 within CSR_CFG */
#define TX_CAN_CFG_REG_TSEG2_MASK        ((uint8) ((uint8) 0x07u << TX_CAN_CFG_REG_TSEG2_SHIFT))
/* Highest allowed value of cfg_tseg2 */
#define TX_CAN_CFG_REG_TSEG2_UPPER_LIMIT (0x07u)
/* Lowest allowed value of cfg_tseg2 */
#define TX_CAN_CFG_REG_TSEG2_LOWER_LIMIT (0x02u)
/* Lowest allowed value of cfg_tseg2 if sample point is one point */
#define TX_CAN_CFG_REG_TSEG2_EXCEPTION   (0x01u)
/* Bits 11-8 within CSR_CFG */
#define TX_CAN_CFG_REG_TSEG1_SHIFT       (8u)
#define TX_CAN_CFG_REG_TSEG1_MASK        (0x0Fu)
/* Highest allowed value of cfg_tseg1 */
#define TX_CAN_CFG_REG_TSEG1_UPPER_LIMIT (0x0Fu)
/* Lowest allowed value of cfg_tseg1 */
#define TX_CAN_CFG_REG_TSEG1_LOWER_LIMIT (0x02u)
#define TX_CAN_ARBITER_SHIFT             (12u)

#if (CY_PSOC3 || CY_PSOC5)
    #define TX_CAN_ARBITRATION_SHIFT     (4u)
    /* Bit 12 within CSR_CFG */
    #define TX_CAN_ARBITRATION_MASK      ((uint8) ((uint8) 0x01u << TX_CAN_ARBITRATION_SHIFT))
#else  /* CY_PSOC4 */
    #define TX_CAN_ARBITRATION_SHIFT     (12u)
    /* Bit 12 within CSR_CFG */
    #define TX_CAN_ARBITRATION_MASK      ((uint32) ((uint32) 0x01u << TX_CAN_ARBITRATION_SHIFT))
    /* Bit 13 within CSR_CFG */
    #define TX_CAN_ENDIANNESS_SHIFT      (13u)
    #define TX_CAN_ENDIANNESS_MASK       ((uint32) ((uint32) 0x01u << TX_CAN_ENDIANNESS_SHIFT))
    /* Bit 14 within CSR_CFG */
    #define TX_CAN_ECR_MODE_SHIFT        (14u)
    #define TX_CAN_ECR_MODE_MASK         ((uint32) ((uint32) 0x01u << TX_CAN_ECR_MODE_SHIFT))
#endif /* (CY_PSOC3 || CY_PSOC5) */

/* Bits 23-16 within CSR_CFG */
#define TX_CAN_BITRATE_SHIFT             (16u)
#define TX_CAN_BITRATE_MASK              (0x7FFFu)
#define TX_CAN_BITRATE_MASK_SHIFTED      \
        ((uint32) ((uint32) TX_CAN_BITRATE_MASK << TX_CAN_BITRATE_SHIFT))

/* Mask for bits within TX_CAN_CSR_CMD */
#define TX_CAN_MODE_SHIFT                (0u)
/* Bit 0 within CSR_CMD */
#define TX_CAN_MODE_MASK                 ((uint8) ((uint8) 0x01u << TX_CAN_MODE_SHIFT))
#define TX_CAN_OPMODE_MASK_SHIFT         (1u)
/* Bit 1 within CSR_CMD */
#define TX_CAN_OPMODE_MASK               ((uint8) ((uint8) 0x01u << TX_CAN_OPMODE_MASK_SHIFT))

#if (CY_PSOC3 || CY_PSOC5)
    #define TX_CAN_OPMODE_FIELD_MASK     ((uint8) ((uint8) 0x03u << TX_CAN_MODE_SHIFT))
#else  /* CY_PSOC4 */
    #define TX_CAN_OPMODE_FIELD_MASK     ((uint8) ((uint8) 0x07u << TX_CAN_MODE_SHIFT))
#endif /* (CY_PSOC3 || CY_PSOC5) */

/* Mask for bits within TX_CAN_CSR_CMD */
#define TX_CAN_ERROR_STATE_SHIFT         (0u)
/* Bit 17-16 within ERR_SR */
#define TX_CAN_ERROR_STATE_MASK          ((uint8) ((uint8) 0x03u << TX_CAN_ERROR_STATE_SHIFT))

#if (CY_PSOC3 || CY_PSOC5)
    #define TX_CAN_TX_ERROR_FLAG_SHIFT   (2u)
    /* Bit 18 within ERR_SR */
    #define TX_CAN_TX_ERROR_FLAG_MASK    ((uint8) ((uint8) 0x01u << TX_CAN_TX_ERROR_FLAG_SHIFT))
    #define TX_CAN_RX_ERROR_FLAG_SHIFT   (3u)
    /* Bit 19 within ERR_SR */
    #define TX_CAN_RX_ERROR_FLAG_MASK    ((uint8) ((uint8) 0x01u << TX_CAN_RX_ERROR_FLAG_SHIFT))
#else  /* CY_PSOC4 */
    #define TX_CAN_TX_ERROR_FLAG_SHIFT   (18u)
    /* Bit 18 within ERR_SR */
    #define TX_CAN_TX_ERROR_FLAG_MASK    ((uint32) ((uint32) 0x01u << TX_CAN_TX_ERROR_FLAG_SHIFT))
    #define TX_CAN_RX_ERROR_FLAG_SHIFT   (19u)
    /* Bit 19 within ERR_SR */
    #define TX_CAN_RX_ERROR_FLAG_MASK    ((uint32) ((uint32) 0x01u << TX_CAN_RX_ERROR_FLAG_SHIFT))

    /* Mask and Macros for bits within TX_CAN_ECR_REG */
    #define TX_CAN_ECR_STATUS_ARM        (0x01u)
    /* Mask for clearing TX_CANINT_STATUS */
    #define TX_CAN_INT_STATUS_MASK       (0x00001FFCu)
#endif /* (CY_PSOC3 || CY_PSOC5) */

/* Mask and Macros for bits within TX_CAN_INT_EN_REG */
#define TX_CAN_GLOBAL_INT_SHIFT          (0u)
#define TX_CAN_ARBITRATION_LOST_SHIFT    (2u)
#define TX_CAN_OVERLOAD_ERROR_SHIFT      (3u)
#define TX_CAN_BIT_ERROR_SHIFT           (4u)
#define TX_CAN_STUFF_ERROR_SHIFT         (5u)
#define TX_CAN_ACK_ERROR_SHIFT           (6u)
#define TX_CAN_FORM_ERROR_SHIFT          (7u)

#if (CY_PSOC3 || CY_PSOC5)
    #define TX_CAN_CRC_ERROR_SHIFT       (0u)
    #define TX_CAN_BUS_OFF_SHIFT         (1u)
    #define TX_CAN_RX_MSG_LOST_SHIFT     (2u)
    #define TX_CAN_TX_MESSAGE_SHIFT      (3u)
    #define TX_CAN_RX_MESSAGE_SHIFT      (4u)

    /* Bit 0 within INT_EN */
    #define TX_CAN_GLOBAL_INT_MASK       ((uint8) ((uint8) 0x01u << TX_CAN_GLOBAL_INT_SHIFT))
    /* Bit 2 within INT_EN and INT_SR */
    #define TX_CAN_ARBITRATION_LOST_MASK ((uint8) ((uint8) 0x01u << TX_CAN_ARBITRATION_LOST_SHIFT))
    /* Bit 3 within INT_EN and INT_SR */
    #define TX_CAN_OVERLOAD_ERROR_MASK   ((uint8) ((uint8) 0x01u << TX_CAN_OVERLOAD_ERROR_SHIFT))
    /* Bit 4 within INT_EN and INT_SR */
    #define TX_CAN_BIT_ERROR_MASK        ((uint8) ((uint8) 0x01u << TX_CAN_BIT_ERROR_SHIFT))
    /* Bit 5 within INT_EN and INT_SR */
    #define TX_CAN_STUFF_ERROR_MASK      ((uint8) ((uint8) 0x01u << TX_CAN_STUFF_ERROR_SHIFT))
    /* Bit 6 within INT_EN and INT_SR */
    #define TX_CAN_ACK_ERROR_MASK        ((uint8) ((uint8) 0x01u << TX_CAN_ACK_ERROR_SHIFT))
    /* Bit 7 within INT_EN and INT_SR */
    #define TX_CAN_FORM_ERROR_MASK       ((uint8) ((uint8) 0x01u << TX_CAN_FORM_ERROR_SHIFT))
    /* Bit 8 within INT_EN and INT_SR */
    #define TX_CAN_CRC_ERROR_MASK        ((uint8) ((uint8) 0x01u << TX_CAN_CRC_ERROR_SHIFT))
    /* Bit 9 within INT_EN and INT_SR */
    #define TX_CAN_BUS_OFF_MASK          ((uint8) ((uint8) 0x01u << TX_CAN_BUS_OFF_SHIFT))
    /* Bit 10 within INT_EN and INT_SR */
    #define TX_CAN_RX_MSG_LOST_MASK      ((uint8) ((uint8) 0x01u << TX_CAN_RX_MSG_LOST_SHIFT))
    /* Bit 11 within INT_EN and INT_SR */
    #define TX_CAN_TX_MESSAGE_MASK       ((uint8) ((uint8) 0x01u << TX_CAN_TX_MESSAGE_SHIFT))
    /* Bit 12 within INT_EN and INT_SR */
    #define TX_CAN_RX_MESSAGE_MASK       ((uint8) ((uint8) 0x01u << TX_CAN_RX_MESSAGE_SHIFT))

    #define TX_CAN_ARBITRATION_LOST_INT_ENABLE   \
            (TX_CAN_INT_EN_REG.byte[0u] |= TX_CAN_ARBITRATION_LOST_MASK)
    #define TX_CAN_ARBITRATION_LOST_INT_DISABLE  \
            (TX_CAN_INT_EN_REG.byte[0u] &= (uint8) (~TX_CAN_ARBITRATION_LOST_MASK))
    #define TX_CAN_OVERLOAD_ERROR_INT_ENABLE     \
            (TX_CAN_INT_EN_REG.byte[0u] |= TX_CAN_OVERLOAD_ERROR_MASK)
    #define TX_CAN_OVERLOAD_ERROR_INT_DISABLE    \
            (TX_CAN_INT_EN_REG.byte[0u] &= (uint8) (~TX_CAN_OVERLOAD_ERROR_MASK))
    #define TX_CAN_BIT_ERROR_LOST_INT_ENABLE     \
            (TX_CAN_INT_EN_REG.byte[0u] |= TX_CAN_BIT_ERROR_MASK)
    #define TX_CAN_BIT_ERROR_LOST_INT_DISABLE    \
            (TX_CAN_INT_EN_REG.byte[0u] &= (uint8) (~TX_CAN_BIT_ERROR_MASK))
    #define TX_CAN_STUFF_ERROR_INT_ENABLE        \
            (TX_CAN_INT_EN_REG.byte[0u] |= TX_CAN_STUFF_ERROR_MASK)
    #define TX_CAN_STUFF_ERROR_INT_DISABLE       \
            (TX_CAN_INT_EN_REG.byte[0u] &= (uint8) (~TX_CAN_STUFF_ERROR_MASK))
    #define TX_CAN_ACK_ERROR_INT_ENABLE          \
            (TX_CAN_INT_EN_REG.byte[0u] |= TX_CAN_ACK_ERROR_MASK)
    #define TX_CAN_ACK_ERROR_INT_DISABLE         \
            (TX_CAN_INT_EN_REG.byte[0u] &= (uint8) (~TX_CAN_ACK_ERROR_MASK))
    #define TX_CAN_FORM_ERROR_INT_ENABLE         \
            (TX_CAN_INT_EN_REG.byte[0u] |= TX_CAN_FORM_ERROR_MASK)
    #define TX_CAN_FORM_ERROR_INT_DISABLE        \
            (TX_CAN_INT_EN_REG.byte[0u] &= (uint8) (~TX_CAN_FORM_ERROR_MASK))
    #define TX_CAN_CRC_ERROR_INT_ENABLE          \
            (TX_CAN_INT_EN_REG.byte[1u] |= TX_CAN_CRC_ERROR_MASK)
    #define TX_CAN_CRC_ERROR_INT_DISABLE         \
            (TX_CAN_INT_EN_REG.byte[1u] &= (uint8) (~TX_CAN_CRC_ERROR_MASK))
    #define TX_CAN_BUS_OFF_INT_ENABLE            \
            (TX_CAN_INT_EN_REG.byte[1u] |= TX_CAN_BUS_OFF_MASK)
    #define TX_CAN_BUS_OFF_INT_DISABLE           \
            (TX_CAN_INT_EN_REG.byte[1u] &= (uint8) (~TX_CAN_BUS_OFF_MASK))
    #define TX_CAN_RX_MSG_LOST_INT_ENABLE        \
            (TX_CAN_INT_EN_REG.byte[1u] |= TX_CAN_RX_MSG_LOST_MASK)
    #define TX_CAN_RX_MSG_LOST_INT_DISABLE       \
            (TX_CAN_INT_EN_REG.byte[1u] &= (uint8) (~TX_CAN_RX_MSG_LOST_MASK))
    #define TX_CAN_TX_MSG_INT_ENABLE             \
            (TX_CAN_INT_EN_REG.byte[1u] |= TX_CAN_TX_MESSAGE_MASK)
    #define TX_CAN_TX_MSG_INT_DISABLE            \
            (TX_CAN_INT_EN_REG.byte[1u] &= (uint8) (~TX_CAN_TX_MESSAGE_MASK))
    #define TX_CAN_RX_MSG_INT_ENABLE             \
            (TX_CAN_INT_EN_REG.byte[1u] |= TX_CAN_RX_MESSAGE_MASK)
    #define TX_CAN_RX_MSG_INT_DISABLE            \
            (TX_CAN_INT_EN_REG.byte[1u] &= (uint8) (~TX_CAN_RX_MESSAGE_MASK))
#else  /* CY_PSOC4 */
    #define TX_CAN_CRC_ERROR_SHIFT       (8u)
    #define TX_CAN_BUS_OFF_SHIFT         (9u)
    #define TX_CAN_RX_MSG_LOST_SHIFT     (10u)
    #define TX_CAN_TX_MESSAGE_SHIFT      (11u)
    #define TX_CAN_RX_MESSAGE_SHIFT      (12u)

    /* Mask and Macros for bits within TX_CAN_INT_EN_REG */
    /* Bit 0 within INT_EN */
    #define TX_CAN_GLOBAL_INT_MASK       ((uint32) ((uint32) 0x01u << TX_CAN_GLOBAL_INT_SHIFT))
    /* Bit 2 within INT_EN and INT_SR */
    #define TX_CAN_ARBITRATION_LOST_MASK ((uint32) ((uint32) 0x01u << TX_CAN_ARBITRATION_LOST_SHIFT))
    /* Bit 3 within INT_EN and INT_SR */
    #define TX_CAN_OVERLOAD_ERROR_MASK   ((uint32) ((uint32) 0x01u << TX_CAN_OVERLOAD_ERROR_SHIFT))
    /* Bit 4 within INT_EN and INT_SR */
    #define TX_CAN_BIT_ERROR_MASK        ((uint32) ((uint32) 0x01u << TX_CAN_BIT_ERROR_SHIFT))
    /* Bit 5 within INT_EN and INT_SR */
    #define TX_CAN_STUFF_ERROR_MASK      ((uint32) ((uint32) 0x01u << TX_CAN_STUFF_ERROR_SHIFT))
    /* Bit 6 within INT_EN and INT_SR */
    #define TX_CAN_ACK_ERROR_MASK        ((uint32) ((uint32) 0x01u << TX_CAN_ACK_ERROR_SHIFT))
    /* Bit 7 within INT_EN and INT_SR */
    #define TX_CAN_FORM_ERROR_MASK       ((uint32) ((uint32) 0x01u << TX_CAN_FORM_ERROR_SHIFT))
    /* Bit 8 within INT_EN and INT_SR */
    #define TX_CAN_CRC_ERROR_MASK        ((uint32) ((uint32) 0x01u << TX_CAN_CRC_ERROR_SHIFT))
    /* Bit 9 within INT_EN and INT_SR */
    #define TX_CAN_BUS_OFF_MASK          ((uint32) ((uint32) 0x01u << TX_CAN_BUS_OFF_SHIFT))
    /* Bit 10 within INT_EN and INT_SR */
    #define TX_CAN_RX_MSG_LOST_MASK      ((uint32) ((uint32) 0x01u << TX_CAN_RX_MSG_LOST_SHIFT))
    /* Bit 11 within INT_EN and INT_SR */
    #define TX_CAN_TX_MESSAGE_MASK       ((uint32) ((uint32) 0x01u << TX_CAN_TX_MESSAGE_SHIFT))
    /* Bit 12 within INT_EN and INT_SR */
    #define TX_CAN_RX_MESSAGE_MASK       ((uint32) ((uint32) 0x01u << TX_CAN_RX_MESSAGE_SHIFT))

    #define TX_CAN_ARBITRATION_LOST_INT_ENABLE   \
            (TX_CAN_INT_EN_REG |= TX_CAN_ARBITRATION_LOST_MASK)
    #define TX_CAN_ARBITRATION_LOST_INT_DISABLE  \
            (TX_CAN_INT_EN_REG &= (uint32) (~TX_CAN_ARBITRATION_LOST_MASK))
    #define TX_CAN_OVERLOAD_ERROR_INT_ENABLE     \
            (TX_CAN_INT_EN_REG |= TX_CAN_OVERLOAD_ERROR_MASK)
    #define TX_CAN_OVERLOAD_ERROR_INT_DISABLE    \
            (TX_CAN_INT_EN_REG &= (uint32) (~TX_CAN_OVERLOAD_ERROR_MASK))
    #define TX_CAN_BIT_ERROR_LOST_INT_ENABLE     \
            (TX_CAN_INT_EN_REG |= TX_CAN_BIT_ERROR_MASK)
    #define TX_CAN_BIT_ERROR_LOST_INT_DISABLE    \
            (TX_CAN_INT_EN_REG &= (uint32) (~TX_CAN_BIT_ERROR_MASK))
    #define TX_CAN_STUFF_ERROR_INT_ENABLE        \
            (TX_CAN_INT_EN_REG |= TX_CAN_STUFF_ERROR_MASK)
    #define TX_CAN_STUFF_ERROR_INT_DISABLE       \
            (TX_CAN_INT_EN_REG &= (uint32) (~TX_CAN_STUFF_ERROR_MASK))
    #define TX_CAN_ACK_ERROR_INT_ENABLE          \
            (TX_CAN_INT_EN_REG |= TX_CAN_ACK_ERROR_MASK)
    #define TX_CAN_ACK_ERROR_INT_DISABLE         \
            (TX_CAN_INT_EN_REG &= (uint32) (~TX_CAN_ACK_ERROR_MASK))
    #define TX_CAN_FORM_ERROR_INT_ENABLE         \
            (TX_CAN_INT_EN_REG |= TX_CAN_FORM_ERROR_MASK)
    #define TX_CAN_FORM_ERROR_INT_DISABLE        \
            (TX_CAN_INT_EN_REG &= (uint32) (~TX_CAN_FORM_ERROR_MASK))
    #define TX_CAN_CRC_ERROR_INT_ENABLE          \
            (TX_CAN_INT_EN_REG |= TX_CAN_CRC_ERROR_MASK)
    #define TX_CAN_CRC_ERROR_INT_DISABLE         \
            (TX_CAN_INT_EN_REG &= (uint32) (~TX_CAN_CRC_ERROR_MASK))
    #define TX_CAN_BUS_OFF_INT_ENABLE            \
            (TX_CAN_INT_EN_REG |= TX_CAN_BUS_OFF_MASK)
    #define TX_CAN_BUS_OFF_INT_DISABLE           \
            (TX_CAN_INT_EN_REG &= (uint32) (~TX_CAN_BUS_OFF_MASK))
    #define TX_CAN_RX_MSG_LOST_INT_ENABLE        \
            (TX_CAN_INT_EN_REG |= TX_CAN_RX_MSG_LOST_MASK)
    #define TX_CAN_RX_MSG_LOST_INT_DISABLE       \
            (TX_CAN_INT_EN_REG &= (uint32) (~TX_CAN_RX_MSG_LOST_MASK))
    #define TX_CAN_TX_MSG_INT_ENABLE             \
            (TX_CAN_INT_EN_REG |= TX_CAN_TX_MESSAGE_MASK)
    #define TX_CAN_TX_MSG_INT_DISABLE            \
            (TX_CAN_INT_EN_REG &= (uint32) (~TX_CAN_TX_MESSAGE_MASK))
    #define TX_CAN_RX_MSG_INT_ENABLE             \
            (TX_CAN_INT_EN_REG |= TX_CAN_RX_MESSAGE_MASK)
    #define TX_CAN_RX_MSG_INT_DISABLE            \
            (TX_CAN_INT_EN_REG &= (uint32) (~TX_CAN_RX_MESSAGE_MASK))

    /* Bit 13 within INT_EN and INT_SR */
    #define TX_CAN_RTR_MSG_SHIFT              (13u)
    #define TX_CAN_RTR_MSG_MASK               ((uint32) ((uint32) 0x01u << TX_CAN_RTR_MSG_SHIFT))
    #define TX_CAN_RTR_MSG_INT_ENABLE         (TX_CAN_INT_EN_REG |= TX_CAN_RTR_MSG_MASK)
    #define TX_CAN_RTR_MSG_INT_DISABLE        \
            (TX_CAN_INT_EN_REG &= (uint32) (~TX_CAN_RTR_MSG_MASK))
    /* Bit 14 within INT_EN and INT_SR */
    #define TX_CAN_STUCK_AT_ZERO_SHIFT        (14u)
    #define TX_CAN_STUCK_AT_ZERO_MASK         \
            ((uint32) ((uint32) 0x01u << TX_CAN_STUCK_AT_ZERO_SHIFT))
    #define TX_CAN_STUCK_AT_ZERO_INT_ENABLE   \
            (TX_CAN_INT_EN_REG |= TX_CAN_STUCK_AT_ZERO_MASK)
    #define TX_CAN_STUCK_AT_ZERO_INT_DISABLE  \
            (TX_CAN_INT_EN_REG &= (uint32) (~TX_CAN_STUCK_AT_ZERO_MASK))
    /* Bit 15 within INT_EN and INT_SR */
    #define TX_CAN_SST_FAILURE_SHIFT          (15u)
    #define TX_CAN_SST_FAILURE_MASK           \
            ((uint32) ((uint32) 0x01u << TX_CAN_SST_FAILURE_SHIFT))
    #define TX_CAN_SST_FAILURE_INT_ENABLE     \
            (TX_CAN_INT_EN_REG |= TX_CAN_SST_FAILURE_MASK)
    #define TX_CAN_SST_FAILURE_INT_DISABLE    \
            (TX_CAN_INT_EN_REG &= (uint32) (~TX_CAN_SST_FAILURE_MASK))
#endif /* CY_PSOC3 || CY_PSOC5 */

#define TX_CAN_GLOBAL_INT_ENABLE_SHIFT        (0u)
#define TX_CAN_ARBITRATION_LOST_ENABLE_SHIFT  (2u)
#define TX_CAN_OVERLOAD_ERROR_ENABLE_SHIFT    (3u)
#define TX_CAN_BIT_ERROR_ENABLE_SHIFT         (4u)
#define TX_CAN_STUFF_ERROR_ENABLE_SHIFT       (5u)
#define TX_CAN_ACK_ERROR_ENABLE_SHIFT         (6u)
#define TX_CAN_FORM_ERROR_ENABLE_SHIFT        (7u)
#define TX_CAN_CRC_ERROR_ENABLE_SHIFT         (8u)
#define TX_CAN_BUS_OFF_ENABLE_SHIFT           (9u)
#define TX_CAN_RX_MSG_LOST_ENABLE_SHIFT       (10u)
#define TX_CAN_TX_MESSAGE_ENABLE_SHIFT        (11u)
#define TX_CAN_RX_MESSAGE_ENABLE_SHIFT        (12u)

#define TX_CAN_GLOBAL_INT_ENABLE    ((uint16) ((uint16) 0x01u << TX_CAN_GLOBAL_INT_ENABLE_SHIFT))
#define TX_CAN_ARBITRATION_LOST_ENABLE \
        ((uint16) ((uint16) 0x01u << TX_CAN_ARBITRATION_LOST_ENABLE_SHIFT))
#define TX_CAN_OVERLOAD_ERROR_ENABLE   \
        ((uint16) ((uint16) 0x01u << TX_CAN_OVERLOAD_ERROR_ENABLE_SHIFT))
#define TX_CAN_BIT_ERROR_ENABLE     ((uint16) ((uint16) 0x01u << TX_CAN_BIT_ERROR_ENABLE_SHIFT))
#define TX_CAN_STUFF_ERROR_ENABLE   ((uint16) ((uint16) 0x01u << TX_CAN_STUFF_ERROR_ENABLE_SHIFT))
#define TX_CAN_ACK_ERROR_ENABLE     ((uint16) ((uint16) 0x01u << TX_CAN_ACK_ERROR_ENABLE_SHIFT))
#define TX_CAN_FORM_ERROR_ENABLE    ((uint16) ((uint16) 0x01u << TX_CAN_FORM_ERROR_ENABLE_SHIFT))
#define TX_CAN_CRC_ERROR_ENABLE     ((uint16) ((uint16) 0x01u << TX_CAN_CRC_ERROR_ENABLE_SHIFT))
#define TX_CAN_BUS_OFF_ENABLE       ((uint16) ((uint16) 0x01u << TX_CAN_BUS_OFF_ENABLE_SHIFT))
#define TX_CAN_RX_MSG_LOST_ENABLE   ((uint16) ((uint16) 0x01u << TX_CAN_RX_MSG_LOST_ENABLE_SHIFT))
#define TX_CAN_TX_MESSAGE_ENABLE    ((uint16) ((uint16) 0x01u << TX_CAN_TX_MESSAGE_ENABLE_SHIFT))
#define TX_CAN_RX_MESSAGE_ENABLE    ((uint16) ((uint16) 0x01u << TX_CAN_RX_MESSAGE_ENABLE_SHIFT))

#if (!(CY_PSOC3 || CY_PSOC5))
    #define TX_CAN_RTR_MESSAGE_ENABLE_SHIFT   (13u)
    #define TX_CAN_STUCK_AT_ZERO_ENABLE_SHIFT (14u)
    #define TX_CAN_SST_FAILURE_ENABLE_SHIFT   (15u)

    #define TX_CAN_RTR_MESSAGE_ENABLE   \
            ((uint16) ((uint16) 0x01u << TX_CAN_RTR_MESSAGE_ENABLE_SHIFT))
    #define TX_CAN_STUCK_AT_ZERO_ENABLE \
            ((uint16) ((uint16) 0x01u << TX_CAN_STUCK_AT_ZERO_ENABLE_SHIFT))
    #define TX_CAN_SST_FAILURE_ENABLE   \
            ((uint16) ((uint16) 0x01u << TX_CAN_SST_FAILURE_ENABLE_SHIFT))
#endif /* (!(CY_PSOC3 || CY_PSOC5)) */

#define TX_CAN_REG_ADDR_MASK        ((uint32) 0x0000FFFFu)


/***************************************
* The following code is DEPRECATED and
* should not be used in new projects.
***************************************/

#define TX_CAN_TREE_BYTE_OFFSET     (TX_CAN_THREE_BYTE_OFFSET)

/* TX_CAN_SetRestartType() parameters */
#define TX_CAN_RESTART_BY_HAND      (TX_CAN_MANUAL_RESTART)

/* TX_CAN_SetOpMode() parameters */
#define TX_CAN_LISTEN_ONLY          (TX_CAN_LISTEN_ONLY_MODE)
#define TX_CAN_ACTIVE_MODE          (TX_CAN_INITIAL_MODE)

#ifdef TX_CAN_ISR_CALLBACK
    #define TX_CAN_ISR_INTERRUPT_CALLBACK
    #define TX_CAN_ISR_InterruptCallback  TX_CAN_Isr_Callback
#endif

#endif /* CY_CAN_TX_CAN_H */


/* [] END OF FILE */

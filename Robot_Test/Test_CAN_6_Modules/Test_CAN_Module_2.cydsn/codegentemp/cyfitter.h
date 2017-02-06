#ifndef INCLUDED_CYFITTER_H
#define INCLUDED_CYFITTER_H
#include "cydevice_trm.h"

/* CAN_CanIP */
#define CAN_CanIP__BUFFER_STATUS CYREG_CAN0_BUFFER_STATUS
#define CAN_CanIP__CAN_RX0_ACR CYREG_CAN0_CAN_RX0_ACR
#define CAN_CanIP__CAN_RX0_ACR_DATA CYREG_CAN0_CAN_RX0_ACR_DATA
#define CAN_CanIP__CAN_RX0_AMR CYREG_CAN0_CAN_RX0_AMR
#define CAN_CanIP__CAN_RX0_AMR_DATA CYREG_CAN0_CAN_RX0_AMR_DATA
#define CAN_CanIP__CAN_RX0_CONTROL CYREG_CAN0_CAN_RX0_CONTROL
#define CAN_CanIP__CAN_RX0_DATA_HIGH CYREG_CAN0_CAN_RX0_DATA_HIGH
#define CAN_CanIP__CAN_RX0_DATA_LOW CYREG_CAN0_CAN_RX0_DATA_LOW
#define CAN_CanIP__CAN_RX0_ID CYREG_CAN0_CAN_RX0_ID
#define CAN_CanIP__CAN_RX1_ACR CYREG_CAN0_CAN_RX1_ACR
#define CAN_CanIP__CAN_RX1_ACR_DATA CYREG_CAN0_CAN_RX1_ACR_DATA
#define CAN_CanIP__CAN_RX1_AMR CYREG_CAN0_CAN_RX1_AMR
#define CAN_CanIP__CAN_RX1_AMR_DATA CYREG_CAN0_CAN_RX1_AMR_DATA
#define CAN_CanIP__CAN_RX1_CONTROL CYREG_CAN0_CAN_RX1_CONTROL
#define CAN_CanIP__CAN_RX1_DATA_HIGH CYREG_CAN0_CAN_RX1_DATA_HIGH
#define CAN_CanIP__CAN_RX1_DATA_LOW CYREG_CAN0_CAN_RX1_DATA_LOW
#define CAN_CanIP__CAN_RX1_ID CYREG_CAN0_CAN_RX1_ID
#define CAN_CanIP__CAN_RX10_ACR CYREG_CAN0_CAN_RX10_ACR
#define CAN_CanIP__CAN_RX10_ACR_DATA CYREG_CAN0_CAN_RX10_ACR_DATA
#define CAN_CanIP__CAN_RX10_AMR CYREG_CAN0_CAN_RX10_AMR
#define CAN_CanIP__CAN_RX10_AMR_DATA CYREG_CAN0_CAN_RX10_AMR_DATA
#define CAN_CanIP__CAN_RX10_CONTROL CYREG_CAN0_CAN_RX10_CONTROL
#define CAN_CanIP__CAN_RX10_DATA_HIGH CYREG_CAN0_CAN_RX10_DATA_HIGH
#define CAN_CanIP__CAN_RX10_DATA_LOW CYREG_CAN0_CAN_RX10_DATA_LOW
#define CAN_CanIP__CAN_RX10_ID CYREG_CAN0_CAN_RX10_ID
#define CAN_CanIP__CAN_RX11_ACR CYREG_CAN0_CAN_RX11_ACR
#define CAN_CanIP__CAN_RX11_ACR_DATA CYREG_CAN0_CAN_RX11_ACR_DATA
#define CAN_CanIP__CAN_RX11_AMR CYREG_CAN0_CAN_RX11_AMR
#define CAN_CanIP__CAN_RX11_AMR_DATA CYREG_CAN0_CAN_RX11_AMR_DATA
#define CAN_CanIP__CAN_RX11_CONTROL CYREG_CAN0_CAN_RX11_CONTROL
#define CAN_CanIP__CAN_RX11_DATA_HIGH CYREG_CAN0_CAN_RX11_DATA_HIGH
#define CAN_CanIP__CAN_RX11_DATA_LOW CYREG_CAN0_CAN_RX11_DATA_LOW
#define CAN_CanIP__CAN_RX11_ID CYREG_CAN0_CAN_RX11_ID
#define CAN_CanIP__CAN_RX12_ACR CYREG_CAN0_CAN_RX12_ACR
#define CAN_CanIP__CAN_RX12_ACR_DATA CYREG_CAN0_CAN_RX12_ACR_DATA
#define CAN_CanIP__CAN_RX12_AMR CYREG_CAN0_CAN_RX12_AMR
#define CAN_CanIP__CAN_RX12_AMR_DATA CYREG_CAN0_CAN_RX12_AMR_DATA
#define CAN_CanIP__CAN_RX12_CONTROL CYREG_CAN0_CAN_RX12_CONTROL
#define CAN_CanIP__CAN_RX12_DATA_HIGH CYREG_CAN0_CAN_RX12_DATA_HIGH
#define CAN_CanIP__CAN_RX12_DATA_LOW CYREG_CAN0_CAN_RX12_DATA_LOW
#define CAN_CanIP__CAN_RX12_ID CYREG_CAN0_CAN_RX12_ID
#define CAN_CanIP__CAN_RX13_ACR CYREG_CAN0_CAN_RX13_ACR
#define CAN_CanIP__CAN_RX13_ACR_DATA CYREG_CAN0_CAN_RX13_ACR_DATA
#define CAN_CanIP__CAN_RX13_AMR CYREG_CAN0_CAN_RX13_AMR
#define CAN_CanIP__CAN_RX13_AMR_DATA CYREG_CAN0_CAN_RX13_AMR_DATA
#define CAN_CanIP__CAN_RX13_CONTROL CYREG_CAN0_CAN_RX13_CONTROL
#define CAN_CanIP__CAN_RX13_DATA_HIGH CYREG_CAN0_CAN_RX13_DATA_HIGH
#define CAN_CanIP__CAN_RX13_DATA_LOW CYREG_CAN0_CAN_RX13_DATA_LOW
#define CAN_CanIP__CAN_RX13_ID CYREG_CAN0_CAN_RX13_ID
#define CAN_CanIP__CAN_RX14_ACR CYREG_CAN0_CAN_RX14_ACR
#define CAN_CanIP__CAN_RX14_ACR_DATA CYREG_CAN0_CAN_RX14_ACR_DATA
#define CAN_CanIP__CAN_RX14_AMR CYREG_CAN0_CAN_RX14_AMR
#define CAN_CanIP__CAN_RX14_AMR_DATA CYREG_CAN0_CAN_RX14_AMR_DATA
#define CAN_CanIP__CAN_RX14_CONTROL CYREG_CAN0_CAN_RX14_CONTROL
#define CAN_CanIP__CAN_RX14_DATA_HIGH CYREG_CAN0_CAN_RX14_DATA_HIGH
#define CAN_CanIP__CAN_RX14_DATA_LOW CYREG_CAN0_CAN_RX14_DATA_LOW
#define CAN_CanIP__CAN_RX14_ID CYREG_CAN0_CAN_RX14_ID
#define CAN_CanIP__CAN_RX15_ACR CYREG_CAN0_CAN_RX15_ACR
#define CAN_CanIP__CAN_RX15_ACR_DATA CYREG_CAN0_CAN_RX15_ACR_DATA
#define CAN_CanIP__CAN_RX15_AMR CYREG_CAN0_CAN_RX15_AMR
#define CAN_CanIP__CAN_RX15_AMR_DATA CYREG_CAN0_CAN_RX15_AMR_DATA
#define CAN_CanIP__CAN_RX15_CONTROL CYREG_CAN0_CAN_RX15_CONTROL
#define CAN_CanIP__CAN_RX15_DATA_HIGH CYREG_CAN0_CAN_RX15_DATA_HIGH
#define CAN_CanIP__CAN_RX15_DATA_LOW CYREG_CAN0_CAN_RX15_DATA_LOW
#define CAN_CanIP__CAN_RX15_ID CYREG_CAN0_CAN_RX15_ID
#define CAN_CanIP__CAN_RX2_ACR CYREG_CAN0_CAN_RX2_ACR
#define CAN_CanIP__CAN_RX2_ACR_DATA CYREG_CAN0_CAN_RX2_ACR_DATA
#define CAN_CanIP__CAN_RX2_AMR CYREG_CAN0_CAN_RX2_AMR
#define CAN_CanIP__CAN_RX2_AMR_DATA CYREG_CAN0_CAN_RX2_AMR_DATA
#define CAN_CanIP__CAN_RX2_CONTROL CYREG_CAN0_CAN_RX2_CONTROL
#define CAN_CanIP__CAN_RX2_DATA_HIGH CYREG_CAN0_CAN_RX2_DATA_HIGH
#define CAN_CanIP__CAN_RX2_DATA_LOW CYREG_CAN0_CAN_RX2_DATA_LOW
#define CAN_CanIP__CAN_RX2_ID CYREG_CAN0_CAN_RX2_ID
#define CAN_CanIP__CAN_RX3_ACR CYREG_CAN0_CAN_RX3_ACR
#define CAN_CanIP__CAN_RX3_ACR_DATA CYREG_CAN0_CAN_RX3_ACR_DATA
#define CAN_CanIP__CAN_RX3_AMR CYREG_CAN0_CAN_RX3_AMR
#define CAN_CanIP__CAN_RX3_AMR_DATA CYREG_CAN0_CAN_RX3_AMR_DATA
#define CAN_CanIP__CAN_RX3_CONTROL CYREG_CAN0_CAN_RX3_CONTROL
#define CAN_CanIP__CAN_RX3_DATA_HIGH CYREG_CAN0_CAN_RX3_DATA_HIGH
#define CAN_CanIP__CAN_RX3_DATA_LOW CYREG_CAN0_CAN_RX3_DATA_LOW
#define CAN_CanIP__CAN_RX3_ID CYREG_CAN0_CAN_RX3_ID
#define CAN_CanIP__CAN_RX4_ACR CYREG_CAN0_CAN_RX4_ACR
#define CAN_CanIP__CAN_RX4_ACR_DATA CYREG_CAN0_CAN_RX4_ACR_DATA
#define CAN_CanIP__CAN_RX4_AMR CYREG_CAN0_CAN_RX4_AMR
#define CAN_CanIP__CAN_RX4_AMR_DATA CYREG_CAN0_CAN_RX4_AMR_DATA
#define CAN_CanIP__CAN_RX4_CONTROL CYREG_CAN0_CAN_RX4_CONTROL
#define CAN_CanIP__CAN_RX4_DATA_HIGH CYREG_CAN0_CAN_RX4_DATA_HIGH
#define CAN_CanIP__CAN_RX4_DATA_LOW CYREG_CAN0_CAN_RX4_DATA_LOW
#define CAN_CanIP__CAN_RX4_ID CYREG_CAN0_CAN_RX4_ID
#define CAN_CanIP__CAN_RX5_ACR CYREG_CAN0_CAN_RX5_ACR
#define CAN_CanIP__CAN_RX5_ACR_DATA CYREG_CAN0_CAN_RX5_ACR_DATA
#define CAN_CanIP__CAN_RX5_AMR CYREG_CAN0_CAN_RX5_AMR
#define CAN_CanIP__CAN_RX5_AMR_DATA CYREG_CAN0_CAN_RX5_AMR_DATA
#define CAN_CanIP__CAN_RX5_CONTROL CYREG_CAN0_CAN_RX5_CONTROL
#define CAN_CanIP__CAN_RX5_DATA_HIGH CYREG_CAN0_CAN_RX5_DATA_HIGH
#define CAN_CanIP__CAN_RX5_DATA_LOW CYREG_CAN0_CAN_RX5_DATA_LOW
#define CAN_CanIP__CAN_RX5_ID CYREG_CAN0_CAN_RX5_ID
#define CAN_CanIP__CAN_RX6_ACR CYREG_CAN0_CAN_RX6_ACR
#define CAN_CanIP__CAN_RX6_ACR_DATA CYREG_CAN0_CAN_RX6_ACR_DATA
#define CAN_CanIP__CAN_RX6_AMR CYREG_CAN0_CAN_RX6_AMR
#define CAN_CanIP__CAN_RX6_AMR_DATA CYREG_CAN0_CAN_RX6_AMR_DATA
#define CAN_CanIP__CAN_RX6_CONTROL CYREG_CAN0_CAN_RX6_CONTROL
#define CAN_CanIP__CAN_RX6_DATA_HIGH CYREG_CAN0_CAN_RX6_DATA_HIGH
#define CAN_CanIP__CAN_RX6_DATA_LOW CYREG_CAN0_CAN_RX6_DATA_LOW
#define CAN_CanIP__CAN_RX6_ID CYREG_CAN0_CAN_RX6_ID
#define CAN_CanIP__CAN_RX7_ACR CYREG_CAN0_CAN_RX7_ACR
#define CAN_CanIP__CAN_RX7_ACR_DATA CYREG_CAN0_CAN_RX7_ACR_DATA
#define CAN_CanIP__CAN_RX7_AMR CYREG_CAN0_CAN_RX7_AMR
#define CAN_CanIP__CAN_RX7_AMR_DATA CYREG_CAN0_CAN_RX7_AMR_DATA
#define CAN_CanIP__CAN_RX7_CONTROL CYREG_CAN0_CAN_RX7_CONTROL
#define CAN_CanIP__CAN_RX7_DATA_HIGH CYREG_CAN0_CAN_RX7_DATA_HIGH
#define CAN_CanIP__CAN_RX7_DATA_LOW CYREG_CAN0_CAN_RX7_DATA_LOW
#define CAN_CanIP__CAN_RX7_ID CYREG_CAN0_CAN_RX7_ID
#define CAN_CanIP__CAN_RX8_ACR CYREG_CAN0_CAN_RX8_ACR
#define CAN_CanIP__CAN_RX8_ACR_DATA CYREG_CAN0_CAN_RX8_ACR_DATA
#define CAN_CanIP__CAN_RX8_AMR CYREG_CAN0_CAN_RX8_AMR
#define CAN_CanIP__CAN_RX8_AMR_DATA CYREG_CAN0_CAN_RX8_AMR_DATA
#define CAN_CanIP__CAN_RX8_CONTROL CYREG_CAN0_CAN_RX8_CONTROL
#define CAN_CanIP__CAN_RX8_DATA_HIGH CYREG_CAN0_CAN_RX8_DATA_HIGH
#define CAN_CanIP__CAN_RX8_DATA_LOW CYREG_CAN0_CAN_RX8_DATA_LOW
#define CAN_CanIP__CAN_RX8_ID CYREG_CAN0_CAN_RX8_ID
#define CAN_CanIP__CAN_RX9_ACR CYREG_CAN0_CAN_RX9_ACR
#define CAN_CanIP__CAN_RX9_ACR_DATA CYREG_CAN0_CAN_RX9_ACR_DATA
#define CAN_CanIP__CAN_RX9_AMR CYREG_CAN0_CAN_RX9_AMR
#define CAN_CanIP__CAN_RX9_AMR_DATA CYREG_CAN0_CAN_RX9_AMR_DATA
#define CAN_CanIP__CAN_RX9_CONTROL CYREG_CAN0_CAN_RX9_CONTROL
#define CAN_CanIP__CAN_RX9_DATA_HIGH CYREG_CAN0_CAN_RX9_DATA_HIGH
#define CAN_CanIP__CAN_RX9_DATA_LOW CYREG_CAN0_CAN_RX9_DATA_LOW
#define CAN_CanIP__CAN_RX9_ID CYREG_CAN0_CAN_RX9_ID
#define CAN_CanIP__CAN_TX0_CONTROL CYREG_CAN0_CAN_TX0_CONTROL
#define CAN_CanIP__CAN_TX0_DATA_HIGH CYREG_CAN0_CAN_TX0_DATA_HIGH
#define CAN_CanIP__CAN_TX0_DATA_LOW CYREG_CAN0_CAN_TX0_DATA_LOW
#define CAN_CanIP__CAN_TX0_ID CYREG_CAN0_CAN_TX0_ID
#define CAN_CanIP__CAN_TX1_CONTROL CYREG_CAN0_CAN_TX1_CONTROL
#define CAN_CanIP__CAN_TX1_DATA_HIGH CYREG_CAN0_CAN_TX1_DATA_HIGH
#define CAN_CanIP__CAN_TX1_DATA_LOW CYREG_CAN0_CAN_TX1_DATA_LOW
#define CAN_CanIP__CAN_TX1_ID CYREG_CAN0_CAN_TX1_ID
#define CAN_CanIP__CAN_TX2_CONTROL CYREG_CAN0_CAN_TX2_CONTROL
#define CAN_CanIP__CAN_TX2_DATA_HIGH CYREG_CAN0_CAN_TX2_DATA_HIGH
#define CAN_CanIP__CAN_TX2_DATA_LOW CYREG_CAN0_CAN_TX2_DATA_LOW
#define CAN_CanIP__CAN_TX2_ID CYREG_CAN0_CAN_TX2_ID
#define CAN_CanIP__CAN_TX3_CONTROL CYREG_CAN0_CAN_TX3_CONTROL
#define CAN_CanIP__CAN_TX3_DATA_HIGH CYREG_CAN0_CAN_TX3_DATA_HIGH
#define CAN_CanIP__CAN_TX3_DATA_LOW CYREG_CAN0_CAN_TX3_DATA_LOW
#define CAN_CanIP__CAN_TX3_ID CYREG_CAN0_CAN_TX3_ID
#define CAN_CanIP__CAN_TX4_CONTROL CYREG_CAN0_CAN_TX4_CONTROL
#define CAN_CanIP__CAN_TX4_DATA_HIGH CYREG_CAN0_CAN_TX4_DATA_HIGH
#define CAN_CanIP__CAN_TX4_DATA_LOW CYREG_CAN0_CAN_TX4_DATA_LOW
#define CAN_CanIP__CAN_TX4_ID CYREG_CAN0_CAN_TX4_ID
#define CAN_CanIP__CAN_TX5_CONTROL CYREG_CAN0_CAN_TX5_CONTROL
#define CAN_CanIP__CAN_TX5_DATA_HIGH CYREG_CAN0_CAN_TX5_DATA_HIGH
#define CAN_CanIP__CAN_TX5_DATA_LOW CYREG_CAN0_CAN_TX5_DATA_LOW
#define CAN_CanIP__CAN_TX5_ID CYREG_CAN0_CAN_TX5_ID
#define CAN_CanIP__CAN_TX6_CONTROL CYREG_CAN0_CAN_TX6_CONTROL
#define CAN_CanIP__CAN_TX6_DATA_HIGH CYREG_CAN0_CAN_TX6_DATA_HIGH
#define CAN_CanIP__CAN_TX6_DATA_LOW CYREG_CAN0_CAN_TX6_DATA_LOW
#define CAN_CanIP__CAN_TX6_ID CYREG_CAN0_CAN_TX6_ID
#define CAN_CanIP__CAN_TX7_CONTROL CYREG_CAN0_CAN_TX7_CONTROL
#define CAN_CanIP__CAN_TX7_DATA_HIGH CYREG_CAN0_CAN_TX7_DATA_HIGH
#define CAN_CanIP__CAN_TX7_DATA_LOW CYREG_CAN0_CAN_TX7_DATA_LOW
#define CAN_CanIP__CAN_TX7_ID CYREG_CAN0_CAN_TX7_ID
#define CAN_CanIP__CNTL CYREG_CAN0_CNTL
#define CAN_CanIP__COMMAND CYREG_CAN0_COMMAND
#define CAN_CanIP__CONFIG CYREG_CAN0_CONFIG
#define CAN_CanIP__ECR CYREG_CAN0_ECR
#define CAN_CanIP__ERROR_STATUS CYREG_CAN0_ERROR_STATUS
#define CAN_CanIP__INT_EBL CYREG_CAN0_INT_EBL
#define CAN_CanIP__INT_STATUS CYREG_CAN0_INT_STATUS
#define CAN_CanIP__INTR_CAN CYREG_CAN0_INTR_CAN
#define CAN_CanIP__INTR_CAN_MASK CYREG_CAN0_INTR_CAN_MASK
#define CAN_CanIP__INTR_CAN_MASKED CYREG_CAN0_INTR_CAN_MASKED
#define CAN_CanIP__INTR_CAN_SET CYREG_CAN0_INTR_CAN_SET
#define CAN_CanIP__TTCAN_CAPTURE CYREG_CAN0_TTCAN_CAPTURE
#define CAN_CanIP__TTCAN_COMPARE CYREG_CAN0_TTCAN_COMPARE
#define CAN_CanIP__TTCAN_COUNTER CYREG_CAN0_TTCAN_COUNTER
#define CAN_CanIP__TTCAN_TIMING CYREG_CAN0_TTCAN_TIMING

/* CAN_HFCLK */
#define CAN_HFCLK__DIV_ID 0x00000040u
#define CAN_HFCLK__DIV_REGISTER CYREG_PERI_DIV_16_CTL0
#define CAN_HFCLK__PA_DIV_ID 0x000000FFu

/* CAN_isr */
#define CAN_isr__INTC_CLR_EN_REG CYREG_CM0_ICER
#define CAN_isr__INTC_CLR_PD_REG CYREG_CM0_ICPR
#define CAN_isr__INTC_MASK 0x8000000u
#define CAN_isr__INTC_NUMBER 27u
#define CAN_isr__INTC_PRIOR_MASK 0xC0000000u
#define CAN_isr__INTC_PRIOR_NUM 3u
#define CAN_isr__INTC_PRIOR_REG CYREG_CM0_IPR6
#define CAN_isr__INTC_SET_EN_REG CYREG_CM0_ISER
#define CAN_isr__INTC_SET_PD_REG CYREG_CM0_ISPR

/* RX_1 */
#define RX_1__0__DR CYREG_GPIO_PRT4_DR
#define RX_1__0__DR_CLR CYREG_GPIO_PRT4_DR_CLR
#define RX_1__0__DR_INV CYREG_GPIO_PRT4_DR_INV
#define RX_1__0__DR_SET CYREG_GPIO_PRT4_DR_SET
#define RX_1__0__HSIOM CYREG_HSIOM_PORT_SEL4
#define RX_1__0__HSIOM_MASK 0x0000000Fu
#define RX_1__0__HSIOM_SHIFT 0u
#define RX_1__0__INTCFG CYREG_GPIO_PRT4_INTR_CFG
#define RX_1__0__INTR CYREG_GPIO_PRT4_INTR
#define RX_1__0__INTR_CFG CYREG_GPIO_PRT4_INTR_CFG
#define RX_1__0__INTSTAT CYREG_GPIO_PRT4_INTR
#define RX_1__0__MASK 0x01u
#define RX_1__0__PC CYREG_GPIO_PRT4_PC
#define RX_1__0__PC2 CYREG_GPIO_PRT4_PC2
#define RX_1__0__PORT 4u
#define RX_1__0__PS CYREG_GPIO_PRT4_PS
#define RX_1__0__SHIFT 0u
#define RX_1__DR CYREG_GPIO_PRT4_DR
#define RX_1__DR_CLR CYREG_GPIO_PRT4_DR_CLR
#define RX_1__DR_INV CYREG_GPIO_PRT4_DR_INV
#define RX_1__DR_SET CYREG_GPIO_PRT4_DR_SET
#define RX_1__INTCFG CYREG_GPIO_PRT4_INTR_CFG
#define RX_1__INTR CYREG_GPIO_PRT4_INTR
#define RX_1__INTR_CFG CYREG_GPIO_PRT4_INTR_CFG
#define RX_1__INTSTAT CYREG_GPIO_PRT4_INTR
#define RX_1__MASK 0x01u
#define RX_1__PC CYREG_GPIO_PRT4_PC
#define RX_1__PC2 CYREG_GPIO_PRT4_PC2
#define RX_1__PORT 4u
#define RX_1__PS CYREG_GPIO_PRT4_PS
#define RX_1__SHIFT 0u

/* TX_1 */
#define TX_1__0__DR CYREG_GPIO_PRT4_DR
#define TX_1__0__DR_CLR CYREG_GPIO_PRT4_DR_CLR
#define TX_1__0__DR_INV CYREG_GPIO_PRT4_DR_INV
#define TX_1__0__DR_SET CYREG_GPIO_PRT4_DR_SET
#define TX_1__0__HSIOM CYREG_HSIOM_PORT_SEL4
#define TX_1__0__HSIOM_MASK 0x000000F0u
#define TX_1__0__HSIOM_SHIFT 4u
#define TX_1__0__INTCFG CYREG_GPIO_PRT4_INTR_CFG
#define TX_1__0__INTR CYREG_GPIO_PRT4_INTR
#define TX_1__0__INTR_CFG CYREG_GPIO_PRT4_INTR_CFG
#define TX_1__0__INTSTAT CYREG_GPIO_PRT4_INTR
#define TX_1__0__MASK 0x02u
#define TX_1__0__PC CYREG_GPIO_PRT4_PC
#define TX_1__0__PC2 CYREG_GPIO_PRT4_PC2
#define TX_1__0__PORT 4u
#define TX_1__0__PS CYREG_GPIO_PRT4_PS
#define TX_1__0__SHIFT 1u
#define TX_1__DR CYREG_GPIO_PRT4_DR
#define TX_1__DR_CLR CYREG_GPIO_PRT4_DR_CLR
#define TX_1__DR_INV CYREG_GPIO_PRT4_DR_INV
#define TX_1__DR_SET CYREG_GPIO_PRT4_DR_SET
#define TX_1__INTCFG CYREG_GPIO_PRT4_INTR_CFG
#define TX_1__INTR CYREG_GPIO_PRT4_INTR
#define TX_1__INTR_CFG CYREG_GPIO_PRT4_INTR_CFG
#define TX_1__INTSTAT CYREG_GPIO_PRT4_INTR
#define TX_1__MASK 0x02u
#define TX_1__PC CYREG_GPIO_PRT4_PC
#define TX_1__PC2 CYREG_GPIO_PRT4_PC2
#define TX_1__PORT 4u
#define TX_1__PS CYREG_GPIO_PRT4_PS
#define TX_1__SHIFT 1u

/* LED_1 */
#define LED_1__0__DR CYREG_GPIO_PRT2_DR
#define LED_1__0__DR_CLR CYREG_GPIO_PRT2_DR_CLR
#define LED_1__0__DR_INV CYREG_GPIO_PRT2_DR_INV
#define LED_1__0__DR_SET CYREG_GPIO_PRT2_DR_SET
#define LED_1__0__HSIOM CYREG_HSIOM_PORT_SEL2
#define LED_1__0__HSIOM_MASK 0x00000F00u
#define LED_1__0__HSIOM_SHIFT 8u
#define LED_1__0__INTCFG CYREG_GPIO_PRT2_INTR_CFG
#define LED_1__0__INTR CYREG_GPIO_PRT2_INTR
#define LED_1__0__INTR_CFG CYREG_GPIO_PRT2_INTR_CFG
#define LED_1__0__INTSTAT CYREG_GPIO_PRT2_INTR
#define LED_1__0__MASK 0x04u
#define LED_1__0__PA__CFG0 CYREG_UDB_PA2_CFG0
#define LED_1__0__PA__CFG1 CYREG_UDB_PA2_CFG1
#define LED_1__0__PA__CFG10 CYREG_UDB_PA2_CFG10
#define LED_1__0__PA__CFG11 CYREG_UDB_PA2_CFG11
#define LED_1__0__PA__CFG12 CYREG_UDB_PA2_CFG12
#define LED_1__0__PA__CFG13 CYREG_UDB_PA2_CFG13
#define LED_1__0__PA__CFG14 CYREG_UDB_PA2_CFG14
#define LED_1__0__PA__CFG2 CYREG_UDB_PA2_CFG2
#define LED_1__0__PA__CFG3 CYREG_UDB_PA2_CFG3
#define LED_1__0__PA__CFG4 CYREG_UDB_PA2_CFG4
#define LED_1__0__PA__CFG5 CYREG_UDB_PA2_CFG5
#define LED_1__0__PA__CFG6 CYREG_UDB_PA2_CFG6
#define LED_1__0__PA__CFG7 CYREG_UDB_PA2_CFG7
#define LED_1__0__PA__CFG8 CYREG_UDB_PA2_CFG8
#define LED_1__0__PA__CFG9 CYREG_UDB_PA2_CFG9
#define LED_1__0__PC CYREG_GPIO_PRT2_PC
#define LED_1__0__PC2 CYREG_GPIO_PRT2_PC2
#define LED_1__0__PORT 2u
#define LED_1__0__PS CYREG_GPIO_PRT2_PS
#define LED_1__0__SHIFT 2u
#define LED_1__DR CYREG_GPIO_PRT2_DR
#define LED_1__DR_CLR CYREG_GPIO_PRT2_DR_CLR
#define LED_1__DR_INV CYREG_GPIO_PRT2_DR_INV
#define LED_1__DR_SET CYREG_GPIO_PRT2_DR_SET
#define LED_1__INTCFG CYREG_GPIO_PRT2_INTR_CFG
#define LED_1__INTR CYREG_GPIO_PRT2_INTR
#define LED_1__INTR_CFG CYREG_GPIO_PRT2_INTR_CFG
#define LED_1__INTSTAT CYREG_GPIO_PRT2_INTR
#define LED_1__MASK 0x04u
#define LED_1__PA__CFG0 CYREG_UDB_PA2_CFG0
#define LED_1__PA__CFG1 CYREG_UDB_PA2_CFG1
#define LED_1__PA__CFG10 CYREG_UDB_PA2_CFG10
#define LED_1__PA__CFG11 CYREG_UDB_PA2_CFG11
#define LED_1__PA__CFG12 CYREG_UDB_PA2_CFG12
#define LED_1__PA__CFG13 CYREG_UDB_PA2_CFG13
#define LED_1__PA__CFG14 CYREG_UDB_PA2_CFG14
#define LED_1__PA__CFG2 CYREG_UDB_PA2_CFG2
#define LED_1__PA__CFG3 CYREG_UDB_PA2_CFG3
#define LED_1__PA__CFG4 CYREG_UDB_PA2_CFG4
#define LED_1__PA__CFG5 CYREG_UDB_PA2_CFG5
#define LED_1__PA__CFG6 CYREG_UDB_PA2_CFG6
#define LED_1__PA__CFG7 CYREG_UDB_PA2_CFG7
#define LED_1__PA__CFG8 CYREG_UDB_PA2_CFG8
#define LED_1__PA__CFG9 CYREG_UDB_PA2_CFG9
#define LED_1__PC CYREG_GPIO_PRT2_PC
#define LED_1__PC2 CYREG_GPIO_PRT2_PC2
#define LED_1__PORT 2u
#define LED_1__PS CYREG_GPIO_PRT2_PS
#define LED_1__SHIFT 2u

/* LED_2 */
#define LED_2__0__DR CYREG_GPIO_PRT2_DR
#define LED_2__0__DR_CLR CYREG_GPIO_PRT2_DR_CLR
#define LED_2__0__DR_INV CYREG_GPIO_PRT2_DR_INV
#define LED_2__0__DR_SET CYREG_GPIO_PRT2_DR_SET
#define LED_2__0__HSIOM CYREG_HSIOM_PORT_SEL2
#define LED_2__0__HSIOM_MASK 0x0000F000u
#define LED_2__0__HSIOM_SHIFT 12u
#define LED_2__0__INTCFG CYREG_GPIO_PRT2_INTR_CFG
#define LED_2__0__INTR CYREG_GPIO_PRT2_INTR
#define LED_2__0__INTR_CFG CYREG_GPIO_PRT2_INTR_CFG
#define LED_2__0__INTSTAT CYREG_GPIO_PRT2_INTR
#define LED_2__0__MASK 0x08u
#define LED_2__0__PA__CFG0 CYREG_UDB_PA2_CFG0
#define LED_2__0__PA__CFG1 CYREG_UDB_PA2_CFG1
#define LED_2__0__PA__CFG10 CYREG_UDB_PA2_CFG10
#define LED_2__0__PA__CFG11 CYREG_UDB_PA2_CFG11
#define LED_2__0__PA__CFG12 CYREG_UDB_PA2_CFG12
#define LED_2__0__PA__CFG13 CYREG_UDB_PA2_CFG13
#define LED_2__0__PA__CFG14 CYREG_UDB_PA2_CFG14
#define LED_2__0__PA__CFG2 CYREG_UDB_PA2_CFG2
#define LED_2__0__PA__CFG3 CYREG_UDB_PA2_CFG3
#define LED_2__0__PA__CFG4 CYREG_UDB_PA2_CFG4
#define LED_2__0__PA__CFG5 CYREG_UDB_PA2_CFG5
#define LED_2__0__PA__CFG6 CYREG_UDB_PA2_CFG6
#define LED_2__0__PA__CFG7 CYREG_UDB_PA2_CFG7
#define LED_2__0__PA__CFG8 CYREG_UDB_PA2_CFG8
#define LED_2__0__PA__CFG9 CYREG_UDB_PA2_CFG9
#define LED_2__0__PC CYREG_GPIO_PRT2_PC
#define LED_2__0__PC2 CYREG_GPIO_PRT2_PC2
#define LED_2__0__PORT 2u
#define LED_2__0__PS CYREG_GPIO_PRT2_PS
#define LED_2__0__SHIFT 3u
#define LED_2__DR CYREG_GPIO_PRT2_DR
#define LED_2__DR_CLR CYREG_GPIO_PRT2_DR_CLR
#define LED_2__DR_INV CYREG_GPIO_PRT2_DR_INV
#define LED_2__DR_SET CYREG_GPIO_PRT2_DR_SET
#define LED_2__INTCFG CYREG_GPIO_PRT2_INTR_CFG
#define LED_2__INTR CYREG_GPIO_PRT2_INTR
#define LED_2__INTR_CFG CYREG_GPIO_PRT2_INTR_CFG
#define LED_2__INTSTAT CYREG_GPIO_PRT2_INTR
#define LED_2__MASK 0x08u
#define LED_2__PA__CFG0 CYREG_UDB_PA2_CFG0
#define LED_2__PA__CFG1 CYREG_UDB_PA2_CFG1
#define LED_2__PA__CFG10 CYREG_UDB_PA2_CFG10
#define LED_2__PA__CFG11 CYREG_UDB_PA2_CFG11
#define LED_2__PA__CFG12 CYREG_UDB_PA2_CFG12
#define LED_2__PA__CFG13 CYREG_UDB_PA2_CFG13
#define LED_2__PA__CFG14 CYREG_UDB_PA2_CFG14
#define LED_2__PA__CFG2 CYREG_UDB_PA2_CFG2
#define LED_2__PA__CFG3 CYREG_UDB_PA2_CFG3
#define LED_2__PA__CFG4 CYREG_UDB_PA2_CFG4
#define LED_2__PA__CFG5 CYREG_UDB_PA2_CFG5
#define LED_2__PA__CFG6 CYREG_UDB_PA2_CFG6
#define LED_2__PA__CFG7 CYREG_UDB_PA2_CFG7
#define LED_2__PA__CFG8 CYREG_UDB_PA2_CFG8
#define LED_2__PA__CFG9 CYREG_UDB_PA2_CFG9
#define LED_2__PC CYREG_GPIO_PRT2_PC
#define LED_2__PC2 CYREG_GPIO_PRT2_PC2
#define LED_2__PORT 2u
#define LED_2__PS CYREG_GPIO_PRT2_PS
#define LED_2__SHIFT 3u

/* LED_3 */
#define LED_3__0__DR CYREG_GPIO_PRT2_DR
#define LED_3__0__DR_CLR CYREG_GPIO_PRT2_DR_CLR
#define LED_3__0__DR_INV CYREG_GPIO_PRT2_DR_INV
#define LED_3__0__DR_SET CYREG_GPIO_PRT2_DR_SET
#define LED_3__0__HSIOM CYREG_HSIOM_PORT_SEL2
#define LED_3__0__HSIOM_MASK 0x000F0000u
#define LED_3__0__HSIOM_SHIFT 16u
#define LED_3__0__INTCFG CYREG_GPIO_PRT2_INTR_CFG
#define LED_3__0__INTR CYREG_GPIO_PRT2_INTR
#define LED_3__0__INTR_CFG CYREG_GPIO_PRT2_INTR_CFG
#define LED_3__0__INTSTAT CYREG_GPIO_PRT2_INTR
#define LED_3__0__MASK 0x10u
#define LED_3__0__PA__CFG0 CYREG_UDB_PA2_CFG0
#define LED_3__0__PA__CFG1 CYREG_UDB_PA2_CFG1
#define LED_3__0__PA__CFG10 CYREG_UDB_PA2_CFG10
#define LED_3__0__PA__CFG11 CYREG_UDB_PA2_CFG11
#define LED_3__0__PA__CFG12 CYREG_UDB_PA2_CFG12
#define LED_3__0__PA__CFG13 CYREG_UDB_PA2_CFG13
#define LED_3__0__PA__CFG14 CYREG_UDB_PA2_CFG14
#define LED_3__0__PA__CFG2 CYREG_UDB_PA2_CFG2
#define LED_3__0__PA__CFG3 CYREG_UDB_PA2_CFG3
#define LED_3__0__PA__CFG4 CYREG_UDB_PA2_CFG4
#define LED_3__0__PA__CFG5 CYREG_UDB_PA2_CFG5
#define LED_3__0__PA__CFG6 CYREG_UDB_PA2_CFG6
#define LED_3__0__PA__CFG7 CYREG_UDB_PA2_CFG7
#define LED_3__0__PA__CFG8 CYREG_UDB_PA2_CFG8
#define LED_3__0__PA__CFG9 CYREG_UDB_PA2_CFG9
#define LED_3__0__PC CYREG_GPIO_PRT2_PC
#define LED_3__0__PC2 CYREG_GPIO_PRT2_PC2
#define LED_3__0__PORT 2u
#define LED_3__0__PS CYREG_GPIO_PRT2_PS
#define LED_3__0__SHIFT 4u
#define LED_3__DR CYREG_GPIO_PRT2_DR
#define LED_3__DR_CLR CYREG_GPIO_PRT2_DR_CLR
#define LED_3__DR_INV CYREG_GPIO_PRT2_DR_INV
#define LED_3__DR_SET CYREG_GPIO_PRT2_DR_SET
#define LED_3__INTCFG CYREG_GPIO_PRT2_INTR_CFG
#define LED_3__INTR CYREG_GPIO_PRT2_INTR
#define LED_3__INTR_CFG CYREG_GPIO_PRT2_INTR_CFG
#define LED_3__INTSTAT CYREG_GPIO_PRT2_INTR
#define LED_3__MASK 0x10u
#define LED_3__PA__CFG0 CYREG_UDB_PA2_CFG0
#define LED_3__PA__CFG1 CYREG_UDB_PA2_CFG1
#define LED_3__PA__CFG10 CYREG_UDB_PA2_CFG10
#define LED_3__PA__CFG11 CYREG_UDB_PA2_CFG11
#define LED_3__PA__CFG12 CYREG_UDB_PA2_CFG12
#define LED_3__PA__CFG13 CYREG_UDB_PA2_CFG13
#define LED_3__PA__CFG14 CYREG_UDB_PA2_CFG14
#define LED_3__PA__CFG2 CYREG_UDB_PA2_CFG2
#define LED_3__PA__CFG3 CYREG_UDB_PA2_CFG3
#define LED_3__PA__CFG4 CYREG_UDB_PA2_CFG4
#define LED_3__PA__CFG5 CYREG_UDB_PA2_CFG5
#define LED_3__PA__CFG6 CYREG_UDB_PA2_CFG6
#define LED_3__PA__CFG7 CYREG_UDB_PA2_CFG7
#define LED_3__PA__CFG8 CYREG_UDB_PA2_CFG8
#define LED_3__PA__CFG9 CYREG_UDB_PA2_CFG9
#define LED_3__PC CYREG_GPIO_PRT2_PC
#define LED_3__PC2 CYREG_GPIO_PRT2_PC2
#define LED_3__PORT 2u
#define LED_3__PS CYREG_GPIO_PRT2_PS
#define LED_3__SHIFT 4u

/* LED_4 */
#define LED_4__0__DR CYREG_GPIO_PRT2_DR
#define LED_4__0__DR_CLR CYREG_GPIO_PRT2_DR_CLR
#define LED_4__0__DR_INV CYREG_GPIO_PRT2_DR_INV
#define LED_4__0__DR_SET CYREG_GPIO_PRT2_DR_SET
#define LED_4__0__HSIOM CYREG_HSIOM_PORT_SEL2
#define LED_4__0__HSIOM_MASK 0x00F00000u
#define LED_4__0__HSIOM_SHIFT 20u
#define LED_4__0__INTCFG CYREG_GPIO_PRT2_INTR_CFG
#define LED_4__0__INTR CYREG_GPIO_PRT2_INTR
#define LED_4__0__INTR_CFG CYREG_GPIO_PRT2_INTR_CFG
#define LED_4__0__INTSTAT CYREG_GPIO_PRT2_INTR
#define LED_4__0__MASK 0x20u
#define LED_4__0__PA__CFG0 CYREG_UDB_PA2_CFG0
#define LED_4__0__PA__CFG1 CYREG_UDB_PA2_CFG1
#define LED_4__0__PA__CFG10 CYREG_UDB_PA2_CFG10
#define LED_4__0__PA__CFG11 CYREG_UDB_PA2_CFG11
#define LED_4__0__PA__CFG12 CYREG_UDB_PA2_CFG12
#define LED_4__0__PA__CFG13 CYREG_UDB_PA2_CFG13
#define LED_4__0__PA__CFG14 CYREG_UDB_PA2_CFG14
#define LED_4__0__PA__CFG2 CYREG_UDB_PA2_CFG2
#define LED_4__0__PA__CFG3 CYREG_UDB_PA2_CFG3
#define LED_4__0__PA__CFG4 CYREG_UDB_PA2_CFG4
#define LED_4__0__PA__CFG5 CYREG_UDB_PA2_CFG5
#define LED_4__0__PA__CFG6 CYREG_UDB_PA2_CFG6
#define LED_4__0__PA__CFG7 CYREG_UDB_PA2_CFG7
#define LED_4__0__PA__CFG8 CYREG_UDB_PA2_CFG8
#define LED_4__0__PA__CFG9 CYREG_UDB_PA2_CFG9
#define LED_4__0__PC CYREG_GPIO_PRT2_PC
#define LED_4__0__PC2 CYREG_GPIO_PRT2_PC2
#define LED_4__0__PORT 2u
#define LED_4__0__PS CYREG_GPIO_PRT2_PS
#define LED_4__0__SHIFT 5u
#define LED_4__DR CYREG_GPIO_PRT2_DR
#define LED_4__DR_CLR CYREG_GPIO_PRT2_DR_CLR
#define LED_4__DR_INV CYREG_GPIO_PRT2_DR_INV
#define LED_4__DR_SET CYREG_GPIO_PRT2_DR_SET
#define LED_4__INTCFG CYREG_GPIO_PRT2_INTR_CFG
#define LED_4__INTR CYREG_GPIO_PRT2_INTR
#define LED_4__INTR_CFG CYREG_GPIO_PRT2_INTR_CFG
#define LED_4__INTSTAT CYREG_GPIO_PRT2_INTR
#define LED_4__MASK 0x20u
#define LED_4__PA__CFG0 CYREG_UDB_PA2_CFG0
#define LED_4__PA__CFG1 CYREG_UDB_PA2_CFG1
#define LED_4__PA__CFG10 CYREG_UDB_PA2_CFG10
#define LED_4__PA__CFG11 CYREG_UDB_PA2_CFG11
#define LED_4__PA__CFG12 CYREG_UDB_PA2_CFG12
#define LED_4__PA__CFG13 CYREG_UDB_PA2_CFG13
#define LED_4__PA__CFG14 CYREG_UDB_PA2_CFG14
#define LED_4__PA__CFG2 CYREG_UDB_PA2_CFG2
#define LED_4__PA__CFG3 CYREG_UDB_PA2_CFG3
#define LED_4__PA__CFG4 CYREG_UDB_PA2_CFG4
#define LED_4__PA__CFG5 CYREG_UDB_PA2_CFG5
#define LED_4__PA__CFG6 CYREG_UDB_PA2_CFG6
#define LED_4__PA__CFG7 CYREG_UDB_PA2_CFG7
#define LED_4__PA__CFG8 CYREG_UDB_PA2_CFG8
#define LED_4__PA__CFG9 CYREG_UDB_PA2_CFG9
#define LED_4__PC CYREG_GPIO_PRT2_PC
#define LED_4__PC2 CYREG_GPIO_PRT2_PC2
#define LED_4__PORT 2u
#define LED_4__PS CYREG_GPIO_PRT2_PS
#define LED_4__SHIFT 5u

/* Miscellaneous */
#define CY_PROJECT_NAME "Test_CAN_Module_2"
#define CY_VERSION "PSoC Creator  3.3 CP3"
#define CYDEV_BANDGAP_VOLTAGE 1.024
#define CYDEV_BCLK__HFCLK__HZ 24000000U
#define CYDEV_BCLK__HFCLK__KHZ 24000U
#define CYDEV_BCLK__HFCLK__MHZ 24U
#define CYDEV_BCLK__SYSCLK__HZ 24000000U
#define CYDEV_BCLK__SYSCLK__KHZ 24000U
#define CYDEV_BCLK__SYSCLK__MHZ 24U
#define CYDEV_CHIP_DIE_LEOPARD 1u
#define CYDEV_CHIP_DIE_PANTHER 19u
#define CYDEV_CHIP_DIE_PSOC4A 11u
#define CYDEV_CHIP_DIE_PSOC5LP 18u
#define CYDEV_CHIP_DIE_TMA4 2u
#define CYDEV_CHIP_DIE_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_PSOC3 1u
#define CYDEV_CHIP_FAMILY_PSOC4 2u
#define CYDEV_CHIP_FAMILY_PSOC5 3u
#define CYDEV_CHIP_FAMILY_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_USED CYDEV_CHIP_FAMILY_PSOC4
#define CYDEV_CHIP_JTAG_ID 0x112D11A1u
#define CYDEV_CHIP_MEMBER_3A 1u
#define CYDEV_CHIP_MEMBER_4A 11u
#define CYDEV_CHIP_MEMBER_4C 16u
#define CYDEV_CHIP_MEMBER_4D 7u
#define CYDEV_CHIP_MEMBER_4E 4u
#define CYDEV_CHIP_MEMBER_4F 12u
#define CYDEV_CHIP_MEMBER_4G 2u
#define CYDEV_CHIP_MEMBER_4H 10u
#define CYDEV_CHIP_MEMBER_4I 15u
#define CYDEV_CHIP_MEMBER_4J 8u
#define CYDEV_CHIP_MEMBER_4K 9u
#define CYDEV_CHIP_MEMBER_4L 14u
#define CYDEV_CHIP_MEMBER_4M 13u
#define CYDEV_CHIP_MEMBER_4N 6u
#define CYDEV_CHIP_MEMBER_4O 5u
#define CYDEV_CHIP_MEMBER_4U 3u
#define CYDEV_CHIP_MEMBER_5A 18u
#define CYDEV_CHIP_MEMBER_5B 17u
#define CYDEV_CHIP_MEMBER_UNKNOWN 0u
#define CYDEV_CHIP_MEMBER_USED CYDEV_CHIP_MEMBER_4M
#define CYDEV_CHIP_DIE_EXPECT CYDEV_CHIP_MEMBER_USED
#define CYDEV_CHIP_DIE_ACTUAL CYDEV_CHIP_DIE_EXPECT
#define CYDEV_CHIP_REV_LEOPARD_ES1 0u
#define CYDEV_CHIP_REV_LEOPARD_ES2 1u
#define CYDEV_CHIP_REV_LEOPARD_ES3 3u
#define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3u
#define CYDEV_CHIP_REV_PANTHER_ES0 0u
#define CYDEV_CHIP_REV_PANTHER_ES1 1u
#define CYDEV_CHIP_REV_PANTHER_PRODUCTION 1u
#define CYDEV_CHIP_REV_PSOC4A_ES0 17u
#define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17u
#define CYDEV_CHIP_REV_PSOC5LP_ES0 0u
#define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0u
#define CYDEV_CHIP_REV_TMA4_ES 17u
#define CYDEV_CHIP_REV_TMA4_ES2 33u
#define CYDEV_CHIP_REV_TMA4_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_3A_ES1 0u
#define CYDEV_CHIP_REVISION_3A_ES2 1u
#define CYDEV_CHIP_REVISION_3A_ES3 3u
#define CYDEV_CHIP_REVISION_3A_PRODUCTION 3u
#define CYDEV_CHIP_REVISION_4A_ES0 17u
#define CYDEV_CHIP_REVISION_4A_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4C_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4D_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4E_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0u
#define CYDEV_CHIP_REVISION_4G_ES 17u
#define CYDEV_CHIP_REVISION_4G_ES2 33u
#define CYDEV_CHIP_REVISION_4G_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4H_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4I_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4J_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4K_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4L_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4M_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4N_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4O_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4U_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_5A_ES0 0u
#define CYDEV_CHIP_REVISION_5A_ES1 1u
#define CYDEV_CHIP_REVISION_5A_PRODUCTION 1u
#define CYDEV_CHIP_REVISION_5B_ES0 0u
#define CYDEV_CHIP_REVISION_5B_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_USED CYDEV_CHIP_REVISION_4M_PRODUCTION
#define CYDEV_CHIP_REV_EXPECT CYDEV_CHIP_REVISION_USED
#define CYDEV_CONFIG_READ_ACCELERATOR 1
#define CYDEV_CONFIG_UNUSED_IO_AllowButWarn 0
#define CYDEV_CONFIG_UNUSED_IO CYDEV_CONFIG_UNUSED_IO_AllowButWarn
#define CYDEV_CONFIG_UNUSED_IO_AllowWithInfo 1
#define CYDEV_CONFIG_UNUSED_IO_Disallowed 2
#define CYDEV_CONFIGURATION_COMPRESSED 1
#define CYDEV_CONFIGURATION_MODE_COMPRESSED 0
#define CYDEV_CONFIGURATION_MODE CYDEV_CONFIGURATION_MODE_COMPRESSED
#define CYDEV_CONFIGURATION_MODE_DMA 2
#define CYDEV_CONFIGURATION_MODE_UNCOMPRESSED 1
#define CYDEV_DEBUG_PROTECT_KILL 4
#define CYDEV_DEBUG_PROTECT_OPEN 1
#define CYDEV_DEBUG_PROTECT CYDEV_DEBUG_PROTECT_OPEN
#define CYDEV_DEBUG_PROTECT_PROTECTED 2
#define CYDEV_DEBUGGING_DPS_Disable 3
#define CYDEV_DEBUGGING_DPS_SWD 2
#define CYDEV_DEBUGGING_DPS CYDEV_DEBUGGING_DPS_SWD
#define CYDEV_DEBUGGING_ENABLE 1
#define CYDEV_DFT_SELECT_CLK0 10u
#define CYDEV_DFT_SELECT_CLK1 11u
#define CYDEV_DMA_CHANNELS_AVAILABLE 8
#define CYDEV_HEAP_SIZE 0x80
#define CYDEV_IMO_TRIMMED_BY_USB 0u
#define CYDEV_IMO_TRIMMED_BY_WCO 1u
#define CYDEV_INTR_NUMBER_DMA 13u
#define CYDEV_IS_EXPORTING_CODE 0
#define CYDEV_IS_IMPORTING_CODE 0
#define CYDEV_PROJ_TYPE 0
#define CYDEV_PROJ_TYPE_BOOTLOADER 1
#define CYDEV_PROJ_TYPE_LAUNCHER 5
#define CYDEV_PROJ_TYPE_LOADABLE 2
#define CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER 4
#define CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER 3
#define CYDEV_PROJ_TYPE_STANDARD 0
#define CYDEV_STACK_SIZE 0x0800
#define CYDEV_USE_BUNDLED_CMSIS 1
#define CYDEV_VARIABLE_VDDA 1
#define CYDEV_VDDA 3.3
#define CYDEV_VDDA_MV 3300
#define CYDEV_VDDD 3.3
#define CYDEV_VDDD_MV 3300
#define CYDEV_VDDIO 3.3
#define CYDEV_VDDIO_MV 3300
#define CYDEV_WDT_GENERATE_ISR 1u
#define CYIPBLOCK_m0s8can_VERSION 1
#define CYIPBLOCK_m0s8cpussv2_VERSION 1
#define CYIPBLOCK_m0s8csd_VERSION 1
#define CYIPBLOCK_m0s8ioss_VERSION 1
#define CYIPBLOCK_m0s8lcd_VERSION 2
#define CYIPBLOCK_m0s8lpcomp_VERSION 2
#define CYIPBLOCK_m0s8peri_VERSION 1
#define CYIPBLOCK_m0s8scb_VERSION 2
#define CYIPBLOCK_m0s8srssv2_VERSION 1
#define CYIPBLOCK_m0s8tcpwm_VERSION 2
#define CYIPBLOCK_m0s8udbif_VERSION 1
#define CYIPBLOCK_m0s8wco_VERSION 1
#define CYIPBLOCK_s8pass4al_VERSION 1
#define DMA_CHANNELS_USED__MASK 0u
#define CYDEV_BOOTLOADER_ENABLE 0

#endif /* INCLUDED_CYFITTER_H */

# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\Henry Alberto\Desktop\Protocolos\CAN_NODO_1_BIDIRECCIONAL.cydsn\CAN_NODO_1_BIDIRECCIONAL.cyprj
# Date: Thu, 22 Sep 2016 09:24:08 GMT
#set_units -time ns
create_clock -name {CyXTAL} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/xtal}]]
create_clock -name {CyMASTER_CLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/clk_sync}]]
create_generated_clock -name {CyBUS_CLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2 3} [list [get_pins {ClockBlock/clk_bus_glb}]]
create_clock -name {CyBUS_CLK(fixed-function)} -period 41.666666666666664 -waveform {0 20.8333333333333} [get_pins {ClockBlock/clk_bus_glb_ff}]
create_clock -name {CyILO} -period 1000000 -waveform {0 500000} [list [get_pins {ClockBlock/ilo}] [get_pins {ClockBlock/clk_100k}] [get_pins {ClockBlock/clk_1k}] [get_pins {ClockBlock/clk_32k}]]
create_clock -name {CyPLL_OUT} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/pllout}]]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]


# Component constraints for C:\Users\Henry Alberto\Desktop\Protocolos\CAN_NODO_1_BIDIRECCIONAL.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\Henry Alberto\Desktop\Protocolos\CAN_NODO_1_BIDIRECCIONAL.cydsn\CAN_NODO_1_BIDIRECCIONAL.cyprj
# Date: Thu, 22 Sep 2016 09:24:01 GMT

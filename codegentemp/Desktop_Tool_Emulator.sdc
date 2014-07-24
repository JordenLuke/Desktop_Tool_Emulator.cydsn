# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\Milo\Documents\PSoC Creator\DPI_Desktop_Tester\Desktop_Tool_Emulator.cydsn\Desktop_Tool_Emulator.cyprj
# Date: Wed, 23 Jul 2014 21:34:27 GMT
#set_units -time ns
create_clock -name {UART_1_SCBCLK(FFB)} -period 8666.6666666666661 -waveform {0 4333.33333333333} [list [get_pins {ClockBlock/ff_div_2}]]
create_clock -name {I2C_1_SCBCLK(FFB)} -period 1250 -waveform {0 625} [list [get_pins {ClockBlock/ff_div_3}]]
create_clock -name {CyHFCLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/hfclk}]]
create_generated_clock -name {SPIM_1_IntClock} -source [get_pins {ClockBlock/hfclk}] -edges {1 13 25} [list [get_pins {ClockBlock/udb_div_0}]]
create_generated_clock -name {UART_1_SCBCLK} -source [get_pins {ClockBlock/hfclk}] -edges {1 209 417} -nominal_period 8666.6666666666661 [list]
create_generated_clock -name {I2C_1_SCBCLK} -source [get_pins {ClockBlock/hfclk}] -edges {1 31 61} [list]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CySYSCLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/sysclk}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyLFCLK} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]


# Component constraints for C:\Users\Milo\Documents\PSoC Creator\DPI_Desktop_Tester\Desktop_Tool_Emulator.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\Milo\Documents\PSoC Creator\DPI_Desktop_Tester\Desktop_Tool_Emulator.cydsn\Desktop_Tool_Emulator.cyprj
# Date: Wed, 23 Jul 2014 21:34:24 GMT

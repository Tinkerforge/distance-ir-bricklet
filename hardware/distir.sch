EESchema Schematic File Version 2  date Fr 30 Dez 2011 10:02:14 CET
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:tinkerforge
LIBS:distir-cache
EELAYER 25  0
EELAYER END
$Descr A4 11700 8267
encoding utf-8
Sheet 1 1
Title "Dist-IR Bricklet"
Date "28 dec 2011"
Rev "1.1"
Comp "Tinkerforge GmbH"
Comment1 "Licensed under CERN OHL v.1.1"
Comment2 "Copyright (©) 2011, B.Nordmeyer <bastian@tinkerforge.com>"
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 550  7200 0    40   ~ 0
Copyright Tinkerforge GmbH 2011.\nThis documentation describes Open Hardware and is licensed under the\nCERN OHL v. 1.1.\nYou may redistribute and modify this documentation under the terms of the\nCERN OHL v.1.1. (http://ohwr.org/cernohl). This documentation is distributed\nWITHOUT ANY EXPRESS OR IMPLIED WARRANTY, INCLUDING OF\nMERCHANTABILITY, SATISFACTORY QUALITY AND FITNESS FOR A\nPARTICULAR PURPOSE. Please see the CERN OHL v.1.1 for applicable\nconditions\n
Wire Wire Line
	3500 2900 3500 3250
Wire Wire Line
	3500 3250 3350 3250
Wire Wire Line
	6750 3050 6750 3500
Wire Wire Line
	6750 3050 3350 3050
Wire Wire Line
	4550 4500 4500 4500
Connection ~ 7700 3500
Wire Wire Line
	6750 3500 8050 3500
Connection ~ 7700 4100
Wire Wire Line
	7700 3950 7700 4150
Wire Wire Line
	3350 3650 3700 3650
Wire Wire Line
	4500 4900 4950 4900
Wire Wire Line
	3350 3350 3700 3350
Connection ~ 3600 4700
Wire Wire Line
	3700 4600 3600 4600
Wire Wire Line
	3600 4600 3600 5000
Wire Wire Line
	3600 4900 3700 4900
Wire Wire Line
	2900 4200 2900 4100
Wire Wire Line
	3350 3550 3500 3550
Wire Wire Line
	3500 3550 3500 4800
Wire Wire Line
	3500 4800 3700 4800
Wire Wire Line
	3600 4700 3700 4700
Connection ~ 3600 4900
Wire Wire Line
	3350 3450 3700 3450
Wire Wire Line
	4500 4800 4950 4800
Wire Wire Line
	8050 3400 7950 3400
Wire Wire Line
	7700 4100 7950 4100
Wire Wire Line
	7950 4100 7950 3400
Wire Wire Line
	7700 3500 7700 3550
Wire Wire Line
	8050 3300 8050 2800
Wire Wire Line
	8050 2800 8000 2800
Wire Wire Line
	7200 2800 7500 2800
Connection ~ 7400 2800
Wire Wire Line
	4500 4500 4500 4600
Wire Wire Line
	4950 4500 4950 4650
Connection ~ 4500 4500
Wire Wire Line
	7400 3300 7400 3350
Wire Wire Line
	3350 3150 3600 3150
Wire Wire Line
	3600 3150 3600 3300
$Comp
L R R1
U 1 1 4CA9AC9E
P 7400 3050
F 0 "R1" V 7480 3050 50  0000 C CNN
F 1 "DNP" V 7400 3050 50  0000 C CNN
F 2 "0603" H 7400 3050 60  0001 C CNN
	1    7400 3050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR7
U 1 1 4CA9ACE2
P 7400 3350
F 0 "#PWR7" H 7400 3350 30  0001 C CNN
F 1 "GND" H 7400 3280 30  0001 C CNN
	1    7400 3350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR6
U 1 1 4CE13025
P 4950 4650
F 0 "#PWR6" H 4950 4650 30  0001 C CNN
F 1 "GND" H 4950 4580 30  0001 C CNN
	1    4950 4650
	1    0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 4CE1301F
P 4750 4500
F 0 "C1" V 4600 4500 50  0000 L CNN
F 1 "100nF" V 4850 4500 50  0000 L CNN
F 2 "0603" H 4750 4500 60  0001 C CNN
	1    4750 4500
	0    1    1    0   
$EndComp
NoConn ~ 4500 4700
$Comp
L R R2
U 1 1 4CA9ACAD
P 7750 2800
F 0 "R2" V 7830 2800 50  0000 C CNN
F 1 "1k" V 7750 2800 50  0000 C CNN
F 2 "0603" H 7750 2800 60  0001 C CNN
	1    7750 2800
	0    1    1    0   
$EndComp
NoConn ~ 3350 3750
NoConn ~ 3350 3850
NoConn ~ 3350 3950
$Comp
L CP1 C2
U 1 1 4C697C2F
P 7700 3750
F 0 "C2" H 7750 3850 50  0000 L CNN
F 1 "100µF/10V" H 7750 3650 50  0000 L CNN
F 2 "3528-21" H 7700 3750 60  0001 C CNN
	1    7700 3750
	1    0    0    -1  
$EndComp
Text GLabel 7200 2800 0    60   Output ~ 0
IN_1
$Comp
L GND #PWR8
U 1 1 4C697BDE
P 7700 4150
F 0 "#PWR8" H 7700 4150 30  0001 C CNN
F 1 "GND" H 7700 4080 30  0001 C CNN
	1    7700 4150
	1    0    0    -1  
$EndComp
$Comp
L CONN_3 K1
U 1 1 4C697B8C
P 8400 3400
F 0 "K1" V 8350 3400 50  0000 C CNN
F 1 "CONN_3" V 8450 3400 40  0000 C CNN
F 2 "PIN_ARRAY_3X1" H 8400 3400 60  0001 C CNN
	1    8400 3400
	1    0    0    -1  
$EndComp
$Comp
L DRILL U3
U 1 1 4C693732
P 11000 6700
F 0 "U3" H 11050 6750 60  0001 C CNN
F 1 "DRILL" H 11000 6700 60  0000 C CNN
F 2 "Drill" H 11000 6700 60  0001 C CNN
	1    11000 6700
	1    0    0    -1  
$EndComp
$Comp
L DRILL U2
U 1 1 4C693727
P 11000 6500
F 0 "U2" H 11050 6550 60  0001 C CNN
F 1 "DRILL" H 11000 6500 60  0000 C CNN
F 2 "Drill" H 11000 6500 60  0001 C CNN
	1    11000 6500
	1    0    0    -1  
$EndComp
Text GLabel 3700 3650 2    60   Input ~ 0
IN_1
Text GLabel 4950 4900 2    60   Input ~ 0
SDA
Text GLabel 4950 4800 2    60   Input ~ 0
SCL
Text GLabel 3700 3450 2    60   Output ~ 0
SDA
Text GLabel 3700 3350 2    60   Output ~ 0
SCL
$Comp
L VCC #PWR5
U 1 1 4C5FD35E
P 4500 4500
F 0 "#PWR5" H 4500 4600 30  0001 C CNN
F 1 "VCC" H 4500 4600 30  0000 C CNN
	1    4500 4500
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR4
U 1 1 4C5FD34E
P 3600 5000
F 0 "#PWR4" H 3600 5000 30  0001 C CNN
F 1 "GND" H 3600 4930 30  0001 C CNN
	1    3600 5000
	1    0    0    -1  
$EndComp
$Comp
L CAT24C U1
U 1 1 4C5FD337
P 4100 5000
F 0 "U1" H 3950 5500 60  0000 C CNN
F 1 "M24C64" H 4100 5000 60  0000 C CNN
F 2 "TSSOP8" H 4100 5000 60  0001 C CNN
	1    4100 5000
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR2
U 1 1 4C5FCFB4
P 3500 2900
F 0 "#PWR2" H 3500 3000 30  0001 C CNN
F 1 "VCC" H 3500 3000 30  0000 C CNN
	1    3500 2900
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR3
U 1 1 4C5FCF5E
P 3600 3300
F 0 "#PWR3" H 3600 3300 30  0001 C CNN
F 1 "GND" H 3600 3230 30  0001 C CNN
	1    3600 3300
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR1
U 1 1 4C5FCF4F
P 2900 4200
F 0 "#PWR1" H 2900 4200 30  0001 C CNN
F 1 "GND" H 2900 4130 30  0001 C CNN
	1    2900 4200
	1    0    0    -1  
$EndComp
$Comp
L CON-SENSOR P1
U 1 1 4C5FCF27
P 2900 3500
F 0 "P1" H 2650 4050 60  0000 C CNN
F 1 "CON-SENSOR" V 3050 3500 60  0000 C CNN
F 2 "CON-SENSOR" H 2900 3500 60  0001 C CNN
	1    2900 3500
	-1   0    0    -1  
$EndComp
$EndSCHEMATC

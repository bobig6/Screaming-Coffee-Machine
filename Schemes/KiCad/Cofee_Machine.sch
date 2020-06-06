EESchema Schematic File Version 4
LIBS:Cofee_Machine (1)-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L coffee_machine_examples:Heater U?
U 1 1 5DFA45F5
P 4200 4300
F 0 "U?" H 4200 4350 50  0000 L CNN
F 1 "Heater" H 4100 4250 50  0000 L CNN
F 2 "" H 4100 4300 50  0001 C CNN
F 3 "" H 4100 4300 50  0001 C CNN
F 4 "Heats the coffee" H 4200 4300 50  0001 C CNN "Description"
	1    4200 4300
	1    0    0    -1  
$EndComp
$Comp
L coffee_machine_examples:Pump U?
U 1 1 5DFA4690
P 7350 4900
F 0 "U?" H 7350 4950 50  0000 L CNN
F 1 "Pump" H 7350 4850 50  0000 L CNN
F 2 "" H 7350 4900 50  0001 C CNN
F 3 "" H 7350 4900 50  0001 C CNN
	1    7350 4900
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST SW?
U 1 1 5DFA7310
P 5900 4000
F 0 "SW?" V 5809 4098 50  0000 L CNN
F 1 "SW_SPST" V 5900 4098 50  0000 L CNN
F 2 "" H 5900 4000 50  0001 C CNN
F 3 "" H 5900 4000 50  0001 C CNN
F 4 "Cream Switch" V 5991 4098 50  0000 L CNN "Description"
	1    5900 4000
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_SPST SW?
U 1 1 5DFA739B
P 6900 4000
F 0 "SW?" V 6809 4098 50  0000 L CNN
F 1 "SW_SPST" V 6900 4098 50  0000 L CNN
F 2 "" H 6900 4000 50  0001 C CNN
F 3 "" H 6900 4000 50  0001 C CNN
F 4 "Coffee switch" V 6991 4098 50  0000 L CNN "Description"
	1    6900 4000
	0    1    1    0   
$EndComp
$Comp
L Device:LED D?
U 1 1 5DFA7778
P 3750 3550
F 0 "D?" V 3833 3432 50  0000 R CNN
F 1 "LED" V 3742 3432 50  0000 R CNN
F 2 "" H 3750 3550 50  0001 C CNN
F 3 "~" H 3750 3550 50  0001 C CNN
F 4 "Ready LED" V 3651 3432 50  0000 R CNN "Ddescription"
	1    3750 3550
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_WallPlug_Earth P?
U 1 1 5DFA806C
P 2550 3300
F 0 "P?" H 2615 3625 50  0000 C CNN
F 1 "Conn_WallPlug_Earth" H 2615 3534 50  0000 C CNN
F 2 "" H 2950 3300 50  0001 C CNN
F 3 "~" H 2950 3300 50  0001 C CNN
	1    2550 3300
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST SW?
U 1 1 5DFA886B
P 3450 3200
F 0 "SW?" H 3450 3525 50  0000 C CNN
F 1 "SW_SPST" H 3450 3434 50  0000 C CNN
F 2 "" H 3450 3200 50  0001 C CNN
F 3 "" H 3450 3200 50  0001 C CNN
F 4 "Main Switch" H 3450 3343 50  0000 C CNN "Description"
	1    3450 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	2850 3200 2900 3200
Wire Wire Line
	3650 3200 3750 3200
Wire Wire Line
	3750 3200 3750 3400
Wire Wire Line
	3750 3700 3750 3850
Wire Wire Line
	3800 4450 3750 4450
Wire Wire Line
	3200 4450 3200 3400
Wire Wire Line
	3200 3400 2900 3400
Connection ~ 3750 4450
Wire Wire Line
	3750 4450 3200 4450
$Comp
L power:GND #PWR?
U 1 1 5DFA8F25
P 4150 4750
F 0 "#PWR?" H 4150 4500 50  0001 C CNN
F 1 "GND" H 4155 4577 50  0000 C CNN
F 2 "" H 4150 4750 50  0001 C CNN
F 3 "" H 4150 4750 50  0001 C CNN
	1    4150 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	5050 4200 5050 4450
Wire Wire Line
	5050 3800 5050 3200
Wire Wire Line
	5050 3200 3750 3200
Connection ~ 3750 3200
Wire Wire Line
	5050 5100 4700 5100
Wire Wire Line
	4700 5100 4700 3850
Wire Wire Line
	4700 3850 3750 3850
Connection ~ 3750 3850
Wire Wire Line
	3750 3850 3750 4150
Wire Wire Line
	5050 3200 5900 3200
Connection ~ 5050 3200
Wire Wire Line
	5900 3200 5900 3800
Wire Wire Line
	5900 4200 5900 4450
Wire Wire Line
	5900 4450 5050 4450
Connection ~ 5050 4450
Wire Wire Line
	5050 4450 5050 4800
Wire Wire Line
	5900 3200 6900 3200
Wire Wire Line
	6900 3200 6900 3800
Connection ~ 5900 3200
Wire Wire Line
	6900 4200 6900 4350
Wire Wire Line
	6900 4800 6950 4800
Wire Wire Line
	6950 5000 6900 5000
Wire Wire Line
	6900 5000 6900 5500
Wire Wire Line
	6900 5500 3200 5500
Wire Wire Line
	3200 5500 3200 4450
Connection ~ 3200 4450
Text GLabel 2350 2900 0    50   Input ~ 0
SOCKET-P
Wire Wire Line
	2900 2900 2900 3200
Wire Wire Line
	2350 2900 2900 2900
Connection ~ 2900 3200
Wire Wire Line
	2900 3200 3250 3200
Text GLabel 2350 3550 0    50   Input ~ 0
SOCKET-N
Wire Wire Line
	2350 3550 2900 3550
Wire Wire Line
	2900 3550 2900 3400
Connection ~ 2900 3400
Wire Wire Line
	2900 3400 2850 3400
Text GLabel 2350 3900 0    50   Input ~ 0
SOCKET-GND
Wire Wire Line
	2350 3900 2850 3900
Wire Wire Line
	2850 3900 2850 3600
$Comp
L Cofee_Machine-(1)-rescue:thermostat-coffee_machine_examples~(1) U?
U 1 1 5DFA6A00
P 5050 4000
F 0 "U?" H 5178 4046 50  0001 L CNN
F 1 "thermostat" H 5178 4046 50  0000 L CNN
F 2 "" H 5050 4000 50  0001 C CNN
F 3 "" H 5050 4000 50  0001 C CNN
F 4 "Red" H 5178 3955 50  0000 L CNN "Description"
	1    5050 4000
	1    0    0    -1  
$EndComp
$Comp
L Cofee_Machine-(1)-rescue:thermostat-coffee_machine_examples~(1) U?
U 1 1 5DFA6FBD
P 5050 4900
F 0 "U?" H 5178 4946 50  0001 L CNN
F 1 "thermostat" H 5178 4946 50  0000 L CNN
F 2 "" H 5050 4900 50  0001 C CNN
F 3 "" H 5050 4900 50  0001 C CNN
F 4 "Black" H 5178 4855 50  0000 L CNN "Description"
	1    5050 4900
	1    0    0    -1  
$EndComp
Text GLabel 3700 2700 0    50   Input ~ 0
GLOBAL-MS
Wire Wire Line
	3700 2700 3750 2700
Wire Wire Line
	3750 2700 3750 3200
Wire Wire Line
	7200 4350 6900 4350
Connection ~ 6900 4350
Wire Wire Line
	6900 4350 6900 4800
Text GLabel 7200 4350 2    50   Input ~ 0
GLOBAL-COFFEE-SWITCH
$EndSCHEMATC

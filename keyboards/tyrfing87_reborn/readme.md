# tyrfing87_reborn

![tyrfing87_reborn](imgur.com image replace me!)

*A short description of the keyboard/project*

* Keyboard Maintainer: [Vaarai](https://github.com/Vaarai)
* Hardware Supported: *The PCBs, controllers supported*
* Hardware Availability: *Links to where you can find this hardware*

Make example for this keyboard (after setting up your build environment):

    make tyrfing87_reborn:default

Flashing example for this keyboard:

    make tyrfing87_reborn:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Hardware

*Mapping = Microcontroler -> PCB -> Keyboard*

+------+------+------|==|------+------+------+
| KBRD |  PCB |  MCU |==|  MCU |  PCB | KBRD |
+------+------+------|==|------+------+------+
|   R6 |   13 |  PC7 |==|  PD6 |   12 |  C12 |
|      |  3V3 |  3V3 |==|  PB7 |   11 |  C11 |
|      |  REF | AREF |==|  PB6 |   10 |  C10 |
|      |   A0 |  PF7 |==|  PB5 |    9 |   C9 |
|      |   A1 |  PF6 |==|  PB4 |    8 |   C8 |
|   R5 |   A2 |  PF5 |==|  PE6 |    7 |   C7 |
|   R4 |   A3 |  PF4 |==|  PD7 |    6 |   C6 |
|   R3 |   A4 |  PF1 |==|  PC6 |    5 |   C5 |
|   R2 |   A5 |  PF0 |==|  PD4 |    4 |   C4 |
|      | AREF | AREF |==|  PD0 |    3 |   C3 |
|      |  GND |  GND |==|  PD1 |    2 |   C2 |
|      |   5V |   5V |==|  GND |  GND |      |
|      |  RST |  RST |==|  RST |  RST |      |
|      |  GND |  GND |==|  PD2 |  RX1 |   C1 |
|      |  VIN |  VIN |==|  PD3 |  TX1 |   C0 |
|   R1 | MISO |  PB3 |==|  PB0 |   SS |      |
|   R0 |  SCK |  PB1 |==|  PB2 | MOSI |      |
+------+------+------|==|------+------+------+

*KLE Description of ROW/COL mapping of the existing hardware matrix (7x13)*

["R0\nC0",{x:1},"R0\nC1","R0\nC2","R0\nC3","R0\nC4",{x:0.5},"R0\nC5","R0\nC6","R0\nC7","R0\nC8",{x:0.5},"R0\nC9","R0\nC10","R0\nC11","R0\nC12",{x:0.25},"R6\nC3","R6\nC4","R6\nC6"],
[{y:0.5},"R1\nC0","R1\nC1","R1\nC2","R1\nC3","R1\nC4","R1\nC5","R1\nC6","R1\nC7","R1\nC8","R1\nC9","R1\nC10","R1\nC11","R1\nC12",{w:2},"R5\nC12",{x:0.25},"R6\nC7","R6\nC8","R6\nC9"],
[{w:1.5},"R2\nC0","R2\nC1","R2\nC2","R2\nC3","R2\nC4","R2\nC5","R2\nC6","R2\nC7","R2\nC8","R2\nC9","R2\nC10","R2\nC11","R2\nC12",{w:1.5},"R3\nC12",{x:0.25},"R6\nC10","R6\nC11","R6\nC12"],
[{w:1.75},"R3\nC0","R3\nC1","R3\nC2","R3\nC3","R3\nC4","R3\nC5","R3\nC6","R3\nC7","R3\nC8","R3\nC9","R3\nC10","R3\nC11",{w:2.25},"R4\nC12"],
[{w:2.25},"R4\nC0","R4\nC1","R4\nC2","R4\nC3","R4\nC4","R4\nC5","R4\nC6","R4\nC7","R4\nC8","R4\nC9","R4\nC10",{w:2.75},"R4\nC11",{x:1.25},"R5\nC11"],
[{w:1.25},"R5\nC0",{w:1.25},"R5\nC1",{w:1.25},"R5\nC2",{w:6.25},"R5\nC3",{w:1.25},"R5\nC4",{w:1.25},"R5\nC5",{w:1.25},"R5\nC6",{w:1.25},"R5\nC7",{x:0.25},"R5\nC8","R5\nC9","R5\nC10"]

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available

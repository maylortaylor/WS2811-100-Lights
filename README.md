# WS2811 100 Lights

Controls a WS2811 based strand of LEDs. Accepts input from a Rotary
Encoder (pattern select) and Potentiometer (brightness). Stores current
pattern in to memory for recall after power loss. Based on Christmas 2016
design and modified for more attention grabbing patterns.

```
Connections:
  VCC = 5v

  WS2811:
    GND -> GND
    VCC -> VCC
    DAT -> Digital 6

  Rotary Encoder:
    D 3 <-   -> D 4
    GND <- O  |
    D 2 <-   -> GND

  Potentiometer:
    /-> GND (alternative A0)
    Q-> A1
    \-> VCC (alternative A1)
```

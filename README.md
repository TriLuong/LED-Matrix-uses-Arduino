# LEd-Matrix-using-Arduino
Using Arduino, Three 74HC595 and One ULN2803 to display LED Matrix and send words to display from RS232. Schematic in File "Schematic" (Using Eagle Software to open it).

Arduino
- Pin 12 connects to DS of 74HC595
- Pin 10 connects to SHCP of 74HC595
- Pin 11 connects to STCP of 74HC595

Three 74HC595
- Q0-Q7 connect to Row of LED Matrix
- Q7S (74HC595[1]) conncets to DS (74HC595[2])
- Q7S (74HC595[2]) conncets to DS (74HC595[3])
- Q7S (74HC595[2]) conncets to DS (74HC595[3])
  
One ULN2803 
- 1B-8B connect to Pin 2-9 of Arduino
- 1C-8C connect to Column of LED Matrix

GND of Aruduino, ULN2803 and 74HC595 connect each other.

if you want to understand how 74HC595 works, you can see it in link below: 
https://www.youtube.com/watch?v=6fVbJbNPrEU

Reference: https://github.com/thaitanloi365/LedMatrix 

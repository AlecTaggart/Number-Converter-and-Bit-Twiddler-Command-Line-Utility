# https://github.com/AlecTaggart/Number-Converter-and-Bit-Twiddler-Command-Line-Utility.git


USAGE:
-The default bit width for nt is 32. You can change this default with the -b option. Support following bit widths: 4, 8, 16, 32

-You can select the range of bits to use for conversion using the -r option:

$ nt -b 4 -r 4,7 0b000010100000
1010 (base 2)
0b1010 (base 2)
0xA (base 16)
10 (base 10 unsigned)
-6 (base 10 signed)

$ nt -b 16 713
0000 0010 1100 1001 (base 2) 
0b0000001011001001 (base 2) 
0x02C9 (base 16)
713 (base 10 unsigned)
713 (based 10 signed)  

$ nt -b 16 -713
1111 1101 0011 0111 (base 2) 
0b111110100110111 (base 2)
0xFD37 (base 16)
64823 (base 10 unsigned)
-713 (base 10 signed)

$ nt -b 8 0xE0
1110 0000 (base 2)
0b11100000 (base 2)
0xE0 (base 16)
224 (base 10 unsigned)
-32 (base 10 signed)

FUNCTION:
Conversion of inputs:
Binary input
Hexadecimal input
Unsigned decimal input
Signed decimal input
Binary output
Hexadecimal output
Unsigned decimal output
Signed decimal output

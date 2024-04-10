#!/bin/bash

Black='\033[0;30m'
Red='\033[0;31m'
Green='\033[0;32m'
Yellow='\033[0;33m'
Blue='\033[0;34m'
Purple='\033[0;35m'
Cyan='\033[0;36m'
White='\033[0;37m'
Color_Off='\033[0m'

make d
echo -e $Blue"\nTesting characters\n"$Color_Off
./scalar \'c\'
./scalar \'" "\'
./scalar \'*\'
./scalar \'$(printf '\017')\'
echo -e $Blue"\nTesting integers\n"$Color_Off
./scalar 48
./scalar -48
./scalar --48
./scalar +48
./scalar ++48
./scalar 0
./scalar 300
./scalar 256
./scalar 2147483647
./scalar 2147483648
./scalar -2147483648
./scalar 123123213213
echo -e $Blue"\nTesting floats\n"$Color_Off
./scalar 48.4f
./scalar -48.4f
./scalar +48.4f
./scalar 0.0f
./scalar 48.0f
./scalar 255.0f
./scalar 256.0f
./scalar 300.0f
./scalar -123.0f
./scalar 255.5f
./scalar --48.4f
./scalar ++48.4f
./scalar 2147483648.0f
./scalar -2147483648.0f
./scalar -2147483648.1f
./scalar 123123213213.0f
./scalar 12321321321321123123213221321321321312321321313.0f
echo -e $Blue"\nTesting doubles\n"$Color_Off
./scalar 48.4
./scalar -48.4
./scalar +48.4
./scalar 48.0
./scalar 255.0
./scalar -123.0
./scalar 255.5
./scalar 0.0
./scalar --48.0
./scalar ++48.0
./scalar 123123213213.0
./scalar 2147483647.0
./scalar 2147483648.0
./scalar -2147483648.0
./scalar -2147483648.1
./scalar 123213213213211231232132132132132131231231232131.0
echo -e $Blue"\nTesting pseudos\n"$Color_Off
./scalar inf
./scalar inff
./scalar -inf
./scalar -inff
./scalar +inf
./scalar +inff
./scalar nan
./scalar nanf
echo -e $Blue"\nTesting bad stuff\n"$Color_Off
./scalar none
./scalar ""
./scalar "-"
./scalar "+"
./scalar "48.4f4"
./scalar "48.f"
./scalar "48."
./scalar "48..2"
./scalar "48..2f"
./scalar "."
./scalar ".1"
./scalar ".12f"
./scalar "48.5.12f"
./scalar "48.5.12"
./scalar "48f"
./scalar "48.2ff"
./scalar "+.123f"
./scalar "-.123f"
./scalar "+.123"
./scalar "-.1233"


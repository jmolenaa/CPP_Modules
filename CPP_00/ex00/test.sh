RED='\033[1;31m'
GREEN='\033[1;32m'
YELLOW='\033[1;33m'
BLUE='\033[1;34m'
MAGENTA='\033[1;35m'
CYAN='\033[1;36m'
END='\033[0m'

#!/bin/bash

make
echo "${MAGENTA}Testing:${END}\n${YELLOW}./megaphone${END}"
./megaphone
echo "${MAGENTA}Testing:${END}\n${YELLOW}./megaphone "shhhhh... I think the students are asleep..."${END}"
./megaphone "shhhhh... I think the students are asleep..."
echo "${MAGENTA}Testing:${END}\n${YELLOW}./megaphone Damnit " ! " "Sorry students, I thought this thing was off."${END}"
./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
echo "${MAGENTA}Testing:${END}\n${YELLOW}./megaphone '""'${END}"
./megaphone ""
echo "${MAGENTA}Testing:${END}\n${YELLOW}./megaphone '" "'${END}"
./megaphone " "

#~/bin/bash

make fclean d
echo ---------------------------------------------------------------------------------------------
./PmergeMe 1 1 12
echo ---------------------------------------------------------------------------------------------
./PmergeMe 12312313123132 1 2
echo ---------------------------------------------------------------------------------------------
./PmergeMe 1
echo ---------------------------------------------------------------------------------------------
./PmergeMe 2 1
echo ---------------------------------------------------------------------------------------------
./PmergeMe -1 1 10 9
echo ---------------------------------------------------------------------------------------------
./PmergeMe asd 1 2
echo ---------------------------------------------------------------------------------------------
./PmergeMe "" 1 2
echo ---------------------------------------------------------------------------------------------
./PmergeMe 3 5 9 7 4
echo ---------------------------------------------------------------------------------------------
echo ---------------------------------------------------------------------------------------------
./PmergeMe 5 2 3 1 4 7 10 40 0 9 12 32 333 43 6666 8 6 1999 999
echo ---------------------------------------------------------------------------------------------
echo ---------------------------------------------------------------------------------------------
./PmergeMe 5 2 3 1 4 7 10 40
echo ---------------------------------------------------------------------------------------------


./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`

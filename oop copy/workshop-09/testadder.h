echo Test 01: 3 + 5 = 8
./adder < input01.txt | diff - output01.txt
echo Test 02: 3 + 7 = 10
./adder < input02.txt | diff - output02.txt
echo Test 03: 0 + 0 = 0
./adder < input03.txt | diff - output03.txt
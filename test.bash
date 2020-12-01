#!/usr/bin/env bash
make all
./main.o<inputs/in1.txt>results1.txt
./main.o<inputs/in2.txt>results2.txt
printf 'O\nD\n)\n400\nO\n300\nI\nP\n30\nE' | ./main.o > results3.txt
printf 'O\n-9O\nb\nO\n100\nB\n902\nB\nB\n901\nD\n902\nD\n-901\nD\nD\n901\n-10\nD\n901\nD\n951\nD\n901\n150\nW\n902\nW\nW\n901\n-10\nC\n902\nC\nC\n901\nD\n901\nI\n-10\nI\nI\n10\nP\nO\n500\nP\nE' | ./main.o > result.txt
#./main.o<inputs/input.txt>result.txt
printf '\n'
echo ================================================================================================
echo ---------------------------------Tests Summary--------------------------------------------------
echo ================================================================================================
printf '\n'
diff -q -s results1.txt outputs/out1.txt
diff -q -s results2.txt outputs/out2.txt
diff -q -s results3.txt outputs/out3.txt
diff -q -s result.txt outputs/output.txt
printf '\n'
echo ================================================================================================
echo ---------------------------------File Comparison------------------------------------------------
echo ================================================================================================
printf '\n'
echo =============================================First==============================================
diff -y --suppress-common-lines -W 150 results1.txt outputs/out1.txt
echo =============================================Second=============================================
diff -y --suppress-common-lines -W 150 results2.txt outputs/out2.txt
echo =============================================Third==============================================
diff -y --suppress-common-lines -W 150 results3.txt outputs/out3.txt
echo =============================================Last!==============================================
diff -y --suppress-common-lines -W 150 result.txt outputs/output.txt
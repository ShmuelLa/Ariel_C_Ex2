#!/usr/bin/env bash
make all
printf 'O\n456\nO\n345\nB\n903\nB\n902\nI\n5\nP\nE' | ./main.o > results1.txt
printf 'O\n456\nO\n345\nW\n902\n50\nP\nW\n901\n1000\nE' | ./main.o > results2.txt
printf 'O\nD\n)\n400\nO\n300\nI\nP\n30\nE' | ./main.o > results3.txt
printf '\n'
echo ================================================================================================
echo ---------------------------------Tests Summary--------------------------------------------------
echo ================================================================================================
printf '\n'
diff -q results1.txt outputs/out1.txt
diff -q results2.txt outputs/out2.txt
diff -q results3.txt outputs/out3.txt
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

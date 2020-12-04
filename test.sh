#!/usr/bin/env bash
make all
./main.o<inputs/in1.txt>results1.txt
./main.o<inputs/in2.txt>results2.txt
./main.o<inputs/in3.txt>results3.txt
./main.o<inputs/input.txt>result.txt
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
echo ================================================================================================
echo ---------------------------------Tests Summary--------------------------------------------------
echo ================================================================================================
#diff -y --suppress-common-lines -W 150 result.txt outputs/out4.txt | cat -t
printf '\n'
diff -q -s results1.txt outputs/out1.txt
diff -q -s results2.txt outputs/out2.txt
diff -q -s results3.txt outputs/out3.txt
diff -q -s result.txt outputs/output.txt
printf '\n'

#!/usr/bin/env bash
make all
./main.o<inputs/in1.txt>testresults/results1.txt
./main.o<inputs/in2.txt>testresults/results2.txt
./main.o<inputs/in3.txt>testresults/results3.txt
./main.o<inputs/input.txt>testresults/result.txt
printf '\n'
echo ================================================================================================
echo ---------------------------------File Comparison------------------------------------------------
echo ================================================================================================
printf '\n'
echo =============================================First==============================================
diff -y --suppress-common-lines -W 150 testresults/results1.txt outputs/out1.txt
echo =============================================Second=============================================
diff -y --suppress-common-lines -W 150 testresults/results2.txt outputs/out2.txt
echo =============================================Third==============================================
diff -y --suppress-common-lines -W 150 testresults/results3.txt outputs/out3.txt
echo =============================================Last!==============================================
diff -y --suppress-common-lines -W 150 testresults/result.txt outputs/output.txt
echo ================================================================================================
echo ---------------------------------Tests Summary--------------------------------------------------
echo ================================================================================================
printf '\n'
diff -q -s testresults/results1.txt outputs/out1.txt
diff -q -s testresults/results2.txt outputs/out2.txt
diff -q -s testresults/results3.txt outputs/out3.txt
diff -q -s testresults/result.txt outputs/output.txt
printf '\n'

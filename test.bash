#!/usr/bin/env bash
printf 'O\n456\nO\n345\nB\n903\nB\n902\nI\n5\nP\nE' | ./main.o > results1.txt
diff -q results1.txt outputs/out1.txt
diff -y -W 150 results1.txt outputs/out1.txt

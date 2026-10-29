#!/bin/bash
# Script: for_loop_demo.sh
# Purpose: Demonstrate the use of for loops in shell scripting

# Example 1: Print numbers from 1 to 5
echo "For Loop Example 1: Numbers from 1 to 5"
for i in {1..5}; do
    echo "Number: $i"
done

# Example 2: Iterate over a list of items
echo "For Loop Example 2: Days of the Week"
for day in Monday Tuesday Wednesday Thursday Friday; do
    echo "Day: $day"
done

# Example 3: Iterate through files in the current directory
echo "For Loop Example 3: Files in the Current Directory"
for file in *; do
    echo "File: $file"
done

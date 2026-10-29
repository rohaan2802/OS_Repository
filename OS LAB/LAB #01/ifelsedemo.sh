#!/bin/bash
# Script: if_else_demo.sh
# Purpose: Demonstrate if-else conditions in shell scripting

# Prompt the user for a number
echo "Enter a number:"
read number

# Check if the number is positive, negative, or zero
if [ $number -gt 0 ]; then
    echo "The number $number is positive."
else
    echo "The number is zero."
fi


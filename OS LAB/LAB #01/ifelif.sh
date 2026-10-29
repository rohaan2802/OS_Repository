#!/bin/bash
# Script: if_elif_demo.sh
# Purpose: Demonstrate if-elif-else ladder in shell scripting

# Prompt for the user's favorite day
echo "What is your favorite day of the week?"
read day

# Check the input and respond
if [ "$day" = "Monday" ]; then
    echo "Start of the work week! Stay motivated!"
    
elif [ "$day" = "Friday" ]; then
    echo "It's almost the weekend! Hang in there!"
elif [ "$day" = "Sunday" ]; then
    echo "Time to relax before the new week!"
else
    echo "Every day is great if you make it so!"
fi


#!/bin/bash
# Script: while_loop_demo.sh
# Purpose: Demonstrate the use of while loops in shell scripting

# Example 1: Countdown from 5 to 1
echo "While Loop Example 1: Countdown from 5 to 1"
count=5
while [ $count -gt 0 ]; do
    echo "Count: $count"
    count=$((count - 1)) # Decrement the count
done

# 


#!/bin/bash
# Script: variables_demo.sh
# Purpose: Demonstrate different types of variables in shell scripting

# User-defined (Shell) Variable
# A variable that we define for our own use
greeting="Hello, Students!"
echo "User-defined Variable: $greeting"

# Modify the value of the variable
greeting="Welcome to Shell Scripting!"
echo "Modified Variable: $greeting"

# System (Environment) Variable
# Example: $HOME holds the user's home directory
echo "System Variable: Your home directory is $HOME"

# Arithmetic in Variables
# Storing a mathematical expression
num1=10
num2=20
sum=$((num1 + num2))
echo "Arithmetic Example: The sum of $num1 and $num2 is $sum"

# Null Variable
# A variable with no value assigned
null_var=""
echo "Null Variable: '$null_var' (Nothing is stored here!)"

# Demonstrating Case Sensitivity
# Variable names are case-sensitive
VAR1="Uppercase Variable"
var1="Lowercase Variable"
echo "Case Sensitivity: VAR1 is '$VAR1', var1 is '$var1'"


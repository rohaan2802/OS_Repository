#!/bin/bash
# Script: input_demo.sh
# Purpose: Show how to handle user input in shell scripting

# Prompt for the user's name
echo "Enter your name:"
read name
echo "Hello, $name! Welcome to the Linux Lab."

# Prompt for the user's favorite programming language
echo "What is your favorite programming language?"
read language
echo "Wow! You love $language!"

# Prompt for multiple inputs
echo "Enter your first name, last name, and age (space-separated):"
read first_name last_name age
echo "Your full name is $first_name $last_name, and you are $age years old."


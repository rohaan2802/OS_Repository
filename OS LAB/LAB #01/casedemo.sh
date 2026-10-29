#!/bin/bash
# Script: case_demo.sh
# Purpose: Demonstrate case statements in shell scripting

# Prompt for the user's favorite programming language
echo "Enter your favorite programming language (Python, Java, C++):"
read language

# Respond using a case statement
case $language in
    Python)
        echo "Python is great for AI and machine learning!"
        ;;
    Java)
        echo "Java is amazing for enterprise applications!"
        ;;
    C++)
        echo "C++ is excellent for performance-critical software!"
        ;;
    *)
        echo "That's an interesting choice! Keep learning $language!"
        ;;
esac


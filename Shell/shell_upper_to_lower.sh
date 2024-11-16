#!/bin/sh

# Prompt the user for input
echo "Enter the text you want to convert to lowercase:"
read user_input

# Convert the input to lowercase using `tr`
converted_text=$(echo "$user_input" | tr '[:upper:]' '[:lower:]')

# Display the result
echo "Converted text: $converted_text"


# Prompt the user for input
echo "Enter the text you want to convert to uppercase:"
read user_input

# Convert the input to uppercase using `tr`
converted_text=$(echo "$user_input" | tr '[:lower:]' '[:upper:]')

# Display the result
echo "Converted text: $converted_text"

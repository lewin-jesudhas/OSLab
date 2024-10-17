# Step 1: Reading a string via user input
echo "Enter the string:"
read string

# Step 2: Read the character to be replaced
echo "Enter the character to be replaced:"
read old_char

# Step 3: Read the new replacement character
echo "Enter the new character:"
read new_char

# Step 4: Initialize an empty result string
result=""

# Step 5: Loop through each character of the string
i=0
len=${#string}
while [ $i -lt $len ]; do
    # Extract the current character
    current_char=$(echo "$string" | cut -c $((i+1)))

    # Check if current character is the one to be replaced
    if [ "$current_char" = "$old_char" ]; then
        result="$result$new_char"  # Replace with new character
    else
        result="$result$current_char"  # Append original character
    fi

    i=$((i + 1))  # Increment index
done

# Step 6: Print the modified string
echo "Modified string: $result"

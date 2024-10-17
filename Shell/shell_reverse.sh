# Reading a string via user input
echo "Enter string:"
read string

# Getting the length of the given string using a different method
len=0
temp_string="$string"

# Calculate string length
while [ -n "$temp_string" ]; do
    temp_string=${temp_string%?}  # Remove last character from the string
    len=$((len + 1))
done

# Looping for reversing the string
# Initialize i=len-1 for reversing the string and run till i=0
reverse=""
i=$((len - 1))

while [ $i -ge 0 ]; do
    # Extract single character from string using awk
    char=$(echo "$string" | awk -v i="$((i + 1))" '{print substr($0, i, 1)}')
    reverse="$reverse$char"
    i=$((i - 1))
done

# Display the reversed string
echo "Reversed string: $reverse"

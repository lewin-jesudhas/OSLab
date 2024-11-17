echo "Enter string:"
read string

reverse=$(echo "$string" | rev) # Using the 'rev' command
echo "Reversed: $reverse"

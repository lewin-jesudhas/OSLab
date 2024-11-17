echo "Enter string:"
read string

len=${#string}
reverse=""
i=$((len - 1))

while [ $i -ge 0 ]; do
	char=$(echo "$string" | awk -v i="$((i + 1))" '{print substr($0, i ,1)}')
	reverse="$reverse$char"
	i=$((i - 1))
done

echo "Reversed: $reverse"

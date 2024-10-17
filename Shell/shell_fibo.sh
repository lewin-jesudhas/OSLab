echo "Enter the number of terms:"
read n

a=0
b=1
i=0

echo "Fibonacci Series:"
while [ $i -lt $n ]
do
    echo -n "$a "
    next=$((a + b))
    a=$b
    b=$next
    i=$((i + 1))
done
echo

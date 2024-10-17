echo "Enter a number"
read num
fact=1

while [ $num -gt 1 ]
do
    fact=$(expr $fact \* $num)  # fact = fact * num using expr
    num=$(expr $num - 1)        # num = num - 1 using expr
done

echo "The factorial is: $fact"

echo "Enter num1:"
read num1
echo "Enter num2:"
read num2
echo "Enter num3:"
read num3
echo "Num1 = $num1, Num2 = $num2, Num3 = $num3"

if [ $num1 -gt $num2 ] && [ $num1 -gt $num3 ]; then 
    greatest=$num1
elif [ $num2 -gt $num1 ] && [ $num2 -gt $num3 ]; then
    greatest=$num2
else
    greatest=$num3
fi

echo "The greatest number is: $greatest"

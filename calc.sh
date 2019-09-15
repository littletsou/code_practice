#!/bin/bash

#Calculate add, sub, mul, dev and factorial
#Example: ./calc.sh factorial 3

#a=123
#a=456
#a=789
#if [ "$a" = "123" ]; then
#    echo "var is 123"
#elif [ "$a" = "456" ]; then
#    echo "var is 456"
#else
#    echo "var is 789"
#fi
#echo "$2"

add() {
result=$(expr $1 + $2)
echo "$1 + $2 = $result"
}

sub() {
result=$(expr $1 - $2)
echo "$1 - $2 = $result"
}

function mul() {
result=$(expr $1 \* $2)
echo "$1 * $2 = $result"
}
function dev() {
result=$(expr $1 / $2)
echo "$1 / $2 = $result"
}

function factorial() {
result=1
for ((i=1; i<=$1; i++))
do
	result=$(expr $result \* $i)
	#result=$($result \* $i) -> wrong
	#result=$result \* $i -> wrong
	#result=$((result * i)) -> correct
done
echo "$1! = $result"
}

main() {
#echo "1: $1"
#echo "2: $2"
#echo "3: $3"
functionCase=$1
num1=$2
num2=$3
if [ $functionCase = 'add' ]; then
    add $num1 $num2
elif [ $functionCase = 'sub' ]; then
    sub $num1 $num2
elif [ $functionCase = 'mul' ]; then
    mul $num1 $num2
elif [ $functionCase = 'dev' ]; then
    dev $num1 $num2
elif [ $functionCase = 'factorial' ]; then
    factorial $num1
else 
    echo "Error command."
fi
}

main $1 $2 $3
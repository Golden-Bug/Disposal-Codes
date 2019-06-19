function line()
{
	echo "************"
}
	
echo "Your username :$(echo $USER)"
line
echo "Current date and time :$(date)"
line
echo "Currently logged in:"
who
line

read -p 'Enter a: ' a
read -p 'Enter b: ' b
add=$((a+b))
echo "addition of a & b is $add"
read -p 'Enter x: ' x
read -p 'Enter y: ' y
sub=$((x-y))
echo "Subtraction a & b is $sub"
mod=$((a%b))
echo "Modulation of a & b is $mod"
if (($a==$b))
then
	echo "a is equal to b"
else
	echo "Not equal"
fi
AND=$((a&b))
echo "Bitwise a&b is $AND"
POW=$((a^b))
echo "Power is $POW"
rightshift=$((b>>1))
echo "shift $rightshift"
read -p 'Enter file name: ' FileName
if [-e $FileName]
then 
	echo "File exist"
else 
	echo "File don't exist"
fi

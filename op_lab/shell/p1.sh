#!/bin/bash
# sh p1.sh
echo $PATH
echo $PATH | tr ":" "\n" | nl

# Question 1
echo "\n"
echo "Question  1 Ans"
#count number of : in PATH variable
var=`echo $PATH | grep -o ":" | wc -l`
n=`expr $var + 1`

#for number of directory in PATH variable, iterate and fetch one directory at a time





#Others useful commands
# Question 2
echo "\n"
echo "Question  2"
sudo fdisk -l /dev/sda




#Question 3
echo "\n"
echo "Question  3 Ans"
ls -l -h





#select the first line that contains the string "vendor_id" in file /proc/cpuinfo



# Question  4
echo "\n"
echo "Question  4 Ans"
grep -R "vendor_id" "/proc/cpuinfo"| sed -n 1p
grep -R "model name" "/proc/cpuinfo"| sed -n 1p
grep -R "cpu MHz" "/proc/cpuinfo"| sed -n 1p
grep -R "cache size" "/proc/cpuinfo"| sed -n 1p





# Question 5
echo "\n"
echo "Question  5 Ans"
grep -R "NAME" "/etc/os-release"| sed -n 1p
grep -R "VERSION" "/etc/os-release"| sed -n 1p
echo  "Kernel Release =\"$(uname -r)\""
echo  "Release Number =\"$(uname -v)\""


# Question 6
echo "\n"
echo "Question  6 Ans"

du -h -d 2 ./



#remove white spaces from front and end of a string
sample="   Yay Completed Ass !     "
echo "${sample}" | sed -e 's/^[ \t]*//'




















#To see currently running process 
ps

#To stop any process by PID i.e. to kill process
kill  {PID}

#To stop processes by name i.e. to kill process
kill {name}

#To get information about all running process
ps -ag

#To stop all process except your shell
kill 0

#For background processing (With &, use to put particular command and program in background)
ls / -R | wc -l &

#To display the owner of the processes along with the processes  
ps aux

#To see if a particular process is running or not. For this purpose you have to use ps command in combination with the #grep command
#For e.g. you want to see whether Apache web server process is running or not then give command 
ps ax | grep {name}

#To see currently running processes and other information like memory and CPU usage with real time updates.
top

#To display a tree of processes
 pstree

  #Following tables most commonly used command(s) with process:

TOP
 HTOP
 PS
 PSTREE
 PGREP
 NICE
 RENICE
 KILL

 # To compile pthread 
 gcc -Wall pthread.c -lpthread
 ./a.out
 

 # To compile the g++ program and run it
 g++ -o output next_fit.cpp
 ./output

 # Write shell script to delete the word <Dd> coming b/w 5th n 7th position
#!/bin/bash
echo "$( cat $1 | sed '/....dd/d' | sed '/......dd/' )"

Then you can run it as
./delete.sh input.txt

## Shell script to reverse a string
if [ -z "$1" ]
	then 
	echo "Error. No arguments detected."
else
	n=0
	n=$1
	sd=0
	rev=0

	while [ $n -gt 0 ]
	do
		sd=$(( $n % 10 ))
		rev=`expr $rev \* 10 + $sd` 
		n=$(( $n / 10 ))
	done

	echo "Reverse number of entered digit is $rev"

fi
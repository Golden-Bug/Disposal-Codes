arr=(Ratul Harsha Ankit)
echo ${arr[0]} #element finding
echo ${arr[@]} #full array
echo ${arr[@]:1:2} #1 to 2 element print
echo ${arr[0]:1:3} #1st element 1 to 3
echo ${#arr[@]} # full length
echo ${#arr[0]} #element length
echo ${arr[@]/*[aB]*/} #search element
echo ${arr[@]/*[bA]*/} #search element
echo ${arr[@]//a/A}


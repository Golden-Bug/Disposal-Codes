read -p 'Enter file name : ' FileName 
  
if [ -e $FileName ] 
then 
    echo File Exist 
else
    echo File doesnot exist 
fi 
if [ -s $FileName ]
then 	
	echo The given File is not empty
else
	echo File is empty
fi


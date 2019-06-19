.data
message1:    .asciiz"Enter No. of inputs:\n"
message2:   .asciiz"\nEnter Input(s)\n"
message3:   .asciiz"\nResult:\n"
message4:   .asciiz"  "
message5:   .asciiz"\nPivot:\n"	


.text
 .globl main
main:
 	#for printing 'message1'
		li $v0, 4
		la $a0, message1
		syscall
	#for taking value of "n"
		li  $v0,  5
		syscall
	#shifting value from v0->s0
		add $s0, $v0, 0
	#Memory allocation
		mul $t0, $s0, 4
		addi $a0, $t0, 0
		li $v0, 9  
		syscall
	#memory address storing in 's1'
		addi $s1, $v0, 0
	#for printing 'message2'
		li $v0, 4
		la $a0, message2
		syscall
	#initializing parameters
		li $s2, 0
		li $s3, 0
INPUT:
	#read input from
		li $v0, 5
		syscall
		add $s4, $s2, $s1
		sw $v0, 0($s4)
		addi $s2, $s2, 4	#address
		addi $s3, $s3, 1      #counter
		bne $s3, $s0, INPUT      #goto input till s3!=s0
		
		li $t7, 1

	#for checking base case(if only element is there then print the element)
		
		beq $s0, $t7, RESULT
		li $s2 , 0
		addi $s3, $s0, -1
		addi $s4 , $s2, -1	#$s4('i')=left-1
		addi $s5, $s3, 1		#$s5('j')=right+1
		jal QUICKSORT_I
		j RESULT
QUICKSORT_I:
		addi $sp, $sp, -20  #decresing stack pointer by 20
   		  sw    $s2, 0($sp)    
     		  sw    $s3, 4($sp)      
    		  sw    $s4, 8($sp)      
    		  sw    $s5, 12($sp)     
     		  sw    $ra, 16($sp)
	   # calculation of the pivot
       		add   $t0, $s2, $s3    
       		div   $t0, $t0, 2      
      		mul   $t0, $t0, 4      
      		add   $t0, $t0, $s1    
       		lw    $t0, 0($t0) 

		# pivot printing
		# Print 'message5'
		  li $v0,4
		  la $a0,message5
		  syscall
		
	       li $v0,1
	       add $a0,$t0,$zero
     	       syscall

            li    $v0, 4
            la    $a0, message4
            syscall
     
    		bge   $s4, $s5, rec_1  # if s4('i') >= s5('j'), recursive_1
		j     loop_i
QUICKSORT_R:

      		 addi  $sp, $sp, -28    # decrement $sp(stack pointer) by 28
     		 sw    $s2, 0($sp)      # store $s2 left
      	 sw    $s3, 4($sp)      # store $s3 right
       	 sw    $s4, 8($sp)      # store $s4 i
      	 sw    $s5, 12($sp)     # store $s5 j
     		 sw    $ra, 16($sp)     # store $ra return address
    		 sw    $a2, 20($sp)     # store $a2, previous left
   		 sw    $a3, 24($sp)     # store $a3, previous right

     		 bge   $s2, $s3, return # if $s2(left index) >= $s5(right index), go to return stage

   	     # calculation of the pivot
      	  add   $t0, $s2, $s3    
      	  div   $t0, $t0, 2      
     		  mul   $t0, $t0, 4      
     		  add   $t0, $t0, $s1    
     		  lw    $t0, 0($t0)      # $t0 : pivot

		# pivot printing
		# Print 'message5'
		  li $v0,4
		  la $a0,message5
		  syscall
		
	       li $v0,1
	       add $a0,$t0,$zero
     	       syscall

            li    $v0, 4
            la    $a0, message4
            syscall

	       
      		 addi  $s4, $s2, -1     # i = left - 1
      		 addi  $s5, $s3, 1      # j = right + 1
       
     		 bge   $s4, $s5, rec_1  # if $s4("i") > $s5("j"), recursive_1

	loop_i:
       		addi  $s4, $s4, 1      # i += 1
       		mul   $t1, $s4, 4      
       		add   $t1, $t1, $s1    # $t1(a[i]) address
       		lw    $t2, 0($t1)      # $t2(a[i]) data
       		blt   $t2, $t0, loop_i # if $t2(a[i]) < $t0(pivot), go to loop_i
       
	loop_j:
      		 addi  $s5, $s5, -1     # j -= 1
       		mul   $t3, $s5, 4      
       		add   $t3, $t3, $s1    # $t3(a[j]) address
       		lw    $t4, 0($t3)      # $t4(a[j]) data
       		bgt   $t4, $t0, loop_j # if $t4(a[j]) > $t0(pivot), go to loop_j
       		blt   $s4, $s5, swap   # if $s4("i") < $s5("j"), go to swap       

	rec_1:
       		move  $a3, $s3         # copy right for later use
       		addi  $s3, $s4, -1      # right = i - 1
       		move  $a2, $s2         # copy left for later use
       		jal   QUICKSORT_R    # quicksort(a, left, i-1), recursive call

	rec_2:
      		addi  $s2, $s5, 1       # right = j + 1
      		move  $s3, $a3         # move previous right to $s3
      		 jal   QUICKSORT_R   # quicksort(a, j+1, right), recursive call
     		 j     return                 # jump to result stage

	swap:
       		sw    $t4, 0($t1)
      		sw    $t2, 0($t3)
       		j     loop_i           # jump back to loop_i 

	return:
      		lw    $s2, 0($sp)      # load left
      		lw    $s3, 4($sp)      # load right
      		lw    $s4, 8($sp)      # load i
      		lw    $s5, 12($sp)     # load j
      		lw    $ra, 16($sp)     # load return address
      		lw    $a2, 20($sp)     # load previous left
      		lw    $a3, 24($sp)     # load previous right
      		addi  $sp, $sp, 28     # increment $sp(stack pointer) by 28
     		jr    $ra              # return to the address stored in $ra

	RESULT:
     		# print results
      		li    $v0, 4
      		la    $a0, message3
       		syscall

       		li    $s2, 0    # set $s2(offset index) to 0
      		li    $s3, 0    # set $s3(counting index) to 0

	output:
     		# print the output
     		li    $v0, 1        # print_int syscall code = 1
     		add   $s4, $s2, $s1 #$s4=$s2(offset)+$s1(base address)
      	lw    $a0, 0($s4)   # load word from 0($s4) to $a0
     		syscall                # print_int inside $a0

     		# print space 
      		li    $v0, 4
      		la    $a0, message4
      		syscall

      		addi $s2, $s2,4 #increment $s2(offset index)by 4
      		addi $s3, $s3,1 #increment$s3(counting index)by 1

       		bne  $s3, $s0,output #if $s3(counting index)!=$s0(number of inputs), print 			integer  

      		li    $v0, 10          # termination   
       		syscall





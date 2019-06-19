.text
main:
	#get the user to input stuff
	la $a0, prompt_input
	li $v0, 4
	syscall
	
	li $v0, 5
	#store the values
	addi $t0, $v0, 0

	li $t1, 1
loop:
	blt $t0, 1, done
	mul $t1, $t1, $t0
	addi $t0, $t0, -1
	j loop

done:
	la $a0, ans
	li $v0, 4
	syscall

	addi $a0, $t1, 0
	li $v0, 1
	syscall

	li $v0, 10
	syscall

.data
ans:	 .asciiz "The result of N! is: "
prompt_input:	 .asciiz "Please enter a value that is greater than 0 and less than 12: "
	

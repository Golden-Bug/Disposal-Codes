.data
factorial_param: .word 3

.text
.globl main

main:
	lw $a0, factorial_param
	jal factorial
	
	add $a0, $zero, $v0
	li $v0, 1
	syscall
	
	li $v0, 10
	syscall
	
factorial:
	# Push registers
	addi $sp, $sp, -8
	sw $ra, 0($sp)
	sw $a0, 4($sp)
	
	# Base Case
	blt $a0, 2, return1
	
	# Recursion Step
	addi $a0, $a0, -1
	jal factorial
	addi $a0, $a0, 1
	
	# Multiply n * (n - 1) * (n - 2) * ...
	multu $a0, $v0
	mflo $v0
	
exit_factorial:
	# Pop registers
	lw $ra, 0($sp)
	lw $a0, 4($sp)
	addi $sp, $sp, 8
	
	# Go back.
	jr $ra
	
# Return 1.
return1:
	li $v0, 1
	j exit_factorial 
	

	.file	"structs.c"
	.text
	.section	.rodata
	.align 8
.LC0:
	.string	"size of color: %d, val: %d, var: %d\n"
	.align 8
.LC1:
	.string	"size of vector: %d, val: %d, var: %d\n"
.LC2:
	.string	"size of sample: %d, var: %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movl	$115, -32(%rbp)
	movl	$110, -28(%rbp)
	movl	$112, -24(%rbp)
	movl	$167, -20(%rbp)
	movl	$88, -16(%rbp)
	movq	$2, -48(%rbp)
	movq	$4, -40(%rbp)
	movb	$97, -54(%rbp)
	movb	$98, -53(%rbp)
	movb	$99, -52(%rbp)
	movw	$145, -50(%rbp)
	movl	$20, %ecx
	movl	$4, %edx
	movl	$20, %esi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$16, %ecx
	movl	$8, %edx
	movl	$16, %esi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$6, %edx
	movl	$6, %esi
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Debian 12.2.0-10) 12.2.0"
	.section	.note.GNU-stack,"",@progbits

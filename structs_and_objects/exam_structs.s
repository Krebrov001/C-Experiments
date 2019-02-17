	.file	"exam_structs.c"
	.text
	.globl	bar
	.type	bar, @function
bar:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movzbl	32(%rax), %eax
	movl	%eax, %edx
	movq	-8(%rbp), %rax
	addq	$40, %rax
	movzbl	8(%rax), %eax
	addl	%edx, %eax
	movl	%eax, %edx
	movq	-8(%rbp), %rax
	movb	%dl, 8(%rax)
	movq	-8(%rbp), %rax
	movl	8(%rax), %edx
	movq	-8(%rbp), %rax
	movl	%edx, 24(%rax)
	movq	-8(%rbp), %rax
	addq	$40, %rax
	movzbl	8(%rax), %eax
	movsbw	%al, %dx
	movq	-8(%rbp), %rax
	movw	%dx, 10(%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	bar, .-bar
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.9) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits

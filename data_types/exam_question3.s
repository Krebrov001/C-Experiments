	.file	"exam_question3.c"
	.text
	.globl	quiz1
	.type	quiz1, @function
quiz1:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movl	%edi, %edx
	movl	%esi, %eax
	movb	%dl, -52(%rbp)
	movb	%al, -56(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movw	$43, -34(%rbp)
	movb	$0, -35(%rbp)
.L2:
	movzwl	-34(%rbp), %edx
	movsbl	-35(%rbp), %eax
	cltq
	movl	-32(%rbp,%rax,4), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movw	%ax, -34(%rbp)
	movsbl	-35(%rbp), %eax
	movsbl	-52(%rbp), %ecx
	movsbl	-35(%rbp), %edx
	addl	%ecx, %edx
	cltq
	movl	%edx, -32(%rbp,%rax,4)
	movzbl	-35(%rbp), %eax
	addl	$1, %eax
	movb	%al, -35(%rbp)
	movzbl	-35(%rbp), %eax
	cmpb	-56(%rbp), %al
	jl	.L2
	movsbl	-52(%rbp), %edx
	movswl	-34(%rbp), %eax
	addl	%edx, %eax
	movq	-8(%rbp), %rsi
	xorq	%fs:40, %rsi
	je	.L4
	call	__stack_chk_fail
.L4:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	quiz1, .-quiz1
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.9) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits

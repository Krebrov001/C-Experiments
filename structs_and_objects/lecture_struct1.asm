
a.out:     file format elf64-x86-64


Disassembly of section .init:

00000000004003f0 <_init>:
  4003f0:	48 83 ec 08          	sub    $0x8,%rsp
  4003f4:	48 8b 05 fd 0b 20 00 	mov    0x200bfd(%rip),%rax        # 600ff8 <_DYNAMIC+0x1d0>
  4003fb:	48 85 c0             	test   %rax,%rax
  4003fe:	74 05                	je     400405 <_init+0x15>
  400400:	e8 3b 00 00 00       	callq  400440 <__libc_start_main@plt+0x10>
  400405:	48 83 c4 08          	add    $0x8,%rsp
  400409:	c3                   	retq   

Disassembly of section .plt:

0000000000400410 <__stack_chk_fail@plt-0x10>:
  400410:	ff 35 f2 0b 20 00    	pushq  0x200bf2(%rip)        # 601008 <_GLOBAL_OFFSET_TABLE_+0x8>
  400416:	ff 25 f4 0b 20 00    	jmpq   *0x200bf4(%rip)        # 601010 <_GLOBAL_OFFSET_TABLE_+0x10>
  40041c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400420 <__stack_chk_fail@plt>:
  400420:	ff 25 f2 0b 20 00    	jmpq   *0x200bf2(%rip)        # 601018 <_GLOBAL_OFFSET_TABLE_+0x18>
  400426:	68 00 00 00 00       	pushq  $0x0
  40042b:	e9 e0 ff ff ff       	jmpq   400410 <_init+0x20>

0000000000400430 <__libc_start_main@plt>:
  400430:	ff 25 ea 0b 20 00    	jmpq   *0x200bea(%rip)        # 601020 <_GLOBAL_OFFSET_TABLE_+0x20>
  400436:	68 01 00 00 00       	pushq  $0x1
  40043b:	e9 d0 ff ff ff       	jmpq   400410 <_init+0x20>

Disassembly of section .plt.got:

0000000000400440 <.plt.got>:
  400440:	ff 25 b2 0b 20 00    	jmpq   *0x200bb2(%rip)        # 600ff8 <_DYNAMIC+0x1d0>
  400446:	66 90                	xchg   %ax,%ax

Disassembly of section .text:

0000000000400450 <_start>:
  400450:	31 ed                	xor    %ebp,%ebp
  400452:	49 89 d1             	mov    %rdx,%r9
  400455:	5e                   	pop    %rsi
  400456:	48 89 e2             	mov    %rsp,%rdx
  400459:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
  40045d:	50                   	push   %rax
  40045e:	54                   	push   %rsp
  40045f:	49 c7 c0 10 06 40 00 	mov    $0x400610,%r8
  400466:	48 c7 c1 a0 05 40 00 	mov    $0x4005a0,%rcx
  40046d:	48 c7 c7 46 05 40 00 	mov    $0x400546,%rdi
  400474:	e8 b7 ff ff ff       	callq  400430 <__libc_start_main@plt>
  400479:	f4                   	hlt    
  40047a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000400480 <deregister_tm_clones>:
  400480:	b8 3f 10 60 00       	mov    $0x60103f,%eax
  400485:	55                   	push   %rbp
  400486:	48 2d 38 10 60 00    	sub    $0x601038,%rax
  40048c:	48 83 f8 0e          	cmp    $0xe,%rax
  400490:	48 89 e5             	mov    %rsp,%rbp
  400493:	76 1b                	jbe    4004b0 <deregister_tm_clones+0x30>
  400495:	b8 00 00 00 00       	mov    $0x0,%eax
  40049a:	48 85 c0             	test   %rax,%rax
  40049d:	74 11                	je     4004b0 <deregister_tm_clones+0x30>
  40049f:	5d                   	pop    %rbp
  4004a0:	bf 38 10 60 00       	mov    $0x601038,%edi
  4004a5:	ff e0                	jmpq   *%rax
  4004a7:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  4004ae:	00 00 
  4004b0:	5d                   	pop    %rbp
  4004b1:	c3                   	retq   
  4004b2:	0f 1f 40 00          	nopl   0x0(%rax)
  4004b6:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  4004bd:	00 00 00 

00000000004004c0 <register_tm_clones>:
  4004c0:	be 38 10 60 00       	mov    $0x601038,%esi
  4004c5:	55                   	push   %rbp
  4004c6:	48 81 ee 38 10 60 00 	sub    $0x601038,%rsi
  4004cd:	48 c1 fe 03          	sar    $0x3,%rsi
  4004d1:	48 89 e5             	mov    %rsp,%rbp
  4004d4:	48 89 f0             	mov    %rsi,%rax
  4004d7:	48 c1 e8 3f          	shr    $0x3f,%rax
  4004db:	48 01 c6             	add    %rax,%rsi
  4004de:	48 d1 fe             	sar    %rsi
  4004e1:	74 15                	je     4004f8 <register_tm_clones+0x38>
  4004e3:	b8 00 00 00 00       	mov    $0x0,%eax
  4004e8:	48 85 c0             	test   %rax,%rax
  4004eb:	74 0b                	je     4004f8 <register_tm_clones+0x38>
  4004ed:	5d                   	pop    %rbp
  4004ee:	bf 38 10 60 00       	mov    $0x601038,%edi
  4004f3:	ff e0                	jmpq   *%rax
  4004f5:	0f 1f 00             	nopl   (%rax)
  4004f8:	5d                   	pop    %rbp
  4004f9:	c3                   	retq   
  4004fa:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000400500 <__do_global_dtors_aux>:
  400500:	80 3d 31 0b 20 00 00 	cmpb   $0x0,0x200b31(%rip)        # 601038 <__TMC_END__>
  400507:	75 11                	jne    40051a <__do_global_dtors_aux+0x1a>
  400509:	55                   	push   %rbp
  40050a:	48 89 e5             	mov    %rsp,%rbp
  40050d:	e8 6e ff ff ff       	callq  400480 <deregister_tm_clones>
  400512:	5d                   	pop    %rbp
  400513:	c6 05 1e 0b 20 00 01 	movb   $0x1,0x200b1e(%rip)        # 601038 <__TMC_END__>
  40051a:	f3 c3                	repz retq 
  40051c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400520 <frame_dummy>:
  400520:	bf 20 0e 60 00       	mov    $0x600e20,%edi
  400525:	48 83 3f 00          	cmpq   $0x0,(%rdi)
  400529:	75 05                	jne    400530 <frame_dummy+0x10>
  40052b:	eb 93                	jmp    4004c0 <register_tm_clones>
  40052d:	0f 1f 00             	nopl   (%rax)
  400530:	b8 00 00 00 00       	mov    $0x0,%eax
  400535:	48 85 c0             	test   %rax,%rax
  400538:	74 f1                	je     40052b <frame_dummy+0xb>
  40053a:	55                   	push   %rbp
  40053b:	48 89 e5             	mov    %rsp,%rbp
  40053e:	ff d0                	callq  *%rax
  400540:	5d                   	pop    %rbp
  400541:	e9 7a ff ff ff       	jmpq   4004c0 <register_tm_clones>

0000000000400546 <main>:
                            ; function prologue
			    ; push the old value of the base pointer %rbp/%ebp onto the stack
			    ; it was pointing to the base of the caller's stack frame before
			    ; mov the memory address in %rsp/%esp into %rbp/%ebp
			    ; make %rbp/%ebp point to whatever %rsp/%esp is pointing to
			    ; the stack pointer %rsp/%esp is pointing to the top of the stack,
			    ; the top of the caller function's stack frame, and moving the
			    ; base pointer over here is where the callee's function stack frame will
			    ; be constructed from.
  400546:	55                   	push   %rbp
  400547:	48 89 e5             	mov    %rsp,%rbp
                            ; then the stack pointer is decremented to make room for local variables
  40054a:	48 83 ec 20          	sub    $0x20,%rsp
  40054e:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  400555:	00 00 
  400557:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
  40055b:	31 c0                	xor    %eax,%eax
  40055d:	c6 45 e0 41          	movb   $0x41,-0x20(%rbp)
  400561:	c7 45 e4 04 00 00 00 	movl   $0x4,-0x1c(%rbp)
  400568:	c7 45 e8 05 00 00 00 	movl   $0x5,-0x18(%rbp)
  40056f:	f2 0f 10 05 b1 00 00 	movsd  0xb1(%rip),%xmm0        # 400628 <_IO_stdin_used+0x8>
  400576:	00 
  400577:	f2 0f 11 45 f0       	movsd  %xmm0,-0x10(%rbp)
  40057c:	b8 00 00 00 00       	mov    $0x0,%eax
  400581:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
  400585:	64 48 33 14 25 28 00 	xor    %fs:0x28,%rdx
  40058c:	00 00 
  40058e:	74 05                	je     400595 <main+0x4f>
  400590:	e8 8b fe ff ff       	callq  400420 <__stack_chk_fail@plt>
  400595:	c9                   	leaveq 
  400596:	c3                   	retq   
  400597:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  40059e:	00 00 

00000000004005a0 <__libc_csu_init>:
  4005a0:	41 57                	push   %r15
  4005a2:	41 56                	push   %r14
  4005a4:	41 89 ff             	mov    %edi,%r15d
  4005a7:	41 55                	push   %r13
  4005a9:	41 54                	push   %r12
  4005ab:	4c 8d 25 5e 08 20 00 	lea    0x20085e(%rip),%r12        # 600e10 <__frame_dummy_init_array_entry>
  4005b2:	55                   	push   %rbp
  4005b3:	48 8d 2d 5e 08 20 00 	lea    0x20085e(%rip),%rbp        # 600e18 <__init_array_end>
  4005ba:	53                   	push   %rbx
  4005bb:	49 89 f6             	mov    %rsi,%r14
  4005be:	49 89 d5             	mov    %rdx,%r13
  4005c1:	4c 29 e5             	sub    %r12,%rbp
  4005c4:	48 83 ec 08          	sub    $0x8,%rsp
  4005c8:	48 c1 fd 03          	sar    $0x3,%rbp
  4005cc:	e8 1f fe ff ff       	callq  4003f0 <_init>
  4005d1:	48 85 ed             	test   %rbp,%rbp
  4005d4:	74 20                	je     4005f6 <__libc_csu_init+0x56>
  4005d6:	31 db                	xor    %ebx,%ebx
  4005d8:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
  4005df:	00 
  4005e0:	4c 89 ea             	mov    %r13,%rdx
  4005e3:	4c 89 f6             	mov    %r14,%rsi
  4005e6:	44 89 ff             	mov    %r15d,%edi
  4005e9:	41 ff 14 dc          	callq  *(%r12,%rbx,8)
  4005ed:	48 83 c3 01          	add    $0x1,%rbx
  4005f1:	48 39 eb             	cmp    %rbp,%rbx
  4005f4:	75 ea                	jne    4005e0 <__libc_csu_init+0x40>
  4005f6:	48 83 c4 08          	add    $0x8,%rsp
  4005fa:	5b                   	pop    %rbx
  4005fb:	5d                   	pop    %rbp
  4005fc:	41 5c                	pop    %r12
  4005fe:	41 5d                	pop    %r13
  400600:	41 5e                	pop    %r14
  400602:	41 5f                	pop    %r15
  400604:	c3                   	retq   
  400605:	90                   	nop
  400606:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  40060d:	00 00 00 

0000000000400610 <__libc_csu_fini>:
  400610:	f3 c3                	repz retq 

Disassembly of section .fini:

0000000000400614 <_fini>:
  400614:	48 83 ec 08          	sub    $0x8,%rsp
  400618:	48 83 c4 08          	add    $0x8,%rsp
  40061c:	c3                   	retq   

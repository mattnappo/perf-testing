	.file	"vector_math.c"
	.text
	.globl	vec_add_naive
	.type	vec_add_naive, @function
vec_add_naive:
.LFB5011:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movl	%ecx, -44(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L2
.L3:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	vmovss	(%rax), %xmm1
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-32(%rbp), %rax
	addq	%rdx, %rax
	vmovss	(%rax), %xmm0
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	vaddss	%xmm0, %xmm1, %xmm0
	vmovss	%xmm0, (%rax)
	addl	$1, -4(%rbp)
.L2:
	movl	-4(%rbp), %eax
	cmpl	-44(%rbp), %eax
	jl	.L3
	nop
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5011:
	.size	vec_add_naive, .-vec_add_naive
	.globl	vec_add_avx
	.type	vec_add_avx, @function
vec_add_avx:
.LFB5012:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	andq	$-32, %rsp
	subq	$232, %rsp
	movq	%rdi, -96(%rsp)
	movq	%rsi, -104(%rsp)
	movq	%rdx, -112(%rsp)
	movl	%ecx, -116(%rsp)
	movl	$0, 228(%rsp)
	jmp	.L5
.L9:
	movl	228(%rsp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-96(%rsp), %rax
	addq	%rdx, %rax
	vmovss	(%rax), %xmm0
	movl	228(%rsp), %eax
	cltq
	addq	$1, %rax
	leaq	0(,%rax,4), %rdx
	movq	-96(%rsp), %rax
	addq	%rdx, %rax
	vmovss	(%rax), %xmm1
	movl	228(%rsp), %eax
	cltq
	addq	$2, %rax
	leaq	0(,%rax,4), %rdx
	movq	-96(%rsp), %rax
	addq	%rdx, %rax
	vmovss	(%rax), %xmm2
	movl	228(%rsp), %eax
	cltq
	addq	$3, %rax
	leaq	0(,%rax,4), %rdx
	movq	-96(%rsp), %rax
	addq	%rdx, %rax
	vmovss	(%rax), %xmm3
	movl	228(%rsp), %eax
	cltq
	addq	$4, %rax
	leaq	0(,%rax,4), %rdx
	movq	-96(%rsp), %rax
	addq	%rdx, %rax
	vmovss	(%rax), %xmm4
	movl	228(%rsp), %eax
	cltq
	addq	$5, %rax
	leaq	0(,%rax,4), %rdx
	movq	-96(%rsp), %rax
	addq	%rdx, %rax
	vmovss	(%rax), %xmm5
	movl	228(%rsp), %eax
	cltq
	addq	$6, %rax
	leaq	0(,%rax,4), %rdx
	movq	-96(%rsp), %rax
	addq	%rdx, %rax
	vmovss	(%rax), %xmm6
	movl	228(%rsp), %eax
	cltq
	addq	$7, %rax
	leaq	0(,%rax,4), %rdx
	movq	-96(%rsp), %rax
	addq	%rdx, %rax
	vmovss	(%rax), %xmm7
	vmovss	%xmm7, -60(%rsp)
	vmovss	%xmm6, -64(%rsp)
	vmovss	%xmm5, -68(%rsp)
	vmovss	%xmm4, -72(%rsp)
	vmovss	%xmm3, -76(%rsp)
	vmovss	%xmm2, -80(%rsp)
	vmovss	%xmm1, -84(%rsp)
	vmovss	%xmm0, -88(%rsp)
	vmovss	-60(%rsp), %xmm1
	vmovss	-64(%rsp), %xmm0
	vunpcklps	%xmm1, %xmm0, %xmm1
	vmovss	-68(%rsp), %xmm2
	vmovss	-72(%rsp), %xmm0
	vunpcklps	%xmm2, %xmm0, %xmm0
	vmovlhps	%xmm1, %xmm0, %xmm1
	vmovss	-76(%rsp), %xmm2
	vmovss	-80(%rsp), %xmm0
	vunpcklps	%xmm2, %xmm0, %xmm2
	vmovss	-84(%rsp), %xmm3
	vmovss	-88(%rsp), %xmm0
	vunpcklps	%xmm3, %xmm0, %xmm0
	vmovlhps	%xmm2, %xmm0, %xmm0
	vinsertf128	$0x1, %xmm1, %ymm0, %ymm0
	vmovaps	%ymm0, 168(%rsp)
	movl	228(%rsp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-104(%rsp), %rax
	addq	%rdx, %rax
	vmovss	(%rax), %xmm0
	movl	228(%rsp), %eax
	cltq
	addq	$1, %rax
	leaq	0(,%rax,4), %rdx
	movq	-104(%rsp), %rax
	addq	%rdx, %rax
	vmovss	(%rax), %xmm1
	movl	228(%rsp), %eax
	cltq
	addq	$2, %rax
	leaq	0(,%rax,4), %rdx
	movq	-104(%rsp), %rax
	addq	%rdx, %rax
	vmovss	(%rax), %xmm2
	movl	228(%rsp), %eax
	cltq
	addq	$3, %rax
	leaq	0(,%rax,4), %rdx
	movq	-104(%rsp), %rax
	addq	%rdx, %rax
	vmovss	(%rax), %xmm3
	movl	228(%rsp), %eax
	cltq
	addq	$4, %rax
	leaq	0(,%rax,4), %rdx
	movq	-104(%rsp), %rax
	addq	%rdx, %rax
	vmovss	(%rax), %xmm4
	movl	228(%rsp), %eax
	cltq
	addq	$5, %rax
	leaq	0(,%rax,4), %rdx
	movq	-104(%rsp), %rax
	addq	%rdx, %rax
	vmovss	(%rax), %xmm5
	movl	228(%rsp), %eax
	cltq
	addq	$6, %rax
	leaq	0(,%rax,4), %rdx
	movq	-104(%rsp), %rax
	addq	%rdx, %rax
	vmovss	(%rax), %xmm6
	movl	228(%rsp), %eax
	cltq
	addq	$7, %rax
	leaq	0(,%rax,4), %rdx
	movq	-104(%rsp), %rax
	addq	%rdx, %rax
	vmovss	(%rax), %xmm7
	vmovss	%xmm7, -28(%rsp)
	vmovss	%xmm6, -32(%rsp)
	vmovss	%xmm5, -36(%rsp)
	vmovss	%xmm4, -40(%rsp)
	vmovss	%xmm3, -44(%rsp)
	vmovss	%xmm2, -48(%rsp)
	vmovss	%xmm1, -52(%rsp)
	vmovss	%xmm0, -56(%rsp)
	vmovss	-28(%rsp), %xmm1
	vmovss	-32(%rsp), %xmm0
	vunpcklps	%xmm1, %xmm0, %xmm1
	vmovss	-36(%rsp), %xmm2
	vmovss	-40(%rsp), %xmm0
	vunpcklps	%xmm2, %xmm0, %xmm0
	vmovlhps	%xmm1, %xmm0, %xmm1
	vmovss	-44(%rsp), %xmm2
	vmovss	-48(%rsp), %xmm0
	vunpcklps	%xmm2, %xmm0, %xmm2
	vmovss	-52(%rsp), %xmm3
	vmovss	-56(%rsp), %xmm0
	vunpcklps	%xmm3, %xmm0, %xmm0
	vmovlhps	%xmm2, %xmm0, %xmm0
	vinsertf128	$0x1, %xmm1, %ymm0, %ymm0
	vmovaps	%ymm0, 136(%rsp)
	vmovaps	168(%rsp), %ymm0
	vmovaps	%ymm0, 8(%rsp)
	vmovaps	136(%rsp), %ymm0
	vmovaps	%ymm0, -24(%rsp)
	vmovaps	8(%rsp), %ymm0
	vaddps	-24(%rsp), %ymm0, %ymm0
	vmovaps	%ymm0, 104(%rsp)
	movl	228(%rsp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-112(%rsp), %rax
	addq	%rdx, %rax
	movq	%rax, 96(%rsp)
	vmovaps	104(%rsp), %ymm0
	vmovaps	%ymm0, 40(%rsp)
	vmovaps	40(%rsp), %ymm0
	movq	96(%rsp), %rax
	vmovups	%ymm0, (%rax)
	nop
	addl	$8, 228(%rsp)
.L5:
	movl	228(%rsp), %eax
	cmpl	-116(%rsp), %eax
	jl	.L9
	nop
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5012:
	.size	vec_add_avx, .-vec_add_avx
	.section	.rodata
.LC0:
	.string	"vector_math.c"
.LC1:
	.string	"c[i] == a[i] + b[i]"
	.text
	.globl	vec_check_add
	.type	vec_check_add, @function
vec_check_add:
.LFB5013:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movl	%ecx, -44(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L11
.L14:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	vmovss	(%rax), %xmm0
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	vmovss	(%rax), %xmm2
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-32(%rbp), %rax
	addq	%rdx, %rax
	vmovss	(%rax), %xmm1
	vaddss	%xmm1, %xmm2, %xmm1
	vucomiss	%xmm1, %xmm0
	jp	.L15
	vucomiss	%xmm1, %xmm0
	je	.L12
.L15:
	movl	$__PRETTY_FUNCTION__.0, %ecx
	movl	$43, %edx
	movl	$.LC0, %esi
	movl	$.LC1, %edi
	call	__assert_fail
.L12:
	addl	$1, -4(%rbp)
.L11:
	movl	-4(%rbp), %eax
	cmpl	-44(%rbp), %eax
	jl	.L14
	nop
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5013:
	.size	vec_check_add, .-vec_check_add
	.section	.rodata
	.align 8
	.type	__PRETTY_FUNCTION__.0, @object
	.size	__PRETTY_FUNCTION__.0, 14
__PRETTY_FUNCTION__.0:
	.string	"vec_check_add"
	.ident	"GCC: (GNU) 14.2.1 20240801 (Red Hat 14.2.1-1)"
	.section	.note.GNU-stack,"",@progbits

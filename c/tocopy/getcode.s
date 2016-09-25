	.file	"getcode.c"
	.section	.rodata
.LC0:
	.string	"Erreur : Arguments"
.LC1:
	.string	"r"
.LC2:
	.string	"w"
.LC3:
	.string	"tocopyTab.c"
.LC4:
	.string	"Erreur : Ouverture fichier"
	.align 8
.LC5:
	.string	"#include<stdio.h>\nchar tab[] = {%d"
.LC6:
	.string	", %d"
.LC7:
	.string	"};"
	.align 8
.LC8:
	.ascii	"int main(){  FILE *fp;  long "
	.string	"int i = sizeof(tab) / sizeof(*tab) - 1;  int j = 0;  fp = fopen(\"tocopyFinal\", \"w\");  if(fp == NULL)    {      printf(\"Erreur : Acces tocopyFinal\");      return 1;    }    while(i-- >= 0)      putc(tab[j++], fp);system(\"chmod u+x tocopyFinal\");  return 0;}"
.LC9:
	.string	"gcc tocopyTab.c -o extract"
.LC10:
	.string	"rm tocopyTab.c"
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
	subq	$48, %rsp
	movl	%edi, -36(%rbp)
	movq	%rsi, -48(%rbp)
	cmpl	$2, -36(%rbp)
	je	.L2
	movl	$.LC0, %edi
	call	puts
	movl	$1, %eax
	jmp	.L3
.L2:
	movq	-48(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movl	$.LC1, %esi
	movq	%rax, %rdi
	call	fopen
	movq	%rax, -16(%rbp)
	movl	$.LC2, %esi
	movl	$.LC3, %edi
	call	fopen
	movq	%rax, -8(%rbp)
	cmpq	$0, -16(%rbp)
	je	.L4
	cmpq	$0, -8(%rbp)
	jne	.L5
.L4:
	movl	$.LC4, %edi
	movl	$0, %eax
	call	printf
	movl	$1, %eax
	jmp	.L3
.L5:
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	fgetc
	movl	%eax, -20(%rbp)
	movl	-20(%rbp), %edx
	movq	-8(%rbp), %rax
	movl	$.LC5, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	jmp	.L6
.L7:
	movl	-20(%rbp), %edx
	movq	-8(%rbp), %rax
	movl	$.LC6, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
.L6:
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	fgetc
	movl	%eax, -20(%rbp)
	cmpl	$-1, -20(%rbp)
	jne	.L7
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	movl	$2, %edx
	movl	$1, %esi
	movl	$.LC7, %edi
	call	fwrite
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	movl	$285, %edx
	movl	$1, %esi
	movl	$.LC8, %edi
	call	fwrite
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	fclose
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	fclose
	movl	$.LC9, %edi
	call	system
	movl	$.LC10, %edi
	call	system
	movl	$0, %eax
.L3:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.7.2-2ubuntu1) 4.7.2"
	.section	.note.GNU-stack,"",@progbits

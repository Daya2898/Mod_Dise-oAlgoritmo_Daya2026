	.file	"reglas.c"
	.text
	.section .rdata,"dr"
	.align 8
.LC0:
	.ascii "========================================\0"
.LC1:
	.ascii "REGLAS DEL LABORATORIO\0"
	.align 8
.LC2:
	.ascii "1.\11Guardar y hacer commit con frecuencia\0"
	.align 8
.LC3:
	.ascii "2.\11No comer ni beber cerca de los equipos\0"
.LC4:
	.ascii "3.\11Apagar el equipo al salir \0"
.LC5:
	.ascii "Gracias por su colaboraci\303\263n\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	call	__main
	leaq	.LC0(%rip), %rax
	movq	%rax, %rcx
	call	puts
	leaq	.LC1(%rip), %rax
	movq	%rax, %rcx
	call	puts
	leaq	.LC2(%rip), %rax
	movq	%rax, %rcx
	call	puts
	leaq	.LC3(%rip), %rax
	movq	%rax, %rcx
	call	puts
	leaq	.LC4(%rip), %rax
	movq	%rax, %rcx
	call	puts
	leaq	.LC5(%rip), %rax
	movq	%rax, %rcx
	call	puts
	leaq	.LC0(%rip), %rax
	movq	%rax, %rcx
	call	puts
	movl	$0, %eax
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (Rev4, Built by MSYS2 project) 16.2.0"
	.def	puts;	.scl	2;	.type	32;	.endef

	bits	32
	section	.text
	COMMON	z	4
	GLOBAL	_fact
_fact	push	ebp
	mov	ebp, esp
	sub	esp, 4
	mov	eax, [ebp+8]
	mov	eax, 1
	mov	[z], eax
L1:
	mov	eax, 1
	mov	[ebp-4], eax
	mov	eax, [ebp+8]
	cmp	eax, [ebp-4]
	setge	al
	movzx	eax, al
	cmp	eax, 0
	je	L2
	mov	eax, [ebp+8]
	mov	[ebp-4], eax
	mov	eax, [z]
	imul	eax, [ebp-4]
	mov	[z], eax
	mov	eax, 1
	mov	[ebp-4], eax
	mov	eax, [ebp+8]
	sub	eax, [ebp-4]
	mov	[ebp+8], eax
	jmp	L1
L2:
	mov	eax, [z]
	jmp	Lretfact
Lretfact	mov	esp, ebp
	pop	ebp
	ret

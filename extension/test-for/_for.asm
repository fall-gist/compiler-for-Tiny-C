	bits	32
	section	.text
	GLOBAL	_fact
_fact	push	ebp
	mov	ebp, esp
	sub	esp, 12
	mov	eax, [ebp-4]
	mov	eax, 1
	mov	[ebp-8], eax
	mov	eax, 1
	mov	[ebp-4], eax
L1:
	mov	eax, [ebp+8]
	mov	[ebp-12], eax
	mov	eax, [ebp-4]
	cmp	eax, [ebp-12]
	setle	al
	movzx	eax, al
	cmp	eax, 0
	je	L2
	mov	eax, [ebp-4]
	mov	[ebp-12], eax
	mov	eax, [ebp-8]
	imul	eax, [ebp-12]
	mov	[ebp-8], eax
	mov	eax, 1
	mov	[ebp-12], eax
	mov	eax, [ebp-4]
	add	eax, [ebp-12]
	mov	[ebp-4], eax
	jmp	L1
L2:
	mov	eax, [ebp-8]
	jmp	Lretfact
Lretfact	mov	esp, ebp
	pop	ebp
	ret

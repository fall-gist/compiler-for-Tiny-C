	bits	32
	section	.text
	GLOBAL	_foo
_foo	push	ebp
	mov	ebp, esp
	sub	esp, 8
	mov	eax, [ebp+8]
	mov	eax, [ebp-4]
	mov	eax, [ebp+8]
	mov	[ebp-8], eax
	mov	eax, [ebp+8]
	imul	eax, [ebp-8]
	mov	[ebp-4], eax
	mov	eax, 2
	mov	[ebp-8], eax
	mov	eax, [ebp-4]
	add	eax, [ebp-8]
	jmp	Lretfoo
Lretfoo	mov	esp, ebp
	pop	ebp
	ret

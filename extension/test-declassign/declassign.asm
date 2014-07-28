	bits	32
	section	.text
	GLOBAL	_f
_f	push	ebp
	mov	ebp, esp
	sub	esp, 4
	mov	eax, 1
	mov	[ebp-4], eax
Lretf	mov	esp, ebp
	pop	ebp
	ret

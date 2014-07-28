	bits	32
	section	.text
	GLOBAL	_f
_f	push	ebp
	mov	ebp, esp
	sub	esp, 4
	mov	eax, [ebp+8]
	EXTERN	_g
	mov	eax, [ebp+8]
	push	eax
	call	_g
	mov	[ebp-4], eax
	EXTERN	_g
	mov	eax, [ebp+8]
	push	eax
	call	_g
	imul	eax, [ebp-4]
	jmp	Lretf
Lretf	mov	esp, ebp
	pop	ebp
	ret

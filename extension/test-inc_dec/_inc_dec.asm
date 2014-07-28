	bits	32
	section	.text
	GLOBAL	_f
_f	push	ebp
	mov	ebp, esp
	sub	esp, 8
	mov	eax, [ebp-8]
	mov	eax, 0
	mov	[ebp-4], eax
	mov	eax, [ebp-4]
	inc	eax
	mov	[ebp-4], eax
	mov	[ebp-8], eax
	mov	eax, [ebp-4]
	jmp	Lretf
Lretf	mov	esp, ebp
	pop	ebp
	ret
	GLOBAL	_g
_g	push	ebp
	mov	ebp, esp
	sub	esp, 8
	mov	eax, [ebp-8]
	mov	eax, 0
	mov	[ebp-4], eax
	mov	eax, [ebp-4]
	dec	eax
	mov	[ebp-4], eax
	mov	[ebp-8], eax
	mov	eax, [ebp-8]
	jmp	Lretg
Lretg	mov	esp, ebp
	pop	ebp
	ret

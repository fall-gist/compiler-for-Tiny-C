	bits	32
	section	.text
	GLOBAL	_f
_f	push	ebp
	mov	ebp, esp
	sub	esp, 8
	mov	eax, 0
	mov	[ebp-4], eax
	inc	eax
	mov	[ebp-4], eax
	mov	[ebp-8], eax
	mov	eax, [ebp-4]
Lretf	mov	esp, ebp
	pop	ebp
	ret
	GLOBAL	_g
_g	push	ebp
	mov	ebp, esp
	sub	esp, 8
	mov	eax, 0
	mov	[ebp-4], eax
	dec	eax
	mov	[ebp-4], eax
	mov	[ebp-8], eax
Lretg	mov	esp, ebp
	pop	ebp
	ret

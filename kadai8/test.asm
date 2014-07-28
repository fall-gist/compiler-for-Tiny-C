	bits	32
	section	.text
	mov	eax, [x]
	GLOBAL	_f
_f	push	ebp
	mov	ebp, esp
	sub	esp, 28
	mov	eax, [ebp+8]
	mov	eax, [ebp+12]
	mov	eax, [ebp-4]
	mov	eax, [ebp-8]
	mov	eax, [ebp-12]
	mov	eax, [ebp-12]
	mov	[ebp-16], eax
	mov	eax, [ebp-8]
	add	eax, [ebp-16]
	mov	eax, [ebp-16]
	mov	eax, [ebp-20]
	mov	eax, [ebp-20]
	mov	[ebp-24], eax
	mov	eax, [ebp-12]
	mov	[ebp-28], eax
	mov	eax, [ebp-16]
	add	eax, [ebp-28]
	add	eax, [ebp-24]
	mov	eax, [ebp-8]
	mov	eax, [ebp-8]
	mov	[ebp-12], eax
	mov	eax, [ebp+12]
	mov	[ebp-16], eax
	mov	eax, [ebp-4]
	add	eax, [ebp-16]
	add	eax, [ebp-12]
	mov	eax, [ebp+12]
	mov	[ebp-8], eax
	mov	eax, [ebp-4]
	add	eax, [ebp-8]
Lretf	mov	esp, ebp
	pop	ebp
	ret
	GLOBAL	_g
_g	push	ebp
	mov	ebp, esp
	sub	esp, 28
	mov	eax, [ebp+8]
	mov	eax, [ebp-4]
	mov	eax, [ebp+8]
	push	eax
	mov	eax, [x]
	push	eax
	call	_f
	mov	eax, [ebp-4]
	push	eax
	call	_g
Lretg	mov	esp, ebp
	pop	ebp
	ret

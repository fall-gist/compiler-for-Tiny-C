	bits	32
	section	.text
	GLOBAL	_sum_of_squares
_sum_of_squares	push	ebp
	mov	ebp, esp
	sub	esp, 8
	mov	eax, [ebp+12]
	mov	eax, [ebp+12]
	mov	[ebp-8], eax
	mov	eax, [ebp+12]
	imul	eax, [ebp-8]
	mov	[ebp-4], eax
	mov	eax, [ebp+8]
	mov	[ebp-8], eax
	mov	eax, [ebp+8]
	imul	eax, [ebp-8]
	add	eax, [ebp-4]
	jmp	Lretsum_of_squares
Lretsum_of_squares	mov	esp, ebp
	pop	ebp
	ret

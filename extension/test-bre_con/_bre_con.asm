	bits	32
	section	.text
	GLOBAL	_sum_even
_sum_even	push	ebp
	mov	ebp, esp
	sub	esp, 12
	mov	eax, [ebp-4]
	mov	eax, 0
	mov	[ebp-8], eax
	mov	eax, 0
	mov	[ebp-4], eax
L1:
	mov	eax, [ebp-4]
	inc	eax
	mov	[ebp-4], eax
	mov	eax, [ebp+8]
	mov	[ebp-12], eax
	mov	eax, [ebp-4]
	cmp	eax, [ebp-12]
	setg	al
	movzx	eax, al
	cmp	eax, 0
	je	L3
	jmp	L2
L3:
	mov	eax, 2
	mov	[ebp-12], eax
	mov	eax, [ebp-4]
	cdq
	idiv	dword [ebp-12]
	mov	eax, edx
	cmp	eax, 0
	je	L5
	jmp	L1
L5:
	mov	eax, [ebp-4]
	mov	[ebp-12], eax
	mov	eax, [ebp-8]
	add	eax, [ebp-12]
	mov	[ebp-8], eax
	jmp	L1
L2:
	mov	eax, [ebp-8]
	jmp	Lretsum_even
Lretsum_even	mov	esp, ebp
	pop	ebp
	ret

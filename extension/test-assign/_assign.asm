	bits	32
	section	.text
	GLOBAL	_addass
_addass	push	ebp
	mov	ebp, esp
	sub	esp, 8
	mov	eax, 0
	mov	[ebp-4], eax
	mov	eax, 2
	mov	[ebp-8], eax
	mov	eax, [ebp-4]
	add	eax, [ebp-8]
	mov	[ebp-4], eax
	mov	eax, [ebp-4]
	jmp	Lretaddass
Lretaddass	mov	esp, ebp
	pop	ebp
	ret
	GLOBAL	_subass
_subass	push	ebp
	mov	ebp, esp
	sub	esp, 8
	mov	eax, 5
	mov	[ebp-4], eax
	mov	eax, 2
	mov	[ebp-8], eax
	mov	eax, [ebp-4]
	sub	eax, [ebp-8]
	mov	[ebp-4], eax
	mov	eax, [ebp-4]
	jmp	Lretsubass
Lretsubass	mov	esp, ebp
	pop	ebp
	ret
	GLOBAL	_mulass
_mulass	push	ebp
	mov	ebp, esp
	sub	esp, 8
	mov	eax, 1
	mov	[ebp-4], eax
	mov	eax, 4
	mov	[ebp-8], eax
	mov	eax, [ebp-4]
	imul	eax, [ebp-8]
	mov	[ebp-4], eax
	mov	eax, [ebp-4]
	jmp	Lretmulass
Lretmulass	mov	esp, ebp
	pop	ebp
	ret
	GLOBAL	_divass
_divass	push	ebp
	mov	ebp, esp
	sub	esp, 8
	mov	eax, 10
	mov	[ebp-4], eax
	mov	eax, 2
	mov	[ebp-8], eax
	mov	eax, [ebp-4]
	cdq
	idiv	dword [ebp-8]
	mov	[ebp-4], eax
	mov	eax, [ebp-4]
	jmp	Lretdivass
Lretdivass	mov	esp, ebp
	pop	ebp
	ret
	GLOBAL	_assigns
_assigns	push	ebp
	mov	ebp, esp
	sub	esp, 20
	mov	eax, [ebp-8]
	mov	eax, 1
	mov	[ebp-4], eax
	mov	eax, 2
	mov	[ebp-8], eax
	mov	eax, 3
	mov	[ebp-12], eax
	mov	eax, [ebp-12]
	mov	[ebp-20], eax
	mov	eax, [ebp-8]
	imul	eax, [ebp-20]
	mov	[ebp-8], eax
	mov	[ebp-16], eax
	mov	eax, [ebp-4]
	add	eax, [ebp-16]
	mov	[ebp-4], eax
	mov	eax, [ebp-4]
	jmp	Lretassigns
Lretassigns	mov	esp, ebp
	pop	ebp
	ret

	bits	32
	section	.text
	GLOBAL	_addass
_addass	push	ebp
	mov	ebp, esp
	sub	esp, 8
	mov	[ebp-4], 0
	mov	[ebp-8], 2
	mov	eax, [ebp-4]
	add	eax, [ebp-8]
	mov	[ebp-4], eax
Lretaddass	mov	esp, ebp
	pop	ebp
	ret
	GLOBAL	_subass
_subass	push	ebp
	mov	ebp, esp
	sub	esp, 8
	mov	[ebp-4], 5
	mov	[ebp-8], 2
	mov	eax, [ebp-4]
	sub	eax, [ebp-8]
	mov	[ebp-4], eax
Lretsubass	mov	esp, ebp
	pop	ebp
	ret
	GLOBAL	_mulass
_mulass	push	ebp
	mov	ebp, esp
	sub	esp, 8
	mov	[ebp-4], 1
	mov	[ebp-8], 4
	mov	eax, [ebp-4]
	imul	eax, [ebp-8]
	mov	[ebp-4], eax
Lretmulass	mov	esp, ebp
	pop	ebp
	ret
	GLOBAL	_divass
_divass	push	ebp
	mov	ebp, esp
	sub	esp, 8
	mov	[ebp-4], 10
	mov	[ebp-8], 2
	mov	eax, [ebp-4]
	cdq
	idiv	dword [ebp-8]
	mov	[ebp-4], eax
Lretdivass	mov	esp, ebp
	pop	ebp
	ret
	GLOBAL	_assigns
_assigns	push	ebp
	mov	ebp, esp
	sub	esp, 20
	mov	[ebp-4], 1
	mov	[ebp-8], 2
	mov	[ebp-12], 3
	mov	[ebp-20], [ebp-12]
	mov	eax, [ebp-8]
	imul	eax, [ebp-20]
	mov	[ebp-8], eax
	mov	[ebp-16], eax
	mov	eax, [ebp-4]
	add	eax, [ebp-16]
	mov	[ebp-4], eax
Lretassigns	mov	esp, ebp
	pop	ebp
	ret

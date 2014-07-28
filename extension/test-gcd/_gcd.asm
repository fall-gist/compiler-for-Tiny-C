	bits	32
	section	.text
	GLOBAL	_gcd1
_gcd1	push	ebp
	mov	ebp, esp
	sub	esp, 4
	mov	eax, [ebp+12]
	mov	eax, [ebp+12]
	mov	[ebp-4], eax
	mov	eax, [ebp+8]
	cmp	eax, [ebp-4]
	sete	al
	movzx	eax, al
	cmp	eax, 0
	je	L1
	mov	eax, [ebp+8]
	jmp	Lretgcd1
	jmp	L2
L1:
	mov	eax, [ebp+12]
	mov	[ebp-4], eax
	mov	eax, [ebp+8]
	cmp	eax, [ebp-4]
	setg	al
	movzx	eax, al
	cmp	eax, 0
	je	L3
	mov	eax, [ebp+12]
	push	eax
	mov	eax, [ebp+12]
	mov	[ebp-4], eax
	mov	eax, [ebp+8]
	sub	eax, [ebp-4]
	push	eax
	call	_gcd1
	jmp	Lretgcd1
	jmp	L4
L3:
	mov	eax, [ebp+8]
	mov	[ebp-4], eax
	mov	eax, [ebp+12]
	sub	eax, [ebp-4]
	push	eax
	mov	eax, [ebp+8]
	push	eax
	call	_gcd1
	jmp	Lretgcd1
L4:
L2:
Lretgcd1	mov	esp, ebp
	pop	ebp
	ret
	GLOBAL	_gcd2
_gcd2	push	ebp
	mov	ebp, esp
	sub	esp, 4
	mov	eax, [ebp+12]
	mov	eax, [ebp+12]
	mov	[ebp-4], eax
	mov	eax, [ebp+8]
	cmp	eax, [ebp-4]
	sete	al
	movzx	eax, al
	cmp	eax, 0
	je	L5
	mov	eax, [ebp+8]
	jmp	Lretgcd2
	jmp	L6
L5:
	mov	eax, [ebp+12]
	mov	[ebp-4], eax
	mov	eax, [ebp+8]
	cmp	eax, [ebp-4]
	setg	al
	movzx	eax, al
	cmp	eax, 0
	je	L7
	mov	eax, [ebp+12]
	push	eax
	mov	eax, [ebp+12]
	mov	[ebp-4], eax
	mov	eax, [ebp+8]
	sub	eax, [ebp-4]
	push	eax
	call	_gcd2
	jmp	Lretgcd2
	jmp	L8
L7:
	mov	eax, [ebp+8]
	mov	[ebp-4], eax
	mov	eax, [ebp+12]
	sub	eax, [ebp-4]
	push	eax
	mov	eax, [ebp+8]
	push	eax
	call	_gcd2
	jmp	Lretgcd2
L8:
L6:
Lretgcd2	mov	esp, ebp
	pop	ebp
	ret

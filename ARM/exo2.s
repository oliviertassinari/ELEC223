mov r1, #0xef
orr r1, r1, #0xbe00
orr r1, r1, #0xad00000
orr r1, r1, #0xde0000000

mov r2, #0x100
mov r3, #0x200

Loop:
	cmp r2, r3
	beq Fin
	str r1, [r2]
	add r2, r2, #0x04
	bne Loop

Fin:
	mov r4, #0x01
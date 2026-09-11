#off1=13
#toff=0
# offset=13
	.text
	.global	main
main:
	leas	-13,s
	ldb	#65
	stb	8,s
	ldb	#66
	stb	9,s
	ldb	#67
	stb	10,s
	clr	11,s
	ldb	#20
	stb	0,s
	clr	1,s
	leay	8,s
	sty	2,s
	ldd	#3
	std	4,s
	ldd	#0
	std	6,s
	leax	,s
	tfr	x,d
	jsr	(bios_call)
	stb	12,s
	ldd	#0
.l1:
	leas	13,s
	rts
	.type	main,@function
	.size	main,$-main

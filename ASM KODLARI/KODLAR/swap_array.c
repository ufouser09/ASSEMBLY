//2 dizinin yerini farkli adreslemeyle degistirelim 
//d1,d2 byte tanýmli
//n:dizinin boyutu

	MOV CX,N
	XOR SI,SI
	LEA DI,d2

DON:MOV AL,d1[SI]
	XCHG AL,[DI]
	MOV d1[SI],AL

	INC DI
	INC SI 
	LOOP DON

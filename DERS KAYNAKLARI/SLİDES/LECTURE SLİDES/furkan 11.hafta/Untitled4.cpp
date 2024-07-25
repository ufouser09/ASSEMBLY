			EXTRN n:WORD, dizi:BYTE
			PUBLIC SIRALIMI
mycode		SEGMENT PARA 'kk'
			ASSUME CS:mycode
SIRALIMI	PROC FAR
			PUSH DI
			PUSH CX
			XOR DI, DI
			XOR AX, AX
			MOV CX, n
			DEC CX

don:		CMP DI, CX
			JAE sirali
			MOV AH, dizi[DI]
			CMP AH, dizi[DI+1]
			JG sirasiz
			INC DI
			JMP don
sirali:		MOV AL, 1
sirasiz:	POP CX
			POP DI
			RETF
SIRALIMI	ENDP
mycode		ENDS
			END

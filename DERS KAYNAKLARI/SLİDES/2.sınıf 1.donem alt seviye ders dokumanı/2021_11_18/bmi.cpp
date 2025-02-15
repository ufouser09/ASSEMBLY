STSG SEGMENT PARA STACK 'STSGM'
	DW 20 DUP (?)
STSG ENDS

DTSG SEGMENT PARA 'DTSGM'
	BOY DB 80, 85, 90, 95, 100, 195 DUP (100)
	AGIR DW 300, 200, 250, 175, 150, 195 DUP (250)
	N DW 200
	BMI DW 200 DUP (0)
DTSG ENDS

CDSG SEGMENT PARA 'CDSGM'
	ASSUME CS: CDSG, DS: DTSG, SS: STSG
	
	ANA PROC FAR

		PUSH DS
		XOR AX, AX
		PUSH AX

		MOV AX, DTSG
		MOV DS, AX
		
		XOR SI, SI
		MOV CX, N
		MOV DI, 703

L1:	
		XOR AX, AX
		MOV AL, BOY[SI]
		MUL AL; AX <- AL^2 = h^2
		MOV BX, AX
		SHL SI, 1
		MOV AX, AGIR[SI]
		MUL DI; DX:AX <- w * 703
		;DX:AX/h^2
		DIV BX ; AX <- w*703/h^2, DX <- kalan
		MOV BMI[SI], AX
		SHR SI, 1
		INC SI
		LOOP L1	
		
		RETF
	ANA ENDP


CDSG ENDS

	END ANA

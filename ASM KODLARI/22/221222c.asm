mys		SEGMENT PARA 'kod'
		ORG 100h
		ASSUME CS:mys, DS:mys, SS:mys
BILGI:	JMP ANA
kuyruk	DB 14, 11, 54, 62, 11, 3, 8, 63, 16, 81, 5
k_esik	DB 15
b_esik	DB 50
indis 	DB ?
boyut	DW 11
ANA		PROC NEAR
		MOV AL, k_esik
		MOV AH, b_esik
		XOR BX, BX
don:	CMP kuyruk[BX], AL
		JB sonra
		CMP kuyruk[BX], AH
		JBE bulun
sonra:	INC BX
		JMP don
bulun:	MOV indis, BL
		RET
ANA		ENDP
mys		ENDS
		END BILGI
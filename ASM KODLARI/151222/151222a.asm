		EXTRN TOPLAMA:FAR
myss	SEGMENT PARA STACK 'yigin'
		DW 20 DUP(?)
myss	ENDS
mydata	SEGMENT PARA 'veri'
asay	DW 0fff1h
bsay	DW 12
top		DD 0
mydata	ENDS
mycode	SEGMENT PARA 'kod'
		ASSUME CS:mycode, SS:myss, DS:mydata
UZAK	PROC FAR
		PUSH DS
		XOR AX, AX
		PUSH AX
		MOV AX, mydata
		MOV DS, AX
		MOV AX, asay
		MOV BX, bsay
		LEA SI, top
		CALL TOPLAMA
		RETF
UZAK	ENDP
mycode	ENDS
		END UZAK

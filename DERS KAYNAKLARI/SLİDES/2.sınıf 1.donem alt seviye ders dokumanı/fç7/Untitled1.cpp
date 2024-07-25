datasg		SEGMENT PARA 'data'
a			DB 17
b			DB 12
c			DB 16
tip			DB 2
datasg		ENDS
stacksg		SEGMENT PARA STACK 'y'
			DW 12 DUP(?)
stacksg		ENDS
codesg		SEGMENT PARA 'kod'
			ASSUME CS:codesg, DS:datasg, SS:stacksg
UCGEN		PROC FAR
			PUSH DS
			XOR AX, AX
			PUSH AX
			MOV AX, datasg
			MOV DS, AX
			
			MOV AL, a
			MOV BL, b
			MOV CL, c
			CMP AL, BL
			JE J1
			CMP BL, CL
			JE SON
			CMP AL, CL
			JE SON
			MOV tip, 3
			JMP SON
J1:			CMP AL, CL
			JNE SON
			MOV tip, 1
			JMP SON	
SON:		RETF
UCGEN		ENDP
codesg		ENDS
			END UCGEN

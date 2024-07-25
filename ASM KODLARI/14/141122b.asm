datasg		SEGMENT PARA 'veri'
a			DB 13
b			DB 13
c			DB 13
tip			DB 2
datasg		ENDS
stacksg		SEGMENT PARA STACK 'yigin'
			DW 12 DUP(?)
stacksg		ENDS
codesg		SEGMENT PARA 'kod'
			ASSUME DS:datasg, CS:codesg, SS:stacksg
ILK			PROC FAR
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
			JE J2
			CMP AL, CL
			JE J2
			MOV tip, 3
			JMP J2
J1:			CMP AL, CL
			JNE J2
			MOV tip, 1
			JMP J2
J2:			RET

ILK			ENDP
codesg		ENDS
			END ILK
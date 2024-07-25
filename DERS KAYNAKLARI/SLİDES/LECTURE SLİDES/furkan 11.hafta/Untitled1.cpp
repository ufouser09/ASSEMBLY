			EXTRN ALAN_BUL:FAR
myss		SEGMENT PARA STACK 'ssss'
			DW 20 DUP(?)
myss		ENDS

myds		SEGMENT PARA 'dddd'
kenarlar	DW 8, 6, 5, 9, 12, 7, 2, 3, 2
n			DW 3
enbykalan	DW 0
myds		ENDS

mycs		SEGMENT PARA 'kkkk'
			ASSUME CS:mycs, DS:myds, SS:myss
ANA			PROC FAR
			PUSH DS
			XOR AX, AX
			PUSH AX
			MOV AX, myds
			MOV DS, AX

			MOV CX, n
			XOR BX, BX

L1:			PUSH kenarlar[BX]
			PUSH kenarlar[BX+2]
			PUSH kenarlar[BX+4]

			CALL ALAN_BUL

			CMP AX, enbykalan
			JBE devam
			MOV enbykalan, AX
devam:		ADD BX, 6
			LOOP L1

			RETF
ANA			ENDP
mycs		ENDS
			END ANA

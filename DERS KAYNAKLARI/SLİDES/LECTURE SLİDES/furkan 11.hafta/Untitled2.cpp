			PUBLIC ALAN_BUL
mycode		SEGMENT PARA 'kk'
			ASSUME CS:mycode
ALAN_BUL	PROC FAR
			PUSH BP
			PUSH BX
			PUSH CX
			PUSH DI
			PUSH DX

			MOV BP, SP
			XOR AX, AX
			ADD AX, [BP+14]
			ADD AX, [BP+16]
			ADD AX, [BP+18]
			SHR AX, 1			; u yu bulduk

			MOV BX, AX
			SUB BX, [BP+14]		; u-a

			MOV CX, AX
			SUB CX, [BP+16]		; u-b

			MOV DI, AX
			SUB DI, [BP+18]		; u-c

			MUL BX				; DX:AX <- BX * AX   u*(u-a)
			MUL CX				; AX: u*(u-a)*(u-b)
			MUL DI				; AX: u*(u-a)*(u-b)*(u-c)

			POP DX
			POP DI
			POP CX
			POP BX
			POP BP

			RETF 6
ALAN_BUL	ENDP
mycode		ENDS
			END

mys		SEGMENT PARA STACK 's'
		DW 20 DUP(?)
mys		ENDS
myd		SEGMENT PARA 'D'
sayi	DW 2
ust		DW 11
sonuc	DW ?
myd		ENDS
myc		SEGMENT PARA 'K'
		ASSUME CS:myc, DS:myd, SS:mys
ANA		PROC FAR
--------------------------------------------------------------------------------

		PUSH DS
		XOR AX, AX
		PUSH AX
--------------------------------------------------------------------------------

		MOV AX, myd
		MOV DS, AX
--------------------------------------------------------------------------------
		//sayi degiskenini Bx yazmac�na atan�r
		MOV BX, sayi
		//ust degiskeni Cx yazmac�na atan�r
		MOV CX, ust
		//ustal degiskeni cagr�l�r
		CALL ustal
		//Ax yazmac� sonuc degiskenine atan�r
		MOV sonuc, AX
		RETF
ANA		ENDP

ustal	PROC NEAR
		//Cx yazmac� stack'e at�l�r	
		PUSH CX
		//1 degeri Ax yazmac�na atan�r
		MOV AX, 1
		//Dx:Ax->Ax*Bx
L1:		MUL BX
		//dongu doner
		LOOP L1
		//stack'e at�lan Cx cekilir
		POP CX
		RET
ustal	ENDP
myc		ENDS
		END ANA

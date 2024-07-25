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
		//sayi degiskenini Bx yazmacýna atanýr
		MOV BX, sayi
		//ust degiskeni Cx yazmacýna atanýr
		MOV CX, ust
		//ustal degiskeni cagrýlýr
		CALL ustal
		//Ax yazmacý sonuc degiskenine atanýr
		MOV sonuc, AX
		RETF
ANA		ENDP

ustal	PROC NEAR
		//Cx yazmacý stack'e atýlýr	
		PUSH CX
		//1 degeri Ax yazmacýna atanýr
		MOV AX, 1
		//Dx:Ax->Ax*Bx
L1:		MUL BX
		//dongu doner
		LOOP L1
		//stack'e atýlan Cx cekilir
		POP CX
		RET
ustal	ENDP
myc		ENDS
		END ANA

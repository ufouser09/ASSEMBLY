		EXTRN TOPLAMA:FAR
mys		SEGMENT PARA STACK 's'
		DW 20 DUP(?)
mys		ENDS
myd		SEGMENT PARA 'D'
sayi1	DB 170
sayi2	DB 190
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
		//sayi 1 degiskeni Bl yazmac�na atan�r
		MOV BL, sayi1
		//sayi 2 degiskeni Bh yazmac�na atan�r
		MOV BH, sayi2
		//TOPLAMA �a�r�l�r
		CALL TOPLAMA
		//Ax yazmac�ndaki deger sonuc degiskenine atan�r
		MOV sonuc, AX
		RETF
ANA		ENDP
myc		ENDS
		END ANA

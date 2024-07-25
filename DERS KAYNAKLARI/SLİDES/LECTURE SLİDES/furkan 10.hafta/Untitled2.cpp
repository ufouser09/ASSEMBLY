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
		//sayi 1 degiskeni Bl yazmacýna atanýr
		MOV BL, sayi1
		//sayi 2 degiskeni Bh yazmacýna atanýr
		MOV BH, sayi2
		//TOPLAMA çaðrýlýr
		CALL TOPLAMA
		//Ax yazmacýndaki deger sonuc degiskenine atanýr
		MOV sonuc, AX
		RETF
ANA		ENDP
myc		ENDS
		END ANA

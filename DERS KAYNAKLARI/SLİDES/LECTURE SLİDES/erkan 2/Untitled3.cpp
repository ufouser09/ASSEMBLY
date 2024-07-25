-----------------------------------------------------------------------

STSG SEGMENT PARA STACK 'STSGM'
	DW 20 DUP (?)
STSG ENDS
-----------------------------------------------------------------------

DTSG SEGMENT PARA 'DTSGM'
	ASAY DW 0F000H
	BSAY DW 0E000H
	SONUC DD 0
DTSG ENDS
-----------------------------------------------------------------------

CDSG SEGMENT PARA 'CDSGM'
	ASSUME CS: CDSG, DS: DTSG, SS: STSG
-----------------------------------------------------------------------
	
	ANA PROC FAR
-----------------------------------------------------------------------

		PUSH DS
		XOR AX, AX
		PUSH AX
-----------------------------------------------------------------------

		MOV AX, DTSG
		MOV DS, AX
-----------------------------------------------------------------------
		//sonuc degiskeninin degeri Bx yazmacýna adreslenir
		LEA BX, SONUC
		//Ax yazmacýna A sayisi atýlýr
		MOV AX, ASAY
		//A sayisi ile B sayisi toplanýr
		ADD AX, BSAY
		//buldugumuz toplam BX adresine atýlýr
		MOV [BX], AX
		//eger carry miz olusmamýssa l1 etiketine gidilir
		JNC L1
		//eger carry miz olusmussa BX+2 ye carry miz atýlýr
		INC WORD PTR [BX+2]
L1:		
		RETF
	ANA ENDP


CDSG ENDS

	END ANA

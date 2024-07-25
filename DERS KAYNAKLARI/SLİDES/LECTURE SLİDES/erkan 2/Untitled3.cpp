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
		//sonuc degiskeninin degeri Bx yazmac�na adreslenir
		LEA BX, SONUC
		//Ax yazmac�na A sayisi at�l�r
		MOV AX, ASAY
		//A sayisi ile B sayisi toplan�r
		ADD AX, BSAY
		//buldugumuz toplam BX adresine at�l�r
		MOV [BX], AX
		//eger carry miz olusmam�ssa l1 etiketine gidilir
		JNC L1
		//eger carry miz olusmussa BX+2 ye carry miz at�l�r
		INC WORD PTR [BX+2]
L1:		
		RETF
	ANA ENDP


CDSG ENDS

	END ANA

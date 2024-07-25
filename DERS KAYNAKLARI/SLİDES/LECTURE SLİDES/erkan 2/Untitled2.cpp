-----------------------------------------------------------------------

STSG SEGMENT BYTE STACK 'STK'
	DW 32 DUP (?)
STSG ENDS
-----------------------------------------------------------------------

DTSG SEGMENT WORD 'DTK'
	ASAY DW 0F000H
	BSAY DW 0E000H
	SONUC DD 0
DTSG ENDS
-----------------------------------------------------------------------

CDSG SEGMENT WORD 'CDK'
	ASSUME CS: CDSG, DS: DTSG, SS: STSG
-----------------------------------------------------------------------

	ANA PROC FAR
		PUSH DS
		XOR AX, AX
		PUSH AX
-----------------------------------------------------------------------

		MOV AX, DTSG
		MOV DS, AX
-----------------------------------------------------------------------
		//sonuc degiskenin degeri BX yazmacýna atýlýr
		LEA BX, SONUC
		//A sayisi Ax yazmacýna atýlýr
		MOV AX, ASAY
		//A sayisi ile B sayisi toplanýr
		ADD AX, BSAY
		//buldugumuz toplam BX adresine atýlýr
		MOV [BX], AX
		//eger elde varsa onu da BX+2 ye koyarýz
		ADC WORD PTR [BX+2], 0
		

		RETF
	ANA ENDP

CDSG ENDS

	END ANA

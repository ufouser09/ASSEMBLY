-----------------------------------------------------------------------

STSG SEGMENT PARA STACK 'STSGM'
	DW 20 DUP (?)
STSG ENDS
-----------------------------------------------------------------------

DTSG SEGMENT PARA 'DTSGM'
	ASAY DD 0ABCDEF98H
	BSAY DD	0B9876543H
	SONUC DQ 0
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
		//A sayisi Sý adresine atýlýr
		LEA SI, ASAY
		//B sayisi Dý adresine atýlýr
		LEA DI, BSAY
		//sonuc degerimiz BX adresine atýlýr
		LEA BX, SONUC
		//Sý adresindeki deger Ax yazmacýna atýlýr
		MOV AX, [SI]
		//A sayisi ile B sayisini toplarýz
		ADD AX, [DI]
		//buldugumuz toplam Bx yazmacýna gider
		MOV [BX], AX	
		//tasma varsa o da BX+2 adresine gider
		ADC WORD PTR [BX+2], 0
		//A sayisinin Sý+2 adresindeki deger Ax yazmacýna gider
		MOV AX, [SI+2]
		//A sayisi ile B sayisi toplanýr
		ADD AX, [DI+2]
		//tasma varsa tasma Bx+4 degerine gider
		ADC WORD PTR [BX+4], 0
		//yeni buldugumuz toplam ile onceki tasmanýn saklandýgý Bx+2 adresi toplanýr
		ADD [BX+2], AX	
		//tasma varsa tasma BX+4 adresinde sakla
		ADC WORD PTR [BX+4], 0		
-----------------------------------------------------------------------
		
		RETF
	ANA ENDP


CDSG ENDS

	END ANA
-----------------------------------------------------------------------
	

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
		//A sayisi S� adresine at�l�r
		LEA SI, ASAY
		//B sayisi D� adresine at�l�r
		LEA DI, BSAY
		//sonuc degerimiz BX adresine at�l�r
		LEA BX, SONUC
		//S� adresindeki deger Ax yazmac�na at�l�r
		MOV AX, [SI]
		//A sayisi ile B sayisini toplar�z
		ADD AX, [DI]
		//buldugumuz toplam Bx yazmac�na gider
		MOV [BX], AX	
		//tasma varsa o da BX+2 adresine gider
		ADC WORD PTR [BX+2], 0
		//A sayisinin S�+2 adresindeki deger Ax yazmac�na gider
		MOV AX, [SI+2]
		//A sayisi ile B sayisi toplan�r
		ADD AX, [DI+2]
		//tasma varsa tasma Bx+4 degerine gider
		ADC WORD PTR [BX+4], 0
		//yeni buldugumuz toplam ile onceki tasman�n sakland�g� Bx+2 adresi toplan�r
		ADD [BX+2], AX	
		//tasma varsa tasma BX+4 adresinde sakla
		ADC WORD PTR [BX+4], 0		
-----------------------------------------------------------------------
		
		RETF
	ANA ENDP


CDSG ENDS

	END ANA
-----------------------------------------------------------------------
	

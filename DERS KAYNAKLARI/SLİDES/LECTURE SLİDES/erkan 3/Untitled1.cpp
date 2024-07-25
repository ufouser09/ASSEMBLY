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
		//A sayisi S� indisine at�l�r		
		LEA SI, ASAY
		//B sayisi D� indisine at�l�r
		LEA DI, BSAY
		//Sonuc B YAzmac�na at�l�r
		LEA BX, SONUC
		//S� indisindeki deger Ax yazmac�na at�l�r
		MOV AX, [SI]
		//A say�s� ile B sayisi toplan�r
		ADD AX, [DI]
		//buldugmuz toplam BX adresine at�l�r
		MOV [BX], AX	
		//eger tasma varsa BX+2 adresinde tutulur
		ADC WORD PTR [BX+2], 0
		//daha sonra S�+2 adresindeki deger Ax yazmac�na at�l�r
		MOV AX, [SI+2]
		//A sayisinin S�+2 yazmac�ndaki deger ile B sayisinin D�+2 adresindeki deger toplan�r
		ADD AX, [DI+2]
		//tasma varsa BX+4 adresine gider
		ADC WORD PTR [BX+4], 0
		//yeni buldugumuz toplam ile BX+2 deki tasma olan adres toplan�r
		ADD [BX+2], AX	
		//eger ondan da tasma varsa BX+4 adresine aktarilir.
		ADC WORD PTR [BX+4], 0		
		RETF
	ANA ENDP


CDSG ENDS

	END ANA

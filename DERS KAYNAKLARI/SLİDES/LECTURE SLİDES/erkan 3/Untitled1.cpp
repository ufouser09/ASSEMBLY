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
		//A sayisi Sý indisine atýlýr		
		LEA SI, ASAY
		//B sayisi Dý indisine atýlýr
		LEA DI, BSAY
		//Sonuc B YAzmacýna atýlýr
		LEA BX, SONUC
		//Sý indisindeki deger Ax yazmacýna atýlýr
		MOV AX, [SI]
		//A sayýsý ile B sayisi toplanýr
		ADD AX, [DI]
		//buldugmuz toplam BX adresine atýlýr
		MOV [BX], AX	
		//eger tasma varsa BX+2 adresinde tutulur
		ADC WORD PTR [BX+2], 0
		//daha sonra Sý+2 adresindeki deger Ax yazmacýna atýlýr
		MOV AX, [SI+2]
		//A sayisinin Sý+2 yazmacýndaki deger ile B sayisinin Dý+2 adresindeki deger toplanýr
		ADD AX, [DI+2]
		//tasma varsa BX+4 adresine gider
		ADC WORD PTR [BX+4], 0
		//yeni buldugumuz toplam ile BX+2 deki tasma olan adres toplanýr
		ADD [BX+2], AX	
		//eger ondan da tasma varsa BX+4 adresine aktarilir.
		ADC WORD PTR [BX+4], 0		
		RETF
	ANA ENDP


CDSG ENDS

	END ANA

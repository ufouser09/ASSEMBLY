-----------------------------------------------------------------------

STSG SEGMENT PARA STACK 'STSGM'
	DW 20 DUP (?)
STSG ENDS
-----------------------------------------------------------------------

DTSG SEGMENT PARA 'DTSGM'
	DIZI DB 300 DUP (255)
	N DW 300
	ORT DB 0
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
		//Cx yazmacýna N'i yani dongu sayisini atarýz
		MOV CX, N
		//Bx'i sýfýrlarýz
		XOR BX, BX
		//Dx'i sýfýrlarýz
		XOR DX, DX
		//Ax'i sýfýrlarýz
		XOR AX, AX
		//Carry'i sýfýrlarýz
		CLC
L1:	
		//dizinin Bx indisindeki degeri AL yazmacýna Atarýz	
		ADC AL, DIZI[BX]
		//carry varsa bunu Ah'da tutarýz
		ADC AH, 0
		//Dx'i sýfýrlarýz
		ADC DX, 0
		//Bx'i yani dongü indisimizi 1 arttýrýrýz
		INC BX
		//dongu dönmesi saglanýr		
		LOOP L1
		//Dx:Ax/Bx--->bolum:Ax,kalan:Dx
		DIV BX
		//bolum degerini ORT degiskenin de tutarýz.
		MOV ORT, AL			
		
		RETF
	ANA ENDP


CDSG ENDS

	END ANA

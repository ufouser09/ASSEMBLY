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
		//Cx yazmac�na N'i yani dongu sayisini atar�z
		MOV CX, N
		//Bx'i s�f�rlar�z
		XOR BX, BX
		//Dx'i s�f�rlar�z
		XOR DX, DX
		//Ax'i s�f�rlar�z
		XOR AX, AX
		//Carry'i s�f�rlar�z
		CLC
L1:	
		//dizinin Bx indisindeki degeri AL yazmac�na Atar�z	
		ADC AL, DIZI[BX]
		//carry varsa bunu Ah'da tutar�z
		ADC AH, 0
		//Dx'i s�f�rlar�z
		ADC DX, 0
		//Bx'i yani dong� indisimizi 1 artt�r�r�z
		INC BX
		//dongu d�nmesi saglan�r		
		LOOP L1
		//Dx:Ax/Bx--->bolum:Ax,kalan:Dx
		DIV BX
		//bolum degerini ORT degiskenin de tutar�z.
		MOV ORT, AL			
		
		RETF
	ANA ENDP


CDSG ENDS

	END ANA

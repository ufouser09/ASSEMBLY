-----------------------------------------------------------------------

STSG SEGMENT PARA STACK 'STSGM'
	DW 20 DUP (?)
STSG ENDS
-----------------------------------------------------------------------

DTSG SEGMENT PARA 'DTSGM'
	DIZI DW 1,2,3,4,5,195 DUP (0FFFFH)
	N DW 200
	ORT DW 0
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
		//N sayisini yani d�ng� sayisini Cx yazmac�na atar�z		
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
		//dizinin Bx indisindeki degeri Ax yazmac�na atar�z
		ADC AX, DIZI[BX]
		//kalan eldeyi de Dx yazmac�nda tutar�z
		ADC DX, 0
		//Bx'i yani indisi 2 artt�r�r�z
		ADD BX, 2	
		//dong�m�z doner
		LOOP L1
		//Bx 2'ser 2'ser artt�g� i�in onu 2 ye boleriz
		SHR BX, 1
		//Dx:Ax/Bx---->bolum:Ax,kalan:Dx
		DIV BX
		//bolum degerimiz Ax yani ortalamam�z olmustur onu da ORT'a atar�z
		MOV ORT, AX			
		
		RETF
	ANA ENDP


CDSG ENDS

	END ANA

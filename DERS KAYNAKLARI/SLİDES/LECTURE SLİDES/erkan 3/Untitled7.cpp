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
		//N sayisini yani döngü sayisini Cx yazmacýna atarýz		
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
		//dizinin Bx indisindeki degeri Ax yazmacýna atarýz
		ADC AX, DIZI[BX]
		//kalan eldeyi de Dx yazmacýnda tutarýz
		ADC DX, 0
		//Bx'i yani indisi 2 arttýrýrýz
		ADD BX, 2	
		//dongümüz doner
		LOOP L1
		//Bx 2'ser 2'ser arttýgý için onu 2 ye boleriz
		SHR BX, 1
		//Dx:Ax/Bx---->bolum:Ax,kalan:Dx
		DIV BX
		//bolum degerimiz Ax yani ortalamamýz olmustur onu da ORT'a atarýz
		MOV ORT, AX			
		
		RETF
	ANA ENDP


CDSG ENDS

	END ANA

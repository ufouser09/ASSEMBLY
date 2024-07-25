STSG SEGMENT PARA STACK 'STSGM'
	DW 20 DUP (?)
STSG ENDS
-----------------------------------------------------------------------

DTSG SEGMENT PARA 'DTSGM'
	ASAY DW 16
	BSAY DW 20
	GCD DW 0
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
		//Ax yazmac�na A sayisini atars�n
		MOV AX, ASAY
		//Bx yazmac�na B sayisini atars�n
		MOV BX, BSAY
		//A sayisi ile B sayisini kars�last�r�s�n
		CMP AX, BX ; AX<BX ise swap AX<->BX
		//eger A sayisi B sayisindan buyuk ise o zaman NOSWP etiketine atlars�n
		JAE NOSWP
		//Eger B A dan buyuk ise Ax ile Bx i yer degistirirsin
		XCHG AX, BX
NOSWP:	
		//B sayisi ile 0 � kars�last�r�rs�n
		CMP BX, 0
		//Eger B sayin 0'a esit ise direk c�k�sa gidebilirsin cunku ebobu bulmussundur
		JE CIKIS
		//eger Bx 0 a esit degilse o zaman devam et
		
		//16 bitlik bolme islemi yap�cag�m�z i�in Dx i s�f�rlar�z
		XOR DX, DX
		//DX:AX/BX---->bolum:Ax,kalan:DX de olusur
		DIV BX ; AX <- DX:AX/BX, DX <- DX:AX % BX
		//B sayisin� Ax'e atars�n 
		MOV AX, BX
		//Dx'i yani kalan'� Bx'e atars�n 
		MOV BX, DX
		//tekrar NOSWP etiketine atlars�n
		JMP NOSWP
CIKIS:		
		//Bx 0'esit oldugu durumda buraya gelirs�n Bx 0'a esitse zaten ebob o olur.
		; BX=0
		//????
		MOV GCD, AX
		
		RETF
	ANA ENDP


CDSG ENDS

	END ANA

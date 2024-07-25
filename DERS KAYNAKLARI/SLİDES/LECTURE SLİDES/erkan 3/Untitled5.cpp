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
		//Ax yazmacýna A sayisini atarsýn
		MOV AX, ASAY
		//Bx yazmacýna B sayisini atarsýn
		MOV BX, BSAY
		//A sayisi ile B sayisini karsýlastýrýsýn
		CMP AX, BX ; AX<BX ise swap AX<->BX
		//eger A sayisi B sayisindan buyuk ise o zaman NOSWP etiketine atlarsýn
		JAE NOSWP
		//Eger B A dan buyuk ise Ax ile Bx i yer degistirirsin
		XCHG AX, BX
NOSWP:	
		//B sayisi ile 0 ý karsýlastýrýrsýn
		CMP BX, 0
		//Eger B sayin 0'a esit ise direk cýkýsa gidebilirsin cunku ebobu bulmussundur
		JE CIKIS
		//eger Bx 0 a esit degilse o zaman devam et
		
		//16 bitlik bolme islemi yapýcagýmýz için Dx i sýfýrlarýz
		XOR DX, DX
		//DX:AX/BX---->bolum:Ax,kalan:DX de olusur
		DIV BX ; AX <- DX:AX/BX, DX <- DX:AX % BX
		//B sayisiný Ax'e atarsýn 
		MOV AX, BX
		//Dx'i yani kalan'ý Bx'e atarsýn 
		MOV BX, DX
		//tekrar NOSWP etiketine atlarsýn
		JMP NOSWP
CIKIS:		
		//Bx 0'esit oldugu durumda buraya gelirsýn Bx 0'a esitse zaten ebob o olur.
		; BX=0
		//????
		MOV GCD, AX
		
		RETF
	ANA ENDP


CDSG ENDS

	END ANA


//dizinin s�ral� m� s�ras�z oldugunu bulan kod 
myds		SEGMENT PARA 'data'
dizi		Db 1, 2, 6, 4, 5
n			DW 5
s			DB ?
myds		ENDS
myss		SEGMENT	PARA STACK 'yig'
			DW 12 DUP(?)
myss		ENDS
mycs		SEGMENT PARA 'kk'
			ASSUME CS:mycs, DS:myds, SS:myss
-----------------------------------------------------------------------

ANA 		PROC FAR
			PUSH DS
			XOR AX, AX
			PUSH AX
-----------------------------------------------------------------------

			MOV AX, myds
			MOV DS, AX
-----------------------------------------------------------------------
			//Bx yazmac�na 0 degeri at�l�r			
			MOV BX, 0
			//s� degeri 0 lan�r
			XOR SI, SI
			//Cx yazmac�na N degeri at�l�r
			MOV CX, n
			//Cx yazmac� 1 azalt�l�r
			DEC CX
			//Bx yazmac� ile 0 degeri kars�last�r�l�r
don:		CMP BX, 0
			//BX 0'a esit degilse o zaman son_if etiketine atla
			JNE son_if
			//S� ile Cx yazmac� kars�last�r�l�r yani indis d�ng� sayisini asip asmad�g�na bak�l�r
			CMP SI, CX
			//eger indisimiz d�ng� sayisini asm�ssa Son_if etiketine git
			JAE son_if
			//dizinin S� indisindeki deger al'ye atar�z
			MOV AL, dizi[SI]
			//dizinin S� indisindeki deger ile bir sonraki indisindeki deger kars�last�r�l�r.
			CMP AL, dizi[SI+1]
			//eger 1.deger 2.degerden kucuk esitse artt�r etiketine gider
			JLE artir
			//eger 1.deger 2.degerden buyuk ise Bx yazmac�na 1 degeri at�l�r
			MOV BX, 1
			//S� indisini 1 artt�r�r�z.
artir:		INC SI
			//don etiketine gider
			JMP don
			//Bx degeri 0 ile kars�last�r�r�z
son_if:		CMP BX, 0
			//eger 0'a esit degilse o zaman s�ras�zd�r yani Bx yazmac� 0 ise s�ral�d�r 0'a esit degilse 1 ise yani o zaman sirasizdir
			JNE sirasiz
			//eger sirali ise s'ye 1 degeri atan�r.
			MOV s, 1
			//son etiketine atlar�z
			JMP Son
			//sirasiz ise s'ye 0 degeri atan�r.
sirasiz:	MOV s, 0		
Son:		RETF
ANA			ENDP
mycs		ENDS
			END ANA

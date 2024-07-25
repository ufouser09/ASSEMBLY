
//dizinin sýralý mý sýrasýz oldugunu bulan kod 
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
			//Bx yazmacýna 0 degeri atýlýr			
			MOV BX, 0
			//sý degeri 0 lanýr
			XOR SI, SI
			//Cx yazmacýna N degeri atýlýr
			MOV CX, n
			//Cx yazmacý 1 azaltýlýr
			DEC CX
			//Bx yazmacý ile 0 degeri karsýlastýrýlýr
don:		CMP BX, 0
			//BX 0'a esit degilse o zaman son_if etiketine atla
			JNE son_if
			//Sý ile Cx yazmacý karsýlastýrýlýr yani indis döngü sayisini asip asmadýgýna bakýlýr
			CMP SI, CX
			//eger indisimiz döngü sayisini asmýssa Son_if etiketine git
			JAE son_if
			//dizinin Sý indisindeki deger al'ye atarýz
			MOV AL, dizi[SI]
			//dizinin Sý indisindeki deger ile bir sonraki indisindeki deger karsýlastýrýlýr.
			CMP AL, dizi[SI+1]
			//eger 1.deger 2.degerden kucuk esitse arttýr etiketine gider
			JLE artir
			//eger 1.deger 2.degerden buyuk ise Bx yazmacýna 1 degeri atýlýr
			MOV BX, 1
			//Sý indisini 1 arttýrýrýz.
artir:		INC SI
			//don etiketine gider
			JMP don
			//Bx degeri 0 ile karsýlastýrýrýz
son_if:		CMP BX, 0
			//eger 0'a esit degilse o zaman sýrasýzdýr yani Bx yazmacý 0 ise sýralýdýr 0'a esit degilse 1 ise yani o zaman sirasizdir
			JNE sirasiz
			//eger sirali ise s'ye 1 degeri atanýr.
			MOV s, 1
			//son etiketine atlarýz
			JMP Son
			//sirasiz ise s'ye 0 degeri atanýr.
sirasiz:	MOV s, 0		
Son:		RETF
ANA			ENDP
mycs		ENDS
			END ANA

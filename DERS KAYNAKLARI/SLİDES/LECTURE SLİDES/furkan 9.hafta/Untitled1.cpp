codesg		SEGMENT PARA 'kod'
			ORG 100h
			ASSUME CS:codesg, SS:codesg, DS:codesg
Basla:		JMP SICAKLIK
n			DW 5
dizi		DB 10, -19, 40, 17, -2
esik		DB -20
s			DB ?
SICAKLIK	PROC NEAR
--------------------------------------------------------------------------------
			//Sý'yý sýfýrlariz yani indisi 0'larýz
			XOR SI, SI
			//N sayisi yani dongu sayisini Cx'e atarýz
			MOV CX, n
			//esik deger Al'ye atýlýr
			MOV AL, esik
			//indis ile Cx yazmacýný yani döngü sayisini karsýlastýrýrýz
DON:		CMP SI, CX
			//indis degerimiz dongu sayisindan buyuk esit ise dogru yazmacýna git
			JAE dogru
			//dizinin Sý indisindeki deger ile esik degerimizi karsýlastýrýrýz
			CMP AL, dizi[SI]
			//esik degerimiz dizinin Sý ýndisli degerinden buyuk ise yanlýs etiketine git
			JG yanlis
			//Sý'yý yani indisi bir arttýrýrýz.
			INC SI
			//don etiketine gider
			JMP DON
			//yanlis etiketine atlanýr.
yanlis:		MOV S, 2
			//son etiketine gider
			JMP SON
			//s degiskenine 1 degeri atanýr
dogru:		MOV S, 1
SON:		RET
SICAKLIK	ENDP
codesg		ENDS
			END Basla

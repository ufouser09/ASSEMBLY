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
			//S�'y� s�f�rlariz yani indisi 0'lar�z
			XOR SI, SI
			//N sayisi yani dongu sayisini Cx'e atar�z
			MOV CX, n
			//esik deger Al'ye at�l�r
			MOV AL, esik
			//indis ile Cx yazmac�n� yani d�ng� sayisini kars�last�r�r�z
DON:		CMP SI, CX
			//indis degerimiz dongu sayisindan buyuk esit ise dogru yazmac�na git
			JAE dogru
			//dizinin S� indisindeki deger ile esik degerimizi kars�last�r�r�z
			CMP AL, dizi[SI]
			//esik degerimiz dizinin S� �ndisli degerinden buyuk ise yanl�s etiketine git
			JG yanlis
			//S�'y� yani indisi bir artt�r�r�z.
			INC SI
			//don etiketine gider
			JMP DON
			//yanlis etiketine atlan�r.
yanlis:		MOV S, 2
			//son etiketine gider
			JMP SON
			//s degiskenine 1 degeri atan�r
dogru:		MOV S, 1
SON:		RET
SICAKLIK	ENDP
codesg		ENDS
			END Basla

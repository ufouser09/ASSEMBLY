--------------------------------------------------------------------------------

deneme		SEGMENT PARA 'den'
			ORG 100h
			ASSUME CS:deneme, DS:deneme, SS:deneme
KAYNAK_BUL	PROC NEAR
--------------------------------------------------------------------------------
			//Bx'i sýfýrlarýz			
			XOR BX, BX
			//k_esik degeri al'ye atýyabiliriz.
			MOV AL, k_esik
			//b_esik degeri ah'e atarýz
			MOV AH, b_esik
			//Al dizinin Bx indisindeki degere atanýr
DON:		CMP dizi[BX], AL
			//dizinin Bx adresindeki deger al yazmacýndaki degerden kucuk ise sonraki etiketine atlanýr
			JB sonraki
			//dizinin Bx adresindeki deger al yazmacýndan buyuk ise buraya geliriz.
			//ah degerimiz ile dizinin BX indisindeki deger ile karsýlastýrýrýz
			CMP dizi[BX], AH
			//dizinin Bx indisindeki deger ah den buyuk ve esit ise buldum etiketine atlanýr
			JBE buldum
			//Bx indisini 1 arttýrýrýz
sonraki:	INC BX
			//don etiketine doner
			JMP DON
			//Bl yazmacý indeks degiskenine atanýr
buldum:		MOV indeks, BL
			RET
KAYNAK_BUL	ENDP
dizi		DB 14, 11, 45, 62, 11, 3, 8, 63, 81, 5, 12
k_esik		DB 15
b_esik		DB 50
indeks		DB ?
deneme		ENDS
			END KAYNAK_BUL

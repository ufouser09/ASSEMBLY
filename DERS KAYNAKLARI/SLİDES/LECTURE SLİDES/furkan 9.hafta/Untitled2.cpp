--------------------------------------------------------------------------------

deneme		SEGMENT PARA 'den'
			ORG 100h
			ASSUME CS:deneme, DS:deneme, SS:deneme
KAYNAK_BUL	PROC NEAR
--------------------------------------------------------------------------------
			//Bx'i s�f�rlar�z			
			XOR BX, BX
			//k_esik degeri al'ye at�yabiliriz.
			MOV AL, k_esik
			//b_esik degeri ah'e atar�z
			MOV AH, b_esik
			//Al dizinin Bx indisindeki degere atan�r
DON:		CMP dizi[BX], AL
			//dizinin Bx adresindeki deger al yazmac�ndaki degerden kucuk ise sonraki etiketine atlan�r
			JB sonraki
			//dizinin Bx adresindeki deger al yazmac�ndan buyuk ise buraya geliriz.
			//ah degerimiz ile dizinin BX indisindeki deger ile kars�last�r�r�z
			CMP dizi[BX], AH
			//dizinin Bx indisindeki deger ah den buyuk ve esit ise buldum etiketine atlan�r
			JBE buldum
			//Bx indisini 1 artt�r�r�z
sonraki:	INC BX
			//don etiketine doner
			JMP DON
			//Bl yazmac� indeks degiskenine atan�r
buldum:		MOV indeks, BL
			RET
KAYNAK_BUL	ENDP
dizi		DB 14, 11, 45, 62, 11, 3, 8, 63, 81, 5, 12
k_esik		DB 15
b_esik		DB 50
indeks		DB ?
deneme		ENDS
			END KAYNAK_BUL

   �,
   ; ikili arama (Binary Search)


   MYSEG    SEGMENT PARA 'CODE'
            ORG 100H
            ASSUME CS:MYSEG,SS:MYSEG, DS:MYSEG
   BILGI:   JMP MAIN
   DIZI     OW -21, -8, -3, -1, 0 , 4, 14, 21, 45, 67
   ELEMAN   DW 10
   SAYI    	DW 45
   ADRES    DW OFFFFH  ; Aranan say�n�n dizide olmad��� var say�larak
                       ; adres de�i�keni OFFFFH yap�lm��t�r.
   MAIN   PROC NEAR
            XOR SI, SI ; dizinin ilk eleman�n�n g�reli adresi
      MOV DI, ELEMAN 		; word tan�ml� dizinin son eleman�n� takip eden
               				; bellek g�z�n�n adresi 2 * eleman kadar uzakta
               				; olacakt�r. Dizi 0. adresten ba�lad��� i�in
            SHL DI, 1 	 	; son eleman da 2 * elaman -2 adresinde yer al�r.
       SUB DI, 2  			; dizinin son eleman�n�n g�reli adresi

       MOV AX, SAYI 		; aranacak olan say� Ax'e konur.
   CMP SI, DI 				; dizinin ilk eleman�n�n g�reli adresi, son eleman�n

            JG SON     		; g�reli adresinden b�y�k ise i�lem sonlan�r
            MOV BX, SI 		; dizinin ortas�na denk gelen adresin bulunmas� i�in
            ADD sx, DI 		; ba� ve son adres toplan�p 2'ye b�l�n�yor.



       SHR BX, 1
       AND BX, OFEH
       CMP AX, DIZI[BX]		; ortadaki eleman� ile aranan say�y� kar��la��r.
       JE BULDU   			; aranan say� bulundu
       JG SAGDA   			; AX b�y�k �se, say� dizinin ortas� ile sonu aras�nda
       MOV DI, BX 			; de�il ise ba�� ile ortas� aras�nda olacakt�r.
       SUB DI, 2  			; DI-BX yaparak dizinin ortas�n� sonu kabul et
                  			; kar��la�t�rmay� zaten orta eleman ile yapt���m�z 
                  			; i�in ondan �nceki elaman� kullanaca��z
       JMP KONT
SAGDA: MOV SI, BX 			; SI-BX yaparak dizinin ba��n� ortas� kabul et
       ADD SI, 2  			; kar��la�t�rmay� zaten orta eleman ile yapt���m�z 
                  			; i�in ondan sonraki elaman� kullanaca��z
       JMP KONT
BULDU: MOV ADRES, BX		; BX yazmac�nda saklanan adres de�erini belle�e koy
       MOV SI, DI 			; kont isimli �evrinden (while) d�zg�n �ikmak i�in 
                  			; ko�ul ifades�ni �evrinden ��kacak �ek�lde ayarla
       ADD SI, 2  			; word dizi oldu�u i�in inciisi 2 artt�r
       JMP KONT   			; �evrim ko�ulunu kontrol etmek �zere dallan
SON:   RET
MAIN   ENDP
MYSEG  ENDS
       END BILGI



   •,
   ; ikili arama (Binary Search)


   MYSEG    SEGMENT PARA 'CODE'
            ORG 100H
            ASSUME CS:MYSEG,SS:MYSEG, DS:MYSEG
   BILGI:   JMP MAIN
   DIZI     OW -21, -8, -3, -1, 0 , 4, 14, 21, 45, 67
   ELEMAN   DW 10
   SAYI    	DW 45
   ADRES    DW OFFFFH  ; Aranan sayýnýn dizide olmadýðý var sayýlarak
                       ; adres deðiþkeni OFFFFH yapýlmýþtýr.
   MAIN   PROC NEAR
            XOR SI, SI ; dizinin ilk elemanýnýn göreli adresi
      MOV DI, ELEMAN 		; word tanýmlý dizinin son elemanýný takip eden
               				; bellek gözünün adresi 2 * eleman kadar uzakta
               				; olacaktýr. Dizi 0. adresten baþladýðý için
            SHL DI, 1 	 	; son eleman da 2 * elaman -2 adresinde yer alýr.
       SUB DI, 2  			; dizinin son elemanýnýn göreli adresi

       MOV AX, SAYI 		; aranacak olan sayý Ax'e konur.
   CMP SI, DI 				; dizinin ilk elemanýnýn göreli adresi, son elemanýn

            JG SON     		; göreli adresinden büyük ise iþlem sonlanýr
            MOV BX, SI 		; dizinin ortasýna denk gelen adresin bulunmasý için
            ADD sx, DI 		; baþ ve son adres toplanýp 2'ye bölünüyor.



       SHR BX, 1
       AND BX, OFEH
       CMP AX, DIZI[BX]		; ortadaki elemaný ile aranan sayýyý karþýlaþýr.
       JE BULDU   			; aranan sayý bulundu
       JG SAGDA   			; AX büyük ýse, sayý dizinin ortasý ile sonu arasýnda
       MOV DI, BX 			; deðil ise baþý ile ortasý arasýnda olacaktýr.
       SUB DI, 2  			; DI-BX yaparak dizinin ortasýný sonu kabul et
                  			; karþýlaþtýrmayý zaten orta eleman ile yaptýðýmýz 
                  			; için ondan önceki elamaný kullanacaðýz
       JMP KONT
SAGDA: MOV SI, BX 			; SI-BX yaparak dizinin baþýný ortasý kabul et
       ADD SI, 2  			; karþýlaþtýrmayý zaten orta eleman ile yaptýðýmýz 
                  			; için ondan sonraki elamaný kullanacaðýz
       JMP KONT
BULDU: MOV ADRES, BX		; BX yazmacýnda saklanan adres deðerini belleðe koy
       MOV SI, DI 			; kont isimli çevrinden (while) düzgün çikmak için 
                  			; koþul ifadesýni çevrinden çýkacak þekýlde ayarla
       ADD SI, 2  			; word dizi olduðu için inciisi 2 arttýr
       JMP KONT   			; çevrim koþulunu kontrol etmek üzere dallan
SON:   RET
MAIN   ENDP
MYSEG  ENDS
       END BILGI



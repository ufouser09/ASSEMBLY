





           ; PROGRAM : �rnek 9-6.ASM
           ; INT 21H - fonksiyon 9H ile ekrana mesaj yazmay� sa�layan 
           ; COM yap�s�nda bir program


                   PAGE 	60,80
                   TITLE 	Ekrana mesaj yazma                                 �

           CDSEG SEGMENT PARA 'CODE'                                   
                   ORG 100H         ; COM program 100H den ba�lar       
                   ASSUME CS:CDSEG, SS:CDSEG, DS:CDSEG


           ; i�leminin ger�ekle�tir ildi�i yordam


           YAZDIR PROC NEAR
                   LEA DX, MESAJ     DX yazd�r�lacak mesaj�n ba �n� g�stermeli 
                   MOV AH, 09H      ; AH, fonksiyon numaras�n� ter
                   INT 21H          ; 21H numaral� kesmeyi �a��
                   RET              ; d�n                     �
           YAZDIR ENDP                                      �


           ; De�i�kenleri tan�mlad���m�z alan


           MESAJ   DB 'COM yapisinda bir program calis
           CDSEG ENDS
                   END YAZDIR       ; program�n ba�lanTv noktas�


                                                                                    I



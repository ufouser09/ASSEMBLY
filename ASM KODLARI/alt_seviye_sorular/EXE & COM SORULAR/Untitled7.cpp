





           ; PROGRAM : Örnek 9-6.ASM
           ; INT 21H - fonksiyon 9H ile ekrana mesaj yazmayý saðlayan 
           ; COM yapýsýnda bir program


                   PAGE 	60,80
                   TITLE 	Ekrana mesaj yazma                                 •

           CDSEG SEGMENT PARA 'CODE'                                   
                   ORG 100H         ; COM program 100H den baþlar       
                   ASSUME CS:CDSEG, SS:CDSEG, DS:CDSEG


           ; iþleminin gerçekleþtir ildiði yordam


           YAZDIR PROC NEAR
                   LEA DX, MESAJ     DX yazdýrýlacak mesajýn ba ýný göstermeli 
                   MOV AH, 09H      ; AH, fonksiyon numarasýný ter
                   INT 21H          ; 21H numaralý kesmeyi çaðý
                   RET              ; dön                     ý
           YAZDIR ENDP                                      •


           ; Deðiþkenleri tanýmladýðýmýz alan


           MESAJ   DB 'COM yapisinda bir program calis
           CDSEG ENDS
                   END YAZDIR       ; programýn baþlanTv noktasý


                                                                                    I



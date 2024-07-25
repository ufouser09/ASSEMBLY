 COM tipi programda veri kesiminin kod kesiminden sonra yerleþtirildiði 
; model kullanýlmýþtýr.

MYS      SEGMENT PARA 'KOD'
         ORG 100H
         ASSUME CS:MYS, JDS:LMYS, SS:MYS
KAYNAK_BUL PROC NEAR
         XOR BX, BX Q9         ; KUYRUK dizisinin indisi olarak
                               ; kullanýlacak BX yazmacý O'lanýr. 
         MOV AL, K_ESIK        ; K_ESIK deðeri AL yazmacýna konur.
         MOV AH, B_ESIK         ; B_ESIK deðeri AH yazmacýna konur.
DON:     CMP KUYRUK[BX], AL     ; KUYRUK dizisinin BX indisli elemaný
                                 ;ile AL karþýlaþtýrýlýr.
         JB SONRAKI              ;KUYRUK[BX], AL'den küçükse SONRAKI
                                 ;etiketine atlanýr.
         CMP KUYRUK[BX], AH      ;KUYRUK[BX], AL'den büyük eþitse
                                 ;KUYRUK dizisinin BX indisli elemaný 
                                 ;ile AH karþýlaþtýrýlýr.
         :BE BULUNDU             ;KUYRUK[BX], AH'den küçük eþitse
                                 ;BULUNDU etiketine atlanýr.
SONRAKI:C!' INC BX               ;KUYRUK[BX], AH'den büyükse BX
                                 ;yazmacýnýn deðeri 1 arttýrýlýr.
   4.þ>-) JMP DON                ;çevrim koþuluna gitmek için DON
                                 ;etiketine atlanýr.
BULUNDU: MOV INDIS, BL           ;Kuyruða sonradan giren kiþinin sýrasý
                                 ;BL, INDIS deðiþkeni içerisine atýlýr.
SON:     RET
KAYNAK_BULENDP
KUYRUK   DB 14, 11, 54, 62, 11, 3, 8, 63, 81, 5, 16
KESIK    DB 15
B_ESIK   DB 50
INDIS    DB ?
MYS      ENDS
         END KAYNAK_BUL



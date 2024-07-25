 COM tipi programda veri kesiminin kod kesiminden sonra yerle�tirildi�i 
; model kullan�lm��t�r.

MYS      SEGMENT PARA 'KOD'
         ORG 100H
         ASSUME CS:MYS, JDS:LMYS, SS:MYS
KAYNAK_BUL PROC NEAR
         XOR BX, BX Q9         ; KUYRUK dizisinin indisi olarak
                               ; kullan�lacak BX yazmac� O'lan�r. 
         MOV AL, K_ESIK        ; K_ESIK de�eri AL yazmac�na konur.
         MOV AH, B_ESIK         ; B_ESIK de�eri AH yazmac�na konur.
DON:     CMP KUYRUK[BX], AL     ; KUYRUK dizisinin BX indisli eleman�
                                 ;ile AL kar��la�t�r�l�r.
         JB SONRAKI              ;KUYRUK[BX], AL'den k���kse SONRAKI
                                 ;etiketine atlan�r.
         CMP KUYRUK[BX], AH      ;KUYRUK[BX], AL'den b�y�k e�itse
                                 ;KUYRUK dizisinin BX indisli eleman� 
                                 ;ile AH kar��la�t�r�l�r.
         :BE BULUNDU             ;KUYRUK[BX], AH'den k���k e�itse
                                 ;BULUNDU etiketine atlan�r.
SONRAKI:C!' INC BX               ;KUYRUK[BX], AH'den b�y�kse BX
                                 ;yazmac�n�n de�eri 1 artt�r�l�r.
   4.�>-) JMP DON                ;�evrim ko�uluna gitmek i�in DON
                                 ;etiketine atlan�r.
BULUNDU: MOV INDIS, BL           ;Kuyru�a sonradan giren ki�inin s�ras�
                                 ;BL, INDIS de�i�keni i�erisine at�l�r.
SON:     RET
KAYNAK_BULENDP
KUYRUK   DB 14, 11, 54, 62, 11, 3, 8, 63, 81, 5, 16
KESIK    DB 15
B_ESIK   DB 50
INDIS    DB ?
MYS      ENDS
         END KAYNAK_BUL



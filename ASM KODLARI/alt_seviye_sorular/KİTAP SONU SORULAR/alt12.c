

; MAIN yordam i�erisinde SAY harici yordam� �a��r�lm��t�r.

        EXTREN SAY:FAR
MN'SS   SEGMENT PARA STACK 'S'
        DW 20 DUP(?)
MYSS    ENDS

MYDS    SEGMENT PARA 'DATA'
DIZI    DW 12, 12, 12, 12, 12, 12, 13, 14, 15, 16, 17
N       DW 11
ARANAN  DB 12



                                                             




SONUC    DW ? 
MYDS     ENDS

MYCS     SEGMENT PARA PUBLIC 'CODE' 
         ASSUME CS:MYCS, DS:MYDS, SS:MYSS 
MAIN     PROC FAR
         PUSH DS
         XOR AX, AX 
         PUSH AX
         MOV AX, MYDS                              ��
         MOV DS, AX 
         XOR AX, AX              ;AH yazmac�n�n O'lanmas�C)) i�in AX 
                                 ;yazmac� s�f�rlan�r. ��nk� XOR AX, AX 
                                 ;kodunun performans� XOR AH, AH komutu 
                                 ;performans�ndan ��..-,ha iyidir.
         MOV AL, ARANAN          ;ARANAN de�i�ken�nin de�eri AL
                                 ;yazmac�na konu)ur.
         PUSH AX                 ;AX y���na
         LEA AX, DIZI            ;DIZI'nin adresi AX yazmac�na al�n�r.
         PUSH AX                 ;AX �zerinden DIZI'nin adresi y���na
                                 ;at�l�r.
         PUSH N                  ;DIZI'nin eleman say�s� (N) y���na
                                 ;at�l�r.
         CALL SAY                ;SAY yol-dam� �a��r�l�r.
         MOV SONUC, AX           ;SAY yordam�ndan AX �zerinden
                                 ;d�nd�r�len de�er SONUC de�i�kenine 
                                 ;yerle�tirilir.
         RETF 
MAIN     ENDP 
MYCS     ENDS 
         END MAIN



; SAY harici yordam� i�erisinde Sayma i�lemi ger�ekle�tirilmektedir.

             PUBLIC SAY
MYCS         SEGMENT PARA PUBLIC 'CODE' 
             ASSUME CS:MYCS
SAY          PROC FAR 
             PUSH CX                           ; Harici   yordamda kullan�lan yazma�lar
             PUSH DI                           ; CX,  DI ve BP y���na at�l�r.
             PUSH BP 
             MOV BP, SP                        ; stack Pointer ile Base Pointer'�n
                                               ; ayn�  yeri  g�stermesi    sa�lan�r.
             MOV CX,   [BP+10]                 ; Y���na en son at�lan de�er olan
                                               ; dizinin eleman say�s�      y���ndan cx
                                               ; yazmac�na al�n�r.
             MOV UI,   [BP+12]                 ; DIZI'nin adresi     DI yazmac�na al�n�r.
             MOV BX,   [BP+14]                 ; Aranan say�    BX yazmac�na al�n�r.
             X0i-t AX, AX                      ; AX de�eri   s�f�rlan�r.
L�:          CMP BX,   [DI]                    ; BX ile DI yazmac�n�n g�sterdi�i
          �                                    ; yerdeki   word de�er kar��la�t�r�l�r.
             JNE ATLA                          ; BX, DI adresindeki      bir word de�ere
                                               ; e�it de�ilse ATLA etiketine gidilir.
             INC AX                            ; BX, DI adresindeki      bir word de�ere
                                               ; e�itse AX yazmac�n�n de�eri 1 artar.
ATLA:        ADD DI,   2                       ; DIZI word tan�ml�     oldu�u i�in DI
                                               ; yazmac�   2 artt�r�l�r.
             LOOP Ll                           ; �evrim i�lemleri CX kez yap�l�r.
             POP BP                            ; Ba�lang��ta y���na at�lan yazma�lar 
             POP DI                            ; at�ld�klar� s�ralar�n tersiyle
             POP CX                            ; y���ndan al�n�rlar.
             RETF 6                            ; MAIN yordam taraf�ndan y���na at�lan
                                               ; aranan say�, dizinin adresi ve dizinin 
                                               ; eleman say�s� de�erlerini y���ndan

		say endp								;kald�rmak i�in retf 6 komutu kullan�l�r
		mycs ends
			end	

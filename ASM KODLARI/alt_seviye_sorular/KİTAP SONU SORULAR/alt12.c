

; MAIN yordam içerisinde SAY harici yordamý çaðýrýlmýþtýr.

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
         MOV AX, MYDS                              ••
         MOV DS, AX 
         XOR AX, AX              ;AH yazmacýnýn O'lanmasýC)) için AX 
                                 ;yazmacý sýfýrlanýr. Çünkü XOR AX, AX 
                                 ;kodunun performansý XOR AH, AH komutu 
                                 ;performansýndan •±..-,ha iyidir.
         MOV AL, ARANAN          ;ARANAN deðiþkenýnin deðeri AL
                                 ;yazmacýna konu)ur.
         PUSH AX                 ;AX yýðýna
         LEA AX, DIZI            ;DIZI'nin adresi AX yazmacýna alýnýr.
         PUSH AX                 ;AX üzerinden DIZI'nin adresi yýðýna
                                 ;atýlýr.
         PUSH N                  ;DIZI'nin eleman sayýsý (N) yýðýna
                                 ;atýlýr.
         CALL SAY                ;SAY yol-damý çaðýrýlýr.
         MOV SONUC, AX           ;SAY yordamýndan AX üzerinden
                                 ;döndürülen deðer SONUC deðiþkenine 
                                 ;yerleþtirilir.
         RETF 
MAIN     ENDP 
MYCS     ENDS 
         END MAIN



; SAY harici yordamý içerisinde Sayma iþlemi gerçekleþtirilmektedir.

             PUBLIC SAY
MYCS         SEGMENT PARA PUBLIC 'CODE' 
             ASSUME CS:MYCS
SAY          PROC FAR 
             PUSH CX                           ; Harici   yordamda kullanýlan yazmaçlar
             PUSH DI                           ; CX,  DI ve BP yýðýna atýlýr.
             PUSH BP 
             MOV BP, SP                        ; stack Pointer ile Base Pointer'ýn
                                               ; ayný  yeri  göstermesi    saðlanýr.
             MOV CX,   [BP+10]                 ; Yýðýna en son atýlan deðer olan
                                               ; dizinin eleman sayýsý      yýðýndan cx
                                               ; yazmacýna alýnýr.
             MOV UI,   [BP+12]                 ; DIZI'nin adresi     DI yazmacýna alýnýr.
             MOV BX,   [BP+14]                 ; Aranan sayý    BX yazmacýna alýnýr.
             X0i-t AX, AX                      ; AX deðeri   sýfýrlanýr.
Lý:          CMP BX,   [DI]                    ; BX ile DI yazmacýnýn gösterdiði
          Ð                                    ; yerdeki   word deðer karþýlaþtýrýlýr.
             JNE ATLA                          ; BX, DI adresindeki      bir word deðere
                                               ; eþit deðilse ATLA etiketine gidilir.
             INC AX                            ; BX, DI adresindeki      bir word deðere
                                               ; eþitse AX yazmacýnýn deðeri 1 artar.
ATLA:        ADD DI,   2                       ; DIZI word tanýmlý     olduðu için DI
                                               ; yazmacý   2 arttýrýlýr.
             LOOP Ll                           ; çevrim iþlemleri CX kez yapýlýr.
             POP BP                            ; Baþlangýçta yýðýna atýlan yazmaçlar 
             POP DI                            ; atýldýklarý sýralarýn tersiyle
             POP CX                            ; yýðýndan alýnýrlar.
             RETF 6                            ; MAIN yordam tarafýndan yýðýna atýlan
                                               ; aranan sayý, dizinin adresi ve dizinin 
                                               ; eleman sayýsý deðerlerini yýðýndan

		say endp								;kaldýrmak için retf 6 komutu kullanýlýr
		mycs ends
			end	

------------------------------------------------------------------------------------
      
	  TITLE yard�mc� yordam �a��rma 
      EXTRN TOPLAMA:FAR
STSEG SEGMENT PARA STACK 'STACK' 
      DW 12 DUP(0)
STSEG ENDS
DTSEG SEGMENT PARA 'DATA'
------------------------------------------------------------------------------------

; kullan�lacak de�i�kenler tan�mlan�r.
------------------------------------------------------------------------------------

SAYI1 DB 12H 
SAYI2 DB 78H 
SONUC DW OH 
DTSEG ENDS
CDSEG SEGMENT PARA 'CODE'
      ASSUME CS:CDSEG, SS:STSEG, DS:DTSEG
BASLA PROC FAR
------------------------------------------------------------------------------------

; D�n�� i�in gerekli olan de�erler y���nda saklan�yor
------------------------------------------------------------------------------------

      PUSH DS 
      XOR AX, AX
      PUSH AX
------------------------------------------------------------------------------------

; DATASG ismiyle tan�ml� kesim alan�na eri�ebilmek i�in gerekli tan�mlar
------------------------------------------------------------------------------------

      MOV AX, DTSEG 
      MOV DS, AX
------------------------------------------------------------------------------------

; i�lem blo�u ba�l�yor
------------------------------------------------------------------------------------

      MOV BH, SAYI1 ; De�erler BH ve BL yazma�lar� �zerinden
      MOV BL, SAYI2 ; �ag�r�lacak olan yard�mc� yordama aktar�l�r 
      CALL TOPLAMA  ; yordam ca��r�l�r
      MOV SONUC, AX ; toplama i�leminin sonucunu AX yazmac�nda
      RET
BASLA ENDP 
CDSEG ENDS 
      END BASLA    ; program�n ba�lang�� noktas�
------------------------------------------------------------------------------------



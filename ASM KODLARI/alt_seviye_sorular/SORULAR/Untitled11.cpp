; PROGRAM : Örnek 11-2.ASM
; Örnek 11-2-1.ASM ile veri kesimleri birleþtirilmiþtir.

      PAGE 60,80
      TITLE Veri kesimleri birleþik
---------------------------------------------------------------------------------------------------------------------------------------

; ALTPRRG ve I_WORD Örnek 11-2-1.ASM içinde tanýmlýdýr'.
; B_WORD ise Örnek 11-2-1.ASM içindeki ALTPRG isimli yordam eriþecektir.
---------------------------------------------------------------------------------------------------------------------------------------

      EXTRN ALTPRG:FAR, I_WORD:WORD 
      PUBLIC B_WORD
STSEG SEGMENT PARA STACK 'STACK' 
      DW 12 DUP(0)
STSEG ENDS
•---------------------------------------------------------------------------------------------------------------------------------------

; Veri kesimi PUBLIC tanýmlanmýþtýr. Ayrýca BYTE tanýmý ile tüm alanýn 
; etkin kullanýlmasý amaçlanmýþtýr.
•---------------------------------------------------------------------------------------------------------------------------------------

DTSEG SEGMENT BYTE PUBLIC 'DATA' 
I_BYTE1 DB ?
I_BYTE2 DB ? 
B_WORD DW OABCDH
DTSEG ENDS
CDSEG SEGMENT PARA 'CODE'
      ASSUME CS:CDSEG,SS:STSE:3 DS:DTSEG 
BASLA PROC FAR
•---------------------------------------------------------------------------------------------------------------------------------------

; Dönüþ için gerekli olan deðerler yýðýnda saklanýyor
---------------------------------------------------------------------------------------------------------------------------------------

      PUSH DS 
      XOR AX, AX 
      PUSH AX
---------------------------------------------------------------------------------------------------------------------------------------

? DTSEG ismiyle tanýmlý veri kesimine eriþebilmek için gerekli tanýmlar
---------------------------------------------------------------------------------------------------------------------------------------

          MOV AX, DTSEG 
          MOV DS, AX
---------------------------------------------------------------------------------------------------------------------------------------

• iþlem bloðu baþlýyor
---------------------------------------------------------------------------------------------------------------------------------------

          MOV /2,X, I_WORD     ; örnek 11-2-1.A5m içindeki deðeri al
          MOV I_BYTE1, AL      ; Parçalayarak kendi içinde tanýmlý deðiþkenlere 
          MOV I_BYTE2, AH      ; yerleþtir
          CALL ALTPRG          ; harici yordamý çaðýr
          RET                  ; Dös'a dön
BASLA     ENDP
CDSEG     ENDS
          END BASLA          ; programýn baþlangýç noktasý

---------------------------------------------------------------------------------------------------------------------------------------




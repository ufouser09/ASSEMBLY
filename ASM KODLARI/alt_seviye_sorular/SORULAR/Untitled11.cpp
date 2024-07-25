; PROGRAM : �rnek 11-2.ASM
; �rnek 11-2-1.ASM ile veri kesimleri birle�tirilmi�tir.

      PAGE 60,80
      TITLE Veri kesimleri birle�ik
---------------------------------------------------------------------------------------------------------------------------------------

; ALTPRRG ve I_WORD �rnek 11-2-1.ASM i�inde tan�ml�d�r'.
; B_WORD ise �rnek 11-2-1.ASM i�indeki ALTPRG isimli yordam eri�ecektir.
---------------------------------------------------------------------------------------------------------------------------------------

      EXTRN ALTPRG:FAR, I_WORD:WORD 
      PUBLIC B_WORD
STSEG SEGMENT PARA STACK 'STACK' 
      DW 12 DUP(0)
STSEG ENDS
�---------------------------------------------------------------------------------------------------------------------------------------

; Veri kesimi PUBLIC tan�mlanm��t�r. Ayr�ca BYTE tan�m� ile t�m alan�n 
; etkin kullan�lmas� ama�lanm��t�r.
�---------------------------------------------------------------------------------------------------------------------------------------

DTSEG SEGMENT BYTE PUBLIC 'DATA' 
I_BYTE1 DB ?
I_BYTE2 DB ? 
B_WORD DW OABCDH
DTSEG ENDS
CDSEG SEGMENT PARA 'CODE'
      ASSUME CS:CDSEG,SS:STSE:3 DS:DTSEG 
BASLA PROC FAR
�---------------------------------------------------------------------------------------------------------------------------------------

; D�n�� i�in gerekli olan de�erler y���nda saklan�yor
---------------------------------------------------------------------------------------------------------------------------------------

      PUSH DS 
      XOR AX, AX 
      PUSH AX
---------------------------------------------------------------------------------------------------------------------------------------

? DTSEG ismiyle tan�ml� veri kesimine eri�ebilmek i�in gerekli tan�mlar
---------------------------------------------------------------------------------------------------------------------------------------

          MOV AX, DTSEG 
          MOV DS, AX
---------------------------------------------------------------------------------------------------------------------------------------

� i�lem blo�u ba�l�yor
---------------------------------------------------------------------------------------------------------------------------------------

          MOV /2,X, I_WORD     ; �rnek 11-2-1.A5m i�indeki de�eri al
          MOV I_BYTE1, AL      ; Par�alayarak kendi i�inde tan�ml� de�i�kenlere 
          MOV I_BYTE2, AH      ; yerle�tir
          CALL ALTPRG          ; harici yordam� �a��r
          RET                  ; D�s'a d�n
BASLA     ENDP
CDSEG     ENDS
          END BASLA          ; program�n ba�lang�� noktas�

---------------------------------------------------------------------------------------------------------------------------------------




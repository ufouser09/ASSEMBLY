; PROGRAM : �rnek 11-2-1.ASM
; �rnek 11-2.ASM ile veri kesimleri birle�tirili�tir.

        PAGE 60,80
        TITLE Veri kesimleri birle�ik

; ALTPRRG ve I_WORD �rnek 11-2.ASM taraf�ndan kullan�lacakt�r. 
; B_WORD, �rnek 11-2.ASM i�inde tan�ml�d�r

        PUBLIC ALTPRG, I_WORD 
        EXTRN B_WORD: WORD

; veri kesimi PUBLIC tan�mlanm��t�r. Ayr�ca BYTE tan�m� ile t�m alan�n 
; etkin kullan�lmas� ama�lanm��t�r.
�
DTSEG SEGMENT BYTE PUBLIC 'DATA'
B_BYTE1 DB ? 
B_BYTE2 DB ? 
I_WORD DW 01234H
DTSEG ENDS
CODESG SEGMENT PARA 'CODE'
        ASSUME CS:CODESG, DS:DTSLG
ALTPRG PROC FAR
� 
; i�lem blo�u ba�l�yor

        MOV AX, B_WORD  ; �rnek 11-2.ASM i�indeki B_WORD de�erini al
        MOV B_BYTE1, AL ; Kendi veri kesiminde tan�ml� de�i�kenlere koy 
        MOV B_BYTE2, \H
        RET       , 'V ; �a��ran noktaya geri d�n
ALTPRG ENDP      '�D/
CODESG ENDS      U'
        END :Ny
               ���



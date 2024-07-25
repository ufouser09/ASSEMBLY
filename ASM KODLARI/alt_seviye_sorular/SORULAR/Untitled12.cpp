; PROGRAM : Örnek 11-2-1.ASM
; Örnek 11-2.ASM ile veri kesimleri birleþtiriliþtir.

        PAGE 60,80
        TITLE Veri kesimleri birleþik

; ALTPRRG ve I_WORD örnek 11-2.ASM tarafýndan kullanýlacaktýr. 
; B_WORD, örnek 11-2.ASM içinde tanýmlýdýr

        PUBLIC ALTPRG, I_WORD 
        EXTRN B_WORD: WORD

; veri kesimi PUBLIC tanýmlanmýþtýr. Ayrýca BYTE tanýmý ile tüm alanýn 
; etkin kullanýlmasý amaçlanmýþtýr.
•
DTSEG SEGMENT BYTE PUBLIC 'DATA'
B_BYTE1 DB ? 
B_BYTE2 DB ? 
I_WORD DW 01234H
DTSEG ENDS
CODESG SEGMENT PARA 'CODE'
        ASSUME CS:CODESG, DS:DTSLG
ALTPRG PROC FAR
• 
; iþlem bloðu baþlýyor

        MOV AX, B_WORD  ; Örnek 11-2.ASM içindeki B_WORD deðerini al
        MOV B_BYTE1, AL ; Kendi veri kesiminde tanýmlý deðiþkenlere koy 
        MOV B_BYTE2, \H
        RET       , 'V ; çaðýran noktaya geri dön
ALTPRG ENDP      '›D/
CODESG ENDS      U'
        END :Ny
               ••¦



STEK SEGMENT PARA STACK 'STK'
        DW 30 DUP(?)
STEK ENDS

DSG  SEGMENT PARA 'DTS'
a DW 0F000H
b DW 0AF01H
c DD 0
DSG ENDS

CSG  SEGMENT PARA 'CODE'
        ASSUME CS:CSG, DS:DSG, SS:STEK
TOPLA PROC FAR
; AX ve BX 16 bit deðerler
; (AX:BX) <-- AX+BX
        ADD BX, AX
        MOV AX, 0
        ADC AX, 0
        RETF
TOPLA ENDP


BASLA   PROC FAR
; c <-- a+b
        PUSH DS
        XOR AX,AX
        PUSH AX

        MOV AX, DSG
        MOV DS, AX

        MOV AX, a
        MOV BX, b
        CALL FAR PTR TOPLA
        LEA SI, c
        MOV [SI], BX
        MOV [SI+2], AX


        RETF
BASLA   ENDP
CSG  ENDS
        END BASLA


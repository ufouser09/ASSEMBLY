PUBLIC TOPLA

CSG  SEGMENT PARA 'CODE'
        ASSUME CS:CSG
TOPLA PROC FAR
; AX ve BX 16 bit deðerler
; (AX:BX) <-- AX+BX
        ADD BX, AX
        MOV AX, 0
        ADC AX, 0
        RETF
TOPLA ENDP

CSG  ENDS
        END


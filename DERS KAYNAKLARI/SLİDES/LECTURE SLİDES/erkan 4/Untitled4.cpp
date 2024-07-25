-----------------------------------------------------------------------

        PAGE 60,80
        TITLE ornek____
-----------------------------------------------------------------------
        
CODESG  SEGMENT PARA 'CODE'
        ORG 100H
        ASSUME CS:CODESG, SS:CODESG, DS:CODESG, ES:CODESG
-----------------------------------------------------------------------

BILGI: 
JMP BASLA
VAR DB 0
BASLA   PROC NEAR
-----------------------------------------------------------------------
	//Ah yazmacýna 1 degeri atanýr		
	MOV AH, 1
	
	INT 21H
	MOV VAR, AL
	INC AL
	MOV DL, AL
	MOV AH, 2
	INT 21H

        RET
BASLA   ENDP

CODESG  ENDS
        END BILGI


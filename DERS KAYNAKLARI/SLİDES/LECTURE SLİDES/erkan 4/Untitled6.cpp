CODESG  SEGMENT PARA 'CODE'
        ORG 100H
        ASSUME CS:CODESG, SS:CODESG, DS:CODESG, ES:CODESG
BILGI:  JMP BASLA
MESAJ DB 3 DUP (0), '$'
VAR DB 54H

BASLA   PROC NEAR
	XOR AH, AH
	MOV AL, VAR
	MOV BL, 10
	DIV BL ; AL <- AX/BL, AH <- AX%BL: 1'ler
	ADD AH, '0'
	MOV MESAJ[2], AH
	XOR AH, AH
	DIV BL ; AL: 100'ler, AH: 10'lar
	ADD AH, '0'
	MOV MESAJ[1], AH
	ADD AL, '0'
	MOV MESAJ[0], AL
	LEA DX, MESAJ
	MOV AH, 09H
	INT 21H
	
        RET
BASLA   ENDP
CODESG  ENDS
        END BILGI


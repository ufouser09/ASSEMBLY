        PAGE 60,80
        TITLE ornek____
        
CODESG  SEGMENT PARA 'CODE'
        ORG 100H
        ASSUME CS:CODESG, SS:CODESG, DS:CODESG, ES:CODESG
BILGI:  JMP BASLA
NOTLAR	DB 100

BASLA   PROC NEAR


	
        RET
BASLA   ENDP
CODESG  ENDS
        END BILGI
        
        
//com tipi kod iskeleti        
        


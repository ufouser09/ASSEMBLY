•,
; Büyük Tansiyon > Küçük Tansiyon olacaktýr.
; BYK : Büyük tansiyon deðerleri 
; KCK : Küçük tansiyon deðerleri 
; GUN : Farkýn en fazla olduðu gün


MYSTACK     SEGMENT PARA STACK 'STACK'
            DW 32 DUP (?)
MYSTACK     ENDS


MYDATA      SEGMENT PARA 'DATA'
BYK         DB 12,13,14,15,15,16,13,12,10,9 
KCK         DB 5 , 6, 7, 8, 9, 3, 2, 5, 5,6 
GUN         DW 0
ELEMAN      DW 10
MYDATA      ENDS


MYCODE ;<SEGMENT PARA 'CODE'
            ASSUME CS:MYCODE, SS:MYSTACK, DS:MYDATA 
MAINPROC FAR
     <r.)   PUSH DS
            XOR AX, AX 
    9)      PUSH AX

            MOV AX, MYDATA 
            MOV DS, AX
            MOV CX, ELEMAN      ; tekrar sayýsý CX yazmacýna konur 
            XOR SI, SI          ; dizi indisi olacak
            XOR BX, BX          ; tansiyon arasýndaki en büyük farký tutar
            MOV AL, BYK[SI]     ; Büyük tansiyon deðeri AL'de 
            SUB AL, KCK[SI]     ; Küçük tansiyon deðeri BL'de
            CMP AL, BL
            JB SONRAKI          ; sayýlar iþaretsiz

         MOV BL, AL     		; fark daha büyük ise BL'ye koy
         MOV GUN, SI    		; indisi GUN olarak sakla
SONRAKI: INC SI         		; dizi byte, artým tek olmalý
         LOOP LÝ
         RET
MAIN     ENDP
MYCODE   ENDS                                      
         END MAIN



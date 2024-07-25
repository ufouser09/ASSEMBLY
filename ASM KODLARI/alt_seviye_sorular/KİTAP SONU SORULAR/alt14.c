�,
; B�y�k Tansiyon > K���k Tansiyon olacakt�r.
; BYK : B�y�k tansiyon de�erleri 
; KCK : K���k tansiyon de�erleri 
; GUN : Fark�n en fazla oldu�u g�n


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
            MOV CX, ELEMAN      ; tekrar say�s� CX yazmac�na konur 
            XOR SI, SI          ; dizi indisi olacak
            XOR BX, BX          ; tansiyon aras�ndaki en b�y�k fark� tutar
            MOV AL, BYK[SI]     ; B�y�k tansiyon de�eri AL'de 
            SUB AL, KCK[SI]     ; K���k tansiyon de�eri BL'de
            CMP AL, BL
            JB SONRAKI          ; say�lar i�aretsiz

         MOV BL, AL     		; fark daha b�y�k ise BL'ye koy
         MOV GUN, SI    		; indisi GUN olarak sakla
SONRAKI: INC SI         		; dizi byte, art�m tek olmal�
         LOOP L�
         RET
MAIN     ENDP
MYCODE   ENDS                                      
         END MAIN



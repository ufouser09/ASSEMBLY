 Tablo 12-6: EXTRN/PUBLIC kullan�m� ile parame;.re aktar�m� - 
                    veri i�eren program
                TITLE EXTRN/PUBL�C ile parametre aktar�m�
2               PUBLIC Ack, Eleman
3    Stcksgl    SEGMENT PARA STACK 'STACK'
4               DW 12 DUP (?)
5    Stcksgl    ENDS
6    Datasgl    SEGMENT BYTE 'DATA'
7    Ack        DB 100 DUP (?)
8    Eleman     DW 100
9    Datasgl    ENDS
10   Codesgl    SEGMENT PARA 'CODE'
11              ASSUME CS:Codesg I, DS:Datasgl, SS:Stcksgl
12   Basla      PROC FAR
13              PUSH DS    ; D�n�� adreslerinin y���nda saklanmas�
14              XOR AX, AX
15              PUSH AX
16                         ; Di�er i�lemler
17              RET
18   Basla      ENDP
19   Codesgl    ENDS
20              END Basla  Pro ramrn ba lan r notas�



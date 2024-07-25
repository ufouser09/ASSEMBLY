 Tablo 12-6: EXTRN/PUBLIC kullanýmý ile parame;.re aktarýmý - 
                    veri içeren program
                TITLE EXTRN/PUBLÝC ile parametre aktarýmý
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
13              PUSH DS    ; Dönüþ adreslerinin yýðýnda saklanmasý
14              XOR AX, AX
15              PUSH AX
16                         ; Diðer iþlemler
17              RET
18   Basla      ENDP
19   Codesgl    ENDS
20              END Basla  Pro ramrn ba lan r notasý



                Tablo 12-1: Yýðýn üzerinden parametre aktarýmý - ILK.ASM
ILK.ASM
          1                                    TITLE yýðýn üzerinden parametre aktarýmý 
          2                                    EXTRN Altprg: FAR
          3           Stseg                    SEGMENT PARA STACK 'STACK'
          4                                    DW 16 DUP(?)
          5           Stseg                    ENDS
          6           Datasg                   SEGMENT BYTE 'DATA'
          7           Word 1                   DW 1234H
          8           Word2                    DW 5678H
          9           B_Word                   DW O
          10          Datasg                   ENDS
          11          Codesg                   SEGMENT PARA 'CODE'
          12                                   ASSUME CS:Codesg, DS Datasry, SS: Stseg
          13          Beste                    PROC FAR
          14                                   PUSH DS                  ; Dönüþ adreslednin yýðýnda saklanmasý
          15                                   XOR AX, AX
          16                                   PUSH AX
          17                                                            ; Diðer iþlemler
          18                                   PUSH Wordl               ; Parametreler yýðýna basýlýr
          19                                   PUSH Word2
          20                                   CALL Altprg
          21                                                            ; Diðer iþlemler
          22                                   RET
          23          Basla                    ENDP
          24          Codesg                   ENDS
          25                                   ENI> Basla               ; Pro 'rant, ba lan r noktasý•



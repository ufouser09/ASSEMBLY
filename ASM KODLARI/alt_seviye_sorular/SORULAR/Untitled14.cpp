        Tablo 12-3: Y���n �zerinden pararnetre aktar�m� - IKI.ASM

IKIASM
      1             TITLE y���n �zerinden parametreleri alan program 
      2             PUBLIC Altprg
      3   Codesg    SEGMENT PARA 'code
      4             ASSUME CS: Codesg
      5   Altprg    PROC FAR
      6             PUSH BP
      7             MOV BP, SP
      8             MOv AX: [BP+6]AX-Word2
      9             MOV BX, IBP+8]BX-Word1
      10                          ; Di�er i�lemler
      11
      12            POP BP
      13            RET 4         ; �a��r�ld��� noktaya geri d�n
      14  Altprg    ENDP
      15  Codesg    ENDS
      16  y         END
          �



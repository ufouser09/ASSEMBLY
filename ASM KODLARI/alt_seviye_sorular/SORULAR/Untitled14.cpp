        Tablo 12-3: Yýðýn üzerinden pararnetre aktarýmý - IKI.ASM

IKIASM
      1             TITLE yýðýn üzerinden parametreleri alan program 
      2             PUBLIC Altprg
      3   Codesg    SEGMENT PARA 'code
      4             ASSUME CS: Codesg
      5   Altprg    PROC FAR
      6             PUSH BP
      7             MOV BP, SP
      8             MOv AX: [BP+6]AX-Word2
      9             MOV BX, IBP+8]BX-Word1
      10                          ; Diðer iþlemler
      11
      12            POP BP
      13            RET 4         ; Çaðýrýldýðý noktaya geri dön
      14  Altprg    ENDP
      15  Codesg    ENDS
      16  y         END
          •



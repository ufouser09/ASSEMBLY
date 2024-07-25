------------------------------------------------------------------------------------
      
	  TITLE yardýmcý yordam çaðýrma 
      EXTRN TOPLAMA:FAR
STSEG SEGMENT PARA STACK 'STACK' 
      DW 12 DUP(0)
STSEG ENDS
DTSEG SEGMENT PARA 'DATA'
------------------------------------------------------------------------------------

; kullanýlacak deðiþkenler tanýmlanýr.
------------------------------------------------------------------------------------

SAYI1 DB 12H 
SAYI2 DB 78H 
SONUC DW OH 
DTSEG ENDS
CDSEG SEGMENT PARA 'CODE'
      ASSUME CS:CDSEG, SS:STSEG, DS:DTSEG
BASLA PROC FAR
------------------------------------------------------------------------------------

; Dönüþ için gerekli olan deðerler yýðýnda saklanýyor
------------------------------------------------------------------------------------

      PUSH DS 
      XOR AX, AX
      PUSH AX
------------------------------------------------------------------------------------

; DATASG ismiyle tanýmlý kesim alanýna eriþebilmek için gerekli tanýmlar
------------------------------------------------------------------------------------

      MOV AX, DTSEG 
      MOV DS, AX
------------------------------------------------------------------------------------

; iþlem bloðu baþlýyor
------------------------------------------------------------------------------------

      MOV BH, SAYI1 ; Deðerler BH ve BL yazmaçlarý üzerinden
      MOV BL, SAYI2 ; çagýrýlacak olan yardýmcý yordama aktarýlýr 
      CALL TOPLAMA  ; yordam caðýrýlýr
      MOV SONUC, AX ; toplama iþleminin sonucunu AX yazmacýnda
      RET
BASLA ENDP 
CDSEG ENDS 
      END BASLA    ; programýn baþlangýç noktasý
------------------------------------------------------------------------------------



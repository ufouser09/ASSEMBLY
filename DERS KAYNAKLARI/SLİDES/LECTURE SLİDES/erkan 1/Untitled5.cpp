-----------------------------------------------------------------------
STEK SEGMENT PARA STACK 'STK'
DW 30 DUP(?)
STEK ENDS
-----------------------------------------------------------------------

DSG  SEGMENT PARA 'DTS'        
N DW 500
ARRAY DB 1,2,8,20,25,495 DUP(81)
ODD DW 0
DSG ENDS
-----------------------------------------------------------------------

CSG  SEGMENT PARA 'CODE'
ASSUME CS:CSG, DS:DSG, SS:STEK
-----------------------------------------------------------------------

BASLA   PROC FAR
-----------------------------------------------------------------------

PUSH DS
XOR AX,AX
PUSH AX
-----------------------------------------------------------------------

MOV AX, DSG
MOV DS, AX
-----------------------------------------------------------------------

;kod buradan sonra 
-----------------------------------------------------------------------
		//arrayýn basýndaki deger Bx yazmacýna atarýz
		LEA BX, ARRAY; [BX] === ARRAY[0]
			
		//döngü sayisini Cx yazmacýna atarýz
		MOV CX, N

	L1: 
		//Bx deki Degeri 01H ile and leriz yani þey demek istiyoruz sonuc 1 çýkarsa tek 0 cýkarsa çýfttýr
		TEST BYTE PTR [BX], 01H	;MOV AL, [BX];TEST AL, 01H
	
		//sonuc 0 ise demek de sonucumuz çifttir.çift etiketine atlanýr 
		JZ CIFT
		//sonuc 0 degilse 1 dir o zaman tektir.ve odd'u bir arttýrýrýz.
		INC ODD
		
		CIFT:
		//indisi 1 arttýrýrýz.	
		INC BX
		//döngüyü döndürürüz.
		LOOP L1


-----------------------------------------------------------------------

		;kod buraya kadar
-----------------------------------------------------------------------

RETF
BASLA   ENDP
CSG  ENDS
END BASLA


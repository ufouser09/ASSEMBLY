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
		//array�n bas�ndaki deger Bx yazmac�na atar�z
		LEA BX, ARRAY; [BX] === ARRAY[0]
			
		//d�ng� sayisini Cx yazmac�na atar�z
		MOV CX, N

	L1: 
		//Bx deki Degeri 01H ile and leriz yani �ey demek istiyoruz sonuc 1 ��karsa tek 0 c�karsa ��ftt�r
		TEST BYTE PTR [BX], 01H	;MOV AL, [BX];TEST AL, 01H
	
		//sonuc 0 ise demek de sonucumuz �ifttir.�ift etiketine atlan�r 
		JZ CIFT
		//sonuc 0 degilse 1 dir o zaman tektir.ve odd'u bir artt�r�r�z.
		INC ODD
		
		CIFT:
		//indisi 1 artt�r�r�z.	
		INC BX
		//d�ng�y� d�nd�r�r�z.
		LOOP L1


-----------------------------------------------------------------------

		;kod buraya kadar
-----------------------------------------------------------------------

RETF
BASLA   ENDP
CSG  ENDS
END BASLA


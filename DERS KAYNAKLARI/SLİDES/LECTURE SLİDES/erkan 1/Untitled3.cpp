STEK SEGMENT PARA STACK 'STK'
DW 30 DUP(?)
STEK ENDS
-------------------------------------------------------------------

DSG  SEGMENT PARA 'DTS'        
N DW 500
ARRAY DB 1,2,8,20,25,495 DUP(81)
ODD DW 0
DSG ENDS
-------------------------------------------------------------------

CSG  SEGMENT PARA 'CODE'
ASSUME CS:CSG, DS:DSG, SS:STEK
-------------------------------------------------------------------

BASLA   PROC FAR
-------------------------------------------------------------------

PUSH DS
XOR AX,AX
PUSH AX
-------------------------------------------------------------------

MOV AX, DSG
MOV DS, AX
-------------------------------------------------------------------

;kod buradan sonra
;DIV ornegi
		//cx e dizinin boyutu at�l�r
		MOV CX, N		;CX e dizi boyutu at�l�r
		//array�n bas�ndaki deger Bx e at�l�r
		LEA BX, ARRAY 	;dizinin baslang�c�ndaki deger BX e at�l�r
		//dl ye 2 degeri at�l�r
		MOV DL, 2		;DL degerine 2 sayisi at�l�r

	L1: 
		//Bx deki deger al ye at�l�r
		MOV AL, [BX]  	;BX deki degeri AL ye atar�z
		//bolme yap�cag�m�z i�in ah 0 lan�r
		XOR AH, AH		;AH 0 lan�r.
		//bolum al kalan ah
		DIV DL			;AX->AX/DL->bolum:AL,kalan:AH
		//biz teklik ve �iftlik i�in ah a bak�yoruz
		CMP AH, 0		;kalan AH 0 ise sayimiz �ifttir
		//eger kalan 0 ise �ifttir ve l2 etiketine git demek
		JZ L2 			; cift deger
		//sonuc 0 degilse tektir odd degeri artt�r
		INC ODD			;kalan AH 0 degilse o zaman ODD a gecer ve ODD u bir artt�r�r
		L2:
		//indisi bir artt�r�r�z.				
		INC BX			;bir sonraki elemana ge�mek i�in BX i bir artt�r�r�z.

		LOOP L1


;kod buraya kadar

RETF
BASLA   ENDP
CSG  ENDS
END BASLA


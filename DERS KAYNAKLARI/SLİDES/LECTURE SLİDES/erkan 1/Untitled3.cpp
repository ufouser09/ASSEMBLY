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
		//cx e dizinin boyutu atýlýr
		MOV CX, N		;CX e dizi boyutu atýlýr
		//arrayýn basýndaki deger Bx e atýlýr
		LEA BX, ARRAY 	;dizinin baslangýcýndaki deger BX e atýlýr
		//dl ye 2 degeri atýlýr
		MOV DL, 2		;DL degerine 2 sayisi atýlýr

	L1: 
		//Bx deki deger al ye atýlýr
		MOV AL, [BX]  	;BX deki degeri AL ye atarýz
		//bolme yapýcagýmýz için ah 0 lanýr
		XOR AH, AH		;AH 0 lanýr.
		//bolum al kalan ah
		DIV DL			;AX->AX/DL->bolum:AL,kalan:AH
		//biz teklik ve çiftlik için ah a bakýyoruz
		CMP AH, 0		;kalan AH 0 ise sayimiz çifttir
		//eger kalan 0 ise çifttir ve l2 etiketine git demek
		JZ L2 			; cift deger
		//sonuc 0 degilse tektir odd degeri arttýr
		INC ODD			;kalan AH 0 degilse o zaman ODD a gecer ve ODD u bir arttýrýr
		L2:
		//indisi bir arttýrýrýz.				
		INC BX			;bir sonraki elemana geçmek için BX i bir arttýrýrýz.

		LOOP L1


;kod buraya kadar

RETF
BASLA   ENDP
CSG  ENDS
END BASLA


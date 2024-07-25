STEK SEGMENT PARA STACK 'STK'
DW 30 DUP(?)
STEK ENDS
-------------------------------------------------------------------

DSG  SEGMENT PARA 'DTS'        
		N DW 500
		ARRAY DW 1,2,8,20,825,495 DUP(81)
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


-------------------------------------------------------------------
 
;kod buradan sonra
		//array ýn basýndaki degeri Bx e atarýz.
		LEA BX, ARRAY	;dizinin bas indisini bx e atýyorsun
		//sý yý yani indisi 0 larýz
		XOR SI, SI		;sý larý 0 lýyorsun
		//Cx e döngü sayisini atarýz
		MOV CX, N 		;CX e dongu sayýsýný veriyorsun cunku loop dondukce cx bir azalýr
	L1:
		//Ax e Bx+Sý daki degeri atarýz
		MOV AX, [BX+SI]	;dizinin basýndaki eleman ax e atýlýr
		//Ax deki degeri 1 adým saga þhift ederiz
		SHR AX, 1		;dizi 1 birim saga kaydýrýlýr ve CF (carry flag)e en anlamsýz bit atýlýr eger cf 1 ise sayi tek 0 ise sayi çifttir
		//eger carry miz 1 ise tektir o zaman odd u bir arttýrýrýz.
		ADC ODD, 0       ;ODD degiskenimiz 0 ile toplanýr ama carry flag de hesaba katýlýr
		//Sý yý yani indisi word oldugu için 2 arttýrýrýz.
		ADD SI, 2       ;dizimiz word oldugu için 2 ser 2 ser artar 
		//dongüyü döndürürüz
		LOOP L1			;CX 0 lanana kadar loopumuz döner

;kod buraya kadar

RETF
BASLA   ENDP
CSG  ENDS
END BASLA


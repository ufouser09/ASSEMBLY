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
		//array �n bas�ndaki degeri Bx e atar�z.
		LEA BX, ARRAY	;dizinin bas indisini bx e at�yorsun
		//s� y� yani indisi 0 lar�z
		XOR SI, SI		;s� lar� 0 l�yorsun
		//Cx e d�ng� sayisini atar�z
		MOV CX, N 		;CX e dongu say�s�n� veriyorsun cunku loop dondukce cx bir azal�r
	L1:
		//Ax e Bx+S� daki degeri atar�z
		MOV AX, [BX+SI]	;dizinin bas�ndaki eleman ax e at�l�r
		//Ax deki degeri 1 ad�m saga �hift ederiz
		SHR AX, 1		;dizi 1 birim saga kayd�r�l�r ve CF (carry flag)e en anlams�z bit at�l�r eger cf 1 ise sayi tek 0 ise sayi �ifttir
		//eger carry miz 1 ise tektir o zaman odd u bir artt�r�r�z.
		ADC ODD, 0       ;ODD degiskenimiz 0 ile toplan�r ama carry flag de hesaba kat�l�r
		//S� y� yani indisi word oldugu i�in 2 artt�r�r�z.
		ADD SI, 2       ;dizimiz word oldugu i�in 2 ser 2 ser artar 
		//dong�y� d�nd�r�r�z
		LOOP L1			;CX 0 lanana kadar loopumuz d�ner

;kod buraya kadar

RETF
BASLA   ENDP
CSG  ENDS
END BASLA


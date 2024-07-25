-------------------------------------------------------------------
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


-------------------------------------------------------------------

;kod buradan sonra
-------------------------------------------------------------------
			//arrayýn baslangýcýndaki deger bx e atanýr
			LEA BX, ARRAY
			//Sý sýfýrlanýr
			XOR SI, SI
			//dongu sayisi Cx e atýlýr
			MOV CX, N 
		L1:
			//Bx+Sý daki deger al ye atýlýr
			MOV AL, [BX+SI]
			//al deki deger bir saga right edilir
			SHR AL, 1
			//eger carry flag de 1 varsa sayimiz tektir odd degerimiz 1 artar
			ADC ODD, 0       
			//indisi bir artýrýrýz
			INC SI       
			//dongi döner tekrar
			LOOP L1
-------------------------------------------------------------------

;kod buraya kadar
-------------------------------------------------------------------

RETF
BASLA   ENDP
CSG  ENDS
END BASLA


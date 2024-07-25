STEK SEGMENT PARA STACK 'STK'
DW 30 DUP(?)
STEK ENDS

DSG  SEGMENT PARA 'DTS'        
N DW 500
ARRAY DB 1,2,8,20,25,495 DUP(81)
ODD DW 0
DSG ENDS

CSG  SEGMENT PARA 'CODE'
ASSUME CS:CSG, DS:DSG, SS:STEK

BASLA   PROC FAR

PUSH DS
XOR AX,AX
PUSH AX

MOV AX, DSG
MOV DS, AX



;kod buradan sonra
			//dizinin basýndaki degeri bx e atar
			LEA BX, ARRAY;dizinin basýndaki deger BX e atýlýr
			//sý yý 0 lar
			XOR SI, SI;SI degerimiz 0 lanýr
			//döngü yazmacýna döngü sayisini atar
			MOV CX, N;CX e dongu sayýmýz atýlýr
		L1:
			//al degerine Bx+Sý daki degeri atar
			MOV AL, [BX+SI];AL degerine BX deki deger atýlýr
			//al degeri saga 1 adým þift edilir
			SHR AL, 1;AL degerimiz saga dogru shift edilir
			//eger carry miz 0 ise çift 1 ise tektir
			JNC CIFT;carry miz 0 ise cifttir ve cift etiketine gider
			//eger carry flag 0 degilse 1 dir.o zaman odd u yani tek sayilari tutan degiskeni bir arttýr
			INC ODD;buraya geldiyse demek ki carry miz çift degildir ODD u bir arttýrýrýz

		CIFT:
			//eger carry miz 0 ise o zaman cift etiketine atladýk 
			
			
			//indisi bir arttýrýrýz
			INC SI;SI yý bir arttýrýrýz;
			//Dongü tekrar döner
			LOOP L1;tekrar doner


;kod buraya kadar

RETF
BASLA   ENDP
CSG  ENDS
END BASLA


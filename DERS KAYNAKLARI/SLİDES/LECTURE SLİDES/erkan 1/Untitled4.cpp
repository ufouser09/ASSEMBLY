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
			//dizinin bas�ndaki degeri bx e atar
			LEA BX, ARRAY;dizinin bas�ndaki deger BX e at�l�r
			//s� y� 0 lar
			XOR SI, SI;SI degerimiz 0 lan�r
			//d�ng� yazmac�na d�ng� sayisini atar
			MOV CX, N;CX e dongu say�m�z at�l�r
		L1:
			//al degerine Bx+S� daki degeri atar
			MOV AL, [BX+SI];AL degerine BX deki deger at�l�r
			//al degeri saga 1 ad�m �ift edilir
			SHR AL, 1;AL degerimiz saga dogru shift edilir
			//eger carry miz 0 ise �ift 1 ise tektir
			JNC CIFT;carry miz 0 ise cifttir ve cift etiketine gider
			//eger carry flag 0 degilse 1 dir.o zaman odd u yani tek sayilari tutan degiskeni bir artt�r
			INC ODD;buraya geldiyse demek ki carry miz �ift degildir ODD u bir artt�r�r�z

		CIFT:
			//eger carry miz 0 ise o zaman cift etiketine atlad�k 
			
			
			//indisi bir artt�r�r�z
			INC SI;SI y� bir artt�r�r�z;
			//Dong� tekrar d�ner
			LOOP L1;tekrar doner


;kod buraya kadar

RETF
BASLA   ENDP
CSG  ENDS
END BASLA


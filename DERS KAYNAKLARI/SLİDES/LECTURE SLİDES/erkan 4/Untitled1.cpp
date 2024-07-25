-----------------------------------------------------------------------

        PAGE 60,80
        TITLE ornek____
-----------------------------------------------------------------------
        
CODESG  SEGMENT PARA 'CODE'
        ORG 100H
        ASSUME CS:CODESG, SS:CODESG, DS:CODESG, ES:CODESG
BILGI:  JMP BASLA
-----------------------------------------------------------------------

N DW 100
DIZI DW 3, -3, 10, -10, 20, 95 DUP (?)
BYK DW ?
-----------------------------------------------------------------------

BASLA   PROC NEAR
-----------------------------------------------------------------------
	//degisken sayisini Cx yazmac�na atar�z
	MOV CX, N
	//Cx yazmac�n� 1 azalt�r�z
	DEC CX
	//S�'y� 0 lar�z
	XOR SI, SI
	//dizinin S� indisindeki degeri Ax'e atar�z
	MOV AX, DIZI[SI]
	L1:
		//word oldugu i�in S�'y� 2'ser 2'ser artt�r�r�z
		ADD SI, 2
		//dizinin ilk degeri ile ikinci degerini kars�last�r�r�z
		CMP AX, DIZI[SI]
		//eger birinci degerimiz 2.degerimizden daha buyuk ise L2 yazmac�na gider
		JGE L2
			//eger 2.degerimiz 1.degerimizden buyuk ise o zaman da 2.degerimizi 1.degerine atar�z.ve buyuk varsayd�g�m�z deger art�k 2.degerimiz olur
			MOV AX, DIZI[SI]
		L2:
			//d�ng�m�z CX kadar d�ner
	LOOP L1
	//dizinin en buyuk sayisi BYK degiskenine atan�r
	MOV BYK, AX
	
        RET
BASLA   ENDP
CODESG  ENDS
        END BILGI


-----------------------------------------------------------------------
  
        PAGE 60,80
        TITLE ornek____
-----------------------------------------------------------------------
        
CODESG  SEGMENT PARA 'CODE'
        ORG 100H
        ASSUME CS:CODESG, SS:CODESG, DS:CODESG, ES:CODESG
BASLA   PROC NEAR
-----------------------------------------------------------------------
	//dongu sayisini Cx'e atar�z
	MOV CX, N
	//Cx'i 1 azalt�r�z
	DEC CX
	//S�'y� yani indisi 0 lar�z
	XOR SI, SI
	//dizinin ilk indisindeki degeri Ax'e atar�z 
	MOV AX, DIZI[SI]
	L1:
		//S� indisini word oldugu i�in 2'ser 2'ser artt�r�r�z.
		ADD SI, 2
		//1.ald�g�m�z deger ile ikinci degeri kars�last�r�r�z
		CMP AX, DIZI[SI]
		//eger 1.degerimiz 2.degerimizden buyuk esitse l2 etiketine git
		JGE L2
		//Eger 2.degerimiz 1.degerimizden buyuk ise de onu Ax e ata ve art�k buyuk varsayd�g�m�z deger o olsun
			MOV AX, DIZI[SI]
		L2:
	LOOP L1
	//en son en buyuk sayi BYK degiskenine atan�r
	MOV BYK, AX
	
        RET
BASLA   ENDP

N DW 100
DIZI DW 3, -3, 10, -10, 20, 95 DUP (?)
BYK DW ?

CODESG  ENDS
        END BASLA


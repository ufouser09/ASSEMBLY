		INCLUDE 091221.mac
cseg	SEGMENT PARA 'tum'
		ORG 100h
		ASSUME CS:cseg, DS:cseg, SS:cseg
		ANA		PROC FAR
--------------------------------------------------------------------------------
		//s� indisi 0 lan�r		
		XOR SI, SI
		//N degiskeni Cx yazmac�na atan�r
		MOV CX, n
		//dizinin S� indisindeki deger 1 saga SAR'lan�r bu da 2 ye bolme manas�na gelir
L1:		SAR dizi[SI], 1
		//S� degiskeni 1 artt�r�r�z
		INC SI
		//dong� d�ner
		LOOP L1
		ENKCK dizi, n
		MOV kck, AL
		RET
ANA		ENDP
dizi	DB 10, -2, 4, 5, 10, 3, 5, 17
n		DW 8
kck		DB ?
cseg	ENDS
		END ANA

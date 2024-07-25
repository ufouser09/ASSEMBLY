dizi1 ýn elemanlarýný 0 lamak istiyoruz

veri:dizi 1 DB 25 DUP(?)
		n DW 25
		
		LEA DI,dizi1
		mov CX,n
		CLD
		XOR AL,AL;<---Al<----0
		rep stosb	

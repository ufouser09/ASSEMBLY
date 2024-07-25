dizi1'i 1-25'e kadar degerler ile ilklendirmek istiyoruz

veri:Dizi 1 DB 25 DUP(?)
			n DW 25
			
	lea dý,dýzý1
	mov cx,n
	mov al,1
	l1:stosb
	inc al
	loop l1
	
	
	lea dý,dizi1
	mov cx,n
	xor al,al
	l1:inc al
	stosb
	loop l1			

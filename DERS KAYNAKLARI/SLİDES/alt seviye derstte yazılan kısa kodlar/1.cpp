//�F THEN ELSE
cmp ax,0
je label,1
mov bx,1;false
mov cx,5;bu sat�ra gerek yok yanl�s
label 1:mov bx,2;true
		mov cx,5

//bu kodda false olsa bx,2 diye c�kar

cmp ax,0
je label 1;true koluna g�re
mov bx,1;false
jmp EXIT
label 1:mov bx,2;true
EXIT:mov cx,5



cmp ax,0
jne LABEL 1
mov bx,2;true
jmp EXIT
label 1:mov bx,1;false
EXIT:mov cx,5;c�k�s


if then else'de naparsak yapal�m 2 tane dallanma komutuna ihtiyac duyar�z	

if(AX==0){
	BX=2;
}	
else{
	BX=1;
}
CX=5;

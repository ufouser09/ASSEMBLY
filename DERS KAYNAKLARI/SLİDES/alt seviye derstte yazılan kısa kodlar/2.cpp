//ÝF NULL ELSE

cmp ax,0
je TRUEKOL
jmp EXIT;false
TRUEKOL:mov BX,1
EXIT:MOV cx,5


//bos kol kosul
cmp ax,0
jne ax,0
mov bx,1;TRUE
FALSEKOL:mov cx,5
//bu kod daha verimli

if(AX==0){
	BX=1;
}
CX=5;

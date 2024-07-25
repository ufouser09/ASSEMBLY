cmp ax,0
jz true
mov bx,1
jmp next
true:mov bx,2
next:mov cx,5

if(AX=0){
	BX=2;
}
else{
	BX=1;
}
CX=5;

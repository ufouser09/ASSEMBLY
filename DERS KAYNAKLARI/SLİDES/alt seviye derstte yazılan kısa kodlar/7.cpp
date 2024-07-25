cmp ax,0
jz true
jmp next
true:mov bx,1
next:mov cx,5

if(AX=0){
	BX=1
}
CX=5

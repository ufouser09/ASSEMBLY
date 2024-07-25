//FOR DOWN TO
xor ax,ax
mov cx,10
tekrar:add ax,cx
sub cx,2
jcxz devam
jmp tekrar
devam:
	
	ax=0
	for(i=10;i>0;i=+2){
		ax=Ax+i
	}
	bx=1;

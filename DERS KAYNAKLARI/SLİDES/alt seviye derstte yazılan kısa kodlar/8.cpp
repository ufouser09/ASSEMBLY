xor ax,ax
mov s�,1
tekrar:cmp s�,10
ja devam
add ax,s�
add s�,2
jmp tekrar
devam:mov bx,1



ax=0
i=1
while(i<=10){
	ax=ax+i
	i=i+2
}
BX=1

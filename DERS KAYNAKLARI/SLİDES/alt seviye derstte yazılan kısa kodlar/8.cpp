xor ax,ax
mov sý,1
tekrar:cmp sý,10
ja devam
add ax,sý
add sý,2
jmp tekrar
devam:mov bx,1



ax=0
i=1
while(i<=10){
	ax=ax+i
	i=i+2
}
BX=1

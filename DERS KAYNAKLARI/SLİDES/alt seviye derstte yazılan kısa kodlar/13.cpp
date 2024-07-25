mov ax,0
mov cx,4
mov dý,0
l2:push cx
mov cx,3
mov sý,2
l1:add ax,dý
add ax,sý
ýnc sý
loop l1
pop cx
ýnc dý
loop l2
mov bx,1






ax=0
for(i=0;i<3;i++){
	for(j=2;j<4;j++){
		ax=ax+i+j
	}
}
bx=1;

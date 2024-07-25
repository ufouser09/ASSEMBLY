----------------------------------------------------------------------------------------------------------------

dizinin sýralý olup olmadýgýnýn kontrolu

byte tanýmlý bir dizinin kucukten buyuge sýralý olup olmadýgýný bulan exe tipi assembly programýný yazýnýz.
----------------------------------------------------------------------------------------------------------------

start  

n=5;----->cx
dizi[n]={1,2,3,4,5}
knt=0---->bx
i=0;------>sý

while(knt==0  &&  i>n-1){
	if(dizi[i]>dizi[i+1]){
		knt=1;
	}
	i=i+1;
}
if(knt==0){
	s=1;
}
else{
	s=0;
}
stop
----------------------------------------------------------------------------------------------------------------

program içerisinde kullanýlan yazmaclarýn karsýlýk geldigi degiskenler akýs diyagramýnda gösterilmistir
----------------------------------------------------------------------------------------------------------------


myds		segment para 'veri'
dizi		db 1,2,3,4,5
N			dw 5
s			db ?
myds		ends


myss 		segment para stack 'yýgýn'
			dw 20 dup(?)
myss 		ends


mycs		segment para 'kod'
			assume ds:myds,ss:myss,cs:mycs
ana 		proc far
----------------------------------------------------------------------------------------------------------------
			//dönüs için gerekli olan degerler yýgýnda saklanýyor
			push ds
			xor ax,ax
			push ax
			----------------------------------------------------------------------------------------------------------------
			//datasg ismiyle tanýmlý kesim alanýna erisebilmek için gerekli tanýmlar
			mov	ax,myds
			mov ds,ax		
			----------------------------------------------------------------------------------------------------------------
			//kodumuz burdan sonra baslýyor
			
			----------------------------------------------------------------------------------------------------------------

			//bx yazmacý knt dir ve döngüyü kontrol eder.
			mov bx,0;(bx yazmacý dongu kosulunun bozulup bozulmadýgýný belirlemek için kullanýlýr.baslnagýc degeri 0 dýr);
			//dizinin indisini sý(source index tutar)yaný forun içindeki i dir
			xor sý,sý;(sý dizinin indisini tutmaktadýr.sýfýrlamak dizinin ilk elemanýný gosterir hale gelir.);
			
			//dizinin eleman sayisi cx e atýlýr.
			mov cx,N;(dizinin eleman sayýsý cx e alýnýr)
			//döngü sayisini bir azaltýrýz çünkü döngü sayisindan bir eksik sayida karsýlastýrma yaparýz
			dec cx;(sondan bir önceki eleman için son elemanla karsýlastýrma yapýlacagýndan cx degeri 1 azaltýlýr);
			----------------------------------------------------------------------------------------------------------------

			//cmp komutu ile bx 0  ile karsýlastýrýlýr yani burda knt nin 0 esit olup olmadýgýna bakýlýr 0 a esitse döngü dogru gidiyordur eger yanlýs ise yani esit degilse döngüden çýkýp son if'e gidebilirsin
	don:	cmp bx,0;(kontrol yazmacý bx 0 ile karsýlastýrýlýr);
			//burda esit degilse son if'e gitcegini söylüyor.
			jne son_ýf;(0 a esit degilse son_ýf etiketine atlanýr)
			//dongunun indisi ile cx karsýlastýrýlýr  indisimizin döngü sýnýrýný asýp asmadýgýna bakýlýr.
			----------------------------------------------------------------------------------------------------------------

			
			cmp	sý,cx;(0 a esitse sý ile cx karsýlastýrýlýr)
			//eger sý cx den buyuk eþitse yani döngünün sonuna gelmiþ isek o zaman son_ife gidebilirsin
			jge son_ýf;(sý cx ten buyuk esitse son_if etiketine atlanýr)
			//dizinin sý indisli elemaný al ye alýnýr
			----------------------------------------------------------------------------------------------------------------

			
			mov al,dýzý[sý];(dizinin sý indisli elemaný al ye alýnýr )
			//dizinin elemaný kendisinden sonra gelen elemanla karsýlastýrýlýr
			cmp al,dýzý[sý+1];(al ile dizinin sý+1 indisli elemaný karsýlastýrýlýr)
			//kucuk esitse yani kosulumuzu saglýyorsa arttýr etiketine git
			jle artýr;(al dýzýnýn sý+1 ýndýslý elemanýndan kucuk esýtse arttýr etiketine atlanýr)
			//eger kosulumuzu saglamýyorsa kontrol degiskenine bir atýlýr.
			mov bx,1;(buyukse kontrol yazmacý bx e 1 atanýr)
			----------------------------------------------------------------------------------------------------------------
			//burda indis degiskenimizi bir arttýrýp döngüyü tekrar döndürürüz
	arttýr:	ýnc sý;(ýndýs yazmacý dizi byte tanýmlý oldugu için 1 arttýrýlýr)
			jmp don;(dongu kosullarýna(don etiketine) atlanýr)
	son_ýf:	cmp bx,0;(Döngüden çýkýlmýþtýr. Döngüde 2 adet koþul olduðundân hangi koþulun bozulduðunu anlamak için BX ile 0 karþýlaþtýrýlýr.)
			//kontrol degiskenimiz yani bx yazmacýmýz 0 degilse bu dizi sirasizdir
			jne sýrasýz;(BX, 0 deðilse, dizi sýralý olmayacaðý için sýrasýz etiketine atlanýr.)
			//eger kontrol degiskenimiz 0 ise dizimiz sýralýdýr.
			mov s,1;(bx 0 a esitse dizi sýralýdýr ve bunun için s degiskenine 1 yazýlýr)
			jmp son;(programýn sonuna atlanýr);
	sýrasýz:mov s,0;(dizi sýrasýz ise bu satýra gelinmiþtir)(bunun için s degiskenine 0 yazýlýr);
	
	son: 	retf
	ana 	endp
	mycs	ends
			end ana								
						

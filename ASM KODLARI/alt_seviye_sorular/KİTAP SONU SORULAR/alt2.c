ebob hesaplama
----------------------------------------------------------------------------------------------------------------

a ve b =[0-5000]aralýgýnda olmak uzere ebob(a,b)degerini bulan kod parcacýgýný yazalým;

start 

a=28;(birinci sayimizi ax olarak tuttuk)
b=32;(ikinci sayimizi bx olarak tuttuk)

if(a<b)
tmp=a;
a=b;
b=tmp;

while((a mod b)!=0)
c=a mod b
a=b
b=c

stop
----------------------------------------------------------------------------------------------------------------

codesg 		segment para 'kod'
			org 100h
			assume cs:cseg,ds:cseg,ss:cseg
ebob 		proc near

----------------------------------------------------------------------------------------------------------------
//burda ilk önce iki tane degiskenimiz var bunlarý alýyoruz sonra bunlarý karsýlastýrýyoruz. 
			mov ax,a;(birinci sayimizi ax degiskenine atadýk)
			mov bx,b;(ikinci sayimizi bx degiskenine atadýk)
			cmp ax,bx;(a ile b degerlerinden buyuk olanýnýn karsýlastýrma isleminin ilk operandý olmasý gerekir.bunun için a ile b ,ax ve bx yazmaclarý uzerinden karsýlastýrýlýr.a ile b den buyuk olaný ax in içerisine kucuk olaný bx içerisine konulur);
			
			
			
			//karsýlastýrma sonucumuzda buyuk esit cýkarsa istedigimizi elde etmisizdir
			jae l1;(ax,bx den buyuk esitse istedigimiz kombinasyon olusmustur.isleme atlanýr)
			//eger a, b den buyuk esit cýkmamýssa burda sayýlarýmýz degistiriyoruz
			xchg ax,bx;(ax bx den buyuk degilse bu iki yazmacýn içerisindeki degerler yer degistirilir)
			//16 bitlik bolme iþlemi yapýlacagý için DX imiz ilk önce sýfýrlanýr
		l1:	mov dx,0;(16 bitlik bolme islemi yapýlacagý için dx yazmacý 0 lanýr);
		//sonra burda aslýda a mod b yapyoruz ve mod sonucumuz yaný kalan dx de olusur
			dýv bx;(dx:ax/bx->bolum:ax,kalan:dx);
			//kalan degiskenimizi 0 la karsýlastýrýyoruz eger sonucumuz 0 ise ebob degerimiz b sayisidir.direk sonuc satýrýna gidebilirsiniz.
			cmp dx,0;(32/28-->bolum:1,kalan:4)(bolme islemi sonucu kalan 0 ise ebob bx yazmacý uzerinden olusmustur)
			je l2;(o sebeple (kalan 0 ise)l2 etiketine atlanýr)
			//kalan 0 degilse burda da dendigi gibi b degerimiz a ya mod sonucumuz bx e atýlýr ve döngü bu sekilde devam eder
			mov ax,bx;(kalan 0 degilse bx,ax'e,dx de bx'e alýnýr)
			mov bx,dx;
			jmp l1;(kosullu döngünün basýna atlanýr)
		
		
		l2:	mov sonuc,bx;(bx uzerinde olusan ebob degeri sonuc degiskenine alýnýr)
		
			ret;
	ebob 	endp;
	codesg	ends;
	end 	basla;			
//sayfa 518

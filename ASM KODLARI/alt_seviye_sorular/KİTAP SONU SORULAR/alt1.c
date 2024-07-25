verilen degerler için program cýktýsýný olusturma

----------------------------------------------------------------------------------------------------------------
SORU
x==[1-5]ve n=[1-6] aralýgýnda T=1 + x + x^2/2 + x^3/3 + ..... x^n/n;

----------------------------------------------------------------------------------------------------------------
/*
(bu soruya baktýgýnda diceksin ki burda bir toplam degiskene ihtiyacýn var toplam 
diye bir þey olustur bunu 16 bitlik yazmac olan BX de tut sonra bir döngü adedi olustur
 bu döngü sayilarini CX yazmacýnda tutuyoruz
sonra yukarýda þeyi fark etmen lazým her indis artýsýnda x in üstü ve altý indisle eþit þekilde gidiyor.
burda bi de x li ifademiz sürekli üslü þekilde artýyor.onun için ayrý bir degisken tutuyoruz.
onu da ax þeklinde tutarýz.bi de bu for döngüsü içinde artýcak for döngüsü içindeki i mizi ise
 DI þeklinde tutuyoruz.kýsacasý denklemimiz söyle olur.

for(i=1;i<=n;i++){
	t=t+xk/i;
	xk=xk*x;
}

 )
 */
----------------------------------------------------------------------------------------------------------------



start 


n=6;(bu dizinin eleman sayisi)(cx)(döngü sayisi cx de saklanýr)
x=5;(bu x'in degeri)(sý)(source index)
t=1;(bu toplam ifademiz toplam buna yazýlacak)(bx)(ilk basta 1 ifademiz oldugu için bir den baslattýk)
xk=x;(bu x ifademiz)(ax)

for(i=1;i<=n;i++)(burdaki i li ifedemizi ise (dý)ile tutarýz);
t=t+xk/i;
xk=xk*x;

stop

KODUMUZ
-------------------------------------------------------------------------------------------------------------
cseg 	segment para 'kod'
		org 100h
		assume cs:cseg,ds:cseg,ss:cseg
maýn 	proc near
		(kodumuzu buraya yazýcaz)
		
		//burda söyle düsünceksin ilk önce döngü sayisini döngü yazmacýna atarsýn 
		//sonra x degerimizi önceden dedigimiz gibi sý indexinde tutucaksin
		//sonra bizim bi de toplam için tutmak istedigimiz bx yazmacýna 1 degerini atarsýn
		//sonra ax degerine sý yazmacýnýn degerini atarsýn
		//burda sý x i temsil ederken ax her adýmda olusan x leri belirtir mesela birinci adýmda x iken ikinci adýmda x^2 olmus
		//sonra geriye forun içindeki i ifademiz var  onu da dý olarak tutarýz ve 1 degerini atarýz
		//biz bide 16 bitlik bolme islemi yapýcagýmýz için DX sýfýrlanýr
		mov cx,n;(dongu N kere donmesi için N cs içine atýlýr);
		mov sý,x;(x degerý sý içinde tutulur)
		mov bx,1;(ilk eleman 1 oldugu için toplam sonucunu tutacak bx yazmacýna 1 degeri atanýr)
		
		mov ax,sý;
		mov dý,1;(cevrim degiskeni dý olacak sekilde ayarlanýr)
		mov dx,0;(16 bitlik bolme islemi için dx yazmacý 0 lanýr)
	
	
	l1:	push ax;(ax yazmacýnýn degeri tekrar kullanýlacagý için ve bolme islemi(dýv)sonucu ax üzerinde olusacagý için bu yazmac yýgýnda saklanýr)(ax de x saklanýyor)
	
		dýv dý;(dx:ax/dý->bolum:ax;kalan dx,yani istenilen deger ax üzerinde olusur)//(burda x/i islemimizi yapýyoruz)
		
		add bx,ax;(bolme islemi sonucu bx ile toplanýr)//(sonra t=t+xk/i islemimizi yapýyoruz)
		pop ax;(ax yazmacýnýn bolmeden önceki halinin sý ile cagrýlmasý için yýgýndan alýnýr)//(sonra ax i tekrar cekiyoruz x cektik);
		
		mul sý;(ax*sý->dx:ax ikilisinden olusur.x ve n degerleri için verilen kýsýtlardan ötürü dx degeri her durumda 0 olur)//(burda xk=xk*x islemi yapýlýr)
		
		ýnc dý;(cevrim ýndýsý arttýrýlýr)(dongu degiskenimiz olan i bir artar)//(sonra i mizi bir arttýrýyoruz)
		loop l1;(islem cx kere tekrar edilir)(islem cx e atadýgýmýz N kadar devam eder)
		mov sonuc,bx;(bx yazmacýnda olusan deger,sonuc degiskenine alýnýr.)(en son döngü bozuldugunda ise sonuc bx üzerinde olusurdu bizde onu sonuc degiskenimize atýyoruz);
		
		ret
	maýn endp
sonuc 	dw ?;
n		dw 6;
x		dw 5;
cseg	ends;
		end maýn;
		
	//hocalarýn kitabý sayfa 516

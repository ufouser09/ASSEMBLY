verilen degerler i�in program c�kt�s�n� olusturma

----------------------------------------------------------------------------------------------------------------
SORU
x==[1-5]ve n=[1-6] aral�g�nda T=1 + x + x^2/2 + x^3/3 + ..... x^n/n;

----------------------------------------------------------------------------------------------------------------
/*
(bu soruya bakt�g�nda diceksin ki burda bir toplam degiskene ihtiyac�n var toplam 
diye bir �ey olustur bunu 16 bitlik yazmac olan BX de tut sonra bir d�ng� adedi olustur
 bu d�ng� sayilarini CX yazmac�nda tutuyoruz
sonra yukar�da �eyi fark etmen laz�m her indis art�s�nda x in �st� ve alt� indisle e�it �ekilde gidiyor.
burda bi de x li ifademiz s�rekli �sl� �ekilde art�yor.onun i�in ayr� bir degisken tutuyoruz.
onu da ax �eklinde tutar�z.bi de bu for d�ng�s� i�inde art�cak for d�ng�s� i�indeki i mizi ise
 DI �eklinde tutuyoruz.k�sacas� denklemimiz s�yle olur.

for(i=1;i<=n;i++){
	t=t+xk/i;
	xk=xk*x;
}

 )
 */
----------------------------------------------------------------------------------------------------------------



start 


n=6;(bu dizinin eleman sayisi)(cx)(d�ng� sayisi cx de saklan�r)
x=5;(bu x'in degeri)(s�)(source index)
t=1;(bu toplam ifademiz toplam buna yaz�lacak)(bx)(ilk basta 1 ifademiz oldugu i�in bir den baslatt�k)
xk=x;(bu x ifademiz)(ax)

for(i=1;i<=n;i++)(burdaki i li ifedemizi ise (d�)ile tutar�z);
t=t+xk/i;
xk=xk*x;

stop

KODUMUZ
-------------------------------------------------------------------------------------------------------------
cseg 	segment para 'kod'
		org 100h
		assume cs:cseg,ds:cseg,ss:cseg
ma�n 	proc near
		(kodumuzu buraya yaz�caz)
		
		//burda s�yle d�s�nceksin ilk �nce d�ng� sayisini d�ng� yazmac�na atars�n 
		//sonra x degerimizi �nceden dedigimiz gibi s� indexinde tutucaksin
		//sonra bizim bi de toplam i�in tutmak istedigimiz bx yazmac�na 1 degerini atars�n
		//sonra ax degerine s� yazmac�n�n degerini atars�n
		//burda s� x i temsil ederken ax her ad�mda olusan x leri belirtir mesela birinci ad�mda x iken ikinci ad�mda x^2 olmus
		//sonra geriye forun i�indeki i ifademiz var  onu da d� olarak tutar�z ve 1 degerini atar�z
		//biz bide 16 bitlik bolme islemi yap�cag�m�z i�in DX s�f�rlan�r
		mov cx,n;(dongu N kere donmesi i�in N cs i�ine at�l�r);
		mov s�,x;(x deger� s� i�inde tutulur)
		mov bx,1;(ilk eleman 1 oldugu i�in toplam sonucunu tutacak bx yazmac�na 1 degeri atan�r)
		
		mov ax,s�;
		mov d�,1;(cevrim degiskeni d� olacak sekilde ayarlan�r)
		mov dx,0;(16 bitlik bolme islemi i�in dx yazmac� 0 lan�r)
	
	
	l1:	push ax;(ax yazmac�n�n degeri tekrar kullan�lacag� i�in ve bolme islemi(d�v)sonucu ax �zerinde olusacag� i�in bu yazmac y�g�nda saklan�r)(ax de x saklan�yor)
	
		d�v d�;(dx:ax/d�->bolum:ax;kalan dx,yani istenilen deger ax �zerinde olusur)//(burda x/i islemimizi yap�yoruz)
		
		add bx,ax;(bolme islemi sonucu bx ile toplan�r)//(sonra t=t+xk/i islemimizi yap�yoruz)
		pop ax;(ax yazmac�n�n bolmeden �nceki halinin s� ile cagr�lmas� i�in y�g�ndan al�n�r)//(sonra ax i tekrar cekiyoruz x cektik);
		
		mul s�;(ax*s�->dx:ax ikilisinden olusur.x ve n degerleri i�in verilen k�s�tlardan �t�r� dx degeri her durumda 0 olur)//(burda xk=xk*x islemi yap�l�r)
		
		�nc d�;(cevrim �nd�s� artt�r�l�r)(dongu degiskenimiz olan i bir artar)//(sonra i mizi bir artt�r�yoruz)
		loop l1;(islem cx kere tekrar edilir)(islem cx e atad�g�m�z N kadar devam eder)
		mov sonuc,bx;(bx yazmac�nda olusan deger,sonuc degiskenine al�n�r.)(en son d�ng� bozuldugunda ise sonuc bx �zerinde olusurdu bizde onu sonuc degiskenimize at�yoruz);
		
		ret
	ma�n endp
sonuc 	dw ?;
n		dw 6;
x		dw 5;
cseg	ends;
		end ma�n;
		
	//hocalar�n kitab� sayfa 516

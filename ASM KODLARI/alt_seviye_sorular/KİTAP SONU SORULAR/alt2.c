ebob hesaplama
----------------------------------------------------------------------------------------------------------------

a ve b =[0-5000]aral�g�nda olmak uzere ebob(a,b)degerini bulan kod parcac�g�n� yazal�m;

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
//burda ilk �nce iki tane degiskenimiz var bunlar� al�yoruz sonra bunlar� kars�last�r�yoruz. 
			mov ax,a;(birinci sayimizi ax degiskenine atad�k)
			mov bx,b;(ikinci sayimizi bx degiskenine atad�k)
			cmp ax,bx;(a ile b degerlerinden buyuk olan�n�n kars�last�rma isleminin ilk operand� olmas� gerekir.bunun i�in a ile b ,ax ve bx yazmaclar� uzerinden kars�last�r�l�r.a ile b den buyuk olan� ax in i�erisine kucuk olan� bx i�erisine konulur);
			
			
			
			//kars�last�rma sonucumuzda buyuk esit c�karsa istedigimizi elde etmisizdir
			jae l1;(ax,bx den buyuk esitse istedigimiz kombinasyon olusmustur.isleme atlan�r)
			//eger a, b den buyuk esit c�kmam�ssa burda say�lar�m�z degistiriyoruz
			xchg ax,bx;(ax bx den buyuk degilse bu iki yazmac�n i�erisindeki degerler yer degistirilir)
			//16 bitlik bolme i�lemi yap�lacag� i�in DX imiz ilk �nce s�f�rlan�r
		l1:	mov dx,0;(16 bitlik bolme islemi yap�lacag� i�in dx yazmac� 0 lan�r);
		//sonra burda asl�da a mod b yapyoruz ve mod sonucumuz yan� kalan dx de olusur
			d�v bx;(dx:ax/bx->bolum:ax,kalan:dx);
			//kalan degiskenimizi 0 la kars�last�r�yoruz eger sonucumuz 0 ise ebob degerimiz b sayisidir.direk sonuc sat�r�na gidebilirsiniz.
			cmp dx,0;(32/28-->bolum:1,kalan:4)(bolme islemi sonucu kalan 0 ise ebob bx yazmac� uzerinden olusmustur)
			je l2;(o sebeple (kalan 0 ise)l2 etiketine atlan�r)
			//kalan 0 degilse burda da dendigi gibi b degerimiz a ya mod sonucumuz bx e at�l�r ve d�ng� bu sekilde devam eder
			mov ax,bx;(kalan 0 degilse bx,ax'e,dx de bx'e al�n�r)
			mov bx,dx;
			jmp l1;(kosullu d�ng�n�n bas�na atlan�r)
		
		
		l2:	mov sonuc,bx;(bx uzerinde olusan ebob degeri sonuc degiskenine al�n�r)
		
			ret;
	ebob 	endp;
	codesg	ends;
	end 	basla;			
//sayfa 518

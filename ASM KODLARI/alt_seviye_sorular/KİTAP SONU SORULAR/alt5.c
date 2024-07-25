----------------------------------------------------------------------------------------------------------------

dizinin s�ral� olup olmad�g�n�n kontrolu

byte tan�ml� bir dizinin kucukten buyuge s�ral� olup olmad�g�n� bulan exe tipi assembly program�n� yaz�n�z.
----------------------------------------------------------------------------------------------------------------

start  

n=5;----->cx
dizi[n]={1,2,3,4,5}
knt=0---->bx
i=0;------>s�

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

program i�erisinde kullan�lan yazmaclar�n kars�l�k geldigi degiskenler ak�s diyagram�nda g�sterilmistir
----------------------------------------------------------------------------------------------------------------


myds		segment para 'veri'
dizi		db 1,2,3,4,5
N			dw 5
s			db ?
myds		ends


myss 		segment para stack 'y�g�n'
			dw 20 dup(?)
myss 		ends


mycs		segment para 'kod'
			assume ds:myds,ss:myss,cs:mycs
ana 		proc far
----------------------------------------------------------------------------------------------------------------
			//d�n�s i�in gerekli olan degerler y�g�nda saklan�yor
			push ds
			xor ax,ax
			push ax
			----------------------------------------------------------------------------------------------------------------
			//datasg ismiyle tan�ml� kesim alan�na erisebilmek i�in gerekli tan�mlar
			mov	ax,myds
			mov ds,ax		
			----------------------------------------------------------------------------------------------------------------
			//kodumuz burdan sonra basl�yor
			
			----------------------------------------------------------------------------------------------------------------

			//bx yazmac� knt dir ve d�ng�y� kontrol eder.
			mov bx,0;(bx yazmac� dongu kosulunun bozulup bozulmad�g�n� belirlemek i�in kullan�l�r.baslnag�c degeri 0 d�r);
			//dizinin indisini s�(source index tutar)yan� forun i�indeki i dir
			xor s�,s�;(s� dizinin indisini tutmaktad�r.s�f�rlamak dizinin ilk eleman�n� gosterir hale gelir.);
			
			//dizinin eleman sayisi cx e at�l�r.
			mov cx,N;(dizinin eleman say�s� cx e al�n�r)
			//d�ng� sayisini bir azalt�r�z ��nk� d�ng� sayisindan bir eksik sayida kars�last�rma yapar�z
			dec cx;(sondan bir �nceki eleman i�in son elemanla kars�last�rma yap�lacag�ndan cx degeri 1 azalt�l�r);
			----------------------------------------------------------------------------------------------------------------

			//cmp komutu ile bx 0  ile kars�last�r�l�r yani burda knt nin 0 esit olup olmad�g�na bak�l�r 0 a esitse d�ng� dogru gidiyordur eger yanl�s ise yani esit degilse d�ng�den ��k�p son if'e gidebilirsin
	don:	cmp bx,0;(kontrol yazmac� bx 0 ile kars�last�r�l�r);
			//burda esit degilse son if'e gitcegini s�yl�yor.
			jne son_�f;(0 a esit degilse son_�f etiketine atlan�r)
			//dongunun indisi ile cx kars�last�r�l�r  indisimizin d�ng� s�n�r�n� as�p asmad�g�na bak�l�r.
			----------------------------------------------------------------------------------------------------------------

			
			cmp	s�,cx;(0 a esitse s� ile cx kars�last�r�l�r)
			//eger s� cx den buyuk e�itse yani d�ng�n�n sonuna gelmi� isek o zaman son_ife gidebilirsin
			jge son_�f;(s� cx ten buyuk esitse son_if etiketine atlan�r)
			//dizinin s� indisli eleman� al ye al�n�r
			----------------------------------------------------------------------------------------------------------------

			
			mov al,d�z�[s�];(dizinin s� indisli eleman� al ye al�n�r )
			//dizinin eleman� kendisinden sonra gelen elemanla kars�last�r�l�r
			cmp al,d�z�[s�+1];(al ile dizinin s�+1 indisli eleman� kars�last�r�l�r)
			//kucuk esitse yani kosulumuzu sagl�yorsa artt�r etiketine git
			jle art�r;(al d�z�n�n s�+1 �nd�sl� eleman�ndan kucuk es�tse artt�r etiketine atlan�r)
			//eger kosulumuzu saglam�yorsa kontrol degiskenine bir at�l�r.
			mov bx,1;(buyukse kontrol yazmac� bx e 1 atan�r)
			----------------------------------------------------------------------------------------------------------------
			//burda indis degiskenimizi bir artt�r�p d�ng�y� tekrar d�nd�r�r�z
	artt�r:	�nc s�;(�nd�s yazmac� dizi byte tan�ml� oldugu i�in 1 artt�r�l�r)
			jmp don;(dongu kosullar�na(don etiketine) atlan�r)
	son_�f:	cmp bx,0;(D�ng�den ��k�lm��t�r. D�ng�de 2 adet ko�ul oldu�und�n hangi ko�ulun bozuldu�unu anlamak i�in BX ile 0 kar��la�t�r�l�r.)
			//kontrol degiskenimiz yani bx yazmac�m�z 0 degilse bu dizi sirasizdir
			jne s�ras�z;(BX, 0 de�ilse, dizi s�ral� olmayaca�� i�in s�ras�z etiketine atlan�r.)
			//eger kontrol degiskenimiz 0 ise dizimiz s�ral�d�r.
			mov s,1;(bx 0 a esitse dizi s�ral�d�r ve bunun i�in s degiskenine 1 yaz�l�r)
			jmp son;(program�n sonuna atlan�r);
	s�ras�z:mov s,0;(dizi s�ras�z ise bu sat�ra gelinmi�tir)(bunun i�in s degiskenine 0 yaz�l�r);
	
	son: 	retf
	ana 	endp
	mycs	ends
			end ana								
						

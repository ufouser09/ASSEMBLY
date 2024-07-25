dizi birlestirme
----------------------------------------------------------------------------------------------------------------

a s�rketinde cal�sanlar�n dogum y�l� d1 dizisinde b sirketinde cal�sanlar�n yaslar� d2 dizisnde tutulmaktad�r once
 a s�rketinde cal�san a1 k�s�n�n sonra b s�rkentinde cal�san b1 kisinin bilgileri boyutu a1+b1 
 olan d3 dizisine aktar�lmak isteniyor.bu islemi gerceklestiren kod parcac�g�n� yazal�m
 ----------------------------------------------------------------------------------------------------------------

 start
 
 a1=5;
 b1=7;
 d1={1989,2002,1996,2003,1971}---->d�
 d2={21,63,42,29,54,35,32}------>s�
 
 
 for(i=1;i<a1;i++)
 d3[i]=d1[i];
 
 
 for(i=1;i<b1;i++)
 d3[a1+i]=d2[i],
 
 stop
 ----------------------------------------------------------------------------------------------------------------

 ilk dizide dogum tarihi ikinci dizide ise yas b�lg�s� tutuldugundan ilki word tan�ml� olmal�yken ikincisi byte tan�ml� olabilmektedir
 
 allsg		segment para 'code'
 org 		100h
 			assume cs:allsg,ds:allsg,ss:allsg
 atla:		jmp arrays
 a1			dw 5
 d1			dw 1989,2002,1996,2003,1971
 b1			dw 7
 d2 		db 21,63,42,29,54,35,32
 d3			dw 12 dup(?)
 arrays 	proc near
 ----------------------------------------------------------------------------------------------------------------
			//burda biz iki dizinin nerde basl�cag�n� bilmemiz laz�m bunu da load effective adress yani lea ile yapar�z
			
 			lea d�,d1;(d1 dizisinin adresi d� yazmac�na al�n�r)
			lea	s�,d2;(d2 dizisinin adresi s� yazmac�na al�n�r)
			
			//ama bizim d3 dizisini de indislemek i�in bir �ey kullanmam�z laz�m bunu da bx ile yapar�z
			xor bx,bx;(xor islemi bx yazmac�n� 0 lamak i�in kullan�l�r)(bx d3 dizinin indisi olarak kullan�lacakt�r)
			//ilk for da a1 kere islem yap�lacag� i�in cx e a1 at�l�r
			mov cx,a1;(d1 dizisi �zerinde a1 kere islem yap�lacag� i�in l1 cevriminin cevrim degiskeni a1 olarak ayarlan�r)
			
			//burda d1 dizisinin ilk eleman�n� ax e at�yorsun asl�nda
		l1:	mov ax,[d�];(d1 adresinde bulunan bir word boyutundaki deger ax yazmac�na al�n�r)
		//sonra bu ax deki degeri d3[bx] de at�yorsun 
			mov d3[bx],ax;(d3 dizisinin bx adresine (indisine)ax yazmac�n�n degeri atan�r)
			//yukar�da g�rd�g�n gibi d� dizisi word tan�ml� oldugu i�in d� y� 2 ser 2 ser artt�r�rs�n
			add d�,2;	(d1 word tan�ml� oldugu i�in,d1 dizisinin adresini gosteren d1 yazmac� iki�er olarak artt�r�l�r)
			//ayn� sekilde d3 dizisinin adresini tutan bx degiskeni de 2 ser 2 ser artar
			add bx,2;(ayn� sekilde d3 dizisinin indisini tutan bx yazmac� da,dizi word tan�ml� oldugu i�in 2 artt�r�l�r)
			//ve boyle d�ng� devam eder
			loop l1;(a1 kez l1 dongusunun islemi ger�eklestirilir)(d1 dizisinin a1 elemani,d3 dizisinin ilk a1 eleman�na yerlest�r�lm�st�r);
			//sonra ikinci d�ng�m�z ortaya c�k�yor burda da ikinci d�ngumuz b1 kez d�necegi i�in cx e yan� d�ng� yazmac�na b1 yerlest�r�l�r
			mov cx,b1;(d2 dizisinin elaman sayisi olan b1 degeri cx i�erisine yerlest�r�l�r)
			//d2 dizisinin ilk eleman� al yazmac�na yerlestirilir
		l2:mov al,[s�];(d2 dizisinin s� adresinden 1 byte al�n�p al yazmac�n�n i�erisine at�l�r)
		//d2 dizisinden d3 dizisine aktar�m yap�lacak ama d3 dizisi word oldugu i�in cbw ile ile d2 dizisi al den ax'e genisletilir
		cbw;(d2 dizisi byte d3 dizisi ise word tan�ml�d�r.d2 dizisinin al ye al�nan elemanlar� cbw kodu ile ax e genisletilir )
		//d2 dizisinin elemanlar�n� d3 dizisine aktar�yoruz.
		mov d3[bx],ax;(boylece d2 dizisinin elemanlar� d3 dizisine bx indisinin en son kald�g� yerden itibaren yerlestirilir)
		//d3 dizisi word oldugu i�in 2 ser 2 ser artt�rmam�z laz�m
		add bx,2;(d3 dizisi word tan�ml� oldugu i�in bx 2 artt�r�l�r)
		//d2 dizisi byte tan�ml� oldugu i�in onu ise birer birer artt�rmam�z laz�m
		inc s�;(d2 dizisi byte tan�ml� oldugu i�in s� 1 artt�r�l�r)
		//d�ngumuz bu sekilde devam eder.
		loop l2;(b1 elemanl� d2 dizisinin t�m elemanlar� d3 dizisine yerlest�r�l�nceye kadar cevrim b1 kez cal�s�r)
		
		ret;
arrays 	endp;
allsg 	ends
		end atla;				
		
		
		// sayfa 520

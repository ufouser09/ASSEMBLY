dizi birlestirme
----------------------------------------------------------------------------------------------------------------

a sýrketinde calýsanlarýn dogum yýlý d1 dizisinde b sirketinde calýsanlarýn yaslarý d2 dizisnde tutulmaktadýr once
 a sýrketinde calýsan a1 kýsýnýn sonra b sýrkentinde calýsan b1 kisinin bilgileri boyutu a1+b1 
 olan d3 dizisine aktarýlmak isteniyor.bu islemi gerceklestiren kod parcacýgýný yazalým
 ----------------------------------------------------------------------------------------------------------------

 start
 
 a1=5;
 b1=7;
 d1={1989,2002,1996,2003,1971}---->dý
 d2={21,63,42,29,54,35,32}------>sý
 
 
 for(i=1;i<a1;i++)
 d3[i]=d1[i];
 
 
 for(i=1;i<b1;i++)
 d3[a1+i]=d2[i],
 
 stop
 ----------------------------------------------------------------------------------------------------------------

 ilk dizide dogum tarihi ikinci dizide ise yas býlgýsý tutuldugundan ilki word tanýmlý olmalýyken ikincisi byte tanýmlý olabilmektedir
 
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
			//burda biz iki dizinin nerde baslýcagýný bilmemiz lazým bunu da load effective adress yani lea ile yaparýz
			
 			lea dý,d1;(d1 dizisinin adresi dý yazmacýna alýnýr)
			lea	sý,d2;(d2 dizisinin adresi sý yazmacýna alýnýr)
			
			//ama bizim d3 dizisini de indislemek için bir þey kullanmamýz lazým bunu da bx ile yaparýz
			xor bx,bx;(xor islemi bx yazmacýný 0 lamak için kullanýlýr)(bx d3 dizinin indisi olarak kullanýlacaktýr)
			//ilk for da a1 kere islem yapýlacagý için cx e a1 atýlýr
			mov cx,a1;(d1 dizisi üzerinde a1 kere islem yapýlacagý için l1 cevriminin cevrim degiskeni a1 olarak ayarlanýr)
			
			//burda d1 dizisinin ilk elemanýný ax e atýyorsun aslýnda
		l1:	mov ax,[dý];(d1 adresinde bulunan bir word boyutundaki deger ax yazmacýna alýnýr)
		//sonra bu ax deki degeri d3[bx] de atýyorsun 
			mov d3[bx],ax;(d3 dizisinin bx adresine (indisine)ax yazmacýnýn degeri atanýr)
			//yukarýda gördügün gibi dý dizisi word tanýmlý oldugu için dý yý 2 ser 2 ser arttýrýrsýn
			add dý,2;	(d1 word tanýmlý oldugu için,d1 dizisinin adresini gosteren d1 yazmacý ikiþer olarak arttýrýlýr)
			//ayný sekilde d3 dizisinin adresini tutan bx degiskeni de 2 ser 2 ser artar
			add bx,2;(ayný sekilde d3 dizisinin indisini tutan bx yazmacý da,dizi word tanýmlý oldugu için 2 arttýrýlýr)
			//ve boyle döngü devam eder
			loop l1;(a1 kez l1 dongusunun islemi gerçeklestirilir)(d1 dizisinin a1 elemani,d3 dizisinin ilk a1 elemanýna yerlestýrýlmýstýr);
			//sonra ikinci döngümüz ortaya cýkýyor burda da ikinci döngumuz b1 kez dönecegi için cx e yaný döngü yazmacýna b1 yerlestýrýlýr
			mov cx,b1;(d2 dizisinin elaman sayisi olan b1 degeri cx içerisine yerlestýrýlýr)
			//d2 dizisinin ilk elemaný al yazmacýna yerlestirilir
		l2:mov al,[sý];(d2 dizisinin sý adresinden 1 byte alýnýp al yazmacýnýn içerisine atýlýr)
		//d2 dizisinden d3 dizisine aktarým yapýlacak ama d3 dizisi word oldugu için cbw ile ile d2 dizisi al den ax'e genisletilir
		cbw;(d2 dizisi byte d3 dizisi ise word tanýmlýdýr.d2 dizisinin al ye alýnan elemanlarý cbw kodu ile ax e genisletilir )
		//d2 dizisinin elemanlarýný d3 dizisine aktarýyoruz.
		mov d3[bx],ax;(boylece d2 dizisinin elemanlarý d3 dizisine bx indisinin en son kaldýgý yerden itibaren yerlestirilir)
		//d3 dizisi word oldugu için 2 ser 2 ser arttýrmamýz lazým
		add bx,2;(d3 dizisi word tanýmlý oldugu için bx 2 arttýrýlýr)
		//d2 dizisi byte tanýmlý oldugu için onu ise birer birer arttýrmamýz lazým
		inc sý;(d2 dizisi byte tanýmlý oldugu için sý 1 arttýrýlýr)
		//döngumuz bu sekilde devam eder.
		loop l2;(b1 elemanlý d2 dizisinin tüm elemanlarý d3 dizisine yerlestýrýlýnceye kadar cevrim b1 kez calýsýr)
		
		ret;
arrays 	endp;
allsg 	ends
		end atla;				
		
		
		// sayfa 520

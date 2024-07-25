 Tablo 12-7: EXTRN/PUBLIC kullan�m� ile parametre aktar�m� - 
                     veri kullanan program
1                 TITLE EXTRN/PUBLIC ile parametre aktar 
2                 EXTRN Ack:Byte, Eleman: Word o�)
3     Stcksg2     SEGMENT PARA STACK 'STACK  C7
4                 DW 10 DUP (?)              �
5     Stcksg2     ENDS                     C�
6     Datasg2     SEGMENT BYTE 'DATA'    �Ni
7     B_Bytel     DB ?
8     B_Byte21    DB ?              n .<0
9     Datasg2     ENDS                V
10    Codesg2     SEGMENT PARA 'CODE'
11                ASSUME CS:Codesg2, DS:Datasg2, SS:Stcksg2
12    Altprg      PROC FAR
13                            ; D�n�� ve veri kesimi eri�imi i�in gerekli kodlar
14                LEA SI, Ack ; Ac�k isimli de�i�ke
15                            ; Di�er i�lemler
16                RET         ; �a��r�ld��� noktaya geri d�n
17    Altprg      ENDP
18    Codesg2     ENDS
19                ENUITprg    ; Program�n ba�lang�� notas�

//YORDAMLAR VE PARAMETRE AKTARMA Y�NTEMLER�
yazd�g�m�z yordamlar aras�nda bir tak�m degerlerin verilip al�nmas� islemi parametre aktarma olarak adland�r�lmaktad�r.
parametre aktar�m�nda dikkat edilmesi gereken en �nemli nokta aktar�lmas� dusunulen parametrenin say�s�d�r.
bu say�ya bagl� olarak parametre aktarma y�ntemlerinden uygun olan�n�n secilmesi gerekir.eger az say�da parametre aktar�m� s�z konusu olacak ise bunlar deger(by value)olarak aktar�labilir.
ancak �ok miktarda parametre aktar�m� s�z konusuu ise bunlar� deger olarak aktarmak her zaman mumkun olmayacakt�r.
bu gibi durumlarda adres(by referance)ile kars� tarafa parametre aktarmak daha uygundur.

yordamlara parametre aktarmak i�in 3 temek y�ntem vard�r.bunlar:
	
	1-yazmac uzerinden parametre aktarmak(deger aktar�m�)
	2-y�g�n �zerinden parametre aktarma(deger aktar�m�)
	3-public/extrn tan�mlar� yard�m�yla ortak veri tan�m� yaparak parametre aktarma(adres aktarma)
	
//YAZMAC UZER�NDEN PArAMETRE AKTARMA

aktar�lacak parametre say�ca az ise yazmaclardan yararlanmak en h�zl� ve kolay yollardan birisidir.
parametre aktarmak i�in genelde veri yazmaclar�(AX,BX,CX,DX)ve indis yazmaclar�(SI,DI)kullan�l�r.
bunlar d�s�nda kalan yazmaclar�n parametre aktar�m� i�in kullan�lmas� al�s�ld�k bir durum olmad�g� gibi kesim ve isaretci grubu yazmaclar �zel g�revleri nedeniyle parametre aktar�m�nda kullan�lmaya uygun degillerdir.
bununla birlikte veri ve indis yazmaclar�ndan da baz�lar�n�n programda yap�lan islemlerin geregi olarak kullan�mda olabilecegi de dusunulmelidir.
k�saca yazmac uzerinden parametre aktar�m� 2-3  parametre i�in oldukca h�zl� bir cozumdur.
zira yazmac kumesi mikroislemci uzerinde cal�st�r�lan her turlu program taraf�ndan paylas�lan niteliktedir.
genel olarak aktar�lmas� dusunulen parametre yazmaca yerlestirildikten sonra gerekli yordam(veya kesme)cag�r�lacakt�r.benzer sekilde cag�r�lan yordam da(veya kesme de)kendisini cag�ran koda donus degerini
yazmac(lar)kullanarak aktarabilir.
daha �nce inceledigimiz �rnek 10-1,�rnek 10-2,ornek 10-3 ve 11-1 de yazmac kullan�larak parametre aktar�lm�st�r.


//YIGIN UZER�NDEN PARAMETRE AKTARMA
deger olarak parametre aktarma yollar�ndan biri de y�g�n� kullanmakt�r.y�g�n�n yordamlar aras�nda paylas�l�r nitelikte bir alan olmas� onun parametre aktar�m�nda kullan�lmas�na imkan saglamaktad�r.
ancak y�g�n�n parametre aktarmak amac�yla kullan�labilmesi i�in aktar�lmas� dusunulen parametreleri bar�nd�rabilecek buyuklukte tan�mlanmas� gereklidir.ayr�ca y�g�n�n yordam cag�rma islemlerinde donus adreslerini tuttugu da dusunuldugunde,y�g�n �zerinde tutulacak(unutulacak)
herhangi bir deger,cag�r�lan noktaya donusu imkans�z hale getirecektir.
benzer sekilde y�g�ndan gereginden fazla degerin al�nmas� da ayn� sonucu dogurur.k�saca y�g�n kullan�m� s�ras�nda her PUSH isleminin kars�l�g� olarak bir POP islemi veya buna esdeger sonuc uretecek turde baska islemlerin yap�lams� gerekmektedir.y�g�n �zeriden aktar�lacak parametrelerin yordam cag�r�lmadan �nce PUSH komutlar� yard�m�yla y�g�na yerlestirilmesi gerekmektedir.
ancak bundan sonra CALL komutu kullan�larak program�n ak�s� ilg�l� yordamdan devam edicek sekilde degistirlebilir.cag�r�lan yordam�n i�inden y�g�nda bulunan parametrelere erismek i�in POP komutu kesinlikle kullan�lmamal�d�r.
SP yazmac�n degeri kullan�c� taraf�ndan degistirilerek y�g�n uzerinde herhangi bir alana eris�lmeye cal�s�lmas� daha da buyuk problemlere neden olacakt�r.
bu durumda y�g�n alan� uzerideki parametrelere erisim i�in BP yazmac�ndan yararlan�lmal�d�r.

y�g�n uzerinden parametre aktarma islemi i�in kullan�lacak iskelet program yap�s� tablo 12-1 de verilmistir.ilk asm isimmli programdan WORD1 ve WORD2 isimli degiskenler y�g�na PUSH komutlar� yard�m�yla yerlestirilmistir.(sat�r 18-19).
parametrelerin y�g�na yerlesmesini tak�ben onlar uzerinde islem yap�lmas� planlanan ALTPRG isimli,far olarak tan�mlanm�s har�c� yordam (sat�r 2)CALL komutu (sat�r 20)ile cag�r�lm�st�r.cag�r�lan yordam�n FAR tan�mlanm�s olmas� nedeniyle donus adresi olarak y�g�nda kesim ve goreli konum ikilisinin saklanmas� gerekecektir.
buna g�re y�g�n�n buyuklugunun ihitiyac� kars�layacak bicimde belirlenmesi gerekmektedir�
�LK.ASM isimli program komut sat�r�ndan cag�r�ld�g� i�in geri donebilmek �zere y�g�nda 2 word donus adresi zaten yerlestirilmis durumdad�r.(sat�r 14,16).buna ek olarak y�g�na parametre olarak yerlest�r�lm�s olan 2 word daha vard�r
cag�r�lan FAR yordamdan geri donulebilmesi i�in gerekli olan 2 word'luk donus adresi de dusunuldugunde toplam 6 word'luk y�g�n alan�n�n kullan�ld�g� ac�kca g�r�lmektedir.
bu kullan�m m�ktar�na bakarak y�g�n� ucu ucuna yetecek kadar tan�mlamak dogru bir yaklas�m degildir.
Zira ilerleyen basl�klar alt�nda anlatacag�m�z -sistemin surekliligini saglamak �zere belirli aral�klarla devreye girip c�kan -kesmeler de y�g�n alan�n� kullan�lmaktad�r.
kesmeler de d�kkate al�narak y�g�n�n ihtiyac�n uzerinde bir deger verilerek tan�mlanmas� al�s�lm�s bir durumdur.ancak bu degeri �ok buyuk secmek de dogru bir yaklas�m degildir.programc�,y�g�n buyuklugunu zaman i�erisinde kazanacag� deneyim ile uygulaman�n gereklerine dikkat ederek belirlemelidir.
-
-
-
-
-SEMA
-
-
-
-


parametreli aktar�cag�m�z yordam cag�r�ld�g� anda y�g�n�n durumu incelendiginde tablo 12-2'de g�sterilen yap� ile kars�las�lacakt�r.

-SEMA

ilk.asm isimli programda (tablo 12-1,sat�r 4)y�g�n 16 adet word olarak tan�mlanm�st�r.(20H adet byte).buna g�re y�g�n kesimi i�inde isaretci olarak kullan�lan SP yazmac�n�n degeri 001EH olacakt�r.(y�g�na ilk yerlestirilen deger 001EH-001FH adresli bytlara yerlesm�st�r.)komut sat�r�na d�nusu saglamak i�in donus kesim adresi ve g�reli konum adresleri de y�g�na yerlest�r�lm�st�r.
ard�ndan WORD1 ve WORD2 isimli word tipindeki degiskenler y�g�na parametre olarak yerlest�r�lm�st�r.(sat�r 18-19).FAR olarak tan�ml� har�c� yordam�n cagr�lmas�yla program�n 21.sat�rdaki komutu islemek i�in donebilmesini saglamak �zere gerekli kesim ve goreli konum degerleri de y�g�na yerlest�r�lecektir.(sat�r 20)


simdi parametrelere eriserek bunlar uzerinde islem yapacak olan program parcas�n�n  iskelet yap�s�n� tablo 12-3 uzerinde inceleyelim
y�g�n �zerinden parametrelere erismek isteyen yordam bu islemi yaparken BP yazmac�ndan yararlanmaktad�r.
BP yazmac�,sp yazmac� gibi y�g�n alan�n�n baslang�c�n� g�steren SS kesim yazmac� ile birlikte kullan�l�r.
ancak BP yazmac�n�n,SP yazmac�ndan farkl� olarak degeri kullan�c� taraf�ndan degistirilebilmektedir.
bu sayede kullan�c� y�g�n� bir dizi gibi kullanabilmekte ve y�g�n �zerinde istedigi veriye rahatl�kla ulasabilmektedir.

-
-
-
-
-12-3
-
-
-
-
tablo 12-3 de verilen yordam�n hemen bas�nda BP yazmac�n�n da y�g�n �zerinde sakland�g� g�r�lmektedir.(sat�r 6)cag�r�lan yordam�n g�revini yerine getirmek �zere kulland�g� yazmaclar�n o anda sahip olduklar� degerler cag�ran yordam ac�s�ndan �nemli olabilir.
bu yazmaclardaki degerlerin bozulmas�n� engellemek �zere y�g�nda saklanmalar� ve cag�ran yordama geri donulmeden hemen �nce y�g�na konus s�ras�n�n tersinde ilgili yazmaclara aktar�lmalar� gereklidir.
bu sayede cag�r�lan kodlar kendilerini cag�ran kodlar�n cal�smalar�n� engellemez ve hemen hemen her t�rl� program ile birlikte kullan�labilirler.BP yazmac�n�n degeri de PUSH komutu ile y�g�n �zerinde geldigi yerde kullan�mda olabilecegi dusuncesi ile saklanmaktad�r.
Altprg isimli yordama gelindiginde y�g�n�n durumunu tablo 12-4 uzerinde inceleyecek olursak


-12-4

BP yazmac� PUSH edildikten sonra SP yazmac�ide�eri bu yazmaca y�klenmektedir
(sat�r 7). B�ylece BP yazmacm�n de�eri kullan�c� kontrol�nde belirlenerek y���na bir dizi
gibi eri�me �ans� elde edilmi�tir. Y��m adresleri incelendi�inde y���n�n altmda kalan de-
�erlere eri�mek i�in BP yazmacmdaki de�erin artt�r�lmas� gereklidir. Bunu yaparken eri-
�ilmesi d���n�len parametrenin adresi hesaplanmal�d�r. Wordl isimli de�i�kene eri�ebil-
mek i�in [BP+8] adresli168 bellek i�eri�ine bakmak yeterli olacakt�r (sat�r 9). Y��m ala-
n�ndaki parametrelere BP yazmac� 114ri�ilmesinin en b�y�k avantaj�, herhangi bir PUSH
i�lemi yap�lmas� durumunda bile Ig1P yazmacm�n de�erinin de�i�memesidir. B�ylece y�-
��ndaki parametrelere eri�mekShi yeniden adres hesab� yap�lmas� gerekmez. �a��r�lan
yordamdan d�n�lmeden �ncebrogramm ba��nda kullamlan PUSH BP komutunun kar��-
l��� olan POP BP komutunQP69 kullan�lmas� (sat�r 1 2) gerekir. Bu sayede SP yazmac�
d�n�� adreslerinin oldu�u noktay� g�sterir hale gelmi� olur ve RET (sat�r 1 3) komutuyla
�a��ran yordama d�n�l�r. RET komutu do�as� gere�i d�n�� adreslerini ilgili yazma�lara
yerle�tirdikten sonk�P yazmacm�n de�erini de ayarlayacakt�r. Bu i�lemden sonra y���n�n
durumu Tablo 1 I�ie g�sterildi�i gibi olacakt�r. Bu noktada sorulmas� gereken �nemli
bir soru vard�r. rametre olarak aktar�lmak �zere y���na yerle�tirilen de�erleri oradan



�ekmek/almak kimin sorumluluk' unda olacakt�r ?" Bu sorunun cevab� uygulaman�n nite-
li�ine ba�li olarak de�i�ebilir. E�er �a��nlan yordam, aktanlan parametreler �zerinde i�-
lem yapm�� ve bunun sonu�lar�n� yine y��mda parametreler� 7� i�in aynlm�� al�4azarak
kendisini �a��ran programa aktarmay� ama�lam��sa bu de�erleri r��ndan �ekmek yine
�a��ran tarafin g�revidir. �a��ran taraf bunlan uygun �ekilde POP ederenerekli de�i�-
kenlere veya yazma�lara aktararak i�lemlerine devam edecektir. Ancak �Inlan yordam-
dan d�n�ld���nde y���n �zerindeki de�erler �nemli de�illerse iki olasillk olu�maktad�r.
�lk olas�l�k bu de�erleri y���na koyan�n kald�rmas�d�r Parametrelefi r��na koymak i�in
kullan�lan PUSH komutu kadar POP komutu ile bunlar y��mdan geri alm�rlar. Bu i�lem
program�n yava�lamas�na neden olacakt�r. Zira her POP i�lemi i�in r��na eri�ilmekte, bir
word al�narak bir yazma� veya bellek alan�na aktanlmaktandmdan SP yazmacm�n de-
�eri (POP komutu tarafmdan) 2 byte artt�nlmaktadr. �stelinu i�lem hi� kullan�lmaya-
cak olan veriyi �ekmek (k�saca program�n do�ru bir �elgeesonlanmas�m sa�layacak d�-
n�� adreslerine ula�mak) i�in yap�lmaktad�r. Di�er olal'�lc hem daha kolay hem de ba�a-
r�m� ilkin g�re daha iyi bir ��z�m sunmaktad�r. Bu ��z�m, �a��nlan yordamm geri d�n-
mesini sa�layan RET komutunun yan�na yaz�ladde�er ile SP yazmac�mn de�erinin artt�-
nlmas�d�r. �rne�imizde (sat�r 13) RET 4 komutu, �nce d�n�� adreslerini y��indaR � 4144-u Et
rak (SP �0018H de�erini al�r) ardmdan SP<-SP + 4 i�lemini yap�lmaktad�r (SN-001CH"


-tablo 12-5


                                                                                          
//12.3 EXTRN/PUBLIC Kullan�m� ile Parametre Aktar�m�
      Daha �nceki �rneklerimizde EXTRN/PUBLIC kullan�m� ile nas�l parametre aktar�l-
      d��� konusu �zerinde durmu�tuk. Bu �ekilde parametre aktar�m�nda adrIcullan�l-
      d��� (by reference) i�in daha fazla veri, daha az zahmet ile kar�� tarafa'aktanlabil-     mektedir. Tablo 12-6'da verilen iskelet kod par�as�nda Ack isimli 100 - 9te b�y�kl�-      ��nde bir dizi ve Eleman isimli de�i�ken PUBLIC tan�mlanarak (Ta�r 2) ba�ka bir
-     mektedir. Tablo 12-6'da verilen iskelet kod par�as�nda Ack isimli 100 - 9te b�y�kl�-      ��nde bir dizi ve Eleman isimli de�i�ken PUBLIC tan�mlanarak (Ta�r 2) ba�ka bir
      ��nde bir dizi ve Eleman isimli de�i�ken PUBLIC tan�mlanarak (Ta�r 2) ba�ka bir
      kod taraf�ndan kullan�labilir k�l�nm��t�r.


   Benzer �ekilde Tablo 12-7'deki program par�as�nda, EXTRN tan�m� ile Ack isimli
   byte, Eleman isimli word tipinde (sat�r 2) harici veri alanlar�na eri�ilmek istendi�i
   belirtilmi�tir.
   Dikkat ed�k olursa Tablo 12-6' da verilen iskelet kod par�as�nda tan�ml� olan Ack
   isimli d� yap�s�ndaki de�i�kene Tablo 12-7'de verilen iskelet kod par�as�ndaki
   Altprg3�mli yordam�n eri�erek bir tak�m i�lemler yapmas� hedeflenmi�tir. Ancak
   Alt            yordam, �zerinde i�lem yapaca�� d�zinin ba�lang�� adresini ve veri ti-
   piqb � ilmesine ra�men dizinin uzunlu�u (eleman say�s�) hakk�nda bir bilgiye sahip
       ildir. O zaman eleman say�s�n�n da Altprg isimli yordama bir �ekilde parametre
,arak aktar�lmas� gerekecektir. Hat�rlanaca�� �zere az say�da parametre aktarmak
   i�in yazma�lar�n kullan�lmas� en uygun y�ntemdir. Ancak bu �rne�imizde bu y�n-
   temin kullan�lmas� m�mk�n de�ildir. Zira Altprg isimli yordam ile Tablo 12-6'da
   verilen program arasmda (Ack isimli de�i�keni payla�mak d���nda) bir kodvl ��i"Ssiu EtWindows'u etkinle�t



   yoktur. K�saca Tablo 12-6'da ki program dilimi i�inde Altprg isimli yordam �a��nl-  mad��� i�in �a��rma i�lemi �ncesinde bir yazma� yard�m� ile Eleman say�s�n�n para-  metre olarak aktar�lmas� da m�mk�n olamaz. O zaman dizinin boyutun elirleyen
-  mad��� i�in �a��rma i�lemi �ncesinde bir yazma� yard�m� ile Eleman say�s�n�n para-  metre olarak aktar�lmas� da m�mk�n olamaz. O zaman dizinin boyutun elirleyen
-  metre olarak aktar�lmas� da m�mk�n olamaz. O zaman dizinin boyutun elirleyen
   Eleman de�i�kenin de EXTRN/PUBLIC tan�mlar� kullan�larak pala�� mas� ve
   Altprg isimli yordam�n ihtiya� duydu�u anda bu de�i�ken kullanmas� lanmal�d�r.

-tablo


Her iki kod par�as� kendi     na �al��abilir olmakla beraber Tablo 12-7'deki progra-
m�n, Tablo 12-6'da tamml� Ack isimli veri alan�n� kullanabilmesi i�in her iki koda
ait OBJ uzant�l� dosyalln birlikte Link i�leminden ge�irilmesi gereklidir'''.
                , //bi51 



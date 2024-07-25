 Tablo 12-7: EXTRN/PUBLIC kullanýmý ile parametre aktarýmý - 
                     veri kullanan program
1                 TITLE EXTRN/PUBLIC ile parametre aktar 
2                 EXTRN Ack:Byte, Eleman: Word oç)
3     Stcksg2     SEGMENT PARA STACK 'STACK  C7
4                 DW 10 DUP (?)              •
5     Stcksg2     ENDS                     CÝ
6     Datasg2     SEGMENT BYTE 'DATA'    ýNi
7     B_Bytel     DB ?
8     B_Byte21    DB ?              n .<0
9     Datasg2     ENDS                V
10    Codesg2     SEGMENT PARA 'CODE'
11                ASSUME CS:Codesg2, DS:Datasg2, SS:Stcksg2
12    Altprg      PROC FAR
13                            ; Dönüþ ve veri kesimi eriþimi için gerekli kodlar
14                LEA SI, Ack ; Acýk isimli deðiþke
15                            ; Diðer iþlemler
16                RET         ; Çaðýrýldýðý noktaya geri dön
17    Altprg      ENDP
18    Codesg2     ENDS
19                ENUITprg    ; Programýn baþlangýç notasý

//YORDAMLAR VE PARAMETRE AKTARMA YÖNTEMLERÝ
yazdýgýmýz yordamlar arasýnda bir takým degerlerin verilip alýnmasý islemi parametre aktarma olarak adlandýrýlmaktadýr.
parametre aktarýmýnda dikkat edilmesi gereken en önemli nokta aktarýlmasý dusunulen parametrenin sayýsýdýr.
bu sayýya baglý olarak parametre aktarma yöntemlerinden uygun olanýnýn secilmesi gerekir.eger az sayýda parametre aktarýmý söz konusu olacak ise bunlar deger(by value)olarak aktarýlabilir.
ancak çok miktarda parametre aktarýmý söz konusuu ise bunlarý deger olarak aktarmak her zaman mumkun olmayacaktýr.
bu gibi durumlarda adres(by referance)ile karsý tarafa parametre aktarmak daha uygundur.

yordamlara parametre aktarmak için 3 temek yöntem vardýr.bunlar:
	
	1-yazmac uzerinden parametre aktarmak(deger aktarýmý)
	2-yýgýn üzerinden parametre aktarma(deger aktarýmý)
	3-public/extrn tanýmlarý yardýmýyla ortak veri tanýmý yaparak parametre aktarma(adres aktarma)
	
//YAZMAC UZERÝNDEN PArAMETRE AKTARMA

aktarýlacak parametre sayýca az ise yazmaclardan yararlanmak en hýzlý ve kolay yollardan birisidir.
parametre aktarmak için genelde veri yazmaclarý(AX,BX,CX,DX)ve indis yazmaclarý(SI,DI)kullanýlýr.
bunlar dýsýnda kalan yazmaclarýn parametre aktarýmý için kullanýlmasý alýsýldýk bir durum olmadýgý gibi kesim ve isaretci grubu yazmaclar özel görevleri nedeniyle parametre aktarýmýnda kullanýlmaya uygun degillerdir.
bununla birlikte veri ve indis yazmaclarýndan da bazýlarýnýn programda yapýlan islemlerin geregi olarak kullanýmda olabilecegi de dusunulmelidir.
kýsaca yazmac uzerinden parametre aktarýmý 2-3  parametre için oldukca hýzlý bir cozumdur.
zira yazmac kumesi mikroislemci uzerinde calýstýrýlan her turlu program tarafýndan paylasýlan niteliktedir.
genel olarak aktarýlmasý dusunulen parametre yazmaca yerlestirildikten sonra gerekli yordam(veya kesme)cagýrýlacaktýr.benzer sekilde cagýrýlan yordam da(veya kesme de)kendisini cagýran koda donus degerini
yazmac(lar)kullanarak aktarabilir.
daha önce inceledigimiz örnek 10-1,örnek 10-2,ornek 10-3 ve 11-1 de yazmac kullanýlarak parametre aktarýlmýstýr.


//YIGIN UZERÝNDEN PARAMETRE AKTARMA
deger olarak parametre aktarma yollarýndan biri de yýgýný kullanmaktýr.yýgýnýn yordamlar arasýnda paylasýlýr nitelikte bir alan olmasý onun parametre aktarýmýnda kullanýlmasýna imkan saglamaktadýr.
ancak yýgýnýn parametre aktarmak amacýyla kullanýlabilmesi için aktarýlmasý dusunulen parametreleri barýndýrabilecek buyuklukte tanýmlanmasý gereklidir.ayrýca yýgýnýn yordam cagýrma islemlerinde donus adreslerini tuttugu da dusunuldugunde,yýgýn üzerinde tutulacak(unutulacak)
herhangi bir deger,cagýrýlan noktaya donusu imkansýz hale getirecektir.
benzer sekilde yýgýndan gereginden fazla degerin alýnmasý da ayný sonucu dogurur.kýsaca yýgýn kullanýmý sýrasýnda her PUSH isleminin karsýlýgý olarak bir POP islemi veya buna esdeger sonuc uretecek turde baska islemlerin yapýlamsý gerekmektedir.yýgýn üzeriden aktarýlacak parametrelerin yordam cagýrýlmadan önce PUSH komutlarý yardýmýyla yýgýna yerlestirilmesi gerekmektedir.
ancak bundan sonra CALL komutu kullanýlarak programýn akýsý ilgýlý yordamdan devam edicek sekilde degistirlebilir.cagýrýlan yordamýn içinden yýgýnda bulunan parametrelere erismek için POP komutu kesinlikle kullanýlmamalýdýr.
SP yazmacýn degeri kullanýcý tarafýndan degistirilerek yýgýn uzerinde herhangi bir alana erisýlmeye calýsýlmasý daha da buyuk problemlere neden olacaktýr.
bu durumda yýgýn alaný uzerideki parametrelere erisim için BP yazmacýndan yararlanýlmalýdýr.

yýgýn uzerinden parametre aktarma islemi için kullanýlacak iskelet program yapýsý tablo 12-1 de verilmistir.ilk asm isimmli programdan WORD1 ve WORD2 isimli degiskenler yýgýna PUSH komutlarý yardýmýyla yerlestirilmistir.(satýr 18-19).
parametrelerin yýgýna yerlesmesini takýben onlar uzerinde islem yapýlmasý planlanan ALTPRG isimli,far olarak tanýmlanmýs harýcý yordam (satýr 2)CALL komutu (satýr 20)ile cagýrýlmýstýr.cagýrýlan yordamýn FAR tanýmlanmýs olmasý nedeniyle donus adresi olarak yýgýnda kesim ve goreli konum ikilisinin saklanmasý gerekecektir.
buna göre yýgýnýn buyuklugunun ihitiyacý karsýlayacak bicimde belirlenmesi gerekmektedirç
ÝLK.ASM isimli program komut satýrýndan cagýrýldýgý için geri donebilmek üzere yýgýnda 2 word donus adresi zaten yerlestirilmis durumdadýr.(satýr 14,16).buna ek olarak yýgýna parametre olarak yerlestýrýlmýs olan 2 word daha vardýr
cagýrýlan FAR yordamdan geri donulebilmesi için gerekli olan 2 word'luk donus adresi de dusunuldugunde toplam 6 word'luk yýgýn alanýnýn kullanýldýgý acýkca görülmektedir.
bu kullaným mýktarýna bakarak yýgýný ucu ucuna yetecek kadar tanýmlamak dogru bir yaklasým degildir.
Zira ilerleyen baslýklar altýnda anlatacagýmýz -sistemin surekliligini saglamak üzere belirli aralýklarla devreye girip cýkan -kesmeler de yýgýn alanýný kullanýlmaktadýr.
kesmeler de dýkkate alýnarak yýgýnýn ihtiyacýn uzerinde bir deger verilerek tanýmlanmasý alýsýlmýs bir durumdur.ancak bu degeri çok buyuk secmek de dogru bir yaklasým degildir.programcý,yýgýn buyuklugunu zaman içerisinde kazanacagý deneyim ile uygulamanýn gereklerine dikkat ederek belirlemelidir.
-
-
-
-
-SEMA
-
-
-
-


parametreli aktarýcagýmýz yordam cagýrýldýgý anda yýgýnýn durumu incelendiginde tablo 12-2'de gösterilen yapý ile karsýlasýlacaktýr.

-SEMA

ilk.asm isimli programda (tablo 12-1,satýr 4)yýgýn 16 adet word olarak tanýmlanmýstýr.(20H adet byte).buna göre yýgýn kesimi içinde isaretci olarak kullanýlan SP yazmacýnýn degeri 001EH olacaktýr.(yýgýna ilk yerlestirilen deger 001EH-001FH adresli bytlara yerlesmýstýr.)komut satýrýna dönusu saglamak için donus kesim adresi ve göreli konum adresleri de yýgýna yerlestýrýlmýstýr.
ardýndan WORD1 ve WORD2 isimli word tipindeki degiskenler yýgýna parametre olarak yerlestýrýlmýstýr.(satýr 18-19).FAR olarak tanýmlý harýcý yordamýn cagrýlmasýyla programýn 21.satýrdaki komutu islemek için donebilmesini saglamak üzere gerekli kesim ve goreli konum degerleri de yýgýna yerlestýrýlecektir.(satýr 20)


simdi parametrelere eriserek bunlar uzerinde islem yapacak olan program parcasýnýn  iskelet yapýsýný tablo 12-3 uzerinde inceleyelim
yýgýn üzerinden parametrelere erismek isteyen yordam bu islemi yaparken BP yazmacýndan yararlanmaktadýr.
BP yazmacý,sp yazmacý gibi yýgýn alanýnýn baslangýcýný gösteren SS kesim yazmacý ile birlikte kullanýlýr.
ancak BP yazmacýnýn,SP yazmacýndan farklý olarak degeri kullanýcý tarafýndan degistirilebilmektedir.
bu sayede kullanýcý yýgýný bir dizi gibi kullanabilmekte ve yýgýn üzerinde istedigi veriye rahatlýkla ulasabilmektedir.

-
-
-
-
-12-3
-
-
-
-
tablo 12-3 de verilen yordamýn hemen basýnda BP yazmacýnýn da yýgýn üzerinde saklandýgý görülmektedir.(satýr 6)cagýrýlan yordamýn görevini yerine getirmek üzere kullandýgý yazmaclarýn o anda sahip olduklarý degerler cagýran yordam acýsýndan önemli olabilir.
bu yazmaclardaki degerlerin bozulmasýný engellemek üzere yýgýnda saklanmalarý ve cagýran yordama geri donulmeden hemen önce yýgýna konus sýrasýnýn tersinde ilgili yazmaclara aktarýlmalarý gereklidir.
bu sayede cagýrýlan kodlar kendilerini cagýran kodlarýn calýsmalarýný engellemez ve hemen hemen her türlü program ile birlikte kullanýlabilirler.BP yazmacýnýn degeri de PUSH komutu ile yýgýn üzerinde geldigi yerde kullanýmda olabilecegi dusuncesi ile saklanmaktadýr.
Altprg isimli yordama gelindiginde yýgýnýn durumunu tablo 12-4 uzerinde inceleyecek olursak


-12-4

BP yazmacý PUSH edildikten sonra SP yazmacþideðeri bu yazmaca yüklenmektedir
(satýr 7). Böylece BP yazmacmýn deðeri kullanýcý kontrolünde belirlenerek yýðýna bir dizi
gibi eriþme þansý elde edilmiþtir. Yýðm adresleri incelendiðinde yýðýnýn altmda kalan de-
ðerlere eriþmek için BP yazmacmdaki deðerin arttýrýlmasý gereklidir. Bunu yaparken eri-
þilmesi düþünülen parametrenin adresi hesaplanmalýdýr. Wordl isimli deðiþkene eriþebil-
mek için [BP+8] adresli168 bellek içeriðine bakmak yeterli olacaktýr (satýr 9). Yýðm ala-
nýndaki parametrelere BP yazmacý 114riþilmesinin en büyük avantajý, herhangi bir PUSH
iþlemi yapýlmasý durumunda bile Ig1P yazmacmýn deðerinin deðiþmemesidir. Böylece yý-
ðýndaki parametrelere eriþmekShi yeniden adres hesabý yapýlmasý gerekmez. Çaðýrýlan
yordamdan dönülmeden öncebrogramm baþýnda kullamlan PUSH BP komutunun karþý-
lýðý olan POP BP komutunQP69 kullanýlmasý (satýr 1 2) gerekir. Bu sayede SP yazmacý
dönüþ adreslerinin olduðu noktayý gösterir hale gelmiþ olur ve RET (satýr 1 3) komutuyla
çaðýran yordama dönülür. RET komutu doðasý gereði dönüþ adreslerini ilgili yazmaçlara
yerleþtirdikten sonkþP yazmacmýn deðerini de ayarlayacaktýr. Bu iþlemden sonra yýðýnýn
durumu Tablo 1 Iþie gösterildiði gibi olacaktýr. Bu noktada sorulmasý gereken önemli
bir soru vardýr. rametre olarak aktarýlmak üzere yýðýna yerleþtirilen deðerleri oradan



çekmek/almak kimin sorumluluk' unda olacaktýr ?" Bu sorunun cevabý uygulamanýn nite-
liðine baðli olarak deðiþebilir. Eðer çaðýnlan yordam, aktanlan parametreler üzerinde iþ-
lem yapmýþ ve bunun sonuçlarýný yine yýðmda parametreler° 7° için aynlmýþ alþ4azarak
kendisini çaðýran programa aktarmayý amaçlamýþsa bu deðerleri rðýndan çekmek yine
çaðýran tarafin görevidir. Çaðýran taraf bunlan uygun þekilde POP ederenerekli deðiþ-
kenlere veya yazmaçlara aktararak iþlemlerine devam edecektir. Ancak çInlan yordam-
dan dönüldüðünde yýðýn üzerindeki deðerler önemli deðillerse iki olasillk oluþmaktadýr.
Ýlk olasýlýk bu deðerleri yýðýna koyanýn kaldýrmasýdýr Parametrelefi rðýna koymak için
kullanýlan PUSH komutu kadar POP komutu ile bunlar yýðmdan geri almýrlar. Bu iþlem
programýn yavaþlamasýna neden olacaktýr. Zira her POP iþlemi için rðýna eriþilmekte, bir
word alýnarak bir yazmaç veya bellek alanýna aktanlmaktandmdan SP yazmacmýn de-
ðeri (POP komutu tarafmdan) 2 byte arttýnlmaktadr. Üstelinu iþlem hiç kullanýlmaya-
cak olan veriyi çekmek (kýsaca programýn doðru bir þelgeesonlanmasým saðlayacak dö-
nüþ adreslerine ulaþmak) için yapýlmaktadýr. Diðer olal'ýlc hem daha kolay hem de baþa-
rýmý ilkin göre daha iyi bir çözüm sunmaktadýr. Bu çözüm, çaðýnlan yordamm geri dön-
mesini saðlayan RET komutunun yanýna yazýladdeðer ile SP yazmacýmn deðerinin arttý-
nlmasýdýr. Örneðimizde (satýr 13) RET 4 komutu, önce dönüþ adreslerini yýðindaR Ý 4144-u Et
rak (SP —0018H deðerini alýr) ardmdan SP<-SP + 4 iþlemini yapýlmaktadýr (SN-001CH"


-tablo 12-5


                                                                                          
//12.3 EXTRN/PUBLIC Kullanýmý ile Parametre Aktarýmý
      Daha önceki örneklerimizde EXTRN/PUBLIC kullanýmý ile nasýl parametre aktarýl-
      dýðý konusu üzerinde durmuþtuk. Bu þekilde parametre aktarýmýnda adrIcullanýl-
      dýðý (by reference) için daha fazla veri, daha az zahmet ile karþý tarafa'aktanlabil-     mektedir. Tablo 12-6'da verilen iskelet kod parçasýnda Ack isimli 100 - 9te büyüklü-      ðünde bir dizi ve Eleman isimli deðiþken PUBLIC tanýmlanarak (Taýr 2) baþka bir
-     mektedir. Tablo 12-6'da verilen iskelet kod parçasýnda Ack isimli 100 - 9te büyüklü-      ðünde bir dizi ve Eleman isimli deðiþken PUBLIC tanýmlanarak (Taýr 2) baþka bir
      ðünde bir dizi ve Eleman isimli deðiþken PUBLIC tanýmlanarak (Taýr 2) baþka bir
      kod tarafýndan kullanýlabilir kýlýnmýþtýr.


   Benzer þekilde Tablo 12-7'deki program parçasýnda, EXTRN tanýmý ile Ack isimli
   byte, Eleman isimli word tipinde (satýr 2) harici veri alanlarýna eriþilmek istendiði
   belirtilmiþtir.
   Dikkat edýk olursa Tablo 12-6' da verilen iskelet kod parçasýnda tanýmlý olan Ack
   isimli dý yapýsýndaki deðiþkene Tablo 12-7'de verilen iskelet kod parçasýndaki
   Altprg3§mli yordamýn eriþerek bir takým iþlemler yapmasý hedeflenmiþtir. Ancak
   Alt            yordam, üzerinde iþlem yapacaðý dýzinin baþlangýç adresini ve veri ti-
   piqb ý ilmesine raðmen dizinin uzunluðu (eleman sayýsý) hakkýnda bir bilgiye sahip
       ildir. O zaman eleman sayýsýnýn da Altprg isimli yordama bir þekilde parametre
,arak aktarýlmasý gerekecektir. Hatýrlanacaðý üzere az sayýda parametre aktarmak
   için yazmaçlarýn kullanýlmasý en uygun yöntemdir. Ancak bu örneðimizde bu yön-
   temin kullanýlmasý mümkün deðildir. Zira Altprg isimli yordam ile Tablo 12-6'da
   verilen program arasmda (Ack isimli deðiþkeni paylaþmak dýþýnda) bir kodvl ýýi"Ssiu EtWindows'u etkinleþt



   yoktur. Kýsaca Tablo 12-6'da ki program dilimi içinde Altprg isimli yordam çaðýnl-  madýðý için çaðýrma iþlemi öncesinde bir yazmaç yardýmý ile Eleman sayýsýnýn para-  metre olarak aktarýlmasý da mümkün olamaz. O zaman dizinin boyutun elirleyen
-  madýðý için çaðýrma iþlemi öncesinde bir yazmaç yardýmý ile Eleman sayýsýnýn para-  metre olarak aktarýlmasý da mümkün olamaz. O zaman dizinin boyutun elirleyen
-  metre olarak aktarýlmasý da mümkün olamaz. O zaman dizinin boyutun elirleyen
   Eleman deðiþkenin de EXTRN/PUBLIC tanýmlarý kullanýlarak palaþý masý ve
   Altprg isimli yordamýn ihtiyaç duyduðu anda bu deðiþken kullanmasý lanmalýdýr.

-tablo


Her iki kod parçasý kendi     na çalýþabilir olmakla beraber Tablo 12-7'deki progra-
mýn, Tablo 12-6'da tammlý Ack isimli veri alanýný kullanabilmesi için her iki koda
ait OBJ uzantýlý dosyalln birlikte Link iþleminden geçirilmesi gereklidir'''.
                , //bi51 



örnek EXE programlar bu kýsýmda bazi basit uygulamalar EXE program tipinde kodlanacak ve adým adým nasýl derlendigi,ne sekilde sonuc ürettiði ve nasýl degerlendirilmesi gerektigi acýklanacaktýr.

Örnek 9-1
16 bit uzunluðunda pozitif iki tam sayý toplayan programý EXE tipinde yaza . Tah- 
min edilebileceði gibi pozitif 16 bit'lik iki sayýnýn toplamý, 16 bit ile ifade, edilebi- 
lenden daha büyük bir deðer olabilir. Bu durumda sonucun bir üst birini cinsinden, 
yani 32 bit olmasý gerekecektir. Buna göre programmýzda toplanacak)sayýlarý ASA- 
YISI ve BSAYISI, sonucu ise TOPLAM isimli deðiþkenlerde tutmak•içýn gerekli veri 
tanýmlamalarýn yapalým. Toplama iþleminin AX yazmacý kuphlarak yapýlmasý 
daha etkin bir program yazmamýzý saðlayacaktýr. TOPLAM isimirdeðiskenin 32 bit 
olacaðý ve 8086 mikroiþlemcisi ile bir seferde en fazla 16 bit'iþjem yapýlabildiði dik- 
kate alýndýðýnda yazmaç dolaylý, baz göreli veya doðrudan (ýdisli adresleme teknik- 
lerinden birinin kullanýlmasý uygun olacaktýr. n



------------------------------------------------------------------------------------------------
; PROGRAM : Örnek 9-1.ASM
; 16 bit tanýmlý ASAYISI ve B SAYISI isimli deðiþkenleri toplayarak elde edilen sonucu TOPLAM isimli 32 bit'lik deðiþkene yerleþtiren EXE program
------------------------------------------------------------------------------------------------

       		PAGE 60,80
       		TITLE 16 BITLIK POZITIF IKI SAYININ TOPLANMASI 
STACKSG 	SEGMENT PARA STACK 'STACK'
       		DW 10 DUP(?)
STACKSG 	ENDS
DATASG 		SEGMENT PARA 'DATA'
ASAYISI 	DW 1234H      ; Giriþ/Çýkýþ deðerlerinin veri alaný üzerinde ilk deðer atamasý yapýlmaktadýr.
BSAYISI 	DW OABCDH     
TOPLAM 		DD OH          ; TOPLAM deðiþkeninin ilk deðeri sýfýr yapýlýr
DATASG 		ENDS
CODESG 		SEGMENT PARA 'CODE'
       		ASSUME CS:CODESG, DS:DATASG, SS:STACKSG
ANA    		PROC FAR
------------------------------------------------------------------------------------------------

; Dönüþ için gerekli olan deðerler yýðýnda saklanýyor
------------------------------------------------------------------------------------------------

       PUSH DS
       SUB AX, AX 
       PUSH AX
------------------------------------------------------------------------------------------------

; DATASG ismiyle tanýmll kesim alanýna eriþebilmek için gerekli tanýmlar
------------------------------------------------------------------------------------------------

       MOV AX ,DATASG 
       MOV DS, AX
------------------------------------------------------------------------------------------------

; Toplama iþleminin gerçekleþtirildiði kod bloðu
------------------------------------------------------------------------------------------------
		//toplam degiskeninin basladýgý adresi sý ya atarýz
       LEA SI, TOPLAM; SI TOPLAM deðiþkenin baþladýðý adresi belirler
       //A sayýsýný Ax e atarsýn
       MOV AX, ASAYISI; AX yazmacý ASAYISI'nýn deðerini tutar 
       //B sayisini Bx e atarsýn
       MOV BX, BSAYISI; BX yazmacý BSAYISI'nýn deðerini tutar
       //A ile B sayisini toplarsýn
       ADD AX, BX; toplamýn sonucu AX yazmacýnda bulunur sonuç ToPLAmýn en az anlamlý word'ünde oluþan eldeyi yüksek anlamlý word'e yaz
       //toplam ý Sý ya yani toplam degiskeninin basladýgý adrese atarsýn
       MOV [SI], AX     
       //16 bitlik toplama oldugu için tasma olursa bir sonraki adrese eklersin                  
       ADC WORD PTR [SI+2] ,0
       RET
ANA    ENDP
CODESG ENDS
       END ANA        ; Programýn baþlangýç noktasý
-----------------------------------------------------------------------------------------------------
9. ASSEMBLY PROGRAM TIPLERI
                                                ti
       Assembly dilinde programlar, genel kodlama tarzýna, kesim tammlamalþita ve ke-
       simlerin düzenlerine baðlý olarak iki farklý tipte yazýlabilirler. Bu tipli dretilen ça-
       lýþtýrýlabilir dosyalarýn uzantýlarýndan adlanm almakta olup EXE 4COM olarak
       bilinirler. Her iki tip assembly programda da ayný komut seti kuÞtlmakla birlikte
       birbirlerinden oldukça farklý özelliklere sahiptirler.

       ilerleyen bölümlerde EXE ve COM tipi programlarýn genel özelliklerinden söz edi-
       lerek her tip için verilen örnekler detaylý olarak açýldanac EXE ve COM program-
       larýn özellikleri bir karþýlaþtýrma tablosu yardýmýyla özene ecektir.
                                      •

9.1 EXE Tipindeki Assembly Programlarýn Genel Özellikleri                                               ti
                    EXE tipindeki programlar ayrýk kesim düzeninde)çalýþmak üzere tasarlanmýþlardýr. •
                    Diðer deyiþle bir EXE programýn bellekte kerid‘iine ait yýðýn, kod ve veri kesimleri 
                    (eðer tanýmlanýrsa ek kesim de) olabilir. EXE programýn bellekte ayný anda eriþebi- 
                    leceði kesim sayýsý, kesim yazmaçlarýmn sayýsý ile sýnýrlýdýr. Ancak EXE program- 
                    larýn boyutlarý kesim boyu ile sýnýrlý olmadýðý için COM tipindeki programlara na- 
                    zaran çok daha fazla bellek kullamrlar. EXE programlarda, ikincil bellek birimleri 
                    üzerinde saklanan kodlarýnýn baþýnda 512 byte büyüklüðünde EXE Header141 olarak 
                    adlandýrýlan bir kontrol bloðu bý j‘maktadýr. Kesimlerin ayrý ayrý tanýmlanabilme- 
                    sinin bir sonucu olarak daha fazlg veri üzerinde iþlem yapabilen daha uzun assembly 
                    kodlarýnýn yazýlmasýna olanslbterir.
                    EXE programýn iskelet yktisý Tablo 9-1'de verilmiþtir. Program yazarken yaygýn 
                    kullanýlan kodlama tek derine uymak her zaman faydalýdýr. Böylece rahat anlaþýlýr 
                    ve kolay takip edil bilir kodlar üretilebilir. Yazýlan programa daha sonra bakýldý- 
                    ðýnda yapýlanlar' aþýlabilmesi ise program içinde bulunan açýklama satýrlarýnm 
                    sayýsýyla orantýlýsly. Programýn ne amaçla yazýldýðý, ne tür veri üzerinde iþlem yap- 
                    týðý, baþka bir 4simde bulunan özel amaçlý kodlardan yararlanýyorsa bunlarýn ne 
                    yaptýklarý,•içerisinde bir problemi çözmek için özel bir uygulama yapýlmýþ ise
                    bunun neclo yapýldýðý gibi bilgilerin açýklama satýrlarý ile koda dahil edilmesi fay- 
                    dalý olacaktýr. Açýklama satýrlannýn derleyici tarafýndan kod olarak yorumlanmasmý 
                    engellemek amacýyla ";" sembolünden yararlanýlýr. Bu sembolden sonra yazýlacak 
                    olaýcl4er türlü metin açýklama satýrý olarak deðerlendirilecektir (Tablo 9-1. 14, 18, 
                    2*)atýrlar).
                  tx,


          Tablo 9-1: EXE tipindeki programýn iskelet yapýsý
1             PAGE  60,80
2             TITLE exe tipinde yazýlmýþ bir assembly programýn iskelet yapýsý (.)/(-\/
3     Stacksg SEGMENT PARA STACK •STACK
4             DW    32 DUP (?)                     (0 •
5     Stacksg ENDS
6     Datasg  SEGMENT PARA 'DATA'
7     sayi    DB ?
8     Eleman  DW ?
9
10    Datasg  ENDS
11    Codesg  SEGMENT PARA 'CODE'
12            ASSUME CS:Codesg, DS:Datasg, SS:StacksQ
13    Basla   PROC FAR
14    ; Programýn geri dönüþ adreslerini yýðýn olarak tanýmlanmýþ kesimde sakla
15            PUSH DS
16            XOR AX, AX
17            PUSH AX
18    ; Deðiþkenlerin tanýmlandýðý kesime eriþmek için gereken iþlemler
19            MOV AX, Datasg
20            MOV DS, AX
21    ; Programýn esas kodu bu satýrdan itibaren baþlamaktadýr
22
23
24            RETF142
25    Basla   ENDP
26    Codesg  ENDS
27            END   Bala

Programýn derleyici taraflildan derlendikten sonra bir çýkýþýnýn almmasý gerekiyor 
ise bunun sayfa üzerinde nesil basýlmasý istendiði PAGE sözde komutu ile belirlenir. 
Bu komut tercihe baðh/lAarak kullanýlýr (satýr 1). Benzer biçimde derleyicinin üret- 
tiði LST uzantýlý dosyanýn her sayfanýn baþýnda bir baþlýk satýn yazýlmasý istenirse
(satýr 2) TITLE þ6üle komutundan yararlaruhr.
        ti
Daha önce de -6-6-guladýðýmýz gibi EXE uzantýlý programlarda ayrýk kesim düzenini
kullanýlmakfgr. Buna göre yýðm (satýr 3), veri (satýr 6) ve kod (satýr 11) kesimleri 
ayrý ayn tdmmlannuþtýr143. Tablo 9-1'de görülen iskelet yapýda Stacksg isimli kesim 
PARArtaçfi»mý uyarmca on altýya tam bölünebilir bir adresten baþlayacak, STACK ta- 
nýmýl!!ýý Liir gereði olarak da yýðýn organizasyonunda kullanýlacaktýr (satýr 3). Taným- 
lari)kesim içinde yýðýn için kullanýlacak bellek alaný programýmýzýn ihtiyaçlarý göz



önüne alýnarak belirlenmelidir'44. Yýðýn üzerinde yapýlan iþlemlerin word temelli ol- 
duðu düþünüldüðünde yýðm boyutunun DW kullanýlarak tanýmlamasý daha doðru 
olacaktýr (satýr 4). Her kesim kendi içinde bir blok olarak deðerlendirilm ýr. Bu 
nedenle her kesim sonu ENDS sözde komutu ile belirlenmelidir (satýr 5, 10.„ 6).

Yüksek seviyeli programlama dilleri kullanýlarak geliþtirilen uygula4arda olduðu 
gibi, üzerinde iþlem yapýlacak deðiþkenlerin uygun veri tipleri ve büyüklükler 
ile tanýmlamasý gereklidir. Deðiþken, ister dýþarýdan bir okuýþaznma iþlemi ile 
alýnsm/verilsinus, isterse veri alaný içinde ilk deðer atamasý yapýlmýþ olsun, veri ke- 
siminde uygun þekilde tanýmlanmandýr (satýr 6-10).
                           ' V
Yüksek seviyeli programlama dillerinde olduðu gibi ass - 1115' y dilinde yazýlmýþ prog- 
ramlarda da en az bir yordam bulunmalýdýr. Ancak pro u ýk ýihtiyaçlarý, modüler ola- 
bilmesi, rahat takip edilebilir ve anlaþýlabilir olmasmý kðiamak üzere yapý bir ana yor- 
dam ve bunun tarafýndan çaðýnlarak kullanýlan diðeNrdýmcý yordamlardan oluþacak 
þekilde düzenlenebilir. Buna göre programýn, kod kesimi içinde (satýr 11-26) en az bir 
PROC tanýmý yapýlmandýr (satýr 13). EXE tipirldeki programlarda bir tane yordam var 
ise bu kontrolü elinde bulunduran temel parça olarak deðerlendirilir ve FAR tipinde 
tanýmlanýr Bir program içinde birden fazla —özellikle— FAR tammli yordam olmasý 
durumda hangisinin ana yordam olduðu nasýl belirlenecektir? Gerek bu problemi çöz- 
mek, gerek ise programýn baþlangýç noktasýný belirlemek üzere assembly programýn 
tipine, sahip olduðu yordam tiplerine ve sarlanna bakýlmaksýzýn END sözde komu- 
tunu takiben ilk çaliþtýnlacak olaQ rdamm ismi yazýlýr (satýr 27).



EXE tipindeki programlarda r kesimin ayn ayn tanýmlamasý nedeni ile bunlardan 
hangisinin hangi kesim ya cý tarafýndan gösterileceðinin belirtilmesi gereklidir. 
ASSUME sözde komuta hatir 12) bu amaçla kullanýlýr. Örnek yapýmýzda CS yaz- 
macý Codesg, DS yazm crDatasg ve nihayet SS yazmacý Stacksg isimleri ile taným- 
lanmýþ kesimleri göstex cek þekilde ayarlanmýþtýr.
Yazdýðýmýz prograrý> erlenip link edildikten sonra elde edilen EXE uzantýlý dosyanýn 
adý komut satýndayazýlarak program çalýþtýnhr. Programýn görevini yerine getirmesini

       •

takiben bizim onu çaðýrdýðmýýz noktaya (genellikle komut satýrma) geri dönmesi ge- 
rekir. Yordamm/programm geri dönebilmesi için yýðýn üzerinde dönüþ adresinin sak- 
lanmasý gerekir. Yýðýn üzerinde saklanan dönüþ adresleri, çaðýnlan yordankm%on ko- 
mutu olan RETF komutunun (satýr 24) iþletilmesi ile yýðmdan çekilin DiðelYdeyiþ ile 
programýn komut satýnndan çaliþtýnlmasý kesimler arasý (intersegmetfikordam ça- 
ðýrma iþlemi gibi deðerlendirilir. FAR tammli (EXE tipinde) yordamln dönüþ adresi 
kesim ve göreli konum ikilisinden oluþacaktýr. Bu ikili sayesinde nt*r.oiþlemcinin ad- 
resleyebileceði bellek araliðýnda herhangi bir noktaya dönüþ yarfikýbilir. Dönüþ adre- 
sini belirleyen kesim ve göreli konum deðerlerinin yýðýna yer4eþtirilmesi programýn 
kontrolünü elinde bulunduran ana yordamýn sorumluluðuduf
EXE tipindeki programlarýn tasanmlan nedeniyle ana yord çaliþmaya baþlatýldýðmda 
DS yazmacý dönüþ için gerekli olan kesim adresini baktadýr. Öncelikli olarak bu 
adresin dönüþ kesim adresi olarak yýðmda saldanmasn4Zicir (satýr 15). Daha sonra dö- 
nüþ için gereken göreli konum adresi yýðýna konmalýihr. Bu deðer de tasarým uyarýnca 
OOOOH olacaktýr (satýr 16-17). Yýðma göreli kon a esini uygun deðer ile koyabilmek 
üzere PUSH iþleminden önce AX yazmacý XOR ý emin tabii tutularak sýfýrlanýr.



EXE tipindeki programlarda ASSUME komutu her ne kadar kesim yazmaçlarý ile 
programcmýn tanýmladýðý kesimleri eþlese de, DS kesim yazmacý özel durumundan 
ötürü uygun kesimi göstermez. Bu durumda ana yordam içinde programcmýn DS 
yazmaç deðerini kendi tanýmladýðý veri kesimini gösterecek biçimde düzeltmesi ge- 
rekir. DS yazmacýnm Datasg isimli kesimi göstermesini saðlamak üzere ilgili kesim 
adresi AX yazmacýndan yararlanýlarak DS yazmacýna aktarýlýr (satýr 19-20). DS ke- 
sim yazmacýna ilgili kesim adrefinin tek bir komut ile aktarýlamamasýnýn arkasýnda 
komut kümesindeki kýsýt yatmaktadýr. Tammlý komut kümesi, kesimi belirleyen eti- 
ketin doðrudan bir kesim gdzmacýna aktanlmasma izin vermediði için AX yazma- 
cýndan yararlamlýr. Ýlk4þfemde AX yazmacýna aktarýlan Datasg isimli veri kesim 
adresi (satýr 19) ikinc:i-klemde DS yazmacýna atanmaktadýr (satýr 20).
Bu temel iþlemlerin tamamlanmasý ile yordamýn yapmasý gereken diðer iþlemlerin prog- 
ramcý tarafýndan lamnasma geçilir. Her yordam bir RET/RETF komutu ile sonlana- 
caktýr. Böylece daha önce (satýr 15-17) yýðýna koyduðumuz dönüþ adresleri yýðmdan 
ahnarak prohýn sonlandýnlacaktýr. Tanunlý yordam ENDP (satýr 25) ve kod kesimi 
ENDS s** komutlan (satýr 26) ile bitirilir. Programýn bittiðini gösterir END sözde 
kodu ise programdaki en son komuttur. END sözde komutunu takiben programýn hangi 
noktaýtan (yordamdan) çalýþmaya baþlayacaðýný belirten etiket yazýlmandýr (satýr 27)




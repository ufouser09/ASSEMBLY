�rnek EXE programlar bu k�s�mda bazi basit uygulamalar EXE program tipinde kodlanacak ve ad�m ad�m nas�l derlendigi,ne sekilde sonuc �retti�i ve nas�l degerlendirilmesi gerektigi ac�klanacakt�r.

�rnek 9-1
16 bit uzunlu�unda pozitif iki tam say� toplayan program� EXE tipinde yaza . Tah- 
min edilebilece�i gibi pozitif 16 bit'lik iki say�n�n toplam�, 16 bit ile ifade, edilebi- 
lenden daha b�y�k bir de�er olabilir. Bu durumda sonucun bir �st birini cinsinden, 
yani 32 bit olmas� gerekecektir. Buna g�re programm�zda toplanacak)say�lar� ASA- 
YISI ve BSAYISI, sonucu ise TOPLAM isimli de�i�kenlerde tutmak�i��n gerekli veri 
tan�mlamalar�n yapal�m. Toplama i�leminin AX yazmac� kuphlarak yap�lmas� 
daha etkin bir program yazmam�z� sa�layacakt�r. TOPLAM isimirde�iskenin 32 bit 
olaca�� ve 8086 mikroi�lemcisi ile bir seferde en fazla 16 bit'i�jem yap�labildi�i dik- 
kate al�nd���nda yazma� dolayl�, baz g�reli veya do�rudan (�disli adresleme teknik- 
lerinden birinin kullan�lmas� uygun olacakt�r. n



------------------------------------------------------------------------------------------------
; PROGRAM : �rnek 9-1.ASM
; 16 bit tan�ml� ASAYISI ve B SAYISI isimli de�i�kenleri toplayarak elde edilen sonucu TOPLAM isimli 32 bit'lik de�i�kene yerle�tiren EXE program
------------------------------------------------------------------------------------------------

       		PAGE 60,80
       		TITLE 16 BITLIK POZITIF IKI SAYININ TOPLANMASI 
STACKSG 	SEGMENT PARA STACK 'STACK'
       		DW 10 DUP(?)
STACKSG 	ENDS
DATASG 		SEGMENT PARA 'DATA'
ASAYISI 	DW 1234H      ; Giri�/��k�� de�erlerinin veri alan� �zerinde ilk de�er atamas� yap�lmaktad�r.
BSAYISI 	DW OABCDH     
TOPLAM 		DD OH          ; TOPLAM de�i�keninin ilk de�eri s�f�r yap�l�r
DATASG 		ENDS
CODESG 		SEGMENT PARA 'CODE'
       		ASSUME CS:CODESG, DS:DATASG, SS:STACKSG
ANA    		PROC FAR
------------------------------------------------------------------------------------------------

; D�n�� i�in gerekli olan de�erler y���nda saklan�yor
------------------------------------------------------------------------------------------------

       PUSH DS
       SUB AX, AX 
       PUSH AX
------------------------------------------------------------------------------------------------

; DATASG ismiyle tan�mll kesim alan�na eri�ebilmek i�in gerekli tan�mlar
------------------------------------------------------------------------------------------------

       MOV AX ,DATASG 
       MOV DS, AX
------------------------------------------------------------------------------------------------

; Toplama i�leminin ger�ekle�tirildi�i kod blo�u
------------------------------------------------------------------------------------------------
		//toplam degiskeninin baslad�g� adresi s� ya atar�z
       LEA SI, TOPLAM; SI TOPLAM de�i�kenin ba�lad��� adresi belirler
       //A say�s�n� Ax e atars�n
       MOV AX, ASAYISI; AX yazmac� ASAYISI'n�n de�erini tutar 
       //B sayisini Bx e atars�n
       MOV BX, BSAYISI; BX yazmac� BSAYISI'n�n de�erini tutar
       //A ile B sayisini toplars�n
       ADD AX, BX; toplam�n sonucu AX yazmac�nda bulunur sonu� ToPLAm�n en az anlaml� word'�nde olu�an eldeyi y�ksek anlaml� word'e yaz
       //toplam � S� ya yani toplam degiskeninin baslad�g� adrese atars�n
       MOV [SI], AX     
       //16 bitlik toplama oldugu i�in tasma olursa bir sonraki adrese eklersin                  
       ADC WORD PTR [SI+2] ,0
       RET
ANA    ENDP
CODESG ENDS
       END ANA        ; Program�n ba�lang�� noktas�
-----------------------------------------------------------------------------------------------------
9. ASSEMBLY PROGRAM TIPLERI
                                                ti
       Assembly dilinde programlar, genel kodlama tarz�na, kesim tammlamal�ita ve ke-
       simlerin d�zenlerine ba�l� olarak iki farkl� tipte yaz�labilirler. Bu tipli dretilen �a-
       l��t�r�labilir dosyalar�n uzant�lar�ndan adlanm almakta olup EXE 4COM olarak
       bilinirler. Her iki tip assembly programda da ayn� komut seti ku�tlmakla birlikte
       birbirlerinden olduk�a farkl� �zelliklere sahiptirler.

       ilerleyen b�l�mlerde EXE ve COM tipi programlar�n genel �zelliklerinden s�z edi-
       lerek her tip i�in verilen �rnekler detayl� olarak a��ldanac EXE ve COM program-
       lar�n �zellikleri bir kar��la�t�rma tablosu yard�m�yla �zene ecektir.
                                      �

9.1 EXE Tipindeki Assembly Programlar�n Genel �zellikleri                                               ti
                    EXE tipindeki programlar ayr�k kesim d�zeninde)�al��mak �zere tasarlanm��lard�r. �
                    Di�er deyi�le bir EXE program�n bellekte kerid�iine ait y���n, kod ve veri kesimleri 
                    (e�er tan�mlan�rsa ek kesim de) olabilir. EXE program�n bellekte ayn� anda eri�ebi- 
                    lece�i kesim say�s�, kesim yazma�lar�mn say�s� ile s�n�rl�d�r. Ancak EXE program- 
                    lar�n boyutlar� kesim boyu ile s�n�rl� olmad��� i�in COM tipindeki programlara na- 
                    zaran �ok daha fazla bellek kullamrlar. EXE programlarda, ikincil bellek birimleri 
                    �zerinde saklanan kodlar�n�n ba��nda 512 byte b�y�kl���nde EXE Header141 olarak 
                    adland�r�lan bir kontrol blo�u b� j�maktad�r. Kesimlerin ayr� ayr� tan�mlanabilme- 
                    sinin bir sonucu olarak daha fazlg veri �zerinde i�lem yapabilen daha uzun assembly 
                    kodlar�n�n yaz�lmas�na olanslbterir.
                    EXE program�n iskelet yktis� Tablo 9-1'de verilmi�tir. Program yazarken yayg�n 
                    kullan�lan kodlama tek derine uymak her zaman faydal�d�r. B�ylece rahat anla��l�r 
                    ve kolay takip edil bilir kodlar �retilebilir. Yaz�lan programa daha sonra bak�ld�- 
                    ��nda yap�lanlar' a��labilmesi ise program i�inde bulunan a��klama sat�rlar�nm 
                    say�s�yla orant�l�sly. Program�n ne ama�la yaz�ld���, ne t�r veri �zerinde i�lem yap- 
                    t���, ba�ka bir 4simde bulunan �zel ama�l� kodlardan yararlan�yorsa bunlar�n ne 
                    yapt�klar�,�i�erisinde bir problemi ��zmek i�in �zel bir uygulama yap�lm�� ise
                    bunun neclo yap�ld��� gibi bilgilerin a��klama sat�rlar� ile koda dahil edilmesi fay- 
                    dal� olacakt�r. A��klama sat�rlann�n derleyici taraf�ndan kod olarak yorumlanmasm� 
                    engellemek amac�yla ";" sembol�nden yararlan�l�r. Bu sembolden sonra yaz�lacak 
                    ola�cl4er t�rl� metin a��klama sat�r� olarak de�erlendirilecektir (Tablo 9-1. 14, 18, 
                    2*)at�rlar).
                  tx,


          Tablo 9-1: EXE tipindeki program�n iskelet yap�s�
1             PAGE  60,80
2             TITLE exe tipinde yaz�lm�� bir assembly program�n iskelet yap�s� (.)/(-\/
3     Stacksg SEGMENT PARA STACK �STACK
4             DW    32 DUP (?)                     (0 �
5     Stacksg ENDS
6     Datasg  SEGMENT PARA 'DATA'
7     sayi    DB ?
8     Eleman  DW ?
9
10    Datasg  ENDS
11    Codesg  SEGMENT PARA 'CODE'
12            ASSUME CS:Codesg, DS:Datasg, SS:StacksQ
13    Basla   PROC FAR
14    ; Program�n geri d�n�� adreslerini y���n olarak tan�mlanm�� kesimde sakla
15            PUSH DS
16            XOR AX, AX
17            PUSH AX
18    ; De�i�kenlerin tan�mland��� kesime eri�mek i�in gereken i�lemler
19            MOV AX, Datasg
20            MOV DS, AX
21    ; Program�n esas kodu bu sat�rdan itibaren ba�lamaktad�r
22
23
24            RETF142
25    Basla   ENDP
26    Codesg  ENDS
27            END   Bala

Program�n derleyici taraflildan derlendikten sonra bir ��k���n�n almmas� gerekiyor 
ise bunun sayfa �zerinde nesil bas�lmas� istendi�i PAGE s�zde komutu ile belirlenir. 
Bu komut tercihe ba�h/lAarak kullan�l�r (sat�r 1). Benzer bi�imde derleyicinin �ret- 
ti�i LST uzant�l� dosyan�n her sayfan�n ba��nda bir ba�l�k sat�n yaz�lmas� istenirse
(sat�r 2) TITLE �6�le komutundan yararlaruhr.
        ti
Daha �nce de -6-6-gulad���m�z gibi EXE uzant�l� programlarda ayr�k kesim d�zenini
kullan�lmakfgr. Buna g�re y��m (sat�r 3), veri (sat�r 6) ve kod (sat�r 11) kesimleri 
ayr� ayn tdmmlannu�t�r143. Tablo 9-1'de g�r�len iskelet yap�da Stacksg isimli kesim 
PARArta�fi�m� uyarmca on alt�ya tam b�l�nebilir bir adresten ba�layacak, STACK ta- 
n�m�l!!�� Liir gere�i olarak da y���n organizasyonunda kullan�lacakt�r (sat�r 3). Tan�m- 
lari)kesim i�inde y���n i�in kullan�lacak bellek alan� program�m�z�n ihtiya�lar� g�z



�n�ne al�narak belirlenmelidir'44. Y���n �zerinde yap�lan i�lemlerin word temelli ol- 
du�u d���n�ld���nde y��m boyutunun DW kullan�larak tan�mlamas� daha do�ru 
olacakt�r (sat�r 4). Her kesim kendi i�inde bir blok olarak de�erlendirilm �r. Bu 
nedenle her kesim sonu ENDS s�zde komutu ile belirlenmelidir (sat�r 5, 10.� 6).

Y�ksek seviyeli programlama dilleri kullan�larak geli�tirilen uygula4arda oldu�u 
gibi, �zerinde i�lem yap�lacak de�i�kenlerin uygun veri tipleri ve b�y�kl�kler 
ile tan�mlamas� gereklidir. De�i�ken, ister d��ar�dan bir oku��aznma i�lemi ile 
al�nsm/verilsinus, isterse veri alan� i�inde ilk de�er atamas� yap�lm�� olsun, veri ke- 
siminde uygun �ekilde tan�mlanmand�r (sat�r 6-10).
                           ' V
Y�ksek seviyeli programlama dillerinde oldu�u gibi ass - 1115' y dilinde yaz�lm�� prog- 
ramlarda da en az bir yordam bulunmal�d�r. Ancak pro u �k �ihtiya�lar�, mod�ler ola- 
bilmesi, rahat takip edilebilir ve anla��labilir olmasm� k�iamak �zere yap� bir ana yor- 
dam ve bunun taraf�ndan �a��nlarak kullan�lan di�eNrd�mc� yordamlardan olu�acak 
�ekilde d�zenlenebilir. Buna g�re program�n, kod kesimi i�inde (sat�r 11-26) en az bir 
PROC tan�m� yap�lmand�r (sat�r 13). EXE tipirldeki programlarda bir tane yordam var 
ise bu kontrol� elinde bulunduran temel par�a olarak de�erlendirilir ve FAR tipinde 
tan�mlan�r Bir program i�inde birden fazla ��zellikle� FAR tammli yordam olmas� 
durumda hangisinin ana yordam oldu�u nas�l belirlenecektir? Gerek bu problemi ��z- 
mek, gerek ise program�n ba�lang�� noktas�n� belirlemek �zere assembly program�n 
tipine, sahip oldu�u yordam tiplerine ve sarlanna bak�lmaks�z�n END s�zde komu- 
tunu takiben ilk �ali�t�nlacak olaQ rdamm ismi yaz�l�r (sat�r 27).



EXE tipindeki programlarda r kesimin ayn ayn tan�mlamas� nedeni ile bunlardan 
hangisinin hangi kesim ya c� taraf�ndan g�sterilece�inin belirtilmesi gereklidir. 
ASSUME s�zde komuta hatir 12) bu ama�la kullan�l�r. �rnek yap�m�zda CS yaz- 
mac� Codesg, DS yazm crDatasg ve nihayet SS yazmac� Stacksg isimleri ile tan�m- 
lanm�� kesimleri g�stex cek �ekilde ayarlanm��t�r.
Yazd���m�z prograr�> erlenip link edildikten sonra elde edilen EXE uzant�l� dosyan�n 
ad� komut sat�ndayaz�larak program �al��t�nhr. Program�n g�revini yerine getirmesini

       �

takiben bizim onu �a��rd��m��z noktaya (genellikle komut sat�rma) geri d�nmesi ge- 
rekir. Yordamm/programm geri d�nebilmesi i�in y���n �zerinde d�n�� adresinin sak- 
lanmas� gerekir. Y���n �zerinde saklanan d�n�� adresleri, �a��nlan yordankm%on ko- 
mutu olan RETF komutunun (sat�r 24) i�letilmesi ile y��mdan �ekilin Di�elYdeyi� ile 
program�n komut sat�nndan �ali�t�nlmas� kesimler aras� (intersegmetfikordam �a- 
��rma i�lemi gibi de�erlendirilir. FAR tammli (EXE tipinde) yordamln d�n�� adresi 
kesim ve g�reli konum ikilisinden olu�acakt�r. Bu ikili sayesinde nt*r.oi�lemcinin ad- 
resleyebilece�i bellek arali��nda herhangi bir noktaya d�n�� yarfik�bilir. D�n�� adre- 
sini belirleyen kesim ve g�reli konum de�erlerinin y���na yer4e�tirilmesi program�n 
kontrol�n� elinde bulunduran ana yordam�n sorumlulu�uduf
EXE tipindeki programlar�n tasanmlan nedeniyle ana yord �ali�maya ba�lat�ld��mda 
DS yazmac� d�n�� i�in gerekli olan kesim adresini baktad�r. �ncelikli olarak bu 
adresin d�n�� kesim adresi olarak y��mda saldanmasn4Zicir (sat�r 15). Daha sonra d�- 
n�� i�in gereken g�reli konum adresi y���na konmal�ihr. Bu de�er de tasar�m uyar�nca 
OOOOH olacakt�r (sat�r 16-17). Y��ma g�reli kon a esini uygun de�er ile koyabilmek 
�zere PUSH i�leminden �nce AX yazmac� XOR � emin tabii tutularak s�f�rlan�r.



EXE tipindeki programlarda ASSUME komutu her ne kadar kesim yazma�lar� ile 
programcm�n tan�mlad��� kesimleri e�lese de, DS kesim yazmac� �zel durumundan 
�t�r� uygun kesimi g�stermez. Bu durumda ana yordam i�inde programcm�n DS 
yazma� de�erini kendi tan�mlad��� veri kesimini g�sterecek bi�imde d�zeltmesi ge- 
rekir. DS yazmac�nm Datasg isimli kesimi g�stermesini sa�lamak �zere ilgili kesim 
adresi AX yazmac�ndan yararlan�larak DS yazmac�na aktar�l�r (sat�r 19-20). DS ke- 
sim yazmac�na ilgili kesim adrefinin tek bir komut ile aktar�lamamas�n�n arkas�nda 
komut k�mesindeki k�s�t yatmaktad�r. Tamml� komut k�mesi, kesimi belirleyen eti- 
ketin do�rudan bir kesim gdzmac�na aktanlmasma izin vermedi�i i�in AX yazma- 
c�ndan yararlaml�r. �lk4�femde AX yazmac�na aktar�lan Datasg isimli veri kesim 
adresi (sat�r 19) ikinc:i-klemde DS yazmac�na atanmaktad�r (sat�r 20).
Bu temel i�lemlerin tamamlanmas� ile yordam�n yapmas� gereken di�er i�lemlerin prog- 
ramc� taraf�ndan lamnasma ge�ilir. Her yordam bir RET/RETF komutu ile sonlana- 
cakt�r. B�ylece daha �nce (sat�r 15-17) y���na koydu�umuz d�n�� adresleri y��mdan 
ahnarak proh�n sonland�nlacakt�r. Tanunl� yordam ENDP (sat�r 25) ve kod kesimi 
ENDS s** komutlan (sat�r 26) ile bitirilir. Program�n bitti�ini g�sterir END s�zde 
kodu ise programdaki en son komuttur. END s�zde komutunu takiben program�n hangi 
nokta�tan (yordamdan) �al��maya ba�layaca��n� belirten etiket yaz�lmand�r (sat�r 27)




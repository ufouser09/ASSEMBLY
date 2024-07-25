------------------------------------------------------------------------------------
  
  PROGRAM : Örnek 10-1.ASM
  Kesim içindeki yordamý çaðýran EXE tipinde program
------------------------------------------------------------------------------------
         PAGE 60,80                                           
         TITLE Sayinin kuvvetini hesaplar                   
STACKSG SEGMENT PARA STACK 'STACK'                         
         DW 10 DUP(?)                                      
STACKSG ENDS 
DATASG SEGMENT PARA 'DATA'                            
                             
------------------------------------------------------------------------------------

------------------------------------------------------------------------------------

 ;Kullanacaðýmýz deðiþkenler
------------------------------------------------------------------------------------

SAYI  DW 2
UST   DW 10                      
SONUC DW 0 
DATASG ENDS
CODESG SEGMENT PARA 'CODE'
      ASSUME CS:CODESG, DS:DATASG, SS:STACKSG 
ANA   PROC FAR
------------------------------------------------------------------------------------

 ;Dönüþ için gerekli olan deðerler yýðýnda saklanýyor
------------------------------------------------------------------------------------

      PUSH DS 
      SUB AX, AX 
      PUSH AX         
------------------------------------------------------------------------------------

 ;DATASG ismiyle tanýmlý kezlýýi alanýna eriþebilmek için gerekli tanýmlar
------------------------------------------------------------------------------------

      MOV AX, DATASG
      MOV DS, AX  
------------------------------------------------------------------------------------

 ;iþleminin gerçekleþtirildiði kod bloðu
------------------------------------------------------------------------------------

      MOV CX, UST  ;UST ve SAYI parametreleri yazmaçlarda
      MOV BX, SAYI
      CALL USTAL     ; Yordam çaðýrma
      MOV SONUÇ AX ; Iþlemin sonucu AX yazmacý üzerinden aktarýlýyor 
      RET       ; dön
ANA   ENDP
------------------------------------------------------------------------------------

; üst alma islemini gerçekleþtiren yordam
------------------------------------------------------------------------------------

USTAL PROC NEAR 
    	MOV AX, 1 
Ll:   	MUL   BX       ; çarpma iþlemi AX üzerinden yapýlýyor 
    	LOOP L1
  		RET        ; çaðýrýldýðýn noktaya dön
USTAL ENDP
CODESG ENDS
      END ANA     ; programýn baþlangýç noktasý
------------------------------------------------------------------------------------
//ASSEMBLY PROGRAMIN TEMEL TASLARI:YORDAM VE MAKRO
//her program içerisinde en az bir tane ana yordam olmasý gerektiðini vurguladýk


//YORDAM ÖZELLÝKLERÝ
yordam PROC sözde komutu ile baslayýp ENDP sözde komutu ile sonlanan bir þekilde tanýmlanmaktadýr
yordamlarýn ayný kesim içinden(intraSegment) ve farkli kesim içerisinden(intersegment)kullanabilmeleri için sýrasýyla NEAR ve FAR olarak tanýmlanmalarý gerekmektedir.
yordamlarýn çaðrýldýklarý yere donebilmeleri için en son komut olarak RET(near tanýmlý yordamlarda) veya RETF (FAR tanýmlý yordamlarda)kullanýlmaktadýr.
ancak ASSEMBLY dili derleyicisi FAR olarak tanýmlý yordamlar RET ile sonlandýrýlsa bile bunu RETF oalrak degerlendirecek ve gerekli duzenlemeleri kendi içinde gerceklestirecektir.
bu nedenle yordam tanýmýýnýn ne olduguna bakýlmaksýzýn RET ile yordamýn sonlandýrýlmasý bir alýskanlýk olmustur.


//yordam tanýmý en genel sekli asagýda gösterilmistir.

yordam_ismi    PROC{NEAR|FAR}
				;yordamýn kodu
				RET
yordam ismi     ENDP


//KESÝM ÝÇÝ YORDAM CAGIRMA
//kesim içi yordam cagýrma(intrasegment call) olarak adlandýrýlan bu tip kullanýmda caðýran ve cagrýlan ayný kesim içinde yer alýr.
//bunu örnek üzerinden inceleyebilmek için ayný kesim içinde tanýmlanmýs iki yordam sahýp oldugumuzu,bunlardan ANA isimli olanýn ilk olarak çalýstýrýlan(yani kontrolu elýnde bulunduran yordam)oldugunu,
//USTAL isimli olanýn ise ANA tarafýndan cagrýlan ve NEAR olarak tanýmlanmýs bir yordam oldugunu dusunelim.


cdseg		segment para 'CODE'
ustal		proc near**//2-buraya gelir
			mov ax,1
			mul bx
			loop l1
			ret//3-sonra burdaki kodu isledikten sonra
ustal		endp
ANA 		proc far
			
			....
			mov cx,ust
			mov bx,sayi
			call ustal**//1-bu proc near'a gider
			mov sonuc,ax//4-kod buradan devam eder
			
			.....
			ret
ana			endp
cdseg		ends
			end ana


//KESÝM ÝÇÝNDEKÝ YORDAMIN CAGRILMASI(intrasegment call)
//cagrýlan yordam sayinin ust ile belirlenen kuvvetini hesaplayan islemini yapmakta ve call ustal komutu yardýmýyla cagrýlmaktadýr.cagýrma islemiyle programýn akýsý ustal ýsýmlý yordamýn oldugu adrese aktarýlmakta(1)
//islemler gerceklestirildikten sonra (2) ret komutunun calýstýrýlmasýyla birlikte cagýrma isleminin yapýldýgý kod parcasý içinde yer alan ve call komutunu takip eden satýra geri dönülmektedir.boylece ana isimli yordamýn kaldýgý noktadan islemlere devam edebilmesini saglamaktadýr(3)
//kesim içi cagýrma isleminin gerceklesmesi sirasýnda bize dogrudan islem olarak görünmeyen,daha dogrusu kullanýlan call komutunun geregý olarak otomatýk olarak yerine getirilen bazý ara islemler de vardýr.bu islemlerin neler oldugunu ve ne amacla yapýldýgýný maddeler halinde acýklayalým
.
.
.
.
.
.
------------------------------------------------------------------------------------
//yordamýn ayný program içinde birden fazla yerde çaðrýlmasý durumundaki akýþ incelendiginde her cagýrmada kontrolun dogrudan ustal ýsýmlý yordamýn oldugu adrese aktarýldýgý,
//islemlerýn tamamlanmasýna takiben ret komutu ile geri donuldugu görülür.bu sayde yordamlar kac kere çaðrýlýrsa çagrýlsýn hep ayný adresten calýstýrýldýklarý ýcýn programýn kodu buyumez.

//ancak her cagýrma islemi geri donebilmek için gerekli adreslerin yýgýna atýlmasý,kontrolun aktarýlacagý göreli konum degerinin ýp yazmacýna atanmasý ve islemin bitimini takiben donus için gerekli adres degerinin yýgýndan cekilmesi gibi islemleri de içermesi nedeniyle ister istemez belli bir gecikmeye neden olur. 
.
.
.
.
.
.
.
.
.
.
------------------------------------------------------------------------------------

//AYNI YORDAMIN KOD ÝÇÝNDE BÝRDEN FAZLA YERDE CAGRILMASI
kesim içi yordam kullanýmý konusundaki bilgilerimizi pekistirmek için ve durumu calýsan program parcalarý uzerinden incelemek üzere ornek 10-1'den yararlanalým

//ÖRNEK 10-1
sekil 10-1'de verilen ve bir sayinin kuvvetini almayý saglayan USTAL isimli yordamý EXE tipinde bir program içinde kullanalým.
ustal isimli yordam giris verilerini 
BX ve CX yazmaclarý uzerinden almakta islem sonucunda hesaplanan degeri ise AX yazmacý üzerinde tutmaktadýr.
üst almak için carpma isleminden yararlanýlacaktýr.

programýmýzdaki SAYÝ,UST ve SONUC isimli degiskenler word olarak tanýmlanmýstýr.
burada SAYÝ ve UST degerleri buyuk secilecek olursa elde edilecek deger SONUC isimli degiskene sýgmayacak kadar buyuk olacaktýr.
buna göre,programýmýzý test ederken giris degerlerini özenle secmek gerekecektir







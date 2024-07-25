----------------------------------------------------------------------------------------------------------------

karsýlastýrma islemleri 
a,b,c isimli 3 kenarýn bir ücgen belirttiði bilinmektedir.ücgenin tipini (eskanar=1,ikizkenar=2,cesitkenar=3)bulan exe tipinde assembly programýný yazalým.
----------------------------------------------------------------------------------------------------------------

start

a=4;---->al
b=5;----->bl
c=3;------>cl

stop;
----------------------------------------------------------------------------------------------------------------

jmp komutlarý ile atlanýlan yerler akýs diyagramýnda noktalý yuvarlaklarla gösterilmektedir

kullanýlan degiskenlerin tanýmlanmasý

datasg 		segment para 'veri'
a			db 4
b			db 5
c			db 3
týp 		db ?
datasg 		ends

stacksg		segment para stack 'yýgýn'
			dw 12 dup(?)
stacksg		ends

codesg		segment para  'kod'
			assume ds:datasg,ss:stacksg,cs:codesg
ana			proc far
//dönus için gerekli degerler yýgýnda saklanýyor
			push ds
			xor ax,ax
			push ax
//datasg ismiyle tanýmlý kesim alanýna erisebilmek için gerekli tanýmlar
			mov ax,datasg
			mov ds,ax
----------------------------------------------------------------------------------------------------------------

			//ilk önce ücgenimizin 3 kenarýný da al bl ve cl olmak üzere yerlestiriyoruz
			mov al,a;(sýrasýyla a,b,c ücgen kenarlarý al,bl,cl byte tipindeki yazmaclara yerlestirilir)
			mov bl,b;
			mov cl,c;
			//ilk önce a ve b kenarýmýzý karsýlastýrýyoruz
			cmp al,bl;(al ve bl yazmac degerleri karsýlastýrýlýr)
			//a ve b esitse j1 etiketine atlarýz
			je j1;(al bl ye esitse j1 etiketine atlanýr)
			// a ve c esit degilse bu sefer b ve c yi karsýlastýrýrýz
			----------------------------------------------------------------------------------------------------------------

			cmp bl,cl;(al,bl ye esit degilse bl ile cl yazmac degerleri karsýastýrýlýr)
			// a ve c esit degil fakat b ve c esitse ücgenimiz ikizkenar ucgendir bu sefer de j2 etiketine atla denir
			je j2;(bl cl ye esitse j2 etiketine atlanýr)
			//a ile b esit degil bi de a ve c esit degilse bu sefer de a ve c yi karsýlastýr diyoruz
			----------------------------------------------------------------------------------------------------------------

			cmp al,cl;(bl,cl ye esit degilse al ile cl yazmac degerleri karsýlastýrýlýr)
			//a ve c esitse bu sefer de ikizkenar ucgendir o zaman j2 etiketine atla deriz.
			je j2;(al ve cl esitse j2 etiketine atlanýr);
			//eger a ve b sonra b ile c sonra a ve c esit degilse de bu sefer çesitkenar ucgendir.
			mov týp,3;(al cl ye esit degilse ucgen cesitkenardýr);
			----------------------------------------------------------------------------------------------------------------
			//kodun sonuna gider.
			jmp son;(týp bulunmustur program sonuna atlanýr)
			----------------------------------------------------------------------------------------------------------------
			
			
			// a ve b esitse buraya geldik burda da a ve c yi karsýlastýrýyoruz
		j1:	cmp al,cl;(al ve bl esit oldugu için buraya gelindi.burada al ve cl karsýlastýrýlýr)
			
			//a ve b esit fakat a ve c esit degilse bu sefer ucgenimiz ikizkenar ucgendir o zaman j2 etiketine atla deriz
			jne j2;(al ve cl esit degilse j2 etiketine atlanýr)
			// a ve c de esitse týp 1 dir bu da eskanar ücgen oldugu anlamýna gelir.
			mov týp,1(al ve cl esitse ucgen eskanardýr)
			//programý sonlandýrmak için son etiketine atlanýr.
			jmp son;(týp bulunmustur program sonuna atlanýr)
			
		j2:	mov týp,2;(diger durumlarda ise ucgen ikizkenardýr)
		
		son:retf
		ana endp
		codesg ends
			end ana		
			
			//sayfa 522										

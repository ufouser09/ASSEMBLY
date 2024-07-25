----------------------------------------------------------------------------------------------------------------

kars�last�rma islemleri 
a,b,c isimli 3 kenar�n bir �cgen belirtti�i bilinmektedir.�cgenin tipini (eskanar=1,ikizkenar=2,cesitkenar=3)bulan exe tipinde assembly program�n� yazal�m.
----------------------------------------------------------------------------------------------------------------

start

a=4;---->al
b=5;----->bl
c=3;------>cl

stop;
----------------------------------------------------------------------------------------------------------------

jmp komutlar� ile atlan�lan yerler ak�s diyagram�nda noktal� yuvarlaklarla g�sterilmektedir

kullan�lan degiskenlerin tan�mlanmas�

datasg 		segment para 'veri'
a			db 4
b			db 5
c			db 3
t�p 		db ?
datasg 		ends

stacksg		segment para stack 'y�g�n'
			dw 12 dup(?)
stacksg		ends

codesg		segment para  'kod'
			assume ds:datasg,ss:stacksg,cs:codesg
ana			proc far
//d�nus i�in gerekli degerler y�g�nda saklan�yor
			push ds
			xor ax,ax
			push ax
//datasg ismiyle tan�ml� kesim alan�na erisebilmek i�in gerekli tan�mlar
			mov ax,datasg
			mov ds,ax
----------------------------------------------------------------------------------------------------------------

			//ilk �nce �cgenimizin 3 kenar�n� da al bl ve cl olmak �zere yerlestiriyoruz
			mov al,a;(s�ras�yla a,b,c �cgen kenarlar� al,bl,cl byte tipindeki yazmaclara yerlestirilir)
			mov bl,b;
			mov cl,c;
			//ilk �nce a ve b kenar�m�z� kars�last�r�yoruz
			cmp al,bl;(al ve bl yazmac degerleri kars�last�r�l�r)
			//a ve b esitse j1 etiketine atlar�z
			je j1;(al bl ye esitse j1 etiketine atlan�r)
			// a ve c esit degilse bu sefer b ve c yi kars�last�r�r�z
			----------------------------------------------------------------------------------------------------------------

			cmp bl,cl;(al,bl ye esit degilse bl ile cl yazmac degerleri kars�ast�r�l�r)
			// a ve c esit degil fakat b ve c esitse �cgenimiz ikizkenar ucgendir bu sefer de j2 etiketine atla denir
			je j2;(bl cl ye esitse j2 etiketine atlan�r)
			//a ile b esit degil bi de a ve c esit degilse bu sefer de a ve c yi kars�last�r diyoruz
			----------------------------------------------------------------------------------------------------------------

			cmp al,cl;(bl,cl ye esit degilse al ile cl yazmac degerleri kars�last�r�l�r)
			//a ve c esitse bu sefer de ikizkenar ucgendir o zaman j2 etiketine atla deriz.
			je j2;(al ve cl esitse j2 etiketine atlan�r);
			//eger a ve b sonra b ile c sonra a ve c esit degilse de bu sefer �esitkenar ucgendir.
			mov t�p,3;(al cl ye esit degilse ucgen cesitkenard�r);
			----------------------------------------------------------------------------------------------------------------
			//kodun sonuna gider.
			jmp son;(t�p bulunmustur program sonuna atlan�r)
			----------------------------------------------------------------------------------------------------------------
			
			
			// a ve b esitse buraya geldik burda da a ve c yi kars�last�r�yoruz
		j1:	cmp al,cl;(al ve bl esit oldugu i�in buraya gelindi.burada al ve cl kars�last�r�l�r)
			
			//a ve b esit fakat a ve c esit degilse bu sefer ucgenimiz ikizkenar ucgendir o zaman j2 etiketine atla deriz
			jne j2;(al ve cl esit degilse j2 etiketine atlan�r)
			// a ve c de esitse t�p 1 dir bu da eskanar �cgen oldugu anlam�na gelir.
			mov t�p,1(al ve cl esitse ucgen eskanard�r)
			//program� sonland�rmak i�in son etiketine atlan�r.
			jmp son;(t�p bulunmustur program sonuna atlan�r)
			
		j2:	mov t�p,2;(diger durumlarda ise ucgen ikizkenard�r)
		
		son:retf
		ana endp
		codesg ends
			end ana		
			
			//sayfa 522										

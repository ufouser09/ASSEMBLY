               �ekil 25-16: E�ik de�er kontrol� ak�� diyagram�


; COv tipi programda veri kesiminin kod kesiminden once yerle�tirildi�i ve 
; 3WP kodu �le ana yordwrA w�land��� yap� kullan�lm��t�r.

ODESG     SEGMENT PARA 'kod'
          ORG 100h
          ASSuME DS:CODESG, 55:CODESG, CS:CODESG
BASLA:    JMP SICAKLIK
N         DW 365
DIZI      DB 365 DUP(?)
ESIK      DB -20
SONUC     DB ?
SICAKLIK PROC NEAr
          XoR SI, SI              ;DIZI indis yazmas� SI s�f�rlan�r. 
          MOV CX, N               ;DIZI'nin boyutu N, CX yazmac�na at�l�r. 
          MoV AL, ES�k            ;esik degiskenin de�eri AL i�erisine konur. 
DON:      CmP SI, CX              ;SI ile CX kar��la�t�r�l�r.
          jAE YANLIS              ;SI, CX de�erine k���k e�itse YANLIS 
                                  ;et�ketine atlan�r.
          cmp AL, DIZI[SI]        ;SI, CX de�erinden buyukse AL ile D1ZI'nin 
                                  ;SI indisindeki eleman kar��la�t�r�l�r. 
          JG DOGRU                ;AL, DIZI'nin SI indisli eleman�ndan 
                                  ;buy�kse DOGRU etiketine atlan�r.
          �NC SI                  ;DIZI byte tamml� oldu�u i�in SI 
                                  ;1 artt�r�l�r.
          JMP DON                 ;Cevrim ko�uluna gitmek i�in DON etiketine 
                                  ;atlan�r.
YANLIS:   MOV SONUC, 0            ;SONUC de�i�kenine 0 de�eri atanarak
          JMP SON                 ;SON etiket�ne atlamr. Yani es�k de�erin 
                                  ;alt�nda bir de�er bulunamam��t�r.
DOGRU:    MOV SONUC, 1            ;SoNUC de�i�kemne 1 de�eri atan�r. Yani



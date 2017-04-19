
A. GİRİŞ

   Bu projede kütüphaneler kullanılarak soy ağacı oluşturma işlemi gerçekleştirilmiştir.
   Girişler için komut satırına parametre olarak dosya adı girilmektedir. Örnek olarak:  ./deneme fam1.txt fam2.txt
   Birinci parametre program adını, ikinci parametre okunacak dosya adını, üçüncü parametre yazilacak dosya adını belirtmektedir.
   Proje içinde fields ve dllist kütüphaneleri kullanılmıştır.

B.İÇİNDEKİLER

   1. Readme	: Bu dosya.
   2. proje1.c	: Proje işlemlerinin gerçekleştiği dosya.
   3. fields.h	: Dosya okumak için gerekli kütüphane
   4. fields.c  : Fields kütüphanesi kullanımı için derlenmesi gereken C dosyası
   5. dllist.h	: Dosyadan okunan verilerin tutulması için gerekli kütüphane.
   6. dllist.c  : Dllist kütüphanesi kullanımı için derlenmesi gereken C dosyası
   7. Makefile	: Derleme işlemi için yazılmış dosya.

C. DERLEME

   Linux işletim sistemi üzerine gerekli dosya ve kütüphanelerin bulunduğu klasörü taşınır.
   Komut satırından gerekli klasörün içine girilir. make komutu ile dosya derlenir

D. ÇALIŞTIRMA

		Çalıştırma 2 şekilde yapılabilmekter.

		  1-)
			-Derleme işleminin yapıldığı yerde "./proje1 <okunacakDosya.txt> yazilacakDosya.txt" yazılarak programın sonucu yazılacakDosya ya yazdırılır.
			-Derleme işleminin yapıldığı yerde "./proje1 <okunacakDosya.txt" yazılarak programın sonucu terminalde görülür.
   		 2-)    Derleme işleminin yapıldığı yerde "./proje1 okunacakDosya.txt yazilacakDosya.txt" yazılarak program çalıştırılmaktadır.

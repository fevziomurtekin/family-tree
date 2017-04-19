
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fields.h"
#include "dllist.h"

struct Person {
 char  name[20];
 char  sex[10];
 char father[20];
 char mother[20];
 struct {
   char  name[20];
   char  sex[10];
 }children[5];
}person[5];

int main(int argc, char *argv[])
{
  IS ptr;
  Dllist dl, tmp;

  // okunacak ve yazılacak dosyayı terminalden alıyoruz.
  char *okunacakDosya=argv[1];
  char *yazilacakDosya=argv[2];

  int flagperson=0,flagfather=0,sart1=0,sart2=0,sartFather=0,sartFather_of=0,sartMother=0,sartMother_of=0;
  int kisiindeks=0,fchildindeks=-1,mchildindeks=-1,z=0,fz=0,flagsex=0;
  int flag=0,flagc=0;

  /*
   Fields ların özelliklerinde eğer satır boş dönerse , diğer fields a da aynı ifadeyi yazdırıyor.
  Bizde aynısını bir daha yazdırmasın diye iki tane tmp tuttuk(her bir sutun için ayrı) ve onlara atıyoruz.
*/

  char temp[10]="",temp1[10]="";

    FILE *wr;
  char ebeveynCinsiyet[10]="";
  Dllist dtmp,stmp,sl;

  dl = new_dllist();
  sl=new_dllist();
  //Dlllist lerimiz oluşturduk.

  int nf, i;
  ptr = new_inputstruct(okunacakDosya);
  // Terminalden aldığımız .txt uzantılı dosyamızı okumaya başlıyoruz.

  int indis=0;
  while(get_line(ptr) >= 0){
    if(strcmp(temp,ptr->fields[1])==0 && strcmp(temp1,ptr->fields[0])==0)
    nf=get_line(ptr);
    /*
    fields üzelliğinden dolayı iki tane tmp tutmuştuk eğer satırlar birebir aynı ise ;
    Boşluk vardır demektir o yüzden bizde bunu saptayıp, aynı ise bir satır daha atlıyoruz.
    */
    dll_append(dl, new_jval_s(strdup(ptr->fields[0])));
    dll_append(sl,new_jval_s(strdup(ptr->fields[1])));
    //2 tane ağaç oluşturup sutun 1 ve sutun 2 mizi o ağaçlara ekledik.

    strcpy(temp,ptr->fields[1]);
    strcpy(temp1,ptr->fields[0]);
  }

jettison_inputstruct(ptr); // ağaca verilerimizi tamamen aktardıktan sonra okuma işlemimizi sonlandırdık.

dll_traverse(tmp, dl)
{

 /*
 dll_traverse bizim ağacın içinde dolasmamızı saglayan fonksiyondu. Bizde 1.ağacımızda dolaşarak bizden istenen 2 koşulu sağlıyor mu diye baktık.
 */

  if(strcmp(jval_s(dll_val(dll_first(dl))),"PERSON")==0 && strcmp(jval_s(tmp->val),"PERSON")==0){
    flagperson++;
  }
  /*
    İlk şartımız, önce ebeynleri tanıtması gerektiğini söylüyor.Bu nedenden dolayı ilk önce Person olarak başlaması gerekir.
  */
  if((strcmp(jval_s(tmp->val),"FATHER_OF")==0 && flagperson==1) || (strcmp(jval_s(tmp->val),"MOTHER_OF")==0 && flagperson==1)){
  flagfather++;
    if(strcmp(jval_s(tmp->val),"SEX")==0)
    flagsex++;
  /*
    Person ile başlayıp sonrasında mother of veya father ofla devam ettikten sonra;
    Bu satıra girip sonra ki Person da ise mother of veya father ofu tanıyorsa doğrudur.

  */
}
  if((strcmp(jval_s(tmp->val),"MOTHER_OF")==0 && flagperson==2 && flagfather>0 && flagsex==0) || (strcmp(jval_s(tmp->val),"FATHER_OF")==0 && flagperson==2 && flagfather>0 && flagsex==0) ){
  sart1=1;
  /*
  Burada da 2.i girdiği personu kontrol ettik. Eğer yine father of veya mother ofu tanıtıyorsa doğrudur demektir.
  Şart1 i sağlıyor,demektir.
  */
  }
    // Sart 1 saglandı.
  if(strcmp(jval_s(tmp->val),"FATHER")!=0) sartFather++;
  if(strcmp(jval_s(tmp->val),"FATHER_OF")==0) sartFather_of++;
  if(strcmp(jval_s(tmp->val),"MOTHER")!=0) sartMother++;
  if(strcmp(jval_s(tmp->val),"Mother_OF")==0) sartMother_of++;

  if((sartFather>0 && sartFather_of==0) || (sartFather_of>0 && sartFather==0) || (sartMother>0 && sartMother_of==0) || (sartMother_of>0 && sartMother==0)){
  sart2=1;}
  else{ sart2=0;}
  /*
      2.Şartımız ise father of/mother of  diye tanıttığı ebevyni bir daha tanıtmamak. Onun için yukarıda gerekli sorguları yaptık.
  */
}

// ilk dizine atadık.
  dtmp = dl->flink;
  stmp = sl->flink;
  // 2 te yedekleyici dllist oluşturduk

if(sart1!=1 || sart2 !=1){ printf("Hatalı giriş, çevrim var.\n" ); exit(1);
// Şartları sağlamıyorsa "Hatalı giriş,çevrim var hatası verip programdan cıkacak."
}else{
while (dtmp != dl && stmp != sl) {

    // yedekleyici listelerimize teker teker en baştan  önceden eklediğimiz listeyi ona atıyoruz.

    if(strcmp(jval_s(dtmp->val),"PERSON")==0)
    {

      /*
      Teker teker kontrol ediyoruz eğer ilk sutun person ise onu structımzdaki person bölmesine ekliyoruz.
      */

      if(strcmp(ebeveynCinsiyet,"")!=0)
      {
        // buradaki islemimiz ise father ve mother in cinsiyetini bulmak için aşağıda sorgulamızı yapıp burada atıyoruz.
    strcpy(person[kisiindeks-1].sex,ebeveynCinsiyet);
      }


      strcpy(person[kisiindeks].name,jval_s(stmp->val));
       kisiindeks++;

     }

      strcpy(ebeveynCinsiyet,"");
      if(strcmp(jval_s(dtmp->val),"FATHER_OF")==0){
       fchildindeks++;
       strcpy(ebeveynCinsiyet,"Male");
        strcpy(person[kisiindeks-1].children[fchildindeks].name,jval_s(stmp->val));
      }

      /*
      Father_Of ise Babadır ve cinsiyeti Male dir.
      Father of sa yanındaki sütundaki isimler persondaki ismin cocukları olacagından dolayı;
      Father of ın yanındaki sutundaki isimleri childiren structımıza attık.
      */

      if(strcmp(jval_s(dtmp->val),"MOTHER_OF")==0){
       mchildindeks++;
       strcpy(ebeveynCinsiyet,"Female");
       strcpy(person[kisiindeks-1].children[mchildindeks].name,jval_s(stmp->val));

      }

            /*
            Mother_Of ise Babadır ve cinsiyeti Male dir.
            Mother of sa yanındaki sütundaki isimler persondaki ismin cocukları olacagından dolayı;
            Mother of ın yanındaki sutundaki isimleri childiren structımıza attık.
            */

      if(strcmp(jval_s(dtmp->val),"SEX")==0)
      {
       if(strcmp(jval_s(stmp->val),"M")==0){
         strcpy(person[kisiindeks-1].sex,"Male");
       }else{
         strcpy(person[kisiindeks-1].sex,"Female");
       }
      }
            /*
            Burada da diğer personların cinsiyetlerini alıp structa atıyoruz.
            */

       dtmp = dtmp->flink;
       stmp = stmp->flink;
 }

 wr = fopen(yazilacakDosya, "w");
 if(  wr == NULL )
     puts(" dosya acilmadi. !\n"), exit(1);
for(int l=0;l<kisiindeks;l++){
 for(int k=0;k<=fchildindeks;k++){
   for(int j=0;j<=kisiindeks;j++){
if(strcmp(person[l].children[k].name,"")!=0){
 if(strcmp(person[l].children[k].name,person[j].name)==0){
   if(strcmp(person[l].sex,"Male")==0){

       strcpy(person[j].father,person[l].name);
       strcpy(person[l].children[k].sex,person[j].sex);


}else{
       strcpy(person[j].mother,person[l].name);
       strcpy(person[l].children[k].sex,person[j].sex);

}
}
}

}
}
 if(strcmp(person[l].father,"")==0 ){
 strcpy(person[l].father,"Unkown");
}
 if(strcmp(person[l].mother,"")==0){
 strcpy(person[l].mother,"Unkown");}
 printf("\n" );
 z=0;
 flagc=0;
 printf(" %s\n",person[l].name );
 printf("\tSex: %s\n",person[l].sex );
 printf("\tFather: %s\n",person[l].father );
 printf("\tMother: %s\n",person[l].mother );


 /*
 Structa atadığım verileri hizalı bir şekilde dosyaya yazdırdık.
 */

/*
Burasını ise terminal ekranında görmek için yazdırdık.
*/

 while(strcmp(person[l].children[z].name,"")!=0)
 {
   if(flagc==0){
   printf("\tChildren:\n");
   flagc++;
   }
   printf("\t  %s\n",person[l].children[z].name );
   z++;
 }
 printf( "\n" );
 fz=0;
 flag=0;
 fprintf(wr, " %s\n",person[l].name );
 fprintf(wr, "\tSex: %s\n",person[l].sex );
 fprintf(wr, "\tFather: %s\n",person[l].father );
 fprintf(wr, "\tMother: %s\n",person[l].mother );

 while(strcmp(person[l].children[fz].name,"")!=0)
 {
   if(flag==0){
   fprintf(wr, "\tChildren:\n");
   flag++;
   }
   fprintf(wr, "\t  %s\n",person[l].children[fz].name );
   fz++;
 }
 fprintf(wr, "\n" );
}
}
//printf("%s \n", jval_s(tmp->val));
}

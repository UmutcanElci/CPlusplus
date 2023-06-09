#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;
const char filename[50] = "./password.txt";
class passwordInfo{
public:
    string appName;
    string password;
};

void add(){
    ofstream file(filename,ios::app);//Dosya olu?turuldu asl?nda sadece ad? ve nerde oldu?u belli de?il. ayr?ca sadece yazma i?lemlerinde kullan?l?r !
    passwordInfo p1;
    cout << "Uygulamanin adini giriniz : ";
    cin >> p1.appName;
    cout << "\nUygulamanizin sifresini giriniz : ";
    cin >> p1.password;

    file.write(p1.appName.c_str(),p1.appName.size());
    file.write(" ",1);
    file.write(p1.password.c_str(),p1.password.size());
    file.write("\n",1);
    file.close();
    cout << "Verileriniz dosyaya eklendi !" << endl;
    /*
     * G�NCELLEME file.open yerine file ? olu?tururken a�m??da say?l?yor ! Bu y�zden
     * (Dosya olu?turudu somut olarak ismide belli ve ios::app modu sayesinde dosya n?n sonuna eklemeler yap?labilecek.
     * ./ txt dosyas?n? porgram?n olu?tu?u diziye yazar)
     * file.open("password.txt",ios::app) --> (yerine) ofstream file("password.txt",ios::app)
     */

}
void list(){
    ifstream readFile(filename,ios::binary);//Dosya okumak i�in
    char buffer[256];
    if (readFile.is_open()) {
        passwordInfo p1;
        while (readFile.getline(buffer,256)) { // Dosyadan veri okuma
            cout << buffer << endl;
        }
    }

    readFile.close();
}

void deletePassword(const char* filename) {
    if (remove(filename) == 0) {
        cout << "Dosya silindi!" << endl;
    }
    else {
        cout << "Dosya silinemedi!" << endl;
    }
}
void searchByName(){
	
}
void menu(){
	int choice;
	cout << "Ekleme islemi i�in 1 - Listleme islemi icin 2 - Dosyayi silmek icin 3 - uygulamadan cikmak icin 4" << endl;
	cin >> choice;
	
	switch(choice){
		case 1:
			add();
			menu();
			break;
		case 2:
			list();
			menu();
			break;
		case 3:
			deletePassword(filename);
			menu();
			break;
		case 4:
		break;
				
	}
}
int main() {
	menu();
    return 0;
}






/*
 * ios::in: Dosyay? okuma modunda a�ar. Bu modu kullanarak dosya i�eri?ini okuyabilirsiniz.
ios::out: Dosyay? yazma modunda a�ar. Bu modu kullanarak dosyaya veri yazabilirsiniz. Bu modu kullanarak a�?lan bir dosya, varsa i�eri?i silinerek yeniden olu?turulur.
ios::app: Dosyay? sona ekleme modunda a�ar. Bu modu kullanarak dosyan?n sonuna veri ekleyebilirsiniz. Bu modda, dosya a�?ld???nda konum dosyan?n sonunda olur ve her yazma i?lemi sonras?nda konum yine dosyan?n sonuna ta??n?r.
ios::binary: Dosyay? ikili modda a�ar. Bu modu kullanarak dosyan?n i�eri?ini ikili veri olarak okuyabilirsiniz veya ikili veri yazabilirsiniz.
ios::ate: Dosya a�?ld???nda konum dosyan?n sonuna ta??n?r. Bu modu kullanarak dosyan?n i�eri?ini de?i?tirerek sonuna eklemek veya mevcut verileri de?i?tirmek m�mk�nd�r.
ios::trunc: Dosyay? yazma modunda a�ar ve dosya i�eri?ini siler. Bu modu kullanarak dosyay? s?f?rdan olu?turabilirsiniz.
 file.read() fonksiyonu, belirtilen dosyadan belirtilen say?da byte okur ve okunan verileri bir bellek blo?una kopyalar.
 */

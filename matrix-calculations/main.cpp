#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include<math.h>



using namespace std;

template<class tur>

class Matrix
{
protected:
    int satir;
    int sutun;
    tur** matrix;
public:
    //10X10 LUK ICERISINDE SIFIR DEGERI BULUNAN BIR MATRIX
    Matrix()
    {
        satir = sutun = 10;
        matrix = new tur * [satir];
        for (int i = 0; i < satir; i++)
        {
            matrix[i] = new tur[sutun];
            for (int j = 0; j < sutun; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }
    //GONDERILEN STRING E GORE BIRIM MATRIX YADA RANDOM ATAMA YAPAN YA DA DEGER ATAMASI MATRIX OLUSTURUR
    Matrix(int _satir, int _sutun, tur deger)
    {
        satir = _satir;
        sutun = _sutun;
        matrix = new tur * [satir];
        for (int i = 0; i < satir; i++)
        {
            matrix[i] = new tur[sutun];
        }
        if (deger == 'e')
        {
            for (int i = 0; i < satir; i++)
            {
                for (int j = 0; j < sutun; j++)
                {
                    if (i == j)
                    {
                        matrix[i][j] = 1;
                    }
                    else
                    {
                        matrix[i][j] = 0;
                    }
                }
            }
        }
        else if (deger == 'r')
        {
            for (int i = 0; i < satir; i++)
            {
                for (int j = 0; j < sutun; j++)
                {
                    matrix[i][j] = rand() % 256;
                }
            }
        }
        else
        {
            for (int i = 0; i < satir; i++)
            {
                for (int j = 0; j < sutun; j++)
                {
                    matrix[i][j] = deger;
                }
            }
        }
    }
    //MATRİX BOYUT DEGİSTİRME FONKSİYONU
    void resize(int _satir, int _sutun)
    {
        int mn_satir, mn_sutun;
        mn_satir = (_satir < satir) ? _satir : satir;
        mn_sutun = (_sutun < sutun) ? _sutun : sutun;
        Matrix sonuc(_satir, _sutun, 0);
        for (int i = 0; i < mn_satir; i++)
        {
            for (int j = 0; j < mn_sutun; j++)
            {
                sonuc.matrix[i][j] = matrix[i][j];
            }
        }
        for (int i = 0; i < satir; i++)
        {
            delete matrix[i];
        }
        delete matrix;
        matrix = new tur * [_satir];
        for (int i = 0; i < _satir; i++)
        {
            matrix[i] = new tur[_sutun];
            for (int j = 0; j < _sutun; j++)
            {
                matrix[i][j] = sonuc.matrix[i][j];
            }
        }
        satir = _satir;
        sutun = _sutun;
    }
    //MATRIX OPERATOR OVERLOADING ISLEMLERI
    Matrix operator+(Matrix gelen)
    {
        cout << "__________________________________________________________________________" << endl;
        Matrix sonuc(satir, sutun, 0);
        for (int i = 0; i < satir; i++)
        {
            for (int j = 0; j < sutun; j++)
            {
                sonuc.matrix[i][j] = matrix[i][j] + gelen.matrix[i][j];
            }
        }
        return sonuc;
    }
    Matrix operator-(Matrix gelen)
    {
        cout << "__________________________________________________________________________" << endl;
        Matrix sonuc(satir, sutun, 0);
        for (int i = 0; i < satir; i++)
        {
            for (int j = 0; j < sutun; j++)
            {
                sonuc.matrix[i][j] = matrix[i][j] - gelen.matrix[i][j];
            }
        }
        return sonuc;
    }
    Matrix operator*(Matrix gelen)
    {
        cout << "__________________________________________________________________________" << endl;
        Matrix sonuc(satir, sutun, 0);
        for (int i = 0; i < satir; i++)
        {
            for (int j = 0; j <sutun; j++)
            {
                double sum = 0.0;
                for (int m = 0; m < sutun; m++)
                {
                    sum += matrix[i][m] * matrix[m][j];
                }
                sonuc.matrix[i][j] = sum;
                sum = 0;
            }
        }
        return sonuc;
    }
    Matrix operator+(int gelen)
    {
        cout << "__________________________________________________________________________" << endl;
        Matrix sonuc(satir, sutun, 0);
        for (int i = 0; i < satir; i++)
        {
            for (int j = 0; j < sutun; j++)
            {
                sonuc.matrix[i][j] = matrix[i][j] + gelen;
            }
        }
        return sonuc;
    }
    Matrix operator-(int gelen)
    {
        cout << "__________________________________________________________________________" << endl;
        Matrix sonuc(satir, sutun, 0);
        for (int i = 0; i < satir; i++)
        {
            for (int j = 0; j < sutun; j++)
            {
                sonuc.matrix[i][j] = matrix[i][j] - gelen;
            }
        }
        return sonuc;
    }
    Matrix operator*(int gelen)
    {
        cout << "__________________________________________________________________________" << endl;
        Matrix sonuc(satir, sutun, 0);
        for (int i = 0; i < satir; i++)
        {
            for (int j = 0; j < sutun; j++)
            {
                sonuc.matrix[i][j] = matrix[i][j] * gelen;
            }
        }
        return sonuc;
    }
    Matrix operator/(int gelen)
    {
        cout << "__________________________________________________________________________" << endl;
        Matrix sonuc(satir, sutun, 0);
        for (int i = 0; i < satir; i++)
        {
            for (int j = 0; j < sutun; j++)
            {
                sonuc.matrix[i][j] = matrix[i][j] / gelen;
            }
        }
        return sonuc;
    }
    Matrix operator %(int gelen)
    {
        cout << "__________________________________________________________________________" << endl;
        Matrix sonuc(satir, sutun, 0);
        for (int i = 0; i < satir; i++)
        {
            for (int j = 0; j < sutun; j++)
            {
                sonuc.matrix[i][j] = matrix[i][j] % gelen;
            }
        }
        return sonuc;
    }
    Matrix operator^(int gelen)
    {
        cout << "__________________________________________________________________________" << endl;
        Matrix sonuc(satir, sutun, 0);
        for (int i = 0; i < satir; i++)
        {
            for (int j = 0; j < sutun; j++)
            {
                tur sum = 1;
                for (int m = 0; m < gelen; m++)
                {
                    sum *= matrix[i][j];
                }
                sonuc.matrix[i][j] = sum;
            }
        }
        return sonuc;
    }

    //MATRIX IN TRANSPOZU
    Matrix T()
    {
        cout << "__________________________________________________________________________" << endl;
        Matrix sonuc(sutun, satir, 0);
        for (int i = 0; i < sutun; i++)
        {
            for (int j = 0; j < satir; j++)
            {
                sonuc.matrix[i][j] = matrix[j][i];
            }
        }
        return sonuc;
    }
    //MATRIX IN ELEMAN DUZEYINDE CARPILMASINI SAGLAR
    Matrix emul(Matrix gelen)
    {
        cout << "__________________________________________________________________________" << endl;
        Matrix sonuc(satir, sutun, 0);
        for (int i = 0; i < satir; i++)
        {
            for (int j = 0; j < sutun; j++)
            {
                sonuc.matrix[i][j] = matrix[i][j] * gelen.matrix[i][j];
            }
        }
        return sonuc;
    }
    //MATRIX IN DETERMINANTINI HESAPLAR
    double Det()
    {
        double sum = 0.0;
        Matrix sonuc(satir, sutun, 0);
        for (int i = 0; i < satir; i++)
        {
            for (int j = 0; j < sutun; j++)
            {
                sonuc.matrix[i][j] = matrix[i][j];
            }
        }

        if (satir == 1)
        {
            return matrix[0][0];
        }
        for (int i = 0; i < satir; i++)
        {
            sum += matrix[i][0] * matris_parcala(i, 0).Det() * ((i % 2 == 0) ? 1 : -1);
        }
        return sum;
    }
    //MATRIX IN DETERMINANTI VE TERSINI ALMAK ICIN
    Matrix matris_parcala(int num_1, int num_2)
    {
        Matrix sonuc(satir - 1, sutun - 1, 0);
        int item_1, item_2;
        item_1 = 0;
        for (int i = 0; i < satir; i++)
        {
            if (i == num_1)
            {
                continue;
            }
            item_2 = 0;
            for (int j = 0; j < sutun; j++)
            {
                if (j == num_2)
                {
                    continue;
                }
                sonuc.matrix[item_1][item_2] = matrix[i][j];
                item_2++;
            }
            item_1++;
        }
        return sonuc;
    }
    //MATRIX TERSI
    Matrix Inversion()
    {
        Matrix sonuc(satir, sutun, 0);
        for (int i = 0; i < satir; i++)
        {
            for (int j = 0; j < sutun; j++)
            {
                sonuc.matrix[i][j] = matris_parcala(i, j).Det();
            }
        }
        //sonuc.print();
        for (int i = 0; i < satir; i++)
        {
            for (int j = 0; j < sutun; j++)
            {
                sonuc.matrix[i][j] *= ((i + j) % 2 == 1) ? 1 : -1;
            }
        }
        Matrix aa(sonuc.satir, sonuc.sutun, 0);
        for (int i = 0; i < satir; i++)
        {
            for (int j = 0; j < sutun; j++)
            {
                aa.matrix[i][j] = sonuc.T().matrix[i][j];
            }
        }

        //aa.print();
        double ff = Det();
        return aa / ff;
    }
    //MATRIX EL ILE GIRILMEK ISTENIRSE
    Matrix matrix_el_ile_gir()
    {
        cout << "satir sayisini giriniz: ";
        cin >> satir;
        cout << "sutun sayisini giriniz: ";
        cin >> sutun;
        Matrix sonuc(satir, sutun, 0);
        matrix = new tur * [satir];
        for (int i = 0; i < satir; i++)
        {
            for (int j = 0; j < sutun; j++)
            {
                cout << i << ".satir  " << j << ".sutun: ";
                cin >> sonuc.matrix[i][j];
            }
        }
        cout << "girmis oldugunuz matris: " << endl;
        cout << "__________________________________________________________________________" << endl;
        for (int i = 0; i < satir; i++)
        {
            for (int j = 0; j < sutun; j++)
            {
                cout << setw(5) << sonuc.matrix[i][j];
            }
            cout << endl;
        }
        return sonuc;
    }
    //KONSOLA YAZDIRMA
    void print()
    {
        cout << endl;
        cout << satir << "-" << sutun << " matrix" << endl;
        cout << "--------------------------------------------------------------------------" << endl;
        for (int i = 0; i < satir; i++)
        {
            for (int j = 0; j < sutun; j++)
            {
                cout << setw(3) << matrix[i][j] << "  ";
            }
            cout << endl << endl;
        }
    }
    //DOSYAYA YAZDIRMA
    void print(string dosya)
    {
        ofstream myfile;
        myfile.open("file.txt", ios::app);
        myfile << endl;
        myfile << satir << "-" << sutun << "matrix" << endl;
        myfile << "--------------------------------------------------------------------------" << endl;
        for (int i = 0; i < satir; i++)
        {
            for (int j = 0; j < sutun; j++)
            {
                myfile << setw(8) << matrix[i][j];
            }
            myfile << endl << endl;
        }
        myfile.close();
    }
    //MATRIX CLASS I ICIN OLUSTURULMUS MENU
    int matrix_menu()
    {
        int secenek;
        cout << endl << "	" << "MATRIX ISLEMLERI ICIN MENU" << endl;
        cout << "_____________________________________________" << endl;
        cout << "1 ->Toplama Islemi" << endl;
        cout << "2 ->Cikarma Islemi" << endl;
        cout << "3 ->Carpma Islemi" << endl;
        cout << "4 ->Matrixisi sabit sayi ile toplama" << endl;
        cout << "5 ->Matrixten sabit sayi cikarma" << endl;
        cout << "6 ->Matrixi sabit sayi ile carpma" << endl;
        cout << "7 ->Matrix sabit sayi ile bolme" << endl;
        cout << "8 ->Matrixin sabit sayi ile bolumunden kalan" << endl;
        cout << "9 ->us alma" << endl;
        cout << "10->Matrixin transpozu" << endl;
        cout << "11->Matrixi eleman duzeyinde carpma" << endl;
        cout << "12->Matrixin tersi" << endl;
        cout << "13->Matrixin determianti" << endl;
        cout << "14->Matrixin boyutunu degistirme." << endl;
        cout << "15->cikis" << endl;
        cout << "16->Ana menuye geri donmek istiyorum." << endl;
        cout << "Lutfen yapmak istediginiz secenegi giriniz: ";
        cin >> secenek;
        return secenek;
    }

};
template<class tur>

class Image:public Matrix<tur>
{
protected:
    //burada Matrix sinifinda tanimli her şey kullanılabilir.
public:
    Image()
    {
        tur red;
        tur green;
        tur blue;
    }
};
template<class tur>

class Table :public Matrix<int>
{
protected:
    //burada Matrix ve Image sınıfına ait tanimlamalar kullanilabilir.
    tur** table;
public:
    //10X10 LUK VE ICERSINDE SIFIR DEGERLERI  ULUNAN BIR TABLO OLUSTURUR.
    Table()
    {
        satir = sutun = 11;
        table = new tur *[satir];
        for (int i = 0; i < satir; i++)
        {
            table[i] = new tur[sutun];
            for (int j = 0; j < sutun; j++)
            {
                table[i][j] = 0;
            }
        }
        int sutun_isim = 65;
        for (int i = 0; i < 1; i++)
        {
            for (int j = 1; j < sutun; j++)
            {
                table[i][j] = (sutun_isim + j - 1);
            }
        }
    }
    //GONDERILEN R VE C DEGERLERINE GORE TABLO OLUSTURULUR.
    Table(int r, int c, tur d)
    {
        satir = r;
        sutun = c;
        table = new tur * [satir];
        for (int i = 0; i < satir; i++)
        {
            table[i] = new tur[sutun];
            for (int j = 0; j < sutun; j++)
            {
                table[i][j] = d;
            }
        }
        int sutun_isim = 65;
        for (int i = 0; i < 1; i++)
        {
            for (int j = 1; j < sutun; j++)
            {
                table[i][j] = (sutun_isim + j - 1);
            }
        }
        if (d == 'r')
        {
            satir = r;
            sutun = c;
            table = new tur * [satir];
            for (int i = 0; i < satir; i++)
            {
                table[i] = new tur[sutun];
                for (int j = 0; j < sutun; j++)
                {
                    table[i][j] = rand() % 256;
                }
            }
            int sutun_isim = 65;
            for (int i = 0; i < 1; i++)
            {
                for (int j = 1; j < sutun; j++)
                {
                    table[i][j] = (sutun_isim + j - 1);
                }
            }

        }
    }
    //GONDERILEN R VE C DEGERLERINE GORE O TABLODA O KONUMDA BULUNAN DEGERI DONDURUR.
    int itemAt(int r, int c)
    {
        cout << table[r][c] << endl;
        return table[r][c];
    }
    //TABLO KONSOLA YAZDIRMA
    void print()
    {
        for (int i = 0; i < satir; i++)
        {
            if (i != 0)
            {
                cout << i << setw(5) << "|";
            }
            for (int j = 0; j < sutun; j++)
            {
                if (i == 0)
                {
                    cout << setw(6) << char(table[i][j]);
                }
                else if (j != sutun - 1)
                {
                    cout << setw(6) << table[i][j];
                }

            }
            cout << endl;
        }
    }
    //TABLO CLASS I ICIN OLUSTURULMUS MENU
    int tablo_menu()
    {
        int secenek;
        cout << endl << "	" << "TABLO ISLEMLERI ICIN MENU" << endl;
        cout << "_____________________________________________" << endl;
        cout << "1->Icerisinde 0 degerlere sahip 10x10 luk bir tablo" << endl;
        cout << "2->rxc boyutunca d degerine sahip tablo olusturmak isterseniz" << endl;
        cout << "3->rxc boyutunda 'r' gonderildiginde 0-255 arasinda degere sahip tablo olusturmak isterseniz" << endl;
        cout << "4->r vr c de gormek istediginiz deger" << endl;
        cout << "5->Cikis" << endl;
        cout << "6->Ana menuye geri donmek istiyorum." << endl;
        cout << "Lutfen yapmak istediginiz secenegi giriniz: ";
        cin >> secenek;
        cout << endl;
        return secenek;
    }
};
int main()
{
    cout << "~~~~~~~~~~~~~~~~~~" << "348336 BUSRA MERVE AYDIN NESNE ODEV" << "~~~~~~~~~~~~~~~~~~" << endl;
    cout << endl;

    	int answer;
    	double toplam;

    	Table<int> t1;
    	Table<int> t2(4, 5, 2);
    	Table<int> t3(5, 5, 'r');
    	Table<int> islem_tablo;
    	Table<int > tablo_sonuc;

    	Matrix<double> yeni_matrix;
    	Matrix<double> islem_sonuc;
    	Matrix<int> sonuc;
    	Matrix<double> islem_matrix;
    	Matrix<double> yeni;
    	Matrix<double> m1;
    	Matrix<double> m2(3, 2, 1);
    	Matrix<double> m3(5, 5, 'e');
    	//m3.print();
    	Matrix<double> m4(2, 2, 'r');
    	//m4.print();
    	Matrix<double> a1(3, 3, 3);
    	Matrix<double> a2(3, 3, 1);
    	Matrix<double> a3(3, 3, 2);
    	Matrix<double> a4(3, 3, 0);
    	Matrix<int> a5(3, 3, 10);

    	//ANA MENU
    	cout << "	ANA MENU" << endl;
    	cout << "-----------------------------" << endl;
    	cout << "1->Matrix islemleri" << endl;
    	cout << "2->Tablo islemleri" << endl;
    	cout << "3->Goruntu islemleri" << endl;
    	cout << "4->Cikis" << endl;
    	cout << "Hangi islemi yapmak istersiniz? ";
    	cin >> answer;

    	if(answer==1)
    	{
    		//MATRIX CLASS
    		while (1)
    		{
    			switch (islem_matrix.matrix_menu())
    			{
    			case 1:
    				islem_sonuc = a1 + a2;
    				cout << "Toplama islemi yapilmistir." << endl;
    				islem_sonuc.print();
    				islem_sonuc.print("file.txt");
    				break;
    			case 2:
    				islem_sonuc = a1 - a2;
    				cout << "Cikarma islemi yapilmistir." << endl;
    				islem_sonuc.print();
    				islem_sonuc.print("file.txt");
    				break;
    			case 3:
    				islem_sonuc = a1 * a2;
    				cout << "Carpma islemi yapilmistir." << endl;
    				islem_sonuc.print();
    				islem_sonuc.print("file.txt");
    				break;
    			case 4:
    				islem_sonuc = a1 + 12;
    				cout << "Matris sabit sayi ile toplandi." << endl;
    				islem_sonuc.print();
    				islem_sonuc.print("file.txt");
    				break;
    			case 5:
    				islem_sonuc = a1 - 2;
    				cout << "Matristen sabir bir sayi cikarildi." << endl;
    				islem_sonuc.print();
    				islem_sonuc.print("file.txt");
    				break;
    			case 6:
    				islem_sonuc = a1 * 2;
    				cout << "Matris sabir bir sayi ile carpildi." << endl;
    				islem_sonuc.print();
    				islem_sonuc.print("file.txt");
    				break;
    			case 7:
    				islem_sonuc = a1 / 3;
    				cout << "Matris sabir bir sayi ile bolundu." << endl;
    				islem_sonuc.print();
    				islem_sonuc.print("file.txt");
    				break;
    			case 8:
    				sonuc = a5 % 6;
    				cout << "Matrisin sabir bir sayiya bolumunden kalan." << endl;
    				sonuc.print();
    				sonuc.print("file.txt");
    				break;
    			case 9:
    				islem_sonuc = a1 ^ 2;
    				cout << "Matrisin ussu alindi." << endl;
    				islem_sonuc.print();
    				islem_sonuc.print("file.txt");
    				break;
    			case 10:
    				cout << "__________________________________________________________________________" << endl;
    				cout << "Asil matris." << endl;
    				m2.print();
    				islem_sonuc = m2.T();
    				cout << "Matrisin transpozu alindi." << endl;
    				islem_sonuc.print();
    				islem_sonuc.print("file.txt");
    				break;
    			case 11:
    				islem_sonuc = m2.emul(m2);
    				cout << "Matrisin eleman duzeyinde carpmasi yapildi." << endl;
    				islem_sonuc.print();
    				islem_sonuc.print("file.txt");
    				break;
    			case 12:
    				islem_sonuc = m4.Inversion();
    				cout << "Matrisin tersi alindi" << endl;
    				islem_sonuc.print();
    				islem_sonuc.print("file.txt");
    				break;
    			case 13:
    				cout << "matrisi el ile girmek isterseniz 1 e istemezseniz 0 a basiniz: ";
    				cin >> answer;
    				if (answer == 1)
    				{
    					toplam = yeni_matrix.matrix_el_ile_gir().Det();
    					//cout << "__________________________________________________________________________" << endl;
    					cout << "Matrisin determinanti hesaplandi." << endl;
    					cout << endl;
    					cout << "Matrixin determinanti: " << toplam << endl;
    					cout << "--------------------------------------------------------------------------" << endl;
    				}
    				else
    				{
    					//cout << "__________________________________________________________________________" << endl;
    					cout << "Matrisin determinanti hesaplandi." << endl;
    					toplam = m4.Det();
    					cout << endl;
    					cout << "Matrixin determinanti: " << toplam << endl;
    					cout << "--------------------------------------------------------------------------" << endl;
    				}
    				break;

    			case 14:
    				m3.resize(8, 8);
    				cout << "__________________________________________________________________________" << endl;
    				cout << "Matrisin boyutu degistirildi." << endl;
    				m3.print();
    				m3.print("file.txt");
    				break;
    			case 15:
    				cout << endl << "TESEKKURLER" << endl;
    				exit(1);
    			case 16:
    				main();
    			}

    		}
    	}
    	if (answer == 2)
    	{
    		//TABLE CLASS
    		while (1)
    		{
    			switch (islem_tablo.tablo_menu())
    			{
    			case 1:
    				cout << "10x10 luk 0 degerine sahip talo" << endl;
    				cout << "__________________________________________________________________________" << endl;
    				t1.print();
    				break;
    			case 2:
    				cout << "rxc boyutunda d degerine sahip tablo" << endl;
    				cout << "__________________________________________________________________________" << endl;
    				t2.print();
    				break;
    			case 3:
    				cout << "rxc boyutlu 0-255 araliginda deger alan bir tablo" << endl;
    				cout << "__________________________________________________________________________" << endl;
    				t3.print();
    				break;
    			case 4:
    				cout << "sectiginiz satir ve sutundaki deger" << endl;
    				cout << "__________________________________________________________________________" << endl;
    				t2.itemAt(2, 2);
    				break;
    			case 5:
    				cout << endl << "TESEKKURLER" << endl;
    				exit(1);
    			case 6:
    				main();
    			}
    		}
    	}
    	else
    	{
    		cout <<endl<< "		TESEKKURLER" << endl;
    		exit(1);
    	}

}

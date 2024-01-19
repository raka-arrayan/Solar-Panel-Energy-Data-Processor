#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <unistd.h>
#include <conio.h>

struct panelsurya //struct panel surya
{
    float daya;
    float output;
    float luas;
    int jumlah;
    char musim[20];
    int hari;
    float power;
    float powerT;
    float indm; //indikator musim
};

struct Peralatan //struct peralatan listrik
{  
    char nama[30];
    char fungsi[100];
    int jumlah;
    double daya;
    double durasi;
};

typedef struct panelsurya panelsurya;
typedef struct Peralatan peralatan; //singkatan

void power(panelsurya *panel);
void enter();
void menuBreakeven(panelsurya *panel, peralatan list[], int *jumlahPeralatan);
void menuQuit();
void menuExtra();
void menuQuiz();
void menuFunfact(int *cntf);
void menuHelp();
void menuKalkulasiTotal(panelsurya *panel, peralatan list[], int *jumlahPeralatan);
void menuAlatinfo(peralatan list[], int *jumlahPeralatan);
void menuAlatmod(peralatan list[], int *jumlahPeralatan, int *MaxPeralatan);
void menuAlatkalkulasi(peralatan list[], int *jumlahPeralatan);
void menuAlatreferensi();
void menuAlat();
void menuPanelreferensi();
void menuPanelkalkulasi(panelsurya *panel);
void menuPanelmod(panelsurya *panel);
void menuPaneldata(panelsurya *panel, int *cntp);
void menuPanelinfo(panelsurya *panel);
void menuPanel();
void menuUtama();
void failpanel();
void failp();
void faila();
void fail(); //prototype

int main(void)
{
    int opsi, cnt = 0, sentinelD = 9, sentinelL = 0, jumlahPeralatan = 0, cntf = 0, MaxPeralatan = 25; //inisialisasi counter, sentinel (2 lapisan), dan jumlah peralatan / status isi panel
    int *cntp = &cnt; //pointer counter agar bisa dipakai antarfungsi
    panelsurya panel; //struct panel
    peralatan *list;  //pointer struct peralatan
	list = (peralatan *)calloc(MaxPeralatan, sizeof(peralatan)); //alokasi memori dinamis
    
    do //loop utama program
    {
    	menuUtama();
        scanf(" %d", &opsi);
        printf("--------------------------------\n");
        system("pause");
        system("cls");

        switch (opsi) //setelah menu utama
        {
	        case 1: //menu panel
    	    
        	    do
            	{
	                menuPanel();
    	            scanf(" %d", &opsi);
        	        printf("--------------------------------\n");
            	    system("pause");
                	system("cls");

	                switch (opsi)
    	            {
 		       	        case 1: //menu info panel
        	    	        if (*cntp == 0) //error jika belum ada data panel
            	    	    {
                	        	failpanel();
                	        	system("pause");
                	        	system("cls");
                    		}
                    		
       		            	else
                    		{
                        		menuPanelinfo(&panel);
                        		printf("--------------------------------\n");
                        		system("pause");
                        		system("cls");
                    		}
                    		break;
						
						case 2: //menu modifikasi panel
							if(*cntp == 0) //pengisian data perdana jika belum ada data
							{
								menuPaneldata(&panel, cntp);
							}
							
							else
							{
								menuPanelmod(&panel); //menu modifikasi data
							}
							break;
						
						case 3:
							if (*cntp == 0) //kalkulasi tidak bisa dijalankan apabila belum ada data
            	    	    {
                	        	failpanel();
                	        	system("pause");
                	        	system("cls");
                    		}
                    		
       		            	else
                    		{
                    			menuPanelkalkulasi(&panel); //kalkulasi penghematan panel
                    			system("pause");
                    			system("cls");
                    		}
                    		break;
                    	
						case 4:
							menuPanelreferensi(); //referensi dasar
							system("pause");
							system("cls");
								
						case 9: //kembali ke menu utama
							break;
							
         		        default:
 		                    fail(); //error handling
        		            system("pause");
                		    system("cls");
                		    break;
                	}
            	} while (opsi != sentinelD);
				break;
			
			case 2: 	
        		
        		do
        		{
        			menuAlat(); //menu peralatan
    	            scanf(" %d", &opsi);
        	        printf("--------------------------------\n");
            	    system("pause");
                	system("cls");
                	
                	switch (opsi)
    	            {
 		       	        case 1: //menu info peralatan
        	    	        menuAlatinfo(list, &jumlahPeralatan);
                    		break;
                    	
                    	case 2: //menu modifikasi peralatan
                    		menuAlatmod(list, &jumlahPeralatan, &MaxPeralatan);
                    		break;
                    		
                    	case 3: //menu kalkulasi biaya peralatan
                    		menuAlatkalkulasi(list, &jumlahPeralatan);
                    		system("pause");
                    		system("cls");
                    		break;
                    		
                    	case 4: //menu referensi/contoh
                    		menuAlatreferensi();
                    		system("pause");
                    		system("cls");
                    		break;
                    		
                    	case 9: 
                    		break;
					}
					
				} while(opsi != sentinelD);
				break;
			
			case 3:
				if(*cntp == 0)
				{
					failp(); //error handling jika belum ada data panel
					system("pause");
					system("cls");
				}
				
				else if(jumlahPeralatan == 0)
				{
					faila(); //error handling jika belum ada data peralatan
					system("pause");
					system("cls");
				}
				
				else
				{
					menuKalkulasiTotal(&panel, list, &jumlahPeralatan); //kalkulasi keseluruhan
					system("pause");
					system("cls");
				}
				
				break;
			
			case 4:
				menuHelp(); //menu help
				break;
				
			case 5:
			
				do
				{
					menuExtra(); //menu extra
					printf("Masukkan Pilihan: ");
					scanf("%d", &opsi);
					switch(opsi)
					{
			
						case 1 :
							system("cls");
							menuFunfact(&cntf); //fun facts
							enter();
							system("cls");
							break;
					
						case 2 :
							system("cls");
							menuQuiz(); //mini quiz
							enter();
							system("cls");
							break;
				
						case 9 :
							system("pause");
							system("cls");
							break;
				
						default :
							printf("Opsi tidak valid!\n");
							system("pause");
							system("cls");
							break;
					}
				} while(opsi != sentinelD);
				break;
	
			case 6:
				if(*cntp == 0)
				{
					failpanel(); //error handling jika belum ada data panel
					system("pause");
					system("cls");
				}
				
				else
				{
					menuBreakeven(&panel, list, &jumlahPeralatan); //menu break even / balik modal
				}
				
				break;
				
			case 0: //menu exit
            	menuQuit(); //terima kasih!
            	break;

        	default:
            	fail();
            	system("pause");
            	system("cls");
            	break;
        }

    } while (opsi != sentinelL);
	
	free(list); //pembebasan memori
    return 0;
}

void power(panelsurya *panel)
{
	if (strcmp(panel->musim, "Kemarau") == 0 || strcmp(panel->musim, "kemarau") == 0 || strcmp(panel->musim, "KEMARAU") == 0) 
		{
        	panel->indm = 1.35;
       	}
    else if (strcmp(panel->musim, "Hujan") == 0 || strcmp(panel->musim, "hujan") == 0 || strcmp(panel->musim, "HUJAN") == 0) 
    	{
    		panel->indm = 0.8; //menetapkan nilai sesuai musim
		}
	panel->power = panel->jumlah * panel->daya * panel->indm;
	panel->powerT = panel->jumlah * panel->daya * panel->indm * panel->hari; //perhitungan tenaga
}

void menuUtama()
{
	printf("--------------------------------\n");
	printf("|         [Menu Utama]         |\n");
	printf("|  Pendata Energi Panel Surya  |\n");
	printf("|     SDG 7 : Clean Energy     |\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("|<Opsi>                        |\n");
	printf("|------                  ------|\n");
	printf("| 1. Data Panel Surya          |\n"); 
	printf("| 2. Data Komponen Listrik     |\n");
	printf("| 3. Kalkulasi Keseluruhan     |\n"); 
	printf("| 4. Help                      |\n"); 
	printf("| 5. Extras                    |\n"); 
	printf("| 6. Data Break Even           |\n"); 
	printf("| 0. Keluar Program            |\n"); 
	printf("|------                  ------|\n");
	printf("|                              |\n");
	printf("|*Dibuat oleh Grup 10 - Maja   |\n");
	printf("--------------------------------\n");
	printf("| Input Pengguna               |\n");
	printf("| Masukkan Pilihan Anda:       |\b\b\b\b\b\b\b");
}

void menuPanel()
{
	printf("--------------------------------\n");
	printf("|       [Menu Informasi]       |\n");
	printf("|       Data Panel Surya       |\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("|<Opsi>                        |\n");
	printf("| 1. Informasi Panel Surya     |\n"); 
	printf("| 2. Modifikasi Data Panel     |\n"); 
	printf("| 3. Hasil Kalkulasi Panel     |\n"); 
	printf("| 4. Referensi Dasar           |\n"); 
	printf("| 9. Kembali ke Menu Utama     |\n");
	printf("--------------------------------\n");
	printf("| Input Pengguna               |\n");
	printf("| Masukkan Pilihan Anda:       |\b\b\b\b\b\b\b");
}

void menuAlat()
{
	printf("--------------------------------\n");
	printf("|       [Menu Informasi]       |\n");
	printf("|    Data Peralatan Listrik    |\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("|<Opsi>                        |\n");
	printf("| 1. Informasi Peralatan       |\n");  
	printf("| 2. Modifikasi Data Peralatan |\n"); 
	printf("| 3. Hasil Kalkulasi Peralatan |\n"); 
	printf("| 4. Referensi Dasar           |\n"); 
	printf("| 9. Kembali ke Menu Utama     |\n");
	printf("--------------------------------\n");
	printf("| Input Pengguna               |\n");
	printf("| Masukkan Pilihan Anda:       |\b\b\b\b\b\b\b");
}

void menuHelp()
{
	int opsi;
	
	do //user dapat melihat info sampai memilih untuk kembali ke menu utama
	{
		puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
		puts("|                             Petunjuk                             |");
		puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
		puts("| Selamat datang di Petunjuk Pengoperasian. Menu ini dibuat agar   |");
		puts("| pengguna dapat lebih memahami dan dapat lebih mudah mengakses    |");
		puts("| menu dan fitur-fitur pada program ini.                           |");
		puts("|                                                                  |");
		puts("| Pilihan Navigasi                                                 |");
		puts("| ------------------                                               |");
		puts("| 1. Menu Utama                                                    |");
		puts("| 2. Menu Panel Surya                                              |");
		puts("| 3. Menu Peralatan                                                |");
		puts("| 4. Menu Kalkulasi Keseluruhan                                    |");
		puts("| 5. Menu Help                                                     |");
		puts("| 6. Menu Extras                                                   |");
		puts("| 7. Menu Data Break Even                                          |");
		puts("| 9. Kembali ke Menu Utama                                         |");
		puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	
		printf(" Input: ");
		scanf("%d", &opsi);
		system("cls");
			
		switch(opsi)
		{
			case 1:
				puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
				puts("|                        Petunjuk Menu Utama                       |");
				puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
				puts("| Menu utama adalah menu pertama yang dapat dilihat saat program   |");
				puts("| pertama dijalankan. Menu ini terdiri dari 6 pilihan, yaitu :     |");
				puts("|                                                                  |");
				puts("| 1. Data Panel Surya                                              |");
				puts("| 2. Data Komponen Listrik                                         |");
				puts("| 3. Data Kalkulasi Keseluruhan                                    |");
				puts("| 4. Petunjuk Pengoperasian                                        |");
				puts("| 5. Extras                                                        |");
				puts("| 6. Data Break Even                                               |");
				puts("|                                                                  |");
				puts("| Terdapat juga pilihan 0 sebagai pilihan untuk keluar dari        |");
				puts("| program. Untuk mengakses pilihan-pilihan tersebut, silahkan      |");
				puts("| input angka sesuai dengan nomor pilihan tersebut lalu tekan      |");
				puts("| enter. Penjelasan setiap menu terdapat pada bagian berikutnya.   |");
				puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
				
				printf("\nTekan Enter untuk lanjut...");
				getch();
				system("cls");	
				break;
				
			case 2:
				puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
				puts("|                          Petunjuk Menu 1                         |");
				puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
				puts("| Menu 1 yaitu Data Panel Surya berisi pilihan untuk menampilkan   |");
				puts("| informasi panel surya, memodifikasi informasi panel surya,       |");
				puts("| menampilkan hasil kalkulasi panel surya, dan berisi referensi    |");
				puts("| dasar.                                                           |");
				puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
				
				printf("\nTekan Enter untuk lanjut...");
				getch();
				system("cls");
				break;
			
			case 3:	
				puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
				puts("|                          Petunjuk Menu 2                         |");
				puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
				puts("| Menu 2 yaitu Data Peralatan Listrik berisi pilihan untuk         |");
				puts("| menampilkan informasi peralatan yang digunakan, memodifikasi     |");
				puts("| jumlah dalam data peralatan, menampilkan kalkulasi dari          |");
				puts("| penggunaan peralatan, dan berisi referensi dasar.                |");
				puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
			
				printf("\nTekan Enter untuk lanjut...");
				getch();
				system("cls");
				break;
				
			case 4:	
				puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
				puts("|                          Petunjuk Menu 3                         |");
				puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
				puts("| Menu 3 yaitu Data Kalkulasi Keseluruhan akan menampilkan         |");
				puts("| kalkulasi dari panel surya dan kalkulasi dari peralatan yang     |");
				puts("| telah diinput.                                                   |");
				puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
				
				printf("\nTekan Enter untuk lanjut...");
				getch();
				system("cls");
				break;
				
			case 5:
				puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
				puts("|                          Petunjuk Menu 4                         |");
				puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
				puts("| Menu 4 yaitu Petunjuk Pengoperasian akan menampilkan petunjuk    |");
				puts("| untuk menggunakan program dan juga fitur-fiturnya.               |");
				puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
					
				printf("\nTekan Enter untuk lanjut...");
				getch();
				system("cls");
				break;
				
			case 6:
				puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
				puts("|                          Petunjuk Menu 5                         |");
				puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
				puts("| Menu 5 yaitu Extras berisi pilihan untuk melihat beberapa Fun    |");
				puts("| Fact dan bermain Mini Quiz tentang Pendata Energi Panel Surya    |");
				puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
				
				printf("\nTekan Enter untuk lanjut...");
				getch();
				system("cls");
				break;
				
			case 7:
				puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
				puts("|                          Petunjuk Menu 6                         |");
				puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
				puts("| Menu 6 yaitu Data Break Even akan menampilkan kalkulasi dari     |");
				puts("| Balik Modal. Yang dimaksud adalah harga, jumlah, dan biaya       |");
				puts("| pemasangan panel surya dan menampilkan kalkulasi balik modalnya. |");
				puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
				system("pause");
				system("cls");
				break;
					
				case 9:
					break;
					
				default:
					fail();
					system("pause");
					system("cls");
					break;
		}
	}while(opsi != 9);
}

void menuExtra()
{
	printf("--------------------------------\n");
	printf("|          [Menu Extra]        |\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("| 1. Fun Fact                  |\n");
	printf("| 2. Mini Quiz                 |\n");
	printf("| 9. Kembali ke Menu Utama     |\n");;
	printf("--------------------------------\n");
}

void menuQuit()
{
	printf("--------------------------------\n");
	printf("|        [Terima Kasih!]       |\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("| Terima kasih telah ikut      |\n");
	printf("| berkontribusi dengan memakai |\n");
	printf("| tenaga bersih dan menjaga    |\n");
	printf("| bumi kita! :)                |\n");
	printf("|                              |\n");
	printf("| Grup 10 - Maja               |\n");
	printf("--------------------------------\n");
}

void fail()
{
	printf("--------------------------------\n");
	printf("|      [Input Tidak Valid!]    |\n");
	printf("|     Mohon pilih input baru!  |\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

void failpanel()
{
	printf("--------------------------------\n");
	printf("|        [Data Kosong!]        |\n");
	printf("|  Mohon input terlebih dulu!  |\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

void failp()
{
	printf("--------------------------------\n");
	printf("|     [Data Panel Kosong!]     |\n");
	printf("|  Mohon input terlebih dulu!  |\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

void faila()
{
	printf("--------------------------------\n");
	printf("|   [Data Peralatan Kosong!]   |\n");
	printf("|  Mohon input terlebih dulu!  |\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

void enter(){
	printf("\n\nTekan enter untuk kembali ke menu extra...");
    getch();
}

void menuPanelinfo(panelsurya *panel) //print data panel
{
    printf("--------------------------------\n");
    printf("|       [Menu Informasi]       |\n");
    printf("|     Informasi Panel Surya    |\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("| %-15s%-9d%-5s% |\n", "Jumlah Panel:", panel->jumlah, "Unit");
    printf("| %-15s%-9.2f%-4s |\n", "Output:", panel->output, "W");
    printf("| %-15s%-9.2f%-4s |\n", "Daya Generasi:", panel->daya, "kWh");
    printf("| %-15s%-9.2f%-4s |\n", "Luas/Panel:", panel->luas, "m2");
    printf("| %-15s%-9.2f%-4s |\n", "Luas Total:", (panel->luas) * (panel->jumlah), "m2");
    printf("| %-15s%-9.2d%-4s |\n", "Waktu Aktif:", panel->hari, "Hari");
    printf("| %-15s%-13s |\n", "Musim Kini:", panel->musim);
    printf("--------------------------------\n");
}

void menuPanelmod(panelsurya *panel) //modifikasi data panel
{
	int opsi;
    printf("---------------------------------------\n");
    printf("|          [Menu Modifikasi]          |\n");
    printf("|             Panel Surya             |\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("| 1. %-15s%-11d%-7s% |\n", "Jumlah Panel:", panel->jumlah, "Unit");
    printf("| 2. %-15s%-11.2f%-6s |\n", "Output:", panel->output, "W");
    printf("| 3. %-15s%-11.2f%-6s |\n", "Daya Generasi:", panel->daya, "kWh");
    printf("| 4. %-15s%-11.2f%-6s |\n", "Luas/Panel:", panel->luas, "m2");
    printf("| 5. %-15s%-11.2d%-6s |\n", "Waktu Aktif:", panel->hari, "Hari");
    printf("| 6. %-15s%-17s |\n", "Musim Kini:", panel->musim);
    printf("---------------------------------------\n");
    printf("| Pilih tujuan modifikasi             |\n| Input: ");
    
	scanf("%d", &opsi);
	printf("---------------------------------------\n");
	switch (opsi) //modifikasi data panel
	{
		case 1:
			printf("| Jumlah Panel baru: ");
			scanf("%d", &panel->jumlah);
			printf("| Input diterima!\n---------------------------------------\n");
			system("pause");
			system("cls");
			break;

		case 2:
			printf("| Output Panel baru: ");
			scanf("%f", &panel->output);
			printf("| Input diterima!\n---------------------------------------\n");
			system("pause");
			system("cls");
			break;

		case 3:
			printf("| Daya Panel baru: ");
			scanf("%f", &panel->daya);
			printf("| Input diterima!\n---------------------------------------\n");
			system("pause");
			system("cls");
			break;

		case 4:
			printf("| Luas/Panel baru: ");
			scanf("%f", &panel->luas);
			printf("| Input diterima!\n---------------------------------------\n");
			system("pause");
			system("cls");
			break;

		case 5:
			printf("| Waktu aktif: ");
			scanf("%d", &panel->hari);
			printf("| Input diterima!\n---------------------------------------\n");
			system("pause");
			system("cls");
			break;

		case 6:
			printf("| Musim kini: ");
			do
			{
				scanf("%s", panel->musim);

				if (strcmp(panel->musim, "Kemarau") != 0 && strcmp(panel->musim, "Hujan") != 0 && strcmp(panel->musim, "kemarau") != 0 && strcmp(panel->musim, "hujan") != 0 && strcmp(panel->musim, "KEMARAU") != 0 && strcmp(panel->musim, "HUJAN") != 0)
				{
					printf("| Musim tidak valid!\n| Input: "); //error handling untuk musim yang tak terdaftar
				}

			} while (strcmp(panel->musim, "Kemarau") != 0 && strcmp(panel->musim, "Hujan") != 0 && strcmp(panel->musim, "kemarau") != 0 && strcmp(panel->musim, "hujan") != 0 && strcmp(panel->musim, "KEMARAU") != 0 && strcmp(panel->musim, "HUJAN") != 0);
			printf("| Input diterima!\n---------------------------------------\n");
			system("pause");
			system("cls");
			break;

		default:
			printf("| Opsi tak terdefinisi!\n");
			break;
	}

}

void menuPaneldata(panelsurya *panel, int *cntp) //pendataan panel pertama
{
	printf("--------------------------------\n");
	printf("|       [Menu Modifikasi]      |\n");
	printf("|          Panel Surya         |\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("| Pendataan Pertama            |\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("| Masukkan Jumlah Panel (1)\n| Input: ");
		scanf("%d", &panel->jumlah);
	printf("--------------------------------\n");
	printf("| Masukkan Output Panel (kWh)\n| Input: ");
		scanf("%f", &panel->daya);	
	printf("--------------------------------\n");
	printf("| Masukkan Daya Panel (Watt)\n| Input: ");
		scanf("%f", &panel->output);
	printf("--------------------------------\n");
	printf("| Masukkan Luas / Panel (m2)\n| Input: ");
		scanf("%f", &panel->luas);
	printf("--------------------------------\n");
	printf("| Masukkan Durasi Aktif Panel   \n| Input: ");
		scanf("%d", &panel->hari);
	printf("--------------------------------\n");
	printf("| Masukkan Musim (Kemarau/Hujan)\n| Input: ");
	
		do
			{
				scanf("%s", panel->musim);		
				if (strcmp(panel->musim, "Kemarau") != 0 && strcmp(panel->musim, "Hujan") != 0 && strcmp(panel->musim, "kemarau") != 0 && strcmp(panel->musim, "hujan") != 0 && strcmp(panel->musim, "KEMARAU") != 0 && strcmp(panel->musim, "HUJAN") != 0) 
					{
       					printf("| Musim tidak valid!\n| Input: ");
        			}
    	} while (strcmp(panel->musim, "Kemarau") != 0 && strcmp(panel->musim, "Hujan") != 0 && strcmp(panel->musim, "kemarau") != 0 && strcmp(panel->musim, "hujan") != 0 && strcmp(panel->musim, "KEMARAU") != 0 && strcmp(panel->musim, "HUJAN") != 0);
								
	printf("--------------------------------\n");
	*cntp = 1;
	system("pause");
	system("cls");				
}

void menuPanelkalkulasi(panelsurya *panel) //perhitungan penghematan panel
{
	power(panel);
    printf("---------------------------------------\n");
    printf("|           [Menu Kalkulasi]          |\n");
    printf("|             Panel Surya             |\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("| Hasil Kalkulasi ------------------- |\n");
    printf("| %-15s%-11.2f%-9s |\n", "Hasil Daya:", panel->power, "kWh/Hari");
    printf("| %-15s%-11.2f%-9s |\n", "Daya Total:", panel->powerT, "kWh");
    printf("| %-15s%-11.2f%-9s |\n", "Penghematan:", panel->powerT * 1352, "Rp");
    printf("---------------------------------------\n");
}

void menuPanelreferensi() //referensi panel surya
{
    printf("---------------------------------------\n");
    printf("|           [Menu Referensi]          |\n");
    printf("|             Panel Surya             |\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("| Apa itu panel surya?                |\n");
    printf("| Panel surya adalah sebuah alat      |\n");
    printf("| semikonduktor yang dapat mengubah   |\n");
    printf("| energi surya menjadi energi listrik |\n");
	printf("|                                     |\n");
    printf("| Makin terang sinar matahari, makin  |\n");
    printf("| banyak energi yang dihasilkan.      |\n");
    printf("| Alat ini adalah sumber energi umum  |\n");
    printf("| yang sangat ramah lingkungan dan    |\n");
    printf("| bersifat sustainable.               |\n");
    printf("---------------------------------------\n");
}

void menuAlatinfo(peralatan list[], int *jumlahPeralatan) 
{
	int i;
	if(*jumlahPeralatan >= 1) //list data peralatan
	{
	
		printf("---------------------------------------\n");
    	printf("|           [Menu Informasi]          |\n");
	    printf("|           Peralatan Listrik         |\n");
    	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    	for (i = 0; i < *jumlahPeralatan; ++i) 
		{
		    printf("| %-15s%-21s% |\n", "Nama Alat:", list[i].nama);
		    printf("| %-8s%-28s% |\n", "Fungsi:", list[i].fungsi);
	    	printf("| %-15s%-11d%-10s% |\n", "Jumlah:", list[i].jumlah, "Unit");
		    printf("| %-15s%-11.2lf%-10s% |\n", "Konsumsi Daya:", list[i].daya, "W");
		    printf("| %-15s%-11.2lf%-9s |\n", "Waktu Aktif:", list[i].durasi, "Jam");
    		printf("---------------------------------------\n");
		}
		system("pause");
		system("cls");
	}
	
	else //error handling jika peralatan masih 0
	{
		failpanel();
		system("pause");
		system("cls");
	}
}

void menuAlatmod(peralatan list[], int *jumlahPeralatan, int *MaxPeralatan)
{
    int pilihan, i; 
    printf("---------------------------------------\n");
    printf("|          [Menu Modifikasi]          |\n");
    printf("|          Peralatan Listrik          |\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("| Jumlah Peralatan: %-17d |\n", *jumlahPeralatan);
    printf("| Opsi Modifikasi ------------------- |\n");
    printf("| 1. Tambah Peralatan                 |\n");
    printf("| 2. Hapus Peralatan                  |\n");
    printf("| 9. Kembali ke Menu                  |\n");
    printf("---------------------------------------\n");
    printf("| Pilih tujuan modifikasi             |\n| Input: ");
    scanf("%d", &pilihan);
	system("pause");
	system("cls");
	
    switch(pilihan) 
	{
		case 1: ;
			peralatan Xperalatan; //penambahan peralatan
			printf("--------------------------------\n");
			printf("| Penambahan Peralatan         |\n");
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			printf("| Masukkan Nama Alat            \n| Input: ");
				scanf(" %[^\n]s", Xperalatan.nama);
			printf("--------------------------------\n");
			printf("| Masukkan Fungsi Alat          \n| Input: ");
				scanf(" %[^\n]s", Xperalatan.fungsi);
			printf("--------------------------------\n");
			printf("| Masukkan Jumlah Alat (1)      \n| Input: ");
				scanf("%d", &Xperalatan.jumlah);
			printf("--------------------------------\n");
			printf("| Masukkan Daya Alat   (W)      \n| Input: ");
				scanf("%lf", &Xperalatan.daya);
			printf("--------------------------------\n");
			printf("| Masukkan Durasi Alat (Jam)    \n| Input: ");
				scanf("%lf", &Xperalatan.durasi);
			printf("--------------------------------\n");
			
			if (*jumlahPeralatan < *MaxPeralatan) 
			{
    	        list[(*jumlahPeralatan)++] = Xperalatan;
        	printf("Peralatan berhasil ditambahkan!\n");
	        }
			 
			else //max peralatan dicapai
			{
    	        printf("Kapasitas peralatan sudah penuh!\n");
       		}
			system("pause");
			system("cls");
			break;
       		
    	case 2:
        	if (*jumlahPeralatan > 0) //menghapus peralatan
			{
				printf("--------------------------------\n");
				printf("| Penghapusan Peralatan        |\n");
				printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			
				for(i = 0; i < *jumlahPeralatan; i++)
				{
					printf("| %d. %-25s |\n", i+1, list[i].nama);
				}
			
				printf("--------------------------------\n");
            	printf("| Pilih peralatan:             |\n| Input: ");
            	int indeks;
            	scanf("%d", &indeks);
            	printf("--------------------------------\n");		
	            if (indeks > 0 && indeks <= *jumlahPeralatan) 
				{
        	        for (i = indeks - 1; i < *jumlahPeralatan - 1; ++i) 
					{
                	    list[i] = list[i + 1];
	                }
    	            (*jumlahPeralatan)--;
        	        printf("| Peralatan berhasil dihapus!  |\n");
            	    printf("--------------------------------\n");
            	    
                	system("pause");
                	system("cls");
            	}	 
            
				else if (indeks > *jumlahPeralatan || indeks < *jumlahPeralatan)
				{
        	        fail();
            	    system("pause");
                	system("cls");
            	}
        	}
    	    else 
				{
					system("cls");
           			failpanel();
           			system("pause");
               		system("cls");
       			}
       			break;
	}
}

void menuAlatkalkulasi(peralatan list[], int *jumlahPeralatan) //data biaya peralatan
{
    int i;
    double dayaHarian = 0, totalDaya = 0;
    double biayaHarian = 0, totalBiaya = 0;
    
	if(*jumlahPeralatan > 0)
    {
		printf("---------------------------------------\n");
    	printf("|           [Menu Kalkulasi]          |\n");
	    printf("|           Peralatan Listrik         |\n");
    	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    	printf("| Hasil Kalkulasi ------------------- |\n");
	    for (i = 0; i < *jumlahPeralatan; ++i) 
		{
        	dayaHarian = list[i].daya * list[i].durasi;
        	biayaHarian = dayaHarian / 1000 * 1352;
        	printf("| %-15s%-20s |\n", "Nama:", list[i].nama);
    		printf("| %-15s%-20.2lf |\n", "Watt:", dayaHarian);
    		printf("| %-11s%-4s%-20.2lf |\n", "Biaya:", "Rp", biayaHarian);
    		printf("---------------------------------------\n");
        	totalDaya += dayaHarian;
        	totalBiaya += biayaHarian;
    	}
    	printf("| %-35s |\n", "Total");
		printf("| %-15s%-11.2lf%-9s |\n", "Daya/Hari:", totalDaya, "W");
    	printf("| %-15s%-11.2lf%-9s |\n", "Biaya/Hari:", totalBiaya, "Rp");
    	printf("---------------------------------------\n");
    }
    
    else
	{
    	failpanel();
		system("pause");
		system("cls");
	}
}

void menuAlatreferensi() 
{
	printf("---------------------------------------\n");
    printf("|           [Menu Referensi]          |\n");
    printf("|           Peralatan Listrik         |\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("| Contoh-Contoh:                      |\n");
    printf("| Nama: Kulkas                        |\n");
    printf("| Fungsi Alat: Mendinginkan makanan   |\n");
    printf("| Konsumsi Daya: 90 Watt              |\n");
	printf("| ----------------------------------- |\n");
    printf("| Nama: Kipas                         |\n");
    printf("| Fungsi Alat: Mendinginkan ruangan   |\n");
    printf("| Konsumsi Daya: 70 Watt              |\n");
    printf("| ----------------------------------- |\n");
    printf("| Nama: Televisi                      |\n");
    printf("| Fungsi Alat: Menampilkan video      |\n");
    printf("| Konsumsi Daya: 40 Watt              |\n");
    printf("---------------------------------------\n");
}

void menuKalkulasiTotal(panelsurya *panel, peralatan list[], int *jumlahPeralatan) //kalkulasi panel + peralatan + net biaya
{
	int i;
	char status[8];
	power(panel);
    double dayaHarian = 0, totalDaya = 0;
    double biayaHarian = 0, totalBiaya = 0;
    
    printf("---------------------------------------\n");
    printf("|           [Menu Kalkulasi]          |\n");
    printf("|             Keseluruhan             |\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("| Hasil Kalkulasi (Panel)             |\n");
    printf("| %-15s%-11.2f%-9s |\n", "Hasil Daya:", panel->power, "kWh/Hari");
    printf("| %-15s%-11.2f%-9s |\n", "Daya Total:", panel->powerT, "kWh");
    printf("| %-15s%-11.2f%-9s |\n", "Penghematan:", panel->powerT * 1352, "Rp");
    printf("---------------------------------------\n");
    printf("| Hasil Kalkulasi (Peralatan)         |\n");
	    for (i = 0; i < *jumlahPeralatan; ++i) 
		{
        	dayaHarian = list[i].daya * list[i].durasi;
        	biayaHarian = dayaHarian / 1000 * 1352;
        	printf("| %-15s%-20s |\n", "Nama:", list[i].nama);
    		printf("| %-15s%-20.2lf |\n", "Watt:", dayaHarian);
    		printf("| %-11s%-4s%-20.2lf |\n", "Biaya:", "Rp", biayaHarian);
    		printf("---------------------------------------\n");
        	totalDaya += dayaHarian;
        	totalBiaya += biayaHarian;
    	}
    	printf("| %-35s |\n", "Total");
		printf("| %-15s%-11.2lf%-9s |\n", "Daya/Hari:", totalDaya, "W");
    	printf("| %-15s%-11.2lf%-9s |\n", "Biaya/Hari:", totalBiaya, "Rp");
    	printf("---------------------------------------\n");
    	printf("| Hasil Kalkulasi (Total)             |\n");
    	printf("| %-13s%-4s%-18.2f |\n", "Penghematan:", "Rp", panel->power * 1352);
    	printf("| %-13s%-4s%-18.2lf |\n", "Biaya:", "Rp", totalBiaya);
    	printf("| %-13s%-4s%-18.2lf |\n", "Total/Hari:", "Rp", (panel->power * 1352) - totalBiaya);
    	
		if((panel->powerT * 1352) > totalBiaya)
    	{
    		snprintf(status, 8, "Surplus");
		}
		
		else
		{
			snprintf(status, 8, "Defisit");
		}
		printf("| %-13s%-22s |\n", "Status:", status); //net
}

void menuBreakeven(panelsurya *panel, peralatan list[], int *jumlahPeralatan)
{
	float hpanel, hpasang, htotal, haritotal;
	int opsi, tahun, harisisa, bulan, hari;
	
	printf("--------------------------------------\n"); //perhitungan balik modal
    printf("|          [Menu Kalkulasi]          |\n");
    printf("|             Break Even             |\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("| *Break Even = Balik Modal           \n");
    printf("| Harga 1 Unit Panel Surya:           \n| Input: ");
    	scanf("%f", &hpanel);
    printf("| Jumlah Total Panel Surya: %-8d |\n", panel->jumlah); //cek jumlah panel (bisa dimodifikasi)
    printf("| Apakah jumlah ini benar?           |\n");
    printf("| 1. Benar                           |\n");
    printf("| 2. Salah (ganti jumlah panel)      |\n");
    printf("--------------------------------------\n");
    	do
    	{		
			printf("| Opsi: ");
			scanf("%d", &opsi);
			if(opsi == 2)
			{
				printf("| Masukkan jumlah panel baru:         \n| Jumlah Panel: ");
					scanf("%d", &panel->jumlah);	
			}
			else if(opsi != 2 && opsi != 1)
			{
				printf("| Masukan tidak valid!\n");
			}
			
		}while(opsi != 2 && opsi != 1);
	
	printf("--------------------------------------\n");
    printf("| Harga Total Pemasangan Panel Surya: \n| Input: ");
    	scanf("%f", &hpasang);
    printf("--------------------------------------\n");
    
	htotal = (hpasang + (hpanel * panel->jumlah));
	haritotal = htotal / (panel->power * 1352);
    haritotal = ceil(haritotal); //perhitungan waktu hingga balik modal berdasarkan biaya panel dan biaya pasang
    system("pause");
    system("cls");
	
	int haritotali = (int)haritotal;
	tahun = haritotali / 365;
    bulan = (haritotali - (tahun * 365)) / 30;
    hari = (haritotali - (tahun * 365) - (bulan *30)); //representasi dalam tahun bulan hari
    
	power(panel);
	
    printf("--------------------------------------\n");
    printf("|          [Menu Kalkulasi]          |\n");
    printf("|             Break Even             |\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("| %-14s%-11.2f%-9s |\n", "Hasil Daya:", panel->power, "kWh/Hari");
    printf("| %-14s%-11.2f%-9s |\n", "Penghematan:", panel->powerT * 1352, "Rp");
    printf("| %-14s%-11.2f%-9s |\n", "Biaya Panel:", htotal , "Rp");
    printf("| Anda akan balik modal pada:        |\n");
    printf("| %-4d %-7s%-4d%-7s%-4d%-7s |\n", tahun, "Tahun, ", bulan, "Bulan, ", hari, "Hari");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    
	system("pause");
	system("cls");
    
}

void menuFunfact(int* cntf){
	char* FunFact[7] = { //list fun fact mengenai panel surya
        "Sebuah tim peneliti telah berhasil menciptakan panel surya yang terbuat dari\nsayuran, seperti bayam. Mereka menggunakan sel-sel surya yang ditempatkan di\ndalam sel-sel tanaman, membuka pintu bagi potensi panel surya organik yang\nlebih ramah lingkungan.",
        "Sebuah inovasi menarik disebut 'Panel Surya Malam Hari' sedang dikembangkan.\nTeknologi ini bertujuan untuk menyimpan energi matahari selama siang hari dan\nmelepaskannya sebagai cahaya di malam hari, memberikan sumber cahaya yang\nramah lingkungan dan hemat energi.",
        "Sebuah penelitian telah mengeksplorasi cara menggunakan gumpalan karet dari\npermen karet untuk menciptakan panel surya. Ide ini menunjukkan bahwa materi\nyang tidak terpakai dapat diubah menjadi sumber energi yang bermanfaat.",
        "Para ilmuwan sedang mempelajari cara panel surya dapat diinspirasi oleh\nstruktur bulu kolibri. Bulu kolibri memiliki tekstur yang dapat meredam cahaya,\ndan penelitian ini bertujuan untuk meningkatkan efisiensi panel surya dengan\nmengadopsi prinsip-prinsip desain dari alam.",
        "Panel surya tidak hanya berpotensi di Bumi. NASA sedang mengembangkan\nteknologi panel surya untuk digunakan di planet-planet lain, seperti Mars.\nKonsep ini memunculkan visi masa depan di mana manusia dapat menghasilkan\nenergi matahari bahkan di luar Bumi.",
        "Teknologi layar surya fleksibel memungkinkan kita menggulung atau membentuk\npanel surya sesuai kebutuhan. Ini membuka pintu untuk aplikasi yang lebih\nkreatif, seperti panel surya yang dapat digunakan di pakaian atau tas.",
        "Penelitian sedang dilakukan untuk menggunakan energi matahari tidak hanya\nuntuk menghasilkan listrik tetapi juga untuk desalinasi air laut. Ini bisa\nmenjadi langkah besar dalam memecahkan masalah kekurangan air di beberapa\nwilayah di dunia."
    };
    printf("\t\t\t\tTahukah Anda?\n=============================================================================\n");
    printf("%s", FunFact[*cntf]);
    *cntf = (*cntf + 1) % 7;
}

void menuQuiz (){
	int x, y, jawab;
	struct quiz{
    	char* pertanyaan;
    	char* jawaban;
	};
	struct quiz soal[5] = { //mini quiz mengenai panel surya
        {"Photovoltaic cell merupakan bagian utama \npanel yang mengkonversi sinar matahari \nmenjadi energi listrik.", "BENAR!"},
        {"Panel surya dapat menangkap energi paling \nbanyak jika sudutnya antara 0 - 15 derajat.", "SALAH! Sudut yang optimal adalah 30-45 derajat."},
        {"Panel surya umum dibuat dengan emas sebagai \nbahan semikonduktornya.", "SALAH! Bahan semikonduktor yang umum dipakai adalah silikon."},
        {"Efisiensi panel menurun seiring dengan \nnaiknya temperatur.", "BENAR! Mengejutkan, bukan?"},
        {"Melalui proses lunar photovoltaics, panel \nsurya dapat menghasilkan energi pada malam hari.", "SALAH! Panel tidak bisa mengkonversi energi cahaya bulan."}
    };
	printf("\tSelamat datang di Mini Quiz!\n============================================\nPada Mini Quiz ini, kalian akan diberikan\nsebuah pernyataan dan diberikan waktu 10 detik.\nSilahkan menentukan apakah pernyataan tersebut\nbenar atau salah. Setelah waktu habis, maka\njawaban yang benar akan diberikan");
	printf("\n\nTekan enter untuk lanjut...");
	getch();
	system("cls");
    for(x = 0; x < 5; x++)
	{
    	for(y = 7; y >= 0; y--){
			printf("\t\tQuestion %d\n============================================\n", x+1);
			printf("%s", soal[x].pertanyaan);
			printf("\n\n\t   Benar?\tSalah?\n");
			printf("\t      Sisa Waktu : %d", y);
			sleep(1);
			system("cls");	
		}
		
			printf("Jawaban Anda: ");
			scanf("%s");
			getchar();

		printf("Pernyataan tersebut... %s", soal[x].jawaban);
		printf("\nTekan enter untuk lanjut ke soal berikutnya...");
		getch();
		system("cls");
	}
	printf("Terimakasih telah memainkan Mini Quiz!");;
}


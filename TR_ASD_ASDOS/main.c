#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>


struct data{
    int kode_transaksi;
    char nama_barang [100];
    int harga_barang;
    int jumlah_barang;
    int total_harga;
    struct data *next;
    struct data *prev;
}*head,*current,*temp, *prev, *tail;

void waktu(){
    struct tm *Sys_T;

    time_t Tval;
    Tval = time(NULL);
    Sys_T = localtime(&Tval);

    printf("\t\t\t\t\t             ---------\n");
    printf("\t\t\t\t\t            |%d/%d/%d|                    \n", Sys_T->tm_mday, Sys_T->tm_mon+1, 1900+Sys_T->tm_year);
    printf("\t\t\t\t\t             ---------\n");
}


void creat(int kode_transaksi, char nama_barang[100], int harga_barang, int jumlah_barang, int total_harga){

    current = (struct data*)malloc(sizeof(struct data));
    current->kode_transaksi = kode_transaksi;
    strcpy(current->nama_barang,nama_barang);
    current->harga_barang = harga_barang;
    current->jumlah_barang = jumlah_barang;


    if(head==NULL){
        head=tail=current;
        head->next=NULL;
    }else{
        tail->next=current;
        tail=current;
    }
    tail->next=NULL;
    tail=current;
}


void read(){
    current=head;

    while(current!=NULL)
    {
       printf("\t             %i\t\t\t%s\t\t%i\t\t%i\t\t%i       \n\n", current->kode_transaksi, current->nama_barang, current->harga_barang, current->jumlah_barang, current->harga_barang*current->jumlah_barang);
       current=current->next;
    }
}

void update_nama_barang(int kode_transaksi){

    char nama_barang_baru[30];
    current = (struct data*)malloc(sizeof(struct data));

    if(head==NULL)
    {
        printf("\n\t\t\t\t                   data kosong \n\n");

        system("pause >nul | echo \t\t\t\t               enter untuk kembali . . ."); system("cls");
        return;
    }


    current = head;
    if(current->kode_transaksi == kode_transaksi)
    {
        printf("\t\t\t\t               nama barang baru: ");
        fflush(stdin);
        gets(nama_barang_baru);
        strcpy(current->nama_barang, nama_barang_baru);
        system("pause >nul | echo \t\t\t\t               enter untuk kembali . . ."); system("cls");
        return;
    }

    while(current!=NULL)
    {
        if(current->kode_transaksi == kode_transaksi)
        {
        printf("\t\t\t\t               nama barang baru: ");
        fflush(stdin);
        gets(nama_barang_baru);
        strcpy(current->nama_barang, nama_barang_baru);
        system("pause >nul | echo \t\t\t\t               enter untuk kembali . . ."); system("cls");
        return;
        }
        current = current->next;
    }

}

void update_harga_barang(int kode_transaksi){
    int harga_barang_baru;

    if(head==NULL)
    {
        printf("\n\t\t\t\t                   data kosong \n\n");

        system("pause >nul | echo \t\t\t\t               enter untuk kembali . . ."); system("cls");
        return;

    }

    current = head;
    if(current->kode_transaksi == kode_transaksi)
    {
        printf("\t\t\t\t               harga barang baru: ");
        scanf("%d", &harga_barang_baru);
        current->harga_barang=harga_barang_baru;
        system("pause >nul | echo \t\t\t\t               enter untuk kembali . . ."); system("cls");

        return;
    }

    while(current!=NULL)
    {
        if(current->kode_transaksi == kode_transaksi)
        {
        printf("\t\t\t\t               harga barang baru: ");
        scanf("%d", &harga_barang_baru);
        current->harga_barang=harga_barang_baru;
        system("pause >nul | echo \t\t\t\t               enter untuk kembali . . ."); system("cls");
        return;
        }
        current = current->next;
    }
    printf("\t\t\t\t               tidak ada data\n\n");
    system("pause >nul | echo \t\t\t\t               enter untuk kembali . . ."); system("cls");
}

void update_jumlah_barang(int kode_transaksi){
    int jumlah_barang_baru;

    if(head==NULL)
    {
        printf("\n\t\t\t\t                   data kosong \n\n");

        system("pause >nul | echo \t\t\t\t               enter untuk kembali . . ."); system("cls");
        return;
    }


    current = head;
    if(current->kode_transaksi == kode_transaksi)
    {
        printf("\t\t\t\t               jumlah barang baru: ");
        scanf("%d", &jumlah_barang_baru);
        current->jumlah_barang=jumlah_barang_baru;
        system("pause >nul | echo \t\t\t\t               enter untuk kembali . . ."); system("cls");
        return;
    }

    while(current!=NULL)
    {
        if(current->kode_transaksi == kode_transaksi)
        {
        printf("\t\t\t\t               jumlah barang baru: ");
        scanf("%d", &jumlah_barang_baru);
        current->jumlah_barang=jumlah_barang_baru;


        return;
        }
        current = current->next;
    }
    printf("\t\t\t\t               tidak ada data\n\n");
    system("pause >nul | echo tekan tombol apapun untuk kembali...");
    system("cls");

}

void tambah_data(int kode_transaksi, char nama_barang[100], int harga_barang, int jumlah_barang, int total_harga){

    current = (struct data*)malloc(sizeof(struct data));
    current->kode_transaksi = kode_transaksi;
    strcpy(current->nama_barang,nama_barang);
    current->harga_barang = harga_barang;
    current->jumlah_barang = jumlah_barang;


    if(head==NULL){
        head=tail=current;
        head->next=NULL;
    }else{
        tail->next=current;
        tail=current;
    }
    tail->next=NULL;
    tail=current;
}

void hapusKepala(){
    current = head;
    if(head==NULL)
    {
        printf("\t\t\t\t                   data kosong \n\n");
        system("pause >nul | echo tekan tombol apapun untuk kembali...");
        //system("cls");
        return;
    }
    if(head==tail)
    {
        head = tail = NULL;
        free(current);
    }
    else
    {
        head = head->next;
        free(current);
    }
}

void hapusAkhir(){
    if(head==NULL)
    {
        printf("\t\t\t\t                   data kosong \n\n");
        system("pause >nul | echo tekan tombol apapun untuk kembali...");
        //system("cls");
        return;
    }
    if(head==tail)
    {
        head = tail = NULL;
        free(current);
    }
    else
    {
        struct data *temp = head;
        while(temp->next!=tail){
            temp = temp->next;
        }
        current = tail;
        tail = temp;
        free(current);
        tail->next = NULL;
    }
}


void hapus_data(int kode_transaksi){
    if(head==NULL)
    {
        printf("\t\t\t\t                   data kosong \n\n");
        system("pause >nul | echo \t\t\t\t               enter untuk kembali . . .");
        return;
    }

    if(head->kode_transaksi == kode_transaksi)
    {
        hapusKepala();
        system("pause >nul | echo \t\t\t\t               enter untuk kembali . . .");
    }
    else if(tail->kode_transaksi == kode_transaksi)
    {
        hapusAkhir();
        system("pause >nul | echo \t\t\t\t               enter untuk kembali . . .");
    }
    else
    {
        struct data *temp = head;
        while(temp->next->kode_transaksi!= kode_transaksi && temp!=tail)
        {
            temp = temp->next;
        }
        current = temp->next;
        temp->next = temp->next->next;
        free(current);
        system("pause >nul | echo \t\t\t\t               enter untuk kembali . . .");
    }
    //printf("\t\t tidak ada data \n\n");
    return;
}


//history
int no_riwayat = 1;
char riwayat[100][100];
void history(){
    printf("\t\t\t\t               +------------------------+\n");
    printf("\t\t\t\t               No.\tRiwayat\n");
    printf("\t\t\t\t               +------------------------+\n");
	for(int no_awal = 1; no_awal < no_riwayat; no_awal++)
    {
		printf("\t\t\t\t               %d.\t%s\n\n",no_awal,riwayat[no_awal]);
	}
    printf("\t\t\t\t               +------------------------+\n");
}



//coba sorting
void coba_sorting_fix(){
    int temp_kode_transaksi;
    char temp_nama_barang [100];
    int temp_harga_barang;
    int temp_jumlah_barang;

    struct data *temp;

    int pilihan;
    printf("\t\t\t\t               urutkan berdasarkan\n\n");
    printf("\t\t\t\t               1. kode transaksi\n");
    printf("\t\t\t\t               2. nama barang \n");
    printf("\t\t\t\t               3. harga barang\n");
    printf("\t\t\t\t               4. jumlah barang\n\n");
    printf("\t\t\t\t               masukkan pilihan: "); scanf("%d", &pilihan);

    switch(pilihan){
    case 1: //kode transaksi
        for(current = head; current!= NULL; current = current->next)
        {
            for(temp=current->next; temp!=NULL; temp=temp->next)
            {
                if(current->kode_transaksi > temp->kode_transaksi)
                {

                    temp_kode_transaksi = current->kode_transaksi;
                    current->kode_transaksi = temp->kode_transaksi;
                    temp->kode_transaksi = temp_kode_transaksi;

                    strcpy(temp_nama_barang,current->nama_barang);
                    strcpy(current->nama_barang, temp->nama_barang);
                    strcpy(temp->nama_barang, temp_nama_barang);


                    temp_harga_barang = current->harga_barang;
                    current->harga_barang = temp->harga_barang;
                    temp->harga_barang = temp_harga_barang;


                    temp_jumlah_barang = current->jumlah_barang;
                    current->jumlah_barang = temp->jumlah_barang;
                    temp->jumlah_barang = temp_jumlah_barang;


                }
            }
        }


    break;

    case 2: //nama barang
        for(current = head; current!= NULL; current = current->next)
        {
            for(temp=current->next; temp!=NULL; temp=temp->next)
            {
                if(strcmp(current->nama_barang, temp->nama_barang) > 0)
                {

                    temp_kode_transaksi = current->kode_transaksi;
                    current->kode_transaksi = temp->kode_transaksi;
                    temp->kode_transaksi = temp_kode_transaksi;

                    strcpy(temp_nama_barang,current->nama_barang);
                    strcpy(current->nama_barang, temp->nama_barang);
                    strcpy(temp->nama_barang, temp_nama_barang);


                    temp_harga_barang = current->harga_barang;
                    current->harga_barang = temp->harga_barang;
                    temp->harga_barang = temp_harga_barang;


                    temp_jumlah_barang = current->jumlah_barang;
                    current->jumlah_barang = temp->jumlah_barang;
                    temp->jumlah_barang = temp_jumlah_barang;


                }
            }
        }



    break;

    case 3: //harga barang
        for(current = head; current!= NULL; current = current->next)
        {
            for(temp=current->next; temp!=NULL; temp=temp->next)
            {
                if(current->harga_barang > temp->harga_barang)
                {

                    temp_kode_transaksi = current->kode_transaksi;
                    current->kode_transaksi = temp->kode_transaksi;
                    temp->kode_transaksi = temp_kode_transaksi;

                    strcpy(temp_nama_barang,current->nama_barang);
                    strcpy(current->nama_barang, temp->nama_barang);
                    strcpy(temp->nama_barang, temp_nama_barang);


                    temp_harga_barang = current->harga_barang;
                    current->harga_barang = temp->harga_barang;
                    temp->harga_barang = temp_harga_barang;


                    temp_jumlah_barang = current->jumlah_barang;
                    current->jumlah_barang = temp->jumlah_barang;
                    temp->jumlah_barang = temp_jumlah_barang;


                }
            }
        }


    break;

    case 4: //jumlah barang
        for(current = head; current!= NULL; current = current->next)
        {
            for(temp=current->next; temp!=NULL; temp=temp->next)
            {
                if(current->jumlah_barang > temp->jumlah_barang)
                {

                    temp_kode_transaksi = current->kode_transaksi;
                    current->kode_transaksi = temp->kode_transaksi;
                    temp->kode_transaksi = temp_kode_transaksi;

                    strcpy(temp_nama_barang,current->nama_barang);
                    strcpy(current->nama_barang, temp->nama_barang);
                    strcpy(temp->nama_barang, temp_nama_barang);


                    temp_harga_barang = current->harga_barang;
                    current->harga_barang = temp->harga_barang;
                    temp->harga_barang = temp_harga_barang;


                    temp_jumlah_barang = current->jumlah_barang;
                    current->jumlah_barang = temp->jumlah_barang;
                    temp->jumlah_barang = temp_jumlah_barang;


                }
            }
        }


    break;


    default:
        printf("\n\n\t\t\t\t               pilihan tidak ada \n\n");
        system("pause >nul | echo \t\t\t\t               enter untuk kembali . . .");
        break;
    } // milik case


}


void coba_searching(){
    int pilihan, kode_transaksi, harga_barang, jumlah_barang;
    char nama_barang[100];
    //struct data *temp = head;
    current = head;
    system("cls");
    waktu();
    printf("\t\t\t\t\t            MENCARI DATA                     \n\n");
    printf("\t\t\t\t                  cari berdasarkan   \n");
    printf("\t\t\t\t                 ------------------\n");
    printf("\t\t\t\t                |1. kode transaksi |\n");
    printf("\t\t\t\t                |2. nama barang    |\n");
    printf("\t\t\t\t                |3. harga barang   |\n");
    printf("\t\t\t\t                |4. jumlah barang  |\n");
    printf("\t\t\t\t                 ------------------\n");
    printf("\t\t\t\t                     pilihan: ");
    scanf("%d", &pilihan);

    switch(pilihan)
    {

    case 1:
        printf("\t\t\t\t               masukkan kode transaksi: ");
        scanf("%d", &kode_transaksi);
        current = head;
        printf("\n\n");
        printf("\t\t    += = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =+\n");
        printf("\t\t    Kode Transaksi\tNama Barang\tHarga Barang\tJumlah Barang\tTotal\n\n");
        while(current!=NULL)
        {
            if(current->kode_transaksi ==  kode_transaksi)
            {
                    printf("\t             %i\t\t\t%s\t\t%i\t\t%i\t\t%i       \n\n", current->kode_transaksi, current->nama_barang, current->harga_barang, current->jumlah_barang, current->harga_barang*current->jumlah_barang);

            }
            current = current->next;
        }
        printf("\t\t    += = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =+\n");

        system("pause >nul | echo \t\t\t\t              enter untuk melanjutkan");
    break; //case 1

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    case 2:
        printf("\t\t\t\t               masukkan nama barang: ");
        fflush(stdin);
        gets(nama_barang);
        current = head;
        printf("\n\n");
        printf("\t\t    += = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =+\n");
        printf("\t\t    Kode Transaksi\tNama Barang\tHarga Barang\tJumlah Barang\tTotal\n\n");
        while(current!=NULL)
        {
            if(strcmp(current->nama_barang, nama_barang) == 0)
            {
                    printf("\t             %i\t\t\t%s\t\t%i\t\t%i\t\t%i       \n\n", current->kode_transaksi, current->nama_barang, current->harga_barang, current->jumlah_barang, current->harga_barang*current->jumlah_barang);

            }
            current = current->next;
        }
        printf("\t\t    += = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =+\n");
        system("pause >nul | echo \t\t\t\t              enter untuk melanjutkan");
    break; //case 2

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    case 3:
        printf("\t\t\t\t               masukkan harga barang: ");
        scanf("%d", &harga_barang);
        current = head;
        printf("\n\n");
        printf("\t\t    += = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =+\n");
        printf("\t\t    Kode Transaksi\tNama Barang\tHarga Barang\tJumlah Barang\tTotal\n\n");
        while(current!=NULL)
        {
            if(current->harga_barang == harga_barang)
            {

                    printf("\t             %i\t\t\t%s\t\t%i\t\t%i\t\t%i       \n\n", current->kode_transaksi, current->nama_barang, current->harga_barang, current->jumlah_barang, current->harga_barang*current->jumlah_barang);

            }
            current = current->next;
        }
        printf("\t\t    += = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =+\n");
        system("pause >nul | echo \t\t\t\t              enter untuk melanjutkan");

    break; //case 3


    case 4:

        printf("\t\t\t\t               masukkan jumlah barang: ");
        scanf("%d", &jumlah_barang);
        current = head;
        printf("\n\n");
        printf("\t\t    += = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =+\n");
        printf("\t\t    Kode Transaksi\tNama Barang\tHarga Barang\tJumlah Barang\tTotal\n\n");
        while(current!=NULL)
        {
            if(current->jumlah_barang == jumlah_barang)
            {

                    printf("\t             %i\t\t\t%s\t\t%i\t\t%i\t\t%i       \n\n", current->kode_transaksi, current->nama_barang, current->harga_barang, current->jumlah_barang, current->harga_barang*current->jumlah_barang);

            }
            current = current->next;
        }
        printf("\t\t    += = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =+\n");
        system("pause >nul | echo \t\t\t\t              enter untuk melanjutkan");


    break; //case 4

    default:
        printf("\n\n");
        printf("\t\t\t\t                  pilihan tidak ada \n\n");
        system("pause >nul | echo \t\t\t\t              enter untuk melanjutkan");
    break; //default
    }
    strcpy(riwayat[no_riwayat],"Mencari Data");
    no_riwayat++;
}

void hapusSemua(){
	while(head!=NULL){
		hapusKepala();
	}
}

void main()
{
//user password
char user[10],pass[10], karakter;
int i;

//input pilihan menu, banyak data
int pilihan_menu, banyak_data;
int pilih;
//input database
int kode_transaksi;
char nama_barang [30];
int harga_barang;
int jumlah_barang;
//int total_harga = harga_barang*jumlah_barang;

//banyak data tambahan
int banyak_data_tambahan;



    waktu();
    system("color F0");
    printf("\n\n\n\n");
    printf("\t\t\t\t= = = = = = = = = = = = = = = = = = = = = = = = = =\n");
    printf("\t\t\t\t|        DATABASE TOKO SPAREPART MOTOR            |\n");
    printf("\t\t\t\t|                    MBUAHMU                      |\n");
    printf("\t\t\t\t= = = = = = = = = = = = = = = = = = = = = = = = = =\n");
    printf("\t\t\t\t               Masukan Username : ");
    scanf("%s",&user);
    printf("\t\t\t\t               Masukan Password : ");
    //scanf("%s",&pass);
    for(i = 0;i < 5;i++)
    {
        karakter = getch();
        if(karakter == 5)
        break;
        pass[i] = karakter;
        karakter = '*' ;
        printf("%c", karakter);
    }
    pass[i] = '\0';

    if(strcmp(user,"admin") == 0 && strcmp(pass,"admin") == 0){

        printf("\n\n\t\t\t\t\t   akses diterima, selamat datang\n\n");
        system("pause >nul | echo \t\t\t\t              enter untuk melanjutkan"); system("cls");
        do{
        system("cls");
        waktu();
        printf("\n\n\n\n");
        system("color F0");
        printf("\t\t\t\t= = = = = = = = = = = = = = = = = = = = = = = = = =\n");
        printf("\t\t\t\t|        DATABASE TOKO SPAREPART MOTOR            |\n");
        printf("\t\t\t\t|                    MBUAHMU                      |\n");
        printf("\t\t\t\t= = = = = = = = = = = = = = = = = = = = = = = = = =\n");
        printf("\t\t\t\t|                 1. Buat database                |\n");
        printf("\t\t\t\t|                 2. Tampilkan database           |\n");
        printf("\t\t\t\t|                 3. Tambah data baru             |\n");
        printf("\t\t\t\t|                 4. Hapus data                   |\n");
        printf("\t\t\t\t|                 5. Edit data                    |\n");
        printf("\t\t\t\t|                 6. Cari data                    |\n");
        printf("\t\t\t\t|                 7. Riwayat aktivitas            |\n");
        printf("\t\t\t\t|                 8. Urutkan data                 |\n");
        printf("\t\t\t\t|                 9. Keluar                       |\n");
        printf("\t\t\t\t= = = = = = = = = = = = = = = = = = = = = = = = = =\n");
        printf("\t\t\t\tpilihan: ");
        scanf("%d", &pilihan_menu);
        switch(pilihan_menu)
        {
        case 1: //buat database
            system("cls");
            printf("\t\t\t\t\t              MEMBUAT DATA                     \n\n");
            printf("\t\t\t\tinput banyak data yang ingin dibuat(max. 4): ");
            scanf("%d", &banyak_data);
            printf("\n\n");
            hapusSemua();
            if(banyak_data <= 4)
            {
                for(int i = 1; i <= banyak_data; i++)
                {
                    printf("\t\t\t\t              DATA BARANG ke-%d\n", i);

                    printf("\t\t\t\t              Kode Transaksi\t: ");
                    scanf("%d",&kode_transaksi);

                    printf("\t\t\t\t              Nama Barang \t: ");
                    fflush(stdin);
                    gets(nama_barang);

                    printf("\t\t\t\t              Harga Barang \t: ");
                    scanf("%d",&harga_barang);

                    printf("\t\t\t\t              Jumlah Barang \t: ");
                    scanf("%d",&jumlah_barang);

                    printf("\t\t\t\t              Total Harga \t: %d \n\n", jumlah_barang*harga_barang);
                    creat (kode_transaksi,nama_barang,harga_barang,jumlah_barang, jumlah_barang*harga_barang);


                }
                strcpy(riwayat[no_riwayat],"Membuat Data");
                no_riwayat++;
                system("pause >nul | echo \t\t\t\t               enter untuk kembali "); system("cls");
            }
            else
            {
                printf("\t\t\t\t                    maksimal adalah 4 \n\n");
                system("pause >nul | echo \t\t\t\t                   enter untuk kembali "); system("cls");

            }
            break;

        case 2: //tampil
            system("cls");
            waktu();
            printf("\t\t\t                            MELIHAT DATA                     \n");
            printf("\t\t    += = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =+\n");
            printf("\t\t    |                      DATABASE TOKO SPAREPART MOTOR                      |\n");
            printf("\t\t    |                                 MBUAHMU                                 |\n");
            printf("\t\t    += = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =+\n");
            printf("\t\t    Kode Transaksi\tNama Barang\tHarga Barang\tJumlah Barang\tTotal\n\n");
            read();
            printf("\t\t    += = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =+\n");
            strcpy(riwayat[no_riwayat],"Melihat Data");
            no_riwayat++;
            printf("\n\n");
            system("pause >nul | echo \t\t\t\t               enter untuk kembali"); system("cls");
        break;

        case 3: //tambah
            system("cls");
            waktu();
            printf("\t\t\t                            TAMBAH DATA                     \n");
            printf("\t\t    += = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =+\n");
            printf("\t\t    |                      DATABASE TOKO SPAREPART MOTOR                      |\n");
            printf("\t\t    |                                 MBUAHMU                                 |\n");
            printf("\t\t    += = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =+\n");
            printf("\t\t    Kode Transaksi\tNama Barang\tHarga Barang\tJumlah Barang\tTotal\n\n");
            read();
            printf("\t\t    += = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =+\n");
            printf("\t\tinput banyak data yang ingin ditambahkan(max. 4): ");
            scanf("%d", &banyak_data_tambahan);
            printf("\n\n");

            if(banyak_data_tambahan <= 4)
            {
                for(int i = 1; i <= banyak_data_tambahan; i++)
                {
                    printf("\t\t\t\t              DATA TAMBAH BARANG ke-%d\n", i);


                    printf("\t\t\t\t              Kode Transaksi\t: ");
                    scanf("%d",&kode_transaksi);

                    printf("\t\t\t\t              Nama Barang \t: ");
                    fflush(stdin);
                    gets(nama_barang);

                    printf("\t\t\t\t              Harga Barang \t: ");
                    scanf("%d",&harga_barang);

                    printf("\t\t\t\t              Jumlah Barang \t: ");
                    scanf("%d",&jumlah_barang);

                    printf("\t\t\t\t              Total Harga \t: %d \n\n", jumlah_barang*harga_barang);
                    creat(kode_transaksi,nama_barang,harga_barang,jumlah_barang, jumlah_barang*harga_barang);

                }
                strcpy(riwayat[no_riwayat],"Menambahkan Data");
                no_riwayat++;
                system("pause >nul | echo \t\t\t\t               enter untuk kembali"); system("cls");
            }
            else
            {
                printf("\t\t\t\t              maksimal adalah 4 \n");
                system("pause >nul | echo \t\t\t\t               enter untuk kembali"); system("cls");

            }



        break;


        case 4: //hapus
            system("cls");
            waktu();
            printf("\t\t\t                            HAPUS DATA                     \n");
            printf("\t\t    += = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =+\n");
            printf("\t\t    |                      DATABASE TOKO SPAREPART MOTOR                      |\n");
            printf("\t\t    |                                 MBUAHMU                                 |\n");
            printf("\t\t    += = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =+\n");
            printf("\t\t    Kode Transaksi\tNama Barang\tHarga Barang\tJumlah Barang\tTotal\n\n");
            read();
            printf("\t\t    += = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =+\n");
            printf("\t\t    pilih kode transaksi dari data yang ingin dihapus:");
            scanf("%d", &kode_transaksi);
            hapus_data(kode_transaksi);
            strcpy(riwayat[no_riwayat],"Menghapus Data");
            no_riwayat++;



        break;



        case 5: //edit
            system("cls");
            waktu();
            printf("\t\t\t                            MENU EDIT                      \n");
            printf("\t\t    += = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =+\n");
            printf("\t\t    |                      DATABASE TOKO SPAREPART MOTOR                      |\n");
            printf("\t\t    |                                 MBUAHMU                                 |\n");
            printf("\t\t    += = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =+\n");
            printf("\t\t    Kode Transaksi\tNama Barang\tHarga Barang\tJumlah Barang\tTotal\n\n");
            read();
            printf("\t\t    += = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =+\n");
            printf("\n\t\t\t\t               masukkan kode transaksi: ");
            scanf("%d", &kode_transaksi);
            printf("\n\n");
            printf("\t\t\t\t               1. ganti nama barang\n");
            printf("\t\t\t\t               2. ganti harga barang\n");
            printf("\t\t\t\t               3. ganti jumlah barang\n\n");
            printf("\t\t\t\t               masukkan pilihan: ");
            scanf("%d", &pilih);
            if(pilih == 1)
            {
                fflush(stdin);
                update_nama_barang(kode_transaksi);

            }
            else if(pilih == 2)
            {
                update_harga_barang(kode_transaksi);

            }
            else if(pilih == 3)
            {
                update_jumlah_barang(kode_transaksi);

            }
            strcpy(riwayat[no_riwayat],"Mengedit Data");
            no_riwayat++;
        break;



        case 6:
        coba_searching();

        break;



        case 7:
            system("cls");
            waktu();
            history();
            printf("\n");
            system("pause >nul | echo \t\t\t\t               enter untuk kembali"); system("cls");

        break;



        case 8:
            system("cls");
            waktu();
			printf("\t\t\t                            MENU URUTKAN                      \n");
            printf("\t\t    += = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =+\n");
            printf("\t\t    |                      DATABASE TOKO SPAREPART MOTOR                      |\n");
            printf("\t\t    |                                 MBUAHMU                                 |\n");
            printf("\t\t    += = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =+\n");
            printf("\t\t    Kode Transaksi\tNama Barang\tHarga Barang\tJumlah Barang\tTotal\n\n");
            read();
            printf("\t\t    += = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =+\n");

			coba_sorting_fix();
			printf("\n");
			system("pause >nul | echo \t\t\t\t               enter untuk kembali");
			strcpy(riwayat[no_riwayat],"Mengurutkan Data");
            no_riwayat++;
			break;

        break;


        case 9:
            system("cls");
            printf("\n\n\n\n\n\n\n");
            char mksh[]={"\t\t\t\t                  TERIMA KASIH\n\n"};
            char gilang[]={"\t\t\t\t          Gilang Agung Saputra 672019229\n\n"};
            int i;
            double j;
            for(i=0;mksh[i]!='\0';i++)
            {
                printf("%c",mksh[i]);
                for(j=0;j<=1000000;j++)
                {

                }
            }

            for(i=0;gilang[i]!='\0';i++)
            {
                printf("%c",gilang[i]);
                for(j=0;j<=1000000;j++)
                {

                }
            }
            //printf("\t\t\t\t                  TERIMA KASIH\n\n");
            //printf("\t\t\t\t          Gilang Agung Saputra 672019229\n\n");
            system("pause >nul | echo \t\t\t\t          enter dua kali untuk mematikan");
        break;

        default:
        printf("\n-- Menu tidak ada --\n");
        break;
        } // milik switch
        //system("pause >nul | echo \t\t\t\t               enter untuk kembali . . ."); system("cls");
        } while(pilihan_menu!=9);

    }// milik sandi
    else{
         printf("\n\n\t\t\t\t\t  Username atau Password tidak sesuai\n");
         system("pause >nul | echo \t\t\t\t              enter untuk mengulang"); system("cls");
         system("cls");
         main();

    }
}//milik main

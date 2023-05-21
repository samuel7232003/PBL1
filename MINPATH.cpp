#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <winbgim.h>
#include <math.h>

const int R=10;
struct toado{
    int tx;
    int ty;
};
int n, m,l=1, check=0;
int e[1001][3], a[1001][3], d=0;


//Ham thiet lap
void setcolor(int backgound_color, int text_color){
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    int color_code = backgound_color * 16 + text_color;
    SetConsoleTextAttribute(hStdout, color_code);
}
 
void info(){
 	int i;
 	setcolor(0,9);
 	printf("\n%9c",201);
 	for (i=0;i<=85;i++) printf("%c",205);
 	printf("%c",187);
 	printf("\n        %c %86c",186,186);
 	printf("\n        %c                             DO AN LAP TRINH TINH TOAN                                %c",186,186);
 	printf("\n        %c                   DE TAI: Cay phu nho nhat va thuat toan Kruskal                     %c",186,186);
 	printf("\n        %c %86c",186,186);
 	printf("\n        %c       Sinh vien thuc hien:                       Giao vien huong dan:                %c",186,186);
 	printf("\n        %c           %c Nguyen Pham Phuc Tan                       %c Nguyen Van Nguyen           %c",186,45,45,186);
 	printf("\n        %c           %c Le Viet Thanh  %59c",186,45,186);
 	printf("\n        %c %86c",186,186);
 	printf("\n        %c",200);
 	for (i=0;i<=85;i++) printf("%c",205);
 	printf("%c\n",188);
}


//Ham thiet lap do thi 
float khoancach(int x1, int y1, int x2, int y2){
	return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
} 

void veduong(int x1, int y1, int x2, int y2, int color){
	float xa,ya;
	xa=x2;
	ya=y2; 
	setcolor(14);
	setfillstyle(SOLID_FILL,14);
	line(x2,y2,x2,y2);
	setcolor(color);
	setfillstyle(SOLID_FILL,color);
	line(x2,y2,x2,y2);
	line(x1,y1,xa,ya);
}

void introngso(int x1, int y1, int x2, int y2, int i){
	float x3,y3;
	char s[100];
	setbkcolor(0);
	x3 = (x1+x2)/2;
	y3 = (y1+y2)/2;
	if (x1>x2) y3=y3+10; 
	if (x1<x2) y3=y3-10;
	if (y1>y2) x3=x3+10;
	if (y1<y2) x3=x3-10;
	sprintf(s,"%d",i);
    outtextxy(x3,y3,s);
}

//Kiem tra loi


void PrintBug(int &check){
	setcolor(0,12);
	switch (check){
		case 1:printf("\n                                         Loi so dinh qua lon!!!\n"); break;
		case 2:printf("\n                                    Loi do thi khong lien thong!!!\n"); break;
		case 3:printf("\n                                 Loi ki tu khong dung kieu du lieu!!!\n");break;
	} 
	printf("                                          Vui long nhap lai.\n");
	system("pause");
	system("cls");
	info();
	check=0; 
}

void ktrlienthong(int e[1001][3], int &check){
	for(int i=1;i<=n;i++){
		check=2; 
        for(int j=1;j<=m;j++){
        	if(i==e[j][1] || i==e[j][2]){
        		check=0; 
			}
		}
		if(check==2){
		    i=n+1;
		    check=2; 
	    }
	
    } 
}

void checktype(int &m,int &n,int e[1001][3],int &check){
	if(m<=0||n<=0) check=3;
	for(int i=1;i<=m;i++){
		if(e[i][1]<=0||e[i][2]<=0||e[i][3]==0) check=3;
	}
	
}

// Ham reset
void reset(int &l, int &d){
	l=1; d=0;
}

//Ham nhap

void get(int &n,int &m, int e[1001][3]){
    printf("               So dinh: ");scanf("%d",&n);
    printf("               So canh: ");scanf("%d",&m);
    if(n<0 || m<0){
        reset(n,m);
        check=3;
	}
    printf("               Nhap ma tran trong so:\n");
    setcolor(0,8);
    printf("          (Nhap ma tran: moi dong la moi canh lan luot: 'Diem dau(<=1), Diem sau(<=1), Trong so' cua canh do!)\n");
    for(int i=1;i<=m;i++){
        int x, y, w;
        printf("               "); 
        scanf("%d %d %d",&x,&y,&w);
		if(x>n || y>n) {
			reset(n, m);
			check=1;
		} 
        e[i][1]=x;e[i][2]=y;e[i][3]=w;
	}
}

void getfile(int e[1001][3], int &n, int &m){
	int v;
	FILE *fi;
	scanf("%d",&v);
    if(v==1)fi=fopen("TEST1.txt","r");
    if(v==2)fi=fopen("TEST2.txt","r");
	if(v==3)fi=fopen("TEST3.txt","r");
	if(v==4)fi=fopen("TEST4.txt","r");
	if(v==5)fi=fopen("TEST5.txt","r");
	if(v==6)fi=fopen("TEST6.txt","r");
	if(v==7)fi=fopen("TEST7.txt","r");
	if(v==8)fi=fopen("TEST8.txt","r");
	if(v==9)fi=fopen("TEST9.txt","r");
	if(v==10)fi=fopen("TEST10.txt","r");
	fscanf(fi,"%d %d ",&n,&m);
	    if(n<=0 || m<=0){
        reset(n,m);
        check=3;
	}
	for(int i=1;i<=m;i++){
		fscanf(fi,"%d %d %d ",&e[i][1],&e[i][2],&e[i][3]);
		if(e[i][1]>n || e[i][2]>n) {
		    reset(n, m);
		    check=1;  
		} 
	}
	fclose(fi);
	setcolor(0,14); 
	printf("          Da lay du lieu tu file!\n\n ");
}

// Ham nhap tu do thi
void nhapdinh(int n, toado C[]){
	int x,y,i;
	char s[100];
    initwindow(640,480);
    cleardevice();
    outtextxy(200,30,"DO AN LAP TRINH TINH TOAN");
    outtextxy(240,40,"-------------");
    setcolor(10);
    setbkcolor(10);
    setfillstyle(1,10);
    settextjustify(1,1);
    i=1;
    while (i<=n){
    	delay(0.0001);
        if (ismouseclick(WM_LBUTTONDOWN)){
            getmouseclick(WM_LBUTTONDOWN, x, y);
            C[i].tx=x;
            C[i].ty=y;
            circle(x,y,R);
            floodfill(x,y,10);
            setcolor(0);
            sprintf(s,"%d",i);
            outtextxy(x,y,s);
            setcolor(10);
            i++;
        }
	}	
}

void nhapcanh(int n, int m, toado C[]){	
	int dau,cuoi,x,y,i,j;
	for (i=1;i<=m;i++){
		dau=0;cuoi=0;
		while (cuoi==0){
			delay(0.0001);	
			if (ismouseclick(WM_LBUTTONDOWN)){
				getmouseclick(WM_LBUTTONDOWN, x, y);
				for (j=1;j<=n;j++){
					if (khoancach(C[j].tx,C[j].ty,x,y)<=R){
						if (dau==0) dau=j;
						else if (dau!=j) cuoi=j;		
					}
				}
			}
		}
		veduong(C[dau].tx,C[dau].ty,C[cuoi].tx,C[cuoi].ty,15);
		e[i][1]=dau; e[i][2]=cuoi; 
		printf("\n            Canh %d:Nhap khoan cach tu %d den %d: ",i,dau,cuoi);
		scanf("%d",&e[i][3]);
		introngso(C[dau].tx,C[dau].ty,C[cuoi].tx,C[cuoi].ty,e[i][3]);
	}
}

void nhapdothi(toado C[]){
 	int i,j;
 	printf("               Nhap so dinh: ");
	scanf("%d",&n);
	nhapdinh(n,C);
	printf("\n               Nhap so canh: ");
	scanf("%d",&m); 
	nhapcanh(n,m,C);
}

//Ham luu du lieu tu do thi vao file test
 
void saveinput(int e[1001][3], int &n, int &m){
	int v;
	FILE *fi;
	scanf("%d",&v);
    if(v==1)fi=fopen("TEST1.txt","w");
    if(v==2)fi=fopen("TEST2.txt","w");
	if(v==3)fi=fopen("TEST3.txt","w");
	if(v==4)fi=fopen("TEST4.txt","w");
	if(v==5)fi=fopen("TEST5.txt","w");
	if(v==6)fi=fopen("TEST6.txt","w");
	if(v==7)fi=fopen("TEST7.txt","w");
	if(v==8)fi=fopen("TEST8.txt","w");
	if(v==9)fi=fopen("TEST9.txt","w");
	if(v==10)fi=fopen("TEST10.txt","w");
	fprintf(fi,"%d %d\n",n,m);
	for(int i=1;i<=m;i++){
		fprintf(fi,"%d %d %d \n",e[i][1],e[i][2],e[i][3]);
	}
	fclose(fi);
	setcolor(0,14); 
	printf("          Da lay du lieu tu file!\n\n ");
}

//Ham kruskal

void swap(int &a,int &b){
	int c=a;a=b;b=c;
}

void sort(int e[1001][3], int &m){
    for(int j=m; j>=1;j--) { 
        int stop=1; 
        if(e[j][3]<e[j-1][3] && e[j-1][3]!=0){
            for(int c=1;c<=3;c++){
                swap(e[j][c],e[j-1][c]);
            }
            stop=0;
        }
        if(stop==0) j=m+1; 
    }
}

void kruskal(int &n, int &m, int &d, int e[1001][3], int a[1001][3], int &l){
	sort(e, m);
	int pa[n+1];
	for(int t=1;t<=n;t++){
        pa[t]=t;
    }  
    for(int i=1;i<=m;i++){
    	int p=e[i][1];
	    int q=e[i][2];
    	if(pa[p]!=pa[q]){
    		int o=pa[q];
    		for(int k=1;k<=n;k++){
    			if(pa[k]==o){
    				pa[k]=pa[p];
				}
			}
		    d+=e[i][3];
		    a[l][1]=e[i][1]; a[l][2]=e[i][2]; a[l][3]=e[i][3]; l++; 
		}
	}
}

//Ham xuat 

void output(int a[1001][3], int &d, int &l){
    printf("Cay phu nho nhat la:\n");
     
    for(int i=1;i<=l-1;i++){
    	printf("(%.0d , %.0d): %.1d\n",a[i][1], a[i][2], a[i][3]);
	}
	printf("\n\n Tong trong so: %.1d", d);
}

void fileout(int a[1001][3],int &d, int &l){
	FILE *fo= fopen("MINPATH.OUT","w");
	fprintf(fo,"Cay phu nho nhat la : \n");
	for(int i=1;i<=l-1;i++){
		fprintf(fo,"(%d,%d): %d \n",a[i][1],a[i][2],a[i][3]);
		
	}
	fprintf(fo,"Tong trong so : %d",d);
	fclose(fo);
	setcolor(0,14); 
	printf("\n\n          Da luu ket qua vao file!\n\n");
}

void xuatdothi(int n, toado C[], int a[1001][3], int &l, int &d){
	char e[100];
    for(int i=1;i<=l;i++){
    	int p= a[i][1];
    	int q= a[i][2];
 		veduong(C[p].tx,C[p].ty,C[q].tx,C[q].ty,12);
 	}
 	sprintf(e,"Tong trong so: %d",d);
 	outtextxy(100,400,e);
}

void xuatdothi2(int n, toado C[], int a[1001][3], int &l, int &d){
    nhapdinh(n, C);
    int x,y,i,j;
	for (i=1;i<=l;i++){
		int x=a[i][1];
		int y=a[i][2]; 
		introngso(C[x].tx,C[x].ty,C[y].tx,C[y].ty,a[i][3]);
	}
}
void menuin(){
	setcolor(0,14);
 	printf("\n                                  %c   CHON CACH NHAP DU LIEU   %c\n",16,17);
 	printf("\n                                        Nhan 1: Tu ban phim");
	printf("\n                                        Nhan 2: Tu file");
	printf("\n                                        Nhap 3: Tu do thi");
	printf("\n                                    Nhan phim bat ky de Ket thuc");
	printf("\n                                             -------\n");
	setcolor(0,8);
	printf("\n          Nhap yeu cau: ");
}

void menuFILE(){
	setcolor(0,2);
 	printf("\n                                  %c   CHON FILE DE LAY DU LIEU    %c\n",16,17);
 	printf("\n                           Nhan 1 : TEST1                 Nhan 2: TEST2 ");
	printf("\n                           Nhan 3 : TEST3                 Nhan 4: TEST4 ");
	printf("\n                           Nhan 5 : TEST5                 Nhan 6: TEST6 ");
	printf("\n                           Nhan 7 : TEST7                 Nhan 8: TEST8 ");
	printf("\n                           Nhan 9 : TEST9                 Nhan 10: TEST10");
	printf("\n                                             -------\n");
	setcolor(0,8);
	printf("\n          Nhap yeu cau: ");
}

void menuout(){
	setcolor(0,11);
	printf("\n              XUAT KET QUA CAY PHU NHO NHAT\n");
	printf("\n            + Nhan 1: De in ket qua ra man hinh");
	printf("\n            + Nhap 2: De in ket qua vao file");
	printf("\n            + Nhap 3: De in ket qua tren do thi va luu vao file");
	printf("\n            + Nhap 4: De luu du lieu vao file test ");
	printf("\n            + Nhap 5: De nhap du lieu moi");
	printf("\n            Nhap phim bat ky de ket thuc");
	printf("\n              -------\n");
	setcolor(0,8);
	printf("\n          Nhap yeu cau: ");
}

 
int main(){
    info(); 
 	toado C[100];
 	check=0; 
 	char in,out;
    do{
 		menuin();
		setcolor(0,15);
		fflush(stdin);
		scanf("%c",&in);
		printf("\n");
		switch (in){
			case '1':{
			    get(n, m, e); 
			    break;	
			}
			case '2':{ 
			    menuFILE();
			    getfile(e,n,m);
			   	break;
			} 
			case '3':{
				nhapdothi(C);
				break;
				
			
			}
			default: return 0;
		}
		if (check==0) checktype(m,n,e,check);
        if (check==0) ktrlienthong(e,check);
		if (check==0){
 		    kruskal(n, m, d, e, a, l);
            do{
			    menuout(); 
			    setcolor(0,15);
			    fflush(stdin);
			    scanf("%c",&out);
		    	printf("\n");
		    	switch (out){
				    case '1':{
				    	output(a, d, l);
				    	break;
				    }
				    case '2':{
				    	output(a, d, l);
				    	fileout(a, d, l);
			        	break;
				    }
				    case '3':{
				    	output(a, d, l);
				    	fileout(a, d, l);
				    	if(in=='2'||in=='1') {
						    xuatdothi2(n,C,a,l,d);
						    in='3';
					    }
				        xuatdothi(n,C,a,l,d);
				    	break;
				    }
				    case '4':{
						menuFILE();
						saveinput(e,n,m);
						break;
					}
				    case '5':{
				    	if(in=='3') closegraph();
				    	system("pause");
			            system("cls");
			            reset(l, d);
		                info();
						break;
					}
					
				    default: return 0;
			    }
			    printf("\n                -------\n\n");
		    }
		    while (out=='1' || out=='2' || out=='3'||out=='4');
		}
		else PrintBug(check); 
	}
	while (in=='1' || in=='2' || in=='3');
 	return 0;
}

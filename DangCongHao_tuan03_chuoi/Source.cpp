#include<stdio.h>
#include<conio.h>

#define MAX 100

struct sv
{
	int mssv;
	char hovaten[50];
	float toan, ly, hoa;
};
void nhapmangsinhvien(sv *&a, int &n)
{
	int chon;
	FILE*f;
	a = new sv[100];
	printf("1. nhap tu ban phim\n");
	printf("2. ghi du lieu vao file\n");
	printf("3. doc du lieu tu file\n");
	printf("chon chuc nang thuc hien: ");
	scanf_s("%d", &chon);
	switch (chon)
	{
	case 1:
		printf("nhap ma so sinh vien: ");
		scanf_s("%d", &(a + n)->mssv);
		fseek(stdin, 0, SEEK_END);
		printf("nhap ho va ten: ");
		gets_s((a + n)->hovaten);
		printf("nhap diem toan ly hoa: ");
		scanf_s("%f %f %f", &(a + n)->toan, &(a + n)->ly, &(a + n)->hoa);
		n++;
		break;
	case 2:
		fopen_s(&f, "data.txt", "wb");
		if (f != NULL)
			fwrite(&a, sizeof(sv), n, f);
		fclose((f));
		printf("da hoan thanh");
		break;
	case 3:

		fopen_s(&f, "data.txt", "wb");
		if (f != NULL)
		{
			while (!feof(f))
				if (fwrite((a + n), sizeof(sv), 1, f))
					n++;
		}
		fclose((f));
		break;
	default:
		break;
	}
}
void tong(sv *&a, int &n)
{
	int chon;
	float dtb;
	float KQ = 0;
	int KT = 0;
	printf("1. tinh diem trung binh\n");
	printf("2. danh sach dau\n");
	printf("3. danh sach rot\n");
	printf("chon chuc nang: ");
	scanf_s("%d", &chon);
	switch (chon)
	{
	case 1:
			KQ = (a->toan + a->ly + a->hoa) / 3;
			if (a->toan * a->ly * a->hoa != 0)
				printf("Diem trung binh la: %f", KQ);
		break;
	case 2:
		printf("nhap diem trung binh: ");
		scanf_s("%.2f", &dtb);
		printf("DANH SACH DAU");
		printf("maso\thoten\tDiemtrungbinh\n");
		printf("----------------------------");
		for (int i = 0; i < n; i++)
		{
			if (dtb==KQ && KT)
			{
				printf("%d\t%s\t%f\n", a->mssv, a->hovaten, dtb);
			}	
		}
		break;
	default:
		break;
	}
}
void inds(sv *&a, int n)
{
	printf("maso\thoten\ttoan\tly\thoa\n");
	printf("---------------------------------------\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d\t%s\t%.2f\t%.2f\t%.2f\n", a->mssv, a->hovaten, a->toan, a->ly, a->hoa);
	}
	printf("Da hoan thanh\n");
}
void main()
{
	sv *a = NULL;
	int sl = 0;
	int chon = 1;

	do
	{
		printf("\n-------CHUONG TRINH QUAN LY SINH VIEN-------\n");
		printf("1. nhap mang sinh vien\n");
		printf("2. tim sinh vien co diem trung binh lon nhat\n");
		printf("3. in danh sach sinh vien\n");
		printf("0.thoat chuong trinh\n");
		printf("---------------------------------------------\n");
		printf("con chuc nang muon thuc hien: ");
		scanf_s("%d", &chon);
		switch (chon)
		{
		case 0: return;
		case 1:nhapmangsinhvien(a, sl);
			break;
		case 2:tong(a, sl);
			break;
		case 3:inds(a, sl);
			break;
		default:
			break;
		}
	}
	while (chon != 0);

	_getch();
}
#include <iostream>
#include <cmath>

using namespace std;

// 1. Định nghĩa cấu trúc Đơn thức
struct DonThuc
{
    int heso;       // hệ số
    int somu;       // số mũ
};

// 2. Định nghĩa cấu trúc Đa thức
struct DaThuc
{
    int n;          // số đơn thức trong đa thức
    DonThuc *p;     // mảng các đơn thức
};

// 3. Hàm rút gọn đa thức
void RutGon(DaThuc &F)
{
        // Sắp xếp đa thức theo thứ tự giảm dần số mũ
    for (int i=0; i<F.n-1; i++)
        for (int j=i+1; j<F.n; j++)
            if (F.p[i].somu < F.p[j].somu)
            {
                DonThuc temp = F.p[i];
                F.p[i] = F.p[j];
                F.p[j] = temp;
            }

    //  Nếu các số mũ trùng nhau thì cộng rồi xoá
    for (int i=0; i<F.n-1; i++)
    {
        if (F.p[i].somu == F.p[i+1].somu)
        {
            F.p[i].heso += F.p[i+1].heso;
            for (int j = i+1; j<F.n-1; j++)
            {
                F.p[j].heso = F.p[j+1].heso;
                F.p[j].somu = F.p[j+1].somu;
            }
            F.n--;
        }
    }
}

// 4. Hàm nhập một đa thức
void NhapDaThuc(DaThuc &F)
{
    cout << "Nhap so don thuc trong da thuc: ";
    cin >> F.n;

    F.p = new DonThuc[F.n];
    cout << "Nhap lan luot cac don thuc (he_so so_mu): ";
    for (int i=0; i<F.n; i++)
        cin >> F.p[i].heso >> F.p[i].somu;

    RutGon(F);

    cout << "===============================================\n\n";
}

// 5. Hàm xuất một đa thức
void XuatDaThuc(DaThuc &F)
{
    bool flag = 0;
    for (int i=0; i<F.n; i++)
    {
        // Xuất hệ số
        if (F.p[i].heso == 0)
            continue;

        else if (F.p[i].heso == -1)
        {
            cout << "-1";
            flag = 1;
        }
        else if (F.p[i].heso > 0)
        {
            if (flag == 1)
                cout << "+";
            if (F.p[i].heso != 1 || F.p[i].somu == 0) cout << F.p[i].heso;
            flag = 1;
        }
        else
            {
                cout << F.p[i].heso;
                flag = 1;
            }

        // Xuất số mũ
        if (F.p[i].somu != 0)
            {
                if (F.p[i].somu != 1)
                    cout << "x^" << F.p[i].somu;
                else
                    cout << "x";
                flag = 1;
            }
    }
    cout << endl;
}

// 6. Hàm trả về đa thức tổng
DaThuc congDaThuc(DaThuc dt1, DaThuc dt2)
{
    DaThuc dtTong;
    dtTong.n = dt1.n + dt2.n;
    dtTong.p = new DonThuc[dtTong.n];

    int i, idx1 = 0, idx2 = 0;
    for (i=0; i<dtTong.n; i++)
    {
        if (dt1.p[idx1].somu > dt2.p[idx2].somu)
        {
            dtTong.p[i].heso =  dt1.p[idx1].heso;
            dtTong.p[i].somu =  dt1.p[idx1].somu;
            idx1++;
        }

        else if (dt1.p[idx1].somu < dt2.p[idx2].somu)
        {
            dtTong.p[i].heso =  dt2.p[idx2].heso;
            dtTong.p[i].somu =  dt2.p[idx2].somu;
            idx2++;
        }

        else if (dt1.p[idx1].somu == dt2.p[idx2].somu)
        {
            dtTong.p[i].heso =  dt1.p[idx1].heso + dt2.p[idx2].heso;
            dtTong.p[i].somu =  dt1.p[idx1].somu;
            idx1++;
            idx2++;
            dtTong.n--;
        }

        if (idx1 == dt1.n || idx2 == dt2.n)
        {
            i++;
            break;
        }
    }

    while (idx1 < dt1.n)
    {
        dtTong.p[i].heso =  dt1.p[idx1].heso;
        dtTong.p[i].somu =  dt1.p[idx1].somu;
        idx1++;
        i++;
    }

    while (idx2 < dt2.n)
    {
        dtTong.p[i].heso =  dt2.p[idx2].heso;
        dtTong.p[i].somu =  dt2.p[idx2].somu;
        idx2++;
        i++;
    }

    return dtTong;
}

// 7. Hàm trả về đa thức hiệu
DaThuc truDaThuc(DaThuc dt1, DaThuc dt2)
{
    DaThuc dtHieu;
    dtHieu.n = dt1.n + dt2.n;
    dtHieu.p = new DonThuc[dtHieu.n];

    int i, idx1 = 0, idx2 = 0;
    for (i=0; i<dtHieu.n; i++)
    {
        if (dt1.p[idx1].somu > dt2.p[idx2].somu)
        {
            dtHieu.p[i].heso =  dt1.p[idx1].heso;
            dtHieu.p[i].somu =  dt1.p[idx1].somu;
            idx1++;
        }

        else if (dt1.p[idx1].somu < dt2.p[idx2].somu)
        {
            dtHieu.p[i].heso =  -dt2.p[idx2].heso;
            dtHieu.p[i].somu =  -dt2.p[idx2].somu;
            idx2++;
        }

        else if (dt1.p[idx1].somu == dt2.p[idx2].somu)
        {
            dtHieu.p[i].heso =  dt1.p[idx1].heso - dt2.p[idx2].heso;
            dtHieu.p[i].somu =  dt1.p[idx1].somu;
            idx1++;
            idx2++;
            dtHieu.n--;
        }

        if (idx1 == dt1.n || idx2 == dt2.n)
        {
            i++;
            break;
        }
    }

    while (idx1 < dt1.n)
    {
        dtHieu.p[i].heso =  dt1.p[idx1].heso;
        dtHieu.p[i].somu =  dt1.p[idx1].somu;
        idx1++;
        i++;
    }

    while (idx2 < dt2.n)
    {
        dtHieu.p[i].heso =  -dt2.p[idx2].heso;
        dtHieu.p[i].somu =  -dt2.p[idx2].somu;
        idx2++;
        i++;
    }

    return dtHieu;
}

// 8. Hàm nhân đơn thức với đa thức
DaThuc nhanDonThucVoiDaThuc(DonThuc dt1, DaThuc dt2)
{
    DaThuc dtTich;
    dtTich.n = dt2.n;
    dtTich.p = new DonThuc[dtTich.n];

    for (int i=0; i<dtTich.n; i++)
    {
        dtTich.p[i].heso = dt1.heso*dt2.p[i].heso;
        dtTich.p[i].somu = dt1.somu + dt2.p[i].somu;
    }

    return dtTich;
}

// 9. Hàm nhân đa thức với đa thức
DaThuc nhanDaThuc(DaThuc dt1, DaThuc dt2)
{
    DaThuc dtTich;
    dtTich.n = dt1.n * dt2.n;
    dtTich.p = new DonThuc[dtTich.n];

    for (int i=0; i<dtTich.n; i++)
        dtTich.p[i].heso = dtTich.p[i].somu = 0;

    for (int i=0; i<dt1.n; i++)
    {
        DaThuc dtTam = nhanDonThucVoiDaThuc(dt1.p[i], dt2);
        dtTich = congDaThuc(dtTich, dtTam);
    }

    return dtTich;
}


// 10. Hàm tính giá trị F(x)
long long tinhGiaTriFx(DaThuc F, int x)
{
    int res = 0;
    for (int i=0; i< F.n; i++)
        res += F.p[i].heso*pow(x, F.p[i].somu);

    return res;

}
int main()
{
    DaThuc F, G;
    cout << "\tNHAP F(X)\n";
    NhapDaThuc(F);

    cout << "\tNHAP G(X)\n";
    NhapDaThuc(G);


    cout << "F(x) = ";
    XuatDaThuc(F);

    cout << "G(x) = ";
    XuatDaThuc(G);

    DaThuc H;
    H = congDaThuc(F, G);
    cout << "\nF(x) + G(x) = ";
    XuatDaThuc(H);

    DaThuc K;
    K = truDaThuc(F, G);
    cout << "F(x) - G(x) = ";
    XuatDaThuc(K);


    DaThuc L;
    L = nhanDaThuc(F, G);
    cout << "F(x).G(x) = ";
    XuatDaThuc(L);

    int x;
    cout << "\n\tNHAP SO NGUYEN X DE TINH GIA TRI F(X): ";
    cin >> x;
    cout << "F("<<x<<") = " << tinhGiaTriFx(F, x);

    return 0;
}

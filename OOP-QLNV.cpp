#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// ======================================================
// ISSUE 2
// XAY DUNG LOP NHAN VIEN
// ======================================================

class NhanVien
{
private:
    string MaNV;
    string HoTen;
    string PhongBan;
    double HeSoLuong;
    int SoNgayCong;
    double LuongThucLinh;

public:
    // Constructor mac dinh
    NhanVien()
    {
        MaNV = "";
        HoTen = "";
        PhongBan = "";
        HeSoLuong = 0.0;
        SoNgayCong = 0;
        LuongThucLinh = 0.0;
    }

    // Constructor day du tham so
    NhanVien(string ma, string ten, string phong,
             double hsl, int ngay)
    {
        MaNV = ma;
        HoTen = ten;
        PhongBan = phong;
        HeSoLuong = hsl;
        SoNgayCong = ngay;
        LuongThucLinh = 0.0;
    }

    // Getter
    string getMaNV() const
    {
        return MaNV;
    }

    string getHoTen() const
    {
        return HoTen;
    }

    string getPhongBan() const
    {
        return PhongBan;
    }

    double getHeSoLuong() const
    {
        return HeSoLuong;
    }

    int getSoNgayCong() const
    {
        return SoNgayCong;
    }

    double getLuongThucLinh() const
    {
        return LuongThucLinh;
    }

    // Setter
    void setMaNV(string ma)
    {
        MaNV = ma;
    }

    void setHoTen(string ten)
    {
        HoTen = ten;
    }

    void setPhongBan(string phong)
    {
        PhongBan = phong;
    }

    void setHeSoLuong(double hsl)
    {
        HeSoLuong = hsl;
    }

    void setSoNgayCong(int ngay)
    {
        SoNgayCong = ngay;
    }

    void setLuongThucLinh(double luong)
    {
        LuongThucLinh = luong;
    }

    // Nhap, xuat
    void nhap();
    void xuat() const;

    // Tinh luong
    void tinhLuong();
};


// Nhap nhan vien
void NhanVien::nhap()
{
    cout << "Nhap ma nhan vien: ";
    getline(cin, MaNV);

    cout << "Nhap ho ten: ";
    getline(cin, HoTen);

    cout << "Nhap phong ban: ";
    getline(cin, PhongBan);

    cout << "Nhap he so luong: ";
    cin >> HeSoLuong;

    cout << "Nhap so ngay cong: ";
    cin >> SoNgayCong;

    cin.ignore();
}


// Tinh luong thuc linh
void NhanVien::tinhLuong()
{
    LuongThucLinh =
        HeSoLuong * 2340000 * SoNgayCong / 26;
}


// Xuat nhan vien
void NhanVien::xuat() const
{
    cout << left
         << setw(10) << MaNV
         << setw(25) << HoTen
         << setw(20) << PhongBan
         << setw(15) << HeSoLuong
         << setw(15) << SoNgayCong
         << right << setw(18)
         << fixed << setprecision(0)
         << LuongThucLinh
         << endl;
}


// ======================================================
// ISSUE 3
// XAY DUNG LOP QUAN LY NHAN VIEN
// ======================================================

class QuanLyNhanVien
{
private:
    NhanVien ds[200];
    int SoLuong;

public:
    QuanLyNhanVien()
    {
        SoLuong = 0;
    }

    void NhapDanhSach();
    void InDanhSach() const;
    void SapXep();
    void TimKiem();
    void Them();
    void Xoa();
};


// ======================================================
// NHAP DANH SACH NHAN VIEN
// ======================================================

void QuanLyNhanVien::NhapDanhSach()
{
    do
    {
        cout << "Nhap so luong nhan vien (0 < n < 200): ";
        cin >> SoLuong;

        if (SoLuong <= 0 || SoLuong >= 200)
        {
            cout << "So luong nhan vien khong hop le, "
                 << "vui long nhap lai.\n";
        }

    } while (SoLuong <= 0 || SoLuong >= 200);

    cin.ignore();

    for (int i = 0; i < SoLuong; i++)
    {
        cout << "\nNhap nhan vien thu " << i + 1 << "\n";
        ds[i].nhap();
    }
}


// ======================================================
// IN DANH SACH NHAN VIEN
// ======================================================

void QuanLyNhanVien::InDanhSach() const
{
    if (SoLuong == 0)
    {
        cout << "Danh sach nhan vien rong\n";
        return;
    }

    cout << "\nDANH SACH NHAN VIEN\n";

    cout << left
         << setw(5) << "STT"
         << setw(10) << "MaNV"
         << setw(25) << "Ho Ten"
         << setw(20) << "Phong Ban"
         << setw(15) << "He So"
         << setw(15) << "Ngay Cong"
         << setw(18) << "Luong"
         << endl;

    cout << string(108, '-') << endl;

    for (int i = 0; i < SoLuong; i++)
    {
        cout << left << setw(5) << i + 1;
        ds[i].xuat();
    }
}


// ======================================================
// ISSUE 4
// SAP XEP THEO LUONG THUC LINH GIAM DAN
// ======================================================

void QuanLyNhanVien::SapXep()
{
    // Tinh luong cho tat ca nhan vien
    for (int i = 0; i < SoLuong; i++)
    {
        ds[i].tinhLuong();
    }

    // Bubble Sort
    for (int i = 0; i < SoLuong - 1; i++)
    {
        for (int j = 0; j < SoLuong - i - 1; j++)
        {
            if (ds[j].getLuongThucLinh() <
                ds[j + 1].getLuongThucLinh())
            {
                NhanVien temp = ds[j];

                ds[j] = ds[j + 1];

                ds[j + 1] = temp;
            }
        }
    }

    cout << "\nDa sap xep danh sach theo "
         << "luong thuc linh giam dan\n";
}


// ======================================================
// ISSUE 5
// TIM KIEM NHAN VIEN THEO MA
// ======================================================

void QuanLyNhanVien::TimKiem()
{
    string MaCanTim;

    cout << "Nhap ma nhan vien can tim: ";
    getline(cin, MaCanTim);

    bool TimThay = false;

    for (int i = 0; i < SoLuong; i++)
    {
        if (ds[i].getMaNV() == MaCanTim)
        {
            cout << "\nTim thay nhan vien:\n";

            cout << left
                 << setw(10) << "MaNV"
                 << setw(25) << "Ho Ten"
                 << setw(20) << "Phong Ban"
                 << setw(15) << "He So"
                 << setw(15) << "Ngay Cong"
                 << setw(18) << "Luong"
                 << endl;

            ds[i].xuat();

            TimThay = true;
            break;
        }
    }

    if (!TimThay)
    {
        cout << "Khong tim thay nhan vien "
             << "voi ma vua nhap\n";
    }
}


// ======================================================
// ISSUE 6
// THEM NHAN VIEN TAI VI TRI K
// ======================================================

void QuanLyNhanVien::Them()
{
    if (SoLuong >= 200)
    {
        cout << "Danh sach da day, khong the them\n";
        return;
    }

    int k;

    do
    {
        cout << "Nhap vi tri can them "
             << "(0 <= k <= " << SoLuong << "): ";
        cin >> k;

        if (k < 0 || k > SoLuong)
        {
            cout << "Vi tri khong hop le, "
                 << "hay nhap lai\n";
        }

    } while (k < 0 || k > SoLuong);

    cin.ignore();

    NhanVien nv;

    cout << "\nNhap nhan vien moi\n";
    nv.nhap();

    // Dich cac phan tu sang phai
    for (int i = SoLuong; i > k; i--)
    {
        ds[i] = ds[i - 1];
    }

    ds[k] = nv;

    SoLuong++;

    cout << "Da them nhan vien vao danh sach\n";
}


// ======================================================
// XOA NHAN VIEN TAI VI TRI K
// ======================================================

void QuanLyNhanVien::Xoa()
{
    if (SoLuong == 0)
    {
        cout << "Danh sach nhan vien rong, "
             << "khong the xoa\n";
        return;
    }

    int k;

    do
    {
        cout << "Nhap vi tri can xoa "
             << "(0 <= k < " << SoLuong << "): ";
        cin >> k;

        if (k < 0 || k >= SoLuong)
        {
            cout << "Vi tri khong hop le, "
                 << "nhap lai\n";
        }

    } while (k < 0 || k >= SoLuong);

    // Dich cac phan tu sang trai
    for (int i = k; i < SoLuong - 1; i++)
    {
        ds[i] = ds[i + 1];
    }

    SoLuong--;

    cout << "Xoa nhan vien thanh cong\n";
}


// ======================================================
// MAIN
// ======================================================

int main()
{
    QuanLyNhanVien ql;

    int LuaChon;

    do
    {
        cout << "\n\n========== QUAN LY NHAN VIEN ==========\n";

        cout << "1. Nhap danh sach nhan vien\n";
        cout << "2. In danh sach nhan vien\n";
        cout << "3. Sap xep theo luong giam dan\n";
        cout << "4. Tim kiem nhan vien theo ma\n";
        cout << "5. Them nhan vien tai vi tri k\n";
        cout << "6. Xoa nhan vien tai vi tri k\n";
        cout << "0. Thoat chuong trinh\n";

        cout << "\nNhap lua chon: ";
        cin >> LuaChon;
        cin.ignore();

        switch (LuaChon)
        {
        case 1:
            ql.NhapDanhSach();
            break;

        case 2:
            ql.InDanhSach();
            break;

        case 3:
            ql.SapXep();
            ql.InDanhSach();
            break;

        case 4:
            ql.TimKiem();
            break;

        case 5:
            ql.Them();
            break;

        case 6:
            ql.Xoa();
            break;

        case 0:
            cout << "Ket thuc chuong trinh\n";
            break;

        default:
            cout << "Lua chon khong hop le\n";
        }

    } while (LuaChon != 0);

    return 0;
}

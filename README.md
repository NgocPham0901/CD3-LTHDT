class NhanVien { 
  private: 
    int maNV; 
    string hoTen; 
    string phongBan; 
    float heSoLuong; 
    int soNgayCong; 
    float luongThucLinh; 
  public:
 // Constructor
   NhanVien() { 
     maNV = 0;
     hoTen = ""; 
  phongBan = ""; 
  heSoLuong = 0; 
  soNgayCong = 0; 
  luongThucLinh = 0; 
} 
// Destructor ~NhanVien() {
 	} 
}; 

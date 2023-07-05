#include <iostream>
using namespace std;

class MataKuliah {
private:
	float presensi;
	float activity;
	float exercise;
	float tugasAkhir;

public:
	MataKuliah() {
		presensi = 0;
		activity = 0;
		exercise = 0;
		tugasAkhir = 0;
	}

	virtual float hitungNilaiAkhir() { return 0; }
	virtual void CekKelulusan() {}
	virtual void input() {}

	void setP(float nilai) {
		this->presensi = nilai;
	}

	float getP() {
		return presensi;
	}

	void setA(float nilai) {
		this->activity = nilai;
	}

	float getA() {
		return activity;
	}

	void setE(float nilai) {
		this->exercise = nilai;
	}

	float getE() {
		return exercise;
	}

	void setUA(float nilai) {
		this->tugasAkhir = nilai;
	}

	float getUA() {
		return tugasAkhir;
	}
};

class Pemrograman : public MataKuliah {
public:
	float hitungNilaiAkhir() {
		return (getP() * 0.1) + (getA() * 0.2) + (getE() * 0.3) + (getUA() * 0.4);
	}

	void CekKelulusan() {
		float na = hitungNilaiAkhir();
		if (na > 75) {
			cout << "Selamat, Anda lulus mata kuliah Pemrograman dengan nilai akhir " << na << endl;
		}
		else {
			cout << "Maaf, Anda tidak lulus mata kuliah Pemrograman." << endl;
		}
	}

	void input() {
		cout << "Masukkan nilai Presensi : ";
		float p = getP();
		cin >> p;
		setP(p);

		cout << "Masukkan nilai Activity : ";
		float a = getA();
		cin >> a;
		setA(a);

		cout << "Masukkan nilai Exercise : ";
		float e = getE();
		cin >> e;
		setE(e);

		cout << "Masukkan nilai Tugas Akhir : ";
		float ua = getUA();
		cin >> ua;
		setUA(ua);
	}
};

int main() {
	cout << "Program Dibuat" << endl;
	char pilihan;

	do {
		MataKuliah* MK;
		Pemrograman pem;
		
		MK = &pem;
		MK->input();
		MK->CekKelulusan();

		cout << "Apakah Anda ingin mengulang program (Y/N)? ";
		cin >> pilihan;

	} while (pilihan == 'Y' || pilihan == 'y');

	return 0;
}
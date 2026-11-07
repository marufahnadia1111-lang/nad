#include <iostream>
#include <string>

using namespace std;

int main() {
    // A. Array 1D: Nama Kelas dan Bobot Penilaian
    string namaKelas[3] = {"TI-1A", "TI-1B", "TI-1C"};
    double bobot[4] = {0.20, 0.20, 0.25, 0.35}; // Tugas, Kuis, UTS, UAS

    // B. Array 2D: Nama Mahasiswa dan Nilai Akhir
    string nama[3][5] = {
        {"Andi", "Budi", "Citra", "Deni", "Eka"}, //1A
        {"Farhan", "Gina", "Hadi", "Intan", "Joko"}, //1B
        {"Karin", "Lukman", "Maya", "Nanda", "Oki"} //1C
    };
    double nilaiAkhir[3][5];

    // C. Array 3D: Seluruh Komponen Nilai [Kelas][Mahasiswa][Komponen]
    int nilai[3][5][4] = {
        // Kelas TI-1A
        {
            {80, 85, 78, 90},
            {70, 75, 68, 72},
            {90, 88, 92, 95},
            {60, 65, 58, 62},
            {85, 80, 82, 88}
        },
        // Kelas TI-1B
        {
            {78, 80, 75, 82},
            {95, 90, 93, 96},
            {65, 70, 60, 68},
            {88, 85, 87, 90},
            {55, 60, 58, 50}
        },
        // Kelas TI-1C
        {
            {82, 84, 80, 86},
            {75, 78, 72, 76},
            {92, 94, 90, 93},
            {68, 65, 70, 72},
            {80, 76, 78, 82}
        }
    };

    int pilihan;

    do {
        // Hitung ulang nilai akhir setiap kali menu dipanggil
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 5; j++) {
                nilaiAkhir[i][j] = (nilai[i][j][0] * bobot[0]) +
                                   (nilai[i][j][1] * bobot[1]) +
                                   (nilai[i][j][2] * bobot[2]) +
                                   (nilai[i][j][3] * bobot[3]);
            }
        }

        // Tampilkan Menu Utama
        cout << "\n========================================\n";
        cout << " SISTEM MONITORING NILAI MAHASISWA\n";
        cout << "========================================\n";
        cout << "1. Tampilkan Seluruh Data Mahasiswa\n";
        cout << "2. Tampilkan Nilai Berdasarkan Kelas\n";
        cout << "3. Hitung dan Tampilkan Nilai Akhir\n";
        cout << "4. Cari Mahasiswa\n";
        cout << "5. Ubah Nilai Mahasiswa\n";
        cout << "6. Tampilkan Peringkat Mahasiswa\n";
        cout << "7. Analisis Statistik Per Kelas\n";
        cout << "8. Analisis Seluruh Kelas\n";
        cout << "9. Tampilkan Mahasiswa Remedial\n";
        cout << "0. Keluar\n";
        cout << "========================================\n";
        cout << "Pilih Menu: ";
        cin >> pilihan;
        cout << endl;

        switch (pilihan) {
            case 1: {
                // FITUR 1: Tampilkan Seluruh Data Mahasiswa
                cout << "=================================================\n";
                cout << "         SELURUH DATA MAHASISWA & NILAI\n";
                cout << "=================================================\n";
                cout << "Kelas\tNama\tTugas\tKuis\tUTS\tUAS\n";
                cout << "-------------------------------------------------\n";
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 5; j++) {
                        cout << namaKelas[i] << "\t"
                             << nama[i][j] << "\t"
                             << nilai[i][j][0] << "\t"
                             << nilai[i][j][1] << "\t"
                             << nilai[i][j][2] << "\t"
                             << nilai[i][j][3] << endl;
                    }
                }
                cout << "=================================================\n";
                break;
            }
            case 2: {
                // FITUR 2: Tampilkan Data Berdasarkan Kelas
                int pilihanKelas;
                cout << "Pilih Kelas (1: TI-1A, 2: TI-1B, 3: TI-1C): ";
                cin >> pilihanKelas;

                if (pilihanKelas < 1 || pilihanKelas > 3) {
                    cout << "[KESALAHAN] Pilihan kelas tidak valid!\n";
                    break;
                }

                int idx = pilihanKelas - 1;
                cout << "\n=========================================\n";
                cout << "       DATA MAHASISWA KELAS " << namaKelas[idx] << "\n";
                cout << "=========================================\n";
                cout << "Nama\tTugas\tKuis\tUTS\tUAS\n";
                cout << "-----------------------------------------\n";
                for (int j = 0; j < 5; j++) {
                    cout << nama[idx][j] << "\t"
                         << nilai[idx][j][0] << "\t"
                         << nilai[idx][j][1] << "\t"
                         << nilai[idx][j][2] << "\t"
                         << nilai[idx][j][3] << endl;
                }
                cout << "=========================================\n";
                break;
            }
            case 3: {
                // FITUR 3: Hitung dan Tampilkan Nilai Akhir
                int pilihanKelas;
                cout << "Pilih Kelas (1: TI-1A, 2: TI-1B, 3: TI-1C): ";
                cin >> pilihanKelas;

                if (pilihanKelas < 1 || pilihanKelas > 3) {
                    cout << "[KESALAHAN] Pilihan kelas tidak valid!\n";
                    break;
                }

                int idx = pilihanKelas - 1;
                cout << "\n=============================================\n";
                cout << "       LAPORAN NILAI AKHIR KELAS " << namaKelas[idx] << "\n";
                cout << "=============================================\n";
                cout << "No\tNama\tNilai Akhir\tGrade\tStatus\n";
                cout << "---------------------------------------------\n";

                for (int j = 0; j < 5; j++) {
                    double na = nilaiAkhir[idx][j];
                    char grade;
                    string status;

                    if (na >= 85) grade = 'A';
                    else if (na >= 75) grade = 'B';
                    else if (na >= 65) grade = 'C';
                    else if (na >= 50) grade = 'D';
                    else grade = 'E';

                    if (na >= 65) status = "LULUS";
                    else status = "TIDAK LULUS";

                    cout << (j + 1) << "\t"
                         << nama[idx][j] << "\t"
                         << na << "\t\t"
                         << grade << "\t"
                         << status << endl;
                }
                cout << "---------------------------------------------\n";
                break;
            }
            case 4: {
                // FITUR 4: Pencarian Mahasiswa
                string cariNama;
                cout << "Masukkan nama mahasiswa yang ingin dicari: ";
                cin >> cariNama;

                bool ditemukan = false;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 5; j++) {
                        // Pencocokan nama sederhana
                        if (nama[i][j] == cariNama) {
                            double na = nilaiAkhir[i][j];
                            char grade;
                            string status;

                            if (na >= 85) grade = 'A';
                            else if (na >= 75) grade = 'B';
                            else if (na >= 65) grade = 'C';
                            else if (na >= 50) grade = 'D';
                            else grade = 'E';

                            if (na >= 65) status = "LULUS";
                            else status = "TIDAK LULUS";

                            cout << "\n[DATA DITEMUKAN]\n";
                            cout << "Nama        : " << nama[i][j] << endl;
                            cout << "Kelas       : " << namaKelas[i] << endl;
                            cout << "Nilai Tugas : " << nilai[i][j][0] << endl;
                            cout << "Nilai Kuis  : " << nilai[i][j][1] << endl;
                            cout << "Nilai UTS   : " << nilai[i][j][2] << endl;
                            cout << "Nilai UAS   : " << nilai[i][j][3] << endl;
                            cout << "Nilai Akhir : " << na << endl;
                            cout << "Grade       : " << grade << endl;
                            cout << "Status      : " << status << endl;
                            ditemukan = true;
                            break;
                        }
                    }
                    if (ditemukan) break;
                }

                if (!ditemukan) {
                    cout << "Mahasiswa tidak ditemukan.\n";
                }
                break;
            }
            case 5: {
                // FITUR 5: Ubah Nilai Mahasiswa
                int pKelas, pMhs, pKomponen;
                double nilaiBaru;

                cout << "Pilih Kelas (1: TI-1A, 2: TI-1B, 3: TI-1C): ";
                cin >> pKelas;
                if (pKelas < 1 || pKelas > 3) { cout << "Pilihan tidak valid!\n"; break; }

                int idxK = pKelas - 1;
                cout << "\nDaftar Mahasiswa:\n";
                for (int j = 0; j < 5; j++) {
                    cout << (j + 1) << ". " << nama[idxK][j] << endl;
                }
                cout << "Pilih Mahasiswa (1-5): ";
                cin >> pMhs;
                if (pMhs < 1 || pMhs > 5) { cout << "Pilihan tidak valid!\n"; break; }

                int idxM = pMhs - 1;
                cout << "\nPilih Komponen (1: Tugas, 2: Kuis, 3: UTS, 4: UAS): ";
                cin >> pKomponen;
                if (pKomponen < 1 || pKomponen > 4) { cout << "Pilihan tidak valid!\n"; break; }

                int idxKom = pKomponen - 1;
                cout << "Masukkan nilai baru (0 - 100): ";
                cin >> nilaiBaru;

                if (nilaiBaru < 0 || nilaiBaru > 100) {
                    cout << "[KESALAHAN] Nilai harus berada pada rentang 0 sampai 100!\n";
                } else {
                    nilai[idxK][idxM][idxKom] = nilaiBaru;
                    cout << "[SUKSES] Nilai berhasil diperbarui!\n";
                }
                break;
            }
            case 6: {
                // FITUR 6: Menampilkan Peringkat Mahasiswa (Bubble Sort Manual)
                int pilihanKelas;
                cout << "Pilih Kelas (1: TI-1A, 2: TI-1B, 3: TI-1C): ";
                cin >> pilihanKelas;

                if (pilihanKelas < 1 || pilihanKelas > 3) {
                    cout << "[KESALAHAN] Pilihan kelas tidak valid!\n";
                    break;
                }

                int idx = pilihanKelas - 1;
                string tempNama[5];
                double tempNilai[5];
                for (int j = 0; j < 5; j++) {
                    tempNama[j] = nama[idx][j];
                    tempNilai[j] = nilaiAkhir[idx][j];
                }

                // Bubble Sort Descending Nilai Akhir & Ascending Nama jika sama
                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j < 4 - i; j++) {
                        if (tempNilai[j] < tempNilai[j + 1] || 
                           (tempNilai[j] == tempNilai[j + 1] && tempNama[j] > tempNama[j + 1])) {
                            double tNilai = tempNilai[j];
                            tempNilai[j] = tempNilai[j + 1];
                            tempNilai[j + 1] = tNilai;

                            string tNama = tempNama[j];
                            tempNama[j] = tempNama[j + 1];
                            tempNama[j + 1] = tNama;
                        }
                    }
                }

                cout << "\n========================================\n";
                cout << "     PERINGKAT KELAS " << namaKelas[idx] << " (1 - 5)\n";
                cout << "========================================\n";
                cout << "Rank\tNama\t\tNilai Akhir\n";
                cout << "----------------------------------------\n";
                for (int j = 0; j < 5; j++) {
                    cout << (j + 1) << "\t" << tempNama[j] << "\t\t" << tempNilai[j] << endl;
                }
                cout << "========================================\n";
                break;
            }
            case 7: {
                // FITUR 7: Analisis Statistik Per Kelas
                int pilihanKelas;
                cout << "Pilih Kelas (1: TI-1A, 2: TI-1B, 3: TI-1C): ";
                cin >> pilihanKelas;

                if (pilihanKelas < 1 || pilihanKelas > 3) {
                    cout << "[KESALAHAN] Pilihan kelas tidak valid!\n";
                    break;
                }

                int idx = pilihanKelas - 1;
                double maxNA = nilaiAkhir[idx][0];
                double minNA = nilaiAkhir[idx][0];
                string mhsMax = nama[idx][0];
                string mhsMin = nama[idx][0];

                double totalNA = 0, totalTugas = 0, totalKuis = 0, totalUTS = 0, totalUAS = 0;
                int jmlLulus = 0, jmlTidakLulus = 0;

                for (int j = 0; j < 5; j++) {
                    double na = nilaiAkhir[idx][j];
                    totalNA += na;

                    if (na > maxNA) { maxNA = na; mhsMax = nama[idx][j]; }
                    if (na < minNA) { minNA = na; mhsMin = nama[idx][j]; }

                    if (na >= 65) jmlLulus++;
                    else jmlTidakLulus++;

                    totalTugas += nilai[idx][j][0];
                    totalKuis += nilai[idx][j][1];
                    totalUTS += nilai[idx][j][2];
                    totalUAS += nilai[idx][j][3];
                }

                double avgNA = totalNA / 5;
                double avgTugas = totalTugas / 5;
                double avgKuis = totalKuis / 5;
                double avgUTS = totalUTS / 5;
                double avgUAS = totalUAS / 5;

                string komr[4] = {"Tugas", "Kuis", "UTS", "UAS"};
                double avgKom[4] = {avgTugas, avgKuis, avgUTS, avgUAS};
                double minAvgKom = avgKom[0];
                string lowestKomName = komr[0];

                for (int k = 1; k < 4; k++) {
                    if (avgKom[k] < minAvgKom) {
                        minAvgKom = avgKom[k];
                        lowestKomName = komr[k];
                    }
                }

                cout << "\n=================================================\n";
                cout << "        ANALISIS STATISTIK KELAS " << namaKelas[idx] << "\n";
                cout << "=================================================\n";
                cout << "Nilai Tertinggi       : " << maxNA << " (" << mhsMax << ")\n";
                cout << "Nilai Terendah        : " << minNA << " (" << mhsMin << ")\n";
                cout << "Rata-rata Nilai Akhir : " << avgNA << endl;
                cout << "Jumlah Mahasiswa Lulus: " << jmlLulus << endl;
                cout << "Jumlah Tidak Lulus    : " << jmlTidakLulus << endl;
                cout << "-------------------------------------------------\n";
                cout << "Rata-rata Tugas       : " << avgTugas << endl;
                cout << "Rata-rata Kuis        : " << avgKuis << endl;
                cout << "Rata-rata UTS         : " << avgUTS << endl;
                cout << "Rata-rata UAS         : " << avgUAS << endl;
                cout << "Komponen Terendah     : " << lowestKomName << " (Rata-rata: " << minAvgKom << ")\n";
                cout << "=================================================\n";
                break;
            }
            case 8: {
                // FITUR 8: Analisis Seluruh Kelas
                double rataKelas[3];
                int totalLulusSemua = 0, totalTidakLulusSemua = 0;
                double maxGlobal = nilaiAkhir[0][0];
                double minGlobal = nilaiAkhir[0][0];

                for (int i = 0; i < 3; i++) {
                    double sum = 0;
                    for (int j = 0; j < 5; j++) {
                        double na = nilaiAkhir[i][j];
                        sum += na;
                        if (na >= 65) totalLulusSemua++;
                        else totalTidakLulusSemua++;

                        if (na > maxGlobal) maxGlobal = na;
                        if (na < minGlobal) minGlobal = na;
                    }
                    rataKelas[i] = sum / 5;
                }

                int idxMaxKelas = 0;
                for (int i = 1; i < 3; i++) {
                    if (rataKelas[i] > rataKelas[idxMaxKelas]) {
                        idxMaxKelas = i;
                    }
                }

                double persentaseLulus = ((double)totalLulusSemua / 15) * 100;

                cout << "\n=================================================\n";
                cout << "            ANALISIS SELURUH KELAS\n";
                cout << "=================================================\n";
                cout << "Rata-rata Kelas TI-1A : " << rataKelas[0] << endl;
                cout << "Rata-rata Kelas TI-1B : " << rataKelas[1] << endl;
                cout << "Rata-rata Kelas TI-1C : " << rataKelas[2] << endl;
                cout << "Kelas Rata-rata Tertinggi: " << namaKelas[idxMaxKelas] << endl;
                cout << "-------------------------------------------------\n";
                cout << "Total Mahasiswa Lulus : " << totalLulusSemua << endl;
                cout << "Total Tidak Lulus     : " << totalTidakLulusSemua << endl;
                cout << "Persentase Kelulusan  : " << persentaseLulus << "%\n";
                cout << "-------------------------------------------------\n";
                
                cout << "Mahasiswa Nilai Tertinggi (" << maxGlobal << "):\n";
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 5; j++) {
                        if (nilaiAkhir[i][j] == maxGlobal) {
                            cout << "- " << nama[i][j] << " (" << namaKelas[i] << ")\n";
                        }
                    }
                }

                cout << "\nMahasiswa Nilai Terendah (" << minGlobal << "):\n";
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 5; j++) {
                        if (nilaiAkhir[i][j] == minGlobal) {
                            cout << "- " << nama[i][j] << " (" << namaKelas[i] << ")\n";
                        }
                    }
                }
                cout << "=================================================\n";
                break;
            }
            case 9: {
                // FITUR 9: Tampilkan Mahasiswa Remedial menggunakan Parallel Array (Tanpa struct)
                string remNama[15];
                string remKelas[15];
                double remNilai[15];
                string remKomp[15];
                int totalRemedial = 0;

                string komponenNama[4] = {"Tugas", "Kuis", "UTS", "UAS"};

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 5; j++) {
                        if (nilaiAkhir[i][j] < 65) {
                            remNama[totalRemedial] = nama[i][j];
                            remKelas[totalRemedial] = namaKelas[i];
                            remNilai[totalRemedial] = nilaiAkhir[i][j];

                            int minVal = nilai[i][j][0];
                            for (int k = 1; k < 4; k++) {
                                if (nilai[i][j][k] < minVal) {
                                    minVal = nilai[i][j][k];
                                }
                            }

                            string kompStr = "";
                            for (int k = 0; k < 4; k++) {
                                int val = nilai[i][j][k];
                                if (val == minVal) {
                                    if (kompStr != "") kompStr += ", ";
                                    // Mengubah int ke string manual secara sederhana dengan to_string
                                    kompStr += komponenNama[k] + " (" + to_string(minVal) + ")";
                                }
                            }

                            remKomp[totalRemedial] = kompStr;
                            totalRemedial++;
                        }
                    }
                }

                // Sorting Ascending berdasarkan Nilai Akhir menggunakan Bubble Sort pada Parallel Array
                for (int i = 0; i < totalRemedial - 1; i++) {
                    for (int j = 0; j < totalRemedial - i - 1; j++) {
                        if (remNilai[j] > remNilai[j + 1]) {
                            double tempN = remNilai[j];
                            remNilai[j] = remNilai[j + 1];
                            remNilai[j + 1] = tempN;

                            string tempNa = remNama[j];
                            remNama[j] = remNama[j + 1];
                            remNama[j + 1] = tempNa;

                            string tempK = remKelas[j];
                            remKelas[j] = remKelas[j + 1];
                            remKelas[j + 1] = tempK;

                            string tempC = remKomp[j];
                            remKomp[j] = remKomp[j + 1];
                            remKomp[j + 1] = tempC;
                        }
                    }
                }

                cout << "\n=================================================================\n";
                cout << "                  DAFTAR MAHASISWA REMEDIAL\n";
                cout << "=================================================================\n";
                if (totalRemedial == 0) {
                    cout << "Tidak ada mahasiswa yang remedial (Semua Lulus).\n";
                } else {
                    cout << "Nama\t\tKelas\tNilai Akhir\tKomponen Terendah\n";
                    cout << "-----------------------------------------------------------------\n";
                    for (int i = 0; i < totalRemedial; i++) {
                        cout << remNama[i] << "\t\t"
                             << remKelas[i] << "\t"
                             << remNilai[i] << "\t\t"
                             << remKomp[i] << endl;
                    }
                }
                cout << "=================================================================\n";
                break;
            }
            case 0:
                cout << "Terima kasih telah menggunakan program ini!\n";
                break;
            default:
                cout << "[KESALAHAN] Pilihan menu tidak valid. Silakan coba lagi.\n";
        }

    } while (pilihan != 0);

    return 0;
}
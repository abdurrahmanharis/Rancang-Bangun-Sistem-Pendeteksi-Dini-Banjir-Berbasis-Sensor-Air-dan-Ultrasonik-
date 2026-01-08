# Rancang Bangun Sistem Peringatan Dini Banjir Berbasis IoT Menggunakan Sensor Ultrasonik dan Sensor Air pada ESP32
**Nama Anggota:**
1. Muhammad Abdurrahman Haris (2306030025)
2. Badru Munir                (2306030088)

## 1. Latar Belakang

Fenomena banjir di Indonesia semakin sering terjadi akibat faktor alam maupun aktivitas manusia, sehingga diperlukan suatu sistem pemantauan yang mampu memberikan informasi kondisi air secara cepat dan akurat. Banjir dapat menimbulkan dampak sosial, ekonomi, dan infrastruktur yang serius, sehingga masyarakat membutuhkan sistem peringatan dini untuk memantau kenaikan permukaan air secara real-time. Sistem berbasis teknologi mikrokontroler dinilai mampu memberikan solusi dalam memonitor ketinggian air melalui sensor, sehingga masyarakat dapat mengambil tindakan lebih awal sebelum banjir mencapai tahap kritis. [Nicko Pratama, Ucuk Darusalam, Novi Dian Nathasia (2020)](https://pdfs.semanticscholar.org/518d/476c31d108da04f2a1cd0fccc67abd8f44aa.pdf).

Upaya pengembangan sistem peringatan dini banjir dengan teknologi sensor dapat dimanfaatkan untuk mendeteksi kenaikan muka air pada sungai atau saluran air secara terus-menerus. Sistem monitoring berbasis mikrokontroler mampu membantu pengiriman informasi kondisi banjir kepada pengguna, sehingga proses mitigasi bencana dapat dilakukan lebih cepat dan terarah. Dengan demikian, integrasi sensor pada sistem peringatan dini dianggap sangat penting untuk meningkatkan kesiapsiagaan masyarakat dalam menghadapi potensi banjir. [Martalia. Andayani, Widyaningrum.Indrasari, Bambang. H. Iswanto (2016)](https://journal.unj.ac.id/unj/index.php/prosidingsnf/article/view/4043).

Penggunaan jaringan komunikasi dan platform berbasis Internet of Things (IoT) memungkinkan data sensor dikirimkan ke perangkat pengguna secara langsung. Hal ini mendukung terciptanya sistem monitoring yang tidak hanya bekerja secara lokal, tetapi juga dapat dipantau dari jarak jauh melalui jaringan internet. Konsep tersebut sangat relevan dengan pengembangan sistem peringatan dini berbasis ESP32, sensor ultrasonik, sensor air digital, dan platform Blynk yang sedang dirancang dalam proyek ini, sehingga masyarakat dapat memperoleh informasi kondisi banjir secara real-time dan responsif. [Zahir Zainuddin, Abdul Latif Arda, Andi Zulkifli Nusri (2019)](https://www.academia.edu/download/100909825/142.pdf).


## 2. Rumusan Masalah

Berdasarkan latar belakang tersebut, rumusan masalah dalam proyek ini adalah sebagai berikut:

1. Bagaimana merancang sistem pendeteksi dini banjir berbasis IoT menggunakan sensor ultrasonik dan sensor air digital pada mikrokontroler ESP32 untuk memantau ketinggian air secara real-time?
2. Bagaimana mekanisme pengolahan dan pengiriman data ketinggian air melalui jaringan WiFi ke platform Blynk agar informasi kondisi banjir dapat dipantau dari jarak jauh? 
3. Bagaimana menetapkan kriteria status Aman, Waspada, dan Bahaya berdasarkan pembacaan sensor agar sistem dapat memberikan peringatan dini yang efektif?

## 3. Tujuan

Tujuan dari Proyek ini adalah:
1. Merancang dan membangun sistem peringatan dini banjir berbasis IoT menggunakan sensor ultrasonik dan sensor air digital pada ESP32 untuk memantau ketinggian air secara real-time.
2. Mengimplementasikan mekanisme pengolahan dan pengiriman data melalui jaringan WiFi ke platform Blynk agar informasi kondisi banjir dapat dipantau dari jarak jauh.
3. Menetapkan kriteria status Aman, Waspada, dan Bahaya berdasarkan hasil pembacaan sensor, sehingga sistem memberikan peringatan dini secara akurat dan informatif.

## 4. Alat dan Bahan
Alat dan bahan yang digunakan dalam proyek ini meliputi:

### 4.1 Perangkat Keras
| No | Alat/Bahan                | Fungsi                                              | Letak Penggunaannya                                                                                        |
| -- | ------------------------- | --------------------------------------------------- | ---------------------------------------------------------------------------------------------------------- |
| 1  | Mikrokontroler ESP32      | Mengolah data sensor dan mengirim data ke Internet. | Dipasang sebagai pusat kendali sistem. Semua sensor, LED, dan modul dihubungkan ke pin GPIO ESP32.         |
| 2  | Sensor Ultrasonik HC-SR04 | Mengukur jarak permukaan air dari posisi sensor.    | Ditempatkan di atas permukaan air (misal di dinding saluran air), dihubungkan ke pin trigger & echo ESP32. |
| 3  | Sensor Air Digital        | Mendeteksi keberadaan air pada level kritis.        | Dipasang pada titik level rawan banjir (level siaga kritis), dihubungkan ke pin input digital ESP32.       |
| 4  | LED Merah                 | Indikator **bahaya kritis**.                     | Dipasang pada pin output ESP32, menyala saat ketinggian air melewati batas bahaya.                         |
| 5  | LED Hijau                 | Indikator **waspada**.                                 | Dipasang pada pin output ESP32, menyala saat kondisi waspada.                                               |
| 6  | Kabel Jumper              | Menghubungkan tiap komponen elektronik.             | Dipasang  untuk menghubungkan ESP32 dengan sensor, LED, dan power.                          |
| 7  | Sumber Daya USB           | Memberikan suplai daya ke ESP32.                    | Dihubungkan dari laptop/adapter ke port USB ESP32.                                                         |
| 8  | Laptop / PC               | Menulis dan upload program.                         | Dipakai saat proses pemrograman melalui Arduino IDE.                                                       |
| 9 | Smartphone Android/iOS    | Monitoring data IoT real-time.                      | Digunakan untuk membuka Aplikasi Blynk dan menerima notifikasi dari sistem.                                |
| 10 | Internet / WiFi           | Media komunikasi data.                              | Diperlukan agar ESP32 bisa terhubung ke server Blynk Cloud.                                                |

### 4.2 Perangkat Lunak 
| No | Software/Aplikasi            | Fungsi Penggunaan                        | Letak Penggunaannya                                                |
| -- | ---------------------------- | ---------------------------------------- | ------------------------------------------------------------------ |
| 1  | Arduino IDE                  | Menulis, kompilasi, dan upload program.  | Digunakan di Laptop/PC selama proses pembuatan program ESP32.      |
| 2  | Board ESP32 (Boards Manager) | Supaya Arduino IDE bisa mengenali ESP32. | Di-install pada Arduino IDE sebelum pemrograman.                   |
| 3  | Aplikasi Blynk               | Monitoring data sensor dan notifikasi.   | Dipasang di smartphone, menerima data dari ESP32 melalui Internet. |

### 4.3 Library Program
| No | Library            | Fungsi Pemakaian                           | Sumber               | Letak Penggunaannya dalam Program                                                                                       |
| -- | ------------------ | ------------------------------------------ | -------------------- | ----------------------------------------------------------------------------------------------------------------------- |
| 1  | WiFi.h             | Menghubungkan ESP32 ke jaringan WiFi.      | Default ESP32 Core   | Di bagian awal program untuk inisialisasi WiFi, login SSID & Password, serta mengecek status koneksi.                   |
| 2  | WiFiClient.h       | Mengelola komunikasi TCP/IP.               | Default ESP32 Core   | Digunakan saat ESP32 mengirim data ke server (misalnya ke Blynk Cloud). Biasanya otomatis dipanggil saat koneksi aktif. |
| 3  | BlynkSimpleEsp32.h | Menghubungkan ESP32 ke Platform IoT Blynk. | Library Blynk        | Dipakai untuk mengirim nilai sensor ke aplikasi Blynk, menerima perintah dari aplikasi, dan mengatur Virtual Pin.       |
| 4  | Ultrasonic.h       | Membaca jarak dari sensor ultrasonik.      | Library pihak ketiga | Digunakan saat mendeklarasikan objek sensor dan memproses hasil jarak dalam satuan cm/mm.                               |
| 5  | Arduino.h          | Menyediakan fungsi dasar Arduino.          | Default              | Dipanggil secara otomatis saat program berjalan (setup(), loop(), digitalWrite(), dll.).                                |


> **Catatan:** Pastikan semua perangkat lunak pendukung dan dependensi sudah terinstal dengan benar sebelum memulai pengembangan sistem.

## 5. Langkah-Langkah Instalasi Library dan Board

### 5.1 Instal Board ESP32

  1. Buka Arduino IDE → File → Preferences
  2. Tambahkan URL berikut pada Additional Board Manager URLs:
  ```
  https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
  ```
  3. Masuk ke Tools → Board → Boards Manager → Cari ESP32 → Klik Install
  4. Pilih board DOIT ESP32 DEVKIT V1 saat melakukan upload program.

### 5.2 Instal Library Blynk

  1. Buka Sketch → Include Library → Manage Libraries
  2. Cari “Blynk” (by Volodymyr Shymanskyy) → Klik Install




## 6. Pengujian Komponen

Pada tahapan ini, dilakukan pengujian setiap komponen penyusun sistem secara mandiri sebelum dilakukan integrasi ke dalam sistem utama. Tujuannya adalah untuk memastikan bahwa seluruh perangkat keras dan perangkat lunak berfungsi dengan baik sehingga siap digunakan pada tahap perancangan sistem IoT.

### 6.1 Pengujian Sensor

Sensor ultrasonik dan sensor air digital diuji secara mandiri untuk memastikan respons yang tepat sebelum integrasi.

**Kode uji sensor (sederhana):**

``` cpp
#include <WiFi.h>
#include "Ultrasonic.h"

// Pin Sensor
#define WATER_SENSOR 32
Ultrasonic ultrasonic(27);

// Variabel
long jarakAir;
int statusAir;

void setup() {
  Serial.begin(9600);
  pinMode(WATER_SENSOR, INPUT);
}

void loop() {

  // Baca sensor ultrasonik
  jarakAir = ultrasonic.MeasureInCentimeters();

  // Baca sensor air digital
  statusAir = !digitalRead(WATER_SENSOR);

  // ---- Output ke Serial Monitor ----
  Serial.print(jarakAir);
  Serial.println(" cm");     

  if(statusAir == HIGH){
    Serial.println("AIR TERDETEKSI");
  } else {
    Serial.println("TIDAK ADA AIR");
  }

  Serial.println(); // pemisah

  delay(1000);
}
```

**Tabel Data Hasil Uji Sensor Ketinggian Air dan Sensor Air Digital**
| No | Kondisi Pengujian                              | Jarak Terbaca (cm) | Status Sensor Air | Output Serial Monitor  |
| -- | ---------------------------------------------- | ------------------ | ----------------- | ---------------------- |
| 1  | Tidak ada air / kering                         | 30 cm              | 0 (LOW)           | 30 cm — TIDAK ADA AIR  |
| 2  | Air mulai naik tapi belum menyentuh sensor air | 18 cm              | 0 (LOW)           | 18 cm — TIDAK ADA AIR  |
| 3  | Permukaan air lebih dekat ke sensor            | 12 cm              | 0 (LOW)           | 12 cm — TIDAK ADA AIR  |
| 4  | Air menyentuh sensor air digital               | 10 cm              | 1 (HIGH)          | 10 cm — AIR TERDETEKSI |
| 5  | Sensor air tetap terendam                      | 8 cm               | 1 (HIGH)          | 8 cm — AIR TERDETEKSI  |

> Program ini menggunakan ESP32 untuk membaca dua jenis sensor, yaitu sensor ultrasonik dan sensor air digital. Sensor ultrasonik pada pin 27 digunakan untuk mengukur jarak tinggi air dalam satuan centimeter, sedangkan sensor air digital pada pin 32 hanya mendeteksi ada atau tidaknya air (logika 1 = terdeteksi). Nilai jarak dan status air kemudian ditampilkan ke Serial Monitor setiap 1 detik. Dengan demikian, program ini berfungsi sebagai alat uji sederhana untuk memastikan kedua sensor sudah bekerja dan terbaca dengan benar oleh ESP32.


### 6.2 Pengujian Output (LED)

LED hijau dan merah diuji secara mandiri agar dapat dikendalikan ESP32 dengan benar.

**Kode uji LED:**

```cpp
#define LED1 13
#define LED2 15

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop() {
  digitalWrite(LED1, HIGH); digitalWrite(LED2, LOW); delay(2000);
  digitalWrite(LED1, LOW); digitalWrite(LED2, HIGH); delay(2000);
  digitalWrite(LED1, LOW); digitalWrite(LED2, LOW); delay(2000);
}

```
**Tabel Data Hasil Uji Output LED**
| No | Kondisi Program                                      | LED Hijau (Pin 13) | LED Merah (Pin 15) | Durasi  | Keterangan                        |
| -- | ---------------------------------------------------- | ------------------ | ------------------ | ------- | --------------------------------- |
| 1  | `digitalWrite(LED1, HIGH); digitalWrite(LED2, LOW);` | ON                 | OFF                | 2 detik | LED hijau menyala, LED merah mati |
| 2  | `digitalWrite(LED1, LOW); digitalWrite(LED2, HIGH);` | OFF                | ON                 | 2 detik | LED hijau mati, LED merah menyala |
| 3  | `digitalWrite(LED1, LOW); digitalWrite(LED2, LOW);`  | OFF                | OFF                | 2 detik | Kedua LED mati                    |

>  Pada program uji, LED hijau dan LED merah dibuat menyala bergantian dengan jeda waktu tertentu, kemudian keduanya dimatikan, sementara statusnya ditampilkan di Serial Monitor. Hasil pengujian menunjukkan bahwa LED berfungsi dengan baik dan dapat dikendalikan dan siap digunakan sebagai indikator kondisi banjir.



### 6.3 Pengujian Konektivitas Wifi
ESP32 diuji untuk memastikan dapat terhubung ke jaringan WiFi.

**Kode uji koneksi WiFi:**
```cpp
#include <WiFi.h>

const char* ssid = "Ryan D Gracia";
const char* pass = "99999999";

void setup() {
  Serial.begin(9600);
  delay(1000);

  Serial.println("Menghubungkan ke WiFi...");
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("ESP32 berhasil terhubung ke WiFi!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
/// memastikan status wifi
}
```
**Tabel Data Hasil Uji Koneksi Wifi ke ESP32**
| No | Kondisi Uji                       | Tampilan di Serial Monitor                                                                                                                  | Status Koneksi            |
| -- | --------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------- |
| 1  | WiFi tersedia & password benar    | `Menghubungkan ke WiFi...` lalu tampil titik “.....” dan akhirnya pesan **"ESP32 berhasil terhubung ke WiFi!"** serta **IP Address muncul** | Berhasil terhubung        |
| 2  | WiFi tersedia tetapi sinyal lemah | Titik “.....” muncul lebih lama sebelum tersambung                                                                                          | Terhubung tetapi lambat   |
| 3  | SSID salah / WiFi tidak ditemukan | Titik “.....” terus muncul tanpa henti                                                                                                      | Gagal terhubung           |
| 4  | Password salah                    | Titik “.....” terus muncul tanpa henti                                                                                                      | Gagal terhubung           |
| 5  | WiFi mati di tengah proses        | Titik berhenti lalu koneksi terputus                                                                                                        | Putus sebelum mendapat IP |

>Program ini berfungsi untuk memastikan ESP32 dapat terhubung ke jaringan WiFi dengan benar. Setelah SSID dan password diatur, ESP32 mencoba menyambung ke WiFi dan menampilkan prosesnya melalui Serial Monitor. Jika koneksi berhasil, program menampilkan pesan keberhasilan beserta alamat IP ESP32. Program ini tidak menjalankan fungsi lain karena hanya difokuskan untuk pengujian koneksi jaringan.



 ### 6.4 Pengujian Koneksi Blynk
ESP32 diuji untuk memastikan komunikasi dengan server Blynk.

**Kode uji Blynk:**
```cpp
#define BLYNK_TEMPLATE_ID "TMPL6ej-IPqPo"
#define BLYNK_TEMPLATE_NAME "Siaga Banjir"
#define BLYNK_AUTH_TOKEN "nTlnWVNxBY0b96M1O2EjNisdOXAFmS8X"

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "Ryan D Gracia";
char pass[] = "99999999";

void setup()
{
  Serial.begin(9600);
  delay(1000);

  Serial.println("Menghubungkan ke WiFi...");
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  Serial.println("ESP32 berhasil terhubung ke WiFi dan Blynk!");
}

void loop()
{
  Blynk.run();   // Menjaga koneksi tetap aktif
}
```
**Tabel Data Hasil Uji Koneksi ESP32 ke WiFi & Blynk**
| No | Tanggal / Waktu Pengujian | SSID WiFi             | Kondisi Sinyal WiFi | Status Koneksi WiFi | Status Koneksi Blynk | Output di Serial Monitor                                | Keterangan             |
| -- | ------------------------- | --------------------- | ------------------- | ------------------- | -------------------- | ------------------------------------------------------- | ---------------------- |
| 1  | 05-01-2026 / 15:33        | Ryan D Gracia         | Kuat                | Terhubung           | Terhubung            | “Menghubungkan ke WiFi…”<br>“ESP32 berhasil terhubung…” | Berhasil               |
| 2  | 05-01-2026 / 15:35        | Ryan D Gracia         | Lemah               | Terhubung           | Kadang terputus      | Terkadang reconnect                                     | Perlu penguatan sinyal |
| 3  | 05-01-2026 / 15:37        | Ryan D Gracia         | Tidak ada sinyal    | Gagal               | Gagal                | “Menghubungkan ke WiFi…” (berulang)                     | Tidak ada jaringan     |
| 4  | 05-01-2026 / 15:38        | SSID salah dimasukkan | -                   | Gagal               | Gagal                | “Menghubungkan ke WiFi…” (tidak pernah tersambung)      | Pastikan SSID benar    |
| 5  | 05-01-2026 / 15:42        | Ryan D Gracia         | Stabil              | Terhubung           | Terhubung stabil     | Koneksi berjalan normal                                 | Kondisi ideal          |

> Saat program dijalankan, ESP32 akan membuka komunikasi Serial dan kemudian mencoba terhubung ke WiFi serta server Blynk menggunakan SSID, password, dan token yang telah dimasukkan. Jika koneksi berhasil, status keberhasilan akan terlihat di Serial Monitor. Fungsi Blynk.run() di dalam loop() menjaga agar koneksi tetap aktif. Secara sederhana, program ini hanya digunakan untuk memastikan bahwa ESP32 sudah berhasil terhubung ke jaringan dan Blynk sebelum dilanjutkan ke tahap integrasi sensor dan output.


## 7. Pembuatan Alat

Pada tahap pembuatan alat, sistem mulai mengintegrasikan pembacaan sensor dengan pengendalian LED untuk membentuk sebuah alarm peringatan banjir sederhana. Fokus utama masih pada versi konvensional (non-IoT), di mana peringatan hanya diberikan secara lokal melalui indikator visual.

### 7.1 Desain Logika Sistem

Sistem membagi kondisi menjadi tiga status berdasarkan pembacaan sensor:

   | Kondisi        | Syarat    | LED | Pesan BLYNK        |   Keterangan  |
   | ----------- | ------- | --- | ----------------- |--------------|
   | Aman   | Air tidak menyentuh sensor digital & jarak > 15 cm | OFF semua  | AMAN      |   Permukaan air normal  |
   | Waspada   | Jarak ≤ 15 cm & sensor air digital belum aktif | LED Hijau ON  | WASPADA BANJIR |  Ketinggian air mulai meningkat|
   | Bahaya | Sensor air digital aktif | LED Merah ON  |   BAHAYA BANJIR TINGGI   |   Air mencapai level kritis  |

>Desain logika ini mengikuti prinsip hierarkis, di mana semakin tinggi tingkat risiko, semakin jelas pula indikasi visual dan notifikasi yang diberikan sistem. Dengan pemisahan kondisi menjadi aman, waspada, dan bahaya, pengguna dapat memahami situasi hanya melalui tampilan LED atau notifikasi pada aplikasi Blynk, tanpa perlu memantau sensor secara manual. Hal ini mendukung tujuan utama sistem sebagai alat peringatan dini banjir berbasis IoT yang responsif dan mudah dipahami.


### 7.2 Konfigurasi Aplikasi Blynk

1. Buat Template di BLYNK dengan membuka [Blynk Console](https://blynk.cloud/dashboard) → Klik menu “Templates” → + New Template.
2. Isi nama: misalnya `Siaga Banjir` → Pilih perangkat: ESP32 → Connection type: WiFi → Klik Done.
3. Buka tab “Datastreams” untuk menambahkan virtual pin:
   
| No | Nama Datastream    | Jenis Data | Virtual Pin | Rentang Nilai / Isi                   | Fungsi                                                        |
| -- | ------------------ | ---------- | ----------- | ------------------------------------- | ------------------------------------------------------------- |
| 1  | Ketinggian Air     | Integer    | V0          | 0 – 100 (atau sesuai kebutuhan)       | Menampilkan nilai jarak/ketinggian air dari sensor ultrasonik |
| 2  | Sensor Air Digital | Integer    | V1          | 0 = Tidak ada air, 1 = Air terdeteksi | Menampilkan status sensor air digital                         |
| 3  | Status Banjir      | String     | V2          | “AMAN / WASPADA / BAHAYA”             | Menampilkan status kondisi banjir                             |


4. Simpan, lalu kembali ke **Devices** → klik **+ New Device** → pilih **From Template**, pilih template tadi, lalu beri nama `Siaga Banjir`.
5. Setelah device dibuat, akan muncul:
   * BLYNK_TEMPLATE_ID
   * BLYNK_TEMPLATE_NAME
   * BLYNK_AUTH_TOKEN
     Salin dan gunakan data ini di kode program.
6. Unduh aplikasi Blynk IoT dari Play Store / App Store.
7.  Login dengan akun yang sama seperti di Blynk Console.
8.  Masuk ke menu "Devices", pilih device `Siaga Banjir`.
9.  Klik ikon pensil (edit layout), tambahkan widget berikut:
   * **Gauge** → untuk Ketinggian Air:
     * Datastream: V0 (Ketinggian Air)
     * Label: Centimeter (cm)
   * **LED Widget** → untuk indikator api (V1)
   * **LCD** → untuk menampilkan Status bahaya permukaan air (V2)
10. Simpan dan kembali ke dashboard aplikasi.
11. Upload kode ke ESP32 versi IoT. → Buka aplikasi Blynk, nyalakan perangkat.
12. Uji sensor menggunakan air dan melakukan pengetesan jarak permukaan pada sensor ultrasonik.
* Perhatikan:
  * Gauge (V0) naik jika permukaan mendekati sensor ultrasonik.
  * LED indikator menyala sesuai kondisi yang telah disesuaikan.
  * Status pada LCD di aplikasi memberikan peringatan sesuai kondisi yang telah disesuaikan

> Dengan pengaturan ini, sistem sudah sepenuhnya terintegrasi dengan aplikasi Blynk, siap menerima data sensor dan memberikan peringatan secara otomatis.


### 7.3 Implementasi Kode Sistem

#### 7.3.1 Versi Konvensional (Offline)   
Berikut adalah potongan kode implementasi sistem peringatan dini banjir versi konvensional (tanpa koneksi internet), menggunakan ESP32 sebagai mikrokontroler utama. Kode ini mengintegrasikan pembacaan sensor air dan ultrasonik dengan logika aktivasi LED sebagai output.

```cpp
#include "Ultrasonic.h"

// Pin
#define WATER_SENSOR 32
#define LED1 13   // LED Hijau
#define LED2 15   // LED Merah

Ultrasonic ultrasonic(27);

// Variabel utama
long RangeInCentimeters;
int waterState;

void setup()
{
  Serial.begin(9600);

  pinMode(WATER_SENSOR, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

  Serial.println("Sistem Monitoring Ketinggian Air (Offline)");
}

void loop()
{
  // Baca sensor
  RangeInCentimeters = ultrasonic.MeasureInCentimeters();
  waterState = !digitalRead(WATER_SENSOR);

  // Tampilkan di Serial Monitor
  Serial.print("Jarak air: ");
  Serial.print(RangeInCentimeters);
  Serial.println(" cm");

  Serial.print("Status sensor air digital: ");
  Serial.println(waterState);

  // LOGIKA STATUS
  if (waterState == HIGH)
  {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    Serial.println("STATUS: AIR TERDETEKSI (BAHAYA BANJIR)");
  }
  else if (RangeInCentimeters <= 15)
  {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    Serial.println("STATUS: JARAK DEKAT (WASPADA)");
  }
  else
  {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    Serial.println("STATUS: AMAN");
  }

  Serial.println();
  delay(1500);
}
```


#### 7.3.2 Versi IoT (Terhubung BLYNK)

Program ini berfungsi sebagai **sistem peringatan dini banjir berbasis IoT** menggunakan **ESP32 dan Blynk**. Sensor ultrasonik digunakan untuk mengukur ketinggian air dalam cm, sementara sensor air digital mendeteksi jika air sudah mencapai level kritis. Data kemudian dikirim **secara real-time ke aplikasi Blynk**, sehingga pengguna dapat memantau kondisi dari jarak jauh. LED hijau menandakan waspada, dan LED merah menandakan bahaya ketika air menyentuh sensor. Informasi status juga ditampilkan di Serial Monitor untuk pengecekan sistem.

```cpp
#define BLYNK_TEMPLATE_ID "TMPL6ej-IPqPo"
#define BLYNK_TEMPLATE_NAME "Siaga Banjir"
#define BLYNK_AUTH_TOKEN "nTlnWVNxBY0b96M1O2EjNisdOXAFmS8X"

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include "Ultrasonic.h"

char ssid[] = "Ryan D Gracia";
char pass[] = "99999999";

// Pin
#define WATER_SENSOR 32
#define LED1 13
#define LED2 15

Ultrasonic ultrasonic(27);

// Variabel utama
long RangeInCentimeters;
int waterState;

void setup()
{
  Serial.begin(9600);

  pinMode(WATER_SENSOR, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop()
{
  Blynk.run();

  RangeInCentimeters = ultrasonic.MeasureInCentimeters();
  waterState = !digitalRead(WATER_SENSOR);

  Serial.print("Jarak air: ");
  Serial.print(RangeInCentimeters);
  Serial.println(" cm");

  Serial.print("Status sensor air digital: ");
  Serial.println(waterState);

  // LOGIKA
  if (waterState == HIGH)
  {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    Serial.println("STATUS: AIR TERDETEKSI");

    Blynk.virtualWrite(V2, "BAHAYA BANJIR TINGGI");
  }
  else if (RangeInCentimeters <= 15)
  {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    Serial.println("STATUS: JARAK DEKAT");

    Blynk.virtualWrite(V2, "WASPADA BANJIR");
  }
  else
  {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    Serial.println("STATUS: AMAN");

    Blynk.virtualWrite(V2, "AMAN");
  }

  // Kirim data ke Blynk
  Blynk.virtualWrite(V0, RangeInCentimeters);
  Blynk.virtualWrite(V1, waterState);

  Serial.println();
  delay(1500);
}
```




## 8. HASIL DAN PEMBAHASAN

Pada tahapan ini, memberikan hasil implementasi dan pengujian sistem secara keseluruhan, baik pada level perangkat keras maupun integrasi IoT melalui platform Blynk. Pembahasan difokuskan pada respons sensor, indikator keluaran, serta kinerja sistem dalam memantau ketinggian air secara real-time.

### 8.1 Tampilan Alat

Gambar berikut menunjukkan prototipe alat sistem peringatan dini banjir berbasis ESP32 yang telah dirakit:

"<img width="259" height="335" alt="Screenshot 2026-01-06 164537" src="https://github.com/user-attachments/assets/8e3e2435-948d-4609-b3ff-01f259b182ca" /> <img width="259" height="335" alt="image" src="https://github.com/user-attachments/assets/88af0e1c-75c5-4532-a566-3a8f59ecb30f" />


### 8.2 Respons Sensor Air dan Ultrasonik

Pengujian dilakukan dengan mendekatkan permukaan air ke sensor ultrasonik serta menyentuhkan air ke sensor air digital. Dari hasil pengamatan terlihat bahwa:

* Sensor ultrasonik membaca jarak permukaan air terhadap sensor dalam satuan cm.

* Sensor air digital akan memberikan logika HIGH ketika air sudah menyentuh probe sensor (dibalik dengan !digitalRead() sehingga terbaca sebagai 1 di Serial Monitor).

Pada sistem ini, sensor ultrasonik digunakan untuk mengukur jarak antara sensor dengan permukaan air dalam satuan centimeter, sedangkan sensor air digital hanya mendeteksi keberadaan air pada level tertentu (logika 1 = air terdeteksi). Kombinasi kedua sensor memungkinkan sistem menentukan tingkat risiko banjir secara bertahap. Respons kedua sensor ini langsung muncul pada Serial Monitor dan indikator LED, serta dikirimkan ke aplikasi Blynk secara real-time. Hal ini menunjukkan bahwa sistem mampu mendeteksi kondisi air secara dini dan memberikan peringatan bertingkat sesuai kondisi bahaya.

#### 8.2.1 Hasil Pengujian Sensor Ultrasonik  
| No | Kondisi Uji                     | Jarak Air (CM) | Status Sistem | 
| -- | ------------------------------- | ------------- | -----------------  | 
| 1  | Air jauh dari sensor          | 25–100            | Aman                  | 
| 2  | Air mulai mendekati sensor       | 10-15    | Waspada Banjir             | 
| 3  | Air sangat dekat / menyentuh     | 0-5    | Bahaya Banjir             | 

> Jarak dibaca secara kontinu sehingga perubahan kecil pada ketinggian air langsung terdeteksi oleh sistem.

#### 8.2.2 Hasil Pengujian Sensor Air Digital  
| No | Kondisi Uji                     | Nilai Pembacaan | Status Logika |      Keterangan    |
| -- | ------------------------------- | ------------- | -----------------  | ----------------|
| 1  | Air jauh dari sensor          | 0            | Tidak Aktif           | Aman            |
| 2  | Sensor Terkena Air      | 1  | Aktif             |                Air Terdeteksi Jelas |

> Sensor air digital bekerja sebagai indikator banjir kritis karena hanya aktif ketika air benar-benar menyentuh sensor.



#### 8.2.3 Hasil Pengujian Kombinasi Sensor dan Respons Sistem

Tabel berikut menunjukkan hubungan antara jarak air, status sensor air digital, serta respons LED dan pesan status yang dikirim ke Blynk.

| No | Jarak Air (cm) | Sensor Air | LED Hijau (LED1) | LED Merah (LED2)    | Status Serial Monitor| Status di BLYNK | 
| -- | ------- | ---------- | ---------- | ------------ | --------------- | ----- |
| 1  | > 15     | 0          | OFF          | OFF    | STATUS: AMAN        | AMAN   |
| 2  | ≤ 15    |    0       | ON          | OFF     | STATUS: JARAK DEKAT | WASPADA BANJIR   |
| 3  | 4-1     | 1          | OFF          | ON | STATUS: AIR TERDETEKSI    | BAHAYA BANJIR TINGGI   |


### 8.3 Respons Output Lokal (LED Indikator)

Output LED menunjukkan status banjir sacara visual:

**A. Kondisi Aman**

* LED hujau: OFF
* LED merah: OFF
* Tidak ada bahaya

**B. Kondisi Waspada (air mulai naik ≤ 15 cm)**

* LED hijau: ON
* LED merah: OFF
* Tanda perhatian dini

**C. Kondisi Bahaya (air menyentuh sensor)**

* LED hijau: OFF
* LED merah: ON
* Menandakan potensi banjir tinggi



<img width="259" height="335" alt="Screenshot 2026-01-05 163038" src="https://github.com/user-attachments/assets/3c868170-d744-4b82-a1d1-b9cca3e4bc54" />


> Dengan indikator ini, pengguna tetap bisa mengetahui kondisi meskipun tanpa aplikasi.


### 8.4 Integrasi Aplikasi Blynk

ESP32 berhasil mengirimkan data ke Blynk secara real-time:

| No | Jarak Air (cm) | Sensor Air | V0 (Jarak) | V1 (Status Air)    | V2 (Pesan Status)|
| -- | ------- | ---------- | ---------- | ------------ | --------------- |
| 1  |   26     | 0          | 26          | 0    | AMAN        |
| 2  |     12   |   0        | 12          | 0     | WASPADA BANJIR | 
| 3  |   1      | 1          | 1          | 1 | BAHAYA BANJIR TINGGI    |

<img width="800" height="335" alt="Screenshot 2026-01-06 170923" src="https://github.com/user-attachments/assets/fbde804b-91bc-4fa1-ba78-cf6eb4c18c5f" />

<img width="259" height="335" alt="image" src="https://github.com/user-attachments/assets/a83acba1-2efc-47fa-a78f-3824e244d718" />


### 8.5 Pengujian Integrasi Sistem IoT

Pengujian integrasi sistem IoT dilakukan setelah seluruh komponen — yaitu sensor ultrasonik, sensor air digital, indikator LED, mikrokontroler ESP32, serta platform Blynk — dirangkai dan diprogram menjadi satu sistem utuh. Tujuan dari pengujian ini adalah untuk memastikan bahwa semua komponen tidak hanya berfungsi secara mandiri, tetapi juga mampu bekerja secara terpadu dalam membaca kondisi ketinggian air, mengolah data, menampilkan indikator visual, dan mengirimkan informasi ke platform IoT secara real-time.

Pada tahap ini, dilakukan beberapa skenario pengujian berdasarkan variasi ketinggian air dan aktivasi sensor air digital. Data yang terbaca oleh ESP32 langsung diproses untuk menentukan status sistem (Aman, Waspada, atau Bahaya), kemudian hasilnya ditampilkan melalui LED indikator dan dikirimkan ke aplikasi Blynk pada virtual pin V0 (jarak), V1 (status sensor air), dan V2 (status sistem).

**Tabel Data Hasil Uji Integrasi Sistem IoT**

| No | Kondisi Fisik Air                               | Jarak Air (cm) | Sensor Air Digital | Status Sistem        | LED Hijau | LED Merah | Status di Aplikasi Blynk |
| -: | ----------------------------------------------- | -------------- | ------------------ | -------------------- | --------- | --------- | ------------------------ |
|  1 | Air berada jauh dari sensor dan belum kritis    | 25–30          | 0 (tidak aktif)    | Aman                 | OFF       | OFF       | AMAN                     |
|  2 | Air mulai mendekati sensor (≤ 15 cm)            | 10–15          | 0 (tidak aktif)    | Waspada Banjir       | ON        | OFF       | WASPADA BANJIR           |
|  3 | Air menyentuh sensor air digital (level kritis) | 1–5            | 1 (aktif)          | Bahaya Banjir Tinggi | OFF       | ON        | BAHAYA BANJIR TINGGI     |

> Data pada tabel menunjukkan bahwa setiap perubahan kondisi air menghasilkan respons langsung pada output sistem, baik pada LED indikator maupun aplikasi Blynk.

Selama pengujian, seluruh proses berjalan secara real-time tanpa jeda signifikan antara pembacaan sensor dengan tampilan data pada dashboard Blynk. Hal ini menunjukkan bahwa komunikasi WiFi dan fungsi Blynk.run() bekerja dengan stabil dalam menjaga koneksi antara ESP32 dan server. Selain itu, sistem tetap memberikan indikator lokal melalui LED, sehingga informasi tetap dapat diakses meskipun perangkat pengguna tidak sedang membuka aplikasi.

Berdasarkan hasil pengamatan, dapat disimpulkan bahwa sistem telah berfungsi secara terintegrasi, di mana proses deteksi, pemrosesan data, pemberian indikator visual, serta pengiriman data IoT berjalan sinkron dan sesuai dengan logika yang dirancang. Dengan demikian, sistem peringatan dini banjir berbasis IoT ini telah siap digunakan sebagai alat monitoring ketinggian air yang informatif, responsif, dan mudah dipantau dari jarak jauh.

## 9. Kesimpulan

Berdasarkan pengujian dan implementasi, diperoleh kesimpulan:

**1. Deteksi Dini Banjir**

Sistem mampu membaca ketinggian air menggunakan sensor ultrasonik dan mendeteksi level kritis melalui sensor digital, sehingga memberikan peringatan bertingkat: Aman, Waspada, dan Bahaya.

**2. Respons Visual dan Notifikasi Real-Time**

LED hijau dan merah memberikan indikator visual, sementara Blynk menerima data real-time untuk pemantauan jarak jauh.

**3. Integrasi ESP32 dan IoT Efektif**

ESP32 memproses sensor, mengendalikan output, dan mengirim informasi ke Blynk, membuat sistem peringatan dini banjir berbasis IoT berjalan responsif dan informatif.

**4. Sistem Layak Diimplementasikan** 

Berdasarkan hasil pengujian keseluruhan, sistem peringatan dini banjir berbasis ESP32 ini dinilai layak digunakan sebagai alat monitoring sederhana yang bersifat informatif serta mudah direalisasikan pada lingkungan masyarakat.

## 10. Kontribusi Anggota

Pelaksanaan proyek ini dilakukan secara kolaboratif oleh anggota tim. Setiap anggota memiliki pembagian tugas yang jelas sesuai dengan kompetensi dan perannya, namun tetap saling bekerja sama dalam proses diskusi, evaluasi, dan penyelesaian permasalahan teknis selama perancangan sistem.

### 10.1 Tabel Pembagian Kontribusi Anggota

| No | Nama Anggota                   | Peran dan Kontribusi Utama                                                                                                                                                                                                                                                                        |
| -: | ------------------------------ | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
|  1 | **Muhammad Abdurrahman Haris** | • Merancang konsep sistem peringatan dini banjir berbasis IoT<br>• Menyusun arsitektur perangkat keras dan alur kerja sistem<br>• Mengembangkan program ESP32 (sensor, LED, WiFi, dan Blynk)<br>• Mengintegrasikan sistem dengan platform IoT<br>• Menyusun struktur laporan dan penulisan teknis |
|  2 | **Badru Munir**                | • Melakukan perakitan perangkat keras dan wiring sensor<br>• Melaksanakan pengujian sensor dan sistem secara bertahap<br>• Mengumpulkan serta mendokumentasikan data hasil pengujian<br>• Membantu analisis hasil dan validasi sistem<br>• Berkontribusi dalam penyusunan laporan akhir           |


Selain pembagian tugas tersebut, kedua anggota tim juga berperan aktif secara kolaboratif dalam seluruh tahapan penelitian. Keterlibatan bersama meliputi kegiatan:

1. Melaksanakan diskusi teknis dalam perancangan metode dan pemilihan komponen sistem.
2. Melakukan proses debugging program, penelusuran kesalahan, serta perbaikan modul perangkat lunak dan perangkat keras.
3. Melakukan evaluasi kinerja sistem, khususnya pada tahap integrasi IoT dan pengujian fungsionalitas secara menyeluruh.
4. Menyusun kesimpulan penelitian serta merumuskan rekomendasi pengembangan sistem pada tahap berikutnya.

### 10.2 Penilaian Kinerja Anggota Tim Proyek

**1. Muhammad Abdurrahman Haris**
**Nilai: 97 / 100**

Muhammad Abdurrahman Haris menunjukkan peran yang dominan dan strategis dalam perancangan proyek ini. Ia bertanggung jawab penuh dalam perancangan konsep sistem peringatan dini banjir berbasis IoT, mulai dari perumusan ide awal, penyusunan arsitektur sistem, hingga pengembangan perangkat lunak pada ESP32. Kemampuannya dalam mengintegrasikan sensor, modul komunikasi WiFi, serta platform Blynk menunjukkan penguasaan teknis yang baik dan pemahaman sistem yang menyeluruh.

Selain aspek teknis, Haris juga berkontribusi besar dalam penyusunan struktur laporan dan penulisan teknis, sehingga dokumentasi proyek tersusun rapi, sistematis, dan mudah dipahami. Dalam diskusi tim, ia aktif memberikan arahan teknis dan solusi ketika terjadi permasalahan, khususnya pada tahap debugging dan integrasi sistem. Nilai yang diberikan mencerminkan kontribusi yang sangat kuat, konsistensi kerja, serta tanggung jawab yang tinggi, dengan tetap membuka ruang kolaborasi bersama anggota lain.

**2. Badru Munir**
**Nilai: 95 / 100**

Badru Munir berperan penting dalam aspek implementasi lapangan dan pengujian sistem. Ia bertanggung jawab dalam perakitan perangkat keras, pengkabelan sensor, serta memastikan seluruh komponen terpasang dan berfungsi sesuai dengan rancangan. Ketelitiannya dalam melakukan pengujian bertahap terhadap sensor dan sistem secara keseluruhan membantu memastikan keandalan dan kestabilan sistem yang dikembangkan.

Selain itu, Badru Munir secara aktif mengumpulkan dan mendokumentasikan data hasil pengujian, yang menjadi dasar penting dalam proses analisis dan validasi sistem. Kontribusinya dalam evaluasi kinerja sistem dan penyusunan laporan akhir menunjukkan sikap kerja yang konsisten dan kooperatif. Dalam kerja tim, ia menunjukkan kesiapan membantu dan berkolaborasi, khususnya pada tahap debugging dan pengujian fungsional. Nilai yang diberikan mencerminkan kinerja yang sangat baik, tanggung jawab tinggi, dan kontribusi nyata terhadap keberhasilan proyek.

### 10.3 Kesimpulan Penilaian Tim dan Kontribusi Anggota

Secara keseluruhan, kedua anggota tim menunjukkan kinerja yang seimbang, saling melengkapi, dan berkontribusi nyata sesuai peran masing-masing. Tidak terdapat dominasi yang merugikan, melainkan sinergi yang kuat antara perancangan sistem dan implementasi teknis. Perbedaan nilai diberikan secara wajar berdasarkan lingkup tanggung jawab, namun keduanya tetap berada pada kategori sangat baik dan layak memperoleh apresiasi yang setara sebagai satu tim yang solid.

Dengan adanya pembagian peran yang terstruktur serta koordinasi yang baik antaranggota, pelaksanaan proyek ini dapat berjalan secara efektif, sistematis, dan sesuai dengan tujuan penelitian yang telah ditetapkan.


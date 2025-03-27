# Distributed Computing Project

## Proje Açıklaması
Bu proje, **MPI ve OpenMP** kullanarak paralel hesaplama yapmaktadır. 

## Kullanım Talimatları
Önce Docker konteynerlerini oluşturup çalıştırın:

docker build -t mpi-openmp-image .

docker-compose up --build

Kodların Açıklaması
main.c → MPI ve OpenMP kullanılarak yazılmış kod.

Dockerfile → MPI ve OpenMP için gerekli bağımlılıkları içeren Docker yapılandırması.

docker-compose.yml → Çalışma ortamını tanımlayan dosya.

YouTube Video Açıklaması
📺 Nasıl çalıştırıldığını görmek için tıklayın:
(https://youtu.be/S2DhgnFE4TQ)

Performans Karşılaştırması (MPI vs OpenMP)
Yöntem	Çalıştırma Süresi
MPI	0.23 saniye
OpenMP	0.19 saniye
MPI, çok sayıda işlemciye dağıtıldığında daha verimli olur.

OpenMP, tek makine içinde iş parçacıklarını yönetmek için daha iyidir.


1️⃣ MPI (Message Passing Interface) Nedir?
MPI, dağıtık bellekli sistemlerde çalışan bir paralel programlama modelidir.
Yani, birden fazla bilgisayar (node) veya birden fazla işlemci arasında veri paylaşımı yaparak büyük ölçekli hesaplamaları hızlandırır.

📌 Özellikleri:
✅ Dağıtık bellekli sistemler için uygundur. (Farklı makinelerde çalışabilir.)
✅ İşlemler birbirinden bağımsızdır ve veri paylaşımı mesajlarla sağlanır.
✅ HPC (High Performance Computing - Yüksek Performanslı Hesaplama) sistemlerinde yaygın olarak kullanılır.
✅ C, C++, Fortran gibi dillerle kullanılabilir.

📌 Çalışma Mantığı:

MPI_Init: MPI ortamını başlatır.

MPI_Comm_rank: Mevcut sürecin ID’sini alır.

MPI_Comm_size: Toplam süreç sayısını alır.

MPI_Send / MPI_Recv: Süreçler arasında mesaj göndermek ve almak için kullanılır.

MPI_Finalize: MPI programını sonlandırır.

📌 Avantajları:
✅ Büyük ölçekli sistemlerde iyi çalışır.
✅ Farklı makinelerle iletişim kurarak süper bilgisayar seviyesinde hesaplama yapabilir.
✅ Veri paylaşımı kontrollü olduğu için ölçeklenebilirliği yüksektir.

📌 Dezavantajları:
❌ Programlaması daha zor çünkü mesaj gönderme/alma işlemlerini elle yönetmek gerekir.
❌ Senkronizasyon ve veri paylaşımı zor olabilir.

2️⃣ OpenMP (Open Multi-Processing) Nedir?
OpenMP, paylaşımlı bellekli sistemlerde çalışan bir paralel programlama modelidir.
Yani tek bir bilgisayardaki çok çekirdekli işlemcileri kullanarak hesaplamaları hızlandırır.

📌 Özellikleri:
✅ Paylaşımlı bellekli sistemler için uygundur. (Tek bir makinede çalışır.)
✅ İş parçacıkları (threads) kullanarak paralellik sağlar.
✅ C, C++, Fortran dillerine kolayca entegre edilebilir.
✅ Kodun içine pragma (#pragma omp) komutları eklenerek paralellik sağlanır.

📌 Çalışma Mantığı:

#pragma omp parallel: Kodun paralel çalışmasını sağlar.

#pragma omp for: Döngüleri paralel hale getirir.

#pragma omp critical: Kritik bölgelerde tek iş parçacığının çalışmasını sağlar.

#pragma omp barrier: Bütün iş parçacıklarının eşitlenmesini sağlar.

📌 Avantajları:
✅ Kodun içine direkt eklenebilir, mesajlaşma gerektirmez.
✅ Daha kolay programlanabilir.
✅ Hızlı ve düşük gecikmeli (low-latency) hesaplamalar için uygundur.

📌 Dezavantajları:
❌ Sadece paylaşımlı bellek sistemlerinde çalışır. (Farklı makinelerde çalışamaz.)
❌ Çok fazla çekirdek eklenince verim düşebilir.

3️⃣ MPI vs OpenMP Karşılaştırması
Özellik	MPI	OpenMP
Kullanım Alanı	Dağıtık bellek sistemleri	Paylaşımlı bellek sistemleri
Ölçeklenebilirlik	Büyük ölçekli sistemlerde iyi çalışır	Küçük-orta ölçekli sistemlerde iyidir
Paralellik Modeli	Farklı makineler arasında mesajlaşma	Aynı makinede iş parçacıkları
Programlama Zorluğu	Daha karmaşık (veri paylaşımı zor)	Daha kolay (pragma komutları ile)
Veri Paylaşımı	Mesaj tabanlı (MPI_Send, MPI_Recv)	Bellek tabanlı (paylaşımlı değişkenler)
Gecikme (Latency)	Daha yüksek (ağ iletişimi var)	Daha düşük (aynı bellek kullanılıyor)
En Çok Kullanıldığı Alanlar	HPC, Süper bilgisayarlar, Büyük veri analizi	Bilimsel hesaplamalar, Çok çekirdekli CPU’lar

4️⃣ Hangi Durumda Hangisini Kullanmalıyım?
✅ Eğer projeniz büyük bir süper bilgisayar veya dağıtık sistemde çalışacaksa, MPI kullanılmalı.
✅ Eğer tek bir makine içinde paralel işlem yapmak istiyorsanız, OpenMP daha uygundur.
✅ Hibrit sistemlerde (hem dağıtık hem de çok çekirdekli) ikisini birlikte kullanılmalı!

5️⃣ Sonuç ve Özet
MPI, büyük ölçekli, dağıtık sistemler için idealdir.

OpenMP, küçük-orta ölçekli, paylaşımlı bellek sistemleri için uygundur.

Eğer büyük bir süper bilgisayarda çalışıyorsanız, MPI kullanılmalı.

Eğer sadece çok çekirdekli bir CPU’da işlem yapıyorsanız, OpenMP yeterlidir.

Hibrit kullanımlar mümkündür. (MPI + OpenMP)

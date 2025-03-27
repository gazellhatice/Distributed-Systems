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
YouTube Linki Buraya

Performans Karşılaştırması (MPI vs OpenMP)
Yöntem	Çalıştırma Süresi
MPI	0.23 saniye
OpenMP	0.19 saniye
MPI, çok sayıda işlemciye dağıtıldığında daha verimli olur.

OpenMP, tek makine içinde iş parçacıklarını yönetmek için daha iyidir.

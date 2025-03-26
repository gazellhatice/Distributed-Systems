FROM ubuntu:latest

# Gerekli paketleri yükle
RUN apt-get update && apt-get install -y \
    mpich \
    libomp-dev \
    build-essential

# Çalışma dizinini oluştur
WORKDIR /app

# Sadece src içindeki main.c dosyasını kopyala
COPY src/main.c /app/main.c

# Kodu derleyelim
RUN mpicc -fopenmp -o main main.c

CMD ["bash"]

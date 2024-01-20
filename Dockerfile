# Use Ubuntu 18.04 as the base image
FROM ubuntu:22.04

# Install required build tools
RUN apt-get update && \
    apt-get install -y g++ sudo make cmake git libpcre3-dev libssl-dev libboost-all-dev && \
    rm -rf /var/lib/apt/lists/*
ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update -y

RUN sudo apt install software-properties-common -y
RUN sudo apt install pkg-config -y
RUN sudo apt install libbrotli-dev
RUN echo "" | sudo add-apt-repository ppa:pistache+team/unstable
RUN apt install libbrotli-dev

RUN sudo apt update
RUN sudo apt install libpistache-dev -y
RUN sudo apt install libcurl4-openssl-dev -y
RUN apt-get install -y wget
RUN apt install libopencv-dev -y

# Install opecv from source
RUN git clone https://github.com/opencv/opencv.git && \
    cd opencv && \
    mkdir build && \
    cd build && \
    cmake -D CMAKE_BUILD_TYPE=Release -D CMAKE_INSTALL_PREFIX=/usr/local .. && \
    make -j8 && \
    make install


WORKDIR /app

# Copy the source code into the container
COPY CMakeLists.txt .
COPY src/ ./src/
RUN cmake .
RUN cmake --build .

CMD ["./MyPistacheProject"]

FROM alpine:3.18

RUN apk add --no-cache gcc g++ make curl tar gzip libc-dev

WORKDIR /build

RUN curl -sL -o vbcc.tar.gz http://phoenix.owl.de/tags/vbcc0_9hP2.tar.gz && \
    mkdir vbcc_src && tar xf vbcc.tar.gz -C vbcc_src --strip-components=1 && \
    cd vbcc_src && \
    mkdir -p bin && \
    yes "" | make TARGET=hc12 && \
    mkdir -p /opt/vbcc/bin && \
    cp bin/vbcchc12 bin/vc /opt/vbcc/bin/

RUN curl -sL -o vasm.tar.gz http://sun.hasenbraten.de/vasm/release/vasm.tar.gz && \
    mkdir vasm_src && tar xf vasm.tar.gz -C vasm_src --strip-components=1 && \
    cd vasm_src && \
    make CPU=6809 SYNTAX=std && \
    make CPU=6809 SYNTAX=mot && \
    cp vasm6809_std vasm6809_mot vobjdump /opt/vbcc/bin/

RUN curl -sL -o vlink.tar.gz http://sun.hasenbraten.de/vlink/release/vlink.tar.gz && \
    mkdir vlink_src && tar xf vlink.tar.gz -C vlink_src --strip-components=1 && \
    cd vlink_src && \
    make && \
    cp vlink /opt/vbcc/bin/

RUN mkdir -p /build/d77util/d77 /build/d77util/lib && \
    cd /build/d77util/d77 && \
    curl -sLO https://raw.githubusercontent.com/captainys/FM/master/7/util/d77/d77fileutil.cpp && \
    curl -sLO https://raw.githubusercontent.com/captainys/FM/master/7/util/d77/d77filesystem.cpp && \
    curl -sLO https://raw.githubusercontent.com/captainys/FM/master/7/util/d77/d77filesystem.h && \
    curl -sLO https://raw.githubusercontent.com/captainys/FM/master/7/util/d77/d77.cpp && \
    curl -sLO https://raw.githubusercontent.com/captainys/FM/master/7/util/d77/d77.h && \
    cd /build/d77util/lib && \
    curl -sLO https://raw.githubusercontent.com/captainys/FM/master/7/util/lib/fm7lib.cpp && \
    curl -sLO https://raw.githubusercontent.com/captainys/FM/master/7/util/lib/fm7lib.h && \
    curl -sLO https://raw.githubusercontent.com/captainys/FM/master/7/util/lib/cpplib.cpp && \
    curl -sLO https://raw.githubusercontent.com/captainys/FM/master/7/util/lib/cpplib.h && \
    cd /build/d77util/d77 && \
    g++ -std=c++11 -O2 -o /opt/vbcc/bin/d77fileutil d77fileutil.cpp d77filesystem.cpp d77.cpp ../lib/fm7lib.cpp ../lib/cpplib.cpp

RUN rm -rf /build

ENV PATH="/opt/vbcc/bin:${PATH}"
ENV VBCC="/opt/vbcc"

RUN mkdir -p /opt/vbcc/config && \
    printf -- "-cc=vbcchc12 -cpu=6809 -quiet %%s -o= %%s %%O -I/opt/libfm7/include\n-as=vasm6809_std -quiet -Fvobj %%s -o %%s\n-rm=rm -f %%s\n-ld=vlink -b rawbin -T /opt/libfm7/ldscripts/libfm7_main.ld /opt/libfm7/src/main_cpu/crt0.o %%s %%s -o %%s\n" > /opt/vbcc/config/libfm7

COPY include /opt/libfm7/include
COPY ldscripts /opt/libfm7/ldscripts
COPY src /opt/libfm7/src
COPY templates /opt/libfm7/templates
COPY Makefile /opt/libfm7/Makefile
COPY docker/entrypoint.sh /entrypoint.sh

RUN chmod +x /entrypoint.sh && \
    make -C /opt/libfm7

WORKDIR /app

ENTRYPOINT ["/entrypoint.sh"]

CMD ["make"]


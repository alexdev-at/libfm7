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
RUN rm -rf /build
ENV PATH="/opt/vbcc/bin:${PATH}"
ENV VBCC="/opt/vbcc"
RUN mkdir -p /opt/vbcc/config && \
    printf -- "-cc=vbcchc12 -cpu=6809 -quiet %%s -o= %%s %%O -I/opt/libfm7/include\n-as=vasm6809_std -quiet -Fvobj %%s -o %%s\n-rm=rm -f %%s\n-ld=vlink -b rawbin -T /opt/libfm7/ldscripts/libfm7_main.ld /opt/libfm7/src/main_cpu/crt0.o %%s %%s -o %%s\n" > /opt/vbcc/config/libfm7
WORKDIR /app
CMD ["/bin/sh"]

FROM debian:unstable-slim

ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update                                                            
RUN apt-get install -qq --no-install-recommends                                  \
                    sudo                                                         \
                    clang                                                        \
                    gcc                                                          \
                    opam                                                         \
                    cpanminus                                                    \
                    git                                                          \
                    ssh                                                          \
                    ca-certificates
# RUN update-alternatives --install /usr/bin/clang clang /usr/bin/clang-11 1000
RUN useradd -d /home/eval -m -s /bin/bash eval     
RUN echo "eval ALL=(ALL) NOPASSWD: ALL" > /etc/sudoers.d/eval                 
RUN chmod 0440 /etc/sudoers.d/eval                     
RUN passwd -l eval                                               
RUN chown -R eval:eval /home/eval

USER eval
ENV HOME=/home/eval
WORKDIR /home/eval

# Setup opam
RUN opam init --disable-sandboxing -a -y && opam install dune

RUN opam install menhir -y
RUN opam install alcotest -y
RUN opam install sexplib -y


# Bring up Usuba
RUN git clone --recurse-submodules https://github.com/usubalang/usuba.git
# RUN git clone --recurse-submodules https://github.com/usubalang/benchmarks.git

RUN opam install ppx_sexp_conv -y
RUN opam install ppx_inline_test -y
RUN opam install ppx_deriving -y
RUN opam install ppx_sexp_conv -y
  


RUN cd usuba && opam exec --  ./configure
RUN cd usuba && opam exec -- dune build


# Bring up Perl dependencies (for benchmarks)
RUN sudo cpanm install -f File::Copy::Recursive             \
                          JSON                              \
                          Statistics::Test::WilcoxonRankSum \
                          Parallel::ForkManager

ENTRYPOINT [ "opam", "exec", "--"]
CMD ["/bin/bash", "-c", "ulimit -s unlimited && cd benchmarks && perl bench_perfs.pl" ]
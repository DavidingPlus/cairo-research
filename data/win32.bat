@REM download
conan download brotli/1.1.0:7e52046413f1e13a5fa19e3d410c5b50df627c3f -r Lark3rdParty
conan download bzip2/1.0.8:d16a91eadaaf5829b928b12d2f836ff7680d3df5 -r Lark3rdParty
conan download expat/2.5.0:ce5788ba7e3bb7dc834e36b06df66c481f42c99a -r Lark3rdParty
conan download fontconfig/2.14.2:7bdcd0ebc5985e64875ce195eb75728a18edbb87 -r Lark3rdParty
conan download freetype/2.13.0:27b2733304cef577b19f699fec3a5bdbefb36d16 -r Lark3rdParty
conan download glib/2.78.0:12d888a7f41df36537da27d0ec738aea62dee0f1 -r conancenter
conan download libffi/3.4.4:3fb49604f9c2f729b85ba3115852006824e72cab -r conancenter
conan download libgettext/0.22:b3e4dccd9a7572a5a29c77cc68475a955d494ef7 -r conancenter
conan download libiconv/1.17:3fb49604f9c2f729b85ba3115852006824e72cab -r conancenter
conan download libpng/1.6.40:ce650d9f1f1c1c0839cf0694a55c1351ddbed859 -r Lark3rdParty
conan download lzo/2.10:3fb49604f9c2f729b85ba3115852006824e72cab -r conancenter
conan download pcre2/10.42:d0174f35624ee8d538ad69ea935d0989a61efc1c -r conancenter
conan download pixman/0.40.0:3fb49604f9c2f729b85ba3115852006824e72cab -r conancenter
conan download zlib/1.3:3fb49604f9c2f729b85ba3115852006824e72cab -r Lark3rdParty
conan download cairo/1.18.0:602beed13834150491d7a60ac73c1660cae1a065 -r conancenter

@REM upload
conan upload glib/2.78.0:12d888a7f41df36537da27d0ec738aea62dee0f1 --all -r Lark3rdParty -c
conan upload libffi/3.4.4:3fb49604f9c2f729b85ba3115852006824e72cab --all -r Lark3rdParty -c
conan upload libgettext/0.22:b3e4dccd9a7572a5a29c77cc68475a955d494ef7 --all -r Lark3rdParty -c
conan upload libiconv/1.17:3fb49604f9c2f729b85ba3115852006824e72cab --all -r Lark3rdParty -c
conan upload lzo/2.10:3fb49604f9c2f729b85ba3115852006824e72cab --all -r Lark3rdParty -c
conan upload pcre2/10.42:d0174f35624ee8d538ad69ea935d0989a61efc1c --all -r Lark3rdParty -c
conan upload pixman/0.40.0:3fb49604f9c2f729b85ba3115852006824e72cab --all -r Lark3rdParty -c
conan upload cairo/1.18.0:602beed13834150491d7a60ac73c1660cae1a065 --all -r Lark3rdParty -c

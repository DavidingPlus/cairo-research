alias conan='~/.local/bin/conan'

# download
conan download brotli/1.1.0:b21556a366bf52552d3a00ce381b508d0563e081 -r Lark3rdParty
conan download bzip2/1.0.8:da606cf731e334010b0bf6e85a2a6f891b9f36b0 -r Lark3rdParty
conan download expat/2.5.0:c215f67ac7fc6a34d9d0fb90b0450016be569d86 -r Lark3rdParty
conan download fontconfig/2.14.2:b172ac37518ca059ccac0be9c3eb29e5179ecf1e -r Lark3rdParty
conan download freetype/2.13.0:f1014dc4f9380132c471ceb778980949abf136d3 -r Lark3rdParty
conan download glib/2.78.0:06c63123a2bb8b6d3ea5dcae501525df32efb7b5 -r conancenter
conan download libelf/0.8.13:6af9cc7cb931c5ad942174fd7838eb655717c709 -r conancenter
conan download libffi/3.4.4:6af9cc7cb931c5ad942174fd7838eb655717c709 -r conancenter
conan download libmount/2.39:6af9cc7cb931c5ad942174fd7838eb655717c709 -r conancenter
conan download libpng/1.6.40:7929d8ecf29c60d74fd3c1f6cb78bbb3cb49c0c7 -r Lark3rdParty
conan download libselinux/3.5:6b0384e3aaa343ede5d2bd125e37a0198206de42 -r conancenter
conan download lzo/2.10:6af9cc7cb931c5ad942174fd7838eb655717c709 -r conancenter
conan download pcre2/10.42:647f8233073b10c84d51b1833c74f5a1cb8e8604 -r conancenter
conan download pixman/0.40.0:6af9cc7cb931c5ad942174fd7838eb655717c709 -r conancenter
conan download util-linux-libuuid/2.39:6af9cc7cb931c5ad942174fd7838eb655717c709 -r conancenter
conan download xorg/system:5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9 -r conancenter
conan download zlib/1.3:6af9cc7cb931c5ad942174fd7838eb655717c709 -r Lark3rdParty
conan download cairo/1.18.0:8098347825649d9fd3e21c49992446a2a2193ad4 -r conancenter

# upload
conan upload glib/2.78.0:06c63123a2bb8b6d3ea5dcae501525df32efb7b5 --all -r Lark3rdParty -c
conan upload libelf/0.8.13:6af9cc7cb931c5ad942174fd7838eb655717c709 --all -r Lark3rdParty -c
conan upload libffi/3.4.4:6af9cc7cb931c5ad942174fd7838eb655717c709 --all -r Lark3rdParty -c
conan upload libmount/2.39:6af9cc7cb931c5ad942174fd7838eb655717c709 --all -r Lark3rdParty -c
conan upload libselinux/3.5:6b0384e3aaa343ede5d2bd125e37a0198206de42 --all -r Lark3rdParty -c
conan upload lzo/2.10:6af9cc7cb931c5ad942174fd7838eb655717c709 --all -r Lark3rdParty -c
conan upload pcre2/10.42:647f8233073b10c84d51b1833c74f5a1cb8e8604 --all -r Lark3rdParty -c
conan upload pixman/0.40.0:6af9cc7cb931c5ad942174fd7838eb655717c709 --all -r Lark3rdParty -c
conan upload util-linux-libuuid/2.39:6af9cc7cb931c5ad942174fd7838eb655717c709 --all -r Lark3rdParty -c
conan upload xorg/system:5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9 --all -r Lark3rdParty -c
conan upload cairo/1.18.0:8098347825649d9fd3e21c49992446a2a2193ad4 --all -r Lark3rdParty -c

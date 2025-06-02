pkgname=posgtkhello
pkgver=1.0
pkgrel=0
pkgdesc="Simple GTK2 C++ application template with a fully configured build system for PostmarketOS"
author="DiabloSat"
url="https://github.com/progzone122/posgtkhello"
license="MIT"
arch="armhf"
depends=""
makedepends="g++ cmake make build-base gtk+2.0-dev pango-dev cairo-dev gdk-pixbuf-dev glib-dev harfbuzz-dev freetype-dev fontconfig-dev"

source="mypkg-1.0.tar.gz"
builddir="$srcdir/app"

build() {
    cd "$builddir"
    mkdir -p build
    cd build
    cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr
    make
}

package() {
    cd "$builddir/build"
    make DESTDIR="$pkgdir" install
}

sha512sums="
2f5abe278d54bcb05089672bc6d970d4e3b947d953a48ef628ec7786117ed3ae52996ed05c3411c3c90b652dff7dda4c9fe30ffc7233ad5ac4be1694759418da  mypkg-1.0.tar.gz
"

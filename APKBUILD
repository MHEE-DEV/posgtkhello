pkgname=posgtkhello
pkgver=1.0
pkgrel=0
pkgdesc="posgtkhello"
url="https://example.com/posgtkhello"
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

sha512sums=""

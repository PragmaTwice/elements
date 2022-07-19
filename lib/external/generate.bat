git clone git://anongit.freedesktop.org/git/cairo
cd cairo
git checkout 1.17.6

meson setup build64 --buildtype release -D b_vscrt=mt --auto-features disabled -D fontconfig=enabled -D freetype=enabled -D png=enabled
meson compile -C build64
meson install -C build64 --destdir install

git clone git://anongit.freedesktop.org/git/cairo
cd cairo
git checkout 1.17.6

meson setup meson-build --backend vs2022 --buildtype release -D b_vscrt=mt --auto-features disabled -D fontconfig=enabled -D freetype=enabled -D png=enabled
(meson compile -C meson-build)
echo $null >> meson-build/subprojects/freetype/libfreetype.a
(meson install -C meson-build --destdir install)

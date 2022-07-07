git clone https://github.com/freedesktop/fontconfig
cd fontconfig
git checkout 2.14.0
vcvars64.bat
meson setup build64 --buildtype release -D b_vscrt=mt --auto-features disabled
meson install -C build64 --destdir install
vcvars32.bat
meson setup build32 --buildtype release -D b_vscrt=mt --auto-features disabled
meson install -C build32 --destdir install


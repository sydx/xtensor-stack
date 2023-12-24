mkdir build
cd build
cmake ^
  -G"Ninja" ^
  -DCMAKE_C_COMPILER=clang ^
  -DCMAKE_CXX_COMPILER=clang ^
  -DCMAKE_FORTRAN_COMPILER=gfortran ^
  -DCMAKE_INSTALL_PREFIX=%LIBRARY_PREFIX% ^
  -DCMAKE_INSTALL_INCLUDEDIR=%LIBRARY_PREFIX%/include ^
  -DCMAKE_INSTALL_LIBDIR=%LIBRARY_PREFIX%/lib ^
  -DCMAKE_INSTALL_BINDIR=%LIBRARY_PREFIX%/bin ^
  -DBUILD_SHARED_LIBS=ON ^
  -DCMAKE_INSTALL_LIBDIR=lib ^
  -DCMAKE_BUILD_TYPE=Release ^
  %SRC_DIR%
if errorlevel 1 exit 1

ninja
if errorlevel 1 exit 1

ninja install
if errorlevel 1 exit 1

# BattleShip
## 環境配置
本專案採用 Dev-c++ 5.11 開發

### Windows 配置：
確保 Windows/System32 資料夾下有如下檔案：
（64 位作業系統檢查 Windows/SysWOW64 ）
```
cxcore100.dll
glut32.dll
highgui100.dll
libguide40.dll
msvcr71.dll
```

### Dev-c++ 庫的配置：
確保 Dev-c++ 安裝目錄下 MinGW64\x86_64-w64-mingw32\bin 資料夾下有如下檔案：
```
libglu32.a
libglut32.a
libglut.a
libopengl.a
```
其次確保 Dev-c++ 安裝目錄下 MinGW64\x86_64-w64-mingw32\inlude\GL 資料夾下有如下檔案：
```
gl.h
glu.h
glut.h
```

### Dev-c++ 參數 Linker 設定：
```
-mwindows -lglut32 -lglu32 -lopengl32 -lwinmm -lgdi32 -m32 -lcv -lcxcore -lhighgui
```

### Dev-c++ 編譯器設定：
```TDM-GCC 4.9.2 32-bit Release```
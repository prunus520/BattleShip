# BattleShip
## 預覽
![開始畫面](/preview/main.png "開始畫面")
![擺放戰艦](/preview/place_ship.gif "擺放戰艦")
![沒攻擊到戰艦](/preview/not_hit_ship.png "沒攻擊到戰艦")
![攻擊到戰艦](/preview/hit_ship.png "攻擊到戰艦")
![電腦AI攻擊](/preview/computer_AI_attack.gif "電腦AI攻擊")
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

### Dev-c++ 參數 Linker 設定：
```
library/lib/GL/libglut32.a
library/lib/opencv/libcv.a
library/lib/opencv/libcxcore.a
library/lib/opencv/libhighgui.a
-mwindows -lglu32 -lopengl32 -lwinmm
```

### Dev-c++ 編譯器設定：
```TDM-GCC 4.9.2 32-bit Release```
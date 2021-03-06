# BattleShip
這是一款 1931 年由 **Clifford Von Wickler** 所設計出的雙人對戰遊戲。<br>
此程式在遊戲中玩家將六種不同戰艦部署在不同位置，之後玩家與電腦之間開始輪流展開攻擊。攻擊時若防守方在該座標未配置任何戰艦，則表示「**未擊中**」，反之若防守方在該座標有配置任何戰艦，則表示「**擊中**」，最先將對方戰艦全部擊沉者即為遊戲贏家。

## 預覽畫面
開始畫面<br>
![開始畫面](/preview/main.png)

左鍵可以抓取或拖曳戰艦，右鍵可以旋轉戰艦的方向<br>
![擺放戰艦](/preview/place_ship.gif)

左鍵點擊右方的格子可以攻擊電腦的戰艦<br>
![沒攻擊到戰艦](/preview/not_hit_ship.png)
![攻擊到戰艦](/preview/hit_ship.png "攻擊到戰艦")

電腦能夠判斷周圍是否有戰艦<br>
![電腦攻擊](/preview/computer_AI_attack.gif)

## 特殊按鍵
1. ESC -> 離開遊戲
1. D -> 上帝模式

## 尚未完成功能
1. 戰艦拖曳時按右鍵，戰艦會當場停住。
1. 戰艦超出方格一點點會強制回復到原位。
1. 戰艦抓取時無法呈現在最上面。
1. 電腦攻擊時無法判斷一個以上的戰艦。
1. 結束按鈕尚未完成。

## 未來新增的功能
1. 增加不同大小的戰艦。
1. 新增玩家隨機擺放戰艦的按鈕。
1. 新增玩家與電腦攻擊時的對話框。

## 環境配置
本專案採用 Dev-c++ 5.11 開發

#### Windows 配置：
確保 Windows/System32 資料夾下有如下檔案：
（64 位作業系統檢查 Windows/SysWOW64 ）
```
cxcore100.dll
glut32.dll
highgui100.dll
libguide40.dll
msvcr71.dll
```

#### Dev-c++ 參數 Linker 設定：
```
library/lib/GL/libglut32.a
library/lib/opencv/libcv.a
library/lib/opencv/libcxcore.a
library/lib/opencv/libhighgui.a
-mwindows -lglu32 -lopengl32 -lwinmm
```

#### Dev-c++ 編譯器設定：
```TDM-GCC 4.9.2 32-bit Release```

#### Dev-c++ 呼叫編譯器時加入以下的命令：
```-std=c++11```
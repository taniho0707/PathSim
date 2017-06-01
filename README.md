PathSim
======================
マイクロマウスのパスをシミュレートするソフトウェアのつもり。
Qtの勉強用に作るのでほどほど性能で満足する可能性大。

使い方
------
開発途中です。
なにもできません。

.mazeファイルについて
------
4byte: [float] 一辺の長さ(mm)
4x31byte: [uint32\_t] column
4x31byte: [uint32\_t] row
4x32byte: [uint32\_t] reached

LICENSE
------
This software is released under the GPL v2 License, see LICENSE.

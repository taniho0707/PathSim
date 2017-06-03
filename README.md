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
1byte: [uint8\_t] ClassType
1byte: [uint8\_t] n = MultiplePosition.size()
nx4byte: [int16\_t, int16\_t] (goalX, goalY)
4x31byte: [uint32\_t] column
4x31byte: [uint32\_t] row
4x32byte: [uint32\_t] reached

LICENSE
------
This software is released under the GPL v2 License, see LICENSE.

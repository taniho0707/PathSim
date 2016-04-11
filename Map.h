/**
 * @file Map.h
 * 迷路データを扱うためのクラスや，それに付随したいくつかのクラスを用意しています。<br>
 * 二次元，三次元ベクトルや壁データのクラスがあります。
 */
#ifndef INCLUDED_MAP_H
#define INCLUDED_MAP_H

#include "const.h"

#include "Walldata.h"


/**
 * 迷路データを管理するクラス
 */
class Map{
private:
	bool isPeripheryWall(int x, int y, int angle);

public:
	Map();

	/**
	 * @brief 一番上の壁がMSB，一番下の壁がLSB，左から順
	 */
	unsigned long column[31];
	/**
	 * @brief 一番右の壁がMSB，一番左の壁がLSB，下から順
	 */
	unsigned long row[31];
	/**
	 * @brief 一番右のマスがMSB，一番左のマスがLSB，下から順
	 */
	unsigned long reached[32];


	/**
	 * @brief 迷路データを初期化する
	 */
	void resetMap();
	/**
	 * @brief 到達マップを初期化する
	 */
	void resetReachedMap();


	/**
	 * @brief 壁を追加します
	 * @param x 壁を追加する区画のx座標
	 * @param y 壁を追加する区画のy座標
	 * @param angle 今自分が向いている絶対方向
	 * @param wall 今見えている壁情報
	 */
	void addWall(int x, int y, EMouseAngle angle, Walldata wall);

	/**
	 * @brief 壁を設定します
	 * @param x 壁を追加する区画のx座標
	 * @param y 壁を追加する区画のy座標
	 * @param angle 今自分が向いている絶対方向
	 * @param wall 今見えている壁情報
	 */
	void setWall(int x, int y, EMouseAngle angle, Walldata wall);

	/**
	 * @brief 壁を追加します。絶対方向でのみ指定が可能です。
	 * @param x 壁を追加する区画のx座標
	 * @param y 壁を追加する区画のy座標
	 * @param angle 今自分が向いている絶対方向
	 */
	void addSingleWall(int x, int y, EMouseAngle angle);

	/**
	 * @brief 壁を設定します。絶対方向でのみ指定が可能です。
	 * @param x 壁を追加する区画のx座標
	 * @param y 壁を追加する区画のy座標
	 * @param angle 今自分が向いている絶対方向
	 * @param wall 今見えている壁情報
	 * @bug まだaddSingleWallと同じ関数
	 */
	void setSingleWall(int x, int y, EMouseAngle angle, int wall);


	/**
	 * @brief 絶対方向から見て壁があるか確認します
	 * @param x 壁を追加する区画のx座標
	 * @param y 壁を追加する区画のy座標
	 * @param ang 今自分が見ている絶対方向
	 * @return 壁が存在したら1，なかったら0をintで返します
	 */
	int isExistWall(int x, int y, EMouseAngle ang);


	/**
	 * @brief 到達マップを設定します
	 * @param x 到達設定する区画のx座標
	 * @param y 到達設定する区画のy座標
	 */
	void setReached(int, int);

	/**
	 * @brief 到達したか確認します
	 * @param x 到達確認する区画のx座標
	 * @param y 到達確認する区画のy座標
	 * @return 到達していたら1，していなかったら0を返します
	 */
	int hasReached(int, int);


	/**
	 * @brief マウスから見たWalldataを絶対方向に変換します
	 * @param wall 変換元の壁情報
	 * @param ang マウスの向いている方向
	 * @return 変換後のWalldataを返します
	 */
	Walldata rotateWallToAbsolute(Walldata wall, EMouseAngle ang);

	/**
	 * @brief 絶対方向のWalldataをマウスから見た方向に変換します
	 * @param wall 変換元の壁情報
	 * @param ang 変換したい方向
	 * @return 変換後のWalldataを返します
	 */
	Walldata rotateWallToRelative(Walldata wall, EMouseAngle ang);


	/**
	 * @brief =演算子のオーバーロード。Mapクラスを代入します
	 * @bug できない
	 */
	/* Map& operator= (Map *tmp){ */
	/* 	/\* column = tmp->column; *\/ */
	/* 	/\* row = tmp->row; *\/ */
	/* 	/\* reached = tmp->reached; *\/ */
	/* 	/\* return *this; *\/ */
	/* } */


	~Map();
};


#endif

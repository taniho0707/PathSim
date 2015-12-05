/**
 * @file Pair.h
 * @brief 二次元ベクトルを実装したクラス
 */
#ifndef INCLUDED_PAIR_H
#define INCLUDED_PAIR_H

template <typename T>
class Pair{
private:

public:
	T x;
	T y;

	/**
	 * @brief コンストラクタ<br>ゼロベクトルとして初期化します
	 */
	Pair<T>(){
		x = 0;
		y = 0;
	}
	Pair<T>(T _x, T _y){
		x = _x;
		y = _y;
	}

	Pair<T>& operator= (Pair<T> tmp){
		x = tmp.x;
		y = tmp.y;
		return *this;
	}

	Pair<T> operator+ (Pair<T> input){
		Pair tmp;
		tmp.x = x + input.x;
		tmp.y = y + input.y;
		return tmp;
	}

	T operator== (Pair<T> input){
		if(x == input.x && y == input.y) return 1;
		else return 0;
	}

	~Pair<T>(){

	}
};

#endif

/**
 * @file Triple.h
 * @brief 三次元ベクトルを実装したクラス
 */
#ifndef INCLUDED_TRIPLE_H
#define INCLUDED_TRIPLE_H

template <typename T>
class Triple{
private:

public:
	T x;
	T y;
	T t;

	/**
	 * @brief コンストラクタ<br>ゼロベクトルとして初期化します
	 */
	Triple<T>(){
		x = 0;
		y = 0;
		t = 0;
	}
	Triple<T>(T _x, T _y, T _t){
		x = _x;
		y = _y;
		t = _t;
	}

	Triple<T>& operator= (Triple<T> tmp){
		x = tmp.x;
		y = tmp.y;
		t = tmp.t;
		return *this;
	}

	Triple<T> operator+ (Triple<T> input){
		Triple<T> tmp;
		tmp.x = x + input.x;
		tmp.y = y + input.y;
		tmp.t = t + input.t;
		return tmp;
	}

	int operator== (Triple<T> input){
		if(x == input.x && y == input.y && t == input.t) return 1;
		else return 0;
	}

	~Triple<T>(){

	}
};

#endif

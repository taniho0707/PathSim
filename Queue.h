/**
 * @file Queue.h
 * @brief Tripleクラスでのキューを実装したクラス<br>
 *        バッファーサイズはQUEUE_BUF_SIZE<br>
 * @todo リングバッファの実装
 */
#ifndef INCLUDED_QUEUE_H
#define INCLUDED_QUEUE_H

template <typename T>
class Queue{
private:
	Triple<T> data[QUEUE_BUF_SIZE];
	unsigned short currentTop;
	unsigned short currentEnd;

public:
	/**
	 * @brief コンストラクタ<br>
	 * 三次元バッファの初期化を行う
	 */
	Queue<T>(){
		currentTop = 0;
		currentEnd = 0;
		for(unsigned short i=0; i<QUEUE_BUF_SIZE; i++){
			data[i].x = 0;
			data[i].y = 0;
			data[i].t = 0;
		}
	}

	/**
	 * @brief プッシュする
	 * @param tmp プッシュするTripleデータ
	 * @return 成功すると0，失敗すると1をintで返す
	 */
	int push(Triple<T> tmp){
		if(currentEnd > QUEUE_BUF_SIZE) return 1;
		data[currentEnd] = tmp;
		++ currentEnd;
		return 0;
	}

	/**
	 * @brief ポップする<br>
	 * この関数の前に必ずempty()でデータが存在するかを確認する必要がある
	 * @return 次のTripleデータを返す
	 */
	Triple<T> pop(){
		++ currentTop;
		return data[currentTop - 1];
	}

	/**
	 * @brief データが存在するか確認する
	 * @return データが存在したら0，存在しなかったら1を返す
	 */
	int empty(){
		if(currentTop == currentEnd) return 1;
		else return 0;
	}

	/**
	 * @brief キューをリセットし，ポインタを先頭に戻す
	 */
	void reset(){
		currentTop = 0;
		currentEnd = 0;
	}

	~Queue<T>(){

	}
};

#endif

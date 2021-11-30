//
//  W12_P2_HashTable.cpp
//  INHA CLASS
//
//  Created by Kang Minsang on 2020/12/13.
//  Copyright © 2020 Kang Minsang. All rights reserved.
//

#include <iostream>
#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2
using namespace std;

class cell {
public:
    int key;
    int value;
    int flag;

    cell() {
        this->key = -1;
        this->value = -1;
        this->flag = NOITEM;
    }
};

class DoubleHashTable {
private:
    cell* hashArr;
    int arrSize; //테이블 크기 N
    int curSize; //현재 개수
public:
    DoubleHashTable(int size) {
        this->arrSize = size;
        this->hashArr = new cell[arrSize];
        this->curSize = 0;
    }

    bool isFull() {
        return curSize == arrSize;
    }

    bool isEmpty() {
        return curSize == 0;
    }

    int hashfunction(int key) {
        return key%arrSize;
    }

    int hashfunction2(int key) {
        return (17-(key%17));
    }

    void find(int key) {
        int probing = 1;
        int initial_idx = hashfunction(key)%arrSize; //homeaddress
        int curIdx = (hashfunction(key)+(probing-1)*hashfunction2(key))%arrSize;
        bool firstOpr = true;

        //반복조건 : 칸이 찬 ISITEM 이거나, 다음위치로 이동하라는 AVALEABLE인 경우
        while(hashArr[curIdx].flag == ISITEM || hashArr[curIdx].flag == AVAILABLE) {
            //값이 같은값을 찾은경우 반환한다
            if(hashArr[curIdx].key == key) {
                cout<<"find "<<key<<"\n";
                return;
            }
            //한바퀴를 돈 후 제자리로 온경우
            else if(curIdx == initial_idx && !firstOpr) {
                cout<<"loop\n";
                return;
            }
            //다음으로 이동하는 경우
            else {
                probing++;
                firstOpr = false;
                curIdx = (hashfunction(key)+(probing-1)*hashfunction2(key))%arrSize;
            }
        }
        //한바퀴 내에 NOITEM을 만난경우 : find값이 없는경우이다
        cout<<"don't find "<<key<<"\n";
    }

    void put(int key, int value) {
        int probing = 1;
        int initial_idx = hashfunction(key)%arrSize;
        int curIdx = (hashfunction(key)+(probing-1)*hashfunction2(key))%arrSize;
        bool firstOpr = true;

        if(isFull()) {
            cout<<"Full\n";
        }
        else {
            //반복조건 : 칸이 차있는 경우 다음칸으로 이동, 빈 경우인 AVAILABLE, NOITEM의 경우 다음위치 이동이 필요없다
            while(hashArr[curIdx].flag == ISITEM) {
                //한바퀴를 돈 경우 반환한다
                if(curIdx == initial_idx && !firstOpr) {
                    cout<<"loop\n";
                    break;
                }
                //다음칸으로 이동
                else {
                    probing++;
                    firstOpr = false;
                    curIdx = (hashfunction(key)+(probing-1)*hashfunction2(key))%arrSize;
                }
            }
            //넣을위치인 curIdx를 찾은 후 put 시작
            hashArr[curIdx].key = key;
            hashArr[curIdx].value = value;
            hashArr[curIdx].flag = ISITEM;
            curSize++;
        }
    }

    void erase(int key) {
        int probing = 1;
        int initial_idx = hashfunction(key)%arrSize;
        int curIdx = (hashfunction(key)+(probing-1)*hashfunction2(key))%arrSize;
        bool firstOpr = true;

        if(isEmpty()) {
            cout<<"Empty\n";
        }
        else {
            //반복조건 : 값이 있거나 값이 있었던 경우 : 삭제가 가능한 경우, NOITEM의 경우 이동이 필요없기 때문
            while(hashArr[curIdx].flag == ISITEM || hashArr[curIdx].flag == AVAILABLE) {
                //삭제대상을 찾은경우 : 삭제한다
                if(hashArr[curIdx].key == key) {
                    hashArr[curIdx].flag = AVAILABLE;
                    hashArr[curIdx].key = -1;
                    hashArr[curIdx].value = -1;
                    curSize--;
                    break;
                }
                //한바퀴 되돌아온경우 : 종료한다
                else if(curIdx == initial_idx && !firstOpr) {
                    cout<<"loop\n";
                    break;
                }
                //다음칸으로 위치이동한다
                else {
                    probing++;
                    firstOpr = false;
                    curIdx = (hashfunction(key)+(probing-1)*hashfunction2(key))%arrSize;
                }
            }
        }
    }

    void print() {
        for(int i=0; i<arrSize; i++) {
            cout<<hashArr[i].value<<" ";
        }
        cout<<"\n";
    }
};

int main()
{
    int T;
    cin>>T;
    while(T--) {
        int P;
        cin>>P;
        DoubleHashTable table = DoubleHashTable(P);
        int Q;
        cin>>Q;
        int key;
        while(Q--) {
            cin>>key;
            table.put(key,key);
        }
        table.print();
    }
}

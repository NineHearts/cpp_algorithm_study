/*조규현과 백승환은 터렛에 근무하는 직원이다. 하지만 워낙 존재감이 없어서 인구수는 차지하지 않는다. 다음은 조규현과 백승환의 사진이다.
이석원은 조규현과 백승환에게 상대편 마린(류재명)의 위치를 계산하라는 명령을 내렸다. 조규현과 백승환은 각각 자신의 터렛 위치에서 현재 적까지의 거리를 계산했다.
조규현의 좌표 $(x_1, y_1)$와 백승환의 좌표 $(x_2, y_2)$가 주어지고, 조규현이 계산한 류재명과의 거리 $r_1$과 백승환이 계산한 류재명과의 거리 $r_2$가 주어졌을 때, 류재명이 있을 수 있는 좌표의 수를 출력하는 프로그램을 작성하시오.*/

#include <iostream>
#include <string>

struct Pos {
    int x;
    int y;

    void init(std::string input);
};

void Pos::init(std::string input){

}

int main() {
    using std::string;
    
    int cycle;
    string in;
    Pos *jo;
    Pos *ba;

    std::cin >> cycle;
    jo = new Pos[cycle];
    ba = new Pos[cycle];

    for (int i = 0; i < cycle; i++){
        getline(std::cin, in);
    }

    return 0;
}
/*조규현과 백승환은 터렛에 근무하는 직원이다. 하지만 워낙 존재감이 없어서 인구수는 차지하지 않는다. 다음은 조규현과 백승환의 사진이다.
이석원은 조규현과 백승환에게 상대편 마린(류재명)의 위치를 계산하라는 명령을 내렸다. 조규현과 백승환은 각각 자신의 터렛 위치에서 현재 적까지의 거리를 계산했다.
조규현의 좌표 $(x_1, y_1)$와 백승환의 좌표 $(x_2, y_2)$가 주어지고, 조규현이 계산한 류재명과의 거리 $r_1$과 백승환이 계산한 류재명과의 거리 $r_2$가 주어졌을 때, 류재명이 있을 수 있는 좌표의 수를 출력하는 프로그램을 작성하시오.*/

#include <iostream>
#include <string>
#include <sstream>

struct Turret {
    int x;
    int y;
    int r;

    void init(int []);
    void show();
};

void Turret::init(int data[]) {
    x = data[0];
    y = data[1];
    r = data[2];
}

void Turret::show() {
    std::cout << "x : " << x << "\ty : " << y << "\tr : " << r << std::endl;
}

int main() {
    using std::string;
    
    int cycle;
    int a[3], b[3];

    string in;
    Turret *jo;
    Turret *ba;

    std::cin >> cycle;
    jo = new Turret[cycle];
    ba = new Turret[cycle];

    for (int i = 0; i < cycle; i++) {
        std::getline(std::cin, in);
        std::istringstream iss(in);

        for (int j = 0; j < 3; j++)
            iss >> a[j];
        for (int k = 0; k < 3; k++)
            iss >> b[k];

        jo[i].init(a); 
        ba[i].init(b);
    }
    
    for (int i = 0; i < cycle; i++) {
        jo[i].show();
        ba[i].show();
    }

    delete[] jo;
    delete[] ba;
    return 0;
}
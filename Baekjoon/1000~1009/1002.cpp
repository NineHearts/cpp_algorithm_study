/*조규현과 백승환은 터렛에 근무하는 직원이다. 하지만 워낙 존재감이 없어서 인구수는 차지하지 않는다. 다음은 조규현과 백승환의 사진이다.
이석원은 조규현과 백승환에게 상대편 마린(류재명)의 위치를 계산하라는 명령을 내렸다. 조규현과 백승환은 각각 자신의 터렛 위치에서 현재 적까지의 거리를 계산했다.
조규현의 좌표 $(x_1, y_1)$와 백승환의 좌표 $(x_2, y_2)$가 주어지고, 조규현이 계산한 류재명과의 거리 $r_1$과 백승환이 계산한 류재명과의 거리 $r_2$가 주어졌을 때, 류재명이 있을 수 있는 좌표의 수를 출력하는 프로그램을 작성하시오.*/

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

/*
    먼저 조규현과 백승환의 위치가 같을 경우와 : x1 == x2 && y1 == y2
    다를 경우로 구분할 수 있다.
    조규현과 백승환의 위치가 서로 같다면 류재명(마린)까지의 위치인 반지름이 같다면 있을 수 있는 위치는 무한대,
    반지름이 다르다면 마린이 있을 수 있는 위치는 0이 된다.

    서로의 위치가 다를 경우 x1 != x2 || y1 == y2
    
    두 점에서 내접할 때, 한 점에서 내접할 때,
    두 점에서 외접할 때, 한 점에서 외접할 때,
    한 원이 다른 원 안에서 만나지 않을 때, 
    한 원이 다른 원 밖에서 만나지 않을 때 
    
    이렇게 총 6가지로 나눌 수 있다.
*/

// 터렛의 좌표와 마린의 거리를 저장할 구조체
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

// 두 터렛 사이의 거리를 반환
double distance(Turret& T1, Turret& T2) {
    return sqrt(pow(T1.x - T2.x, 2) + pow(T1.y - T2.y, 2));
}

int main() {
    using std::string;
    
    int cycle;
    int a[3], b[3];

    string in;
    Turret *jo;
    Turret *ba;

    std::cin >> cycle;
    std::cin.ignore();          // 개행 문자 제거

    jo = new Turret[cycle];     // 케이스의 갯수에 따라 동적 구조체 배열 선언
    ba = new Turret[cycle];     // 케이스의 갯수에 따라 동적 구조체 배열 선언

    for (int i = 0; i < cycle; i++) {
        std::getline(std::cin, in);
        std::istringstream iss(in);     // 띄어쓰기를 제거하기 위한 istringstream

        for (int j = 0; j < 3; j++)
            iss >> a[j];
        for (int k = 0; k < 3; k++)
            iss >> b[k];

        jo[i].init(a);
        ba[i].init(b);
    }
    
    for (int i = 0; i < cycle; i++) {
        double dist = distance(jo[i], ba[i]);

        if (dist == 0) {                        // 조규현과 백승환의 터렛 위치가 같을 때

            if (jo[i].r == ba[i].r) {           // 마린의 위치도 서로 같다면 있을 수 있는 위치가 무한대
                std::cout << -1 << std::endl;
            } else if (jo[i].r != ba[i].r) {     // r이 다르다면 류재명이 존재할 수 없다.
                std::cout << 0 << std::endl;
            }
        } else {
            
            if (dist > jo[i].r + ba[i].r) {     // 서로의 거리가 두 터렛에 류재명 거리의 합보다 크면 존재할 수 없음
                std::cout << 0 << std::endl;
            } else if (dist == jo[i].r + ba[i].r) {     // 한점에서 만날 때
                std::cout << 1 << std::endl;
            } else if (dist + std::min(jo[i].r, ba[i].r) < std::max(jo[i].r, ba[i].r)) {    // 한 원이 다른 원 안에 있을 경우
                std::cout << 0 << std::endl;
            } else if (dist == std::abs(jo[i].r - ba[i].r)) {   // 한 원이 다른 원 안쪽에 있고, 내접할 때
                std::cout << 1 << std::endl;
            } else {                                            // 겹치는 경우
                std::cout << 2 << std::endl;
            }
        }
            
    }

    delete[] jo;
    delete[] ba;
    return 0;
}
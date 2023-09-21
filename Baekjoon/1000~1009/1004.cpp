/*
    빨간 실선은 어린 왕자가 출발점에서 도착점까지 도달하는데 있어서 필요한 행성계 진입/이탈 횟수를 최소화하는 경로이며, 원은 행성계의 경계를 의미한다. 이러한 경로는 여러 개 존재할 수 있지만 적어도 3번의 행성계 진입/이탈이 필요하다는 것을 알 수 있다.

    위와 같은 은하수 지도, 출발점, 도착점이 주어졌을 때 어린 왕자에게 필요한 최소의 행성계 진입/이탈 횟수를 구하는 프로그램을 작성해 보자. 행성계의 경계가 맞닿거나 서로 교차하는 경우는 없다. 또한, 출발점이나 도착점이 행성계 경계에 걸쳐진 경우 역시 입력으로 주어지지 않는
*/

#include <iostream>
#include <string>
#include <sstream>

struct Planet
{
    int x;
    int y;
    int r;
};

struct Point
{
    int x;
    int y;
};

class Milky_Way {
    private:
        int planet_count = 0;
        Planet *planet = nullptr;
        Point goal;
        Point start;
    public:
        void solve();
        void set_planet_count(int n);
        void set_planet(std::string nums);
        void set_point(std::string nums);
        void show();
        ~Milky_Way();
};

void Milky_Way::solve() {

}

void Milky_Way::set_planet_count(int n) {
    planet = new Planet[n];
    planet_count = n;
}


void Milky_Way::set_planet(std::string nums) {
    for 
}

void Milky_Way::set_point(std::string nums) {

    std::istringstream iss(nums);
    iss >> start.x >> start.y >> goal.x >> goal.y;
}

void Milky_Way::show() {
    using std::cout;

    cout << start.x << " " << start.y << std::endl;
    cout << goal.x << " " << goal.y << std::endl;
}

Milky_Way::~Milky_Way() {
    if (planet) {
        delete[] planet;
    }
}

int main() {

    int case_num;
    int planet_count;
    std::string input;
    Milky_Way *milky_way;

    std::cin >> case_num;
    std::cin.ignore();

    milky_way = new Milky_Way[case_num];

    for (int i = 0; i < case_num; i++) {
        getline(std::cin, input);
        milky_way[i].set_point(input);

        std::cin >> planet_count;
        std::cin.ignore();

        milky_way[i].set_planet_count(planet_count);

        for (int i = 0; i < planet_count; i++) {
            getline(std::cin, input);
            milky_way[i].set_planet(input);
        }
    }
    delete[] milky_way;
    return 0;
}
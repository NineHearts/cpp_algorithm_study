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
    int r = -1;
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
        void init();
        void show() const;
        void set_planet_count(int n);
        void set_planet(std::string nums);
        void set_point(std::string nums);
        ~Milky_Way();
};

void Milky_Way::solve() {
    for (int i = 0; i < planet_count; ++i) {
        planet[i];
    }
}

void Milky_Way::init() {
    std::string input;
    getline(std::cin, input);
    set_point(input);

    std::cin >> planet_count;
    std::cin.ignore();

    set_planet_count(planet_count);

    for (int j = 0; j < planet_count; j++) {
        getline(std::cin, input);
        set_planet(input);
    }
}

void Milky_Way::set_planet_count(int n) {
    planet = new Planet[n];
    planet_count = n;
}


void Milky_Way::set_planet(std::string nums) {
    for (int i = 0; i < planet_count; ++i) {
        if (planet[i].r == -1) {
            std::istringstream iss(nums);
            iss >> planet[i].x >> planet[i].y >> planet[i].r;
            break;
        }
    }
}

void Milky_Way::set_point(std::string nums) {

    std::istringstream iss(nums);
    iss >> start.x >> start.y >> goal.x >> goal.y;
}

void Milky_Way::show() const{
    using std::cout;

    cout << "----------start point----------\n"; 
    cout << start.x << " " << start.y << std::endl;
    cout << goal.x << " " << goal.y << std::endl;

    cout << "----------planets----------\n";
    for (int i = 0; i < planet_count; ++i) {
        cout << planet[i].x << " " << planet[i].y << " " << planet[i].r << std::endl;
    }
}

Milky_Way::~Milky_Way() {
    if (planet) {
        delete[] planet;
    }
}

int main() {

    int case_num;
    int planet_count;
    
    Milky_Way *milky_ways;

    std::cin >> case_num;
    std::cin.ignore();

    milky_ways = new Milky_Way[case_num];

    for (int i = 0; i < case_num; i++) {
        milky_ways[i].init();
        milky_ways[i].show();
    }

    delete[] milky_ways;
    return 0;
}
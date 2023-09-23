/*
    빨간 실선은 어린 왕자가 출발점에서 도착점까지 도달하는데 있어서 필요한 행성계 진입/이탈 횟수를 최소화하는 경로이며, 원은 행성계의 경계를 의미한다. 이러한 경로는 여러 개 존재할 수 있지만 적어도 3번의 행성계 진입/이탈이 필요하다는 것을 알 수 있다.

    위와 같은 은하수 지도, 출발점, 도착점이 주어졌을 때 어린 왕자에게 필요한 최소의 행성계 진입/이탈 횟수를 구하는 프로그램을 작성해 보자. 행성계의 경계가 맞닿거나 서로 교차하는 경우는 없다. 또한, 출발점이나 도착점이 행성계 경계에 걸쳐진 경우 역시 입력으로 주어지지 않는
*/

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

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
        double distance(Planet &p1, Point& p2);
        ~Milky_Way();
};

double Milky_Way::distance(Planet &p1, Point& p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

void Milky_Way::solve() {
    int count = 0;
    for (int i = 0; i < planet_count; ++i) {
        bool s = planet[i].r > distance(planet[i], start);
        bool g = planet[i].r > distance(planet[i], goal);
        if (s != g)
            count += 1;
    }
    std::cout << count << std::endl;
}

void Milky_Way::init() {
    using std::cin;

    // set points
    cin >> start.x >> start.y >> goal.x >> goal.y;

    std::cin >> planet_count;
    std::cin.ignore();

    set_planet_count(planet_count);

    for (int j = 0; j < planet_count; j++) {
        for (int i = 0; i < planet_count; ++i) {
            if (planet[i].r == -1) {
                cin >> planet[i].x >> planet[i].y >> planet[i].r;
                break;
            }
    }
    }
}

void Milky_Way::set_planet_count(int n) {
    planet = new Planet[n];
    planet_count = n;
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
    cout << "----------end of milky way----------" << std::endl;;
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
    }

    for (int i = 0; i < case_num; i++) {
        milky_ways[i].solve();
    }

    delete[] milky_ways;
    return 0;
}
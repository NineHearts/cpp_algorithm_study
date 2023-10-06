/*
서기 2012년! 드디어 2년간 수많은 국민들을 기다리게 한 게임 ACM Craft (Association of Construction Manager Craft)가 발매되었다.

이 게임은 지금까지 나온 게임들과는 다르게 ACM크래프트는 다이나믹한 게임 진행을 위해 건물을 짓는 순서가 정해져 있지 않다. 즉, 첫 번째 게임과 두 번째 게임이 건물을 짓는 순서가 다를 수도 있다. 매 게임시작 시 건물을 짓는 순서가 주어진다. 또한 모든 건물은 각각 건설을 시작하여 완성이 될 때까지 Delay가 존재한다.

이번 게임에서는 다음과 같이 건설 순서 규칙이 주어졌다. 1번 건물의 건설이 완료된다면 2번과 3번의 건설을 시작할수 있다. (동시에 진행이 가능하다) 그리고 4번 건물을 짓기 위해서는 2번과 3번 건물이 모두 건설 완료되어야지만 4번건물의 건설을 시작할수 있다.

따라서 4번건물의 건설을 완료하기 위해서는 우선 처음 1번 건물을 건설하는데 10초가 소요된다. 그리고 2번 건물과 3번 건물을 동시에 건설하기 시작하면 2번은 1초뒤에 건설이 완료되지만 아직 3번 건물이 완료되지 않았으므로 4번 건물을 건설할 수 없다. 3번 건물이 완성되고 나면 그때 4번 건물을 지을수 있으므로 4번 건물이 완성되기까지는 총 120초가 소요된다.

프로게이머 최백준은 애인과의 데이트 비용을 마련하기 위해 서강대학교배 ACM크래프트 대회에 참가했다! 최백준은 화려한 컨트롤 실력을 가지고 있기 때문에 모든 경기에서 특정 건물만 짓는다면 무조건 게임에서 이길 수 있다. 그러나 매 게임마다 특정건물을 짓기 위한 순서가 달라지므로 최백준은 좌절하고 있었다. 백준이를 위해 특정건물을 가장 빨리 지을 때까지 걸리는 최소시간을 알아내는 프로그램을 작성해주자.
*/


// 들어오는 값
// 케이스 갯수
// 건물의 갯수와 건물순서 규칙의 갯수
// 각 건설에 걸리는 시간
// 최종 목표 건물


#include <iostream>

// 건물의 데이터 및 함수들을 저장할 클래스
class ACM
{
    private:
        int *rule = nullptr;
        int *building = nullptr;
        
    public:
        void set_building_count(int count);
        void set_building(int index, int time);
        ~ACM();
};

void ACM::set_building_count(int count)
{
    building = new int[count];
}

void ACM::set_building(int index, int build_time)
{
    building[index] = build_time;
}

ACM::~ACM()
{
    if (rule != nullptr)
    {
        delete[] rule;
    }
    if (building != nullptr)
    {
        delete[] building;
    }
}

int main()
{
    int case_num;
    int order_count, buliding_count;
    int time;

    ACM *acm;

    // 첫번째 줄에는 테스트 케이스의 갯수 case_num
    std::cin >> case_num;
    acm = new ACM[case_num];

    for (int i = 0; i < case_num; ++i)
    {
        // 
        std::cin >> buliding_count >> order_count;
        acm[i].set_building_count(buliding_count);

        for (int j = 0; j < buliding_count; ++j)
        {
            std::cin >> time;
            acm[i].set_building(j, time);
            
        }

        for (int j = 0; j < order_count; ++order_count)
        {
            std::cin >> acm.
        }
    }

    delete[] acm;
    return 0;
}
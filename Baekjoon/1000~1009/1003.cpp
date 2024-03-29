// fibonacci(3)을 호출하면 다음과 같은 일이 일어난다.

//     fibonacci(3)은 fibonacci(2)와 fibonacci(1) (첫 번째 호출)을 호출한다.
//     fibonacci(2)는 fibonacci(1) (두 번째 호출)과 fibonacci(0)을 호출한다.
//     두 번째 호출한 fibonacci(1)은 1을 출력하고 1을 리턴한다.
//     fibonacci(0)은 0을 출력하고, 0을 리턴한다.
//     fibonacci(2)는 fibonacci(1)과 fibonacci(0)의 결과를 얻고, 1을 리턴한다.
//     첫 번째 호출한 fibonacci(1)은 1을 출력하고, 1을 리턴한다.
//     fibonacci(3)은 fibonacci(2)와 fibonacci(1)의 결과를 얻고, 2를 리턴한다.

// 1은 2번 출력되고, 0은 1번 출력된다. N이 주어졌을 때, 
// fibonacci(N)을 호출했을 때, 0과 1이 각각 몇 번 출력되는지 구하는 프로그램을 작성하시오.

// int fibonacci(int n) {
//     if (n == 0) {
//         printf("0");
//         return 0;
//     } else if (n == 1) {
//         printf("1");
//         return 1;
//     } else {
//         return fibonacci(n - 1) + fibonacci(n - 2);
//     }
// }


// 피보나치 함수를 재귀 호출하여
// 0을 출력하는 횟수는 fibonacci(0)과 fibonacci(1)일때를 제외하고는
// 결과적으로 피보나치 수열의 n-2번째 수와 같고,
// 1을 출력하는 횟수는 피보나치 수열의 n-1번째 수와 같으므로
// fibonacci(0), fibonacci(1)일때는 각각 정해진 수를,
// 나머지는 피보나치 수열의 값을 계산해 반환한다.

#include <iostream>

int fibonacci(int n, int num);  // num은 0이 호출되는 횟수인지 1이 호출되는 횟수인지 구분
void get_count(int n);          // 숫자를 넣으면 0, 1일때를 제외하고 피보나치 함수를 호출해서 값 print

int main() {

    using std::cin;

    int n;
    int *num;
    
    cin >> n;
    cin.ignore();

    num = new int[n];

    for (int i = 0; i < n; ++i){
        cin >> num[i];
        cin.ignore();
    }

    for (int i = 0; i < n; ++i){
        get_count(num[i]);
    }

    delete[] num;
    return 0;
}

void get_count(int n) {
    
    using std::cout;
    int zero;
    int one;

    if (n == 0) {
        zero = 1;
        one = 0;
    }else if (n == 1) {
        zero = 0;
        one = 1;
    }else {
        zero = fibonacci(n, 0);
        one = fibonacci(n, 1);
    }
    
    cout << zero << " " << one << std::endl;
}

// 피보나치 수열을 구하는 함수
int fibonacci(int n, int num) {

    int sum = 1;
    int pre_1 = 0;
    int pre_2 = 0;
    int i = num != 0 ? 1 : 2;       // 0이 출력되는 갯수를 구하는지 1이 출력되는 갯수인지에 따라 i의 값을 변경
    for (; i < n; ++i) {
        pre_1 = sum;
        sum += pre_2;
        pre_2 = pre_1;
    }
    return sum;
}
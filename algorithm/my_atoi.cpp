#include <iostream>
#include <limits.h>

using namespace std;

enum status{
    valid = 0,
    invalid = 1
};

status atoiStatus = valid;
int my_atoi(const char* str)
{
    if(str == NULL){
        atoiStatus = invalid;
        return 0;
    }

    int ans = 0, tmp = 0;
    int i = 0, sign = 1;

    while(isspace(str[i])){
        ++i;
    }

    if(str[i] == '-'){
        ++i;
        sign = -1;
    }
    else if(str[i] == '+')
        ++i;
    else if(str[i] > '9' || str[i] < '0'){
        atoiStatus = invalid;
        return 0;
    }

    while(str[i] <= '9' && str[i] >= '0'){
        tmp = str[i] - '0';
        if(sign > 0 && (ans > INT_MAX/10 || (ans == INT_MAX/10 && tmp > INT_MAX%10))){
            return INT_MAX;
        }
        else if(sign <0 && (ans > (unsigned)INT_MIN/10 || (ans == (unsigned)INT_MIN/10 && tmp > (unsigned)INT_MIN%10))){
            return INT_MIN;
        }
        ans = ans*10 + tmp;
        ++i;
    }

    return sign*ans;
}

int main()
{
    const char* s = "    a122222222";
    cout << my_atoi(s) << endl;
    cout << atoiStatus << endl;
    return 0;
}
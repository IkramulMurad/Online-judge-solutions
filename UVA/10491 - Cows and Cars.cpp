#include <iostream>
#include <cstdio>
using namespace std;

double calculate(int cows, int cars, int shows){
    int total = cows + cars;
    int switchOption = total - shows - 1;

    //probability of getting car while switching
    //p(cow)*carOption/switchOption + p(car)*carOption/switchOption
    double pcow = double(cows)/total, pcar = double(cars)/total;
    double ans = pcow*cars/switchOption + pcar*(cars - 1)/switchOption;

    return ans;
}

int main()
{
    int cows, cars, shows;
    while(cin >> cows >> cars >> shows){
        printf("%.5f\n", calculate(cows, cars, shows));
    }

    return 0;
}

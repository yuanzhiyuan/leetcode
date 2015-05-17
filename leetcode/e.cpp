#include <iostream>
#include <iomanip>
using namespace std;


class Solution{
public:

double mu;
double zi;
double x;
Solution():mu(1),zi(1){}
double get_fenmu(int i){
mu = mu*i;
return mu;
}
double get_fenzi(){
zi = zi*x;
return zi;

}
double cal(double a){
double sum=1;
x = a;
for(int i=1;i<10000;i++){
sum+=get_fenzi()/get_fenmu(i);

}
return sum;
}


};

int main(){

Solution s;
cout <<setprecision(7)<<s.cal(1) <<endl;

return 0;
}

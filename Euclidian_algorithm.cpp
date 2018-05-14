#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    int a,n,n_1,a_1,tmp,rem_1=1,rem_2=-1,row=0;
    cin>>a>>n;
    if (a<n){
        tmp=a;
        a=n;
        n=tmp;}
    n_1=n;
    a_1=a;
    if ((a==0)||(a==1)||(n==0)||(n==1)||(a==n)){
            cout<<"This isn't how it works, and you know that!";
            return 1;
    }
    vector<int> Mult;
    while (true)
    {
        Mult.push_back(n/a);

        tmp=n%a;
        n=a;
        a=tmp;

        if (a==1||a==0)
            break;
    }
    if (a==0){
        n_1=n_1/n;
        a_1=a_1/n;
    Mult.pop_back();
    }
    if (Mult.size()%2==1)
        row=1;
//    for(int i=0;i<Mult.size();++i)
//        cout<<Mult[i];
    rem_2=rem_2*Mult[Mult.size()-1];
    Mult.pop_back();
    if (Mult.size()>=1)
    while (true)
    {
        rem_1=(rem_1-rem_2*Mult[Mult.size()-1]);
        Mult.pop_back();
        if (Mult.size()==0)
            break;
        rem_2=(rem_2-rem_1*Mult[Mult.size()-1]);
        Mult.pop_back();
        if (Mult.size()==0)
            break;
    }
    if (row==1){
        tmp=rem_1;
        rem_1=rem_2;
        rem_2=tmp;
    }
    if (rem_1<0)
        while(rem_1<0)
        rem_1=rem_1+n_1;
    if (rem_2<0)
        while(rem_2<0)
        rem_2=rem_2+a_1;
    rem_1=rem_1%n_1;
    rem_2=rem_2%a_1;
    if (a==0){
    cout<<a_1*n<<"*"<<rem_1<<"="<<n<<" mod "<<n_1*n<<endl;
    cout<<n_1*n<<"*"<<rem_2<<"="<<n<<" mod "<<a_1*n<<endl;
    }
    else{
    cout<<a_1<<"*"<<rem_1<<"=1 mod "<<n_1<<endl;
    cout<<n_1<<"*"<<rem_2<<"=1 mod "<<a_1<<endl;
    }
    return 0;
}

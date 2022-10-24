#include <bits/stdc++.h>
using namespace std;

#define input
//#define showtemp
#define Vpush

vector<int>V;
int p=0;//全域變數p 讀取V內的數字
unsigned long long sum=0;// 答案可能超過2^31次 


int dfssum(){ //遞迴深度優先
    int a = V[p], b; //a,b判斷節點
    p++;
    if(a==0) return 0;//a節點為0 到最深的地方了
    for(int i=0;i<2+(a%2);i++){// 奇數=>分3節點,偶數=>分2節點
        b = dfssum();
        if(b!=0) sum+=abs(a-b);//b不為0時 計算相連兩節點絕對值 
    }
    return a;//最深節點
}

const vector<string> split(const string &str, const char &delimiter) { //字串切割讀取
    vector<string> result;
    stringstream ss(str);
    string tok;

    while (getline(ss, tok, delimiter)) {
        result.push_back(tok);
    }
    return result;
}


int main(){
    #ifdef input
    string st;
    cin>>st;
    //cout<<st<<endl<<endl;
    vector<string>TEMP=split(st,' ');
    #endif

    #ifdef showtemp
    for(auto &i:TEMP){
        cout<<i<<',';
    }
    #endif

    #ifdef Vpush
    for(auto &i:TEMP){
        int n = stoi(i);//資料型態轉換
        V.push_back(n);//放入全域V vector
    }
    #endif

    //V={2,6,0,8,14,0,0,0,10,0,4,0,0};

    dfssum();
    cout << sum << endl;
    return 0;

    
}

#include <bits/stdc++.h>
using namespace std;

#define input
//#define showtemp
#define Vpush

vector<int>V;
int p=0;//全域變數p 讀取V內的數字
unsigned long long sum=0;// 答案可能超過2^31次 


int dfssum(){ //遞迴深度優先
    int a=V[p],b; //a,b判斷節點
    p++;
    if(a==0) return 0;//a節點為0 到最深的地方了
    for(int i=0;i<2+(a%2);i++){// 奇數=>分3節點,偶數=>分2節點
        b=dfssum();
        if(b!=0) sum+=abs(a-b);//b不為0時 計算相連兩節點絕對值 
    }
    return a;//下一節點
}

const vector<string> split(const string &str, const char &delimiter) { //字串切割讀取
    vector<string> result;
    stringstream ss(str);
    string tok;

    while(getline(ss,tok,delimiter)) {
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
        int n=stoi(i);//資料型態轉換
        V.push_back(n);//放入全域V vector
    }
    #endif

    //V={2,6,0,8,14,0,0,0,10,0,4,0,0};

    dfssum();
    cout<<sum<<endl;
    return 0;

    
}


/*
===========================================================================================================
內容

有一組探險隊要去一個樹狀結構的石窟內探險，該石窟內有n個石室，第i個石室有一個編號ai，
若ai為偶數則會有2條分支(左分支和右分支)，若ai為奇數則有3條分支(左分支、中分支和右分支)。
探險隊想要紀錄這個石窟的結構，每次只要第一次走到一個新的石室，就會將該石室的編號記錄在紙上，
並由左到右依序走訪該石室的分支們，若走到一條死路則會在紙上紀錄一個數字0，
若該石室已經走完所有分支則退回到上一個石室，走訪完整個石窟後在紙上得到上一個數字序列。
探險隊回到基地後忘記計算了這個石窟內所有相鄰的石室編號相差取絕對值的總和，請幫助探險隊從紙上的序列推算出該數值。
===========================================================================================================
輸入說明

輸入一個整數個數不超過10^6的整數序列，石室的編號不超過10^5，並保證造出來的樹深度不超過40。
子題配分
(20%): 石室數量最多不超過20個，編號均為偶數
(20%): 石室數量最多不超過1000個
(60%): 石室最大深度不超過40層，編號和石室編號不超過100000，答案可能會超過2^31。 
===========================================================================================================
輸出說明

輸出一個整數代表這個石窟內所有相鄰的石室編號相差取絕對值的總和，
答案大小有可能會超過2^31。
===========================================================================================================
*/

/*
===========================================================================================================
Sample Input                                            Sample Output

2 6 0 8 14 0 0 0 10 0 4 0 0                             26

5 2 10 0 0 0 8 0 0 17 0 0 0                             26

*/

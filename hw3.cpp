//laimolee
#include<iostream>
#include<vector>
#include<sstream>
#include<string>
using namespace std;
int parenthe[35][2];
int numbera[35], numtime=0, sum=1;
char opa[35], optime=0;
vector<int>cal;     //to calculate

int main(){
    stringstream ss;
    string s;
    int a, last=0;
    char b;
    cin >> s; 
    ss << s;
    ss >> numbera[numtime++];
    cal.push_back(numbera[numtime-1]);

    for(int i=0;i<35;i++){  //reset
        parenthe[i][0] = 0;
        parenthe[i][1] = 0;
    }
    while(ss >> opa[optime++]){     //separate number and operator
        ss >> numbera[numtime++];
        cal.push_back(numbera[numtime-1]);
    }

    for(int i=0;i<optime;i++){
        char h = opa[i];
        last =i;
        if(h == '+'){
            cal.at(i+1) += cal.at(i);   //do calculate
            cal.at(i) = 1;
            if(i!=0){
                while(last > 0 && opa[last-1] != '*'){
                    last--;
                }
            }
            parenthe[last][0] += 1;
            parenthe[i+1][1]  += 1;
        }
    }
    for(int i=0;i<numtime-1;i++){
        sum *= cal[i];
        for(int j=0;j<parenthe[i][0];j++)
            cout << '(';
        cout <<numbera[i];
        for(int j=0;j<parenthe[i][1];j++)
            cout << ')';
        cout << opa[i];
    }                               // the last number and sum's output
    sum *= cal[numtime-1];
    cout << numbera[numtime-1];
    for(int i=0;i<parenthe[numtime-1][1];i++)
        cout << ')';
    cout << '=' << sum << endl;
    return 0;
}

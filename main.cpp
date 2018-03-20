#include <bits/stdc++.h>
using namespace std;
string s;

int getST(string st){
s=st;
string stepen;
int numeric=0, it=1;
for(int i=0; i<(int)s.length(); i++){
    if(s[i]=='^'){
        int j=i+1;
        while((s[j]=='0') || (s[j]=='1') || (s[j]=='2') || (s[j]=='3') || (s[j]=='4') || (s[j]=='5') || (s[j]=='6') || (s[j]=='7') || (s[j]=='8') || (s[j]=='9')){
            stepen[j]=s[j];
            s[j]='@';
            j++;
        }
        for(int k=j-1; k>=i+1; k--){
            numeric=numeric+(((int)stepen[k]-48)*it);
            it=it*10;
        }
    }
}
//numeric=numeric/10;
return numeric;
}

int koef(){
int number=0, it2=1;
for(int j=(int)s.length()-1; j>=0; j--){
    if((s[j]=='0') || (s[j]=='1') || (s[j]=='2') || (s[j]=='3') || (s[j]=='4') || (s[j]=='5') || (s[j]=='6') || (s[j]=='7') || (s[j]=='8') || (s[j]=='9')){
            number=number+(((int)s[j]-48)*it2);
            it2=it2*10;
    }
}
return number;
}

int main()
{
stringstream ss1, ss2;
string c, res1, res2, resE;
getline(cin, c);
int upper=0, lowered=0, backu=0;
upper=getST(c);
//cout << "upper=" << upper << endl;
lowered=koef();
if(c[0]=='x'){lowered=1;}
backu=lowered;
//cout << "lowered=" << lowered << endl;
lowered=lowered*upper;
if(lowered==0){lowered=backu;}
ss1<<lowered;
ss1>>res1;
ss2<<upper-1;
ss2>>res2;
//cout << "res1=" << res1 << endl;
//cout << "res2=" << res2 << endl;
if(lowered != 1 && upper > 1){
resE=res1 + "x^" + res2;
}
if(lowered == 1 && upper > 1){
resE="x^" + res2;
}
if(lowered != 1 && upper == 1){
resE=res1 + "x";
}
if(lowered != 1 && upper == 0){
resE=res1;
}
cout << resE;
}

#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <math.h>
using namespace std;

vector<int> p8{6,3,7,4,8,5,10,9};
vector<int> p10{3,5,2,7,4,10,1,9,8,6};
vector<int> p4{2,4,3,1};
vector<int> IP{2,6,3,1,4,8,5,7};
vector<int> EP{4,1,2,3,2,3,4,1};
vector<int> IPI{4,1,3,5,7,2,8,6};
int S0[4][4]={1,0,3,2,3,2,1,0,0,2,1,3,3,1,3,2};
int S1[4][4]={0,1,2,3,2,0,1,3,3,0,1,0,2,1,0,3};

class SDES{
    public:
        string k1, k2, cipher, decrypted;
        string permutations(string inp, vector<int> p);
        string left_shift(string input, int n);
        string sbox(string input);
        string encrypt(string input, string key);
};

string SDES::permutations(string inp, vector<int> p){
    string temp;
    for(int i=0; i<p.size(); i++){
        temp += inp[p[i]-1];
    }
    temp += '\0';
    return temp;
}
string SDES::left_shift(string input, int n){
    int i, count=0;
    while(count<n){
    int c1 = input[0];
    for(i=0; i<5; i++){
        (i==4) ? input[i] = c1 : input[i] = input[i+1];
    }
    int c2 = input[5];
    for(i=5;i<10;i++){
        (i==9) ? input[i] = c2 : input[i] = input[i+1];
        }
    count++;
    }
    return input;
}
string SDES::sbox(string input){
    int lr, lc, rr, rc;
    string bits[]={"00","01","10","11"};
    string r1 = input.substr(0,1)+input.substr(3,1), c1 = input.substr(1,1)+input.substr(2,1);
    string r2 = input.substr(4,1)+input.substr(7,1), c2 = input.substr(5,1)+input.substr(6,1);
    for(int i=0;i<4;i++){
        if(r1 == bits[i])
            lr=i;
        if(c1 == bits[i])
            lc=i;
        if(r2 == bits[i])
            rr=i;
        if(c2 == bits[i])
            rc=i;
        }
    return bits[S0[lr][lc]]+bits[S1[rr][rc]];
}
string SDES::encrypt(string input, string key){

    string r = permutations(input.substr(4,4), EP);
    int i, temp1[8], temp2[4];
    string out, left;
    //F(R,K)
        for(i=0; i<8; i++){
            temp1[i] = r[i] ^ key[i]; 
            out += to_string(temp1[i]); 
    }
    string f_rk = permutations(sbox(out), p4);
    //Fk(L,R)
    string l = input.substr(0,4);
    for(i=0; i<4; i++){
        temp2[i] = l[i] ^ f_rk[i];
        left += to_string(temp2[i]);
    }
    string right = input.substr(4,4);
    return right+left;
}

int main(){
    string key, plain;
    SDES s;
    cout<<"Enter the 10bit key:";
    cin>>key;
    //keys generation
    s.k1 = s.permutations(s.left_shift(s.permutations(key, p10), 1), p8);
    cout<<"key1:\t"<<s.k1<<"\n";
    s.k2 = s.permutations(s.left_shift(s.left_shift(s.permutations(key, p10), 2), 1), p8);
    cout<<"key2:\t"<<s.k2;
    //encryption
    cout<<'\n'<<"Enter the input to be encrypted:";
    cin>>plain;
    string round1 = s.encrypt(s.permutations(plain, IP), s.k1);
    cout<<"after 1st round of encryption:\t"<<round1<<'\n';
    string round2 = s.encrypt(round1, s.k2);
    s.cipher = s.permutations((round2.substr(4,4)+round2.substr(0,4)), IPI);
    cout<<"ciphertext:"<<s.cipher<<'\n';
    //decryption
    string r1 = s.encrypt(s.permutations(s.cipher, IP), s.k2);
    string r2 = s.encrypt(r1, s.k1);
    s.decrypted = s.permutations((r2.substr(4,4)+r2.substr(0,4)), IPI);
    cout<<"After decryption:"<<s.decrypted;
}
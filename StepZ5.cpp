#include <iostream>
#include <string>
using namespace std;

struct Node{
    char smb;
    int num;
    bool acc;
    Node* go[2];
    Node():go{nullptr, nullptr}{
        smb = '\0';
        num = 0;
        acc = false;
    }
};

int main(){
    int n;
    cin >> n;
    Node* root = new Node();
    for(int i = 1; i <= n; i++){
        char c;
        string str;
        cin >> c >> str;
        auto p = str.begin();
        Node* cur = root;
        while(true){
            int dig = *p - '0';
            if(cur->go[dig] == nullptr)
                break;
            cur = cur->go[dig];
            p++;
            if(cur->acc){
                cout << "NO " << cur->num << '\n';
                return 0;
            }
            if(p == str.end()){
                cout << "NO " << i << '\n';
                return 0;
            }
            
        }
        while(p < str.end()){
            int dig = *p - '0';
            cur->go[dig] = new Node();
            cur = cur->go[dig];
            p++;
        }
        cur->acc = true;
        cur->num = i;
        cur->smb = c;
    }
    string str;
    cin >> str;
    string res = "";
    auto p = str.begin();
    while(p < str.end()){
        //int dig = *p - '0';
        Node* cur = root;
        while(!cur->acc && p < str.end()){
            int dig = *p - '0';
            cur = cur->go[dig];
            p++;
        }
        res += cur->smb;
    }
    cout << res << '\n';

}
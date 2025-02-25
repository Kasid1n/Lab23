#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string x,vector<string> &name,vector<int> &score,vector<char> &grad){
    ifstream stu(x);
    string s;
    char grade,nam[100];
    int a,b,c;
    while(getline(stu,s)){
        sscanf(s.c_str(),"%[^:]: %d %d %d",nam,&a,&b,&c);
        name.push_back(nam);
        
        grade=score2grade(a+b+c);
        score.push_back(a+b+c);
        grad.push_back(grade);
        
    }
    

}

void getCommand(string &command, string &key){
    string temp;
    char format[] = "%s %[^:]s";
    char text1[10], text2[100];
    cout << "Please input your command: \n";
    getline(cin, temp);
    sscanf(temp.c_str(), format, &text1, &text2);
    command = text1;
    key = text2;
}

void searchName(vector<string> name,vector<int> scr,vector<char> grad, string k){
    int i = 0;
    int j = 0;
    string key=toUpperStr(k);
    int s=name.size();
    while(i<s){
        if(key==toUpperStr(name[i])){
            cout<<"---------------------------------\n";
            cout<<name[i]<<"'s score = "<<scr[i]<<endl;
            cout<<name[i]<<"'s grade = "<<grad[i]<<endl;
            cout<<"---------------------------------\n";
            j=1;
        
            
        }
        i++;
    }
    if (i==s&&j==0){
        cout<<"---------------------------------\n";
        cout<<"Cannot found.\n";
        cout<<"---------------------------------\n";
    }
}
void searchGrade(vector<string> name,vector<int> scr,vector<char> grad, string k){
    int i = 0;
    int j = 0;
    char key=toupper(k[0]);
    int s=name.size();
    cout<<"---------------------------------\n";
    while(i<s){
        if(key==grad[i]){
            cout<<name[i]<<" ("<<scr[i]<<")"<<endl;
            j++;
        }
        
        i++;
    }
    if (i>=s&&j==0){
    cout<<"Cannot found.\n";
    }
    cout<<"---------------------------------\n";
}


int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <ctime>
#include <time.h>

using namespace std;

//vector<string> vars;
vector<string> base;
vector<string> ABC;


int good=0;

bool isGoodChar(char c){
    for(int i=0;i<ABC.size();i++){
        if(c==ABC.at(i)[0]){
            return true;

        }
    }
    return false;
}

void loadABC(){
    ifstream fABC("abc.txt");
    string line;
    while(std::getline(fABC,line)){
        ABC.push_back(line);
        cout<<line<<endl;
    }
    fABC.close();
}

void showPercent(int all,int index){
    
    int done=100*index/all;
    cout<<"Done : "<<done<<endl;

}

void writeInFile(string name,string data){
    //ofstream out("/results/test.txt")
    ofstream fout("results/"+data.substr(0,2)+".txt",ios_base::app | ios_base::out );
    if(fout.is_open()){
   
        cout<<data<<endl;
        fout<<data<<endl;
    }else{
        cout<<"error file "<<name<<".txt"<<endl;
    }
    //out<<data<<endl;
    fout.close();
}

int main(int argc, char** argv) {
    
    loadABC();
    //ifstream file("variants.txt");
    ifstream fbase("base.txt");
    string line;
    
    int index=0;
    while(std::getline(fbase,line)){
        string oneMail="";
        oneMail+=line;
        char *start="";
        char c1=oneMail[0];
        char c2=oneMail[1];
        if(isGoodChar(c1) && isGoodChar(c2)){
            good++;
            string name=""+c1+c2;
            //writeInFile(name,line);
            //showPercent(1252669,index);
            //std::clock_t start1;
            //start1=std::clock();
           
            
            cout<<"Start time: "<<time(0)<<endl;
        }else{
            //writeInFile("trash",line);
        }
        
        index++;
    }
    cout<<"All: "<<index<<endl;
    cout<<"Good: "<<good<<endl;
    cout<<"Bad: "<<index-good<<endl;
    string s ="rgrgr rgrgg qwdeq wqe";
   
    return 0;
}


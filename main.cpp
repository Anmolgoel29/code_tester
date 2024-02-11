#include<bits/stdc++.h>
using namespace std;

vector<string> dat;
int state=0;

void comp(const string& filename , const string& path){
    string cmd = "cd \"" + path + "\" && g++ "+ filename+ " -o obj.exe";
    system(cmd.c_str());
}

void exec(const string& filename , const string& path){
    string cmd = "cd \"C:\\Users\\Anmol Goel\\Desktop\\Tech\\code_tester\\cmake-build-debug\" && exec.bat " + filename+ " \"" + path + " \"";
    system(cmd.c_str());
}

void fetch_data(const string& filename , const string& path ){

    ifstream file;
    string pat = path+"\\"+filename;
    file.open(pat.c_str() , ios::in);

    if(!file) cerr<<"error opening file"<<endl;

    file.seekg(0,ios::beg);
    string line;

    int cnt=0;

    while(getline(file,line)){
        if(!line.empty()) {
            if(dat.size() <= cnt)
                dat.push_back(line);
            else
                dat[cnt] += '\n'+line;
        }
        else {
            cnt++;
        }
    }

}

void print(const string& expec_out, const string& n ){
    string expec="none";
    if(state){
        ifstream file;
        file.open(expec_out,ios::in);
        string line;
        while(getline(file,line)){
            line+='\n'+line;
        }

        expec=line;
    }

    ifstream file1;
    file1.open("C:\\Users\\Anmol Goel\\Desktop\\Tech\\code_tester\\cmake-build-debug\\buff_out.txt" , ios::in);

    if(!file1)cerr<<"error opening file1"<<endl;

    string line,res;
    file1.seekg(0,ios::beg);

    while(getline(file1,line)){
        res+='\n'+line;
    }

    cout << n << endl << res << endl << expec <<endl<<endl;
    file1.close();
}

void run(const string& filename , const string& path , const string& expec_out="" ){
    for(const auto &x:dat){
        ofstream file;
        file.open("cmake-build-debug\buff_in.txt" , ios::out | ios::trunc);
        file<<x;
        file.close();
        exec(filename,path);
        print(expec_out , x);
    }
}

vector<string> menu(){
    cout<<"Welcome to the cpp code-runner"<<endl;

    string line;
    vector<string> in;

    cout<<"Enter the Filename of program to execute"<<endl;
    getline(cin,line);
    in.push_back(line);

    cout<<"Enter the path of the program to execute (without the filename)"<<endl;
    getline(cin,line);
    in.push_back(line);

    cout<<"Enter the filename of the testcases file"<<endl;
    getline(cin,line);
    in.push_back(line);

    cout<<"Enter the path of the testcases file (without filename)"<<endl;
    getline(cin,line);
    in.push_back(line);


    cout<<"Do you want to compare with expected output(y/n)"<<endl;
    getline(cin,line);

    if(line=="y"){
        state=1;
        cout<<"Enter the path of the expected output(with filename)"<<endl;
        getline(cin,line);
        in.push_back(line);
    }

    return in;

}

// todo add an option to print in terminal and always print in file.

int main(){
    //todo add interface to specify delim in separating the testcases
    //todo remove the filename argument in the exec.bat file

    vector<string>in;
    system("cd");

    in=menu();
    fetch_data(in[2] , in[3]);
    comp(in[0] , in[1]);
    run(in[0] , in[1] , in[4]);

}
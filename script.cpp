#include <iostream>
#include <vector>
#include <string>

#define year 1
#define sub 3
#define day 2
#define pb push_back

using namespace std;
void input(vector<vector<vector<vector<string>>>>& data){
    for(int i=0; i<year; i++){
        
        int batch;
        cout<<"For year "<<i+1<<": \n";
        cout<<"Enter Number of batches: \n";
        cin>>batch;
        data.pb(vector<vector<vector<string>>>());
        for(int j=0; j<batch; j++){
            cout<<"For batch "<<j+1<<": \n";
            data[i].pb(vector<vector<string>>());
            for(int k=0; k<day; k++){
                cout<<"For day "<<k+1<<": \n";
                data[i][j].pb(vector<string>());
                int t;
                for(int l=0; l<sub; l++){
                    string s;
                    t=(10+l)%12;
                    if(t==0) t=12;
                    else if(t==2) t=3;
                    cout<<t-1<<"-"<<t<<": ";
                    cin>>s;
                    data[i][j][k].pb(s);
                }
                cout<<endl;
            }
        }
    } 
}
string display(vector<vector<vector<vector<string>>>>& data){
    string o="";
    o+="{\n";
    for(int i=0; i<year; i++){
        o+="\t{\n";
        for(int j=0; j<data[i].size(); j++){
            o+="\t\t{\n";
            for(int k=0; k<day; k++){
                o+="\t\t\t{\n";
                for(int l=0; l<sub; l++){
                    if (l!=sub-1) o+="\t\t\t\t"+data[i][j][k][l]+",\n";
                    else o+="\t\t\t\t"+data[i][j][k][l]+"\n";
                }
                if (k!=day-1) o+="\t\t\t},\n";
                else o+="\t\t\t}\n";
            }
            if (j!=data[i].size()-1) o+="\t\t},\n";
            else o+="\t\t}\n";
        }
        if (i!=year-1) o+="\t},\n";
        else o+="\t}\n";

    }
    o+="}\n\n";
    return o;
}
void export_json(){
    cout<<"Not yet complete\n";
}
int main(){
    vector<vector<vector<vector<string>>>> data;
    while(true){
        int ch;
        // cout<<"Stats"<<endl;
        // cout<<"year: "<<data.size()<<endl;
        // if(data.size()!=0) {cout<<"batches: "<<data[0].size()<<endl;
        // if(data[0].size()!=0) {cout<<"days: "<<data[0][0].size()<<endl;
        // if(data[0][0].size()!=0) cout<<"subjects: "<<data[0][0][0].size()<<endl;}}


        cout<<"!!! Not yet Complete to be used, may show unreliable behaviour !!!"<<endl;
        cout<<"Menu:"<<endl;
        cout<<"1. Input"<<endl;
        cout<<"2. display"<<endl;
        cout<<"3. export"<<endl;
        cout<<"0. exit"<<endl;
        cout<<"\nInput: ";
        cin>>ch;
        switch (ch){
            case 0:
                cout<<"exiting...\n";
                return 0;
            case 1:
                input(data);
                break;
            case 2:
                cout<<display(data);
                break;
            case 3:
                export_json();
                break;
            default:
                cout<<"Invalid option\n\n";
                break;
        }
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#define year 1
#define sub 7
#define day 6
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
                int t=9;
                for(int l=0; l<sub; l++){
                    if(k==5 && (t+1)%12==2) {
                        for(l; l<sub; l++) data[i][j][k].pb(string(""));
                        break;
                    }
                    string s;
                    t=(t+1)%12;
                    if(t==0) t=12;
                    else if(t==2) t=3;
                    cout<<(t-1!=0?t-1:12)<<"-"<<t<<": ";
                    cin>>s;
                    data[i][j][k].pb(s);
                }
                cout<<endl;
            }
        }
    } 
}
string display(vector<vector<vector<vector<string>>>>& data, bool export_=false){
    string o="";
    o+=export_?"":"{\n";
    for(int i=0; i<year; i++){
        o+=(export_?"":"\t{\n");
        for(int j=0; j<data[i].size(); j++){
            o+=(export_?"":"\t\t{\n");
            for(int k=0; k<day; k++){
                o+=(export_?"":"\t\t\t{\n");
                for(int l=0; l<sub; l++){
                    if (l!=sub-1) o+=(export_?"":"\t\t\t\t\"")+data[i][j][k][l]+(export_?"":"\",")+"\n";
                    else o+=(export_?"":"\t\t\t\t\"")+data[i][j][k][l]+(export_?"":"\"")+"\n";
                }
                if (k!=day-1) o+=(export_?"":"\t\t\t},\n");
                else o+=(export_?"":"\t\t\t}\n");
            }
            if (j!=data[i].size()-1) o+="\t\t},\n";
            else o+=(export_?"":"\t\t")+string("\n");
        }
        if (i!=year-1) o+=(export_?"":"\t},\n");
        else o+=(export_?"":"\t}\n");

    }
    o+=export_?"":"}\n\n";
    return o;
}
void export_txt(vector<vector<vector<vector<string>>>>& data){
    ofstream file;
    cout<<"fuuuuuuuuu";
    file.open("data.txt");
    file<<display(data, true);
    file.close();
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
        cout<<"\nOption: ";
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
                export_txt(data);
                break;
            default:
                cout<<"Invalid option\n\n";
                break;
        }
    }
    return 0;
}
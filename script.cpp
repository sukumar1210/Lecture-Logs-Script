#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#define year 4
#define day 6
#define sub 7 //max classes in one day
#define pb push_back

using namespace std;

string display(vector<vector<vector<vector<string>>>>& data, bool export_=false){
    string o="";
    o+=export_?"":"{\n";
    // data[year][batch][day][sub]
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
            if (j!=data[i].size()-1) o+=(export_?"":"\t\t\t},\n");
            else o+=(export_?"":"\t\t}")+string("\n");
        }
        if (i!=year-1) o+=(export_?"":"\t},\n");
        else o+=(export_?"":"\t}\n");

    }
    o+=export_?"":"}\n\n";
    return o;
}
string display_java(vector<vector<vector<vector<string>>>>& data, bool export_=false){
    string o="";
    o+=export_?"":"{\n";
    for(int i=0; i<year; i++){
        o+=(export_?"":"\t{\n");
        for(int k=0; k<day; k++){
            o+=(export_?"":"\t\t{\n");
            for(int j=0; j<data[i].size(); j++){
                o+=(export_?"":"\t\t\t{\n");
                for(int l=0; l<sub; l++){
                    if (l!=sub-1) o+=(export_?"":"\t\t\t\t\"")+data[i][j][k][l]+(export_?"":"\",")+"\n";
                    else o+=(export_?"":"\t\t\t\t\"")+data[i][j][k][l]+(export_?"":"\"")+"\n";
                }
                if (j!=data[i].size()-1) o+=(export_?"":"\t\t\t},\n");
                else o+=(export_?"":"\t\t\t}")+string("\n");
            }
            if (k!=day-1) o+=(export_?"":"\t\t},\n");
            else o+=(export_?"":"\t\t}\n");
        }
        if (i!=year-1) o+=(export_?"":"\t},\n");
        else o+=(export_?"":"\t}\n");

    }
    o+=export_?"":"}\n\n";
    return o;
}
void export_txt(vector<vector<vector<vector<string>>>>& data, bool java=false){
    ofstream file;
    if (java) {
        file.open("data.txt");
        file<<display_java(data);
    }
    else {
        file.open("save.txt");
        for(int i=0; i<year; i++){
            file<<data[i].size();
            file<<"\n";
        }
        file<<display(data, true);
    }
    // file<<display(data, true);
    file.close();
}
void input(vector<vector<vector<vector<string>>>>& data, bool cont=false){
    for(int i=0; i<year; i++){
        int batch;
        
        if (cont){
            while(data.size()!=0 && data[i].size()!=0 && i<year) i++;
            if (i==year) {
                cout<<"All years filled\n\n";
                return;
            }
        }
        cout<<"For year "<<i+1<<": \n";
        cout<<"Enter Number of batches: \n";
        cin>>batch;
        cin.ignore(1,'\n');
        data.pb(vector<vector<vector<string>>>());
        for(int j=0; j<batch; j++){
            cout<<"For batch "<<j+1<<": \n";
            data[i].emplace(data[i].begin()+j, vector<vector<string>>());
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
                    getline(cin, s);
                    // cin>>s;
                    data[i][j][k].pb(s);
                }
                cout<<endl;
            }
            export_txt(data);
        }
    } 
}
void load(vector<vector<vector<vector<string>>>>& data){
    data=vector<vector<vector<vector<string>>>>();
    ifstream file;
    file.open("save.txt");
    // file.open("data.txt");
    string s;
    int head=0;
    vector<int> y;
    while(head<4){
        getline(file, s);
        // cout<<s<<endl;
        head++;
        y.pb(stoi(s));
    }
    
    for(int i=0; i<year; i++){
        data.pb(vector<vector<vector<string>>>());
        for(int j=0; j<y[i]; j++){
            data[i].pb(vector<vector<string>>());
            for(int k=0; k<day; k++){
                data[i][j].pb(vector<string>());
                for(int l=0; l<sub; l++){
                    getline(file, s);
                    data[i][j][k].pb(s);
                }
            }
        }
    }

    file.close();
    cout<<"Data Loaded\n\n";
}
void bulk_mod( vector<vector<vector<vector<string>>>>& data ){
    vector<int> grp;
    int yr;
    cout<<"Enter year: ";
    cin>>yr;
    int& i=yr;
    i--;
    int n;
    if (data.size()==0){
        cout<<"No Years Present: Please Use the Input option first\n\n";
        return;
    }
    cout<<"Enter number of Batch groups: ";
    cin>>n;
    if (data[i].size()==0){
        cout<<"No Batches in current year: Please Use the Input option first\n\n";
        return;
    }
    cout<<"Enter Batches: ";
    for (int i=0; i<n; i++){
        int x;
        cin>>x;
        grp.pb(--x);
    }
    cin.ignore(1, '\n');
    for(int k=0; k<day; k++){
        cout<<"For day "<<k+1<<": \n";
        int t=9;
        for(int l=0; l<sub; l++){
            string s;
            t=(t+1)%12;
            if(t==0) t=12;
            else if(t==2) t=3;
            cout<<(t-1!=0?t-1:12)<<"-"<<t<<": ";
            getline(cin, s);
            if (s=="") continue;
            // cin>>s;
            for(int j:grp){
                data[i][j][k][l]=s;
            }
        }
    }
    
}
int main(){
    vector<vector<vector<vector<string>>>> data;
    while(true){
        int ch;
        cout<<"!!! Not yet Complete to be used, may show unreliable behaviour !!!"<<endl;
        cout<<"Menu:"<<endl;
        cout<<"1. Input"<<endl;
        cout<<"2. display"<<endl;
        cout<<"3. export Java Format"<<endl;
        cout<<"4. load"<<endl;
        cout<<"5. Save"<<endl;
        cout<<"0. exit"<<endl;
        cout<<"\nOption: ";
        cin>>ch;
        int choice;
        switch (ch){
            case 0:
                cout<<"exiting...\n";
                return 0;
            case 1:
                cout<<"1. Input Single Classes\n2. Modify in Bulk\nOption: ";
                cin>>choice;
                switch (choice){
                    case 1:
                        cout<<"1. Continue\n2. Start Fresh\nOption:";
                        cin>>choice;
                        switch (choice){
                            case 1:
                                input(data, true);
                                break;
                            case 2:
                                input(data);
                                break;
                            default:
                                break;
                        }
                        break;
                    case 2:
                        bulk_mod(data);
                        break;
                    default:
                        break;
                }
                // input(data);
                break;
            case 2:
                cout<<"1. Normal\n2. Java\nOption: ";
                cin>>choice;
                switch (choice){
                    case 1:
                        cout<<display(data);
                        break;
                    case 2:
                        cout<<display_java(data);
                        break;
                    default:
                        break;
                }
                break;
            case 3:
                export_txt(data, true);
                break;
            case 4:
                load(data);
                break;
            case 5:
                export_txt(data);
                // cout<<data.size()<<endl<<data[0].size()<<endl<<data[0][0].size()<<endl<<data[0][0][0].size()<<endl;
                break;
            default:
            cout<<data.size()<<endl<<data[0].size()<<endl<<data[1].size()<<endl;
                cout<<"Invalid option\n\n";
                break;
        }
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

void Union(vector<vector<string>>&sets,int first_set,int second_set){
    cout << "Union set : " ;
    for(string i:sets[first_set])
        cout<<i<<" ";

    for(string i : sets[second_set]){
        bool found=false;
        for(string j : sets[first_set]){
            if(i==j){
                found=true;
            }
        }
        if(!found){
            cout<<i<<" ";
        }
    }
    cout<<"\n";
}

void Intersection(vector<vector<string>>&sets,int first_set,int second_set){
    cout << "Intersection set : " ;
    for(string i : sets[first_set]){
        for(string j : sets[second_set]){
            if(i==j){
                cout<<i<<" ";
            }
        }
    }
    cout<<"\n";
}

void complement(vector<string>&Universe,vector<vector<string>>&sets,int set_num){
    cout << "complement of "<< set_num +1<<"th set : " ;
    for(string i : Universe){
        bool found=false;
        for(string j : sets[set_num]){
            if(i==j){
                found=true;
            }
        }
        if(!found){
            cout<<i<<" ";
        }
    }
    cout<<"\n";
}

int main(){
    int num_Universe, num_sets, num_set;
    cout<<"== Please enter number of elements of the Universe : ";
    cin>>num_Universe;
    vector<string>Universe(num_Universe);
    cout<<"\n== Please enter elements of the Universe : ";
    for(int i=0;i<num_Universe;++i){
        cin>>Universe[i];
    }
    cout<<"\nPlease enter number of Sets : ";
    cin>>num_sets;

    vector<vector<string>>sets(num_sets);
    for(int i=0;i<num_sets;++i){
        cout<<"\nPlease number of elements of "<< i+1 <<"th set : ";
        cin>>num_set;
        cout<<"\nPlease enter the elements of "<< i+1 <<"th set : ";
        for(int j=0;j<num_set;++j){
            string s;cin>>s;
            sets[i].push_back(s);
        }
    }

    int state;
    while(true){
        cout<<"\nplease choose number of operations do you want to do : \n";
        cout<<"1 - Union of two sets  \n";
        cout<<"2 - Intersection of two sets  \n";
        cout<<"3 - Complement of a set \n";
        cout<<"0 - Exit \n";
        cin>>state;
        if ( state < 0 || state > 3){
            cout<<"invalid inputs\n";
            continue ;
        }
        //system("cls");
        if(state==1){
            int first,second;
            cout<<"\nplease enter the number of the first set : ";
            cin>>first;
            cout<<"\nplease enter the number of the second set : ";
            cin>>second;
            if(first>num_sets||second>num_sets||first<=0||second<=0){
                cout<<"invalid inputs\n";
            }
            else{
                Union(sets,first-1,second-1);
            }
        }
        if(state==2){
            int first,second;
            cout<<"\nplease enter the number of the first set : ";
            cin>>first;
            cout<<"\nplease enter the number of the second set : ";
            cin>>second;
            if(first>num_sets||second>num_sets||first<=0||second<=0){
                cout<<"invalid inputs\n";
            }
            else{
                Intersection(sets,first-1,second-1);
            }
        }
        if(state==3){
            int first;
            cout<<"\nplease enter the number of the set : ";
            cin>>first;
            if(first>num_sets||first<=0){
                cout<<"invalid inputs\n";
            }
            else{
                complement(Universe,sets,first-1);
            }
        }
        if (state == 0)
            break;
    }

    return 0;
}



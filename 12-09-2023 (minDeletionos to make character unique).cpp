#include<bits/stdc++.h>
using namespace std;

int minDeletions(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        for(int i=0; i<n; i++){
            mp[s[i]]++; // counting the character occurrence
        }

        priority_queue<int>pq;
        int cnt=0;
        for(auto it:mp){
            pq.push(it.second); // push the all occurrence of character in max_heap 
        }


        while(pq.size()!=1){
            int top=pq.top();
            pq.pop();

            if(pq.top()==top && top!=0){ // if character frequency is same then delte one character make unique character 
                cnt++;// count the deleted character 
                pq.push(top-1); // delete the character push again in max_heap
            }
        }

        return cnt; // return the answer
    }
    
    int main(){
        string s;
        cin>>s;
        
        cout<<minDeletions(s)<<endl;
        return 0 ;
    }
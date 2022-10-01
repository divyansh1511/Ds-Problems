#include<bits/stdc++.h>
using namespace std;

int HighestProduct(vector<int> &A) {
    sort(A.begin(),A.end());
    int N = A.size();
    return max(A[0]*A[1]*A[N-1],A[N-1]*A[N-2]*A[N-3]);
}

int bulbs(vector<int> &A) {
    int k=0,ans=0;
    for(int i=0;i<A.size();i++){
        if(k==A[i]){
            if(k==0) k=1;
            else k=0;
            ans++;
        }
    }
    return ans;
}

int DisjointIntervals(vector<vector<int> > &A) {
    sort(A.begin() , A.end());
    vector<vector<int>> ans;
    ans.push_back(A[0]);
    for(int i=0;i<A.size();i++){
        if(ans.back()[1] >= A[i][0]){
            ans.back()[1] = min(ans.back()[1] , A[i][1]);
        }
        else{
            ans.push_back(A[i]);
        }
    }
    return ans.size();
}

int MeetingRooms(vector<vector<int> > &A) {
    sort(A.begin() , A.end());
    priority_queue<int , vector<int> , greater<int>> pq;
    pq.push(A[0][1]);
    for(int i=1;i<A.size();i++){
        if(A[i][0] >= pq.top()){
            pq.pop();
        }
        pq.push(A[i][1]);
    }
    return pq.size();
}

int candy(vector<int> &A) {
    int s=A.size();
	if(s<=1)
		return s;
	vector<int> num(s,1);
	for (int i = 1; i < s; i++)
	{
		if(A[i]>A[i-1])
			num[i]=num[i-1]+1;
	}
	for (int i= s-1; i>0 ; i--)
	{
		 if(A[i-1]>A[i])
			num[i-1]=max(num[i]+1,num[i-1]);
	}
	int result=0;
	for (int i = 0; i < s; i++)
	{
		result+=num[i];
	}
	return result;
}

int micetoHoles(vector<int> &A, vector<int> &B) {
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int ans=0;
    for(int i=0;i<A.size();i++) ans=max(ans,abs(A[i]-B[i]));
    return ans;
}

int GasStations(const vector<int> &A, const vector<int> &B) {
    int n = A.size();
    int total_surplus = 0;
    int surplus = 0;
    int start = 0;
    
    for(int i = 0; i < n; i++){
        total_surplus += A[i] - B[i];
        surplus += A[i] - B[i];
        if(surplus < 0){
            surplus = 0;
            start = i + 1;
        }
    }
    return (total_surplus < 0) ? -1 : start;
}

int main(){

}
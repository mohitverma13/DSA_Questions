vector<int> getSecondOrderElements(int n, vector<int> arr) {
    int fmax=INT_MIN;
    int smax=INT_MIN;
    int fmin=INT_MAX;
    int smin=INT_MAX;
vector<int>ans;
    for(int i=0;i<n;i++){
        if(arr[i]>fmax){
            smax=fmax;
            fmax=arr[i];
        }else if(arr[i]<fmax && arr[i]>smax){
            smax=arr[i];
        }

        if(arr[i]<fmin){
            smin=fmin;
            fmin=arr[i];
        }
        else if(arr[i]<smin && arr[i]>fmin){
            smin=arr[i];
        }
    }
ans.push_back(smax);
ans.push_back(smin);
return ans;
}
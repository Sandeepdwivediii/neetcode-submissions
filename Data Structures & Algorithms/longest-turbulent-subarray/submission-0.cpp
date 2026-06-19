class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();

        if(n == 1) return 1;
        int ans = 1;
        int len = 1;

        for(int i=1;i<n;i++){
            if(arr[i] == arr[i-1]){
                len = 1;
            }else if(i >= 2 && 
            arr[i-2]<arr[i-1] && arr[i-1] > arr[i] ||
            arr[i-2]>arr[i-1] && arr[i-1] < arr[i]){
                len++;
            }else{
                len = 2;
            }
            ans = max(ans,len);
        }
        return ans;
    }
};
    int binarySearch(vector<int> v, int t){
        int N = v.size();
        
        if(0 == N)
            return -1;
            
        int l = 0, r = N-1, mid;
        while(l <= r){
            mid = l + (r-l)/2;
            if(v[mid] == t){
                if((mid == 0) || (mid-1>=0 && v[mid-1] != t)){
                    return mid;
                }
            }
            
            if(v[mid] >= t){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        
        return -1;
    }
int findsqrt(int num){
    int start=0;
    int end=2*1e9;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(mid*mid==num){
            return mid;
        }else if(mid*mid>num){
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    return -1;
}
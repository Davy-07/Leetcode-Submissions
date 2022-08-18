class Solution {
public:
    int maxProduct(vector<int>& nums) {
     int product=1;
    int max_product=INT_MIN;
    int n=nums.size();
    int i;
    for(i=0;i<n;i++)
    {
        product=product*nums[i];
        max_product=max(max_product,product);
        if(nums[i]==0)
        {
            product=1;
        }
    }
    product=1;
    for(i=n-1;i>=0;i--)
    {
        product=product*nums[i];
        max_product=max(max_product,product);
        if(nums[i]==0)
        {
            product=1;
        }
    }
    return(max_product);
}   
        
        
};
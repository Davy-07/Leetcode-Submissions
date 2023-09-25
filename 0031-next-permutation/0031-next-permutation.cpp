class Solution {
public:
    void nextPermutation(vector<int>& arr) {

            int index1,index2,i,j;
            for(i=arr.size()-2;i>=0;i--)
            {
                if(arr[i+1]>arr[i])
                {
                    index1 = i;
                    break;
                }
            }
            if(i<0)
            {
                reverse(arr.begin(),arr.end());
            }
            else{
                    for(j=arr.size()-1;j>i;j--)
                    {
                        if(arr[j]>arr[index1])
                        {
                            break;
                        }
                    }

                    swap(arr[index1],arr[j]);
                    reverse(arr.begin()+index1+1,arr.end());
            }

    }
};
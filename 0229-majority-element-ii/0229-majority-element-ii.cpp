class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int  n= nums.size();
        int ele1,ele2;
        ele1 = ele2 = nums[0];
        int i =1;
        while(i<n && ele2==nums[i] )
        {
           
            i++;
        }
        if(i<n) ele2 = nums[i];
        int count1 =i;
        int count2 =1;
        i++;
        cout<< ele1 <<' ' << ele2<<endl;
        cout << i << endl;
        while(i<n)
        {
            if(nums[i]==ele1)
            {
                count1++;
            }
            else if(nums[i]==ele2)
            {
                count2++;
            }
            else if(count1==0)
            {
                ele1 = nums[i];
                count1=1;
            }
            else if(count2==0)
            {
                ele2 = nums[i];
                count2=1;
            }
            else 
            {
                count1--;
                count2--;
            }

            
            i++;
            // if(nums[i]==ele1)
            // {
            //     count1++;
            // }
            // else
            // {
            //     count1--;
            // }

            // if(count1<0)
            // {
            //     ele1 = nums[i];
            //     count1 =1;
            // }


            
            // if(nums[i]==ele2)
            // {
            //     count2++;
            // }
            // else
            // {
            //     count2--;
            // }

            // if(count2<0)
            // {
            //     ele2 = nums[i];
            //     count2=1;
            // }
            // i++;
        }
        count1 = count2 =0;
        cout<< ele1 <<' ' << ele2<<endl;
        
        for(int it:nums)
        {
            if(it == ele1) count1++;
            if(it == ele2) count2++;
        }
        vector<int> ans;
        if(count1>n/3) ans.emplace_back(ele1);
        if(count2>n/3 && ele2!=ele1) ans.emplace_back(ele2);
        return ans;
    }
};
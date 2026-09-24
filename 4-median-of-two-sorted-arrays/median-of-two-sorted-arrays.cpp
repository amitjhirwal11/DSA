class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size() , m = nums2.size();
        int total = (n+m);
        int ptr1 = total/2 , ptr2 = ((total-1)/2);

        int i=0 , j=0;

        int ind1 = -1 , ind2 = -1;

        int count = 0;

        while(i<n && j<m){

            if(nums1[i] < nums2[j]){
                if(count == ptr1){
                    ind1 = nums1[i];
                }
                if(count == ptr2){
                    ind2 = nums1[i];
                }
                i++;
                count++;
            }
            else{
                if(count == ptr1){
                    ind1 = nums2[j];
                }
                if(count == ptr2){
                    ind2 = nums2[j];
                }
                j++;
                count++;
            }

        }

        while(i<n){
            if(count == ptr1){
                ind1 = nums1[i];
            }
            if(count == ptr2){
                ind2 = nums1[i];
            }
            i++;
            count++;
        }

        while(j<m){
            if(count == ptr1){
                ind1 = nums2[j];
            }
            if(count == ptr2){
                ind2 = nums2[j];
            }
            j++;
            count++;
        }

        if(total%2 == 0){
            return (ind1+ind2)/2.0;
        }
        else{
            return ind1;
        }

        return -1;
        
    }
};
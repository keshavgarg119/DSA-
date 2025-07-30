class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n1 = nums1.size();
        int n2 = nums2.size();

        int i = 0, j=0;

        int n = (n1+n2);
        int ind2 = n/2;
        int ind1 = ind2-1;

        int count = 0;
        int ind1_el = -1, ind2_el = -1;
        
        // finding the middle two elements
        while(i<n1 && j<n2) {
            if(nums1[i] < nums2[j]) {
                if(count == ind1) ind1_el = nums1[i];
                if(count == ind2) ind2_el = nums1[i];
                count++;
                i++;
            }
            else {
                if(count == ind1) ind1_el = nums2[j];
                if(count == ind2) ind2_el = nums2[j];
                count++;
                j++;
            }
        }

        // checking wheather all the elements of the arrays are trasversed or not

        while(i < n1) {
            if(count == ind1) ind1_el = nums1[i];
            if(count == ind2) ind2_el = nums1[i];
            count++;
            i++;
        }
        while(j < n2) {
            if(count == ind1) ind1_el = nums2[j];
            if(count == ind2) ind2_el = nums2[j];
            count++;
            j++;
        }

        // checking if the no. of elements are odd
        if(n%2==1) {
            return ind2_el;
        }

        return (double)((double)(ind1_el+ind2_el))/2.0;

    }
};
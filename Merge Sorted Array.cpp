1차 2022-03-31 Fail
실패의 원인.. 이런문제가 처음이었던거 같다. 집중도 못함.
class Solution {
public:
    /*
        문제:
        오름차순으로 정렬되어있는 배열 두개가 주어지고, m, n이 주어진다. 각각 사이즈를 나타낸다.
        nums1과 nums2를 merge해라 오름차순으로.
        단, nums1안에서 정렬해야 한다!!!! 
        제한:
        
        해결방법:
        뒤에서부터 .. 큰거부터 놓는다!!
        그리고 마지막에는 nums2의 요소들이남았을 경우 nums1에 덮어씌우면 된다.
    */
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	    int k=(m+n)-1;
	    int i=m-1,j=n-1;
	    while(i>=0 && j>=0)
	    {
		    if(nums1[i]>=nums2[j])
			    nums1[k--]=nums1[i--];
		    else
			    nums1[k--]=nums2[j--];
	    }

	    //check if nums2 elemnt is left
	    while(j>=0)
	    {
		    nums1[k--]=nums2[j--];
	    }
    }
    
};

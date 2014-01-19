class Solution {
public:
	void sortColors(int A[], int n) {
		int cnt0 = 0, cnt1 = 0, cnt2 = 0;
		for(int i = 0;i<n;i++){
			if(A[i]==0)++cnt0;
			else if(A[i]==1)++cnt1;
			else ++cnt2;
		}
		int i = 0;
		while(cnt0>0){--cnt0;A[i++] = 0;}
		while(cnt1>0){--cnt1;A[i++] = 1;}
		while(cnt2>0){--cnt2;A[i++] = 2;}
	}
};

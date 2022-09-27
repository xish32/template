
class NumArray {
private:
	int bit[500010];
	int data[500010];
//    vector<int>bit;  // bit���±��1��ʼ, bit[0] = 0
//    vector<int>data; // copy of nums

    int lowBit(int x){
        return x & (-x);
    }

    int sum(int idx){ // logn
        // ǰidx�����ĺ�
        int res = 0;
        while(idx > 0){
            res += bit[idx];
            idx -= lowBit(idx);
        }            
        return res;
    }
public:
	NumArray() {
		for (int i = 0 ; i < 500010 ; i++) {
			bit[i] = 0;
			data[i] = 0;
		}
	}
//    NumArray(vector<int>& nums) { // nlogn
//        bit = vector<int>(nums.size() + 1, 0);
//
//        // O(nlogn)����
//        data = vector<int>(nums.size(), 0);
//        for(int i = 0; i < nums.size(); i++)
//            update(i, nums[i]);
//
//        // // O(n)����
//        // data = nums;
//        // for(int i = 1; i <= nums.size(); i++){
//        //     bit[i] += nums[i-1];
//        //     int j = i + lowBit(i);
//        //     if(j <= nums.size()) bit[j] += bit[i];
//        // }
//    }

    void update(int i, int val) { //logn
        int diff = val - data[i];
        data[i] = val;
        i += 1; // bit���±��1��ʼ
        while(i < 500010){
            bit[i] += diff;
            i += lowBit(i);
        }            
    }

    int sumRange(int i, int j) { //logn
        return sum(j+1) - sum(i);
    }
};


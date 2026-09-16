class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //brute force
        //take a hashset and traverse through the array
        //tc=>O(n) sc=>O(n)


        //sort the array 
        //traverse and check for adjacent elements
        //tc=>O(nlogn) sc=>O(1)

        //optimal =>detect a cycle return the start of cycle
        int slow = nums[0];
        int fast = nums[0];
        //detect a cycle
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        //find the starting point of cycle-
        int curr = nums[0];
        while(curr != slow){
            curr = nums[curr];
            slow = nums[slow];
        }
        return curr;
    }
};

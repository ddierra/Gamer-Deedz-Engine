class Solution {
    public int[] twoSum(int[] nums, int target) {
        if (nums.length < 2) {
            return null;
        }

        else {
            for (int i = 0; i < nums.length; i++) {
                if (i < target) {
                    for (int c = 1; c < nums.length; c++) {
                        if (i + c == target) {
                            int[] ind;
                            ind.add(i);
                            ind.add(c);
                            return ind;
                        }
                    }
                }
            }
        }
    }

    public static void main(Strings[] args){
        int[] nums = {2, 3, 4, 5, 6};
        twoSum(nums, 9);
    }
}